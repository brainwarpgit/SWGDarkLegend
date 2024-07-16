/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#include "SharedLabratory.h"
#include "server/zone/managers/crafting/CraftingManager.h"
#include "server/zone/objects/tangible/misc/CustomIngredient.h"
#include "server/zone/objects/manufactureschematic/ingredientslots/ComponentSlot.h"
#include "server/zone/objects/manufactureschematic/ingredientslots/ResourceSlot.h"
#include "server/globalVariables.h"

SharedLabratory::SharedLabratory() : Logger("SharedLabratory"){
}

SharedLabratory::~SharedLabratory() {
}

void SharedLabratory::initialize(ZoneServer* server) {
	zoneServer = server;
}

float SharedLabratory::calculateExperimentationValueModifier(int experimentationResult, int pointsAttempted) {
	// Make it so failure detract
	if (globalVariables::craftingNewExperimentEnabled == true) {
		float results;
		switch (experimentationResult) {
		case CraftingManager::AMAZINGSUCCESS:
			results = 0.08f;
			break;
		case CraftingManager::GREATSUCCESS:
			results = 0.07f;
			break;
		case CraftingManager::GOODSUCCESS:
			results = 0.055f;
			break;
		case CraftingManager::MODERATESUCCESS:
			results = 0.03f;
			break;
		case CraftingManager::SUCCESS:
			results = 0.02f;
			break;
		case CraftingManager::MARGINALSUCCESS:
			results = 0.01f;
			break;
		case CraftingManager::OK:
			results = 0.05f;
			break;
		case CraftingManager::BARELYSUCCESSFUL:
			results = 0.00f;
			break;
		case CraftingManager::CRITICALFAILURE:
			results = -0.01f;
			break;
		default:
			results = 0;
			break;
		}
		results *= pointsAttempted;
		return results;
	} else {
		float results;
		switch (experimentationResult) {
		case CraftingManager::AMAZINGSUCCESS:
			results = 0.08f;
			break;
		case CraftingManager::GREATSUCCESS:
			results = 0.07f;
			break;
		case CraftingManager::GOODSUCCESS:
			results = 0.055f;
			break;
		case CraftingManager::MODERATESUCCESS:
			results = 0.015f;
			break;
		case CraftingManager::SUCCESS:
			results = 0.01f;
			break;
		case CraftingManager::MARGINALSUCCESS:
			results = 0.00f;
			break;
		case CraftingManager::OK:
			results = -0.04f;
			break;
		case CraftingManager::BARELYSUCCESSFUL:
			results = -0.07f;
			break;
		case CraftingManager::CRITICALFAILURE:
			results = -0.08f;
			break;
		default:
			results = 0;
			break;
		}
		results *= pointsAttempted;
		return results;
	}
}
float SharedLabratory::calculateAssemblyValueModifier(int assemblyResult) {
	if (assemblyResult == CraftingManager::AMAZINGSUCCESS && globalVariables::craftingNewAssemblyEnabled == true) {
		return 1.10f;
	} else {
		return 1.05f;
	}

	float result = 1.1f - (assemblyResult * .1f);

	return result;
}

