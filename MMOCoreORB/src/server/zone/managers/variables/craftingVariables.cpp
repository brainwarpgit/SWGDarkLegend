#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/craftingVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

CraftingVariables craftingVars;

CraftingVariables::CraftingVariables() : Logger("CraftingVariables") {}

CraftingVariables::~CraftingVariables() {}

void CraftingVariables::startCraftingVariables() {

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

bool CraftingVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/crafting_variables.lua";

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
		//Crafting 
		if (lua->getGlobalInt("craftingFactoryCrateMaxSize") > 0) craftingVars.craftingFactoryCrateMaxSize = lua->getGlobalInt("craftingFactoryCrateMaxSize");
		if (lua->getGlobalFloat("craftingFactoryRunTimeMultiplier") >= 0) craftingVars.craftingFactoryRunTimeMultiplier = lua->getGlobalFloat("craftingFactoryRunTimeMultiplier");
		if (lua->getGlobalFloat("craftingToolCraftTimeMultiplier") >= 0) craftingVars.craftingToolCraftTimeMultiplier = lua->getGlobalFloat("craftingToolCraftTimeMultiplier");
		if (lua->getGlobalInt("craftingMaxSockets") >= 0) craftingVars.craftingMaxSockets = lua->getGlobalInt("craftingMaxSockets");
		if (lua->getGlobalInt("craftingMinSocketMod") >= 0) craftingVars.craftingMinSocketMod = lua->getGlobalInt("craftingMinSocketMod");
		if (lua->getGlobalInt("craftingMaxSocketMod") > 0) craftingVars.craftingMaxSocketMod = lua->getGlobalInt("craftingMaxSocketMod");
		if (lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled") == true || lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled") == false) craftingVars.craftingNewGenerateSocketsEnabled = lua->getGlobalBoolean("craftingNewGenerateSocketsEnabled");
		if (lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled") == true || lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled") == false) craftingVars.craftingWearableContainerSocketsEnabled = lua->getGlobalBoolean("craftingWearableContainerSocketsEnabled");
		if (lua->getGlobalBoolean("craftingNewAssemblyEnabled") == true || lua->getGlobalBoolean("craftingNewAssemblyEnabled") == false) craftingVars.craftingNewAssemblyEnabled = lua->getGlobalBoolean("craftingNewAssemblyEnabled");
		if (lua->getGlobalBoolean("craftingNewExperimentEnabled") == true || lua->getGlobalBoolean("craftingNewExperimentEnabled") == false) craftingVars.craftingNewExperimentEnabled = lua->getGlobalBoolean("craftingNewExperimentEnabled");
		if (lua->getGlobalBoolean("craftingNewRepairEnabled") == true || lua->getGlobalBoolean("craftingNewRepairEnabled") == false) craftingVars.craftingNewRepairEnabled = lua->getGlobalBoolean("craftingNewRepairEnabled");
		if (lua->getGlobalBoolean("craftingRepairBrokenEnabled") == true || lua->getGlobalBoolean("craftingRepairBrokenEnabled") == false) craftingVars.craftingRepairBrokenEnabled = lua->getGlobalBoolean("craftingRepairBrokenEnabled");
		if (lua->getGlobalFloat("craftingRepairMaxMod") > 0 && lua->getGlobalFloat("craftingRepairMaxMod") < 1) craftingVars.craftingRepairMaxMod = lua->getGlobalFloat("craftingRepairMaxMod");
		if (lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled") == true || lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled") == false) craftingVars.craftingCraftedItemsBetterThanLootEnabled = lua->getGlobalBoolean("craftingCraftedItemsBetterThanLootEnabled");
		if (lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier") > 0 && lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier") <= 1) craftingVars.craftingCraftedItemsBetterThanLootModifier = lua->getGlobalFloat("craftingCraftedItemsBetterThanLootModifier");
		if (lua->getGlobalFloat("craftingKineticMaxResists") >= 0 && lua->getGlobalFloat("craftingKineticMaxResists") <= 100) craftingVars.craftingKineticMaxResists = lua->getGlobalFloat("craftingKineticMaxResists");
		if (lua->getGlobalFloat("craftingEnergyMaxResists") >= 0 && lua->getGlobalFloat("craftingEnergyMaxResists") <= 100) craftingVars.craftingEnergyMaxResists = lua->getGlobalFloat("craftingEnergyMaxResists");
		if (lua->getGlobalFloat("craftingBlastMaxResists") >= 0 && lua->getGlobalFloat("craftingBlastMaxResists") <= 100) craftingVars.craftingBlastMaxResists = lua->getGlobalFloat("craftingBlastMaxResists");
		if (lua->getGlobalFloat("craftingHeatMaxResists") >= 0 && lua->getGlobalFloat("craftingHeatMaxResists") <= 100) craftingVars.craftingHeatMaxResists = lua->getGlobalFloat("craftingHeatMaxResists");
		if (lua->getGlobalFloat("craftingColdMaxResists") >= 0 && lua->getGlobalFloat("craftingColdMaxResists") <= 100) craftingVars.craftingColdMaxResists = lua->getGlobalFloat("craftingColdMaxResists");
		if (lua->getGlobalFloat("craftingElectricityMaxResists") >= 0 && lua->getGlobalFloat("craftingElectricityMaxResists") <= 100) craftingVars.craftingElectricityMaxResists = lua->getGlobalFloat("craftingElectricityMaxResists");
		if (lua->getGlobalFloat("craftingAcidMaxResists") >= 0 && lua->getGlobalFloat("craftingAcidMaxResists") <= 100) craftingVars.craftingAcidMaxResists = lua->getGlobalFloat("craftingAcidMaxResists");
		if (lua->getGlobalFloat("craftingStunMaxResists") >= 0 && lua->getGlobalFloat("craftingStunMaxResists") <= 100) craftingVars.craftingStunMaxResists = lua->getGlobalFloat("craftingStunMaxResists");
		if (lua->getGlobalFloat("craftingLightsaberMaxResists") >= 0 && lua->getGlobalFloat("craftingLightsaberMaxResists") <= 100) craftingVars.craftingLightsaberMaxResists = lua->getGlobalFloat("craftingLightsaberMaxResists");
		if (lua->getGlobalFloat("craftingAssemblyModifier") >= 0) craftingVars.craftingAssemblyModifier = lua->getGlobalFloat("craftingAssemblyModifier");
		if (lua->getGlobalBoolean("craftingWhileEntertainingEnabled") == true || lua->getGlobalBoolean("craftingWhileEntertainingEnabled") == false) craftingVars.craftingWhileEntertainingEnabled = lua->getGlobalBoolean("craftingWhileEntertainingEnabled");
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

bool CraftingVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t CraftingVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void CraftingVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

