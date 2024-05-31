#include "globalVariables.h"
#include "engine/lua/Lua.h"

namespace globalVariables {

//Variables

//Faction
	int factionMaxRank = 15;

//Mission
	int missionBountyExpirationTime = 48;
	int missionExpirationTime = 48;
	int missionMaxCount = 2;
	int missionListCount = 6;
	bool missionNameAndLevelEnabled = false;
	bool missionDirectionSelectionEnabled = false;
	bool missionLevelSelectionEnabled = false;
	int missionRewardMultiplier = 1;

//Player
	int playerSamplingMultiplier = 1;
	int playerSamplingTime = 25;
	bool playerSamplingMiniGameEnabled = true;
	bool playerSamplingRadioactiveWarningEnabled = true;
	
//Player Creation
	int playerCreationNewCreationTime = 60;
	bool playerCreationAllLanguagesEnabled = false;

//Resources
	bool resourcesAddNameEnabled = false;
	int resourcesMinimumQuality = 0;
	int resourcesMaximumQuality = 1000;
	int resourcesContainerSize = 100000;

//Initializer
	bool loadConfigData() {
	    	Lua* lua = new Lua();
		lua->init();			
		if (!lua->runFile("scripts/managers/global_variables.lua")) {
			delete lua;
			return false;
		}
		try {
			//Faction
			if (lua->getGlobalInt("factionMaxRank") > 0 && lua->getGlobalInt("factionMaxRank") <= 21) factionMaxRank = lua->getGlobalInt("factionMaxRank");

			//Mission
			if (lua->getGlobalInt("missionBountyExpirationTime") > 0) missionBountyExpirationTime = lua->getGlobalInt("missionBountyExpirationTime");
			if (lua->getGlobalInt("missionExpirationTime") > 0) missionExpirationTime = lua->getGlobalInt("missionExpirationTime");
			if (lua->getGlobalInt("missionMaxCount") > 0) missionMaxCount = lua->getGlobalInt("missionMaxCount");
			if (lua->getGlobalInt("missionListCount") > 0) missionListCount = lua->getGlobalInt("missionListCount");
			if (lua->getGlobalBoolean("missionNameAndLevelEnabled") == true || lua->getGlobalBoolean("missionNameAndLevelEnabled") == false) missionNameAndLevelEnabled = lua->getGlobalBoolean("missionNameAndLevelEnabled");
			if (lua->getGlobalBoolean("missionDirectionSelectionEnabled") == true || lua->getGlobalBoolean("missionDirectionSelectionEnabled") == false) missionDirectionSelectionEnabled = lua->getGlobalBoolean("missionDirectionSelectionEnabled");
			if (lua->getGlobalBoolean("missionLevelSelectionEnabled") == true || lua->getGlobalBoolean("missionLevelSelectionEnabled") == false) missionLevelSelectionEnabled = lua->getGlobalBoolean("missionLevelSelectionEnabled");
			if (lua->getGlobalInt("missionRewardMultiplier") > 0) missionRewardMultiplier = lua->getGlobalInt("missionRewardMultiplier");

			//Player
			if (lua->getGlobalInt("playerSamplingMultiplier") > 0) playerSamplingMultiplier = lua->getGlobalInt("playerSamplingMultiplier");
			if (lua->getGlobalInt("playerSamplingTime") > 0) playerSamplingTime = lua->getGlobalInt("playerSamplingTime");
			if (lua->getGlobalBoolean("playerSamplingMiniGameEnabled") == true || lua->getGlobalBoolean("playerSamplingMiniGameEnabled") == false) playerSamplingMiniGameEnabled = lua->getGlobalBoolean("playerSamplingMiniGameEnabled");
			if (lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled") == true || lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled") == false) playerSamplingRadioactiveWarningEnabled = lua->getGlobalBoolean("playerSamplingRadioactiveWarningEnabled");

			//Resources
			if (lua->getGlobalBoolean("resourcesAddNameEnabled") == true || lua->getGlobalBoolean("resourcesAddNameEnabled") == false) resourcesAddNameEnabled = lua->getGlobalBoolean("resourcesAddNameEnabled");
			if (lua->getGlobalInt("resourcesMinimumQuality") > 0) resourcesMinimumQuality = lua->getGlobalInt("resourcesMinimumQuality");
			if (lua->getGlobalInt("resourcesMaximumQuality") > 0) resourcesMaximumQuality = lua->getGlobalInt("resourcesMaximumQuality");
			if (lua->getGlobalInt("resourcesContainerSize") > 0) resourcesContainerSize = lua->getGlobalInt("resourcesContainerSize");

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
