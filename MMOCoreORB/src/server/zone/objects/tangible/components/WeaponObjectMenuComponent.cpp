/*
 * WeaponObjectMenuComponent.cpp
 *
 *  Created on: 3/11/2012
 *      Author: kyle
 */

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/powerup/PowerupObject.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "WeaponObjectMenuComponent.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/objects/player/sessions/SlicingSession.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/zone/objects/player/sui/callbacks/WeaponAttachmentSplitterSuiCallback.h"
#include "server/globalVariables.h"

void WeaponObjectMenuComponent::fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const {

	if (!sceneObject->isTangibleObject())
		return;

	ManagedReference<WeaponObject*> weapon = cast<WeaponObject*>(sceneObject);
	if(weapon == nullptr)
		return;

	if(weapon->isASubChildOf(player)) {

		if(weapon->hasPowerup()) {
			menuResponse->addRadialMenuItem(71, 3, "@powerup:mnu_remove_powerup"); // Remove Powerup
		}

		if(weapon->getConditionDamage() > 0 && weapon->canRepair(player)) {
			menuResponse->addRadialMenuItem(70, 3, "@sui:repair"); // Slice
		}
	}
	
	PlayerObject* ghost = player->getPlayerObject();
	if ((sceneObject->isWeaponObject() && player->hasSkill("crafting_weaponsmith_master") && globalVariables::playerWeaponAttachmentSplittingEnabled) || (ghost != nullptr && ghost->isAdmin())) {
		if (weapon != nullptr) {
			const VectorMap<String, int>* skillMods = weapon->getWearableSkillMods();
			if (skillMods->size() >= 1) {
				menuResponse->addRadialMenuItem(80, 3, "Split Modifiers");
			}
		}
	}


	TangibleObjectMenuComponent::fillObjectMenuResponse(sceneObject, menuResponse, player);

}

int WeaponObjectMenuComponent::handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const {
	if (!sceneObject->isTangibleObject())
		return 0;

	ManagedReference<WeaponObject*> weapon = cast<WeaponObject*>(sceneObject);
	if(weapon == nullptr)
		return 1;

	if(weapon->isASubChildOf(player)) {

		if (selectedID == 69 && player->hasSkill("combat_smuggler_slicing_02")) {
			if (weapon->isSliced()) {
				player->sendSystemMessage("@slicing/slicing:already_sliced");
				return 0;
			}

			ManagedReference<Facade*> facade = player->getActiveSession(SessionFacadeType::SLICING);
			ManagedReference<SlicingSession*> session = dynamic_cast<SlicingSession*>(facade.get());

			if (session != nullptr) {
				player->sendSystemMessage("@slicing/slicing:already_slicing");
				return 0;
			}

			//Create Session
			session = new SlicingSession(player);
			session->initalizeSlicingMenu(player, weapon);

			return 0;

		}

		if(selectedID == 70) {

			weapon->repair(player);
			return 1;
		}

		if(selectedID == 71) {

			ManagedReference<PowerupObject*> pup = weapon->removePowerup();
			if(pup == nullptr)
				return 1;

			Locker locker(pup);

			pup->destroyObjectFromWorld( true );
			pup->destroyObjectFromDatabase( true );

			StringIdChatParameter message("powerup", "prose_remove_powerup"); //You detach your powerup from %TT.
			message.setTT(weapon->getDisplayedName()); 
			player->sendSystemMessage(message);

			return 1;
		}
		
		if (selectedID == 80) {
			ZoneServer* server = player->getZoneServer();
			if (server != nullptr) {
				if (weapon != nullptr) {
					SortedVector<ModSortingHelper> sortedMods;
					const VectorMap<String, int>* skillMods = weapon->getWearableSkillMods();
					ManagedReference<SuiListBox*> sui = new SuiListBox(player, 0x00);
					sui->setUsingObject(player);
					sui->setCallback(new WeaponAttachmentSplitterSuiCallback(server, weapon, sceneObject));
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
		}
	}

	return TangibleObjectMenuComponent::handleObjectMenuSelect(sceneObject, player, selectedID);
}
