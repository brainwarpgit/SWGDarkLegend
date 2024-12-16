#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/structureVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

StructureVariables structureVars;

StructureVariables::StructureVariables() : Logger("StructureVariables") {}

StructureVariables::~StructureVariables() {}

void StructureVariables::startStructureVariables() {

	if (!loadConfigData()) {
		info(true) << "loadConfigData() FAILED";
		return;
	}
	std::thread reloadThread([this] { 
		startWatching(
			[this] {
				loadConfigData();
				}
			);
	});
	reloadThread.detach();

}

bool StructureVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/structure_variables.lua";

	bool initialLoad = false;
	
	if (!fileExists(luaFilePath)) {
		return 0;
	}

	time_t modifiedTime = getFileModifiedTime(luaFilePath);

	if (modifiedTime == lastModifiedTime) {
		return true;
	}

	if (lastModifiedTime == 0) {
		info(true) << "Initial Load of " << luaFilePath;
		initialLoad = true;
	} else {
		info(true) << "Reloading due to change in " << luaFilePath;
	}

	lastModifiedTime = modifiedTime;
	
	Lua* lua = new Lua();
	lua->init();

	if (!lua->runFile(luaFilePath.c_str())) {
		info(true) << "Failed to load file " << luaFilePath;
		delete lua;
		lua = nullptr;
		return false;
	}

	try {
		//Structure 
		if (lua->getGlobalInt("structureMaxItemsPerLot") > 0) structureVars.structureMaxItemsPerLot = lua->getGlobalInt("structureMaxItemsPerLot");
		if (lua->getGlobalInt("structureMaxCivicBuildingItems") >= 0) structureVars.structureMaxCivicBuildingItems = lua->getGlobalInt("structureMaxCivicBuildingItems");
		if (lua->getGlobalInt("structureMaxZeroLotBuildingItems") >= 0) structureVars.structureMaxZeroLotBuildingItems = lua->getGlobalInt("structureMaxZeroLotBuildingItems");
		if (lua->getGlobalInt("structureMaxItemsPerStructure") > 0) structureVars.structureMaxItemsPerStructure = lua->getGlobalInt("structureMaxItemsPerStructure");
		if (lua->getGlobalBoolean("structureMaxItemsEnabled") == true || lua->getGlobalBoolean("structureMaxItemsEnabled") == false) structureVars.structureMaxItemsEnabled = lua->getGlobalBoolean("structureMaxItemsEnabled");
		if (lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == true || lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled") == false) structureVars.structureShowHouseMaxItemsEnabled = lua->getGlobalBoolean("structureShowHouseMaxItemsEnabled");
		if (lua->getGlobalFloat("structureBaseMaintenanceRateMultiplier") >= 0) structureVars.structureBaseMaintenanceRateMultiplier = lua->getGlobalFloat("structureBaseMaintenanceRateMultiplier");
		if (lua->getGlobalFloat("structureBasePowerRateMultiplier") >= 0) structureVars.structureBasePowerRateMultiplier = lua->getGlobalFloat("structureBasePowerRateMultiplier");
		if (lua->getGlobalFloat("structureCityMaintenanceBaseMultiplier") >= 0) structureVars.structureCityMaintenanceBaseMultiplier = lua->getGlobalFloat("structureCityMaintenanceBaseMultiplier");
		if (lua->getGlobalFloat("structureCityMaintenanceRateMultiplier") >= 0) structureVars.structureCityMaintenanceRateMultiplier = lua->getGlobalFloat("structureCityMaintenanceRateMultiplier");
		if (lua->getGlobalBoolean("structureAllowAllZonesEnabled") == true || lua->getGlobalBoolean("structureAllowAllZonesEnabled") == false) structureVars.structureAllowAllZonesEnabled = lua->getGlobalBoolean("structureAllowAllZonesEnabled");
		if (lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled") == true || lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled") == false) structureVars.structureInstallationQuickAddMaintenanceEnabled = lua->getGlobalBoolean("structureInstallationQuickAddMaintenanceEnabled");
		if (lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount") > 0 && lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount") <= 100) structureVars.structureInstallationQuickAddMaintenanceAmount = lua->getGlobalInt("structureInstallationQuickAddMaintenanceAmount");
		if (lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled") == true || lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled") == false) structureVars.structureInstallationQuickAddPowerEnabled = lua->getGlobalBoolean("structureInstallationQuickAddPowerEnabled");
		if (lua->getGlobalInt("structureInstallationQuickAddPowerAmount") > 0 && lua->getGlobalInt("structureInstallationQuickAddPowerAmount") <= 100) structureVars.structureInstallationQuickAddPowerAmount = lua->getGlobalInt("structureInstallationQuickAddPowerAmount");
		if (lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled") == true || lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled") == false) structureVars.structureInstallationResourcesRetrieveAllEnabled = lua->getGlobalBoolean("structureInstallationResourcesRetrieveAllEnabled");
		if (lua->getGlobalBoolean("structureRemoveDestroyCodeEnabled") == true || lua->getGlobalBoolean("structureRemoveDestroyCodeEnabled") == false) structureVars.structureRemoveDestroyCodeEnabled = lua->getGlobalBoolean("structureRemoveDestroyCodeEnabled");
	} catch (const Exception& e) {
		info(true) << "Error retrieving LUA varaibles: " << e.what();
		return false;
	}

	if (initialLoad) {
		info(true) << "Initial Load Completed.";
	} else{
		info(true) << "Reload Completed.";
	}
	
	delete lua;
	lua = nullptr;

	return true;
}

bool StructureVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t StructureVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void StructureVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

