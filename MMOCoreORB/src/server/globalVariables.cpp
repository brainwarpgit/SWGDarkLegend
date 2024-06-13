#include "globalVariables.h"
#include "engine/lua/Lua.h"

namespace globalVariables {

//Variables

//Auction
	int auctionMaxBazaarPrice = 20000;
	int auctionMaxSales = 25;
	int auctionMaxSalesFee = 20;
	int auctionVendorExpirePeriod = 30;
	int auctionCommodityExpirePeriod = 7;

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

//Creature
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

//Loot
	int lootDistance = 16;
	bool lootAreaEnabled = false;
	int lootCreditMultiplier = 1;
	int lootAttachmentMax = 25;
	int lootAttachmentMin = 1;
	int lootAttachmentMaxLevel = 250;
	bool lootAttachmentNameEnabled = false;
	int lootAttachmentModCount = 2;
	bool lootCreditLuckModifier = false;
	int lootMaxLevel = 300;
	int lootMinLevel = 1;
	bool lootShowForceCostDecimalEnabled = false;
	bool lootRareColorCrystalsEnabled = false;
	bool lootGroupCreditsSplitEnabled = true;
	
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
	float playerEntertainerWoundHealMultiplier = false;
	bool playerEntertainerBuffDurationCustomEnabled = false;
	float playerEnterainerBuffDuration = 1;
	bool playerEntertainerAllBuffsMusicOrDanceEnabled = false;
	bool playerEntertainerBuffSelfEnabled = false;
	bool playerEntertainerInstantBuffEnabled = false;
	bool playerEntertainerBuffAnywhereEnabled = false;

//Player Creation
	int playerCreationNewCreationTime = 60;
	bool playerCreationAllLanguagesEnabled = false;
	bool playerCreationJoinGalaxyChatEnabled = false;

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
	float playerCombatXPMultiplier = 1;
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
	float playerForceRankXPMultiplier = 1;
	float playerImageDesignerXPMultiplier = 1;
	float playerJediXPMultiplier = 1;
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

			//Creature
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
			if (lua->getGlobalFloat("creatureKineticMaxResists") >= 0) creatureKineticMaxResists = lua->getGlobalFloat("creatureKineticMaxResists");
			if (lua->getGlobalFloat("creatureEnergyMaxResists") >= 0) creatureEnergyMaxResists = lua->getGlobalFloat("creatureEnergyMaxResists");
			if (lua->getGlobalFloat("creatureBlastMaxResists") >= 0) creatureBlastMaxResists = lua->getGlobalFloat("creatureBlastMaxResists");
			if (lua->getGlobalFloat("creatureHeatMaxResists") >= 0) creatureHeatMaxResists = lua->getGlobalFloat("creatureHeatMaxResists");
			if (lua->getGlobalFloat("creatureColdMaxResists") >= 0) creatureColdMaxResists = lua->getGlobalFloat("creatureColdMaxResists");
			if (lua->getGlobalFloat("creatureElectricityMaxResists") >= 0) creatureElectricityMaxResists = lua->getGlobalFloat("creatureElectricityMaxResists");
			if (lua->getGlobalFloat("creatureAcidMaxResists") >= 0) creatureAcidMaxResists = lua->getGlobalFloat("creatureAcidMaxResists");
			if (lua->getGlobalFloat("creatureStunMaxResists") >= 0) creatureStunMaxResists = lua->getGlobalFloat("creatureStunMaxResists");
			if (lua->getGlobalFloat("creatureLightsaberMaxResists") >= 0) creatureLightsaberMaxResists = lua->getGlobalFloat("creatureLightsaberMaxResists");
			if (lua->getGlobalFloat("creatureWildSpawnDensity") >= 0) creatureWildSpawnDensity = lua->getGlobalFloat("creatureWildSpawnDensity");

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

