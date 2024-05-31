#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

#include <string>

namespace globalVariables {

//Variables

//Player
	extern int playerSamplingMultiplier;
	extern int playerSamplingTime;
	extern bool playerSamplingMiniGameEnabled;
	extern bool playerSamplingRadioactiveWarningEnabled;

//Resources
	extern bool resourcesAddNameEnabled;
	extern int resourcesMinimumQuality;
	extern int resourcesMaximumQuality;
	extern int resourcesContainerSize;

//Initializer
	bool loadConfigData();
}

#endif /*GLOBALVARIABLES_H_*/
