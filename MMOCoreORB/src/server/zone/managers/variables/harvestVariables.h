#ifndef HARVESTVARIABLES_H_
#define HARVESTVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class HarvestVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	HarvestVariables();
	~HarvestVariables();
	void startHarvestVariables();
};

extern HarvestVariables harvestVars;

#endif /*HARVESTVARIABLES_H_*/
