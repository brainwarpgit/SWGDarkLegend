#include "globalVariables.h"
#include "engine/lua/Lua.h"

//#include <string>

namespace globalVariables {

//Variables

//Auction
	int auctionMaxBazaarPrice = 20000;
	int auctionMaxSales = 25;
	int auctionMaxSalesFee = 20;
	int auctionVendorExpirePeriod = 30;
	int auctionCommodityExpirePeriod = 7;

//Caves and POIs
	float caveCorelliaAfarathuCaveMultiplier = 1;
	float caveCorelliaDrallCaveMultiplier = 1;
	float caveCorelliaLordNyaxCultMultiplier = 1;
	float caveDantooineForceCrystalHunterCaveMultiplier = 1;
	float caveDantooineJantaCaveMultiplier = 1;
	float caveDantooineKungaStrongholdMultiplier = 1;
	float caveDantooineLizardCaveMultiplier = 1;
	float caveDathomirRancorCaveMultiplier = 1;
	float caveDathomirSpiderClanCaveMultiplier = 1;
	float caveEndorJindaRitualistCaveMultiplier = 1;
	float caveEndorKorgaCaveMultiplier = 1;
	float caveEndorOrphanedMarauderCaveMultiplier = 1;
	float caveLokDroidEngineerCaveMultiplier = 1;
	float caveLokGasMineMultiplier = 1;
	float caveLokImperialResearchFacilityMultiplier = 1;
	float caveLokNymPirateCaveMultiplier = 1;
	float caveNabooNarglatchCaveMultiplier = 1;
	float caveNabooPirateBunkerMultiplier = 1;
	float caveNabooVeermokCaveMultiplier = 1;
	float caveRoriBlackSunOutpostBunkerMultiplier = 1;
	float caveRoriBorgleBatCaveMultiplier = 1;
	float caveRoriGiantBarkMiteCaveMultiplier = 1;
	float caveRoriKobolaBunkerMultiplier = 1;
	float caveRoriPygmyTortonCaveMultiplier = 1;
	float caveTalusAakuanCaveMultiplier = 1;
	float caveTalusBinayrePirateBunkerMultiplier = 1;
	float caveTalusChunkerBunkerMultiplier = 1;
	float caveTalusDetainmentCenterMultiplier = 1;
	float caveTalusErranSifMultiplier = 1;
	float caveTalusGiantDecayMiteCaveMultiplier = 1;
	float caveTalusGiantFynockCaveMultiplier = 1;
	float caveTalusKaymurraBiogenticResearchStationMultiplier = 1;
	float caveTalusLostAqualishCaveMultiplier = 1;
	float caveTalusWeaponsDepotMultiplier = 1;
	float caveTatooineHuttHideoutMultiplier = 1;
	float caveTatooineSennexCaveMultiplier = 1;
	float caveTatooineSquillCaveMultiplier = 1;
	float caveTatooineTuskenBunkerMultiplier = 1;
	float poiCorelliaRebelHideoutMultiplier = 1;
	float poiCorelliaRogueCorsecBaseMultiplier = 1;
	float poiCorelliaStrongholdMultiplier = 1;
	float poiDantooineAbandonedRebelBaseMultiplier = 1;
	float poiDantooineDantariVillageMultiplier = 1;
	float poiDantooineMokkStrongholdMultiplier = 1;
	float poiDathomirCrashSiteMultiplier = 1;
	float poiDathomirImperialPrisonMultiplier = 1;
	float poiDathomirNightsisterLaborCampMultiplier = 1;
	float poiDathomirNightsisterStrongholdMultiplier = 1;
	float poiDathomirNightsisterVsSingingMountainMultiplier = 1;
	float poiDathomirSarlaccMultiplier = 1;
	float poiDathomirSingingMountainClanMultiplier = 1;
	float poiEndorDulokVillageNorthMultiplier = 1;
	float poiEndorDulokVillageSouthMultiplier = 1;
	float poiEndorEwokLakeVillage1Multiplier = 1;
	float poiEndorEwokLakeVillage2Multiplier = 1;
	float poiEndorEwokTreeVillage1Multiplier = 1;
	float poiEndorEwokTreeVillage2Multiplier = 1;
	float poiEndorMarauderStrongholdMultiplier = 1;
	float poiLokCanyonCorsairsStrongholdMultiplier = 1;
	float poiLokDownedBloodRazorTransportMultiplier = 1;
	float poiLokImperialOutpostMultiplier = 1;
	float poiLokKimogilaTownMultiplier = 1;
	float poiNabooAbandonedImperialOutpostMultiplier = 1;
	float poiNabooGunganSacredPlaceMultiplier = 1;
	float poiNabooGunganTempleMultiplier = 1;
	float poiNabooImperialVsGunganMultiplier = 1;
	float poiNabooMaulerStrongholdMultiplier = 1;
	float poiNabooMordranMultiplier = 1;
	float poiNabooWeaponTestingFacilityMultiplier = 1;
	float poiRoriCobralHideoutMultiplier = 1;
	float poiRoriGarynRaidersBunkerMultiplier = 1;
	float poiRoriGungansSwampTownMultiplier = 1;
	float poiRoriHyperdriveResearchFacilityMultiplier = 1;
	float poiRoriImperialEncampmentMultiplier = 1;
	float poiRoriPoacherVsCreatureBattleMultiplier = 1;
	float poiRoriRebelMilitaryBaseMultiplier = 1;
	float poiTalusCorsecVsFlailBattleMultiplier = 1;
	float poiTalusImperialVsRebelBattleMultiplier = 1;
	float poiTalusLostVillageOfDurbinMultiplier = 1;
	float poiTatooineAncientKraytDragonSkeletonMultiplier = 1;
	float poiTatooineFortTuskenMultiplier = 1;
	float poiTatooineImperialDetachmentHqMultiplier = 1;
	float poiTatooineImperialOasisBaseMultiplier = 1;
	float poiTatooineJawaTradersMultiplier = 1;
	float poiTatooineKraytGraveyardMultiplier = 1;
	float poiTatooineSandcrawlerNeMultiplier = 1;
	float poiTatooineVillageRuinsMultiplier = 1;
	float poiYavin4BlueleafTempleMultiplier = 1;
	float poiYavin4ImperialBaseMultiplier = 1;
	float poiYavin4WoolamanderTempleMultiplier = 1;

//Combat
	float combatDamageMeleeWeaponMultiplier = 1;
	float combatDamageUnarmedWeaponMultiplier = 1;
	float combatDamageOneHandWeaponMultiplier = 1;
	float combatDamageTwoHandWeaponMultiplier = 1;
	float combatDamagePolearmWeaponMultiplier = 1;
	float combatDamageRangedWeaponMultiplier = 1;
	float combatDamagePistolWeaponMultiplier = 1;
	float combatDamageCarbineWeaponMultiplier = 1;
	float combatDamageRifleWeaponMultiplier = 1;
	float combatDamageThrownWeaponMultiplier = 1;
	float combatDamageHeavyWeaponMultiplier = 1;
	float combatDamageSpecialHeavyWeaponMultiplier = 1;
	float combatDamageMineWeaponMultiplier = 1;
	float combatDamageJediWeaponMultiplier = 1;
	float combatDamageJediOneHandWeaponMultiplier = 1;
	float combatDamageJediTwoHandWeaponMultiplier = 1;
	float combatDamageJediPolearmWeaponMultiplier = 1;
	float combatDamageJediForcePowerMultiplier = 1;
	float combatDamageAllMultiplier = 1;
	
//Command
	bool commandCheckForceStatusCommandEnabled = true;
	bool commandMeditateMergeEnabled = false;
	
//Crafting
	int craftingFactoryCrateMaxSize = 100;
	int craftingFactoryRunTimeMultiplier = 8;
	int craftingToolCraftTimeMultiplier = 2;
	int craftingMaxSockets = 4;
	int craftingMinSocketMod = 60;
	int craftingMaxSocketMod = 175;
	bool craftingNewGenerateSocketsEnabled = false;
	bool craftingWearableContainerSocketsEnabled = false;
	bool craftingNewAssemblyEnabled = false;
	bool craftingNewExperimentEnabled= false;
	bool craftingNewRepairEnabled = false;
	bool craftingRepairBrokenEnabled = false;
	float craftingRepairMaxMod = 0.8f;
	bool craftingCraftedItemsBetterThanLootEnabled = false;
	float craftingCraftedItemsBetterThanLootModifier = 1.f;
	float craftingKineticMaxResists = 100.0f;
	float craftingEnergyMaxResists = 100.0f;
	float craftingBlastMaxResists = 100.0f;
	float craftingHeatMaxResists = 100.0f;
	float craftingColdMaxResists = 100.0f;
	float craftingElectricityMaxResists = 100.0f;
	float craftingAcidMaxResists = 100.0f;
	float craftingStunMaxResists = 100.0f;
	float craftingLightsaberMaxResists = 100.0f;
	
//Creature
	bool creatureRandomDifficultyEnabled = false;
	int creatureMaxLevel = 336;
	float creatureKineticMaxResists = 100.0f;
	float creatureEnergyMaxResists = 100.0f;
	float creatureBlastMaxResists = 100.0f;
	float creatureHeatMaxResists = 100.0f;
	float creatureColdMaxResists = 100.0f;
	float creatureElectricityMaxResists = 100.0f;
	float creatureAcidMaxResists = 100.0f;
	float creatureStunMaxResists = 100.0f;
	float creatureLightsaberMaxResists = 100.0f;
	float creatureBaseScaleMultiplier = 1;
	float creatureBaseXPMultiplier = 1;
	float creatureBaseMeatAmountMultiplier = 1;
	float creatureBaseHideAmountMultiplier = 1;
	float creatureBaseBoneAmountMultiplier = 1;
	float creatureBaseMilkMultiplier = 1;
	float creatureBaseLevelMultiplier = 1;
	float creatureBaseChanceHitMultiplier = 1;
	float creatureBaseFerocityMultiplier = 1;
	float creatureBaseDamageMaxMultiplier = 1;
	float creatureBaseDamageMinMultiplier = 1;
	float creatureBaseHAMMultiplier = 1;
	float creatureBaseHAMMaxMultiplier = 1;
	float creatureBaseResistsMultiplier = 1;
	float creatureWildSpawnDensity = 32.0f;
	float creatureSpawnElitePercentage = 30;
	float creatureSpawnHeroicPercentage = 10;
	float creatureModBaseScaleModifier = 0;
	float creatureModBaseXPModifier = 0;
	float creatureModBaseMeatAmountModifier = 0;
	float creatureModBaseHideAmountModifier = 0;
	float creatureModBaseBoneAmountModifier = 0;
	float creatureModBaseMilkModifier = 0;
	float creatureModBaseLevelModifier = 0;
	float creatureModBaseChanceHitModifier = 0;
	float creatureModBaseFerocityModifier = 0;
	float creatureModBaseDamageMaxModifier = 0;
	float creatureModBaseDamageMinModifier = 0;
	float creatureModBaseHAMModifier = 0;
	float creatureModBaseHAMMaxModifier = 0;
	float creatureModBaseResistsModifier = 0;
	bool creatureAllCreatureCanSpawnBabyEnabled = false;
	float creatureAllCreatureCanSpawnBabyChance = 0.05;
	bool creatureBabyRandomDifficultyEnabled = false;
	int creatureBabySpawnChanceDestroyMissionLair = 1000;
	int creatureBabySpawnChanceDynamicSpawn = 500;
	int creatureBabySpawnChanceDynamicLair = 500;

//Creature Handler
	int creatureTamingMaxDistance = 8;
	float creatureTamingCycleTime = 10;
	bool creatureTrainingAlwaysSuccessfulEnabled = false;
	bool creatureUntrainCreatureMountEnabled = false;
	bool creatureSetDefaultPetCommandsEnabled = false;
	
//Dungeon
	float dungeonCorellianCorvetteMultiplier = 1;
	float dungeonDeathWatchBunkerMultiplier = 1;
	float dungeonGeonosianBioLabMultiplier = 1; 
	float dungeonWarrenMultiplier = 1;

//Faction
	int factionMaxRank = 15;
	float factionCapMultiplier = 1.0f;

//Harvest
	int harvestDistance = 10;
	bool harvestAreaEnabled = false;
	bool harvestAreaCommandOnlyEnabled = false;
	int harvestMultiplier = 1;
	int harvestMilkTime = 10;
	float harvestDNASampleDistance = 16;

//Jedi
	bool jediForceCostToTuneEnabled = true;
	int jediKnightRequirementNumberOfMasters = 2;

//Loot
	int lootDistance = 16;
	bool lootAreaEnabled = false;
	int lootCreditMultiplier = 1;
	int lootAttachmentMax = 25;
	int lootAttachmentMin = 1;
	int lootAttachmentMaxLevel = 250;
	bool lootAttachmentNameEnabled = false;
	int lootAttachmentModCount = 2;
	int lootDropAttachmentModCount = 2;
	bool lootCreditLuckModifier = false;
	int lootMaxLevel = 300;
	int lootMinLevel = 1;
	bool lootShowForceCostDecimalEnabled = false;
	bool lootRareColorCrystalsEnabled = false;
	bool lootGroupCreditsSplitEnabled = true;
	float lootChanceMultiplier = 1;
	float lootResourceMultiplier = 1;
	bool lootYellowModifierNameEnabled = false;
	std::string lootYellowModifierName = "Enhanced";
	float lootLegendaryDamageModifier = 9;
	float lootExceptionalDamageModifier = 8;
	float lootYellowDamageModifier = 2;
	float lootBaseDamageModifier = 1;
	bool lootUseLootModifiersForDamageModifiersEnabled = false;
	float lootArmorMaxResists = 50;
	bool lootNewLootQualityNamingEnabled = false;
	bool lootModifiersAffectLightsaberCrystalsEnabled = false;
	bool lootLevelToItemDescriptionEnabled = false;
	bool lootModifierToItemDescriptionEnabled = false;
	bool lootQualityToItemDescriptionEnabled = false;
	
//Mission
	int missionBountyExpirationTime = 48;
	int missionExpirationTime = 48;
	int missionMaxCount = 2;
	int missionListCount = 6;
	bool missionNameAndLevelEnabled = false;
	bool missionDirectionSelectionEnabled = false;
	bool missionLevelSelectionEnabled = false;
	int missionRewardMultiplier = 1;
	
//Pet
	int petCallTime = 15;
	int petGrowthCycleTime = 720;
	int petGrowthStagesToGrown = 10;
	bool petStoreInCombatEnabled = false;
	float petOutOfCombatHAMRegenMultiplier = 1;
	bool petAllMountsUsedByAnyone = false;
	bool petCallInCombatEnabled = false;
	float petDamageMultiplier = 1;

//Player
	int playerSamplingMultiplier = 1;
	int playerSamplingTime = 25;
	bool playerSamplingMiniGameEnabled = true;
	bool playerSamplingRadioactiveWarningEnabled = true;
	int playerMaxLots = 10;
	bool playerGlobalSafetyDepositEnabled = false;
	float playerShuttleBoardingDistance = 25.f;
	std::string playerStatMigrationLocation = "tutorial";
	bool playerStatMigrationSalonOnlyEnabled = false;
	bool playerStatMigrationAnyLocationEnabled = false;
	bool playerStatMigrationClearBuffsEnabled = false;
	int playerWoundsonDeath = 100;
	bool playerBackpackWipeEnabled = false;
	bool playerChangeWearableColorsEnabled = false;
	bool playerOverwriteBuffEnabled = false;
	bool playerWoundHealingAnywhereEnabled = false;
	bool playerEnhanceHealingAnywhereEnabled = false;
	int playerWoundHealingMultiplier = 1;
	int playerEnhanceHealingMultiplier = 1;
	int playerDamageHealingMultiplier = 1;
	bool playerInsureWeaponsEnabled = false;
	float playerMeditateHealingMultiplier = 1.0f;
	bool playerMeditateFatigueHealingEnabled = false;
	int playerMeditateFatigueHealingAmount = 10;
	float playerHAMRegenSittingMultiplier = 5.0f;
	float playerHAMRegenKneelingMultiplier = 5.0f;
	float playerMaxArmorUnSliced = 80;
	float playerMaxArmorSliced = 90;
	bool playerJediForceRunToggleEnabled = false;
	bool playerEntertainerHealsAllWoundsEnabled = false;
	float playerEntertainerWoundHealMultiplier = 1;
	bool playerEntertainerBuffDurationCustomEnabled = false;
	float playerEnterainerBuffDuration = 1;
	bool playerEntertainerAllBuffsMusicOrDanceEnabled = false;
	bool playerEntertainerBuffSelfEnabled = false;
	bool playerEntertainerInstantBuffEnabled = false;
	bool playerEntertainerBuffAnywhereEnabled = false;
	float playerSpeedMultiplier = 1;
	float playerMeditateTickTime = 5;
	float playerJediForceMeditateMultiplier = 3;
	int playerMaxLevelNonCHMount = 10;

//Player Creation
	int playerCreationNewCreationTime = 60;
	bool playerCreationAllLanguagesEnabled = false;
	bool playerCreationJoinGalaxyChatEnabled = false;
	bool playerCreationGrantAllNoviceSkillsEnabled = false;

//Player Payments
	bool playerPaymentCashAndBankEnabled = false;

//Player XP
	bool playerForagingXPEnabled = false;
	bool playerMilkingXPEnabled = false;
	bool playerAwardPetHealingXPEnabled = false;
	bool playerAwardSelfHealingXPEnabled = false;
	bool playerAwardXPWeaponSplitEnabled = false;
	float playerDNASamplingXPMultiplier = 1;
	float playerBountyHunterXPMultiplier = 1;
	float playerWildernessSurvivalXPMultiplier = 1;
	float playerCombatXPMultiplier = 0.1;
	float playerOnehandedWeaponsXPMultiplier = 1;
	float playerPolearmWeaponsXPMultiplier = 1;
	float playerTwohandedWeaponsXPMultiplier = 1;
	float playerUnarmedCombatXPMultiplier = 1;
	float playerCarbineWeaponsXPMultiplier = 1;
	float playerHeavyWeaponsXPMultiplier = 1;
	float playerPistolWeaponsXPMultiplier = 1;
	float playerRifleWeaponsXPMultiplier = 1;
	float playerBioEngineerCraftingXPMultiplier = 1;
	float playerArmorCraftingXPMultiplier = 1;
	float playerTailoringXPMultiplier = 1;
	float playerDroidCraftingXPMultiplier = 1;
	float playerFoodCraftingXPMultiplier = 1;
	float playerGeneralCraftingXPMultiplier = 1;
	float playerMedicineCraftingXPMultiplier = 1;
	float playerSpiceCraftingXPMultiplier = 1;
	float playerStructureCraftingXPMultiplier = 1;
	float playerWeaponCraftingXPMultiplier = 1;
	float playerCreatureHandlingXPMultiplier = 1;
	float playerDancingXPMultiplier = 1;
	float playerEntertainerHealingXPMultiplier = 1;
	float playerImageDesignerXPMultiplier = 1;
	float playerJediXPMultiplier = 0.2;
	float playerMedicalXPMultiplier = 1;
	float playerMerchantXPMultiplier = 1;
	float playerMusicianXPMultiplier = 1;
	float playerPoliticalXPMultiplier = 1;
	float playerSurveyingXPMultiplier = 1;
	float playerScoutingXPMultiplier = 1;
	float playerShipwrightXPMultiplier = 1;
	float playerSlicingXPMultiplier = 1;
	float playerStarshipCombatXPMultiplier = 1;
	float playerSquadLeadershipXPMultiplier = 1;
	float playerTrappingXPMultiplier = 1;
	int playerJediNegativeXPCap = -10000000;
	bool playerJediAwardedCombatXPEnabled = false;
	bool playerJediPvEForceRankXPEnabled = false;
	float playerJediForceRankXPMultiplier = 0.05;
	bool playerMeditateGrantsHealingXPEnabled = false;
	bool playerXPBasedOnLevelEnabled = true;
	bool playerCHXPModEnabled = false;
	bool playerCHCombatXPEnabled = false;

//Resources
	bool resourcesAddNameEnabled = false;
	int resourcesMinimumQuality = 0;
	int resourcesMaximumQuality = 1000;
	int resourcesContainerSize = 100000;

//Skills
	bool skillsInstantMasterPoliticianEnabled = false;
	bool skillsInstantMasterMerchantEnabled = false;

//Slicing
	bool slicingNewSliceEnabled = false;
	float slicingTerminalSliceCooldown = 2;
	bool slicingArmorSliceSocketsEnabled = false;
	bool slicingArmorPierceSliceEnabled = false;
	bool slicingWeaponPierceSliceEnabled = false;

//Structure
	int structureMaxItemsPerLot = 100;
	int structureMaxCivicBuildingItems = 250;
	int structureMaxZeroLotBuildingItems = 400;
	int structureMaxItemsPerStructure = 400;
	bool structureMaxItemsEnabled = true;
	bool structureShowHouseMaxItemsEnabled = false;
	int structureBaseMaintenanceRateMultiplier = 1;
	int structureBasePowerRateMultiplier = 1;
	bool structureAllowAllZonesEnabled = false;
	int cityMaintenanceBaseMultiplier = 1;
	int cityMaintenanceRateMultiplier = 1;
	bool structureInstallationQuickAddMaintenanceEnabled = false;
	int structureInstallationQuickAddMaintenanceAmount = 10000;
	bool structureInstallationQuickAddPowerEnabled = false;
	int structureInstallationQuickAddPowerAmount = 10000;
	bool structureInstallationResourcesRetrieveAllEnabled = false;

//Vehicle
	int vehicleBaseDecayCycle = 600;
	int vehicleBaseDecayRate = 15;
	bool vehicleInitialDecayEnabled = true;
	int vehicleCallTime = 15;
	bool vehicleStoreInCombatEnabled = false;

//Vendor
	bool vendorLowMaintenanceEmailEnabled = false;
	int vendorLowMaintenanceEmailWarningThreshold = 360;
	bool vendorSkimSalesForMaintenanceEnabled = false;
	float vendorSkimSalesForMaintenancePercent = 5;

//Wearables
	bool wearablesFactionEnabled = true;
	bool wearablesAllPlayerRacesEnabled = false;

//Initializer
	bool loadConfigData() {
		Lua* lua = new Lua();
		lua->init();			
		if (!lua->runFile("scripts/managers/global_variables.lua")) {
			delete lua;
			return false;
		}
		try {
			//Auction
			if (lua->getGlobalInt("auctionMaxBazaarPrice") > 0) auctionMaxBazaarPrice = lua->getGlobalInt("auctionMaxBazaarPrice");
			if (lua->getGlobalInt("auctionMaxSales") > 0) auctionMaxSales = lua->getGlobalInt("auctionMaxSales");
			if (lua->getGlobalInt("auctionMaxSalesFee") >= 0) auctionMaxSalesFee = lua->getGlobalInt("auctionMaxSalesFee");
			if (lua->getGlobalInt("auctionVendorExpirePeriod") > 0) auctionVendorExpirePeriod = lua->getGlobalInt("auctionVendorExpirePeriod");
			if (lua->getGlobalInt("auctionCommodityExpirePeriod") > 0) auctionCommodityExpirePeriod = lua->getGlobalInt("auctionCommodityExpirePeriod");
			
			//Caves and POIs
			if (lua->getGlobalFloat("caveCorelliaAfarathuCaveMultiplier") > 0) caveCorelliaAfarathuCaveMultiplier = lua->getGlobalFloat("caveCorelliaAfarathuCaveMultiplier");
			if (lua->getGlobalFloat("caveCorelliaDrallCaveMultiplier") > 0) caveCorelliaDrallCaveMultiplier = lua->getGlobalFloat("caveCorelliaDrallCaveMultiplier");
			if (lua->getGlobalFloat("caveCorelliaLordNyaxCultMultiplier") > 0) caveCorelliaLordNyaxCultMultiplier = lua->getGlobalFloat("caveCorelliaLordNyaxCultMultiplier");
			if (lua->getGlobalFloat("caveDantooineForceCrystalHunterCaveMultiplier") > 0) caveDantooineForceCrystalHunterCaveMultiplier = lua->getGlobalFloat("caveDantooineForceCrystalHunterCaveMultiplier");
			if (lua->getGlobalFloat("caveDantooineJantaCaveMultiplier") > 0) caveDantooineJantaCaveMultiplier = lua->getGlobalFloat("caveDantooineJantaCaveMultiplier");
			if (lua->getGlobalFloat("caveDantooineKungaStrongholdMultiplier") > 0) caveDantooineKungaStrongholdMultiplier = lua->getGlobalFloat("caveDantooineKungaStrongholdMultiplier");
			if (lua->getGlobalFloat("caveDantooineLizardCaveMultiplier") > 0) caveDantooineLizardCaveMultiplier = lua->getGlobalFloat("caveDantooineLizardCaveMultiplier");
			if (lua->getGlobalFloat("caveDathomirRancorCaveMultiplier") > 0) caveDathomirRancorCaveMultiplier = lua->getGlobalFloat("caveDathomirRancorCaveMultiplier");
			if (lua->getGlobalFloat("caveDathomirSpiderClanCaveMultiplier") > 0) caveDathomirSpiderClanCaveMultiplier = lua->getGlobalFloat("caveDathomirSpiderClanCaveMultiplier");
			if (lua->getGlobalFloat("caveEndorJindaRitualistCaveMultiplier") > 0) caveEndorJindaRitualistCaveMultiplier = lua->getGlobalFloat("caveEndorJindaRitualistCaveMultiplier");
			if (lua->getGlobalFloat("caveEndorKorgaCaveMultiplier") > 0) caveEndorKorgaCaveMultiplier = lua->getGlobalFloat("caveEndorKorgaCaveMultiplier");
			if (lua->getGlobalFloat("caveEndorOrphanedMarauderCaveMultiplier") > 0) caveEndorOrphanedMarauderCaveMultiplier = lua->getGlobalFloat("caveEndorOrphanedMarauderCaveMultiplier");
			if (lua->getGlobalFloat("caveLokDroidEngineerCaveMultiplier") > 0) caveLokDroidEngineerCaveMultiplier = lua->getGlobalFloat("caveLokDroidEngineerCaveMultiplier");
			if (lua->getGlobalFloat("caveLokGasMineMultiplier") > 0) caveLokGasMineMultiplier = lua->getGlobalFloat("caveLokGasMineMultiplier");
			if (lua->getGlobalFloat("caveLokImperialResearchFacilityMultiplier") > 0) caveLokImperialResearchFacilityMultiplier = lua->getGlobalFloat("caveLokImperialResearchFacilityMultiplier");
			if (lua->getGlobalFloat("caveLokNymPirateCaveMultiplier") > 0) caveLokNymPirateCaveMultiplier = lua->getGlobalFloat("caveLokNymPirateCaveMultiplier");
			if (lua->getGlobalFloat("caveNabooNarglatchCaveMultiplier") > 0) caveNabooNarglatchCaveMultiplier = lua->getGlobalFloat("caveNabooNarglatchCaveMultiplier");
			if (lua->getGlobalFloat("caveNabooPirateBunkerMultiplier") > 0) caveNabooPirateBunkerMultiplier = lua->getGlobalFloat("caveNabooPirateBunkerMultiplier");
			if (lua->getGlobalFloat("caveNabooVeermokCaveMultiplier") > 0) caveNabooVeermokCaveMultiplier = lua->getGlobalFloat("caveNabooVeermokCaveMultiplier");
			if (lua->getGlobalFloat("caveRoriBlackSunOutpostBunkerMultiplier") > 0) caveRoriBlackSunOutpostBunkerMultiplier = lua->getGlobalFloat("caveRoriBlackSunOutpostBunkerMultiplier");
			if (lua->getGlobalFloat("caveRoriBorgleBatCaveMultiplier") > 0) caveRoriBorgleBatCaveMultiplier = lua->getGlobalFloat("caveRoriBorgleBatCaveMultiplier");
			if (lua->getGlobalFloat("caveRoriGiantBarkMiteCaveMultiplier") > 0) caveRoriGiantBarkMiteCaveMultiplier = lua->getGlobalFloat("caveRoriGiantBarkMiteCaveMultiplier");
			if (lua->getGlobalFloat("caveRoriKobolaBunkerMultiplier") > 0) caveRoriKobolaBunkerMultiplier = lua->getGlobalFloat("caveRoriKobolaBunkerMultiplier");
			if (lua->getGlobalFloat("caveRoriPygmyTortonCaveMultiplier") > 0) caveRoriPygmyTortonCaveMultiplier = lua->getGlobalFloat("caveRoriPygmyTortonCaveMultiplier");
			if (lua->getGlobalFloat("caveTalusAakuanCaveMultiplier") > 0) caveTalusAakuanCaveMultiplier = lua->getGlobalFloat("caveTalusAakuanCaveMultiplier");
			if (lua->getGlobalFloat("caveTalusBinayrePirateBunkerMultiplier") > 0) caveTalusBinayrePirateBunkerMultiplier = lua->getGlobalFloat("caveTalusBinayrePirateBunkerMultiplier");
			if (lua->getGlobalFloat("caveTalusChunkerBunkerMultiplier") > 0) caveTalusChunkerBunkerMultiplier = lua->getGlobalFloat("caveTalusChunkerBunkerMultiplier");
			if (lua->getGlobalFloat("caveTalusDetainmentCenterMultiplier") > 0) caveTalusDetainmentCenterMultiplier = lua->getGlobalFloat("caveTalusDetainmentCenterMultiplier");
			if (lua->getGlobalFloat("caveTalusErranSifMultiplier") > 0) caveTalusErranSifMultiplier = lua->getGlobalFloat("caveTalusErranSifMultiplier");
			if (lua->getGlobalFloat("caveTalusGiantDecayMiteCaveMultiplier") > 0) caveTalusGiantDecayMiteCaveMultiplier = lua->getGlobalFloat("caveTalusGiantDecayMiteCaveMultiplier");
			if (lua->getGlobalFloat("caveTalusGiantFynockCaveMultiplier") > 0) caveTalusGiantFynockCaveMultiplier = lua->getGlobalFloat("caveTalusGiantFynockCaveMultiplier");
			if (lua->getGlobalFloat("caveTalusKaymurraBiogenticResearchStationMultiplier") > 0) caveTalusKaymurraBiogenticResearchStationMultiplier = lua->getGlobalFloat("caveTalusKaymurraBiogenticResearchStationMultiplier");
			if (lua->getGlobalFloat("caveTalusLostAqualishCaveMultiplier") > 0) caveTalusLostAqualishCaveMultiplier = lua->getGlobalFloat("caveTalusLostAqualishCaveMultiplier");
			if (lua->getGlobalFloat("caveTalusWeaponsDepotMultiplier") > 0) caveTalusWeaponsDepotMultiplier = lua->getGlobalFloat("caveTalusWeaponsDepotMultiplier");
			if (lua->getGlobalFloat("caveTatooineHuttHideoutMultiplier") > 0) caveTatooineHuttHideoutMultiplier = lua->getGlobalFloat("caveTatooineHuttHideoutMultiplier");
			if (lua->getGlobalFloat("caveTatooineSennexCaveMultiplier") > 0) caveTatooineSennexCaveMultiplier = lua->getGlobalFloat("caveTatooineSennexCaveMultiplier");
			if (lua->getGlobalFloat("caveTatooineSquillCaveMultiplier") > 0) caveTatooineSquillCaveMultiplier = lua->getGlobalFloat("caveTatooineSquillCaveMultiplier");
			if (lua->getGlobalFloat("caveTatooineTuskenBunkerMultiplier") > 0) caveTatooineTuskenBunkerMultiplier = lua->getGlobalFloat("caveTatooineTuskenBunkerMultiplier");
			if (lua->getGlobalFloat("poiCorelliaRebelHideoutMultiplier") > 0) poiCorelliaRebelHideoutMultiplier = lua->getGlobalFloat("poiCorelliaRebelHideoutMultiplier");
			if (lua->getGlobalFloat("poiCorelliaRogueCorsecBaseMultiplier") > 0) poiCorelliaRogueCorsecBaseMultiplier = lua->getGlobalFloat("poiCorelliaRogueCorsecBaseMultiplier");
			if (lua->getGlobalFloat("poiCorelliaStrongholdMultiplier") > 0) poiCorelliaStrongholdMultiplier = lua->getGlobalFloat("poiCorelliaStrongholdMultiplier");
			if (lua->getGlobalFloat("poiDantooineAbandonedRebelBaseMultiplier") > 0) poiDantooineAbandonedRebelBaseMultiplier = lua->getGlobalFloat("poiDantooineAbandonedRebelBaseMultiplier");
			if (lua->getGlobalFloat("poiDantooineDantariVillageMultiplier") > 0) poiDantooineDantariVillageMultiplier = lua->getGlobalFloat("poiDantooineDantariVillageMultiplier");
			if (lua->getGlobalFloat("poiDantooineMokkStrongholdMultiplier") > 0) poiDantooineMokkStrongholdMultiplier = lua->getGlobalFloat("poiDantooineMokkStrongholdMultiplier");
			if (lua->getGlobalFloat("poiDathomirCrashSiteMultiplier") > 0) poiDathomirCrashSiteMultiplier = lua->getGlobalFloat("poiDathomirCrashSiteMultiplier");
			if (lua->getGlobalFloat("poiDathomirImperialPrisonMultiplier") > 0) poiDathomirImperialPrisonMultiplier = lua->getGlobalFloat("poiDathomirImperialPrisonMultiplier");
			if (lua->getGlobalFloat("poiDathomirNightsisterLaborCampMultiplier") > 0) poiDathomirNightsisterLaborCampMultiplier = lua->getGlobalFloat("poiDathomirNightsisterLaborCampMultiplier");
			if (lua->getGlobalFloat("poiDathomirNightsisterStrongholdMultiplier") > 0) poiDathomirNightsisterStrongholdMultiplier = lua->getGlobalFloat("poiDathomirNightsisterStrongholdMultiplier");
			if (lua->getGlobalFloat("poiDathomirNightsisterVsSingingMountainMultiplier") > 0) poiDathomirNightsisterVsSingingMountainMultiplier = lua->getGlobalFloat("poiDathomirNightsisterVsSingingMountainMultiplier");
			if (lua->getGlobalFloat("poiDathomirSarlaccMultiplier") > 0) poiDathomirSarlaccMultiplier = lua->getGlobalFloat("poiDathomirSarlaccMultiplier");
			if (lua->getGlobalFloat("poiDathomirSingingMountainClanMultiplier") > 0) poiDathomirSingingMountainClanMultiplier = lua->getGlobalFloat("poiDathomirSingingMountainClanMultiplier");
			if (lua->getGlobalFloat("poiEndorDulokVillageNorthMultiplier") > 0) poiEndorDulokVillageNorthMultiplier = lua->getGlobalFloat("poiEndorDulokVillageNorthMultiplier");
			if (lua->getGlobalFloat("poiEndorDulokVillageSouthMultiplier") > 0) poiEndorDulokVillageSouthMultiplier = lua->getGlobalFloat("poiEndorDulokVillageSouthMultiplier");
			if (lua->getGlobalFloat("poiEndorEwokLakeVillage1Multiplier") > 0) poiEndorEwokLakeVillage1Multiplier = lua->getGlobalFloat("poiEndorEwokLakeVillage1Multiplier");
			if (lua->getGlobalFloat("poiEndorEwokLakeVillage2Multiplier") > 0) poiEndorEwokLakeVillage2Multiplier = lua->getGlobalFloat("poiEndorEwokLakeVillage2Multiplier");
			if (lua->getGlobalFloat("poiEndorEwokTreeVillage1Multiplier") > 0) poiEndorEwokTreeVillage1Multiplier = lua->getGlobalFloat("poiEndorEwokTreeVillage1Multiplier");
			if (lua->getGlobalFloat("poiEndorEwokTreeVillage2Multiplier") > 0) poiEndorEwokTreeVillage2Multiplier = lua->getGlobalFloat("poiEndorEwokTreeVillage2Multiplier");
			if (lua->getGlobalFloat("poiEndorMarauderStrongholdMultiplier") > 0) poiEndorMarauderStrongholdMultiplier = lua->getGlobalFloat("poiEndorMarauderStrongholdMultiplier");
			if (lua->getGlobalFloat("poiLokCanyonCorsairsStrongholdMultiplier") > 0) poiLokCanyonCorsairsStrongholdMultiplier = lua->getGlobalFloat("poiLokCanyonCorsairsStrongholdMultiplier");
			if (lua->getGlobalFloat("poiLokDownedBloodRazorTransportMultiplier") > 0) poiLokDownedBloodRazorTransportMultiplier = lua->getGlobalFloat("poiLokDownedBloodRazorTransportMultiplier");
			if (lua->getGlobalFloat("poiLokImperialOutpostMultiplier") > 0) poiLokImperialOutpostMultiplier = lua->getGlobalFloat("poiLokImperialOutpostMultiplier");
			if (lua->getGlobalFloat("poiLokKimogilaTownMultiplier") > 0) poiLokKimogilaTownMultiplier = lua->getGlobalFloat("poiLokKimogilaTownMultiplier");
			if (lua->getGlobalFloat("poiNabooAbandonedImperialOutpostMultiplier") > 0) poiNabooAbandonedImperialOutpostMultiplier = lua->getGlobalFloat("poiNabooAbandonedImperialOutpostMultiplier");
			if (lua->getGlobalFloat("poiNabooGunganSacredPlaceMultiplier") > 0) poiNabooGunganSacredPlaceMultiplier = lua->getGlobalFloat("poiNabooGunganSacredPlaceMultiplier");
			if (lua->getGlobalFloat("poiNabooGunganTempleMultiplier") > 0) poiNabooGunganTempleMultiplier = lua->getGlobalFloat("poiNabooGunganTempleMultiplier");
			if (lua->getGlobalFloat("poiNabooImperialVsGunganMultiplier") > 0) poiNabooImperialVsGunganMultiplier = lua->getGlobalFloat("poiNabooImperialVsGunganMultiplier");
			if (lua->getGlobalFloat("poiNabooMaulerStrongholdMultiplier") > 0) poiNabooMaulerStrongholdMultiplier = lua->getGlobalFloat("poiNabooMaulerStrongholdMultiplier");
			if (lua->getGlobalFloat("poiNabooMordranMultiplier") > 0) poiNabooMordranMultiplier = lua->getGlobalFloat("poiNabooMordranMultiplier");
			if (lua->getGlobalFloat("poiNabooWeaponTestingFacilityMultiplier") > 0) poiNabooWeaponTestingFacilityMultiplier = lua->getGlobalFloat("poiNabooWeaponTestingFacilityMultiplier");
			if (lua->getGlobalFloat("poiRoriCobralHideoutMultiplier") > 0) poiRoriCobralHideoutMultiplier = lua->getGlobalFloat("poiRoriCobralHideoutMultiplier");
			if (lua->getGlobalFloat("poiRoriGarynRaidersBunkerMultiplier") > 0) poiRoriGarynRaidersBunkerMultiplier = lua->getGlobalFloat("poiRoriGarynRaidersBunkerMultiplier");
			if (lua->getGlobalFloat("poiRoriGungansSwampTownMultiplier") > 0) poiRoriGungansSwampTownMultiplier = lua->getGlobalFloat("poiRoriGungansSwampTownMultiplier");
			if (lua->getGlobalFloat("poiRoriHyperdriveResearchFacilityMultiplier") > 0) poiRoriHyperdriveResearchFacilityMultiplier = lua->getGlobalFloat("poiRoriHyperdriveResearchFacilityMultiplier");
			if (lua->getGlobalFloat("poiRoriImperialEncampmentMultiplier") > 0) poiRoriImperialEncampmentMultiplier = lua->getGlobalFloat("poiRoriImperialEncampmentMultiplier");
			if (lua->getGlobalFloat("poiRoriPoacherVsCreatureBattleMultiplier") > 0) poiRoriPoacherVsCreatureBattleMultiplier = lua->getGlobalFloat("poiRoriPoacherVsCreatureBattleMultiplier");
			if (lua->getGlobalFloat("poiRoriRebelMilitaryBaseMultiplier") > 0) poiRoriRebelMilitaryBaseMultiplier = lua->getGlobalFloat("poiRoriRebelMilitaryBaseMultiplier");
			if (lua->getGlobalFloat("poiTalusCorsecVsFlailBattleMultiplier") > 0) poiTalusCorsecVsFlailBattleMultiplier = lua->getGlobalFloat("poiTalusCorsecVsFlailBattleMultiplier");
			if (lua->getGlobalFloat("poiTalusImperialVsRebelBattleMultiplier") > 0) poiTalusImperialVsRebelBattleMultiplier = lua->getGlobalFloat("poiTalusImperialVsRebelBattleMultiplier");
			if (lua->getGlobalFloat("poiTalusLostVillageOfDurbinMultiplier") > 0) poiTalusLostVillageOfDurbinMultiplier = lua->getGlobalFloat("poiTalusLostVillageOfDurbinMultiplier");
			if (lua->getGlobalFloat("poiTatooineAncientKraytDragonSkeletonMultiplier") > 0) poiTatooineAncientKraytDragonSkeletonMultiplier = lua->getGlobalFloat("poiTatooineAncientKraytDragonSkeletonMultiplier");
			if (lua->getGlobalFloat("poiTatooineFortTuskenMultiplier") > 0) poiTatooineFortTuskenMultiplier = lua->getGlobalFloat("poiTatooineFortTuskenMultiplier");
			if (lua->getGlobalFloat("poiTatooineImperialDetachmentHqMultiplier") > 0) poiTatooineImperialDetachmentHqMultiplier = lua->getGlobalFloat("poiTatooineImperialDetachmentHqMultiplier");
			if (lua->getGlobalFloat("poiTatooineImperialOasisBaseMultiplier") > 0) poiTatooineImperialOasisBaseMultiplier = lua->getGlobalFloat("poiTatooineImperialOasisBaseMultiplier");
			if (lua->getGlobalFloat("poiTatooineJawaTradersMultiplier") > 0) poiTatooineJawaTradersMultiplier = lua->getGlobalFloat("poiTatooineJawaTradersMultiplier");
			if (lua->getGlobalFloat("poiTatooineKraytGraveyardMultiplier") > 0) poiTatooineKraytGraveyardMultiplier = lua->getGlobalFloat("poiTatooineKraytGraveyardMultiplier");
			if (lua->getGlobalFloat("poiTatooineSandcrawlerNeMultiplier") > 0) poiTatooineSandcrawlerNeMultiplier = lua->getGlobalFloat("poiTatooineSandcrawlerNeMultiplier");
			if (lua->getGlobalFloat("poiTatooineVillageRuinsMultiplier") > 0) poiTatooineVillageRuinsMultiplier = lua->getGlobalFloat("poiTatooineVillageRuinsMultiplier");
			if (lua->getGlobalFloat("poiYavin4BlueleafTempleMultiplier") > 0) poiYavin4BlueleafTempleMultiplier = lua->getGlobalFloat("poiYavin4BlueleafTempleMultiplier");
			if (lua->getGlobalFloat("poiYavin4ImperialBaseMultiplier") > 0) poiYavin4ImperialBaseMultiplier = lua->getGlobalFloat("poiYavin4ImperialBaseMultiplier");
			if (lua->getGlobalFloat("poiYavin4WoolamanderTempleMultiplier") > 0) poiYavin4WoolamanderTempleMultiplier = lua->getGlobalFloat("poiYavin4WoolamanderTempleMultiplier");
			
			//Combat
			if (lua->getGlobalFloat("combatDamageMeleeWeaponMultiplier") > 0) combatDamageMeleeWeaponMultiplier = lua->getGlobalFloat("combatDamageMeleeWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageUnarmedWeaponMultiplier") > 0) combatDamageUnarmedWeaponMultiplier = lua->getGlobalFloat("combatDamageUnarmedWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageOneHandWeaponMultiplier") > 0) combatDamageOneHandWeaponMultiplier = lua->getGlobalFloat("combatDamageOneHandWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageTwoHandWeaponMultiplier") > 0) combatDamageTwoHandWeaponMultiplier = lua->getGlobalFloat("combatDamageTwoHandWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamagePolearmWeaponMultiplier") > 0) combatDamagePolearmWeaponMultiplier = lua->getGlobalFloat("combatDamagePolearmWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageRangedWeaponMultiplier") > 0) combatDamageRangedWeaponMultiplier = lua->getGlobalFloat("combatDamageRangedWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamagePistolWeaponMultiplier") > 0) combatDamagePistolWeaponMultiplier = lua->getGlobalFloat("combatDamagePistolWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageCarbineWeaponMultiplier") > 0) combatDamageCarbineWeaponMultiplier = lua->getGlobalFloat("combatDamageCarbineWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageRifleWeaponMultiplier") > 0) combatDamageRifleWeaponMultiplier = lua->getGlobalFloat("combatDamageRifleWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageThrownWeaponMultiplier") > 0) combatDamageThrownWeaponMultiplier = lua->getGlobalFloat("combatDamageThrownWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageHeavyWeaponMultiplier") > 0) combatDamageHeavyWeaponMultiplier = lua->getGlobalFloat("combatDamageHeavyWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageSpecialHeavyWeaponMultiplier") > 0) combatDamageSpecialHeavyWeaponMultiplier = lua->getGlobalFloat("combatDamageSpecialHeavyWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageMineWeaponMultiplier") > 0) combatDamageMineWeaponMultiplier = lua->getGlobalFloat("combatDamageMineWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageJediWeaponMultiplier") > 0) combatDamageJediWeaponMultiplier = lua->getGlobalFloat("combatDamageJediWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageJediOneHandWeaponMultiplier") > 0) combatDamageJediOneHandWeaponMultiplier = lua->getGlobalFloat("combatDamageJediOneHandWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageJediTwoHandWeaponMultiplier") > 0) combatDamageJediTwoHandWeaponMultiplier = lua->getGlobalFloat("combatDamageJediTwoHandWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageJediPolearmWeaponMultiplier") > 0) combatDamageJediPolearmWeaponMultiplier = lua->getGlobalFloat("combatDamageJediPolearmWeaponMultiplier");
			if (lua->getGlobalFloat("combatDamageJediForcePowerMultiplier") > 0) combatDamageJediForcePowerMultiplier = lua->getGlobalFloat("combatDamageJediForcePowerMultiplier");
			if (lua->getGlobalFloat("combatDamageAllMultiplier") > 0) combatDamageAllMultiplier = lua->getGlobalFloat("combatDamageAllMultiplier");

			//Command
			if (lua->getGlobalBoolean("commandCheckForceStatusCommandEnabled") == true || lua->getGlobalBoolean("commandCheckForceStatusCommandEnabled") == false) commandCheckForceStatusCommandEnabled = lua->getGlobalBoolean("commandCheckForceStatusCommandEnabled");
			if (lua->getGlobalBoolean("commandMeditateMergeEnabled") == true || lua->getGlobalBoolean("commandMeditateMergeEnabled") == false) commandMeditateMergeEnabled = lua->getGlobalBoolean("commandMeditateMergeEnabled");
			
			//Crafting 
			if (lua->getGlobalInt("craftingFactoryCrateMaxSize") > 0) craftingFactoryCrateMaxSize = lua->getGlobalInt("craftingFactoryCrateMaxSize");
			if (lua->getGlobalInt("craftingFactoryRunTimeMultiplier") >= 0) craftingFactoryRunTimeMultiplier = lua->getGlobalInt("craftingFactoryRunTimeMultiplier");
			if (lua->getGlobalInt("craftingToolCraftTimeMultiplier") >= 0) craftingToolCraftTimeMultiplier = lua->getGlobalInt("craftingToolCraftTimeMultiplier");
			if (lua->getGlobalInt("craftingMaxSockets") >= 0) craftingMaxSockets = lua->getGlobalInt("craftingMaxSockets");
			if (lua->getGlobalInt("craftingMinSocketMod") >= 0) craftingMinSocketMod = lua->getGlobalInt("craftingMinSocketMod");
			if (lua->getGlobalInt("craftingMaxSocketMod") > 0) craftingMaxSocketMod = lua->getGlobalInt("craftingMaxSocketMod");
			if (lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled") == true || lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled") == false) craftingNewGenerateSocketsEnabled = lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled");
			if (lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled") == true || lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled") == false) craftingWearableContainerSocketsEnabled = lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled");
			if (lua->getGlobalBoolean("craftingNewAssemblyEnabled") == true || lua->getGlobalBoolean("craftingNewAssemblyEnabled") == false) craftingNewAssemblyEnabled = lua->getGlobalBoolean("craftingNewAssemblyEnabled");
			if (lua->getGlobalBoolean("craftingNewExperimentEnabled") == true || lua->getGlobalBoolean("craftingNewExperimentEnabled") == false) craftingNewExperimentEnabled = lua->getGlobalBoolean("craftingNewExperimentEnabled");
			if (lua->getGlobalBoolean("craftingNewRepairEnabled") == true || lua->getGlobalBoolean("craftingNewRepairEnabled") == false) craftingNewRepairEnabled = lua->getGlobalBoolean("craftingNewRepairEnabled");
			if (lua->getGlobalBoolean("craftingRepairBrokenEnabled") == true || lua->getGlobalBoolean("craftingRepairBrokenEnabled") == false) craftingRepairBrokenEnabled = lua->getGlobalBoolean("craftingRepairBrokenEnabled");
			if (lua->getGlobalFloat("craftingRepairMaxMod") > 0 && lua->getGlobalFloat("craftingRepairMaxMod") < 1) craftingRepairMaxMod = lua->getGlobalFloat("craftingRepairMaxMod");
			if (lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled") == true || lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled") == false) craftingCraftedItemsBetterThanLootEnabled = lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled");
			if (lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier") > 0 && lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier") <= 1) craftingCraftedItemsBetterThanLootModifier = lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier");
			if (lua->getGlobalFloat("craftingKineticMaxResists") >= 0 && lua->getGlobalFloat("craftingKineticMaxResists") <= 100) craftingKineticMaxResists = lua->getGlobalFloat("craftingKineticMaxResists");
			if (lua->getGlobalFloat("craftingEnergyMaxResists") >= 0 && lua->getGlobalFloat("craftingEnergyMaxResists") <= 100) craftingEnergyMaxResists = lua->getGlobalFloat("craftingEnergyMaxResists");
			if (lua->getGlobalFloat("craftingBlastMaxResists") >= 0 && lua->getGlobalFloat("craftingBlastMaxResists") <= 100) craftingBlastMaxResists = lua->getGlobalFloat("craftingBlastMaxResists");
			if (lua->getGlobalFloat("craftingHeatMaxResists") >= 0 && lua->getGlobalFloat("craftingHeatMaxResists") <= 100) craftingHeatMaxResists = lua->getGlobalFloat("craftingHeatMaxResists");
			if (lua->getGlobalFloat("craftingColdMaxResists") >= 0 && lua->getGlobalFloat("craftingColdMaxResists") <= 100) craftingColdMaxResists = lua->getGlobalFloat("craftingColdMaxResists");
			if (lua->getGlobalFloat("craftingElectricityMaxResists") >= 0 && lua->getGlobalFloat("craftingElectricityMaxResists") <= 100) craftingElectricityMaxResists = lua->getGlobalFloat("craftingElectricityMaxResists");
			if (lua->getGlobalFloat("craftingAcidMaxResists") >= 0 && lua->getGlobalFloat("craftingAcidMaxResists") <= 100) craftingAcidMaxResists = lua->getGlobalFloat("craftingAcidMaxResists");
			if (lua->getGlobalFloat("craftingStunMaxResists") >= 0 && lua->getGlobalFloat("craftingStunMaxResists") <= 100) craftingStunMaxResists = lua->getGlobalFloat("craftingStunMaxResists");
			if (lua->getGlobalFloat("craftingLightsaberMaxResists") >= 0 && lua->getGlobalFloat("craftingLightsaberMaxResists") <= 100) craftingLightsaberMaxResists = lua->getGlobalFloat("craftingLightsaberMaxResists");
			
			//Creature 
			if (lua->getGlobalBoolean("creatureRandomDifficultyEnabled") == true || lua->getGlobalBoolean("creatureRandomDifficultyEnabled") == false) creatureRandomDifficultyEnabled = lua->getGlobalBoolean("creatureRandomDifficultyEnabled");
			if (lua->getGlobalInt("creatureMaxLevel") > 0) creatureMaxLevel = lua->getGlobalInt("creatureMaxLevel");
			if (lua->getGlobalFloat("creatureBaseScaleMultiplier") > 0) creatureBaseScaleMultiplier = lua->getGlobalFloat("creatureBaseScaleMultiplier");
			if (lua->getGlobalFloat("creatureBaseXPMultiplier") > 0) creatureBaseXPMultiplier = lua->getGlobalFloat("creatureBaseXPMultiplier");
			if (lua->getGlobalFloat("creatureBaseMeatAmountMultiplier") > 0) creatureBaseMeatAmountMultiplier = lua->getGlobalFloat("creatureBaseMeatAmountMultiplier");
			if (lua->getGlobalFloat("creatureBaseHideAmountMultiplier") > 0) creatureBaseHideAmountMultiplier = lua->getGlobalFloat("creatureBaseHideAmountMultiplier");
			if (lua->getGlobalFloat("creatureBaseBoneAmountMultiplier") > 0) creatureBaseBoneAmountMultiplier = lua->getGlobalFloat("creatureBaseBoneAmountMultiplier");
			if (lua->getGlobalFloat("creatureBaseMilkMultiplier") > 0) creatureBaseMilkMultiplier = lua->getGlobalFloat("creatureBaseMilkMultiplier");
			if (lua->getGlobalFloat("creatureBaseLevelMultiplier") > 0) creatureBaseLevelMultiplier = lua->getGlobalFloat("creatureBaseLevelMultiplier");
			if (lua->getGlobalFloat("creatureBaseChanceHitMultiplier") > 0) creatureBaseChanceHitMultiplier = lua->getGlobalFloat("creatureBaseChanceHitMultiplier");
			if (lua->getGlobalFloat("creatureBaseFerocityMultiplier") > 0) creatureBaseFerocityMultiplier = lua->getGlobalFloat("creatureBaseFerocityMultiplier");
			if (lua->getGlobalFloat("creatureBaseDamageMaxMultiplier") > 0) creatureBaseDamageMaxMultiplier = lua->getGlobalFloat("creatureBaseDamageMaxMultiplier");
			if (lua->getGlobalFloat("creatureBaseDamageMinMultiplier") > 0) creatureBaseDamageMinMultiplier = lua->getGlobalFloat("creatureBaseDamageMinMultiplier");
			if (lua->getGlobalFloat("creatureBaseHAMMultiplier") > 0) creatureBaseHAMMultiplier = lua->getGlobalFloat("creatureBaseHAMMultiplier");
			if (lua->getGlobalFloat("creatureBaseHAMMaxMultiplier") > 0) creatureBaseHAMMaxMultiplier = lua->getGlobalFloat("creatureBaseHAMMaxMultiplier");
			if (lua->getGlobalFloat("creatureBaseResistsMultiplier") > 0) creatureBaseResistsMultiplier = lua->getGlobalFloat("creatureBaseResistsMultiplier");
			if (lua->getGlobalFloat("creatureKineticMaxResists") >= 0 && lua->getGlobalFloat("creatureKineticMaxResists") <= 100) creatureKineticMaxResists = lua->getGlobalFloat("creatureKineticMaxResists");
			if (lua->getGlobalFloat("creatureEnergyMaxResists") >= 0 && lua->getGlobalFloat("creatureEnergyMaxResists") <= 100) creatureEnergyMaxResists = lua->getGlobalFloat("creatureEnergyMaxResists");
			if (lua->getGlobalFloat("creatureBlastMaxResists") >= 0 && lua->getGlobalFloat("creatureBlastMaxResists") <= 100) creatureBlastMaxResists = lua->getGlobalFloat("creatureBlastMaxResists");
			if (lua->getGlobalFloat("creatureHeatMaxResists") >= 0 && lua->getGlobalFloat("creatureHeatMaxResists") <= 100) creatureHeatMaxResists = lua->getGlobalFloat("creatureHeatMaxResists");
			if (lua->getGlobalFloat("creatureColdMaxResists") >= 0 && lua->getGlobalFloat("creatureColdMaxResists") <= 100) creatureColdMaxResists = lua->getGlobalFloat("creatureColdMaxResists");
			if (lua->getGlobalFloat("creatureElectricityMaxResists") >= 0 && lua->getGlobalFloat("creatureElectricityMaxResists") <= 100) creatureElectricityMaxResists = lua->getGlobalFloat("creatureElectricityMaxResists");
			if (lua->getGlobalFloat("creatureAcidMaxResists") >= 0 && lua->getGlobalFloat("creatureAcidMaxResists") <= 100) creatureAcidMaxResists = lua->getGlobalFloat("creatureAcidMaxResists");
			if (lua->getGlobalFloat("creatureStunMaxResists") >= 0 && lua->getGlobalFloat("creatureStunMaxResists") <= 100) creatureStunMaxResists = lua->getGlobalFloat("creatureStunMaxResists");
			if (lua->getGlobalFloat("creatureLightsaberMaxResists") >= 0 && lua->getGlobalFloat("creatureLightsaberMaxResists") <= 100) creatureLightsaberMaxResists = lua->getGlobalFloat("creatureLightsaberMaxResists");
			if (lua->getGlobalFloat("creatureWildSpawnDensity") >= 0) creatureWildSpawnDensity = lua->getGlobalFloat("creatureWildSpawnDensity");
			if (lua->getGlobalFloat("creatureSpawnElitePercentage") >= 0 && lua->getGlobalFloat("creatureSpawnElitePercentage") <= 100 && lua->getGlobalFloat("creatureSpawnElitePercentage") + lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100) creatureSpawnElitePercentage = 1000 - (lua->getGlobalFloat("creatureSpawnElitePercentage") * 10);
			if (lua->getGlobalFloat("creatureSpawnHeroicPercentage") >= 0 && lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100 && lua->getGlobalFloat("creatureSpawnElitePercentage") + lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100) creatureSpawnHeroicPercentage = (1000 - lua->getGlobalFloat("creatureSpawnElitePercentage")) - (lua->getGlobalFloat("creatureSpawnHeroicPercentage") * 10);
			if (lua->getGlobalFloat("creatureModBaseScaleModifier") >= 0) creatureModBaseScaleModifier = lua->getGlobalFloat("creatureModBaseScaleModifier");
			if (lua->getGlobalFloat("creatureModBaseXPModifier") >= 0) creatureModBaseXPModifier = lua->getGlobalFloat("creatureModBaseXPModifier");
			if (lua->getGlobalFloat("creatureModBaseMeatAmountModifier") >= 0) creatureModBaseMeatAmountModifier = lua->getGlobalFloat("creatureModBaseMeatAmountModifier");
			if (lua->getGlobalFloat("creatureModBaseHideAmountModifier") >= 0) creatureModBaseHideAmountModifier = lua->getGlobalFloat("creatureModBaseHideAmountModifier");
			if (lua->getGlobalFloat("creatureModBaseBoneAmountModifier") >= 0) creatureModBaseBoneAmountModifier = lua->getGlobalFloat("creatureModBaseBoneAmountModifier");
			if (lua->getGlobalFloat("creatureModBaseMilkModifier") >= 0) creatureModBaseMilkModifier = lua->getGlobalFloat("creatureModBaseMilkModifier");
			if (lua->getGlobalFloat("creatureModBaseLevelModifier") >= 0) creatureModBaseLevelModifier = lua->getGlobalFloat("creatureModBaseLevelModifier");
			if (lua->getGlobalFloat("creatureModBaseChanceHitModifier") >= 0) creatureModBaseChanceHitModifier = lua->getGlobalFloat("creatureModBaseChanceHitModifier");
			if (lua->getGlobalFloat("creatureModBaseFerocityModifier") >= 0) creatureModBaseFerocityModifier = lua->getGlobalFloat("creatureModBaseFerocityModifier");
			if (lua->getGlobalFloat("creatureModBaseDamageMaxModifier") >= 0) creatureModBaseDamageMaxModifier = lua->getGlobalFloat("creatureModBaseDamageMaxModifier");
			if (lua->getGlobalFloat("creatureModBaseDamageMinModifier") >= 0) creatureModBaseDamageMinModifier = lua->getGlobalFloat("creatureModBaseDamageMinModifier");
			if (lua->getGlobalFloat("creatureModBaseHAMModifier") >= 0) creatureModBaseHAMModifier = lua->getGlobalFloat("creatureModBaseHAMModifier");
			if (lua->getGlobalFloat("creatureModBaseHAMMaxModifier") >= 0) creatureModBaseHAMMaxModifier = lua->getGlobalFloat("creatureModBaseHAMMaxModifier");
			if (lua->getGlobalFloat("creatureModBaseResistsModifier") >= 0) creatureModBaseResistsModifier = lua->getGlobalFloat("creatureModBaseResistsModifier");
			if (lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled") == true || lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled") == false) creatureAllCreatureCanSpawnBabyEnabled = lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled");
			if (lua->getGlobalFloat("creatureAllCreatureCanSpawnBabyChance") > 0) creatureAllCreatureCanSpawnBabyChance = lua->getGlobalFloat("creatureAllCreatureCanSpawnBabyChance");
			if (lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled") == true || lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled") == false) creatureBabyRandomDifficultyEnabled = lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled");
			if (lua->getGlobalInt("creatureBabySpawnChanceDestroyMissionLair") > 0) creatureBabySpawnChanceDestroyMissionLair = lua->getGlobalInt("creatureBabySpawnChanceDestroyMissionLair");
			if (lua->getGlobalInt("creatureBabySpawnChanceDynamicSpawn") > 0) creatureBabySpawnChanceDynamicSpawn = lua->getGlobalInt("creatureBabySpawnChanceDynamicSpawn");
			if (lua->getGlobalInt("creatureBabySpawnChanceDynamicLair") > 0) creatureBabySpawnChanceDynamicLair = lua->getGlobalInt("creatureBabySpawnChanceDynamicLair");

			//Creature Handler 
			if (lua->getGlobalInt("creatureTamingMaxDistance") > 0) creatureTamingMaxDistance = lua->getGlobalInt("creatureTamingMaxDistance");
			if (lua->getGlobalFloat("creatureTamingCycleTime") > 0) creatureTamingCycleTime = lua->getGlobalFloat("creatureTamingCycleTime");
			if (lua->getGlobalBoolean("creatureTrainingAlwaysSuccessfulEnabled") == true || lua->getGlobalBoolean("creatureTrainingAlwaysSuccessfulEnabled") == false) creatureTrainingAlwaysSuccessfulEnabled = lua->getGlobalBoolean("creatureTrainingAlwaysSuccessfulEnabled");
			if (lua->getGlobalBoolean("creatureUntrainCreatureMountEnabled") == true || lua->getGlobalBoolean("creatureUntrainCreatureMountEnabled") == false) creatureUntrainCreatureMountEnabled = lua->getGlobalBoolean("creatureUntrainCreatureMountEnabled");
			if (lua->getGlobalBoolean("creatureSetDefaultPetCommandsEnabled") == true || lua->getGlobalBoolean("creatureSetDefaultPetCommandsEnabled") == false) creatureSetDefaultPetCommandsEnabled = lua->getGlobalBoolean("creatureSetDefaultPetCommandsEnabled");
			
			//Dungeon
			if (lua->getGlobalFloat("dungeonCorellianCorvetteMultiplier") > 0) dungeonCorellianCorvetteMultiplier = lua->getGlobalFloat("dungeonCorellianCorvetteMultiplier");
			if (lua->getGlobalFloat("dungeonDeathWatchBunkerMultiplier") > 0) dungeonDeathWatchBunkerMultiplier = lua->getGlobalFloat("dungeonDeathWatchBunkerMultiplier");
			if (lua->getGlobalFloat("dungeonGeonosianBioLabMultiplier") > 0) dungeonGeonosianBioLabMultiplier = lua->getGlobalFloat("dungeonGeonosianBioLabMultiplier");
			if (lua->getGlobalFloat("dungeonWarrenMultiplier") > 0) dungeonWarrenMultiplier = lua->getGlobalFloat("dungeonWarrenMultiplier");
						
			//Faction
			if (lua->getGlobalInt("factionMaxRank") >= 1 && lua->getGlobalInt("factionMaxRank") <= 21) factionMaxRank = lua->getGlobalInt("factionMaxRank");
			if (lua->getGlobalFloat("factionCapMultiplier") > 0) factionCapMultiplier = lua->getGlobalFloat("factionCapMultiplier");

			//Harvest
			if (lua->getGlobalInt("harvestDistance") > 0) harvestDistance = lua->getGlobalInt("harvestDistance");
			if (lua->getGlobalBoolean("harvestAreaEnabled") == true || lua->getGlobalBoolean("harvestAreaEnabled") == false) harvestAreaEnabled = lua->getGlobalBoolean("harvestAreaEnabled");
			if (lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == true || lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == false) harvestAreaCommandOnlyEnabled = lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled");
			if (lua->getGlobalInt("harvestMultiplier") > 0) harvestMultiplier = lua->getGlobalInt("harvestMultiplier");
			if (lua->getGlobalInt("harvestMilkTime") >= 0) harvestMilkTime = lua->getGlobalInt("harvestMilkTime");
			if (lua->getGlobalFloat("harvestDNASampleDistance") > 0) harvestDNASampleDistance = lua->getGlobalFloat("harvestDNASampleDistance");

			//Jedi jediForceCostToTuneEnabled
			if (lua->getGlobalBoolean("jediForceCostToTuneEnabled") == true || lua->getGlobalBoolean("jediForceCostToTuneEnabled") == false) jediForceCostToTuneEnabled = lua->getGlobalBoolean("jediForceCostToTuneEnabled");
			if (lua->getGlobalInt("jediKnightRequirementNumberOfMasters") >= 0) jediKnightRequirementNumberOfMasters = lua->getGlobalInt("jediKnightRequirementNumberOfMasters");
						
			//Loot
			if (lua->getGlobalInt("lootDistance") > 0) lootDistance = lua->getGlobalInt("lootDistance");
			if (lua->getGlobalBoolean("lootAreaEnabled") == true || lua->getGlobalBoolean("lootAreaEnabled") == false) lootAreaEnabled = lua->getGlobalBoolean("lootAreaEnabled");
			if (lua->getGlobalInt("lootCreditMultiplier") > 0) lootCreditMultiplier = lua->getGlobalInt("lootCreditMultiplier");
			if (lua->getGlobalInt("lootAttachmentMax") > 0) lootAttachmentMax = lua->getGlobalInt("lootAttachmentMax");
			if (lua->getGlobalInt("lootAttachmentMin") > 0) lootAttachmentMin = lua->getGlobalInt("lootAttachmentMin");
			if (lua->getGlobalInt("lootAttachmentMaxLevel") > 0 && lua->getGlobalInt("lootAttachmentMaxLevel") <= lua->getGlobalInt("creatureMaxLevel")) lootAttachmentMaxLevel = lua->getGlobalInt("lootAttachmentMaxLevel");
			if (lua->getGlobalInt("lootAttachmentModCount") > 0) lootAttachmentModCount = lua->getGlobalInt("lootAttachmentModCount");
			if (lua->getGlobalInt("lootDropAttachmentModCount") > 0) lootDropAttachmentModCount = lua->getGlobalInt("lootDropAttachmentModCount");
			if (lua->getGlobalBoolean("lootAttachmentNameEnabled") == true || lua->getGlobalBoolean("lootAttachmentNameEnabled") == false) lootAttachmentNameEnabled = lua->getGlobalBoolean("lootAttachmentNameEnabled");
			if (lua->getGlobalBoolean("lootCreditLuckModifier") == true || lua->getGlobalBoolean("lootCreditLuckModifier") == false) lootCreditLuckModifier = lua->getGlobalBoolean("lootCreditLuckModifier");
			if (lua->getGlobalInt("lootMaxLevel") > 0 && lua->getGlobalInt("lootMaxLevel") <= 450 && lua->getGlobalInt("lootMaxLevel") > lua->getGlobalInt("lootMinLevel")) lootMaxLevel = lua->getGlobalInt("lootMaxLevel");
			if (lua->getGlobalInt("lootMinLevel") > 0 && lua->getGlobalInt("lootMinLevel") < lua->getGlobalInt("lootMaxLevel")) lootMaxLevel = lua->getGlobalInt("lootMaxLevel");
			if (lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == true || lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == false) lootShowForceCostDecimalEnabled = lua->getGlobalBoolean("lootShowForceCostDecimalEnabled");
			if (lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == true || lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == false) lootRareColorCrystalsEnabled = lua->getGlobalBoolean("lootRareColorCrystalsEnabled");
			if (lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == true || lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == false) lootGroupCreditsSplitEnabled = lua->getGlobalBoolean("lootGroupCreditsSplitEnabled");
			if (lua->getGlobalFloat("lootChanceMultiplier") > 0) lootChanceMultiplier = lua->getGlobalFloat("lootChanceMultiplier");
			if (lua->getGlobalFloat("lootResourceMultiplier") > 0) lootResourceMultiplier = lua->getGlobalFloat("lootResourceMultiplier");
			if (lua->getGlobalBoolean("lootYellowModifierNameEnabled") == true || lua->getGlobalBoolean("lootYellowModifierNameEnabled") == false) lootYellowModifierNameEnabled = lua->getGlobalBoolean("lootYellowModifierNameEnabled");
			if (lua->getGlobalBoolean("lootYellowModifierNameEnabled") == true && lua->getGlobalString("lootYellowModifierName") !=  "") lootYellowModifierName = lua->getGlobalString("lootYellowModifierName");
			if (lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled") == true || lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled") == false) lootUseLootModifiersForDamageModifiersEnabled = lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled");
			if (lua->getGlobalFloat("lootArmorMaxResists") > 0 && lua->getGlobalFloat("lootArmorMaxResists") <= lua->getGlobalFloat("playerMaxArmorUnSliced")) lootArmorMaxResists = lua->getGlobalFloat("lootArmorMaxResists");
			if (lua->getGlobalBoolean("lootNewLootQualityNamingEnabled") == true || lua->getGlobalBoolean("lootNewLootQualityNamingEnabled") == false) lootNewLootQualityNamingEnabled = lua->getGlobalBoolean("lootNewLootQualityNamingEnabled");
			if (lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled") == true || lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled") == false) lootModifiersAffectLightsaberCrystalsEnabled = lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled");
			if (lua->getGlobalBoolean("lootLevelToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootNewLootQualityNaminlootLevelToItemDescriptionEnabledgEnabled") == false) lootLevelToItemDescriptionEnabled = lua->getGlobalBoolean("lootLevelToItemDescriptionEnabled");
			if (lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled") == false) lootModifierToItemDescriptionEnabled = lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled");
			if (lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled") == false) lootQualityToItemDescriptionEnabled = lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled");

			//Mission 
			if (lua->getGlobalInt("missionBountyExpirationTime") > 0) missionBountyExpirationTime = lua->getGlobalInt("missionBountyExpirationTime");
			if (lua->getGlobalInt("missionExpirationTime") > 0) missionExpirationTime = lua->getGlobalInt("missionExpirationTime");
			if (lua->getGlobalInt("missionMaxCount") > 0) missionMaxCount = lua->getGlobalInt("missionMaxCount");
			if (lua->getGlobalInt("missionListCount") > 0) missionListCount = lua->getGlobalInt("missionListCount");
			if (lua->getGlobalBoolean("missionNameAndLevelEnabled") == true || lua->getGlobalBoolean("missionNameAndLevelEnabled") == false) missionNameAndLevelEnabled = lua->getGlobalBoolean("missionNameAndLevelEnabled");
			if (lua->getGlobalBoolean("missionDirectionSelectionEnabled") == true || lua->getGlobalBoolean("missionDirectionSelectionEnabled") == false) missionDirectionSelectionEnabled = lua->getGlobalBoolean("missionDirectionSelectionEnabled");
			if (lua->getGlobalBoolean("missionLevelSelectionEnabled") == true || lua->getGlobalBoolean("missionLevelSelectionEnabled") == false) missionLevelSelectionEnabled = lua->getGlobalBoolean("missionLevelSelectionEnabled");
			if (lua->getGlobalInt("missionRewardMultiplier") > 0) missionRewardMultiplier = lua->getGlobalInt("missionRewardMultiplier");
			
			//Pet 
			if (lua->getGlobalInt("petCallTime") >= 0) petCallTime = lua->getGlobalInt("petCallTime");
			if (lua->getGlobalInt("petGrowthCycleTime") > 0) petGrowthCycleTime = lua->getGlobalInt("petGrowthCycleTime");
			if (lua->getGlobalInt("petGrowthStagesToGrown") > 0) petGrowthStagesToGrown = lua->getGlobalInt("petGrowthStagesToGrown");
			if (lua->getGlobalBoolean("petStoreInCombatEnabled") == true || lua->getGlobalBoolean("petStoreInCombatEnabled") == false) petStoreInCombatEnabled = lua->getGlobalBoolean("petStoreInCombatEnabled");
			if (lua->getGlobalFloat("petOutOfCombatHAMRegenMultiplier") > 0) petOutOfCombatHAMRegenMultiplier = lua->getGlobalFloat("petOutOfCombatHAMRegenMultiplier");
			if (lua->getGlobalBoolean("petAllMountsUsedByAnyone") == true || lua->getGlobalBoolean("petAllMountsUsedByAnyone") == false) petAllMountsUsedByAnyone = lua->getGlobalBoolean("petAllMountsUsedByAnyone");
			if (lua->getGlobalBoolean("petCallInCombatEnabled") == true || lua->getGlobalBoolean("petCallInCombatEnabled") == false) petCallInCombatEnabled = lua->getGlobalBoolean("petCallInCombatEnabled");
			if (lua->getGlobalFloat("petDamageMultiplier") > 0) petDamageMultiplier = lua->getGlobalFloat("petDamageMultiplier");
			
			//Player 
			if (lua->getGlobalInt("playerSamplingMultiplier") > 0) playerSamplingMultiplier = lua->getGlobalInt("playerSamplingMultiplier");
			if (lua->getGlobalInt("playerSamplingTime") >= 0) playerSamplingTime = lua->getGlobalInt("playerSamplingTime");
			if (lua->getGlobalBoolean("playerSamplingMiniGameEnabled") == true || lua->getGlobalBoolean("playerSamplingMiniGameEnabled") == false) playerSamplingMiniGameEnabled = lua->getGlobalBoolean("playerSamplingMiniGameEnabled");
			if (lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled") == true || lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled") == false) playerSamplingRadioactiveWarningEnabled = lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled");
			if (lua->getGlobalInt("playerMaxLots") > 0) playerMaxLots = lua->getGlobalInt("playerMaxLots");
			if (lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled") == true || lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled") == false) playerGlobalSafetyDepositEnabled = lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled");
			if (lua->getGlobalFloat("playerShuttleBoardingDistance") > 0) playerShuttleBoardingDistance = lua->getGlobalFloat("playerShuttleBoardingDistance");
			if (lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "tutorial" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dungeon1" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "yavin4" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dantooine" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dathomir" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "endor" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase()   == "lok" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "rori" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "talus" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "naboo" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "corellia" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "tatooine") playerStatMigrationLocation = lua->getGlobalString("playerStatMigrationLocation").toLowerCase();
			if (lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled") == true || lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled") == false) playerStatMigrationSalonOnlyEnabled = lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled");
			if (lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled") == true || lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled") == false) playerStatMigrationAnyLocationEnabled = lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled");
			if (lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled") == true || lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled") == false) playerStatMigrationClearBuffsEnabled = lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled");
			if (lua->getGlobalInt("playerWoundsonDeath") >= 0) playerWoundsonDeath = lua->getGlobalInt("playerWoundsonDeath");
			if (lua->getGlobalBoolean("playerBackpackWipeEnabled") == true || lua->getGlobalBoolean("playerBackpackWipeEnabled") == false) playerBackpackWipeEnabled = lua->getGlobalBoolean("playerBackpackWipeEnabled");
			if (lua->getGlobalBoolean("playerChangeWearableColorsEnabled") == true || lua->getGlobalBoolean("playerChangeWearableColorsEnabled") == false) playerChangeWearableColorsEnabled = lua->getGlobalBoolean("playerChangeWearableColorsEnabled");
			if (lua->getGlobalBoolean("playerOverwriteBuffEnabled") == true || lua->getGlobalBoolean("playerOverwriteBuffEnabled") == false) playerOverwriteBuffEnabled = lua->getGlobalBoolean("playerOverwriteBuffEnabled");
			if (lua->getGlobalBoolean("playerWoundHealingAnywhereEnabled") == true || lua->getGlobalBoolean("playerWoundHealingAnywhereEnabled") == false) playerWoundHealingAnywhereEnabled = lua->getGlobalBoolean("playerWoundHealingAnywhereEnabled");
			if (lua->getGlobalBoolean("playerEnhanceHealingAnywhereEnabled") == true || lua->getGlobalBoolean("playerEnhanceHealingAnywhereEnabled") == false) playerEnhanceHealingAnywhereEnabled = lua->getGlobalBoolean("playerEnhanceHealingAnywhereEnabled");
			if (lua->getGlobalInt("playerWoundHealingMultiplier") > 0) playerWoundHealingMultiplier = lua->getGlobalInt("playerWoundHealingMultiplier");
			if (lua->getGlobalInt("playerEnhanceHealingMultiplier") > 0) playerEnhanceHealingMultiplier = lua->getGlobalInt("playerEnhanceHealingMultiplier");
			if (lua->getGlobalInt("playerDamageHealingMultiplier") > 0) playerDamageHealingMultiplier = lua->getGlobalInt("playerDamageHealingMultiplier");			
			if (lua->getGlobalBoolean("playerInsureWeaponsEnabled") == true || lua->getGlobalBoolean("playerInsureWeaponsEnabled") == false) playerInsureWeaponsEnabled = lua->getGlobalBoolean("playerInsureWeaponsEnabled");
			if (lua->getGlobalFloat("playerMeditateHealingMultiplier") >= 0) playerMeditateHealingMultiplier = lua->getGlobalFloat("playerMeditateHealingMultiplier");
			if (lua->getGlobalBoolean("playerMeditateFatigueHealingEnabled") == true || lua->getGlobalBoolean("playerMeditateFatigueHealingEnabled") == false) playerMeditateFatigueHealingEnabled = lua->getGlobalBoolean("playerMeditateFatigueHealingEnabled");
			if (lua->getGlobalInt("playerMeditateFatigueHealingAmount") > 0) playerMeditateFatigueHealingAmount = lua->getGlobalInt("playerMeditateFatigueHealingAmount");			
			if (lua->getGlobalFloat("playerHAMRegenSittingMultiplier") >= 0) playerHAMRegenSittingMultiplier = lua->getGlobalFloat("playerHAMRegenSittingMultiplier");
			if (lua->getGlobalFloat("playerHAMRegenKneelingMultiplier") >= 0) playerHAMRegenKneelingMultiplier = lua->getGlobalFloat("playerHAMRegenKneelingMultiplier");
			if (lua->getGlobalFloat("playerMaxArmorUnSliced") >= 0) playerMaxArmorUnSliced = lua->getGlobalFloat("playerMaxArmorUnSliced");
			if (lua->getGlobalFloat("playerMaxArmorSliced") >= 0) playerMaxArmorSliced = lua->getGlobalFloat("playerMaxArmorSliced");
			if (lua->getGlobalBoolean("playerJediForceRunToggleEnabled") == true || lua->getGlobalBoolean("playerJediForceRunToggleEnabled") == false) playerJediForceRunToggleEnabled = lua->getGlobalBoolean("playerJediForceRunToggleEnabled");
			if (lua->getGlobalBoolean("playerEntertainerHealsAllWoundsEnabled") == true || lua->getGlobalBoolean("playerEntertainerHealsAllWoundsEnabled") == false) playerEntertainerHealsAllWoundsEnabled = lua->getGlobalBoolean("playerEntertainerHealsAllWoundsEnabled");
			if (lua->getGlobalFloat("playerEntertainerWoundHealMultiplier") >= 0) playerEntertainerWoundHealMultiplier = lua->getGlobalFloat("playerEntertainerWoundHealMultiplier");
			if (lua->getGlobalBoolean("playerEntertainerBuffDurationCustomEnabled") == true || lua->getGlobalBoolean("playerEntertainerBuffDurationCustomEnabled") == false) playerEntertainerBuffDurationCustomEnabled = lua->getGlobalBoolean("playerEntertainerBuffDurationCustomEnabled");
			if (lua->getGlobalFloat("playerEnterainerBuffDuration") >= 0) playerEnterainerBuffDuration = lua->getGlobalFloat("playerEnterainerBuffDuration");
			if (lua->getGlobalBoolean("playerEntertainerAllBuffsMusicOrDanceEnabled") == true || lua->getGlobalBoolean("playerEntertainerAllBuffsMusicOrDanceEnabled") == false) playerEntertainerAllBuffsMusicOrDanceEnabled = lua->getGlobalBoolean("playerEntertainerAllBuffsMusicOrDanceEnabled");
			if (lua->getGlobalBoolean("playerEntertainerBuffSelfEnabled") == true || lua->getGlobalBoolean("playerEntertainerBuffSelfEnabled") == false) playerEntertainerBuffSelfEnabled = lua->getGlobalBoolean("playerEntertainerBuffSelfEnabled");
			if (lua->getGlobalBoolean("playerEntertainerInstantBuffEnabled") == true || lua->getGlobalBoolean("playerEntertainerInstantBuffEnabled") == false) playerEntertainerInstantBuffEnabled = lua->getGlobalBoolean("playerEntertainerInstantBuffEnabled");
			if (lua->getGlobalBoolean("playerEntertainerBuffAnywhereEnabled") == true || lua->getGlobalBoolean("playerEntertainerBuffAnywhereEnabled") == false) playerEntertainerBuffAnywhereEnabled = lua->getGlobalBoolean("playerEntertainerBuffAnywhereEnabled");
			if (lua->getGlobalInt("playerSpeedMultiplier") >= 1) playerSpeedMultiplier = lua->getGlobalInt("playerSpeedMultiplier");
			if (lua->getGlobalFloat("playerMeditateTickTime") >= 0) playerMeditateTickTime = lua->getGlobalFloat("playerMeditateTickTime");
			if (lua->getGlobalFloat("playerJediForceMeditateMultiplier") >= 0) playerJediForceMeditateMultiplier = lua->getGlobalFloat("playerJediForceMeditateMultiplier");
			if (lua->getGlobalInt("playerMaxLevelNonCHMount") >= 1) playerMaxLevelNonCHMount = lua->getGlobalInt("playerMaxLevelNonCHMount");
			
			//Player Creation 
			if (lua->getGlobalInt("playerCreationNewCreationTime") >= 0) playerCreationNewCreationTime = lua->getGlobalInt("playerCreationNewCreationTime");
			if (lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == true || lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == false) playerCreationAllLanguagesEnabled = lua->getGlobalBoolean("playerCreationAllLanguagesEnabled");
			if (lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == true || lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == false) playerCreationJoinGalaxyChatEnabled = lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled");
			if (lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled") == true || lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled") == false) playerCreationGrantAllNoviceSkillsEnabled = lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled");

			//Player Payments
			if (lua->getGlobalBoolean("playerPaymentCashAndBankEnabled") == true || lua->getGlobalBoolean("playerPaymentCashAndBankEnabled") == false) playerPaymentCashAndBankEnabled = lua->getGlobalBoolean("playerPaymentCashAndBankEnabled");

			//Player XP 
			if (lua->getGlobalBoolean("playerForagingXPEnabled") == true || lua->getGlobalBoolean("playerForagingXPEnabled") == false) playerForagingXPEnabled = lua->getGlobalBoolean("playerForagingXPEnabled");
			if (lua->getGlobalBoolean("playerMilkingXPEnabled") == true || lua->getGlobalBoolean("playerMilkingXPEnabled") == false) playerMilkingXPEnabled = lua->getGlobalBoolean("playerMilkingXPEnabled");
			if (lua->getGlobalBoolean("playerAwardSelfHealingXPEnabled") == true || lua->getGlobalBoolean("playerAwardSelfHealingXPEnabled") == false) playerAwardSelfHealingXPEnabled = lua->getGlobalBoolean("playerAwardSelfHealingXPEnabled");
			if (lua->getGlobalBoolean("playerAwardPetHealingXPEnabled") == true || lua->getGlobalBoolean("playerAwardPetHealingXPEnabled") == false) playerAwardPetHealingXPEnabled = lua->getGlobalBoolean("playerAwardPetHealingXPEnabled");
			if (lua->getGlobalBoolean("playerAwardXPWeaponSplitEnabled") == true || lua->getGlobalBoolean("playerAwardXPWeaponSplitEnabled") == false) playerAwardXPWeaponSplitEnabled = lua->getGlobalBoolean("playerAwardXPWeaponSplitEnabled");
			if (lua->getGlobalFloat("playerDNASamplingXPMultiplier") > 0) playerDNASamplingXPMultiplier = lua->getGlobalFloat("playerDNASamplingXPMultiplier");
			if (lua->getGlobalFloat("playerBountyHunterXPMultiplier") > 0) playerBountyHunterXPMultiplier = lua->getGlobalFloat("playerBountyHunterXPMultiplier");
			if (lua->getGlobalFloat("playerWildernessSurvivalXPMultiplier") > 0) playerWildernessSurvivalXPMultiplier = lua->getGlobalFloat("playerWildernessSurvivalXPMultiplier");
			if (lua->getGlobalFloat("playerCombatXPMultiplier") > 0) playerCombatXPMultiplier = lua->getGlobalFloat("playerCombatXPMultiplier");
			if (lua->getGlobalFloat("playerOnehandedWeaponsXPMultiplier") > 0) playerOnehandedWeaponsXPMultiplier = lua->getGlobalFloat("playerOnehandedWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerPolearmWeaponsXPMultiplier") > 0) playerPolearmWeaponsXPMultiplier = lua->getGlobalFloat("playerPolearmWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerTwohandedWeaponsXPMultiplier") > 0) playerTwohandedWeaponsXPMultiplier = lua->getGlobalFloat("playerTwohandedWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerUnarmedCombatXPMultiplier") > 0) playerUnarmedCombatXPMultiplier = lua->getGlobalFloat("playerUnarmedCombatXPMultiplier");
			if (lua->getGlobalFloat("playerCarbineWeaponsXPMultiplier") > 0) playerCarbineWeaponsXPMultiplier = lua->getGlobalFloat("playerCarbineWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerHeavyWeaponsXPMultiplier") > 0) playerHeavyWeaponsXPMultiplier = lua->getGlobalFloat("playerHeavyWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerPistolWeaponsXPMultiplier") > 0) playerPistolWeaponsXPMultiplier = lua->getGlobalFloat("playerPistolWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerRifleWeaponsXPMultiplier") > 0) playerRifleWeaponsXPMultiplier = lua->getGlobalFloat("playerRifleWeaponsXPMultiplier");
			if (lua->getGlobalFloat("playerBioEngineerCraftingXPMultiplier") > 0) playerBioEngineerCraftingXPMultiplier = lua->getGlobalFloat("playerBioEngineerCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerArmorCraftingXPMultiplier") > 0) playerArmorCraftingXPMultiplier = lua->getGlobalFloat("playerArmorCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerTailoringXPMultiplier") > 0) playerTailoringXPMultiplier = lua->getGlobalFloat("playerTailoringXPMultiplier");
			if (lua->getGlobalFloat("playerDroidCraftingXPMultiplier") > 0) playerDroidCraftingXPMultiplier = lua->getGlobalFloat("playerDroidCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerFoodCraftingXPMultiplier") > 0) playerFoodCraftingXPMultiplier = lua->getGlobalFloat("playerFoodCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerGeneralCraftingXPMultiplier") > 0) playerGeneralCraftingXPMultiplier = lua->getGlobalFloat("playerGeneralCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerMedicineCraftingXPMultiplier") > 0) playerMedicineCraftingXPMultiplier = lua->getGlobalFloat("playerMedicineCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerSpiceCraftingXPMultiplier") > 0) playerSpiceCraftingXPMultiplier = lua->getGlobalFloat("playerSpiceCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerStructureCraftingXPMultiplier") > 0) playerStructureCraftingXPMultiplier = lua->getGlobalFloat("playerStructureCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerWeaponCraftingXPMultiplier") > 0) playerWeaponCraftingXPMultiplier = lua->getGlobalFloat("playerWeaponCraftingXPMultiplier");
			if (lua->getGlobalFloat("playerCreatureHandlingXPMultiplier") > 0) playerCreatureHandlingXPMultiplier = lua->getGlobalFloat("playerCreatureHandlingXPMultiplier");
			if (lua->getGlobalFloat("playerDancingXPMultiplier") > 0) playerDancingXPMultiplier = lua->getGlobalFloat("playerDancingXPMultiplier");
			if (lua->getGlobalFloat("playerEntertainerHealingXPMultiplier") > 0) playerEntertainerHealingXPMultiplier = lua->getGlobalFloat("playerEntertainerHealingXPMultiplier");
			if (lua->getGlobalFloat("playerImageDesignerXPMultiplier") > 0) playerImageDesignerXPMultiplier = lua->getGlobalFloat("playerImageDesignerXPMultiplier");
			if (lua->getGlobalFloat("playerJediXPMultiplier") > 0) playerJediXPMultiplier = lua->getGlobalFloat("playerJediXPMultiplier");
			if (lua->getGlobalFloat("playerMedicalXPMultiplier") > 0) playerMedicalXPMultiplier = lua->getGlobalFloat("playerMedicalXPMultiplier");
			if (lua->getGlobalFloat("playerMerchantXPMultiplier") > 0) playerMerchantXPMultiplier = lua->getGlobalFloat("playerMerchantXPMultiplier");
			if (lua->getGlobalFloat("playerMusicianXPMultiplier") > 0) playerMusicianXPMultiplier = lua->getGlobalFloat("playerMusicianXPMultiplier");
			if (lua->getGlobalFloat("playerPoliticalXPMultiplier") > 0) playerPoliticalXPMultiplier = lua->getGlobalFloat("playerPoliticalXPMultiplier");
			if (lua->getGlobalFloat("playerSurveyingXPMultiplier") > 0) playerSurveyingXPMultiplier = lua->getGlobalFloat("playerSurveyingXPMultiplier");
			if (lua->getGlobalFloat("playerScoutingXPMultiplier") > 0) playerScoutingXPMultiplier = lua->getGlobalFloat("playerScoutingXPMultiplier");
			if (lua->getGlobalFloat("playerShipwrightXPMultiplier") > 0) playerShipwrightXPMultiplier = lua->getGlobalFloat("playerShipwrightXPMultiplier");
			if (lua->getGlobalFloat("playerSlicingXPMultiplier") > 0) playerSlicingXPMultiplier = lua->getGlobalFloat("playerSlicingXPMultiplier");
			if (lua->getGlobalFloat("playerStarshipCombatXPMultiplier") > 0) playerStarshipCombatXPMultiplier = lua->getGlobalFloat("playerStarshipCombatXPMultiplier");
			if (lua->getGlobalFloat("playerSquadLeadershipXPMultiplier") > 0) playerSquadLeadershipXPMultiplier = lua->getGlobalFloat("playerSquadLeadershipXPMultiplier");
			if (lua->getGlobalFloat("playerTrappingXPMultiplier") > 0) playerTrappingXPMultiplier = lua->getGlobalFloat("playerTrappingXPMultiplier");
			if (lua->getGlobalInt("playerJediNegativeXPCap") <= 0 && lua->getGlobalInt("playerJediNegativeXPCap") >= 0) playerJediNegativeXPCap = lua->getGlobalInt("playerJediNegativeXPCap");
			if (lua->getGlobalBoolean("playerJediAwardedCombatXPEnabled") == true || lua->getGlobalBoolean("playerJediAwardedCombatXPEnabled") == false) playerJediAwardedCombatXPEnabled = lua->getGlobalBoolean("playerJediAwardedCombatXPEnabled");
			if (lua->getGlobalBoolean("playerJediPvEForceRankXPEnabled") == true || lua->getGlobalBoolean("playerJediPvEForceRankXPEnabled") == false) playerJediPvEForceRankXPEnabled = lua->getGlobalBoolean("playerJediPvEForceRankXPEnabled");
			if (lua->getGlobalFloat("playerJediForceRankXPMultiplier") > 0) playerJediForceRankXPMultiplier = lua->getGlobalFloat("playerJediForceRankXPMultiplier");
			if (lua->getGlobalBoolean("playerMeditateGrantsHealingXPEnabled") == true || lua->getGlobalBoolean("playerMeditateGrantsHealingXPEnabled") == false) playerMeditateGrantsHealingXPEnabled = lua->getGlobalBoolean("playerMeditateGrantsHealingXPEnabled");
			if (lua->getGlobalBoolean("playerXPBasedOnLevelEnabled") == true || lua->getGlobalBoolean("playerXPBasedOnLevelEnabled") == false) playerXPBasedOnLevelEnabled = lua->getGlobalBoolean("playerXPBasedOnLevelEnabled");
			if (lua->getGlobalBoolean("playerCHXPModEnabled") == true || lua->getGlobalBoolean("playerCHXPModEnabled") == false) playerCHXPModEnabled = lua->getGlobalBoolean("playerCHXPModEnabled");
			if (lua->getGlobalBoolean("playerCHCombatXPEnabled") == true || lua->getGlobalBoolean("playerCHCombatXPEnabled") == false) playerCHCombatXPEnabled = lua->getGlobalBoolean("playerCHCombatXPEnabled");
			
			//Resources 
			if (lua->getGlobalBoolean("resourcesAddNameEnabled") == true || lua->getGlobalBoolean("resourcesAddNameEnabled") == false) resourcesAddNameEnabled = lua->getGlobalBoolean("resourcesAddNameEnabled");
			if (lua->getGlobalInt("resourcesMinimumQuality") >= 0 && lua->getGlobalInt("resourcesMinimumQuality") <= lua->getGlobalInt("resourcesMaximumQuality")) resourcesMinimumQuality = lua->getGlobalInt("resourcesMinimumQuality");
			if (lua->getGlobalInt("resourcesMaximumQuality") <= 1000 && lua->getGlobalInt("resourcesMaximumQuality") >= lua->getGlobalInt("resourcesMinimumQuality")) resourcesMaximumQuality = lua->getGlobalInt("resourcesMaximumQuality");
			if (lua->getGlobalInt("resourcesContainerSize") > 0) resourcesContainerSize = lua->getGlobalInt("resourcesContainerSize");
			
			//Skills
			if (lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled") == true || lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled") == false) skillsInstantMasterPoliticianEnabled = lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled");
			if (lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled") == true || lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled") == false) skillsInstantMasterMerchantEnabled = lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled");
			
			//Slicing
			if (lua->getGlobalBoolean("slicingNewSliceEnabled") == true || lua->getGlobalBoolean("slicingNewSliceEnabled") == false) slicingNewSliceEnabled = lua->getGlobalBoolean("slicingNewSliceEnabled");
			if (lua->getGlobalFloat("slicingTerminalSliceCooldown") >= 0) slicingTerminalSliceCooldown = lua->getGlobalFloat("slicingTerminalSliceCooldown");
			if (lua->getGlobalBoolean("slicingArmorSliceSocketsEnabled") == true || lua->getGlobalBoolean("slicingArmorSliceSocketsEnabled") == false) slicingArmorSliceSocketsEnabled = lua->getGlobalBoolean("slicingArmorSliceSocketsEnabled");
			if (lua->getGlobalBoolean("slicingArmorPierceSliceEnabled") == true || lua->getGlobalBoolean("slicingArmorPierceSliceEnabled") == false) slicingArmorPierceSliceEnabled = lua->getGlobalBoolean("slicingArmorPierceSliceEnabled");
			if (lua->getGlobalBoolean("slicingWeaponPierceSliceEnabled") == true || lua->getGlobalBoolean("slicingWeaponPierceSliceEnabled") == false) slicingWeaponPierceSliceEnabled = lua->getGlobalBoolean("slicingWeaponPierceSliceEnabled");

			//Structure
			if (lua->getGlobalInt("structureMaxItemsPerLot") > 0) structureMaxItemsPerLot = lua->getGlobalInt("structureMaxItemsPerLot");
			if (lua->getGlobalInt("structureMaxCivicBuildingItems") >= 0) structureMaxCivicBuildingItems = lua->getGlobalInt("structureMaxCivicBuildingItems");
			if (lua->getGlobalInt("structureMaxZeroLotBuildingItems") >= 0) structureMaxZeroLotBuildingItems = lua->getGlobalInt("structureMaxZeroLotBuildingItems");
			if (lua->getGlobalInt("structureMaxItemsPerStructure") > 0) structureMaxItemsPerStructure = lua->getGlobalInt("structureMaxItemsPerStructure");
			if (lua->getGlobalBoolean("structureMaxItemsEnabled") == true || lua->getGlobalBoolean("structureMaxItemsEnabled") == false) structureMaxItemsEnabled = lua->getGlobalBoolean("structureMaxItemsEnabled");
			if (lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == true || lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == false) structureShowHouseMaxItemsEnabled = lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled");
			if (lua->getGlobalInt("structureBaseMaintenanceRateMultiplier") >= 0) structureBaseMaintenanceRateMultiplier = lua->getGlobalInt("structureBaseMaintenanceRateMultiplier");
			if (lua->getGlobalInt("structureBasePowerRateMultiplier") >= 0) structureBasePowerRateMultiplier = lua->getGlobalInt("structureBasePowerRateMultiplier");
			if (lua->getGlobalInt("cityMaintenanceBaseMultiplier") >= 0) cityMaintenanceBaseMultiplier = lua->getGlobalInt("cityMaintenanceBaseMultiplier");
			if (lua->getGlobalInt("cityMaintenanceRateMultiplier") >= 0) cityMaintenanceRateMultiplier = lua->getGlobalInt("cityMaintenanceRateMultiplier");
			if (lua->getGlobalBoolean("structureAllowAllZonesEnabled") == true || lua->getGlobalBoolean("structureAllowAllZonesEnabled") == false) structureAllowAllZonesEnabled = lua->getGlobalBoolean("structureAllowAllZonesEnabled");
			if (lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled") == true || lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled") == false) structureInstallationQuickAddMaintenanceEnabled = lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled");
			if (lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount") > 0 && lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount") <= 100) structureInstallationQuickAddMaintenanceAmount = lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount");
			if (lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled") == true || lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled") == false) structureInstallationQuickAddPowerEnabled = lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled");
			if (lua->getGlobalInt("structureInstallationQuickAddPowerAmount") > 0 && lua->getGlobalInt("structureInstallationQuickAddPowerAmount") <= 100) structureInstallationQuickAddPowerAmount = lua->getGlobalInt("structureInstallationQuickAddPowerAmount");
			if (lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled") == true || lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled") == false) structureInstallationResourcesRetrieveAllEnabled = lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled");
			
			//Vehicle
			if (lua->getGlobalInt("vehicleBaseDecayCycle") >= 0) vehicleBaseDecayCycle = lua->getGlobalInt("vehicleBaseDecayCycle");
			if (lua->getGlobalInt("vehicleBaseDecayRate") >= 0) vehicleBaseDecayRate = lua->getGlobalInt("vehicleBaseDecayRate");
			if (lua->getGlobalBoolean("vehicleInitialDecayEnabled") == true || lua->getGlobalBoolean("vehicleInitialDecayEnabled") == false) vehicleInitialDecayEnabled = lua->getGlobalBoolean("vehicleInitialDecayEnabled");
			if (lua->getGlobalInt("vehicleCallTime") >= 0) vehicleCallTime = lua->getGlobalInt("vehicleCallTime");
			if (lua->getGlobalBoolean("vehicleStoreInCombatEnabled") == true || lua->getGlobalBoolean("vehicleStoreInCombatEnabled") == false) vehicleStoreInCombatEnabled = lua->getGlobalBoolean("vehicleStoreInCombatEnabled");
			
			//Vendor
			if (lua->getGlobalBoolean("vendorLowMaintenanceEmailEnabled") == true || lua->getGlobalBoolean("vendorLowMaintenanceEmailEnabled") == false) vendorLowMaintenanceEmailEnabled = lua->getGlobalBoolean("vendorLowMaintenanceEmailEnabled");
			if (lua->getGlobalInt("vendorLowMaintenanceEmailWarningThreshold") > 0) vendorLowMaintenanceEmailWarningThreshold = lua->getGlobalInt("vendorLowMaintenanceEmailWarningThreshold");
			if (lua->getGlobalBoolean("vendorSkimSalesForMaintenanceEnabled") == true || lua->getGlobalBoolean("vendorSkimSalesForMaintenanceEnabled") == false) vendorSkimSalesForMaintenanceEnabled = lua->getGlobalBoolean("vendorSkimSalesForMaintenanceEnabled");
			if (lua->getGlobalFloat("vendorSkimSalesForMaintenancePercent") > 0) vendorSkimSalesForMaintenancePercent = lua->getGlobalFloat("vendorSkimSalesForMaintenancePercent");
			
			//Wearables
			if (lua->getGlobalBoolean("wearablesFactionEnabled") == true || lua->getGlobalBoolean("wearablesFactionEnabled") == false) wearablesFactionEnabled = lua->getGlobalBoolean("wearablesFactionEnabled");
			if (lua->getGlobalBoolean("wearablesAllPlayerRacesEnabled") == true || lua->getGlobalBoolean("wearablesAllPlayerRacesEnabled") == false) wearablesAllPlayerRacesEnabled = lua->getGlobalBoolean("wearablesAllPlayerRacesEnabled");
			
		} catch (const Exception& e) {
			delete lua;
			return false;
		}
		delete lua;
		return true;
	}

// Static initializer to run loadConfigData when globalVariables.cpp is initialized
	namespace {
		struct GlobalsInitializer {
			GlobalsInitializer() {
				if (!loadConfigData()) {
					//std::cerr << "Failed to load config data." << std::endl;
				}
			}
		};
		GlobalsInitializer globalsInitializer;  // This will run at program startup
	}
}
