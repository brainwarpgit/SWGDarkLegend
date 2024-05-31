#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <string>

namespace globalVariables {

//Variables

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

//Player
	extern int playerSamplingMultiplier;
	extern int playerSamplingTime;
	extern bool playerSamplingMiniGameEnabled;
	extern bool playerSamplingRadioactiveWarningEnabled;

//Player Creation
	extern int playerCreationNewCreationTime;
	extern bool playerCreationAllLanguagesEnabled;

//Resources
	extern bool resourcesAddNameEnabled;
	extern int resourcesMinimumQuality;
	extern int resourcesMaximumQuality;
	extern int resourcesContainerSize;

//Initializer
	bool loadConfigData();
}

#endif /*GLOBALVARIABLES_H_*/
