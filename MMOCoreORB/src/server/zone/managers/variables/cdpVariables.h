#ifndef CDPVARIABLES_H_
#define CDPVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CDPVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CDPVariables();
	~CDPVariables();
	void startCDPVariables();
	//Cave
	float cdpCaveCorelliaAfarathuCaveMultiplier{1};
	float cdpCaveCorelliaDrallCaveMultiplier{1};
	float cdpCaveCorelliaLordNyaxCultMultiplier{1};
	float cdpCaveDantooineForceCrystalHunterCaveMultiplier{1};
	float cdpCaveDantooineJantaCaveMultiplier{1};
	float cdpCaveDantooineKungaStrongholdMultiplier{1};
	float cdpCaveDantooineLizardCaveMultiplier{1};
	float cdpCaveDathomirRancorCaveMultiplier{1};
	float cdpCaveDathomirSpiderClanCaveMultiplier{1};
	float cdpCaveEndorJindaRitualistCaveMultiplier{1};
	float cdpCaveEndorKorgaCaveMultiplier{1};
	float cdpCaveEndorOrphanedMarauderCaveMultiplier{1};
	float cdpCaveLokDroidEngineerCaveMultiplier{1};
	float cdpCaveLokGasMineMultiplier{1};
	float cdpCaveLokImperialResearchFacilityMultiplier{1};
	float cdpCaveLokNymPirateCaveMultiplier{1};
	float cdpCaveNabooNarglatchCaveMultiplier{1};
	float cdpCaveNabooPirateBunkerMultiplier{1};
	float cdpCaveNabooVeermokCaveMultiplier{1};
	float cdpCaveRoriBlackSunOutpostBunkerMultiplier{1};
	float cdpCaveRoriBorgleBatCaveMultiplier{1};
	float cdpCaveRoriGiantBarkMiteCaveMultiplier{1};
	float cdpCaveRoriKobolaBunkerMultiplier{1};
	float cdpCaveRoriPygmyTortonCaveMultiplier{1};
	float cdpCaveTalusAakuanCaveMultiplier{1};
	float cdpCaveTalusBinayrePirateBunkerMultiplier{1};
	float cdpCaveTalusChunkerBunkerMultiplier{1};
	float cdpCaveTalusDetainmentCenterMultiplier{1};
	float cdpCaveTalusErranSifMultiplier{1};
	float cdpCaveTalusGiantDecayMiteCaveMultiplier{1};
	float cdpCaveTalusGiantFynockCaveMultiplier{1};
	float cdpCaveTalusKaymurraBiogenticResearchStationMultiplier{1};
	float cdpCaveTalusLostAqualishCaveMultiplier{1};
	float cdpCaveTalusWeaponsDepotMultiplier{1};
	float cdpCaveTatooineHuttHideoutMultiplier{1};
	float cdpCaveTatooineSennexCaveMultiplier{1};
	float cdpCaveTatooineSquillCaveMultiplier{1};
	float cdpCaveTatooineTuskenBunkerMultiplier{1};
	//Dungeons
	float cdpDungeonCorellianCorvetteMultiplier{1};
	float cdpDungeonDeathWatchBunkerMultiplier{1};
	float cdpDungeonGeonosianBioLabMultiplier{1};
	float cdpDungeonWarrenMultiplier{1};
	//POI
	float cdpPoiCorelliaRebelHideoutMultiplier{1};
	float cdpPoiCorelliaRogueCorsecBaseMultiplier{1};
	float cdpPoiCorelliaStrongholdMultiplier{1};
	float cdpPoiDantooineAbandonedRebelBaseMultiplier{1};
	float cdpPoiDantooineDantariVillageMultiplier{1};
	float cdpPoiDantooineMokkStrongholdMultiplier{1};
	float cdpPoiDathomirCrashSiteMultiplier{1};
	float cdpPoiDathomirImperialPrisonMultiplier{1};
	float cdpPoiDathomirNightsisterLaborCampMultiplier{1};
	float cdpPoiDathomirNightsisterStrongholdMultiplier{1};
	float cdpPoiDathomirNightsisterVsSingingMountainMultiplier{1};
	float cdpPoiDathomirSarlaccMultiplier{1};
	float cdpPoiDathomirSingingMountainClanMultiplier{1};
	float cdpPoiEndorDulokVillageNorthMultiplier{1};
	float cdpPoiEndorDulokVillageSouthMultiplier{1};
	float cdpPoiEndorEwokLakeVillage1Multiplier{1};
	float cdpPoiEndorEwokLakeVillage2Multiplier{1};
	float cdpPoiEndorEwokTreeVillage1Multiplier{1};
	float cdpPoiEndorEwokTreeVillage2Multiplier{1};
	float cdpPoiEndorMarauderStrongholdMultiplier{1};
	float cdpPoiLokCanyonCorsairsStrongholdMultiplier{1};
	float cdpPoiLokDownedBloodRazorTransportMultiplier{1};
	float cdpPoiLokImperialOutpostMultiplier{1};
	float cdpPoiLokKimogilaTownMultiplier{1};
	float cdpPoiNabooAbandonedImperialOutpostMultiplier{1};
	float cdpPoiNabooGunganSacredPlaceMultiplier{1};
	float cdpPoiNabooGunganTempleMultiplier{1};
	float cdpPoiNabooImperialVsGunganMultiplier{1};
	float cdpPoiNabooMaulerStrongholdMultiplier{1};
	float cdpPoiNabooMordranMultiplier{1};
	float cdpPoiNabooWeaponTestingFacilityMultiplier{1};
	float cdpPoiRoriCobralHideoutMultiplier{1};
	float cdpPoiRoriGarynRaidersBunkerMultiplier{1};
	float cdpPoiRoriGungansSwampTownMultiplier{1};
	float cdpPoiRoriHyperdriveResearchFacilityMultiplier{1};
	float cdpPoiRoriImperialEncampmentMultiplier{1};
	float cdpPoiRoriPoacherVsCreatureBattleMultiplier{1};
	float cdpPoiRoriRebelMilitaryBaseMultiplier{1};
	float cdpPoiTalusCorsecVsFlailBattleMultiplier{1};
	float cdpPoiTalusImperialVsRebelBattleMultiplier{1};
	float cdpPoiTalusLostVillageOfDurbinMultiplier{1};
	float cdpPoiTatooineAncientKraytDragonSkeletonMultiplier{1};
	float cdpPoiTatooineFortTuskenMultiplier{1};
	float cdpPoiTatooineImperialDetachmentHqMultiplier{1};
	float cdpPoiTatooineImperialOasisBaseMultiplier{1};
	float cdpPoiTatooineJawaTradersMultiplier{1};
	float cdpPoiTatooineKraytGraveyardMultiplier{1};
	float cdpPoiTatooineSandcrawlerNeMultiplier{1};
	float cdpPoiTatooineVillageRuinsMultiplier{1};
	float cdpPoiYavin4BlueleafTempleMultiplier{1};
	float cdpPoiYavin4ImperialBaseMultiplier{1};
	float cdpPoiYavin4WoolamanderTempleMultiplier{1};
};

extern CDPVariables cdpVars;

#endif /*CDPVARIABLES_H_*/