			//Loot
			if (lua->getGlobalInt("lootDistance") > 0) lootDistance = lua->getGlobalInt("lootDistance");
			if (lua->getGlobalBoolean("lootAreaEnabled") == true || lua->getGlobalBoolean("lootAreaEnabled") == false) lootAreaEnabled = lua->getGlobalBoolean("lootAreaEnabled");
			if (lua->getGlobalInt("lootCreditMultiplier") > 0) lootCreditMultiplier = lua->getGlobalInt("lootCreditMultiplier");
			if (lua->getGlobalInt("lootAttachmentMax") > 0) lootAttachmentMax = lua->getGlobalInt("lootAttachmentMax");
			if (lua->getGlobalInt("lootAttachmentMin") > 0) lootAttachmentMin = lua->getGlobalInt("lootAttachmentMin");
			if (lua->getGlobalInt("lootAttachmentMaxLevel") > 0 && lua->getGlobalInt("lootAttachmentMaxLevel") <= 336) lootAttachmentMaxLevel = lua->getGlobalInt("lootAttachmentMaxLevel");
			if (lua->getGlobalInt("lootAttachmentModCount") > 0) lootAttachmentModCount = lua->getGlobalInt("lootAttachmentModCount");
			if (lua->getGlobalBoolean("lootAttachmentNameEnabled") == true || lua->getGlobalBoolean("lootAttachmentNameEnabled") == false) lootAttachmentNameEnabled = lua->getGlobalBoolean("lootAttachmentNameEnabled");
			if (lua->getGlobalBoolean("lootCreditLuckModifier") == true || lua->getGlobalBoolean("lootCreditLuckModifier") == false) lootCreditLuckModifier = lua->getGlobalBoolean("lootCreditLuckModifier");
			if (lua->getGlobalInt("lootMaxLevel") > 0 && lua->getGlobalInt("lootMaxLevel") <= 450 && lua->getGlobalInt("lootMaxLevel") > lua->getGlobalInt("lootMinLevel")) lootMaxLevel = lua->getGlobalInt("lootMaxLevel");
			if (lua->getGlobalInt("lootMinLevel") > 0 && lua->getGlobalInt("lootMinLevel") < lua->getGlobalInt("lootMaxLevel")) lootMaxLevel = lua->getGlobalInt("lootMaxLevel");
			if (lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == true || lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == false) lootShowForceCostDecimalEnabled = lua->getGlobalBoolean("lootShowForceCostDecimalEnabled");
			if (lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == true || lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == false) lootRareColorCrystalsEnabled = lua->getGlobalBoolean("lootRareColorCrystalsEnabled");
			if (lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == true || lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == false) lootGroupCreditsSplitEnabled = lua->getGlobalBoolean("lootGroupCreditsSplitEnabled");

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
			if (lua->getGlobalInt("petGrowthCycleTime") >= 0) petGrowthCycleTime = lua->getGlobalInt("petGrowthCycleTime");
			if (lua->getGlobalInt("petGrowthStagesToGrown") >= 0) petGrowthStagesToGrown = lua->getGlobalInt("petGrowthStagesToGrown");
			if (lua->getGlobalBoolean("petStoreInCombatEnabled") == true || lua->getGlobalBoolean("petStoreInCombatEnabled") == false) petStoreInCombatEnabled = lua->getGlobalBoolean("petStoreInCombatEnabled");

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
			
			//Player Creation 
			if (lua->getGlobalInt("playerCreationNewCreationTime") >= 0) playerCreationNewCreationTime = lua->getGlobalInt("playerCreationNewCreationTime");
			if (lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == true || lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == false) playerCreationAllLanguagesEnabled = lua->getGlobalBoolean("playerCreationAllLanguagesEnabled");
			if (lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == true || lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == false) playerCreationJoinGalaxyChatEnabled = lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled");

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
			if (lua->getGlobalFloat("playerForceRankXPMultiplier") > 0) playerForceRankXPMultiplier = lua->getGlobalFloat("playerForceRankXPMultiplier");
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
