/*
 * CreatureTemplate.cpp
 *
 *  Created on: 22/01/2012
 *      Author: victor
 */

#include "CreatureTemplate.h"
#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/managers/variables/creatureVariables.h"
#include <iostream>
#include <string>

CreatureTemplate::CreatureTemplate() {
	missionRandomAttack = 0;
	baseCreatureScale = 1;
	baseCreatureXp = 1;
	baseCreatureMeatAmount = 1;
	baseCreatureHideAmount = 1;
	baseCreatureBoneAmount = 1;
	baseCreatureMilk = 1;
	baseCreatureLevel = 1;
	baseCreatureChanceHit = 1;
	baseCreatureFerocity = 1;
	baseCreatureDamageMax = 1;
	baseCreatureDamageMin = 1;
	baseCreatureHAM = 1;
	baseCreatureHAMmax = 1;
	baseCreatureResists = 1;
	conversationTemplate = 0;
	kinetic = 0;
	energy = 0;
	electricity = 0;
	stun = 0;
	blast = 0;
	heat = 0;
	cold = 0;
	acid = 0;
	lightSaber = 0;

	scale = 1.f;

	objectName = "";
	randomNameType = 0;
	mobType = 0;
	randomNameTag = false;
	customName = "";
	planetMapCategory = 0;
	mapCategoryName = "";
	planetMapSubCategory = 0;
	mapSubCategoryName = "";
	socialGroup = "";
	faction = "";
	level = 0;
	chanceHit = 0.f;
	damageMin = 0;
	damageMax = 0;
	attackSpeed = 0.0f;
	specialDamageMult = 1.f;
	range = 0;
	baseXp = 0;
	baseHAM = 0;
	baseHAMmax = 0;
	armor = 0;
	meatType = "";
	meatAmount = 0;
	hideType = "";
	hideAmount = 0;
	boneType = "";
	boneAmount = 0;
	milkType = "";
	milk = 0.f;
	tamingChance = 0.f;
	ferocity = 0;
	aggroRadius = 0;
	pvpBitmask = 0;
	creatureBitmask = 0;
	diet = 0;
	optionsBitmask = 0;
	customAiMap = 0;
	tauntable = true;
	healerType = "";
	lightsaberColor = 0;

	primaryWeapon = "";
	secondaryWeapon = "";
	thrownWeapon = "",

	templates.removeAll();

	primaryAttacks = new CreatureAttackMap();
	secondaryAttacks = new CreatureAttackMap();

	aiTemplate = "example";
	defaultWeapon = "";
	defaultAttack = "defaultattack";
	controlDeviceTemplate = "object/intangible/pet/pet_control.iff";
	containerComponentTemplate = "";
	reactionStf = "";
	personalityStf = "";
}

CreatureTemplate::~CreatureTemplate() {
	templates.removeAll();

	delete primaryAttacks;
	primaryAttacks = nullptr;

	delete secondaryAttacks;
	secondaryAttacks = nullptr;
}

