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
#include "server/zone/managers/variables/cdpVariables.h"

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
	caveMultipliers["caveCorelliaAfarathuCave"] = cdpVars.cdpCaveCorelliaAfarathuCaveMultiplier;
	caveMultipliers["caveCorelliaDrallCave"] = cdpVars.cdpCaveCorelliaDrallCaveMultiplier;
	caveMultipliers["caveCorelliaLordNyaxCult"] = cdpVars.cdpCaveCorelliaLordNyaxCultMultiplier;
	caveMultipliers["caveDantooineForceCrystalHunterCave"] = cdpVars.cdpCaveDantooineForceCrystalHunterCaveMultiplier;
	caveMultipliers["caveDantooineJantaCave"] = cdpVars.cdpCaveDantooineJantaCaveMultiplier;
	caveMultipliers["caveDantooineKungaStronghold"] = cdpVars.cdpCaveDantooineKungaStrongholdMultiplier;
	caveMultipliers["caveDantooineLizardCave"] = cdpVars.cdpCaveDantooineLizardCaveMultiplier;
	caveMultipliers["caveDathomirRancorCave"] = cdpVars.cdpCaveDathomirRancorCaveMultiplier;
	caveMultipliers["caveDathomirSpiderClanCave"] = cdpVars.cdpCaveDathomirSpiderClanCaveMultiplier;
	caveMultipliers["caveEndorJindaRitualistCave"] = cdpVars.cdpCaveEndorJindaRitualistCaveMultiplier;
	caveMultipliers["caveEndorKorgaCave"] = cdpVars.cdpCaveEndorKorgaCaveMultiplier;
	caveMultipliers["caveEndorOrphanedMarauderCave"] = cdpVars.cdpCaveEndorOrphanedMarauderCaveMultiplier;
	caveMultipliers["caveLokDroidEngineerCave"] = cdpVars.cdpCaveLokDroidEngineerCaveMultiplier;
	caveMultipliers["caveLokGasMine"] = cdpVars.cdpCaveLokGasMineMultiplier;
	caveMultipliers["caveLokImperialResearchFacility"] = cdpVars.cdpCaveLokImperialResearchFacilityMultiplier;
	caveMultipliers["caveLokNymPirateCave"] = cdpVars.cdpCaveLokNymPirateCaveMultiplier;
	caveMultipliers["caveNabooNarglatchCave"] = cdpVars.cdpCaveNabooNarglatchCaveMultiplier;
	caveMultipliers["caveNabooPirateBunker"] = cdpVars.cdpCaveNabooPirateBunkerMultiplier;
	caveMultipliers["caveNabooVeermokCave"] = cdpVars.cdpCaveNabooVeermokCaveMultiplier;
	caveMultipliers["caveRoriBlackSunOutpostBunker"] = cdpVars.cdpCaveRoriBlackSunOutpostBunkerMultiplier;
	caveMultipliers["caveRoriBorgleBatCave"] = cdpVars.cdpCaveRoriBorgleBatCaveMultiplier;
	caveMultipliers["caveRoriGiantBarkMiteCave"] = cdpVars.cdpCaveRoriGiantBarkMiteCaveMultiplier;
	caveMultipliers["caveRoriKobolaBunker"] = cdpVars.cdpCaveRoriKobolaBunkerMultiplier;
	caveMultipliers["caveRoriPygmyTortonCave"] = cdpVars.cdpCaveRoriPygmyTortonCaveMultiplier;
	caveMultipliers["caveTalusAakuanCave"] = cdpVars.cdpCaveTalusAakuanCaveMultiplier;
	caveMultipliers["caveTalusBinayrePirateBunker"] = cdpVars.cdpCaveTalusBinayrePirateBunkerMultiplier;
	caveMultipliers["caveTalusChunkerBunker"] = cdpVars.cdpCaveTalusChunkerBunkerMultiplier;
	caveMultipliers["caveTalusDetainmentCenter"] = cdpVars.cdpCaveTalusDetainmentCenterMultiplier;
	caveMultipliers["caveTalusErranSif"] = cdpVars.cdpCaveTalusErranSifMultiplier;
	caveMultipliers["caveTalusGiantDecayMiteCave"] = cdpVars.cdpCaveTalusGiantDecayMiteCaveMultiplier;
	caveMultipliers["caveTalusGiantFynockCave"] = cdpVars.cdpCaveTalusGiantFynockCaveMultiplier;
	caveMultipliers["caveTalusKaymurraBiogenticResearchStation"] = cdpVars.cdpCaveTalusKaymurraBiogenticResearchStationMultiplier;
	caveMultipliers["caveTalusLostAqualishCave"] = cdpVars.cdpCaveTalusLostAqualishCaveMultiplier;
	caveMultipliers["caveTalusWeaponsDepot"] = cdpVars.cdpCaveTalusWeaponsDepotMultiplier;
	caveMultipliers["caveTatooineHuttHideout"] = cdpVars.cdpCaveTatooineHuttHideoutMultiplier;
	caveMultipliers["caveTatooineSennexCave"] = cdpVars.cdpCaveTatooineSennexCaveMultiplier;
	caveMultipliers["caveTatooineSquillCave"] = cdpVars.cdpCaveTatooineSquillCaveMultiplier;
	caveMultipliers["caveTatooineTuskenBunker"] = cdpVars.cdpCaveTatooineTuskenBunkerMultiplier;
	caveMultipliers["poiCorelliaRebelHideout"] = cdpVars.cdpPoiCorelliaRebelHideoutMultiplier;
	caveMultipliers["poiCorelliaRogueCorsecBase"] = cdpVars.cdpPoiCorelliaRogueCorsecBaseMultiplier;
	caveMultipliers["poiCorelliaStronghold"] = cdpVars.cdpPoiCorelliaStrongholdMultiplier;
	caveMultipliers["poiDantooineAbandonedRebelBase"] = cdpVars.cdpPoiDantooineAbandonedRebelBaseMultiplier;
	caveMultipliers["poiDantooineDantariVillage"] = cdpVars.cdpPoiDantooineDantariVillageMultiplier;
	caveMultipliers["poiDantooineMokkStronghold"] = cdpVars.cdpPoiDantooineMokkStrongholdMultiplier;
	caveMultipliers["poiDathomirCrashSite"] = cdpVars.cdpPoiDathomirCrashSiteMultiplier;
	caveMultipliers["poiDathomirImperialPrison"] = cdpVars.cdpPoiDathomirImperialPrisonMultiplier;
	caveMultipliers["poiDathomirNightsisterLaborCamp"] = cdpVars.cdpPoiDathomirNightsisterLaborCampMultiplier;
	caveMultipliers["poiDathomirNightsisterStronghold"] = cdpVars.cdpPoiDathomirNightsisterStrongholdMultiplier;
	caveMultipliers["poiDathomirNightsisterVsSingingMountain"] = cdpVars.cdpPoiDathomirNightsisterVsSingingMountainMultiplier;
	caveMultipliers["poiDathomirSarlacc"] = cdpVars.cdpPoiDathomirSarlaccMultiplier;
	caveMultipliers["poiDathomirSingingMountainClan"] = cdpVars.cdpPoiDathomirSingingMountainClanMultiplier;
	caveMultipliers["poiEndorDulokVillageNorth"] = cdpVars.cdpPoiEndorDulokVillageNorthMultiplier;
	caveMultipliers["poiEndorDulokVillageSouth"] = cdpVars.cdpPoiEndorDulokVillageSouthMultiplier;
	caveMultipliers["poiEndorEwokLakeVillage1"] = cdpVars.cdpPoiEndorEwokLakeVillage1Multiplier;
	caveMultipliers["poiEndorEwokLakeVillage2"] = cdpVars.cdpPoiEndorEwokLakeVillage2Multiplier;
	caveMultipliers["poiEndorEwokTreeVillage1"] = cdpVars.cdpPoiEndorEwokTreeVillage1Multiplier;
	caveMultipliers["poiEndorEwokTreeVillage2"] = cdpVars.cdpPoiEndorEwokTreeVillage2Multiplier;
	caveMultipliers["poiEndorMarauderStronghold"] = cdpVars.cdpPoiEndorMarauderStrongholdMultiplier;
	caveMultipliers["poiLokCanyonCorsairsStronghold"] = cdpVars.cdpPoiLokCanyonCorsairsStrongholdMultiplier;
	caveMultipliers["poiLokDownedBloodRazorTransport"] = cdpVars.cdpPoiLokDownedBloodRazorTransportMultiplier;
	caveMultipliers["poiLokImperialOutpost"] = cdpVars.cdpPoiLokImperialOutpostMultiplier;
	caveMultipliers["poiLokKimogilaTown"] = cdpVars.cdpPoiLokKimogilaTownMultiplier;
	caveMultipliers["poiNabooAbandonedImperialOutpost"] = cdpVars.cdpPoiNabooAbandonedImperialOutpostMultiplier;
	caveMultipliers["poiNabooGunganSacredPlace"] = cdpVars.cdpPoiNabooGunganSacredPlaceMultiplier;
	caveMultipliers["poiNabooGunganTemple"] = cdpVars.cdpPoiNabooGunganTempleMultiplier;
	caveMultipliers["poiNabooImperialVsGungan"] = cdpVars.cdpPoiNabooImperialVsGunganMultiplier;
	caveMultipliers["poiNabooMaulerStronghold"] = cdpVars.cdpPoiNabooMaulerStrongholdMultiplier;
	caveMultipliers["poiNabooMordran"] = cdpVars.cdpPoiNabooMordranMultiplier;
	caveMultipliers["poiNabooWeaponTestingFacility"] = cdpVars.cdpPoiNabooWeaponTestingFacilityMultiplier;
	caveMultipliers["poiRoriCobralHideout"] = cdpVars.cdpPoiRoriCobralHideoutMultiplier;
	caveMultipliers["poiRoriGarynRaidersBunker"] = cdpVars.cdpPoiRoriGarynRaidersBunkerMultiplier;
	caveMultipliers["poiRoriGungansSwampTown"] = cdpVars.cdpPoiRoriGungansSwampTownMultiplier;
	caveMultipliers["poiRoriHyperdriveResearchFacility"] = cdpVars.cdpPoiRoriHyperdriveResearchFacilityMultiplier;
	caveMultipliers["poiRoriImperialEncampment"] = cdpVars.cdpPoiRoriImperialEncampmentMultiplier;
	caveMultipliers["poiRoriPoacherVsCreatureBattle"] = cdpVars.cdpPoiRoriPoacherVsCreatureBattleMultiplier;
	caveMultipliers["poiRoriRebelMilitaryBase"] = cdpVars.cdpPoiRoriRebelMilitaryBaseMultiplier;
	caveMultipliers["poiTalusCorsecVsFlailBattle"] = cdpVars.cdpPoiTalusCorsecVsFlailBattleMultiplier;
	caveMultipliers["poiTalusImperialVsRebelBattle"] = cdpVars.cdpPoiTalusImperialVsRebelBattleMultiplier;
	caveMultipliers["poiTalusLostVillageOfDurbin"] = cdpVars.cdpPoiTalusLostVillageOfDurbinMultiplier;
	caveMultipliers["poiTatooineAncientKraytDragonSkeleton"] = cdpVars.cdpPoiTatooineAncientKraytDragonSkeletonMultiplier;
	caveMultipliers["poiTatooineFortTusken"] = cdpVars.cdpPoiTatooineFortTuskenMultiplier;
	caveMultipliers["poiTatooineImperialDetachmentHq"] = cdpVars.cdpPoiTatooineImperialDetachmentHqMultiplier;
	caveMultipliers["poiTatooineImperialOasisBase"] = cdpVars.cdpPoiTatooineImperialOasisBaseMultiplier;
	caveMultipliers["poiTatooineJawaTraders"] = cdpVars.cdpPoiTatooineJawaTradersMultiplier;
	caveMultipliers["poiTatooineKraytGraveyard"] = cdpVars.cdpPoiTatooineKraytGraveyardMultiplier;
	caveMultipliers["poiTatooineSandcrawlerNe"] = cdpVars.cdpPoiTatooineSandcrawlerNeMultiplier;
	caveMultipliers["poiTatooineVillageRuins"] = cdpVars.cdpPoiTatooineVillageRuinsMultiplier;
	caveMultipliers["poiYavin4BlueleafTemple"] = cdpVars.cdpPoiYavin4BlueleafTempleMultiplier;
	caveMultipliers["poiYavin4ImperialBase"] = cdpVars.cdpPoiYavin4ImperialBaseMultiplier;
	caveMultipliers["poiYavin4WoolamanderTemple"] = cdpVars.cdpPoiYavin4WoolamanderTempleMultiplier;
	caveMultipliers["dungeonCorellianCorvette"] = cdpVars.cdpDungeonCorellianCorvetteMultiplier;
	caveMultipliers["dungeonDeathWatchBunker"] = cdpVars.cdpDungeonDeathWatchBunkerMultiplier;
	caveMultipliers["dungeonGeonosianBioLab"] = cdpVars.cdpDungeonGeonosianBioLabMultiplier;
	caveMultipliers["dungeonWarren"] = cdpVars.cdpDungeonWarrenMultiplier;
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
		//Logger::console.info("CreatureTemplate: " + templateName,true);
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
		instance()->error("incorrect number of arguments passed to CreatureTemplateManager::addSpawnGroup");
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


