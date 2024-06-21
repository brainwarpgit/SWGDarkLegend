/*
 * CreatureTemplateManager.cpp
 *
 *  Created on: 27/05/2011
 *      Author: victor
 */

#include "CreatureTemplateManager.h"
#include "SpawnGroup.h"
#include "conf/ConfigManager.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include <unordered_map>
#include <string>
#include "server/globalVariables.h"

AtomicInteger CreatureTemplateManager::loadedMobileTemplates;

int CreatureTemplateManager::DEBUG_MODE = 0;
int CreatureTemplateManager::ERROR_CODE = NO_ERROR;

CreatureTemplateManager::CreatureTemplateManager() : Logger("CreatureTemplateManager") {
	/*setLogging(false);
		setGlobalLogging(true);*/

	setLoggingName("CreatureTemplateManager");

	globalAttackSpeedOverride = 0.0f;

	lua = new Lua();
	lua->init();

	if (DEBUG_MODE) {
		setLogging(true);
		lua->setLogging(true);
	}

	hashTable.setNullValue(nullptr);

	lua->registerFunction("includeFile", includeFile);
	lua->registerFunction("addTemplate", addTemplate);
	lua->registerFunction("addWeapon", addWeapon);
	lua->registerFunction("addConversationTemplate", addConversationTemplate);
	lua->registerFunction("addLairTemplate", addLairTemplate);
	lua->registerFunction("addSpawnGroup", addSpawnGroup);
	lua->registerFunction("addDestroyMissionGroup", addDestroyMissionGroup);
	lua->registerFunction("addPatrolPathTemplate", addPatrolPathTemplate);
	lua->registerFunction("addOutfitGroup", addOutfitGroup);
	lua->registerFunction("addDressGroup", addDressGroup);

	lua->setGlobalInt("NONE", ObjectFlag::NONE);
	lua->setGlobalInt("ATTACKABLE", ObjectFlag::ATTACKABLE);
	lua->setGlobalInt("AGGRESSIVE", ObjectFlag::AGGRESSIVE);
	lua->setGlobalInt("OVERT", ObjectFlag::OVERT);
	lua->setGlobalInt("TEF", ObjectFlag::TEF);
	lua->setGlobalInt("PLAYER", ObjectFlag::PLAYER);
	lua->setGlobalInt("ENEMY", ObjectFlag::ENEMY);
	lua->setGlobalInt("WILLBEDECLARED", ObjectFlag::WILLBEDECLARED);
	lua->setGlobalInt("WASDECLARED", ObjectFlag::WASDECLARED);

	lua->setGlobalInt("CONVERSABLE", OptionBitmask::CONVERSE);
	lua->setGlobalInt("AIENABLED", OptionBitmask::AIENABLED);
	lua->setGlobalInt("INVULNERABLE", OptionBitmask::INVULNERABLE);
	lua->setGlobalInt("FACTIONAGGRO", OptionBitmask::FACTIONAGGRO);
	lua->setGlobalInt("INTERESTING", OptionBitmask::INTERESTING);
	lua->setGlobalInt("JTLINTERESTING", OptionBitmask::JTLINTERESTING);

	lua->setGlobalInt("PACK", ObjectFlag::PACK);
	lua->setGlobalInt("HERD", ObjectFlag::HERD);
	lua->setGlobalInt("KILLER", ObjectFlag::KILLER);
	lua->setGlobalInt("STALKER", ObjectFlag::STALKER);
	lua->setGlobalInt("BABY", ObjectFlag::BABY);
	lua->setGlobalInt("LAIR", ObjectFlag::LAIR);
	lua->setGlobalInt("HEALER", ObjectFlag::HEALER);
	lua->setGlobalInt("NOINTIMIDATE", ObjectFlag::NOINTIMIDATE);
	lua->setGlobalInt("NODOT", ObjectFlag::NODOT);

	lua->setGlobalInt("CARNIVORE", ObjectFlag::CARNIVORE);
	lua->setGlobalInt("HERBIVORE", ObjectFlag::HERBIVORE);

	// NameManager Types
	lua->setGlobalInt("NAME_TAG", NameManagerType::TAG);
	lua->setGlobalInt("NAME_GENERIC", NameManagerType::GENERIC);
	lua->setGlobalInt("NAME_R2", NameManagerType::R2);
	lua->setGlobalInt("NAME_R3", NameManagerType::R3);
	lua->setGlobalInt("NAME_R4", NameManagerType::R4);
	lua->setGlobalInt("NAME_R5", NameManagerType::R5);
	lua->setGlobalInt("NAME_3PO", NameManagerType::DROID_3P0);
	lua->setGlobalInt("NAME_EG6", NameManagerType::DROID_EG6);
	lua->setGlobalInt("NAME_WED", NameManagerType::DROID_WED);
	lua->setGlobalInt("NAME_LE", NameManagerType::DROID_LE);
	lua->setGlobalInt("NAME_RA7", NameManagerType::DROID_RA7);
	lua->setGlobalInt("NAME_STORMTROOPER", NameManagerType::STORMTROOPER);
	lua->setGlobalInt("NAME_SCOUTTROOPER", NameManagerType::SCOUTTROOPER);
	lua->setGlobalInt("NAME_DARKTROOPER", NameManagerType::DARKTROOPER);
	lua->setGlobalInt("NAME_SWAMPTROOPER", NameManagerType::SWAMPTROOPER);

	lua->setGlobalInt("MOB_HERBIVORE", AiAgent::MOB_HERBIVORE);
	lua->setGlobalInt("MOB_CARNIVORE", AiAgent::MOB_CARNIVORE);
	lua->setGlobalInt("MOB_NPC", AiAgent::MOB_NPC);
	lua->setGlobalInt("MOB_DROID", AiAgent::MOB_DROID);
	lua->setGlobalInt("MOB_ANDROID", AiAgent::MOB_ANDROID);
	lua->setGlobalInt("MOB_VEHICLE", AiAgent::MOB_VEHICLE);

	loadLuaConfig();
}

