#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <string>

namespace globalVariables {

//Variables

//Crafting
	extern int craftingFactoryCrateMaxSize;
	extern int craftingFactoryRunTimeMultiplier;
	extern int craftingToolCraftTimeMultiplier;

//Faction
	extern int factionMaxRank;

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

//Player Creation
	extern int playerCreationNewCreationTime;
	extern bool playerCreationAllLanguagesEnabled;

//Resources
	extern bool resourcesAddNameEnabled;
	extern int resourcesMinimumQuality;
	extern int resourcesMaximumQuality;
	extern int resourcesContainerSize;

//Skills
	extern bool skillsInstantMasterPoliticianEnabled;
	extern bool skillsInstantMasterMerchantEnabled;

//Structure
	extern int structureMaxItemsPerLot;
	extern int structureMaxCivicBuildingItems;
	extern int structureMaxZeroLotBuildingItems;
	extern int structureMaxItemsPerStructure;
	extern bool structureMaxItemsEnabled;
	extern bool structureShowHouseMaxItemsEnabled;

//Vehicle
	extern int vehicleBaseDecayCycle;
	extern int vehicleBaseDecayRate;
	extern bool vehicleInitialDecayEnabled;
	extern int vehicleCallTime;
	extern bool vehicleStoreInCombatEnabled;

//Initializer
	bool loadConfigData();
}

#endif /*GLOBALVARIABLES_H_*/
