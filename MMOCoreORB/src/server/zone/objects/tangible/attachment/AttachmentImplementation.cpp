/*
 * AttachmentImplementation.cpp
 *
 *  Created on: Mar 10, 2011
 *      Author: polonel
 */

#include "server/zone/objects/tangible/attachment/Attachment.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/loot/LootManager.h"
#include "server/zone/managers/loot/LootValues.h"
#include "server/globalVariables.h"

void AttachmentImplementation::initializeMembers() {
	if (gameObjectType == SceneObjectType::CLOTHINGATTACHMENT) {
		setOptionsBitmask(32, true);
		attachmentType = CLOTHINGTYPE;

	} else if (gameObjectType == SceneObjectType::ARMORATTACHMENT) {
		setOptionsBitmask(32, true);
		attachmentType = ARMORTYPE;
	}
}

void AttachmentImplementation::initializeTransientMembers() {
	TangibleObjectImplementation::initializeTransientMembers();

	setLoggingName("AttachmentObject");

	// This is here to convert the existing HashTable to a VectorMap
	if (skillModifiers.size() < 1) {
		HashTableIterator<String, int> iterator = skillModMap.iterator();

		String key = "";
		int value = 0;

		for (int i = 0; i < skillModMap.size(); ++i) {
			iterator.getNextKeyAndValue(key, value);

			skillModifiers.put(key, value);
		}
	}
}

void AttachmentImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	auto zoneServer = getZoneServer();

	if (zoneServer == nullptr) {
		return;
	}

	auto lootManager = zoneServer->getLootManager();

	if (lootManager == nullptr) {
		return;
	}

	float level = values->hasExperimentalAttribute("level") ? values->getCurrentValue("level") : 1;
	float bonus = values->hasExperimentalAttribute("modifier") ? values->getCurrentValue("modifier") : 1;
	float rank = LootValues::getLevelRankValue(level, 0.2f, 0.9f);

	int chance = rank * bonus * 100.f;
	int roll = System::random(1000);
	int modCount = 1;

	int pivot = chance - roll;

	if (pivot < 40) {
		modCount = 1;
	} else if (pivot < 70) {
		modCount = System::random(1) + 1;
	} else if (pivot < 100) {
		modCount = System::random(2) + 1;
	} else {
		modCount = System::random(1) + 2;
	}

	if (modCount > globalVariables::lootAttachmentModCount) modCount = globalVariables::lootAttachmentModCount;
	if (modCount < 0) modCount = 0;
	
	for (int i = 0; i < modCount; ++i) {
		int mod = 0;
		if (level >= globalVariables::lootAttachmentMaxLevel) {
			mod = globalVariables::lootAttachmentMax;
		} else {
			float scalingFactor = float(level / globalVariables::lootAttachmentMaxLevel);
			int adjustedStats = (int)(scalingFactor * globalVariables::lootAttachmentMax);
			int minStat = adjustedStats - round(adjustedStats * 0.075f);
			int maxStat = adjustedStats + round(adjustedStats * 0.125f);
			mod = System::random(maxStat - minStat) + minStat;
			if (mod > globalVariables::lootAttachmentMax) mod = globalVariables::lootAttachmentMax;
		}
		String modName = lootManager->getRandomLootableMod(gameObjectType);

		skillModifiers.put(modName, mod == 0 ? 1 : mod);
	}
}

void AttachmentImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(msg, object);

	StringBuffer name;

	for (int i = 0; i < skillModifiers.size(); i++) {
		auto key = skillModifiers.elementAt(i).getKey();
		auto value = skillModifiers.elementAt(i).getValue();

		name << "cat_skill_mod_bonus.@stat_n:" << key;

		msg->insertAttribute(name.toString(), value);

		if (globalVariables::lootAttachmentNameEnabled == true) {
			StringId SEAName;
			SEAName.setStringId("stat_n", key);
			setCustomObjectName("", false);
			setObjectName(SEAName, false);
			setCustomObjectName(getDisplayedName() + " +" + String::valueOf(value), true);
			StringId originalName;
			if (isArmorAttachment())
			    originalName.setStringId("item_n", "socket_gem_armor");
			else
			    originalName.setStringId("item_n", "socket_gem_clothing");
			setObjectName(originalName, true);
        	}
        	
        	name.deleteAll();
	}
}