void CreatureTemplateManager::loadLuaConfig() {
	lua->runFile("scripts/managers/creature_manager.lua");

	globalAttackSpeedOverride = lua->getGlobalFloat("globalAttackSpeedOverride");

	LuaObject luaObject = lua->getGlobalObject("aiSpeciesData");

	if (luaObject.isValidTable()) {
		for (int i = 1; i <= luaObject.getTableSize(); ++i) {
			LuaObject speciesData = luaObject.getObjectAt(i);

			if (speciesData.isValidTable()) {
				int speciesID = speciesData.getIntAt(1);
				String skeleton = speciesData.getStringAt(2);
				bool canSit = speciesData.getBooleanAt(3);
				bool canLieDown = speciesData.getBooleanAt(4);

				Reference<AiSpeciesData*> data = new AiSpeciesData(speciesID, skeleton, canSit, canLieDown);

				aiSpeciesData.add(speciesID, data);
			}

			speciesData.pop();
		}
	}

	luaObject.pop();
}

CreatureTemplateManager::~CreatureTemplateManager() {

}

int CreatureTemplateManager::loadTemplates() {
	if (!DEBUG_MODE)
		info("loading mobile templates...", true);

	bool ret = false;

	try {
		ret = lua->runFile("scripts/mobile/creatures.lua");
	} catch (Exception& e) {
		error(e.getMessage());
		e.printStackTrace();
		ret = false;
	}

	lua = nullptr;

	if (!ret)
		ERROR_CODE = GENERAL_ERROR;

	if (!DEBUG_MODE) {
		printf("\n");
		info("done loading mobile templates", true);
	}

	return ERROR_CODE;
}

int CreatureTemplateManager::checkArgumentCount(lua_State* L, int args) {
	int parameterCount = lua_gettop(L);

	if (parameterCount < args) {
		return 1;
	} else if (parameterCount > args)
		return 2;

	return 0;
}

