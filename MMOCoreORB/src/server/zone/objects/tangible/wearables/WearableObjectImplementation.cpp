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
#include "server/globalVariables.h"
#include "server/userVariables.h"

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
	if (globalVariables::craftingNewGenerateSocketsEnabled == false) {
		int skill = 0;
		int luck = 0;
		if (craftingValues != nullptr) {
			ManagedReference<ManufactureSchematic*> manuSchematic = craftingValues->getManufactureSchematic();
			if (manuSchematic != nullptr) {
				ManagedReference<DraftSchematic*> draftSchematic = manuSchematic->getDraftSchematic();
				ManagedReference<CreatureObject*> player = manuSchematic->getCrafter().get();
				if (player != nullptr && draftSchematic != nullptr) {
					String assemblySkill = draftSchematic->getAssemblySkill();
					skill = player->getSkillMod(assemblySkill);
					if (globalVariables::craftingMinSocketMod > skill)
						return;
					luck = System::random(player->getSkillMod("luck") + player->getSkillMod("force_luck"));
				}
			}
		}
		skill -= globalVariables::craftingMinSocketMod;
		int bonusMod = 65 - skill;
		if (bonusMod <= 0) {
			bonusMod = 0;
		} else {
			bonusMod = System::random(bonusMod);
		}
		int skillAdjust = skill + System::random(luck) + bonusMod;
		int maxMod = 65 + System::random(skill);
		float randomSkill = System::random(skillAdjust) * 10;
		float roll = randomSkill / (400.f + maxMod);
		float generatedCount = roll * globalVariables::craftingMaxSockets;
		if (generatedCount > globalVariables::craftingMaxSockets) {
			generatedCount = globalVariables::craftingMaxSockets;
		} else if (generatedCount > 3 && generatedCount <= 3.75f) {
			generatedCount = floor(generatedCount);
		}
		usedSocketCount = 0;
		socketCount = (int)generatedCount;
		socketsGenerated = true;
		return;
	} else {
		int stationNearby = 0;
		float toolEffectiveness = 0;
		int assemblySkill = 0;
		int luckSkill = 0;
		if (craftingValues != nullptr) {
			ManagedReference<ManufactureSchematic*> manuSchematic = craftingValues->getManufactureSchematic();
			if (manuSchematic != nullptr) {
				ManagedReference<DraftSchematic*> draftSchematic = manuSchematic->getDraftSchematic();
				ManagedReference<CreatureObject*> player = manuSchematic->getCrafter().get();
				if (player != nullptr && draftSchematic != nullptr) {
					int cityBonus = player->getSkillMod("private_spec_assembly");
					assemblySkill = std::min(player->getSkillMod("clothing_assembly"),125);
					int forceBonus = std::min(player->getSkillMod("force_assembly"),45);
					int craftBonus = 0;
					int luckRoll = System::random(std::min(player->getSkillMod("luck"),25) + std::min(player->getSkillMod("force_luck"),30));
					toolEffectiveness = userVariables::getUserVariable("toolEffectiveness",player->getFirstName());
					if (userVariables::getUserVariable("stationNearby",player->getFirstName()) == 1.f) stationNearby = 15;
					if (player->hasBuff(BuffCRC::FOOD_CRAFT_BONUS)) {
						Buff* buff = player->getBuff(BuffCRC::FOOD_CRAFT_BONUS);

						if (buff != nullptr) {
							craftBonus = buff->getSkillModifierValue("craft_bonus");
						}
					}
					luckSkill = System::random(125) + ((luckRoll + toolEffectiveness + stationNearby + cityBonus + forceBonus + craftBonus) / 2);
					assemblySkill += (luckRoll + toolEffectiveness + stationNearby + cityBonus + forceBonus + craftBonus) / 2;
				}
			}
		}
		if (luckSkill == 0 && assemblySkill == 0) { // Makes this Loot and not crafted.
			luckSkill = System::random(globalVariables::craftingMaxSocketMod) + globalVariables::craftingMinSocketMod;
			assemblySkill = 20;
		}
		float assemblyDivisor = (globalVariables::craftingMaxSocketMod - globalVariables::craftingMinSocketMod) / globalVariables::craftingMaxSockets;
		if (assemblySkill < globalVariables::craftingMinSocketMod || luckSkill < globalVariables::craftingMinSocketMod) {
			return;
		} else {	
			for ( int i = globalVariables::craftingMaxSockets; i >= 1; --i) {
				if (assemblySkill >= globalVariables::craftingMinSocketMod + (assemblyDivisor * i) || luckSkill >= globalVariables::craftingMinSocketMod + (assemblyDivisor * i)) {
					socketCount = i;
					break;
				}
			}
		}
		usedSocketCount = 0;
		socketsGenerated = true;
		return;
	}
}

void WearableObjectImplementation::applyAttachment(CreatureObject* player, Attachment* attachment) {
	if (!isASubChildOf(player)) {
		return;
	}

	if (getRemainingSockets() < 1 && wearableSkillMods.size() > (globalVariables::craftingMaxSockets + 1)) {
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

String WearableObjectImplementation::repairAttempt(int repairChance, int luckSkill, float repairMaxMod) {
	String message = "";		
	if (globalVariables::craftingNewRepairEnabled == false ) {
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
	} else {
		float repairMaxMod = globalVariables::craftingRepairMaxMod;
		if ((getMaxCondition() - getConditionDamage()) <= 0 && repairMaxMod < 1) {
			message += "This item was broken. Reducing Max Condition by " + std::to_string(repairMaxMod * 100) + "%! ";
			setMaxCondition(getMaxCondition() * repairMaxMod, true);
		}
		if(repairChance < 50 || luckSkill < 50) {
			message += "You barely repaired this item to full condition.";
			setMaxCondition(getMaxCondition() * .6f, true);
			setConditionDamage(0, true);
		} else if(repairChance < 100 || luckSkill < 100) {
			message += "You somewhat repaired this item to full condition.";
			setMaxCondition(getMaxCondition() * .7f, true);
			setConditionDamage(0, true);
		} else if(repairChance < 150 || luckSkill < 150) {
			message += "You almost repaired this item to full condition.";
			setMaxCondition(getMaxCondition() * .8f, true);
			setConditionDamage(0, true);
		} else if(repairChance < 200 || luckSkill < 200) {
			message += "You completely repaired this item to full condition.";
			setMaxCondition(getMaxCondition() * .9f, true);
			setConditionDamage(0, true);
		} else {
			message += "You completely repaired this item to full condition.";
			setMaxCondition(getMaxCondition(), true);
			setConditionDamage(0, true);
		}
	}
	return message;
}

