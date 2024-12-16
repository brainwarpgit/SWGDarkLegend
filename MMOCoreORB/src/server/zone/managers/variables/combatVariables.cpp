#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/combatVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

CombatVariables combatVars;

CombatVariables::CombatVariables() : Logger("CombatVariables") {}

CombatVariables::~CombatVariables() {}

void CombatVariables::startCombatVariables() {

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

bool CombatVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/combat_variables.lua";

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
		//Combat 
		if (lua->getGlobalFloat("combatDamageMeleeWeaponMultiplier") > 0) combatVars.combatDamageMeleeWeaponMultiplier = lua->getGlobalFloat("combatDamageMeleeWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageUnarmedWeaponMultiplier") > 0) combatVars.combatDamageUnarmedWeaponMultiplier = lua->getGlobalFloat("combatDamageUnarmedWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageOneHandWeaponMultiplier") > 0) combatVars.combatDamageOneHandWeaponMultiplier = lua->getGlobalFloat("combatDamageOneHandWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageTwoHandWeaponMultiplier") > 0) combatVars.combatDamageTwoHandWeaponMultiplier = lua->getGlobalFloat("combatDamageTwoHandWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamagePolearmWeaponMultiplier") > 0) combatVars.combatDamagePolearmWeaponMultiplier = lua->getGlobalFloat("combatDamagePolearmWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageRangedWeaponMultiplier") > 0) combatVars.combatDamageRangedWeaponMultiplier = lua->getGlobalFloat("combatDamageRangedWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamagePistolWeaponMultiplier") > 0) combatVars.combatDamagePistolWeaponMultiplier = lua->getGlobalFloat("combatDamagePistolWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageCarbineWeaponMultiplier") > 0) combatVars.combatDamageCarbineWeaponMultiplier = lua->getGlobalFloat("combatDamageCarbineWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageRifleWeaponMultiplier") > 0) combatVars.combatDamageRifleWeaponMultiplier = lua->getGlobalFloat("combatDamageRifleWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageThrownWeaponMultiplier") > 0) combatVars.combatDamageThrownWeaponMultiplier = lua->getGlobalFloat("combatDamageThrownWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageHeavyWeaponMultiplier") > 0) combatVars.combatDamageHeavyWeaponMultiplier = lua->getGlobalFloat("combatDamageHeavyWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageSpecialHeavyWeaponMultiplier") > 0) combatVars.combatDamageSpecialHeavyWeaponMultiplier = lua->getGlobalFloat("combatDamageSpecialHeavyWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageMineWeaponMultiplier") > 0) combatVars.combatDamageMineWeaponMultiplier = lua->getGlobalFloat("combatDamageMineWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageJediWeaponMultiplier") > 0) combatVars.combatDamageJediWeaponMultiplier = lua->getGlobalFloat("combatDamageJediWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageJediOneHandWeaponMultiplier") > 0) combatVars.combatDamageJediOneHandWeaponMultiplier = lua->getGlobalFloat("combatDamageJediOneHandWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageJediTwoHandWeaponMultiplier") > 0) combatVars.combatDamageJediTwoHandWeaponMultiplier = lua->getGlobalFloat("combatDamageJediTwoHandWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageJediPolearmWeaponMultiplier") > 0) combatVars.combatDamageJediPolearmWeaponMultiplier = lua->getGlobalFloat("combatDamageJediPolearmWeaponMultiplier");
		if (lua->getGlobalFloat("combatDamageJediForcePowerMultiplier") > 0) combatVars.combatDamageJediForcePowerMultiplier = lua->getGlobalFloat("combatDamageJediForcePowerMultiplier");
		if (lua->getGlobalFloat("combatDamageAllMultiplier") > 0) combatVars.combatDamageAllMultiplier = lua->getGlobalFloat("combatDamageAllMultiplier");
		if (lua->getGlobalBoolean("combatCriticalDamageEnabled") == true || lua->getGlobalBoolean("combatCriticalDamageEnabled") == false) combatVars.combatCriticalDamageEnabled = lua->getGlobalBoolean("combatCriticalDamageEnabled");
		if (lua->getGlobalFloat("combatCriticalMultiplier") >= 1) combatVars.combatCriticalMultiplier = lua->getGlobalFloat("combatCriticalMultiplier");
		if (lua->getGlobalFloat("combatLegendaryCriticalMultiplier") >= 1) combatVars.combatLegendaryCriticalMultiplier = lua->getGlobalFloat("combatLegendaryCriticalMultiplier");
		if (lua->getGlobalBoolean("combatAIFleeEnabled") == true || lua->getGlobalBoolean("combatAIFleeEnabled") == false) combatVars.combatAIFleeEnabled = lua->getGlobalBoolean("combatAIFleeEnabled");
		if (lua->getGlobalBoolean("combatAICallForHelpEnabled") == true || lua->getGlobalBoolean("combatAICallForHelpEnabled") == false) combatVars.combatAICallForHelpEnabled = lua->getGlobalBoolean("combatAICallForHelpEnabled");
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

bool CombatVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t CombatVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void CombatVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

