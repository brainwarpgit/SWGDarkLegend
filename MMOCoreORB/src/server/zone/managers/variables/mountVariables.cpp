#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/mountVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

MountVariables mountVars;

MountVariables::MountVariables() : Logger("MountVariables") {}

MountVariables::~MountVariables() {}

void MountVariables::startMountVariables() {

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

bool MountVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/mount_variables.lua";

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
		if (lua->getGlobalInt("mountPetCallTime") >= 0) mountVars.mountPetCallTime = lua->getGlobalInt("mountPetCallTime");
		if (lua->getGlobalInt("mountPetGrowthCycleTime") > 0) mountVars.mountPetGrowthCycleTime = lua->getGlobalInt("mountPetGrowthCycleTime");
		if (lua->getGlobalInt("mountPetGrowthStagesToGrown") > 0) mountVars.mountPetGrowthStagesToGrown = lua->getGlobalInt("mountPetGrowthStagesToGrown");
		if (lua->getGlobalBoolean("mountPetStoreInCombatEnabled") == true || lua->getGlobalBoolean("mountPetStoreInCombatEnabled") == false) mountVars.mountPetStoreInCombatEnabled = lua->getGlobalBoolean("mountPetStoreInCombatEnabled");
		if (lua->getGlobalFloat("mountPetOutOfCombatHAMRegenMultiplier") > 0) mountVars.mountPetOutOfCombatHAMRegenMultiplier = lua->getGlobalFloat("mountPetOutOfCombatHAMRegenMultiplier");
		if (lua->getGlobalBoolean("mountPetAllMountsUsedByAnyone") == true || lua->getGlobalBoolean("mountPetAllMountsUsedByAnyone") == false) mountVars.mountPetAllMountsUsedByAnyone = lua->getGlobalBoolean("mountPetAllMountsUsedByAnyone");
		if (lua->getGlobalBoolean("mountPetCallInCombatEnabled") == true || lua->getGlobalBoolean("mountPetCallInCombatEnabled") == false) mountVars.mountPetCallInCombatEnabled = lua->getGlobalBoolean("mountPetCallInCombatEnabled");
		if (lua->getGlobalFloat("mountPetDamageMultiplier") > 0) mountVars.mountPetDamageMultiplier = lua->getGlobalFloat("mountPetDamageMultiplier");
		if (lua->getGlobalBoolean("mountPetSpeedSameAsmountPetEnabled") == true || lua->getGlobalBoolean("mountPetSpeedSameAsmountPetEnabled") == false) mountVars.mountPetSpeedSameAsPlayerEnabled = lua->getGlobalBoolean("mountPetSpeedSameAsmountPetEnabled");
		if (lua->getGlobalBoolean("mountPetGallopToggleEnabled") == true || lua->getGlobalBoolean("mountPetGallopToggleEnabled") == false) mountVars.mountPetGallopToggleEnabled = lua->getGlobalBoolean("mountPetGallopToggleEnabled");
		if (lua->getGlobalFloat("mountPetGallopDamagePercent") >= 0 && lua->getGlobalFloat("mountPetGallopDamagePercent") <= 100) mountVars.mountPetGallopDamagePercent = lua->getGlobalFloat("mountPetGallopDamagePercent");

		//Vehicle 
		if (lua->getGlobalInt("mountVehicleBaseDecayCycle") >= 0) mountVars.mountVehicleBaseDecayCycle = lua->getGlobalInt("mountVehicleBaseDecayCycle");
		if (lua->getGlobalInt("mountVehicleBaseDecayRate") >= 0) mountVars.mountVehicleBaseDecayRate = lua->getGlobalInt("mountVehicleBaseDecayRate");
		if (lua->getGlobalBoolean("mountVehicleInitialDecayEnabled") == true || lua->getGlobalBoolean("mountVehicleInitialDecayEnabled") == false) mountVars.mountVehicleInitialDecayEnabled = lua->getGlobalBoolean("mountVehicleInitialDecayEnabled");
		if (lua->getGlobalInt("mountVehicleCallTime") >= 0) mountVars.mountVehicleCallTime = lua->getGlobalInt("mountVehicleCallTime");
		if (lua->getGlobalBoolean("mountVehicleStoreInCombatEnabled") == true || lua->getGlobalBoolean("mountVehicleStoreInCombatEnabled") == false) mountVars.mountVehicleStoreInCombatEnabled = lua->getGlobalBoolean("mountVehicleStoreInCombatEnabled");
		if (lua->getGlobalBoolean("mountVehicleShowVehicleSpeedEnabled") == true || lua->getGlobalBoolean("mountVehicleShowVehicleSpeedEnabled") == false) mountVars.mountVehicleShowVehicleSpeedEnabled = lua->getGlobalBoolean("mountVehicleShowVehicleSpeedEnabled");
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

bool MountVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t MountVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void MountVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

