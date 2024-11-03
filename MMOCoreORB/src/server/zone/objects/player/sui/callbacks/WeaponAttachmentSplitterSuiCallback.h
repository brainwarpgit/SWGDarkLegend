/*
 * WeaponAttachmentSplitterSuiCallback.h
 *
 *  Created on: 10/16/2024
 *	  Author: Genmi
 */

#ifndef WEAPONATTACHMENTSPLITTERSUICALLBACK_H_
#define WEAPONATTACHMENTSPLITTERSUICALLBACK_H_

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/tangible/attachment/Attachment.h"
#include "server/zone/managers/loot/LootManager.h"
#include "server/zone/managers/loot/LootGroupMap.h"
#include "server/globalVariables.h"

class WeaponAttachmentSplitterSuiCallback : public SuiCallback {
	ManagedWeakReference<WeaponObject*> weaponObject;
	ManagedWeakReference<SceneObject*> sceneObject;

public:
	WeaponAttachmentSplitterSuiCallback(ZoneServer* serv, WeaponObject* weapon, SceneObject* sceneo) : SuiCallback(serv) {
		weaponObject = weapon;
		sceneObject = sceneo;
	}

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args) {
		ManagedReference<SceneObject*> sceneo = sceneObject;
		ManagedReference<WeaponObject*> weapon = weaponObject;
		
		if (creature == nullptr) {
			return;
		}
		
		if (sceneo == nullptr) {
			return;
		}
		
		bool cancelPressed = (eventIndex == 1);

		if (!sui->isListBox() || cancelPressed) {
			return;
		}

		if(!creature->isPlayerCreature()) {
			return;
		}

		String attachmentType = "";
		int jobCost = 0;
		if (weapon != nullptr) {
			SortedVector<ModSortingHelper> sortedMods;
			const VectorMap<String, int>* skillMods = weapon->getWearableSkillMods();
			for (int i = 0; i < skillMods->size(); i++) {
				auto key = skillMods->elementAt(i).getKey();
				auto value = skillMods->elementAt(i).getValue();
				jobCost += value * globalVariables::playerAttachmentSplittingCostPerPoint;
				sortedMods.put(ModSortingHelper(key, value));
			}
			if (creature->getBankCredits() < jobCost) {
				creature->sendSystemMessage("You do not have enough credits in the BANK to complete this split.");
				return;
			}
			ManagedReference<SceneObject*> inventory = creature->getSlottedObject("inventory");
			if (inventory == nullptr || inventory->isContainerFullRecursive() || ((inventory->getCountableObjectsRecursive() + skillMods->size()) > inventory->getContainerVolumeLimit())) {
				creature->sendSystemMessage("Your inventory is full, or there is not enough room for this split.  Canceling split.");
				return;
			}
			for (int i = 0; i < sortedMods.size(); i++) {
				auto key = sortedMods.elementAt(i).getKey();
				auto value = sortedMods.elementAt(i).getValue();
				LootManager* lootManager = creature->getZoneServer()->getLootManager();
				LootGroupMap* lootGroupMap = LootGroupMap::instance();
				if (System::random(100) <= 50) {
					attachmentType = "attachment_clothing";
				} else {
					attachmentType = "attachment_armor";
				}
				Reference<const LootItemTemplate*> itemTemplate = lootGroupMap->getLootItemTemplate(attachmentType);
				ManagedReference<TangibleObject*> caTano = lootManager->createLootAttachment(itemTemplate, key, value); 
				if (caTano != nullptr){
					Attachment* attachment = cast<Attachment*>(caTano.get());
					if (attachment != nullptr){
						Locker objLocker(attachment);
						if (inventory->transferObject(caTano, -1, true, true)) { //Transfer tape to player inventory
							inventory->broadcastObject(caTano, true);
						} else {
							caTano->destroyObjectFromDatabase(true);
							creature->sendSystemMessage("Unable to place Skill Attachment in player's inventory!");
							break;
						}
					}
				}
			}
			weapon->destroyObjectFromWorld(true);
			weapon->destroyObjectFromDatabase(true);
			creature->subtractBankCredits(jobCost);
			creature->sendSystemMessage("Your attachment split has been completed.  You have paid " + std::to_string(jobCost) + " credits.");
		}
	}
};

#endif /* WEAPONATTACHMENTSPLITTERSUICALLBACK_H_ */