int CreatureTemplateManager::includeFile(lua_State* L) {
	if (checkArgumentCount(L, 1) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::includeFile");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String filename = Lua::getStringParameter(L);

	int oldError = ERROR_CODE;

	bool ret = Lua::runFile("scripts/mobile/" + filename, L);

	if (!ret) {
		ERROR_CODE = GENERAL_ERROR;

		instance()->error("running file scripts/mobile/" + filename);
	} else {
		if (!oldError && ERROR_CODE) {
			instance()->error("running file scripts/mobile/" + filename);
		}
	}

	return 0;
}

std::unordered_map<std::string, float> createCaveMultipliers() {
	std::unordered_map<std::string, float> caveMultipliers;
	caveMultipliers["caveCorelliaAfarathuCave"] = globalVariables::caveCorelliaAfarathuCaveMultiplier;
	caveMultipliers["caveCorelliaDrallCave"] = globalVariables::caveCorelliaDrallCaveMultiplier;
	caveMultipliers["caveCorelliaLordNyaxCult"] = globalVariables::caveCorelliaLordNyaxCultMultiplier;
	caveMultipliers["caveDantooineForceCrystalHunterCave"] = globalVariables::caveDantooineForceCrystalHunterCaveMultiplier;
	caveMultipliers["caveDantooineJantaCave"] = globalVariables::caveDantooineJantaCaveMultiplier;
	caveMultipliers["caveDantooineKungaStronghold"] = globalVariables::caveDantooineKungaStrongholdMultiplier;
	caveMultipliers["caveDantooineLizardCave"] = globalVariables::caveDantooineLizardCaveMultiplier;
	caveMultipliers["caveDathomirRancorCave"] = globalVariables::caveDathomirRancorCaveMultiplier;
	caveMultipliers["caveDathomirSpiderClanCave"] = globalVariables::caveDathomirSpiderClanCaveMultiplier;
	caveMultipliers["caveEndorJindaRitualistCave"] = globalVariables::caveEndorJindaRitualistCaveMultiplier;
	caveMultipliers["caveEndorKorgaCave"] = globalVariables::caveEndorKorgaCaveMultiplier;
	caveMultipliers["caveEndorOrphanedMarauderCave"] = globalVariables::caveEndorOrphanedMarauderCaveMultiplier;
	caveMultipliers["caveLokDroidEngineerCave"] = globalVariables::caveLokDroidEngineerCaveMultiplier;
	caveMultipliers["caveLokGasMine"] = globalVariables::caveLokGasMineMultiplier;
	caveMultipliers["caveLokImperialResearchFacility"] = globalVariables::caveLokImperialResearchFacilityMultiplier;
	caveMultipliers["caveLokNymPirateCave"] = globalVariables::caveLokNymPirateCaveMultiplier;
	caveMultipliers["caveNabooNarglatchCave"] = globalVariables::caveNabooNarglatchCaveMultiplier;
	caveMultipliers["caveNabooPirateBunker"] = globalVariables::caveNabooPirateBunkerMultiplier;
	caveMultipliers["caveNabooVeermokCave"] = globalVariables::caveNabooVeermokCaveMultiplier;
	caveMultipliers["caveRoriBlackSunOutpostBunker"] = globalVariables::caveRoriBlackSunOutpostBunkerMultiplier;
	caveMultipliers["caveRoriBorgleBatCave"] = globalVariables::caveRoriBorgleBatCaveMultiplier;
	caveMultipliers["caveRoriGiantBarkMiteCave"] = globalVariables::caveRoriGiantBarkMiteCaveMultiplier;
	caveMultipliers["caveRoriKobolaBunker"] = globalVariables::caveRoriKobolaBunkerMultiplier;
	caveMultipliers["caveRoriPygmyTortonCave"] = globalVariables::caveRoriPygmyTortonCaveMultiplier;
	caveMultipliers["caveTalusAakuanCave"] = globalVariables::caveTalusAakuanCaveMultiplier;
	caveMultipliers["caveTalusBinayrePirateBunker"] = globalVariables::caveTalusBinayrePirateBunkerMultiplier;
	caveMultipliers["caveTalusChunkerBunker"] = globalVariables::caveTalusChunkerBunkerMultiplier;
	caveMultipliers["caveTalusDetainmentCenter"] = globalVariables::caveTalusDetainmentCenterMultiplier;
	caveMultipliers["caveTalusErranSif"] = globalVariables::caveTalusErranSifMultiplier;
	caveMultipliers["caveTalusGiantDecayMiteCave"] = globalVariables::caveTalusGiantDecayMiteCaveMultiplier;
	caveMultipliers["caveTalusGiantFynockCave"] = globalVariables::caveTalusGiantFynockCaveMultiplier;
	caveMultipliers["caveTalusKaymurraBiogenticResearchStation"] = globalVariables::caveTalusKaymurraBiogenticResearchStationMultiplier;
	caveMultipliers["caveTalusLostAqualishCave"] = globalVariables::caveTalusLostAqualishCaveMultiplier;
	caveMultipliers["caveTalusWeaponsDepot"] = globalVariables::caveTalusWeaponsDepotMultiplier;
	caveMultipliers["caveTatooineHuttHideout"] = globalVariables::caveTatooineHuttHideoutMultiplier;
	caveMultipliers["caveTatooineSennexCave"] = globalVariables::caveTatooineSennexCaveMultiplier;
	caveMultipliers["caveTatooineSquillCave"] = globalVariables::caveTatooineSquillCaveMultiplier;
	caveMultipliers["caveTatooineTuskenBunker"] = globalVariables::caveTatooineTuskenBunkerMultiplier;
	caveMultipliers["poiCorelliaRebelHideout"] = globalVariables::poiCorelliaRebelHideoutMultiplier;
	caveMultipliers["poiCorelliaRogueCorsecBase"] = globalVariables::poiCorelliaRogueCorsecBaseMultiplier;
	caveMultipliers["poiCorelliaStronghold"] = globalVariables::poiCorelliaStrongholdMultiplier;
	caveMultipliers["poiDantooineAbandonedRebelBase"] = globalVariables::poiDantooineAbandonedRebelBaseMultiplier;
	caveMultipliers["poiDantooineDantariVillage"] = globalVariables::poiDantooineDantariVillageMultiplier;
	caveMultipliers["poiDantooineMokkStronghold"] = globalVariables::poiDantooineMokkStrongholdMultiplier;
	caveMultipliers["poiDathomirCrashSite"] = globalVariables::poiDathomirCrashSiteMultiplier;
	caveMultipliers["poiDathomirImperialPrison"] = globalVariables::poiDathomirImperialPrisonMultiplier;
	caveMultipliers["poiDathomirNightsisterLaborCamp"] = globalVariables::poiDathomirNightsisterLaborCampMultiplier;
	caveMultipliers["poiDathomirNightsisterStronghold"] = globalVariables::poiDathomirNightsisterStrongholdMultiplier;
	caveMultipliers["poiDathomirNightsisterVsSingingMountain"] = globalVariables::poiDathomirNightsisterVsSingingMountainMultiplier;
	caveMultipliers["poiDathomirSarlacc"] = globalVariables::poiDathomirSarlaccMultiplier;
	caveMultipliers["poiDathomirSingingMountainClan"] = globalVariables::poiDathomirSingingMountainClanMultiplier;
	caveMultipliers["poiEndorDulokVillageNorth"] = globalVariables::poiEndorDulokVillageNorthMultiplier;
	caveMultipliers["poiEndorDulokVillageSouth"] = globalVariables::poiEndorDulokVillageSouthMultiplier;
	caveMultipliers["poiEndorEwokLakeVillage1"] = globalVariables::poiEndorEwokLakeVillage1Multiplier;
	caveMultipliers["poiEndorEwokLakeVillage2"] = globalVariables::poiEndorEwokLakeVillage2Multiplier;
	caveMultipliers["poiEndorEwokTreeVillage1"] = globalVariables::poiEndorEwokTreeVillage1Multiplier;
	caveMultipliers["poiEndorEwokTreeVillage2"] = globalVariables::poiEndorEwokTreeVillage2Multiplier;
	caveMultipliers["poiEndorMarauderStronghold"] = globalVariables::poiEndorMarauderStrongholdMultiplier;
	caveMultipliers["poiLokCanyonCorsairsStronghold"] = globalVariables::poiLokCanyonCorsairsStrongholdMultiplier;
	caveMultipliers["poiLokDownedBloodRazorTransport"] = globalVariables::poiLokDownedBloodRazorTransportMultiplier;
	caveMultipliers["poiLokImperialOutpost"] = globalVariables::poiLokImperialOutpostMultiplier;
	caveMultipliers["poiLokKimogilaTown"] = globalVariables::poiLokKimogilaTownMultiplier;
	caveMultipliers["poiNabooAbandonedImperialOutpost"] = globalVariables::poiNabooAbandonedImperialOutpostMultiplier;
	caveMultipliers["poiNabooGunganSacredPlace"] = globalVariables::poiNabooGunganSacredPlaceMultiplier;
	caveMultipliers["poiNabooGunganTemple"] = globalVariables::poiNabooGunganTempleMultiplier;
	caveMultipliers["poiNabooImperialVsGungan"] = globalVariables::poiNabooImperialVsGunganMultiplier;
	caveMultipliers["poiNabooMaulerStronghold"] = globalVariables::poiNabooMaulerStrongholdMultiplier;
	caveMultipliers["poiNabooMordran"] = globalVariables::poiNabooMordranMultiplier;
	caveMultipliers["poiNabooWeaponTestingFacility"] = globalVariables::poiNabooWeaponTestingFacilityMultiplier;
	caveMultipliers["poiRoriCobralHideout"] = globalVariables::poiRoriCobralHideoutMultiplier;
	caveMultipliers["poiRoriGarynRaidersBunker"] = globalVariables::poiRoriGarynRaidersBunkerMultiplier;
	caveMultipliers["poiRoriGungansSwampTown"] = globalVariables::poiRoriGungansSwampTownMultiplier;
	caveMultipliers["poiRoriHyperdriveResearchFacility"] = globalVariables::poiRoriHyperdriveResearchFacilityMultiplier;
	caveMultipliers["poiRoriImperialEncampment"] = globalVariables::poiRoriImperialEncampmentMultiplier;
	caveMultipliers["poiRoriPoacherVsCreatureBattle"] = globalVariables::poiRoriPoacherVsCreatureBattleMultiplier;
	caveMultipliers["poiRoriRebelMilitaryBase"] = globalVariables::poiRoriRebelMilitaryBaseMultiplier;
	caveMultipliers["poiTalusCorsecVsFlailBattle"] = globalVariables::poiTalusCorsecVsFlailBattleMultiplier;
	caveMultipliers["poiTalusImperialVsRebelBattle"] = globalVariables::poiTalusImperialVsRebelBattleMultiplier;
	caveMultipliers["poiTalusLostVillageOfDurbin"] = globalVariables::poiTalusLostVillageOfDurbinMultiplier;
	caveMultipliers["poiTatooineAncientKraytDragonSkeleton"] = globalVariables::poiTatooineAncientKraytDragonSkeletonMultiplier;
	caveMultipliers["poiTatooineFortTusken"] = globalVariables::poiTatooineFortTuskenMultiplier;
	caveMultipliers["poiTatooineImperialDetachmentHq"] = globalVariables::poiTatooineImperialDetachmentHqMultiplier;
	caveMultipliers["poiTatooineImperialOasisBase"] = globalVariables::poiTatooineImperialOasisBaseMultiplier;
	caveMultipliers["poiTatooineJawaTraders"] = globalVariables::poiTatooineJawaTradersMultiplier;
	caveMultipliers["poiTatooineKraytGraveyard"] = globalVariables::poiTatooineKraytGraveyardMultiplier;
	caveMultipliers["poiTatooineSandcrawlerNe"] = globalVariables::poiTatooineSandcrawlerNeMultiplier;
	caveMultipliers["poiTatooineVillageRuins"] = globalVariables::poiTatooineVillageRuinsMultiplier;
	caveMultipliers["poiYavin4BlueleafTemple"] = globalVariables::poiYavin4BlueleafTempleMultiplier;
	caveMultipliers["poiYavin4ImperialBase"] = globalVariables::poiYavin4ImperialBaseMultiplier;
	caveMultipliers["poiYavin4WoolamanderTemple"] = globalVariables::poiYavin4WoolamanderTempleMultiplier;
	// Add more caves and their corresponding multipliers as needed
	return caveMultipliers;
}

int CreatureTemplateManager::addTemplate(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addTemplate");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}
	String ascii =  lua_tostring(L, -2);
	float cdpMultiplier = 1.0f;
	int difficulty = 1;
	LuaObject obj(L);
	auto caveMultipliers = createCaveMultipliers();
	for (int i = 1; i <= 3; ++i) {
		CreatureTemplate* newTemp = new CreatureTemplate();
		std::string templateName = ascii;
		bool caveFound = false;
		for (const auto& entry : caveMultipliers) {
			if (templateName.find(entry.first) != std::string::npos) {
				difficulty = i + 3;
				cdpMultiplier = entry.second;
				if (i > 1) templateName += "_" + std::to_string(i);
				caveFound = true;
				break;
			}
		}
		if (!caveFound) {
			if (i > 1) templateName += "_" + std::to_string(i);
			difficulty = i;
		}
		String templateN = templateName;		
		uint32 crc = (uint32) templateN.hashCode();
		newTemp->setTemplateName(templateName);
		newTemp->readObject(&obj, difficulty, cdpMultiplier);
		if (instance()->hashTable.containsKey(crc)) {
			luaL_where (L, 2);
			String luaMethodName = lua_tostring(L, -1);
			lua_pop(L, 1);
			instance()->error("overwriting mobile " + ascii + " with " + luaMethodName);
			ERROR_CODE = DUPLICATE_MOBILE;
		}
		CreatureTemplateManager::instance()->hashTable.put(crc, newTemp);
		int count = loadedMobileTemplates.increment();
		printf("\r\tLoading mobile templates: [%d] / [?]\t", count);
	}
	return 0;
}

int CreatureTemplateManager::addConversationTemplate(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addConversationTemplate");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii =  lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

	LuaObject obj(L);
	Reference<ConversationTemplate*> newTemp = new ConversationTemplate(crc);

	if (instance()->conversations.containsKey(crc)) {
		luaL_where (L, 2);
		String luaMethodName = lua_tostring(L, -1);

		lua_pop(L, 1);

		instance()->error("overwriting convoTemplate " + ascii + " with " + luaMethodName);

		ERROR_CODE = DUPLICATE_CONVO;
	}

	CreatureTemplateManager::instance()->conversations.put(crc, newTemp);

	newTemp->readObject(&obj);

	return 0;
}

int CreatureTemplateManager::addWeapon(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addWeapon");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

	LuaObject obj(L);
	if (obj.isValidTable()) {
		TemplateManager* templateManager = TemplateManager::instance();

		Vector<String> weps;
		for (int i = 1; i <= obj.getTableSize(); ++i) {
			String tempName = obj.getStringAt(i);
			SharedObjectTemplate* templateData = templateManager->getTemplate(tempName.hashCode());
			if (templateData == nullptr && tempName != "unarmed") {
				instance()->error() << "Weapon group " << ascii << " has invalid weapon configured: " << tempName;
				continue;
			}

			weps.add(tempName);
		}

		CreatureTemplateManager::instance()->weaponMap.put(crc, weps);
	}

	return 0;
}

int CreatureTemplateManager::addSpawnGroup(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addLairGroup");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

#ifdef DEBUG_REGIONS
	Logger::console.info(true) << "Adding spawn group: " << ascii;
#endif // DEBUG_REGIONS

	LuaObject obj(L);
	CreatureTemplateManager::instance()->spawnGroupMap.put(crc, new SpawnGroup(ascii, obj));

	return 0;
}

int CreatureTemplateManager::addLairTemplate(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addLairTemplate");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

	LuaObject obj(L);

	Reference<LairTemplate*> templ = new LairTemplate(ascii);
	templ->readObject(&obj);

	CreatureTemplateManager::instance()->lairTemplates.put(crc, templ);

	return 0;
}

int CreatureTemplateManager::addDestroyMissionGroup(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addDestroyMissionGroup");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

	LuaObject obj(L);
	CreatureTemplateManager::instance()->destroyMissionGroupMap.put(crc, new SpawnGroup(ascii, obj));

	return 0;
}

int CreatureTemplateManager::addPatrolPathTemplate(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addPatrolPathTemplate");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);

	LuaObject obj(L);

	Reference<PatrolPathTemplate*> templ = new PatrolPathTemplate();
	templ->readObject(&obj);

	instance()->patrolPaths.put(ascii, templ);

	return 0;
}

int CreatureTemplateManager::addOutfitGroup(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addOutfitGroup");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);

	LuaObject obj(L);

	Reference<MobileOutfitGroup*> templ = new MobileOutfitGroup();
	templ->readObject(&obj);

	instance()->outfits.put(ascii, templ);

	return 0;
}

int CreatureTemplateManager::addDressGroup(lua_State* L) {
	if (checkArgumentCount(L, 2) == 1) {
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addDressGroup");
		ERROR_CODE = INCORRECT_ARGUMENTS;
		return 0;
	}

	String ascii = lua_tostring(L, -2);
	uint32 crc = (uint32) ascii.hashCode();

	LuaObject obj(L);

	if (obj.isValidTable()) {
		Vector<String> dressGroup;

		for (int i = 1; i <= obj.getTableSize(); ++i) {
			String templ = obj.getStringAt(i);

			SharedObjectTemplate* dressTemplate = TemplateManager::instance()->getTemplate(templ.hashCode());

			if (dressTemplate == nullptr) {
				instance()->error("Unable to add " + templ + " to dress group " + ascii + ", invalid template.");
				continue;
			}

			dressGroup.add(templ);
		}

		CreatureTemplateManager::instance()->dressMap.put(crc, dressGroup);
	}

	return 0;
}


