/*
 * WearableObjectImplementation.cpp
 *
 *  Created on: 02/08/2009
 *      Author: victor
 */

#include "server/zone/objects/tangible/wearables/WearableObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/objects/tangible/attachment/Attachment.h"
#include "server/zone/managers/skill/SkillModManager.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/zone/objects/transaction/TransactionLog.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/tangible/tool/CraftingTool.h"
#include "server/zone/objects/tangible/tool/CraftingStation.h"

#include "server/zone/managers/variables/craftingVariables.h"
#include "server/zone/managers/variables/lootVariables.h"
#include "server/globalVariables.h"

void WearableObjectImplementation::initializeTransientMembers() {
	TangibleObjectImplementation::initializeTransientMembers();
	setLoggingName("WearableObject");
}

void WearableObjectImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(alm, object);

	for(int i = 0; i < wearableSkillMods.size(); ++i) {
		String key = wearableSkillMods.elementAt(i).getKey();
		String statname = "cat_skill_mod_bonus.@stat_n:" + key;
		int value = wearableSkillMods.get(key);

		if (value > 0)
			alm->insertAttribute(statname, value);
	}

	//Anti Decay Kit
	if (hasAntiDecayKit() && !isArmorObject()){
		alm->insertAttribute("@veteran_new:antidecay_examine_title", "@veteran_new:antidecay_examine_text");
	}

}

void WearableObjectImplementation::updateCraftingValues(CraftingValues* values, bool initialUpdate) {
	/*
	 * Values available:	Range:
	 * sockets				0-0(novice artisan) (Don't use)
	 * hitpoints			1000-1000 (Don't Use)
	 */
	if (initialUpdate) {
		if(values->hasExperimentalAttribute("sockets") && values->getCurrentValue("sockets") >= 0)
			generateSockets(values);
	}
}

void WearableObjectImplementation::generateSockets(CraftingValues* craftingValues) {
	if (socketsGenerated) {
		return;
	}

	int skill = 0;
	int luck = 0;

	if (craftingValues != nullptr) {
		ManagedReference<ManufactureSchematic*> manuSchematic = craftingValues->getManufactureSchematic();

		if (manuSchematic != nullptr) {
			ManagedReference<DraftSchematic*> draftSchematic = manuSchematic->getDraftSchematic();
			ManagedReference<CreatureObject*> player = manuSchematic->getCrafter().get();

			if (player != nullptr && draftSchematic != nullptr) {
				ManagedReference<PlayerManager*> playerMan = player->getZoneServer()->getPlayerManager();
				ManagedReference<CraftingStation*> station = nullptr;
				ManagedReference<CraftingTool*> craftingTool = nullptr;
				if (craftingVars.craftingNewGenerateSocketsEnabled) {
					if (playerMan != nullptr) {
						station = playerMan->getNearbyCraftingStation(player, CraftingTool::CLOTHING);
						if (station != nullptr) {
							skill += station->getEffectiveness();
							craftingTool = cast<CraftingTool*>(station->findCraftingTool(player));
							if (craftingTool != nullptr) {
								skill += craftingTool->getEffectiveness();
							}
						}
					}
					skill += player->getSkillMod("force_assembly");
					if (player->hasBuff(BuffCRC::FOOD_CRAFT_BONUS)) {
						Buff* buff = player->getBuff(BuffCRC::FOOD_CRAFT_BONUS);
						if (buff != nullptr) {
							skill += buff->getSkillModifierValue("craft_bonus");
						}
					}
					skill += player->getSkillMod("private_spec_assembly");
				}
				String assemblySkill = draftSchematic->getAssemblySkill();

				skill += player->getSkillMod(assemblySkill);

				if (craftingVars.craftingMinSocketMod > skill)
					return;

				luck = System::random(player->getSkillMod("luck") + player->getSkillMod("force_luck"));
			}
		}
	}
	skill -= craftingVars.craftingMinSocketMod;
	if (skill < 0) skill = 0;
	int bonusMod = 65 - skill;

	if (bonusMod <= 0) {
		bonusMod = 0;
	} else {
		bonusMod = System::random(bonusMod);
	}

	int skillAdjust = skill + System::random(luck) + bonusMod;
	int maxMod = 0;
	if (craftingVars.craftingNewGenerateSocketsEnabled) {
		maxMod = 65 + System::random(skill + luck);
	} else {
		maxMod = 65 + System::random(skill);
	}
	float randomSkill = System::random(skillAdjust) * 10;
	float roll = randomSkill / (400.f + maxMod);
	float generatedCount = roll * craftingVars.craftingMaxSockets;
	if (generatedCount > craftingVars.craftingMaxSockets) {
		generatedCount = craftingVars.craftingMaxSockets;
	} else if (generatedCount > 3 && generatedCount <= 3.75f) {
		generatedCount = floor(generatedCount);
	}
	usedSocketCount = 0;
	socketCount = (int)generatedCount;

	socketsGenerated = true;

	return;
}

