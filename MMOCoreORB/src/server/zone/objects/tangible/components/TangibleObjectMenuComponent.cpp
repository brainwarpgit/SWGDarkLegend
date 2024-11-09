/*
 * TangibleObjectMenuComponent.cpp
 *
 *  Created on: 26/05/2011
 *      Author: victor
 */

#include "TangibleObjectMenuComponent.h"
#include "server/zone/objects/player/sessions/SlicingSession.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/callbacks/AttachmentSplitterSuiCallback.h"
#include "server/globalVariables.h"

void TangibleObjectMenuComponent::fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const {
	ObjectMenuComponent::fillObjectMenuResponse(sceneObject, menuResponse, player);

	uint32 gameObjectType = sceneObject->getGameObjectType();

	if (!sceneObject->isTangibleObject())
		return;

	TangibleObject* tano = cast<TangibleObject*>( sceneObject);

	// Figure out what the object is and if its able to be Sliced.
	if(tano->isSliceable() && !tano->isSecurityTerminal()) { // Check to see if the player has the correct skill level

		bool hasSkill = true;
		ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

		if ((gameObjectType == SceneObjectType::PLAYERLOOTCRATE) && !player->hasSkill("combat_smuggler_novice"))
			hasSkill = false;
		else if (sceneObject->isContainerObject())
			hasSkill = false; // Let the container handle our slice menu
		else if (sceneObject->isMissionTerminal() && !player->hasSkill("combat_smuggler_slicing_01"))
			hasSkill = false;
		else if (sceneObject->isWeaponObject() && (!inventory->hasObjectInContainer(sceneObject->getObjectID()) || !player->hasSkill("combat_smuggler_slicing_02")))
			hasSkill = false;
		else if (sceneObject->isArmorObject() && (!inventory->hasObjectInContainer(sceneObject->getObjectID()) || !player->hasSkill("combat_smuggler_slicing_03")))
			hasSkill = false;

		if(hasSkill)
			menuResponse->addRadialMenuItem(69, 3, "@slicing/slicing:slice"); // Slice
	}

	if (player->getPlayerObject() != nullptr && player->getPlayerObject()->isPrivileged()) {
		/// Viewing components used to craft item, for admins
		ManagedReference<SceneObject*> container = tano->getSlottedObject("crafted_components");

		if (container != nullptr && container->getContainerObjectsSize() > 0) {
			SceneObject* satchel = container->getContainerObject(0);

			if (satchel != nullptr && satchel->getContainerObjectsSize() > 0) {
				menuResponse->addRadialMenuItem(79, 3, "@ui_radial:ship_manage_components"); // View Components
			}
		}
	}

	ManagedReference<SceneObject*> parent = tano->getParent().get();
	if (parent != nullptr && parent->getGameObjectType() == SceneObjectType::STATICLOOTCONTAINER) {
		menuResponse->addRadialMenuItem(10, 3, "@ui_radial:item_pickup"); //Pick up
	}
	
	PlayerObject* ghost = player->getPlayerObject();
	if (((tano->isAttachment() && !player->isInCombat() && player->hasSkill("crafting_tailor_master") && globalVariables::playerAttachmentSplittingEnabled)) || (ghost != nullptr && ghost->isAdmin() && !player->isInCombat())) {
		Attachment* sea = cast<Attachment*>( sceneObject);
		if (sea != nullptr) {
			VectorMap<String, int>* skillMods = sea->getSkillMods();
			if (skillMods->size() > 1) {
				menuResponse->addRadialMenuItem(80, 3, "Split Modifiers");
			}
		}
	}
}

int TangibleObjectMenuComponent::handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const {
	if (!sceneObject->isTangibleObject())
		return 0;

	TangibleObject* tano = cast<TangibleObject*>( sceneObject);


	if (selectedID == 69 && player->hasSkill("combat_smuggler_novice") ) { // Slice [PlayerLootCrate]
		if (player->containsActiveSession(SessionFacadeType::SLICING)) {
			player->sendSystemMessage("@slicing/slicing:already_slicing");
			return 0;
		}

		//Create Session
		ManagedReference<SlicingSession*> session = new SlicingSession(player);
		session->initalizeSlicingMenu(player, tano);

		return 0;
	} else if (selectedID == 79) { // See components (admin)
		if(player->getPlayerObject() != nullptr && player->getPlayerObject()->isPrivileged()) {

			SceneObject* container = tano->getSlottedObject("crafted_components");
			if(container != nullptr) {

				if(container->getContainerObjectsSize() > 0) {

					SceneObject* satchel = container->getContainerObject(0);

					if(satchel != nullptr) {

						satchel->sendWithoutContainerObjectsTo(player);
						satchel->openContainerTo(player);

					} else {
						player->sendSystemMessage("There is no satchel this container");
					}
				} else {
					player->sendSystemMessage("There are no items in this container");
				}
			} else {
				player->sendSystemMessage("There is no component container in this object");
			}
		}

		return 0;
	} else if (selectedID == 80) {
		ZoneServer* server = player->getZoneServer();
		if (server != nullptr) {
			Attachment* sea = cast<Attachment*>( sceneObject);
			if (sea != nullptr) {
				SortedVector<ModSortingHelper> sortedMods;
				VectorMap<String, int>* skillMods = sea->getSkillMods();
				ManagedReference<SuiListBox*> sui = new SuiListBox(player, 0x00);
				sui->setUsingObject(player);
				sui->setCallback(new AttachmentSplitterSuiCallback(server, tano, sceneObject));
				sui->setPromptTitle("Attachment Splitter");
				int jobCost = 0;
				for (int i = 0; i < skillMods->size(); i++) {
					auto key = skillMods->elementAt(i).getKey();
					auto value = skillMods->elementAt(i).getValue();
					jobCost += value * globalVariables::playerAttachmentSplittingCostPerPoint;
					sortedMods.put(ModSortingHelper(key, value));
				}
				sui->setPromptText("Below are the Skill Mods that will be created in your inventory.  The cost is " + std::to_string(jobCost) + " credits.  Which is 1000 credits per Skill Mod Point. Credits must be available in your BANK account.\n\nWARNING:  This action could delete the current mod whether the function is successful or not.  The original item will be lost.");
				for (int i = 0; i < sortedMods.size(); i++) {
					auto key = sortedMods.elementAt(i).getKey();
					auto value = sortedMods.elementAt(i).getValue();
					String attachmentName = "@stat_n:" + key;
					sui->addMenuItem(attachmentName + " | +" + std::to_string(value));
				}
				sui->setCancelButton(true,"@cancel");
				sui->setOkButton(true,"@ok");
				ManagedReference<PlayerObject*> ghost = player->getPlayerObject();
				ghost->addSuiBox(sui);
				player->sendMessage(sui->generateMessage());
			}
		}
		return 0;
	} else {
		return ObjectMenuComponent::handleObjectMenuSelect(sceneObject, player, selectedID);
	}
}

