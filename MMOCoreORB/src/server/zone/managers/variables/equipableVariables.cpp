#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/equipableVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

EquipableVariables equipableVars;

EquipableVariables::EquipableVariables() : Logger("EquipableVariables") {}

EquipableVariables::~EquipableVariables() {}

void EquipableVariables::startEquipableVariables() {

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

bool EquipableVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/equipable_variables.lua";

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
		//Armor
		if (lua->getGlobalFloat("equipableArmorPSGDecayRateMultiplier") > 0) equipableVars.equipableArmorPSGDecayRateMultiplier = lua->getGlobalFloat("equipableArmorPSGDecayRateMultiplier");
		if (lua->getGlobalFloat("equipableArmorDecayRateMultiplier") > 0) equipableVars.equipableArmorDecayRateMultiplier = lua->getGlobalFloat("equipableArmorDecayRateMultiplier");
		if (lua->getGlobalFloat("equipableArmorMaxArmorUnSliced") >= 0) equipableVars.equipableArmorMaxArmorUnSliced = lua->getGlobalFloat("equipableArmorMaxArmorUnSliced");
		if (lua->getGlobalFloat("equipableArmorMaxArmorSliced") >= 0) equipableVars.equipableArmorMaxArmorSliced = lua->getGlobalFloat("equipableArmorMaxArmorSliced");
		//Weapon
		if (lua->getGlobalInt("equipableWeaponDecayRateChance") > 0) equipableVars.equipableWeaponDecayRateChance = lua->getGlobalInt("equipableWeaponDecayRateChance");
		if (lua->getGlobalInt("equipableWeaponDecayRateWithPowerUpChance") > 0) equipableVars.equipableWeaponDecayRateWithPowerUpChance = lua->getGlobalInt("equipableWeaponDecayRateWithPowerUpChance");
		if (lua->getGlobalFloat("equipableWeaponCrystalDamagePerTick") > 0) equipableVars.equipableWeaponCrystalDamagePerTick = lua->getGlobalFloat("equipableWeaponCrystalDamagePerTick");
		if (lua->getGlobalFloat("equipableWeaponDamagePerTicket") > 0) equipableVars.equipableWeaponDamagePerTicket = lua->getGlobalFloat("equipableWeaponDamagePerTicket");
		//Wearables
		if (lua->getGlobalBoolean("equipableWearablesFactionEnabled") == true || lua->getGlobalBoolean("equipableWearablesFactionEnabled") == false) equipableVars.equipableWearablesFactionEnabled = lua->getGlobalBoolean("equipableWearablesFactionEnabled");
		if (lua->getGlobalBoolean("equipableWearablesAllPlayerRacesEnabled") == true || lua->getGlobalBoolean("equipableWearablesAllPlayerRacesEnabled") == false) equipableVars.equipableWearablesAllPlayerRacesEnabled = lua->getGlobalBoolean("equipableWearablesAllPlayerRacesEnabled");
		if (lua->getGlobalBoolean("equipableWearablesBackpackWipeEnabled") == true || lua->getGlobalBoolean("equipableWearablesBackpackWipeEnabled") == false) equipableVars.equipableWearablesBackpackWipeEnabled = lua->getGlobalBoolean("equipableWearablesBackpackWipeEnabled");
		if (lua->getGlobalBoolean("equipableWearablesChangeWearableColorsEnabled") == true || lua->getGlobalBoolean("equipableWearablesChangeWearableColorsEnabled") == false) equipableVars.equipableWearablesChangeWearableColorsEnabled = lua->getGlobalBoolean("equipableWearablesChangeWearableColorsEnabled");
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

bool EquipableVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t EquipableVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void EquipableVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