void WearableObjectImplementation::applyAttachment(CreatureObject* player, Attachment* attachment) {
	if (!isASubChildOf(player)) {
		return;
	}

	if (getRemainingSockets() < 1 && wearableSkillMods.size() > (craftingVars.craftingMaxSockets + 1)) {
		return;
	}

	Locker locker(player);

	if (isEquipped()) {
		removeSkillModsFrom(player);
	}

	SortedVector<ModSortingHelper> sortedMods;
	VectorMap<String, int>* skillModifiers = attachment->getSkillMods();

	for (int i = 0; i < skillModifiers->size(); i++) {
		auto key = skillModifiers->elementAt(i).getKey();
		auto value = skillModifiers->elementAt(i).getValue();

		sortedMods.put(ModSortingHelper(key, value));
	}

	// Select the next mod in the SEA, sorted high-to-low. If that skill mod is already on the
	// wearable, with higher or equal value, don't apply and continue. Break once one mod
	// is applied.
	
	if (globalVariables::playerAttachmentApplicationModEnabled) {
		int modValue = 0;
		int existingValue = 0;
		for (int i = 0; i < sortedMods.size(); i++) {
			String modName = sortedMods.elementAt(i).getKey();
			modValue = sortedMods.elementAt(i).getValue();
			if (wearableSkillMods.contains(modName)) {
				existingValue = wearableSkillMods.get(modName);
			}
			if ((existingValue + modValue) <= lootVars.lootAttachmentMax || (existingValue + modValue) >= lootVars.lootAttachmentMax) {
				modValue = existingValue + modValue;
				if (modValue > lootVars.lootAttachmentMax) modValue = lootVars.lootAttachmentMax;
				wearableSkillMods.put(modName, modValue);
			}
			if (modValue == existingValue) {
				continue;
			}
			if (existingValue == 0) {
				usedSocketCount++;
			}
		}
	} else {
		for (int i = 0; i < sortedMods.size(); i++) {
			String modName = sortedMods.elementAt(i).getKey();
			int modValue = sortedMods.elementAt(i).getValue();
			int existingValue = -26;
			if (wearableSkillMods.contains(modName)) {
				existingValue = wearableSkillMods.get(modName);
			}
			if (modValue > existingValue) {
				wearableSkillMods.put(modName, modValue);
				break;
			}
		}
		usedSocketCount++;
	}

	addMagicBit(true);
	Locker clocker(attachment, player);
	TransactionLog trx(player, asSceneObject(), attachment, TrxCode::APPLYATTACHMENT);

	if (trx.isVerbose()) {
		// Force a synchronous export because the object will be deleted before we can export it!
		trx.addRelatedObject(attachment, true);
		trx.setExportRelatedObjects(true);
		trx.exportRelated();
	}

	trx.addState("subjectSkillModMap", sortedMods);
	trx.addState("dstSkillModMap", wearableSkillMods);

	attachment->destroyObjectFromWorld(true);
	attachment->destroyObjectFromDatabase(true);

	if (isEquipped()) {
		applySkillModsTo(player);
	}
}

void WearableObjectImplementation::applySkillModsTo(CreatureObject* creature) const {
	if (creature == nullptr) {
		return;
	}

	for (int i = 0; i < wearableSkillMods.size(); ++i) {
		String name = wearableSkillMods.elementAt(i).getKey();
		int value = wearableSkillMods.get(name);

		if (!SkillModManager::instance()->isWearableModDisabled(name))
		{
			creature->addSkillMod(SkillModManager::WEARABLE, name, value, true);
			creature->updateSpeedAndAccelerationMods();
		}
	}

	SkillModManager::instance()->verifyWearableSkillMods(creature);
}

void WearableObjectImplementation::removeSkillModsFrom(CreatureObject* creature) {
	if (creature == nullptr) {
		return;
	}

	for (int i = 0; i < wearableSkillMods.size(); ++i) {
		String name = wearableSkillMods.elementAt(i).getKey();
		int value = wearableSkillMods.get(name);

		if (!SkillModManager::instance()->isWearableModDisabled(name))
		{
			creature->removeSkillMod(SkillModManager::WEARABLE, name, value, true);
			creature->updateSpeedAndAccelerationMods();
		}
	}

	SkillModManager::instance()->verifyWearableSkillMods(creature);
}

bool WearableObjectImplementation::isEquipped() {
	ManagedReference<SceneObject*> parent = getParent().get();
	if (parent != nullptr && parent->isPlayerCreature())
		return true;

	return false;
}

String WearableObjectImplementation::repairAttempt(int repairChance) {
	String message = "";

	if ((getMaxCondition() - getConditionDamage()) <= 0 && craftingVars.craftingRepairBrokenEnabled) {
		message += "This item was broken. Reduced Max Condition by " + std::to_string(craftingVars.craftingRepairMaxMod * 100) + "%! ";
		setMaxCondition(getMaxCondition() * craftingVars.craftingRepairMaxMod, true);
	}

	message += "@error_message:";

	if(repairChance < 25) {
		message += "sys_repair_failed";
		setMaxCondition(1, true);
		setConditionDamage(0, true);
	} else if(repairChance < 50) {
		message += "sys_repair_imperfect";
		setMaxCondition(getMaxCondition() * .65f, true);
		setConditionDamage(0, true);
	} else if(repairChance < 75) {
		setMaxCondition(getMaxCondition() * .80f, true);
		setConditionDamage(0, true);
		message += "sys_repair_slight";
	} else {
		setMaxCondition(getMaxCondition() * .95f, true);
		setConditionDamage(0, true);
		message += "sys_repair_perfect";
	}

	return message;
}

