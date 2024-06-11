#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <string>

namespace globalVariables {

//Variables

//Auction
	extern int auctionMaxBazaarPrice;
	extern int auctionMaxSales;
	extern int auctionMaxSalesFee;
	extern int auctionVendorExpirePeriod;
	extern int auctionCommodityExpirePeriod;

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

// Creature
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
	extern bool playerMeditateFatigueHealingEnabled;
	extern int playerMeditateFatigueHealingAmount;

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

//Loot
	extern int lootDistance;
	extern bool lootAreaEnabled;
	extern int lootCreditMultiplier;
	extern int lootAttachmentMax;
	extern int lootAttachmentMin;
	extern int lootAttachmentMaxLevel;
	extern bool lootAttachmentNameEnabled;
	extern int lootAttachmentModCount;
	extern bool lootCreditLuckModifier;
	extern int lootMaxLevel;
	extern int lootMinLevel;
	extern bool lootShowForceCostDecimalEnabled;
	extern bool lootRareColorCrystalsEnabled;
	extern bool lootGroupCreditsSplitEnabled;

//Mission
	extern int missionBountyExpirationTime;
	extern int missionExpirationTime;
	extern int missionMaxCount;
	extern int missionListCount;
	extern bool missionNameAndLevelEnabled;
	extern bool missionDirectionSelectionEnabled;
	extern bool missionLevelSelectionEnabled;
	extern int missionRewardMultiplier;

//Pet
	extern int petCallTime;
	extern int petGrowthCycleTime;
	extern int petGrowthStagesToGrown;
	extern bool petStoreInCombatEnabled;

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

//Player Creation
	extern int playerCreationNewCreationTime;
	extern bool playerCreationAllLanguagesEnabled;
	extern bool playerCreationJoinGalaxyChatEnabled;

//Player Payments
	extern bool playerPaymentCashAndBankEnabled;

//Player XP
	extern bool playerForagingXPEnabled;
	extern bool playerMilkingXPEnabled;
	extern bool playerAwardPetHealingXPEnabled;
	extern bool playerAwardSelfHealingXPEnabled;
	extern bool playerAwardXPWeaponSplitEnabled;

//Resources
	extern bool resourcesAddNameEnabled;
	extern int resourcesMinimumQuality;
	extern int resourcesMaximumQuality;
	extern int resourcesContainerSize;

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

//Vehicle
	extern int vehicleBaseDecayCycle;
	extern int vehicleBaseDecayRate;
	extern bool vehicleInitialDecayEnabled;
	extern int vehicleCallTime;
	extern bool vehicleStoreInCombatEnabled;

//Vendor
	extern bool vendorLowMaintenanceEmailEnabled;
	extern int vendorLowMaintenanceEmailWarningThreshold;
	extern bool vendorSkimSalesForMaintenanceEnabled;
	extern float vendorSkimSalesForMaintenancePercent;

//Wearables
	extern bool wearablesFactionEnabled;
	extern bool wearablesAllPlayerRacesEnabled;

//Initializer
	bool loadConfigData();
}

#endif /*GLOBALVARIABLES_H_*/
