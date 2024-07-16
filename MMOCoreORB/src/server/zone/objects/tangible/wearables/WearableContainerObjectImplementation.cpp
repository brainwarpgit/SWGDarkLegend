/*
 * WearableContainerObjectImplementation.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: loshult
 */

#include "server/zone/objects/tangible/wearables/WearableContainerObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/skill/SkillModManager.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"
#include "server/zone/objects/draftschematic/DraftSchematic.h"
#include "server/zone/objects/tangible/attachment/Attachment.h"
#include "server/zone/objects/tangible/wearables/ModSortingHelper.h"
#include "server/globalVariables.h"
#include "server/userVariables.h"

void WearableContainerObjectImplementation::initializeTransientMembers() {
	ContainerImplementation::initializeTransientMembers();
	setLoggingName("WearableContainerObject");
}

void WearableContainerObjectImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(alm, object);

	for(int i = 0; i < wearableSkillMods.size(); ++i) {
		String key = wearableSkillMods.elementAt(i).getKey();
		String statname = "cat_skill_mod_bonus.@stat_n:" + key;
		int value = wearableSkillMods.get(key);

		if (value > 0)
			alm->insertAttribute(statname, value);
	}
}

void WearableContainerObjectImplementation::updateCraftingValues(CraftingValues* values, bool initialUpdate) {
	if (initialUpdate) {
		if(values->hasExperimentalAttribute("sockets") && values->getCurrentValue("sockets") >= 0)
			if (globalVariables::craftingWearableContainerSocketsEnabled == true) {
				generateSockets(values);
			}
	}
}

void WearableContainerObjectImplementation::generateSockets(CraftingValues* craftingValues) {
	if (socketsGenerated) {
		return;
	}
	ManagedReference<ManufactureSchematic*> manuSchematic = craftingValues->getManufactureSchematic();
	ManagedReference<DraftSchematic*> draftSchematic = manuSchematic->getDraftSchematic();
	ManagedReference<CreatureObject*> player = manuSchematic->getCrafter().get();
	if (globalVariables::craftingNewGenerateSocketsEnabled == false) {
		int skill = 0;
		int luck = 0;
		if (craftingValues != nullptr) {
			if (manuSchematic != nullptr) {
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
			if (manuSchematic != nullptr) {
				if (player != nullptr && draftSchematic != nullptr) {
					int cityBonus = player->getSkillMod("private_spec_assembly");
					assemblySkill = std::min(player->getSkillMod("clothing_assembly"),125);
					int forceBonus = std::min(player->getSkillMod("force_assembly"),45);
					int luckRoll = System::random(std::min(player->getSkillMod("luck"),25) + std::min(player->getSkillMod("force_luck"),30));
					int craftBonus = 0;
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

void WearableContainerObjectImplementation::applySkillModsTo(CreatureObject* creature) const {
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

void WearableContainerObjectImplementation::removeSkillModsFrom(CreatureObject* creature) {
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

bool WearableContainerObjectImplementation::isEquipped() {
	ManagedReference<SceneObject*> parent = getParent().get();
	if (parent != nullptr && parent->isPlayerCreature())
		return true;

	return false;
}
