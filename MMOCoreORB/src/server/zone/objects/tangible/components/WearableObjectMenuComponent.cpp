/*
 * WearableObjectMenuComponent.cpp
 *
 *  Created on: 10/30/2011
 *      Author: kyle
 */

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"
#include "server/zone/objects/player/sui/callbacks/ColorArmorSuiCallback.h"
#include "server/zone/ZoneServer.h"
#include "client/zone/objects/scene/SceneObject.h"
#include "WearableObjectMenuComponent.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/player/sui/callbacks/wipeinventorySuiCallback.h"
#include "templates/customization/AssetCustomizationManagerTemplate.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/callbacks/AttachmentSplitterSuiCallback.h"
#include "server/zone/objects/player/sui/callbacks/WearableAttachmentSplitterSuiCallback.h"
#include "server/globalVariables.h"

void WearableObjectMenuComponent::fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const {
	if (!sceneObject->isTangibleObject())
		return;

	TangibleObject* tano = cast<TangibleObject*>(sceneObject);
	if (tano == nullptr)
		return;

	if (tano->getConditionDamage() > 0 && tano->canRepair(player)) {
		menuResponse->addRadialMenuItem(70, 3, "@sui:repair"); // Slice
	}

	TangibleObjectMenuComponent::fillObjectMenuResponse(sceneObject, menuResponse, player);

	if ((sceneObject->isArmorObject() || sceneObject->isWearableObject()) && globalVariables::playerChangeWearableColorsEnabled == true) {
		String appearanceFilename = sceneObject->getObjectTemplate()->getAppearanceFilename();
		VectorMap<String, Reference<CustomizationVariable*> > variables;
		AssetCustomizationManagerTemplate::instance()->getCustomizationVariables(appearanceFilename.hashCode(), variables, false);
		String varkey = variables.elementAt(0).getKey();
		if (varkey.contains("color")) {
			menuResponse->addRadialMenuItem(71, 3, "Change Colors");
			for(int i = 0; i< variables.size(); ++i){
				varkey = variables.elementAt(i).getKey();
				if (varkey.contains("color")) {
					String optionName = "Color " + String::valueOf(i + 1);
					menuResponse->addRadialMenuItemToRadialID(71, (72 + i), 3, optionName); // sub-menu
				}
			}
		}
	}
	
	PlayerObject* ghost = player->getPlayerObject();
	if ((sceneObject->isWearableObject() && !sceneObject->isArmorObject() && player->hasSkill("crafting_tailor_master") && globalVariables::playerAttachmentSplittingEnabled) || (ghost != nullptr && ghost->isAdmin())) {
		WearableObject* wearable = cast<WearableObject*>( sceneObject);
		if (wearable != nullptr) {
			VectorMap<String, int>* skillMods = wearable->getWearableSkillMods();
			if (skillMods->size() >= 1) {
				menuResponse->addRadialMenuItem(80, 3, "Split Modifiers");
			}
		}
	}
	
	if ((sceneObject->isWearableObject() && sceneObject->isArmorObject() && player->hasSkill("crafting_armorsmith_master") && globalVariables::playerAttachmentSplittingEnabled) || (ghost != nullptr && ghost->isAdmin())) {
		WearableObject* wearable = cast<WearableObject*>( sceneObject);
		if (wearable != nullptr) {
			VectorMap<String, int>* skillMods = wearable->getWearableSkillMods();
			if (skillMods->size() >= 1) {
				menuResponse->addRadialMenuItem(80, 3, "Split Modifiers");
			}
		}
	}
}

int WearableObjectMenuComponent::handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const {
	if (!sceneObject->isASubChildOf(player))
		return 0;

	if (selectedID == 70) {
		if(!sceneObject->isTangibleObject())
			return 0;

		TangibleObject* tano = cast<TangibleObject*>(sceneObject);
		if(tano == nullptr)
			return 0;

		tano->repair(player);

		return 1;
	}
	else if (selectedID == 72 || selectedID == 73 || selectedID == 74)
	{

		// The color index.
		String appearanceFilename = sceneObject->getObjectTemplate()->getAppearanceFilename();
		VectorMap<String, Reference<CustomizationVariable*> > variables;
		AssetCustomizationManagerTemplate::instance()->getCustomizationVariables(appearanceFilename.hashCode(), variables, false);

		ZoneServer* server = player->getZoneServer();

		// The Sui Box.
		ManagedReference<SuiColorBox*> cbox = new SuiColorBox(player, SuiWindowType::COLOR_ARMOR);
		cbox->setCallback(new ColorArmorSuiCallback(server));

		int colorIndex = 0;
		if(selectedID == 73)
		{
			if(variables.size() - 1 > 1)
			{
				colorIndex = 1;
			}
			else
			{
				return 0;
			}
		}
		else if (selectedID == 74)
		{
			if(variables.size() - 1 > 2)
			{
				colorIndex = 2;
			}
			else
			{
				return 0;
			}
		}

		cbox->setSkillMod(255);		
		cbox->setColorPalette(variables.elementAt(colorIndex).getKey());
		cbox->setUsingObject(sceneObject);

		// Add to player.
		ManagedReference<PlayerObject*> ghost = player->getPlayerObject();
		ghost->addSuiBox(cbox);
		player->sendMessage(cbox->generateMessage());

	} else if (selectedID == 80) {
		ZoneServer* server = player->getZoneServer();
		if (server != nullptr) {
			WearableObject* wearable = cast<WearableObject*>( sceneObject);
			if (wearable != nullptr) {
				SortedVector<ModSortingHelper> sortedMods;
				VectorMap<String, int>* skillMods = wearable->getWearableSkillMods();
				ManagedReference<SuiListBox*> sui = new SuiListBox(player, 0x00);
				sui->setUsingObject(player);
				sui->setCallback(new WearableAttachmentSplitterSuiCallback(server, wearable, sceneObject));
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

	return TangibleObjectMenuComponent::handleObjectMenuSelect(sceneObject, player, selectedID);
}
