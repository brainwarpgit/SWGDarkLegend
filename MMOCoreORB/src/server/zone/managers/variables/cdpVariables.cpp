#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/cdpVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

CDPVariables cdpVars;

CDPVariables::CDPVariables() : Logger("CDPVariables") {}

CDPVariables::~CDPVariables() {}

void CDPVariables::startCDPVariables() {

	if (!loadConfigData()) {
		info(true) << "loadConfigData() FAILED";
		return;
	}
	std::thread reloadThread([this] { 
		startWatching(
			[this] {
				loadConfigData();
				}
			);
	});
	reloadThread.detach();

}

bool CDPVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/cdp_variables.lua";

	bool initialLoad = false;
	
	if (!fileExists(luaFilePath)) {
		return 0;
	}

	time_t modifiedTime = getFileModifiedTime(luaFilePath);

	if (modifiedTime == lastModifiedTime) {
		return true;
	}

	if (lastModifiedTime == 0) {
		info(true) << "Initial Load of " << luaFilePath;
		initialLoad = true;
	} else {
		info(true) << "Reloading due to change in " << luaFilePath;
	}

	lastModifiedTime = modifiedTime;
	
	Lua* lua = new Lua();
	lua->init();

	if (!lua->runFile(luaFilePath.c_str())) {
		info(true) << "Failed to load file " << luaFilePath;
		delete lua;
		lua = nullptr;
		return false;
	}

	try {
		//Caves
		if (lua->getGlobalFloat("cdpCaveCorelliaAfarathuCaveMultiplier") > 0) cdpVars.cdpCaveCorelliaAfarathuCaveMultiplier = lua->getGlobalFloat("cdpCaveCorelliaAfarathuCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveCorelliaDrallCaveMultiplier") > 0) cdpVars.cdpCaveCorelliaDrallCaveMultiplier = lua->getGlobalFloat("cdpCaveCorelliaDrallCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveCorelliaLordNyaxCultMultiplier") > 0) cdpVars.cdpCaveCorelliaLordNyaxCultMultiplier = lua->getGlobalFloat("cdpCaveCorelliaLordNyaxCultMultiplier");
		if (lua->getGlobalFloat("cdpCaveDantooineForceCrystalHunterCaveMultiplier") > 0) cdpVars.cdpCaveDantooineForceCrystalHunterCaveMultiplier = lua->getGlobalFloat("cdpCaveDantooineForceCrystalHunterCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveDantooineJantaCaveMultiplier") > 0) cdpVars.cdpCaveDantooineJantaCaveMultiplier = lua->getGlobalFloat("cdpCaveDantooineJantaCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveDantooineKungaStrongholdMultiplier") > 0) cdpVars.cdpCaveDantooineKungaStrongholdMultiplier = lua->getGlobalFloat("cdpCaveDantooineKungaStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpCaveDantooineLizardCaveMultiplier") > 0) cdpVars.cdpCaveDantooineLizardCaveMultiplier = lua->getGlobalFloat("cdpCaveDantooineLizardCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveDathomirRancorCaveMultiplier") > 0) cdpVars.cdpCaveDathomirRancorCaveMultiplier = lua->getGlobalFloat("cdpCaveDathomirRancorCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveDathomirSpiderClanCaveMultiplier") > 0) cdpVars.cdpCaveDathomirSpiderClanCaveMultiplier = lua->getGlobalFloat("cdpCaveDathomirSpiderClanCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveEndorJindaRitualistCaveMultiplier") > 0) cdpVars.cdpCaveEndorJindaRitualistCaveMultiplier = lua->getGlobalFloat("cdpCaveEndorJindaRitualistCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveEndorKorgaCaveMultiplier") > 0) cdpVars.cdpCaveEndorKorgaCaveMultiplier = lua->getGlobalFloat("cdpCaveEndorKorgaCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveEndorOrphanedMarauderCaveMultiplier") > 0) cdpVars.cdpCaveEndorOrphanedMarauderCaveMultiplier = lua->getGlobalFloat("cdpCaveEndorOrphanedMarauderCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveLokDroidEngineerCaveMultiplier") > 0) cdpVars.cdpCaveLokDroidEngineerCaveMultiplier = lua->getGlobalFloat("cdpCaveLokDroidEngineerCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveLokGasMineMultiplier") > 0) cdpVars.cdpCaveLokGasMineMultiplier = lua->getGlobalFloat("cdpCaveLokGasMineMultiplier");
		if (lua->getGlobalFloat("cdpCaveLokImperialResearchFacilityMultiplier") > 0) cdpVars.cdpCaveLokImperialResearchFacilityMultiplier = lua->getGlobalFloat("cdpCaveLokImperialResearchFacilityMultiplier");
		if (lua->getGlobalFloat("cdpCaveLokNymPirateCaveMultiplier") > 0) cdpVars.cdpCaveLokNymPirateCaveMultiplier = lua->getGlobalFloat("cdpCaveLokNymPirateCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveNabooNarglatchCaveMultiplier") > 0) cdpVars.cdpCaveNabooNarglatchCaveMultiplier = lua->getGlobalFloat("cdpCaveNabooNarglatchCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveNabooPirateBunkerMultiplier") > 0) cdpVars.cdpCaveNabooPirateBunkerMultiplier = lua->getGlobalFloat("cdpCaveNabooPirateBunkerMultiplier");
		if (lua->getGlobalFloat("cdpCaveNabooVeermokCaveMultiplier") > 0) cdpVars.cdpCaveNabooVeermokCaveMultiplier = lua->getGlobalFloat("cdpCaveNabooVeermokCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveRoriBlackSunOutpostBunkerMultiplier") > 0) cdpVars.cdpCaveRoriBlackSunOutpostBunkerMultiplier = lua->getGlobalFloat("cdpCaveRoriBlackSunOutpostBunkerMultiplier");
		if (lua->getGlobalFloat("cdpCaveRoriBorgleBatCaveMultiplier") > 0) cdpVars.cdpCaveRoriBorgleBatCaveMultiplier = lua->getGlobalFloat("cdpCaveRoriBorgleBatCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveRoriGiantBarkMiteCaveMultiplier") > 0) cdpVars.cdpCaveRoriGiantBarkMiteCaveMultiplier = lua->getGlobalFloat("cdpCaveRoriGiantBarkMiteCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveRoriKobolaBunkerMultiplier") > 0) cdpVars.cdpCaveRoriKobolaBunkerMultiplier = lua->getGlobalFloat("cdpCaveRoriKobolaBunkerMultiplier");
		if (lua->getGlobalFloat("cdpCaveRoriPygmyTortonCaveMultiplier") > 0) cdpVars.cdpCaveRoriPygmyTortonCaveMultiplier = lua->getGlobalFloat("cdpCaveRoriPygmyTortonCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusAakuanCaveMultiplier") > 0) cdpVars.cdpCaveTalusAakuanCaveMultiplier = lua->getGlobalFloat("cdpCaveTalusAakuanCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusBinayrePirateBunkerMultiplier") > 0) cdpVars.cdpCaveTalusBinayrePirateBunkerMultiplier = lua->getGlobalFloat("cdpCaveTalusBinayrePirateBunkerMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusChunkerBunkerMultiplier") > 0) cdpVars.cdpCaveTalusChunkerBunkerMultiplier = lua->getGlobalFloat("cdpCaveTalusChunkerBunkerMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusDetainmentCenterMultiplier") > 0) cdpVars.cdpCaveTalusDetainmentCenterMultiplier = lua->getGlobalFloat("cdpCaveTalusDetainmentCenterMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusErranSifMultiplier") > 0) cdpVars.cdpCaveTalusErranSifMultiplier = lua->getGlobalFloat("cdpCaveTalusErranSifMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusGiantDecayMiteCaveMultiplier") > 0) cdpVars.cdpCaveTalusGiantDecayMiteCaveMultiplier = lua->getGlobalFloat("cdpCaveTalusGiantDecayMiteCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusGiantFynockCaveMultiplier") > 0) cdpVars.cdpCaveTalusGiantFynockCaveMultiplier = lua->getGlobalFloat("cdpCaveTalusGiantFynockCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusKaymurraBiogenticResearchStationMultiplier") > 0) cdpVars.cdpCaveTalusKaymurraBiogenticResearchStationMultiplier = lua->getGlobalFloat("cdpCaveTalusKaymurraBiogenticResearchStationMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusLostAqualishCaveMultiplier") > 0) cdpVars.cdpCaveTalusLostAqualishCaveMultiplier = lua->getGlobalFloat("cdpCaveTalusLostAqualishCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTalusWeaponsDepotMultiplier") > 0) cdpVars.cdpCaveTalusWeaponsDepotMultiplier = lua->getGlobalFloat("cdpCaveTalusWeaponsDepotMultiplier");
		if (lua->getGlobalFloat("cdpCaveTatooineHuttHideoutMultiplier") > 0) cdpVars.cdpCaveTatooineHuttHideoutMultiplier = lua->getGlobalFloat("cdpCaveTatooineHuttHideoutMultiplier");
		if (lua->getGlobalFloat("cdpCaveTatooineSennexCaveMultiplier") > 0) cdpVars.cdpCaveTatooineSennexCaveMultiplier = lua->getGlobalFloat("cdpCaveTatooineSennexCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTatooineSquillCaveMultiplier") > 0) cdpVars.cdpCaveTatooineSquillCaveMultiplier = lua->getGlobalFloat("cdpCaveTatooineSquillCaveMultiplier");
		if (lua->getGlobalFloat("cdpCaveTatooineTuskenBunkerMultiplier") > 0) cdpVars.cdpCaveTatooineTuskenBunkerMultiplier = lua->getGlobalFloat("cdpCaveTatooineTuskenBunkerMultiplier");
		
		//Dungeon
		if (lua->getGlobalFloat("cdpDungeonCorellianCorvetteMultiplier") > 0) cdpVars.cdpDungeonCorellianCorvetteMultiplier = lua->getGlobalFloat("cdpDungeonCorellianCorvetteMultiplier");
		if (lua->getGlobalFloat("cdpDungeonDeathWatchBunkerMultiplier") > 0) cdpVars.cdpDungeonDeathWatchBunkerMultiplier = lua->getGlobalFloat("cdpDungeonDeathWatchBunkerMultiplier");
		if (lua->getGlobalFloat("cdpDungeonGeonosianBioLabMultiplier") > 0) cdpVars.cdpDungeonGeonosianBioLabMultiplier = lua->getGlobalFloat("cdpDungeonGeonosianBioLabMultiplier");
		if (lua->getGlobalFloat("cdpDungeonWarrenMultiplier") > 0) cdpVars.cdpDungeonWarrenMultiplier = lua->getGlobalFloat("cdpDungeonWarrenMultiplier");

		//POI
		if (lua->getGlobalFloat("cdpPoiCorelliaRebelHideoutMultiplier") > 0) cdpVars.cdpPoiCorelliaRebelHideoutMultiplier = lua->getGlobalFloat("cdpPoiCorelliaRebelHideoutMultiplier");
		if (lua->getGlobalFloat("cdpPoiCorelliaRogueCorsecBaseMultiplier") > 0) cdpVars.cdpPoiCorelliaRogueCorsecBaseMultiplier = lua->getGlobalFloat("cdpPoiCorelliaRogueCorsecBaseMultiplier");
		if (lua->getGlobalFloat("cdpPoiCorelliaStrongholdMultiplier") > 0) cdpVars.cdpPoiCorelliaStrongholdMultiplier = lua->getGlobalFloat("cdpPoiCorelliaStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiDantooineAbandonedRebelBaseMultiplier") > 0) cdpVars.cdpPoiDantooineAbandonedRebelBaseMultiplier = lua->getGlobalFloat("cdpPoiDantooineAbandonedRebelBaseMultiplier");
		if (lua->getGlobalFloat("cdpPoiDantooineDantariVillageMultiplier") > 0) cdpVars.cdpPoiDantooineDantariVillageMultiplier = lua->getGlobalFloat("cdpPoiDantooineDantariVillageMultiplier");
		if (lua->getGlobalFloat("cdpPoiDantooineMokkStrongholdMultiplier") > 0) cdpVars.cdpPoiDantooineMokkStrongholdMultiplier = lua->getGlobalFloat("cdpPoiDantooineMokkStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirCrashSiteMultiplier") > 0) cdpVars.cdpPoiDathomirCrashSiteMultiplier = lua->getGlobalFloat("cdpPoiDathomirCrashSiteMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirImperialPrisonMultiplier") > 0) cdpVars.cdpPoiDathomirImperialPrisonMultiplier = lua->getGlobalFloat("cdpPoiDathomirImperialPrisonMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirNightsisterLaborCampMultiplier") > 0) cdpVars.cdpPoiDathomirNightsisterLaborCampMultiplier = lua->getGlobalFloat("cdpPoiDathomirNightsisterLaborCampMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirNightsisterStrongholdMultiplier") > 0) cdpVars.cdpPoiDathomirNightsisterStrongholdMultiplier = lua->getGlobalFloat("cdpPoiDathomirNightsisterStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirNightsisterVsSingingMountainMultiplier") > 0) cdpVars.cdpPoiDathomirNightsisterVsSingingMountainMultiplier = lua->getGlobalFloat("cdpPoiDathomirNightsisterVsSingingMountainMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirSarlaccMultiplier") > 0) cdpVars.cdpPoiDathomirSarlaccMultiplier = lua->getGlobalFloat("cdpPoiDathomirSarlaccMultiplier");
		if (lua->getGlobalFloat("cdpPoiDathomirSingingMountainClanMultiplier") > 0) cdpVars.cdpPoiDathomirSingingMountainClanMultiplier = lua->getGlobalFloat("cdpPoiDathomirSingingMountainClanMultiplier");
		if (lua->getGlobalFloat("cdpPoiEndorDulokVillageNorthMultiplier") > 0) cdpVars.cdpPoiEndorDulokVillageNorthMultiplier = lua->getGlobalFloat("cdpPoiEndorDulokVillageNorthMultiplier");
		if (lua->getGlobalFloat("cdpPoiEndorDulokVillageSouthMultiplier") > 0) cdpVars.cdpPoiEndorDulokVillageSouthMultiplier = lua->getGlobalFloat("cdpPoiEndorDulokVillageSouthMultiplier");
		if (lua->getGlobalFloat("cdpPoiEndorEwokLakeVillage1Multiplier") > 0) cdpVars.cdpPoiEndorEwokLakeVillage1Multiplier = lua->getGlobalFloat("cdpPoiEndorEwokLakeVillage1Multiplier");
		if (lua->getGlobalFloat("cdpPoiEndorEwokLakeVillage2Multiplier") > 0) cdpVars.cdpPoiEndorEwokLakeVillage2Multiplier = lua->getGlobalFloat("cdpPoiEndorEwokLakeVillage2Multiplier");
		if (lua->getGlobalFloat("cdpPoiEndorEwokTreeVillage1Multiplier") > 0) cdpVars.cdpPoiEndorEwokTreeVillage1Multiplier = lua->getGlobalFloat("cdpPoiEndorEwokTreeVillage1Multiplier");
		if (lua->getGlobalFloat("cdpPoiEndorEwokTreeVillage2Multiplier") > 0) cdpVars.cdpPoiEndorEwokTreeVillage2Multiplier = lua->getGlobalFloat("cdpPoiEndorEwokTreeVillage2Multiplier");
		if (lua->getGlobalFloat("cdpPoiEndorMarauderStrongholdMultiplier") > 0) cdpVars.cdpPoiEndorMarauderStrongholdMultiplier = lua->getGlobalFloat("cdpPoiEndorMarauderStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiLokCanyonCorsairsStrongholdMultiplier") > 0) cdpVars.cdpPoiLokCanyonCorsairsStrongholdMultiplier = lua->getGlobalFloat("cdpPoiLokCanyonCorsairsStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiLokDownedBloodRazorTransportMultiplier") > 0) cdpVars.cdpPoiLokDownedBloodRazorTransportMultiplier = lua->getGlobalFloat("cdpPoiLokDownedBloodRazorTransportMultiplier");
		if (lua->getGlobalFloat("cdpPoiLokImperialOutpostMultiplier") > 0) cdpVars.cdpPoiLokImperialOutpostMultiplier = lua->getGlobalFloat("cdpPoiLokImperialOutpostMultiplier");
		if (lua->getGlobalFloat("cdpPoiLokKimogilaTownMultiplier") > 0) cdpVars.cdpPoiLokKimogilaTownMultiplier = lua->getGlobalFloat("cdpPoiLokKimogilaTownMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooAbandonedImperialOutpostMultiplier") > 0) cdpVars.cdpPoiNabooAbandonedImperialOutpostMultiplier = lua->getGlobalFloat("cdpPoiNabooAbandonedImperialOutpostMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooGunganSacredPlaceMultiplier") > 0) cdpVars.cdpPoiNabooGunganSacredPlaceMultiplier = lua->getGlobalFloat("cdpPoiNabooGunganSacredPlaceMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooGunganTempleMultiplier") > 0) cdpVars.cdpPoiNabooGunganTempleMultiplier = lua->getGlobalFloat("cdpPoiNabooGunganTempleMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooImperialVsGunganMultiplier") > 0) cdpVars.cdpPoiNabooImperialVsGunganMultiplier = lua->getGlobalFloat("cdpPoiNabooImperialVsGunganMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooMaulerStrongholdMultiplier") > 0) cdpVars.cdpPoiNabooMaulerStrongholdMultiplier = lua->getGlobalFloat("cdpPoiNabooMaulerStrongholdMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooMordranMultiplier") > 0) cdpVars.cdpPoiNabooMordranMultiplier = lua->getGlobalFloat("cdpPoiNabooMordranMultiplier");
		if (lua->getGlobalFloat("cdpPoiNabooWeaponTestingFacilityMultiplier") > 0) cdpVars.cdpPoiNabooWeaponTestingFacilityMultiplier = lua->getGlobalFloat("cdpPoiNabooWeaponTestingFacilityMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriCobralHideoutMultiplier") > 0) cdpVars.cdpPoiRoriCobralHideoutMultiplier = lua->getGlobalFloat("cdpPoiRoriCobralHideoutMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriGarynRaidersBunkerMultiplier") > 0) cdpVars.cdpPoiRoriGarynRaidersBunkerMultiplier = lua->getGlobalFloat("cdpPoiRoriGarynRaidersBunkerMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriGungansSwampTownMultiplier") > 0) cdpVars.cdpPoiRoriGungansSwampTownMultiplier = lua->getGlobalFloat("cdpPoiRoriGungansSwampTownMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriHyperdriveResearchFacilityMultiplier") > 0) cdpVars.cdpPoiRoriHyperdriveResearchFacilityMultiplier = lua->getGlobalFloat("cdpPoiRoriHyperdriveResearchFacilityMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriImperialEncampmentMultiplier") > 0) cdpVars.cdpPoiRoriImperialEncampmentMultiplier = lua->getGlobalFloat("cdpPoiRoriImperialEncampmentMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriPoacherVsCreatureBattleMultiplier") > 0) cdpVars.cdpPoiRoriPoacherVsCreatureBattleMultiplier = lua->getGlobalFloat("cdpPoiRoriPoacherVsCreatureBattleMultiplier");
		if (lua->getGlobalFloat("cdpPoiRoriRebelMilitaryBaseMultiplier") > 0) cdpVars.cdpPoiRoriRebelMilitaryBaseMultiplier = lua->getGlobalFloat("cdpPoiRoriRebelMilitaryBaseMultiplier");
		if (lua->getGlobalFloat("cdpPoiTalusCorsecVsFlailBattleMultiplier") > 0) cdpVars.cdpPoiTalusCorsecVsFlailBattleMultiplier = lua->getGlobalFloat("cdpPoiTalusCorsecVsFlailBattleMultiplier");
		if (lua->getGlobalFloat("cdpPoiTalusImperialVsRebelBattleMultiplier") > 0) cdpVars.cdpPoiTalusImperialVsRebelBattleMultiplier = lua->getGlobalFloat("cdpPoiTalusImperialVsRebelBattleMultiplier");
		if (lua->getGlobalFloat("cdpPoiTalusLostVillageOfDurbinMultiplier") > 0) cdpVars.cdpPoiTalusLostVillageOfDurbinMultiplier = lua->getGlobalFloat("cdpPoiTalusLostVillageOfDurbinMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineAncientKraytDragonSkeletonMultiplier") > 0) cdpVars.cdpPoiTatooineAncientKraytDragonSkeletonMultiplier = lua->getGlobalFloat("cdpPoiTatooineAncientKraytDragonSkeletonMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineFortTuskenMultiplier") > 0) cdpVars.cdpPoiTatooineFortTuskenMultiplier = lua->getGlobalFloat("cdpPoiTatooineFortTuskenMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineImperialDetachmentHqMultiplier") > 0) cdpVars.cdpPoiTatooineImperialDetachmentHqMultiplier = lua->getGlobalFloat("cdpPoiTatooineImperialDetachmentHqMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineImperialOasisBaseMultiplier") > 0) cdpVars.cdpPoiTatooineImperialOasisBaseMultiplier = lua->getGlobalFloat("cdpPoiTatooineImperialOasisBaseMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineJawaTradersMultiplier") > 0) cdpVars.cdpPoiTatooineJawaTradersMultiplier = lua->getGlobalFloat("cdpPoiTatooineJawaTradersMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineKraytGraveyardMultiplier") > 0) cdpVars.cdpPoiTatooineKraytGraveyardMultiplier = lua->getGlobalFloat("cdpPoiTatooineKraytGraveyardMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineSandcrawlerNeMultiplier") > 0) cdpVars.cdpPoiTatooineSandcrawlerNeMultiplier = lua->getGlobalFloat("cdpPoiTatooineSandcrawlerNeMultiplier");
		if (lua->getGlobalFloat("cdpPoiTatooineVillageRuinsMultiplier") > 0) cdpVars.cdpPoiTatooineVillageRuinsMultiplier = lua->getGlobalFloat("cdpPoiTatooineVillageRuinsMultiplier");
		if (lua->getGlobalFloat("cdpPoiYavin4BlueleafTempleMultiplier") > 0) cdpVars.cdpPoiYavin4BlueleafTempleMultiplier = lua->getGlobalFloat("cdpPoiYavin4BlueleafTempleMultiplier");
		if (lua->getGlobalFloat("cdpPoiYavin4ImperialBaseMultiplier") > 0) cdpVars.cdpPoiYavin4ImperialBaseMultiplier = lua->getGlobalFloat("cdpPoiYavin4ImperialBaseMultiplier");
		if (lua->getGlobalFloat("cdpPoiYavin4WoolamanderTempleMultiplier") > 0) cdpVars.cdpPoiYavin4WoolamanderTempleMultiplier = lua->getGlobalFloat("cdpPoiYavin4WoolamanderTempleMultiplier");
	} catch (const Exception& e) {
		info(true) << "Error retrieving LUA varaibles: " << e.what();
		return false;
	}

	if (initialLoad) {
		info(true) << "Initial Load Completed.";
	} else{
		info(true) << "Reload Completed.";
	}
	
	delete lua;
	lua = nullptr;

	return true;
}

bool CDPVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t CDPVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void CDPVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

