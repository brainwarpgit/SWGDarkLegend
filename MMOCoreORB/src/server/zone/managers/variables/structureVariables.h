#ifndef STRUCTUREVARIABLES_H_
#define STRUCTUREVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class StructureVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	StructureVariables();
	~StructureVariables();
	void startStructureVariables();
	//Structure
	int structureMaxItemsPerLot{100};
	int structureMaxCivicBuildingItems{250};
	int structureMaxZeroLotBuildingItems{400};
	int structureMaxItemsPerStructure{400};
	bool structureMaxItemsEnabled{true};
	bool structureShowHouseMaxItemsEnabled{false};
	float structureBaseMaintenanceRateMultiplier{1};
	float structureBasePowerRateMultiplier{1};
	bool structureAllowAllZonesEnabled{false};
	float structureCityMaintenanceBaseMultiplier{1};
	float structureCityMaintenanceRateMultiplier{1};
	bool structureInstallationQuickAddMaintenanceEnabled{false};
	int structureInstallationQuickAddMaintenanceAmount{10};
	bool structureInstallationQuickAddPowerEnabled{false};
	int structureInstallationQuickAddPowerAmount{10};
	bool structureInstallationResourcesRetrieveAllEnabled{false};
	bool structureRemoveDestroyCodeEnabled{false};
};

extern StructureVariables structureVars;

#endif /*STRUCTUREVARIABLES_H_*/
