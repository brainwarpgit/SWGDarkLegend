#include "globalVariables.h"
#include "engine/lua/Lua.h"

namespace globalVariables {

//Variables

//Crafting
	int craftingFactoryCrateMaxSize = 100;
	int craftingFactoryRunTimeMultiplier = 8;
	int craftingToolCraftTimeMultiplier = 2;

//Faction
	int factionMaxRank = 15;

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

//Player Creation
	int playerCreationNewCreationTime = 60;
	bool playerCreationAllLanguagesEnabled = false;

//Resources
	bool resourcesAddNameEnabled = false;
	int resourcesMinimumQuality = 0;
	int resourcesMaximumQuality = 1000;
	int resourcesContainerSize = 100000;

//Skills
	bool skillsInstantMasterPoliticianEnabled = false;
	bool skillsInstantMasterMerchantEnabled = false;

//Structure
	int structureMaxItemsPerLot = 100;
	int structureMaxCivicBuildingItems = 250;
	int structureMaxZeroLotBuildingItems = 400;
	int structureMaxItemsPerStructure = 400;
	bool structureMaxItemsEnabled = true;
	bool structureShowHouseMaxItemsEnabled = false;

//Vehicle
	int vehicleBaseDecayCycle = 600;
	int vehicleBaseDecayRate = 15;
	bool vehicleInitialDecayEnabled = true;
	int vehicleCallTime = 15;
	bool vehicleStoreInCombatEnabled = false;

//Initializer
	bool loadConfigData() {
	    	Lua* lua = new Lua();
		lua->init();			
		if (!lua->runFile("scripts/managers/global_variables.lua")) {
			delete lua;
			return false;
		}
		try {
			//Crafting
			if (lua->getGlobalInt("craftingFactoryCrateMaxSize") > 0) craftingFactoryCrateMaxSize = lua->getGlobalInt("craftingFactoryCrateMaxSize");
			if (lua->getGlobalInt("craftingFactoryRunTimeMultiplier") >= 0) craftingFactoryRunTimeMultiplier = lua->getGlobalInt("craftingFactoryRunTimeMultiplier");
			if (lua->getGlobalInt("craftingToolCraftTimeMultiplier") >= 0) craftingToolCraftTimeMultiplier = lua->getGlobalInt("craftingToolCraftTimeMultiplier");
			
			//Faction
			if (lua->getGlobalInt("factionMaxRank") > 0 && lua->getGlobalInt("factionMaxRank") <= 21) factionMaxRank = lua->getGlobalInt("factionMaxRank");

			//Harvest
			if (lua->getGlobalInt("harvestDistance") > 0) harvestDistance = lua->getGlobalInt("harvestDistance");
			if (lua->getGlobalBoolean("harvestAreaEnabled") == true || lua->getGlobalBoolean("harvestAreaEnabled") == false) harvestAreaEnabled = lua->getGlobalBoolean("harvestAreaEnabled");
			if (lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == true || lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == false) harvestAreaCommandOnlyEnabled = lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled");
			if (lua->getGlobalInt("harvestMultiplier") > 0) harvestMultiplier = lua->getGlobalInt("harvestMultiplier");
			if (lua->getGlobalInt("harvestMilkTime") > 0) harvestMilkTime = lua->getGlobalInt("harvestMilkTime");
			if (lua->getGlobalFloat("harvestDNASampleDistance") > 0) harvestDNASampleDistance = lua->getGlobalFloat("harvestDNASampleDistance");

			//Loot
			if (lua->getGlobalInt("lootDistance") > 0) lootDistance = lua->getGlobalInt("lootDistance");
			if (lua->getGlobalBoolean("lootAreaEnabled") == true || lua->getGlobalBoolean("lootAreaEnabled") == false) lootAreaEnabled = lua->getGlobalBoolean("lootAreaEnabled");
			if (lua->getGlobalInt("lootCreditMultiplier") > 0) lootCreditMultiplier = lua->getGlobalInt("lootCreditMultiplier");
			
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
			if (lua->getGlobalInt("petGrowthStagesToGrown") > 0) petGrowthStagesToGrown = lua->getGlobalInt("petGrowthStagesToGrown");
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
			
			//Resources
			if (lua->getGlobalBoolean("resourcesAddNameEnabled") == true || lua->getGlobalBoolean("resourcesAddNameEnabled") == false) resourcesAddNameEnabled = lua->getGlobalBoolean("resourcesAddNameEnabled");
			if (lua->getGlobalInt("resourcesMinimumQuality") >= 0 && lua->getGlobalInt("resourcesMinimumQuality") <= lua->getGlobalInt("resourcesMaximumQuality")) resourcesMinimumQuality = lua->getGlobalInt("resourcesMinimumQuality");
			if (lua->getGlobalInt("resourcesMaximumQuality") <= 1000 && lua->getGlobalInt("resourcesMaximumQuality") >= lua->getGlobalInt("resourcesMinimumQuality")) resourcesMaximumQuality = lua->getGlobalInt("resourcesMaximumQuality");
			if (lua->getGlobalInt("resourcesContainerSize") > 0) resourcesContainerSize = lua->getGlobalInt("resourcesContainerSize");
			
			//Skills
			if (lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled") == true || lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled") == false) skillsInstantMasterPoliticianEnabled = lua->getGlobalBoolean("skillsInstantMasterPoliticianEnabled");
			if (lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled") == true || lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled") == false) skillsInstantMasterMerchantEnabled = lua->getGlobalBoolean("skillsInstantMasterMerchantEnabled");
			
