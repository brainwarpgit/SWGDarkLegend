#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <unordered_map>
#include <string>

namespace globalVariables {

//Variables

//Armor
	extern float armorPSGDecayRateMultiplier;
	extern float armorDecayRateMultiplier;

//Auction
	extern int auctionMaxBazaarPrice;
	extern int auctionMaxSales;
	extern int auctionMaxSalesFee;
	extern int auctionVendorExpirePeriod;
	extern int auctionCommodityExpirePeriod;

//Caves and POIs
	extern float caveCorelliaAfarathuCaveMultiplier;
	extern float caveCorelliaDrallCaveMultiplier;
	extern float caveCorelliaLordNyaxCultMultiplier;
	extern float caveDantooineForceCrystalHunterCaveMultiplier;
	extern float caveDantooineJantaCaveMultiplier;
	extern float caveDantooineKungaStrongholdMultiplier;
	extern float caveDantooineLizardCaveMultiplier;
	extern float caveDathomirRancorCaveMultiplier;
	extern float caveDathomirSpiderClanCaveMultiplier;
	extern float caveEndorJindaRitualistCaveMultiplier;
	extern float caveEndorKorgaCaveMultiplier;
	extern float caveEndorOrphanedMarauderCaveMultiplier;
	extern float caveLokDroidEngineerCaveMultiplier;
	extern float caveLokGasMineMultiplier;
	extern float caveLokImperialResearchFacilityMultiplier;
	extern float caveLokNymPirateCaveMultiplier;
	extern float caveNabooNarglatchCaveMultiplier;
	extern float caveNabooPirateBunkerMultiplier;
	extern float caveNabooVeermokCaveMultiplier;
	extern float caveRoriBlackSunOutpostBunkerMultiplier;
	extern float caveRoriBorgleBatCaveMultiplier;
	extern float caveRoriGiantBarkMiteCaveMultiplier;
	extern float caveRoriKobolaBunkerMultiplier;
	extern float caveRoriPygmyTortonCaveMultiplier;
	extern float caveTalusAakuanCaveMultiplier;
	extern float caveTalusBinayrePirateBunkerMultiplier;
	extern float caveTalusChunkerBunkerMultiplier;
	extern float caveTalusDetainmentCenterMultiplier;
	extern float caveTalusErranSifMultiplier;
	extern float caveTalusGiantDecayMiteCaveMultiplier;
	extern float caveTalusGiantFynockCaveMultiplier;
	extern float caveTalusKaymurraBiogenticResearchStationMultiplier;
	extern float caveTalusLostAqualishCaveMultiplier;
	extern float caveTalusWeaponsDepotMultiplier;
	extern float caveTatooineHuttHideoutMultiplier;
	extern float caveTatooineSennexCaveMultiplier;
	extern float caveTatooineSquillCaveMultiplier;
	extern float caveTatooineTuskenBunkerMultiplier;
	extern float poiCorelliaRebelHideoutMultiplier;
	extern float poiCorelliaRogueCorsecBaseMultiplier;
	extern float poiCorelliaStrongholdMultiplier;
	extern float poiDantooineAbandonedRebelBaseMultiplier;
	extern float poiDantooineDantariVillageMultiplier;
	extern float poiDantooineMokkStrongholdMultiplier;
	extern float poiDathomirCrashSiteMultiplier;
	extern float poiDathomirImperialPrisonMultiplier;
	extern float poiDathomirNightsisterLaborCampMultiplier;
	extern float poiDathomirNightsisterStrongholdMultiplier;
	extern float poiDathomirNightsisterVsSingingMountainMultiplier;
	extern float poiDathomirSarlaccMultiplier;
	extern float poiDathomirSingingMountainClanMultiplier;
	extern float poiEndorDulokVillageNorthMultiplier;
	extern float poiEndorDulokVillageSouthMultiplier;
	extern float poiEndorEwokLakeVillage1Multiplier;
	extern float poiEndorEwokLakeVillage2Multiplier;
	extern float poiEndorEwokTreeVillage1Multiplier;
	extern float poiEndorEwokTreeVillage2Multiplier;
	extern float poiEndorMarauderStrongholdMultiplier;
	extern float poiLokCanyonCorsairsStrongholdMultiplier;
	extern float poiLokDownedBloodRazorTransportMultiplier;
	extern float poiLokImperialOutpostMultiplier;
	extern float poiLokKimogilaTownMultiplier;
	extern float poiNabooAbandonedImperialOutpostMultiplier;
	extern float poiNabooGunganSacredPlaceMultiplier;
	extern float poiNabooGunganTempleMultiplier;
	extern float poiNabooImperialVsGunganMultiplier;
	extern float poiNabooMaulerStrongholdMultiplier;
	extern float poiNabooMordranMultiplier;
	extern float poiNabooWeaponTestingFacilityMultiplier;
	extern float poiRoriCobralHideoutMultiplier;
	extern float poiRoriGarynRaidersBunkerMultiplier;
	extern float poiRoriGungansSwampTownMultiplier;
	extern float poiRoriHyperdriveResearchFacilityMultiplier;
	extern float poiRoriImperialEncampmentMultiplier;
	extern float poiRoriPoacherVsCreatureBattleMultiplier;
	extern float poiRoriRebelMilitaryBaseMultiplier;
	extern float poiTalusCorsecVsFlailBattleMultiplier;
	extern float poiTalusImperialVsRebelBattleMultiplier;
	extern float poiTalusLostVillageOfDurbinMultiplier;
	extern float poiTatooineAncientKraytDragonSkeletonMultiplier;
	extern float poiTatooineFortTuskenMultiplier;
	extern float poiTatooineImperialDetachmentHqMultiplier;
	extern float poiTatooineImperialOasisBaseMultiplier;
	extern float poiTatooineJawaTradersMultiplier;
	extern float poiTatooineKraytGraveyardMultiplier;
	extern float poiTatooineSandcrawlerNeMultiplier;
	extern float poiTatooineVillageRuinsMultiplier;
	extern float poiYavin4BlueleafTempleMultiplier;
	extern float poiYavin4ImperialBaseMultiplier;
	extern float poiYavin4WoolamanderTempleMultiplier;

//Combat
	extern float combatDamageMeleeWeaponMultiplier;
	extern float combatDamageUnarmedWeaponMultiplier;
	extern float combatDamageOneHandWeaponMultiplier;
	extern float combatDamageTwoHandWeaponMultiplier;
	extern float combatDamagePolearmWeaponMultiplier;
	extern float combatDamageRangedWeaponMultiplier;
	extern float combatDamagePistolWeaponMultiplier;
	extern float combatDamageCarbineWeaponMultiplier;
	extern float combatDamageRifleWeaponMultiplier;
	extern float combatDamageThrownWeaponMultiplier;
	extern float combatDamageHeavyWeaponMultiplier;
	extern float combatDamageSpecialHeavyWeaponMultiplier;
	extern float combatDamageMineWeaponMultiplier;
	extern float combatDamageJediWeaponMultiplier;
	extern float combatDamageJediOneHandWeaponMultiplier;
	extern float combatDamageJediTwoHandWeaponMultiplier;
	extern float combatDamageJediPolearmWeaponMultiplier;
	extern float combatDamageJediForcePowerMultiplier;
	extern float combatDamageAllMultiplier;
	extern bool combatCriticalDamageEnabled;
	extern float combatCriticalMultilier;
	extern float combatLegendaryCriticalMultiplier;
	extern float combatCriticalMaxRollModifier;
	
//Command
	extern bool commandCheckForceStatusCommandEnabled;
	extern bool commandMeditateMergeEnabled;
	extern bool commandObjectCreateAttachmentEnabled;
	extern bool commandfsVillageEnabled;
	extern bool commandRegrantSkillsEnabled;

//Crafting
	extern int craftingFactoryCrateMaxSize;
	extern int craftingFactoryRunTimeMultiplier;
	extern int craftingToolCraftTimeMultiplier;
	extern int craftingMaxSockets;
	extern int craftingMinSocketMod;
	extern int craftingMaxSocketMod;
	extern bool craftingNewGenerateSocketsEnabled;
	extern bool craftingWearableContainerSocketsEnabled;
	extern bool craftingNewAssemblyEnabled;
	extern bool craftingNewExperimentEnabled;
	extern bool craftingNewRepairEnabled;
	extern bool craftingRepairBrokenEnabled;
	extern float craftingRepairMaxMod;
	extern bool craftingCraftedItemsBetterThanLootEnabled;
	extern float craftingCraftedItemsBetterThanLootModifier;
	extern float craftingKineticMaxResists;
	extern float craftingEnergyMaxResists;
	extern float craftingBlastMaxResists;
	extern float craftingHeatMaxResists;
	extern float craftingColdMaxResists;
	extern float craftingElectricityMaxResists;
	extern float craftingAcidMaxResists;
	extern float craftingStunMaxResists;
	extern float craftingLightsaberMaxResists;
	extern float craftingAssemblyModifier;
	extern float craftingPracticeXPMultiplier;
	extern bool craftingWhileEntertainingEnabled;
	
// Creature
	extern bool creatureRandomDifficultyEnabled;
	extern int creatureMaxLevel;
	extern float creatureKineticMaxResists;
	extern float creatureEnergyMaxResists;
	extern float creatureBlastMaxResists;
	extern float creatureHeatMaxResists;
	extern float creatureColdMaxResists;
	extern float creatureElectricityMaxResists;
	extern float creatureAcidMaxResists;
	extern float creatureStunMaxResists;
	extern float creatureLightsaberMaxResists;
	extern float creatureBaseScaleMultiplier;
	extern float creatureBaseXPMultiplier;
	extern float creatureBaseMeatAmountMultiplier;
	extern float creatureBaseHideAmountMultiplier;
	extern float creatureBaseBoneAmountMultiplier;
	extern float creatureBaseMilkMultiplier;
	extern float creatureBaseLevelMultiplier;
	extern float creatureBaseChanceHitMultiplier;
	extern float creatureBaseFerocityMultiplier;
	extern float creatureBaseDamageMaxMultiplier;
	extern float creatureBaseDamageMinMultiplier;
	extern float creatureBaseHAMMultiplier;
	extern float creatureBaseHAMMaxMultiplier;
	extern float creatureBaseResistsMultiplier;
	extern float creatureWildSpawnDensity;
	extern float creatureSpawnElitePercentage;
	extern float creatureSpawnHeroicPercentage;
	extern float creatureModBaseScaleModifier;
	extern float creatureModBaseXPModifier;
	extern float creatureModBaseMeatAmountModifier;
	extern float creatureModBaseHideAmountModifier;
	extern float creatureModBaseBoneAmountModifier;
	extern float creatureModBaseMilkModifier;
	extern float creatureModBaseLevelModifier;
	extern float creatureModBaseChanceHitModifier;
	extern float creatureModBaseFerocityModifier;
	extern float creatureModBaseDamageMaxModifier;
	extern float creatureModBaseDamageMinModifier;
	extern float creatureModBaseHAMModifier;
	extern float creatureModBaseHAMMaxModifier;
	extern float creatureModBaseResistsModifier;
	extern bool creatureAllCreatureCanSpawnBabyEnabled;
	extern float creatureAllCreatureCanSpawnBabyChance;
	extern bool creatureBabyRandomDifficultyEnabled;
	extern int creatureBabySpawnChanceDestroyMissionLair;
	extern int creatureBabySpawnChanceDynamicSpawn;
	extern int creatureBabySpawnChanceDynamicLair;
	extern bool creatureShowRunSpeedEnabled;

//Creature Handler
	extern int creatureTamingMaxDistance;
	extern float creatureTamingCycleTime;
	extern bool creatureTrainingAlwaysSuccessfulEnabled;
	extern bool creatureUntrainCreatureMountEnabled;
	extern bool creatureSetDefaultPetCommandsEnabled;

//Dungeon
	extern float dungeonCorellianCorvetteMultiplier;
	extern float dungeonDeathWatchBunkerMultiplier;
	extern float dungeonGeonosianBioLabMultiplier;
	extern float dungeonWarrenMultiplier;

//Group
	extern int groupMaxSize;

//Faction
	extern int factionMaxRank;
	extern float factionCapMultiplier;

//Harvest
	extern int harvestDistance;
	extern bool harvestAreaEnabled;
	extern bool harvestAreaCommandOnlyEnabled;
	extern int harvestMultiplier;
	extern int harvestMilkTime;
	extern float harvestDNASampleDistance;
	extern bool harvestInCombatEnabled;
	extern int harvestMinimumHarvest;
	extern bool harvestMinimumHarvestEnabled;

//Jedi
	extern bool jediForceCostToTuneEnabled;
	extern int jediKnightRequirementNumberOfMasters;

//Loot
	extern int lootDistance;
	extern bool lootAreaEnabled;
	extern int lootCreditMultiplier;
	extern int lootAttachmentMax;
	extern int lootAttachmentMin;
	extern int lootAttachmentMaxLevel;
	extern bool lootAttachmentNameEnabled;
	extern int lootAttachmentModCount;
	extern int lootDropAttachmentModCount;
	extern bool lootCreditLuckModifier;
	extern int lootMaxLevel;
	extern int lootMinLevel;
	extern bool lootShowForceCostDecimalEnabled;
	extern bool lootRareColorCrystalsEnabled;
	extern bool lootGroupCreditsSplitEnabled;
	extern float lootChanceMultiplier;
	extern float lootResourceMultiplier;
	extern bool lootYellowModifierNameEnabled;
	extern std::string lootYellowModifierName;
	extern float lootLegendaryDamageModifier;
	extern float lootExceptionalDamageModifier;
	extern float lootYellowDamageModifier;
	extern float lootBaseDamageModifier;
	extern bool lootUseLootModifiersForDamageModifiersEnabled;
	extern float lootArmorMaxResists;
	extern bool lootNewLootQualityNamingEnabled;
	extern bool lootModifiersAffectLightsaberCrystalsEnabled;
	extern bool lootLevelToItemDescriptionEnabled;
	extern bool lootModifierToItemDescriptionEnabled;
	extern bool lootQualityToItemDescriptionEnabled;
	extern bool lootSocketsOnWearablesEnabled;
	extern bool lootSocketsOnWearableContainersEnabled;

//Mission
	extern int missionBountyExpirationTime;
	extern int missionExpirationTime;
	extern int missionMaxCount;
	extern int missionListCount;
	extern bool missionNameAndLevelEnabled;
	extern bool missionDirectionSelectionEnabled;
	extern bool missionLevelSelectionEnabled;
	extern int missionRewardMultiplier;
	extern bool missionRandomAttacksEnabled;
	extern bool missionSurveyMissionRewardsResourcesEnabled;
	extern float missionSurveyMissionRewardsResourcesMultiplier;
	extern bool missionSurveyMissionLimitToLessThanNinetyEnabled;
	extern bool missionSurveyMissionEnableMoreResourcesEnabled;
	extern float missionSurveyMissionCompletionDistance;

//Pet
	extern int petCallTime;
	extern int petGrowthCycleTime;
	extern int petGrowthStagesToGrown;
	extern bool petStoreInCombatEnabled;
	extern float petOutOfCombatHAMRegenMultiplier;
	extern bool petAllMountsUsedByAnyone;
	extern bool petCallInCombatEnabled;
	extern float petDamageMultiplier;
	extern bool petSpeedSameAsPlayerEnabled;
	
//Player
	extern int playerSamplingMultiplier;
	extern int playerSamplingTime;
	extern bool playerSamplingMiniGameEnabled;
	extern bool playerSamplingRadioactiveWarningEnabled;
	extern int playerMaxLots;
	extern bool playerGlobalSafetyDepositEnabled;
	extern float playerShuttleBoardingDistance;
	extern std::string playerStatMigrationLocation;
	extern bool playerStatMigrationSalonOnlyEnabled;
	extern bool playerStatMigrationAnyLocationEnabled;
	extern bool playerStatMigrationClearBuffsEnabled;
	extern int playerWoundsonDeath;
	extern bool playerBackpackWipeEnabled;
	extern bool playerChangeWearableColorsEnabled;
	extern bool playerOverwriteBuffEnabled;
	extern bool playerWoundHealingAnywhereEnabled;
	extern bool playerEnhanceHealingAnywhereEnabled;
	extern int playerWoundHealingMultiplier;
	extern int playerEnhanceHealingMultiplier;
	extern int playerDamageHealingMultiplier;
	extern bool playerInsureWeaponsEnabled;
	extern float playerMeditateHealingMultiplier;
	extern bool playerMeditateFatigueHealingEnabled;
	extern int playerMeditateFatigueHealingAmount;
	extern float playerHAMRegenSittingMultiplier;
	extern float playerHAMRegenKneelingMultiplier;
	extern float playerMaxArmorUnSliced;
	extern float playerMaxArmorSliced;
	extern bool playerJediForceRunToggleEnabled;
	extern bool playerEntertainerHealsAllWoundsEnabled;
	extern float playerEntertainerWoundHealMultiplier;
	extern bool playerEntertainerBuffDurationCustomEnabled;
	extern float playerEnterainerBuffDuration;
	extern bool playerEntertainerAllBuffsMusicOrDanceEnabled;
	extern bool playerEntertainerBuffSelfEnabled;
	extern bool playerEntertainerInstantBuffEnabled;
	extern bool playerEntertainerBuffAnywhereEnabled;
	extern float playerSpeedMultiplier;
	extern float playerMeditateTickTime;
	extern float playerJediForceMeditateMultiplier;
	extern int playerMaxLevelNonCHMount;
	extern bool playerSurveyExtendedDistanceEnabled;
	extern bool playerAttachmentSplittingEnabled;
	extern int playerAttachmentSplittingCostPerPoint;
	extern bool playerAttachmentApplicationModEnabled;
	extern bool playerPlayersOnlineAtLoginEnabled;
	extern float playerDefaultRunSpeed;
	extern bool playerBurstRunToggleEnabled;
	extern float playerBurstRunCoolDownTimer;
	extern float playerBurstRunDuration;
	extern float playerBurstRunHamCostPercent;
	extern float playerBurstRunSpeedAndAccelerationModifier;
	extern bool playerGallopToggleEnabled;
	extern float playerGallopDamagePercent;
	extern float playerBurstRunHamCost;
	extern bool playerClothingAttachmentSplittingEnabled;
	extern bool playerArmorAttachmentSplittingEnabled;
	extern bool playerWeaponAttachmentSplittingEnabled;

//Player Creation
	extern int playerCreationNewCreationTime;
	extern bool playerCreationAllLanguagesEnabled;
	extern bool playerCreationJoinGalaxyChatEnabled;
	extern bool playerCreationGrantAllNoviceSkillsEnabled;

//Player Payments
	extern bool playerPaymentCashAndBankEnabled;

//Player XP
	extern bool playerForagingXPEnabled;
	extern bool playerMilkingXPEnabled;
	extern bool playerAwardPetHealingXPEnabled;
	extern bool playerAwardSelfHealingXPEnabled;
	extern bool playerAwardXPWeaponSplitEnabled;
	extern float playerDNASamplingXPMultiplier;
	extern float playerBountyHunterXPMultiplier;
	extern float playerWildernessSurvivalXPMultiplier;
	extern float playerCombatXPMultiplier;
	extern float playerOnehandedWeaponsXPMultiplier;
	extern float playerPolearmWeaponsXPMultiplier;
	extern float playerTwohandedWeaponsXPMultiplier;
	extern float playerUnarmedCombatXPMultiplier;
	extern float playerCarbineWeaponsXPMultiplier;
	extern float playerHeavyWeaponsXPMultiplier;
	extern float playerPistolWeaponsXPMultiplier;
	extern float playerRifleWeaponsXPMultiplier;
	extern float playerBioEngineerCraftingXPMultiplier;
	extern float playerArmorCraftingXPMultiplier;
	extern float playerTailoringXPMultiplier;
	extern float playerDroidCraftingXPMultiplier;
	extern float playerFoodCraftingXPMultiplier;
	extern float playerGeneralCraftingXPMultiplier;
	extern float playerMedicineCraftingXPMultiplier;
	extern float playerSpiceCraftingXPMultiplier;
	extern float playerStructureCraftingXPMultiplier;
	extern float playerWeaponCraftingXPMultiplier;
	extern float playerCreatureHandlingXPMultiplier;
	extern float playerDancingXPMultiplier;
	extern float playerEntertainerHealingXPMultiplier;
	extern float playerImageDesignerXPMultiplier;
	extern float playerJediXPMultiplier;
	extern float playerMedicalXPMultiplier;
	extern float playerMerchantXPMultiplier;
	extern float playerMusicianXPMultiplier;
	extern float playerPoliticalXPMultiplier;
	extern float playerSurveyingXPMultiplier;
	extern float playerScoutingXPMultiplier;
	extern float playerShipwrightXPMultiplier;
	extern float playerSlicingXPMultiplier;
	extern float playerStarshipCombatXPMultiplier;
	extern float playerSquadLeadershipXPMultiplier;
	extern float playerTrappingXPMultiplier;
	extern int playerJediNegativeXPCap;
	extern bool playerJediAwardedCombatXPEnabled;
	extern bool playerJediPvEForceRankXPEnabled;
	extern float playerJediForceRankXPMultiplier;
	extern bool playerMeditateGrantsHealingXPEnabled;
	extern bool playerXPBasedOnLevelEnabled;
	extern bool playerCHXPModEnabled;
	extern bool playerCHCombatXPEnabled;

//Ranger
	extern int rangerAreaTrackDistance;
	extern float rangerAreaTrackCycleTime;
	extern bool rangerAreaTrackHighlightBabyEnabled;

//Resources
	extern bool resourcesAddNameEnabled;
	extern int resourcesMinimumQuality;
	extern int resourcesMaximumQuality;
	extern int resourcesContainerSize;
	extern int resourcesResourceDeedSize;
	
//Server
	extern float serverDrawDistance;

//Skills
	extern bool skillsInstantMasterPoliticianEnabled;
	extern bool skillsInstantMasterMerchantEnabled;

//Slicing
	extern bool slicingNewSliceEnabled;
	extern float slicingTerminalSliceCooldown;
	extern bool slicingArmorSliceSocketsEnabled;
	extern bool slicingArmorPierceSliceEnabled;
	extern bool slicingWeaponPierceSliceEnabled;

//Structure
	extern int structureMaxItemsPerLot;
	extern int structureMaxCivicBuildingItems;
	extern int structureMaxZeroLotBuildingItems;
	extern int structureMaxItemsPerStructure;
	extern bool structureMaxItemsEnabled;
	extern bool structureShowHouseMaxItemsEnabled;
	extern int structureBaseMaintenanceRateMultiplier;
	extern int structureBasePowerRateMultiplier;
	extern bool structureAllowAllZonesEnabled;
	extern int cityMaintenanceBaseMultiplier;
	extern int cityMaintenanceRateMultiplier;
	extern bool structureInstallationQuickAddMaintenanceEnabled;
	extern int structureInstallationQuickAddMaintenanceAmount;
	extern bool structureInstallationQuickAddPowerEnabled;
	extern int structureInstallationQuickAddPowerAmount;
	extern bool structureInstallationResourcesRetrieveAllEnabled;
	extern bool structureRemoveDestroyCodeEnabled;

//Vehicle
	extern int vehicleBaseDecayCycle;
	extern int vehicleBaseDecayRate;
	extern bool vehicleInitialDecayEnabled;
	extern int vehicleCallTime;
	extern bool vehicleStoreInCombatEnabled;
	extern bool vehicleShowVehicleSpeedEnabled;

//Vendor
	extern bool vendorLowMaintenanceEmailEnabled;
	extern int vendorLowMaintenanceEmailWarningThreshold;
	extern bool vendorSkimSalesForMaintenanceEnabled;
	extern float vendorSkimSalesForMaintenancePercent;

//Weapon
	extern int weaponDecayRateChance;
	extern int weaponDecayRateWithPowerUpChance;
	extern float weaponCrystalDamagePerTick;
	extern float weaponDamagePerTicket;
	
//Wearables
	extern bool wearablesFactionEnabled;
	extern bool wearablesAllPlayerRacesEnabled;
	
//Initializer
	bool loadConfigData();
	void stopConfigWatcher();
}

#endif /*GLOBALVARIABLES_H_*/
