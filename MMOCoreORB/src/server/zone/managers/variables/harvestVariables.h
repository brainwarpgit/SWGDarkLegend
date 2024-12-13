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
	//Harvest
	int harvestDistance{10};
	bool harvestAreaEnabled{false};
	bool harvestAreaCommandOnlyEnabled{false};
	float harvestMultiplier{1};
	float harvestMilkTime{10};
	int harvestDNASampleDistance{16};
	bool harvestInCombatEnabled{false};
	int harvestMinimumHarvest{2};
	bool harvestMinimumHarvestEnabled{false};
	bool harvestCriticalEnabled{false};
	float harvestCriticalMultiplier{1.0};
	float harvestLegendaryCriticalMultiplier{1.0};
};

extern HarvestVariables harvestVars;

#endif /*HARVESTVARIABLES_H_*/