			//Structure
			if (lua->getGlobalInt("structureMaxItemsPerLot") > 0) structureMaxItemsPerLot = lua->getGlobalInt("structureMaxItemsPerLot");
			if (lua->getGlobalInt("structureMaxCivicBuildingItems") >= 0) structureMaxCivicBuildingItems = lua->getGlobalInt("structureMaxCivicBuildingItems");
			if (lua->getGlobalInt("structureMaxZeroLotBuildingItems") >= 0) structureMaxZeroLotBuildingItems = lua->getGlobalInt("structureMaxZeroLotBuildingItems");
			if (lua->getGlobalInt("structureMaxItemsPerStructure") > 0) structureMaxItemsPerStructure = lua->getGlobalInt("structureMaxItemsPerStructure");
			if (lua->getGlobalBoolean("structureMaxItemsEnabled") == true || lua->getGlobalBoolean("structureMaxItemsEnabled") == false) structureMaxItemsEnabled = lua->getGlobalBoolean("structureMaxItemsEnabled");
			if (lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == true || lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == false) structureShowHouseMaxItemsEnabled = lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled");

			//Vehicle
			if (lua->getGlobalInt("vehicleBaseDecayCycle") >= 0) vehicleBaseDecayCycle = lua->getGlobalInt("vehicleBaseDecayCycle");
			if (lua->getGlobalInt("vehicleBaseDecayRate") >= 0) vehicleBaseDecayRate = lua->getGlobalInt("vehicleBaseDecayRate");
			if (lua->getGlobalBoolean("vehicleInitialDecayEnabled") == true || lua->getGlobalBoolean("vehicleInitialDecayEnabled") == false) vehicleInitialDecayEnabled = lua->getGlobalBoolean("vehicleInitialDecayEnabled");
			if (lua->getGlobalInt("vehicleCallTime") >= 0) vehicleCallTime = lua->getGlobalInt("vehicleCallTime");
			if (lua->getGlobalBoolean("vehicleStoreInCombatEnabled") == true || lua->getGlobalBoolean("vehicleStoreInCombatEnabled") == false) vehicleStoreInCombatEnabled = lua->getGlobalBoolean("vehicleStoreInCombatEnabled");

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
