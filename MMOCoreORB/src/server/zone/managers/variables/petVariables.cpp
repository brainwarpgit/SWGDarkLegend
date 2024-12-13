#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/petVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

PetVariables petVars;

PetVariables::PetVariables() : Logger("PetVariables") {}

PetVariables::~PetVariables() {}

void PetVariables::startPetVariables() {

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

bool PetVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/pet_variables.lua";

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
		//Pet 
		if (lua->getGlobalInt("petCallTime") >= 0) petVars.petCallTime = lua->getGlobalInt("petCallTime");
		if (lua->getGlobalInt("petGrowthCycleTime") > 0) petVars.petGrowthCycleTime = lua->getGlobalInt("petGrowthCycleTime");
		if (lua->getGlobalInt("petGrowthStagesToGrown") > 0) petVars.petGrowthStagesToGrown = lua->getGlobalInt("petGrowthStagesToGrown");
		if (lua->getGlobalBoolean("petStoreInCombatEnabled") == true || lua->getGlobalBoolean("petStoreInCombatEnabled") == false) petVars.petStoreInCombatEnabled = lua->getGlobalBoolean("petStoreInCombatEnabled");
		if (lua->getGlobalFloat("petOutOfCombatHAMRegenMultiplier") > 0) petVars.petOutOfCombatHAMRegenMultiplier = lua->getGlobalFloat("petOutOfCombatHAMRegenMultiplier");
		if (lua->getGlobalBoolean("petAllMountsUsedByAnyone") == true || lua->getGlobalBoolean("petAllMountsUsedByAnyone") == false) petVars.petAllMountsUsedByAnyone = lua->getGlobalBoolean("petAllMountsUsedByAnyone");
		if (lua->getGlobalBoolean("petCallInCombatEnabled") == true || lua->getGlobalBoolean("petCallInCombatEnabled") == false) petVars.petCallInCombatEnabled = lua->getGlobalBoolean("petCallInCombatEnabled");
		if (lua->getGlobalFloat("petDamageMultiplier") > 0) petVars.petDamageMultiplier = lua->getGlobalFloat("petDamageMultiplier");
		if (lua->getGlobalBoolean("petSpeedSameAspetEnabled") == true || lua->getGlobalBoolean("petSpeedSameAspetEnabled") == false) petVars.petSpeedSameAsPlayerEnabled = lua->getGlobalBoolean("petSpeedSameAspetEnabled");
		if (lua->getGlobalBoolean("petGallopToggleEnabled") == true || lua->getGlobalBoolean("petGallopToggleEnabled") == false) petVars.petGallopToggleEnabled = lua->getGlobalBoolean("petGallopToggleEnabled");
		if (lua->getGlobalFloat("petGallopDamagePercent") >= 0 && lua->getGlobalFloat("petGallopDamagePercent") <= 100) petVars.petGallopDamagePercent = lua->getGlobalFloat("petGallopDamagePercent");
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

bool PetVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t PetVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void PetVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