float SharedLabratory::getAssemblyPercentage(float value) {

	float percentage = (value * (0.000015f * value + .015f)) * 0.01f;
	return percentage;
}
float SharedLabratory::getWeightedValue(ManufactureSchematic* manufactureSchematic, int type) {

	int nsum = 0;
	float weightedAverage = 0;
	int n = 0;
	int stat = 0;

	for (int i = 0; i < manufactureSchematic->getSlotCount(); ++i) {

		Reference<IngredientSlot* > ingredientslot = manufactureSchematic->getSlot(i);
		Reference<DraftSlot* > draftslot = manufactureSchematic->getDraftSchematic()->getDraftSlot(i);

		if (ingredientslot->isComponentSlot()) {
			ComponentSlot* compSlot = cast<ComponentSlot*>(ingredientslot.get());

			if (compSlot == nullptr)
				continue;

			ManagedReference<TangibleObject*> tano = compSlot->getPrototype();

			if (tano == nullptr || !tano->isCustomIngredient())
				continue;

			ManagedReference<CustomIngredient*> component = cast<CustomIngredient*>( tano.get());

			if (component == nullptr)
				continue;

			n = draftslot->getQuantity();
			stat = component->getValueOf(type);

			if (stat != 0) {
				nsum += n;
				weightedAverage += (stat * n);
			}

			continue;
		}

		/// If resource slot, continue
		if(!ingredientslot->isResourceSlot())
			continue;

		ResourceSlot* resSlot = cast<ResourceSlot*>(ingredientslot.get());

		if(resSlot == nullptr)
			continue;

		ManagedReference<ResourceSpawn* > spawn = resSlot->getCurrentSpawn();

		if (spawn == nullptr) {
			error("Spawn object is null when running getWeightedValue");
			return 0.0f;
		}

		n = draftslot->getQuantity();
		stat = spawn->getValueOf(type);

		if (stat != 0) {

			nsum += n;
			weightedAverage += (stat * n);
		}
	}

	if (weightedAverage != 0)
		weightedAverage /= float(nsum);

	return weightedAverage;
}
int SharedLabratory::calculateAssemblySuccess(CreatureObject* player,DraftSchematic* draftSchematic, float effectiveness){
	if (globalVariables::craftingNewAssemblyEnabled == true) {
		float cityBonus = std::min(player->getSkillMod("private_spec_assembly"),20);
		float assemblySkill = std::min(player->getSkillMod(draftSchematic->getAssemblySkill()),125);
		float forceBonus = std::min(player->getSkillMod("force_assembly"),45);
		float luckRoll = System::random(std::min(player->getSkillMod("luck"),25) + std::min(player->getSkillMod("force_luck"),30));
		float craftBonus = 0;
		if (player->hasBuff(BuffCRC::FOOD_CRAFT_BONUS)) {
			Buff* buff = player->getBuff(BuffCRC::FOOD_CRAFT_BONUS);
			if (buff != nullptr) {
				craftBonus = buff->getSkillModifierValue("craft_bonus");
			}
		}
		float luckSkill = System::random(125) + luckRoll + effectiveness + cityBonus + forceBonus + craftBonus;
		assemblySkill += luckRoll + effectiveness + cityBonus + forceBonus + craftBonus;
		float failMitigate = std::min(player->getSkillMod("force_failure_reduction"),10);
		float failRoll = System::random(assemblySkill + luckRoll + effectiveness + cityBonus + forceBonus + craftBonus + 100);	
		float toolModifier = 1.0f + (effectiveness / 10);	
		float failSkill = toolModifier * ((failRoll / 10) + failMitigate);

	//	player->sendSystemMessage("cityBonus " + std::to_string(cityBonus));
	//	player->sendSystemMessage("forceBonus " + std::to_string(forceBonus));
	//	player->sendSystemMessage("luckRoll " + std::to_string(luckRoll));
	//	player->sendSystemMessage("craftBonus " + std::to_string(craftBonus));
	//	player->sendSystemMessage("effectiveness " + std::to_string(effectiveness));
	//	player->sendSystemMessage("luckSkill " + std::to_string(luckSkill));
	//	player->sendSystemMessage("assemblySkill " + std::to_string(assemblySkill));k
	//	player->sendSystemMessage("failMitigate " + std::to_string(failMitigate));
	//	player->sendSystemMessage("failRoll " + std::to_string(failRoll));	
	//	player->sendSystemMessage("toolModifier " + std::to_string(toolModifier));	
	//	player->sendSystemMessage("failSkill " + std::to_string(failSkill));
		
		if(failSkill < 10) {
			assemblySkill -= 20;
			player->sendSystemMessage("Critical Failure!");
		}

		if (assemblySkill >= 140 || luckSkill >= 140)
			return CraftingManager::AMAZINGSUCCESS;	

		if (assemblySkill >= 120 || luckSkill >= 120)
			return CraftingManager::GREATSUCCESS;

		if (assemblySkill >= 100 || luckSkill >= 100)
			return CraftingManager::GOODSUCCESS;

		if (assemblySkill >= 80 || luckSkill >= 80)
			return CraftingManager::MODERATESUCCESS;

		if (assemblySkill >= 60 || luckSkill >= 60)
			return CraftingManager::SUCCESS;

		if (assemblySkill >= 40 || luckSkill >= 40)
			return CraftingManager::MARGINALSUCCESS;

		if (assemblySkill >= 20 || luckSkill >= 20)
			return CraftingManager::OK;

		return CraftingManager::BARELYSUCCESSFUL;
	} else {
		// assemblyPoints is 0-12
		/// City bonus should be 10
		float cityBonus = player->getSkillMod("private_spec_assembly");

		int assemblySkill = player->getSkillMod(draftSchematic->getAssemblySkill());
		assemblySkill += player->getSkillMod("force_assembly");

		float assemblyPoints = ((float)assemblySkill) / 10.0f;
		int failMitigate = (player->getSkillMod(draftSchematic->getAssemblySkill()) - 100 + cityBonus) / 7;
		failMitigate += player->getSkillMod("force_failure_reduction");

		if(failMitigate < 0)
			failMitigate = 0;
		if(failMitigate > 5)
			failMitigate = 5;

		// 0.85-1.15
		float toolModifier = 1.0f + (effectiveness / 100.0f);

		//Pyollian Cake
		float craftbonus = 0;
		if (player->hasBuff(BuffCRC::FOOD_CRAFT_BONUS)) {
			Buff* buff = player->getBuff(BuffCRC::FOOD_CRAFT_BONUS);

			if (buff != nullptr) {
				craftbonus = buff->getSkillModifierValue("craft_bonus");
				toolModifier *= 1.0f + (craftbonus / 100.0f);
			}
		}

		int luckRoll = System::random(100) + cityBonus;

		if(luckRoll > (95 - craftbonus))
			return CraftingManager::AMAZINGSUCCESS;

		if(luckRoll < (5 - craftbonus - failMitigate))
			luckRoll -= System::random(100);

		//if(luckRoll < 5)
		//	return CRITICALFAILURE;

		luckRoll += System::random(player->getSkillMod("luck") + player->getSkillMod("force_luck"));

		int assemblyRoll = (toolModifier * (luckRoll + (assemblyPoints * 5)));

		if (assemblyRoll > 70)
			return CraftingManager::GREATSUCCESS;

		if (assemblyRoll > 60)
			return CraftingManager::GOODSUCCESS;

		if (assemblyRoll > 50)
			return CraftingManager::MODERATESUCCESS;

		if (assemblyRoll > 40)
			return CraftingManager::SUCCESS;

		if (assemblyRoll > 30)
			return CraftingManager::MARGINALSUCCESS;

		if (assemblyRoll > 20)
			return CraftingManager::OK;

		return CraftingManager::BARELYSUCCESSFUL;
	}
}