void CreatureTemplate::readObject(LuaObject* templateData, int creatureDiff, float cdpMult) {
	conversationTemplate = String(templateData->getStringField("conversationTemplate").trim()).hashCode();
	objectName = templateData->getStringField("objectName").trim();
	randomNameType = templateData->getIntField("randomNameType");
	randomNameTag = templateData->getBooleanField("randomNameTag");

	mapCategoryName = String(templateData->getStringField("planetMapCategory").trim());
	planetMapCategory = mapCategoryName.hashCode();

	mapSubCategoryName = String(templateData->getStringField("planetMapSubCategory").trim());
	planetMapSubCategory = mapSubCategoryName.hashCode();

	mobType = templateData->getIntField("mobType");
	customName = templateData->getStringField("customName").trim();
	socialGroup = templateData->getStringField("socialGroup").trim();
	faction = templateData->getStringField("faction").trim().toLowerCase();
	level = templateData->getIntField("level");
	chanceHit = templateData->getFloatField("chanceHit");
	damageMin = templateData->getIntField("damageMin");
	damageMax = templateData->getIntField("damageMax");
	specialDamageMult = templateData->getFloatField("specialDamageMult");
	attackSpeed = templateData->getFloatField("attackSpeed");
	if (specialDamageMult < 0.001f) specialDamageMult = 1.f; // could use numeric_limit here, but this will prevent people from putting tiny modifiers in as well.
	baseXp = templateData->getIntField("baseXp");
	baseHAM = templateData->getIntField("baseHAM");
	baseHAMmax = templateData->getIntField("baseHAMmax");
	armor = templateData->getIntField("armor");
	meatType = templateData->getStringField("meatType").trim();
	meatAmount = templateData->getIntField("meatAmount");
	hideType = templateData->getStringField("hideType").trim();
	hideAmount = templateData->getIntField("hideAmount");
	boneType = templateData->getStringField("boneType").trim();
	boneAmount = templateData->getIntField("boneAmount");
	milk = templateData->getIntField("milk");
	tamingChance = templateData->getFloatField("tamingChance");
	ferocity = templateData->getIntField("ferocity");
	aggroRadius = templateData->getIntField("aggroRadius");
	pvpBitmask = templateData->getIntField("pvpBitmask");
	creatureBitmask = templateData->getIntField("creatureBitmask");
	diet = templateData->getIntField("diet");
	optionsBitmask = templateData->getIntField("optionsBitmask");
	patrolPathTemplate = templateData->getStringField("patrolPathTemplate");
	defaultWeapon = templateData->getStringField("defaultWeapon");
	tauntable = templateData->getBooleanField("tauntable", true);
	healerType = templateData->getStringField("healerType").trim();
	lightsaberColor = templateData->getIntField("lightsaberColor");
	missionRandomAttack = templateData->getIntField("missionRandomAttack");
	if (creatureVars.creatureRandomDifficultyEnabled == false) {
		creatureDifficulty = 1;
	} else {
		creatureDifficulty = creatureDiff;
	}
	cdpMultiplier = cdpMult;
	
	if(!templateData->getStringField("defaultAttack").isEmpty())
		defaultAttack = templateData->getStringField("defaultAttack");

	if(!templateData->getStringField("customAiMap").isEmpty())
		customAiMap = templateData->getStringField("customAiMap").hashCode();

	scale = templateData->getFloatField("scale");

	if (!templateData->getStringField("milkType").isEmpty()) {
		milkType = templateData->getStringField("milkType").trim();
	}
	baseMobLevel = (float)level;
	levelPercentDifference = 1.0f;
	if (missionRandomAttack == 0) {
		scale *= creatureVars.creatureBaseScaleMultiplier;
		baseXp *= creatureVars.creatureBaseXPMultiplier;
		meatAmount *= creatureVars.creatureBaseMeatAmountMultiplier;
		hideAmount *= creatureVars.creatureBaseHideAmountMultiplier;
		boneAmount *= creatureVars.creatureBaseBoneAmountMultiplier;
		milk *= creatureVars.creatureBaseMilkMultiplier;
		level *= creatureVars.creatureBaseLevelMultiplier;
		chanceHit *= creatureVars.creatureBaseChanceHitMultiplier;
		ferocity *= creatureVars.creatureBaseFerocityMultiplier;
		damageMax *= creatureVars.creatureBaseDamageMaxMultiplier;
		damageMin *= creatureVars.creatureBaseDamageMinMultiplier;
		baseHAM *= creatureVars.creatureBaseHAMMultiplier;
		baseHAMmax *= creatureVars.creatureBaseHAMMaxMultiplier;
		baseMobLevel = (float)level;
		if (creatureDifficulty >=1 && creatureDifficulty <= 3) {
			for(int i = 2; i <= creatureDifficulty; ++i) {
				baseCreatureScale += creatureVars.creatureModBaseScaleModifier;
				baseCreatureXp += creatureVars.creatureModBaseXPModifier;
				baseCreatureMeatAmount += creatureVars.creatureModBaseMeatAmountModifier;
				baseCreatureHideAmount += creatureVars.creatureModBaseHideAmountModifier;
				baseCreatureBoneAmount += creatureVars.creatureModBaseBoneAmountModifier;
				baseCreatureMilk += creatureVars.creatureModBaseMilkModifier;
				baseCreatureLevel += creatureVars.creatureModBaseLevelModifier;
				baseCreatureChanceHit += creatureVars.creatureModBaseChanceHitModifier;
				baseCreatureFerocity += creatureVars.creatureModBaseFerocityModifier;
				baseCreatureDamageMax += creatureVars.creatureModBaseDamageMaxModifier;
				baseCreatureDamageMin += creatureVars.creatureModBaseDamageMinModifier;
				baseCreatureHAM += creatureVars.creatureModBaseHAMModifier;
				baseCreatureHAMmax += creatureVars.creatureModBaseHAMMaxModifier;
				baseCreatureResists += creatureVars.creatureModBaseResistsModifier;
			}
		} else if (creatureDifficulty >= 4) {
			for(int i = 5; i <= creatureDifficulty; ++i) {
				baseCreatureScale += creatureVars.creatureModBaseScaleModifier;
				baseCreatureXp += creatureVars.creatureModBaseXPModifier;
				baseCreatureMeatAmount += creatureVars.creatureModBaseMeatAmountModifier;
				baseCreatureHideAmount += creatureVars.creatureModBaseHideAmountModifier;
				baseCreatureBoneAmount += creatureVars.creatureModBaseBoneAmountModifier;
				baseCreatureMilk += creatureVars.creatureModBaseMilkModifier;
				baseCreatureLevel += creatureVars.creatureModBaseLevelModifier;
				baseCreatureChanceHit += creatureVars.creatureModBaseChanceHitModifier;
				baseCreatureFerocity += creatureVars.creatureModBaseFerocityModifier;
				baseCreatureDamageMax += creatureVars.creatureModBaseDamageMaxModifier;
				baseCreatureDamageMin += creatureVars.creatureModBaseDamageMinModifier;
				baseCreatureHAM += creatureVars.creatureModBaseHAMModifier;
				baseCreatureHAMmax += creatureVars.creatureModBaseHAMMaxModifier;
				baseCreatureResists += creatureVars.creatureModBaseResistsModifier;
			}
		}
		if (creatureDifficulty >= 4) {
			baseCreatureLevel += creatureVars.creatureModBaseLevelModifier * cdpMultiplier;
			baseCreatureChanceHit += creatureVars.creatureModBaseChanceHitModifier * cdpMultiplier;
			baseCreatureFerocity += creatureVars.creatureModBaseFerocityModifier * cdpMultiplier;
			baseCreatureDamageMax += creatureVars.creatureModBaseDamageMaxModifier * cdpMultiplier;
			baseCreatureDamageMin += creatureVars.creatureModBaseDamageMinModifier * cdpMultiplier;
			baseCreatureHAM += creatureVars.creatureModBaseHAMModifier * cdpMultiplier;
			baseCreatureHAMmax += creatureVars.creatureModBaseHAMMaxModifier * cdpMultiplier;
			baseCreatureResists += creatureVars.creatureModBaseResistsModifier * cdpMultiplier;
		}

		scale *= baseCreatureScale;
		baseXp *= baseCreatureXp;
		meatAmount *= baseCreatureMeatAmount;
		hideAmount *= baseCreatureHideAmount;
		boneAmount *= baseCreatureBoneAmount;
		milk *= baseCreatureMilk;
		level *= baseCreatureLevel;
		chanceHit *= baseCreatureChanceHit;
		ferocity *= baseCreatureFerocity;
		damageMax *= baseCreatureDamageMax;
		damageMin *= baseCreatureDamageMin;
		baseHAM *= baseCreatureHAM;
		baseHAMmax *= baseCreatureHAMmax;
		
		if (creatureDifficulty == 2 && System::random(1000) > 975) armor += 1;
		if (creatureDifficulty == 3 && System::random(1000) > 975) armor += 2;
		if (creatureDifficulty == 4 && System::random(1000) > 975) armor += 1;
		if (creatureDifficulty == 5 && System::random(1000) > 975) armor += 2;
		if (creatureDifficulty == 6 && System::random(1000) > 975) armor += 3;
		if (armor > 3) armor = 3;
		
		levelPercentDifference = (level - baseMobLevel) / baseMobLevel;
		if (creatureDifficulty <= 1) levelPercentDifference = 1.0f;

		if (damageMin >= damageMax) damageMin = damageMax * 0.9;
		if (baseHAMmax >= baseHAM) baseHAM = baseHAMmax * 0.9;
		
		damageMin = std::max(1,damageMin);
		damageMax = std::max(2,damageMax);
		baseHAM = std::max(1,baseHAM);
		baseHAMmax = std::max(2,baseHAMmax);
	}
	
	LuaObject res = templateData->getObjectField("resists");
	if (res.getTableSize() == 9) {
		kinetic = res.getFloatAt(1);
		if (creatureDifficulty >= 4 && kinetic < 0) {
			kinetic = .09 * level;
			if (kinetic > creatureVars.creatureKineticMaxResists) {
				kinetic = creatureVars.creatureKineticMaxResists;
			}
		} else {
			if (kinetic > 100) {
				kinetic = (((kinetic - 100) * baseCreatureResists) * levelPercentDifference) + 100;
				if (kinetic > 100 + creatureVars.creatureKineticMaxResists) {
					kinetic = 100 + creatureVars.creatureKineticMaxResists;
				}
			} else {
				kinetic = (kinetic * baseCreatureResists) * levelPercentDifference;
				if (kinetic > creatureVars.creatureKineticMaxResists) {
					kinetic = creatureVars.creatureKineticMaxResists;
				}
			}
			if (kinetic < 0) {
				kinetic = -1;
			}
		}
		energy = res.getFloatAt(2);
		if (creatureDifficulty >= 4 && energy < 0) {
			energy = .09 * level;
			if (energy > creatureVars.creatureEnergyMaxResists) {
				energy = creatureVars.creatureEnergyMaxResists;
			}
		} else {
			if (energy > 100) {
				energy = ((((energy - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (energy > 100 + creatureVars.creatureEnergyMaxResists) {
					energy = 100 + creatureVars.creatureEnergyMaxResists;
				}
			} else {
				energy = (energy * baseCreatureResists) * levelPercentDifference;
				if (energy > creatureVars.creatureEnergyMaxResists) {
					energy = creatureVars.creatureEnergyMaxResists;
				}
			}
			if (energy < 0) {
				energy = -1;
			}
		}
		blast = res.getFloatAt(3);
		if (creatureDifficulty >= 4 && blast < 0) {
			blast = .09 * level;
			if (blast > creatureVars.creatureBlastMaxResists) {
				blast = creatureVars.creatureBlastMaxResists;
			}
		} else {
			if (blast > 100) {
				blast = ((((blast - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (blast > 100 + creatureVars.creatureBlastMaxResists) {
					blast = 100 + creatureVars.creatureBlastMaxResists;
				}
			} else {
				blast = (blast * baseCreatureResists) * levelPercentDifference;
				if (blast > creatureVars.creatureBlastMaxResists) {
					blast = creatureVars.creatureBlastMaxResists;
				}
			}
			if (blast < 0) {
				blast = -1;
			}
		}
		heat = res.getFloatAt(4);
		if (creatureDifficulty >= 4 && heat < 0) {
			heat = .09 * level;
			if (heat > creatureVars.creatureHeatMaxResists) {
				heat = creatureVars.creatureHeatMaxResists;
			}
		} else {
			if (heat > 100) {
				heat = ((((heat - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (heat > 100 + creatureVars.creatureHeatMaxResists) {
					heat = 100 + creatureVars.creatureHeatMaxResists;
				}
			} else {
				heat = (heat * baseCreatureResists) * levelPercentDifference;
				if (heat > creatureVars.creatureHeatMaxResists) {
					heat = creatureVars.creatureHeatMaxResists;
				}
			}
			if (heat < 0) {
				heat = -1;
			}
		}
		cold = res.getFloatAt(5);
		if (creatureDifficulty >= 4 && cold < 0) {
			cold = .09 * level;
			if (cold > creatureVars.creatureColdMaxResists) {
				cold = creatureVars.creatureColdMaxResists;
			}
		} else {
			if (cold > 100) {
				cold = ((((cold - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (cold > 100 + creatureVars.creatureColdMaxResists) {
					cold = 100 + creatureVars.creatureColdMaxResists;
				}
			} else {
				cold = (cold * baseCreatureResists) * levelPercentDifference;
				if (cold > creatureVars.creatureColdMaxResists) {
					cold = creatureVars.creatureColdMaxResists;
				}
			}
			if (cold < 0) {
				cold = -1;
			}
		}
		electricity = res.getFloatAt(6);
		if (creatureDifficulty >= 4 && electricity < 0) {
			electricity = .09 * level;
			if (electricity > creatureVars.creatureAcidMaxResists) {
				electricity = creatureVars.creatureAcidMaxResists;
			}
		} else {
			if (electricity > 100) {
				electricity = ((((electricity - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (electricity > 100 + creatureVars.creatureElectricityMaxResists) {
					electricity = 100 + creatureVars.creatureElectricityMaxResists;
				}
			} else {
				electricity = (electricity * baseCreatureResists) * levelPercentDifference;
				if (electricity > creatureVars.creatureElectricityMaxResists) {
					electricity = creatureVars.creatureElectricityMaxResists;
				}
			}
			if (electricity < 0) {
				electricity = -1;
			}
		}
		acid = res.getFloatAt(7);
		if (creatureDifficulty >= 4 && acid < 0) {
			acid = .09 * level;
			if (acid > creatureVars.creatureAcidMaxResists) {
				acid = creatureVars.creatureAcidMaxResists;
			}
		} else {
			if (acid > 100) {
				acid = ((((acid - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (acid > 100 + creatureVars.creatureAcidMaxResists) {
					acid = 100 + creatureVars.creatureAcidMaxResists;
				}
			} else {
				acid = (acid * baseCreatureResists) * levelPercentDifference;
				if (acid > creatureVars.creatureAcidMaxResists) {
					acid = creatureVars.creatureAcidMaxResists;
				}
			}
			if (acid < 0) {
				acid = -1;
			}
		}
		stun = res.getFloatAt(8);
		if (creatureDifficulty >= 4 && stun < 0) {
			stun = .09 * level;
			if (stun > creatureVars.creatureStunMaxResists) {
				stun = creatureVars.creatureStunMaxResists;
			}
		} else {
			if (stun > 100) {
				stun = ((((stun - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (stun > 100 + creatureVars.creatureStunMaxResists) {
					stun = 100 + creatureVars.creatureStunMaxResists;
				}
			} else {
				stun = (stun * baseCreatureResists) * levelPercentDifference;
				if (stun > creatureVars.creatureStunMaxResists) {
					stun = creatureVars.creatureStunMaxResists;
				}
			}
			if (stun < 0) {
				stun = -1;
			}
		}
		lightSaber = res.getFloatAt(9);
		if (creatureDifficulty >= 4 && lightSaber < 0) {
			lightSaber = .09 * level;
			if (lightSaber > creatureVars.creatureLightsaberMaxResists) {
				lightSaber = creatureVars.creatureLightsaberMaxResists;
			}
		} else {
			if (lightSaber > 100) {
				lightSaber = ((((lightSaber - 100) * baseCreatureResists) * levelPercentDifference) + 100);
				if (lightSaber > 100 + creatureVars.creatureLightsaberMaxResists) {
					lightSaber = 100 + creatureVars.creatureLightsaberMaxResists;
				}
			} else {
				lightSaber = (lightSaber * baseCreatureResists) * levelPercentDifference;
				if (lightSaber > creatureVars.creatureLightsaberMaxResists) {
					lightSaber = creatureVars.creatureLightsaberMaxResists;
				}
			}
			if (lightSaber < 0) {
				lightSaber = -1;
			}
		}	
	}
	res.pop();

	level = std::max(1,std::min(creatureVars.creatureMaxLevel, level));

	LuaObject temps = templateData->getObjectField("templates");
	if (temps.isValidTable()) {
		for (int i = 1; i <= temps.getTableSize(); ++i) {
			String tempName = temps.getStringAt(i).trim();

			if (tempName.endsWith(".iff")) {
				templates.add(tempName);
				continue;
			}

			const Vector<String>& dressGroup = CreatureTemplateManager::instance()->getDressGroup(tempName);
			templates.addAll(dressGroup);
		}
	}

	temps.pop();

	LuaObject lootCollections = templateData->getObjectField("lootGroups");
	lootgroups.readObject(&lootCollections, level);
	lootCollections.pop();

	primaryWeapon = templateData->getStringField("primaryWeapon");
	secondaryWeapon = templateData->getStringField("secondaryWeapon");
	thrownWeapon = templateData->getStringField("thrownWeapon");

	LuaObject attackList = templateData->getObjectField("primaryAttacks");
	if (attackList.isValidTable()) {
		int size = attackList.getTableSize();
		lua_State* L = attackList.getLuaState();
		for (int i = 1; i <= size; ++i) {
			lua_rawgeti(L, -1, i);
			LuaObject atk(L);

			if (atk.isValidTable()) {
				int atkSize = atk.getTableSize();
				if (atkSize == 2) {
					String com = atk.getStringAt(1).trim();
					String arg = atk.getStringAt(2).trim();

					primaryAttacks->addAttack(com, arg);
				}
			}

			atk.pop();
		}
	}

	attackList.pop();

	attackList = templateData->getObjectField("secondaryAttacks");
	if (attackList.isValidTable()) {
		int size = attackList.getTableSize();
		lua_State* L = attackList.getLuaState();
		for (int i = 1; i <= size; ++i) {
			lua_rawgeti(L, -1, i);
			LuaObject atk(L);

			if (atk.isValidTable()) {
				int atkSize = atk.getTableSize();
				if (atkSize == 2) {
					String com = atk.getStringAt(1).trim();
					String arg = atk.getStringAt(2).trim();

					secondaryAttacks->addAttack(com, arg);
				}
			}

			atk.pop();
		}
	}

	attackList.pop();

	LuaObject hueTable = templateData->getObjectField("hues");
	if (hueTable.isValidTable()) {
		for (int i = 1; i <= hueTable.getTableSize(); ++i) {
			hues.add(hueTable.getIntAt(i));
		}
	}

	hueTable.pop();

	outfit = templateData->getStringField("outfit");

	aiTemplate = templateData->getStringField("aiTemplate");

	if(!templateData->getStringField("controlDeviceTemplate").isEmpty())
		controlDeviceTemplate = templateData->getStringField("controlDeviceTemplate");

	containerComponentTemplate = templateData->getStringField("containerComponentTemplate");

	reactionStf = templateData->getStringField("reactionStf");
	personalityStf = templateData->getStringField("personalityStf");
}
