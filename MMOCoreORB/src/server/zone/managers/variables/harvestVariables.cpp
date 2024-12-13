#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/harvestVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

HarvestVariables harvestVars;

HarvestVariables::HarvestVariables() : Logger("HarvestVariables") {}

HarvestVariables::~HarvestVariables() {}

void HarvestVariables::startHarvestVariables() {

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

bool HarvestVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/harvest_variables.lua";

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
		//Harvest 
		if (lua->getGlobalInt("harvestDistance") > 0) harvestVars.harvestDistance = lua->getGlobalInt("harvestDistance");
		if (lua->getGlobalBoolean("harvestAreaEnabled") == true || lua->getGlobalBoolean("harvestAreaEnabled") == false) harvestVars.harvestAreaEnabled = lua->getGlobalBoolean("harvestAreaEnabled");
		if (lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == true || lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled") == false) harvestVars.harvestAreaCommandOnlyEnabled = lua->getGlobalBoolean("harvestAreaCommandOnlyEnabled");
		if (lua->getGlobalFloat("harvestMultiplier") > 0) harvestVars.harvestMultiplier = lua->getGlobalFloat("harvestMultiplier");
		if (lua->getGlobalFloat("harvestMilkTime") >= 0) harvestVars.harvestMilkTime = lua->getGlobalFloat("harvestMilkTime");
		if (lua->getGlobalInt("harvestDNASampleDistance") > 0) harvestVars.harvestDNASampleDistance = lua->getGlobalInt("harvestDNASampleDistance");
		if (lua->getGlobalBoolean("harvestInCombatEnabled") == true || lua->getGlobalBoolean("harvestInCombatEnabled") == false) harvestVars.harvestInCombatEnabled = lua->getGlobalBoolean("harvestInCombatEnabled");
		if (lua->getGlobalInt("harvestMinimumHarvest") >= 0) harvestVars.harvestMinimumHarvest = lua->getGlobalInt("harvestMinimumHarvest");
		if (lua->getGlobalBoolean("harvestMinimumHarvestEnabled") == true || lua->getGlobalBoolean("harvestMinimumHarvestEnabled") == false) harvestVars.harvestMinimumHarvestEnabled = lua->getGlobalBoolean("harvestMinimumHarvestEnabled");
		if (lua->getGlobalBoolean("harvestCriticalEnabled") == true || lua->getGlobalBoolean("harvestCriticalEnabled") == false) harvestVars.harvestCriticalEnabled = lua->getGlobalBoolean("harvestCriticalEnabled");
		if (lua->getGlobalFloat("harvestCriticalMultiplier") > 0) harvestVars.harvestCriticalMultiplier = lua->getGlobalFloat("harvestCriticalMultiplier");
		if (lua->getGlobalFloat("harvestLegendaryCriticalMultiplier") > 0) harvestVars.harvestLegendaryCriticalMultiplier = lua->getGlobalFloat("harvestLegendaryCriticalMultiplier");
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

bool HarvestVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t HarvestVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void HarvestVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

