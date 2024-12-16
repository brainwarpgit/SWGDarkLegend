#ifndef MOUNTVARIABLES_H_
#define MOUNTVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class MountVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	MountVariables();
	~MountVariables();
	void startMountVariables();
	//Pet
	float mountPetCallTime{15};
	float mountPetGrowthCycleTime{720};
	int mountPetGrowthStagesToGrown{10};
	bool mountPetStoreInCombatEnabled{false};
	float mountPetOutOfCombatHAMRegenMultiplier{1};
	bool mountPetAllMountsUsedByAnyone{false};
	bool mountPetCallInCombatEnabled{false};
	float mountPetDamageMultiplier{1};
	bool mountPetSpeedSameAsPlayerEnabled{false};
	bool mountPetGallopToggleEnabled{false};
	float mountPetGallopDamagePercent{0};

	//Vehicle
	int mountVehicleBaseDecayCycle{600};
	int mountVehicleBaseDecayRate{15};
	bool mountVehicleInitialDecayEnabled{true};
	int mountVehicleCallTime{15};
	bool mountVehicleStoreInCombatEnabled{false};
	bool mountVehicleShowVehicleSpeedEnabled{false};
};

extern MountVariables mountVars;

#endif /*MOUNTVARIABLES_H_*/
