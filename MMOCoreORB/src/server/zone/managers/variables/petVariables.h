#ifndef PETVARIABLES_H_
#define PETVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PetVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PetVariables();
	~PetVariables();
	void startPetVariables();
	//Pet
	float petCallTime{15};
	float petGrowthCycleTime{720};
	int petGrowthStagesToGrown{10};
	bool petStoreInCombatEnabled{false};
	float petOutOfCombatHAMRegenMultiplier{1};
	bool petAllMountsUsedByAnyone{false};
	bool petCallInCombatEnabled{false};
	float petDamageMultiplier{1};
	bool petSpeedSameAsPlayerEnabled{false};
	bool petGallopToggleEnabled{false};
	float petGallopDamagePercent{0};
};

extern PetVariables petVars;

#endif /*PETVARIABLES_H_*/
