#ifndef WEARABLEVARIABLES_H_
#define WEARABLEVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class WearableVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	WearableVariables();
	~WearableVariables();
	void startWearableVariables();
};

extern WearableVariables wearableVars;

#endif /*WEARABLEVARIABLES_H_*/
