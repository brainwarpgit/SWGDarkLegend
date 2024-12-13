#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/creatureVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

CreatureVariables creatureVars;

CreatureVariables::CreatureVariables() : Logger("CreatureVariables") {}

CreatureVariables::~CreatureVariables() {}

void CreatureVariables::startCreatureVariables() {

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

bool CreatureVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/creature_variables.lua";

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
		//Creature 
		if (lua->getGlobalBoolean("creatureRandomDifficultyEnabled") == true || lua->getGlobalBoolean("creatureRandomDifficultyEnabled") == false) creatureVars.creatureRandomDifficultyEnabled = lua->getGlobalBoolean("creatureRandomDifficultyEnabled");
		if (lua->getGlobalInt("creatureMaxLevel") > 0) creatureVars.creatureMaxLevel = lua->getGlobalInt("creatureMaxLevel");
		if (lua->getGlobalFloat("creatureBaseScaleMultiplier") > 0) creatureVars.creatureBaseScaleMultiplier = lua->getGlobalFloat("creatureBaseScaleMultiplier");
		if (lua->getGlobalFloat("creatureBaseXPMultiplier") > 0) creatureVars.creatureBaseXPMultiplier = lua->getGlobalFloat("creatureBaseXPMultiplier");
		if (lua->getGlobalFloat("creatureBaseMeatAmountMultiplier") > 0) creatureVars.creatureBaseMeatAmountMultiplier = lua->getGlobalFloat("creatureBaseMeatAmountMultiplier");
		if (lua->getGlobalFloat("creatureBaseHideAmountMultiplier") > 0) creatureVars.creatureBaseHideAmountMultiplier = lua->getGlobalFloat("creatureBaseHideAmountMultiplier");
		if (lua->getGlobalFloat("creatureBaseBoneAmountMultiplier") > 0) creatureVars.creatureBaseBoneAmountMultiplier = lua->getGlobalFloat("creatureBaseBoneAmountMultiplier");
		if (lua->getGlobalFloat("creatureBaseMilkMultiplier") > 0) creatureVars.creatureBaseMilkMultiplier = lua->getGlobalFloat("creatureBaseMilkMultiplier");
		if (lua->getGlobalFloat("creatureBaseLevelMultiplier") > 0) creatureVars.creatureBaseLevelMultiplier = lua->getGlobalFloat("creatureBaseLevelMultiplier");
		if (lua->getGlobalFloat("creatureBaseChanceHitMultiplier") > 0) creatureVars.creatureBaseChanceHitMultiplier = lua->getGlobalFloat("creatureBaseChanceHitMultiplier");
		if (lua->getGlobalFloat("creatureBaseFerocityMultiplier") > 0) creatureVars.creatureBaseFerocityMultiplier = lua->getGlobalFloat("creatureBaseFerocityMultiplier");
		if (lua->getGlobalFloat("creatureBaseDamageMaxMultiplier") > 0) creatureVars.creatureBaseDamageMaxMultiplier = lua->getGlobalFloat("creatureBaseDamageMaxMultiplier");
		if (lua->getGlobalFloat("creatureBaseDamageMinMultiplier") > 0) creatureVars.creatureBaseDamageMinMultiplier = lua->getGlobalFloat("creatureBaseDamageMinMultiplier");
		if (lua->getGlobalFloat("creatureBaseHAMMultiplier") > 0) creatureVars.creatureBaseHAMMultiplier = lua->getGlobalFloat("creatureBaseHAMMultiplier");
		if (lua->getGlobalFloat("creatureBaseHAMMaxMultiplier") > 0) creatureVars.creatureBaseHAMMaxMultiplier = lua->getGlobalFloat("creatureBaseHAMMaxMultiplier");
		if (lua->getGlobalFloat("creatureBaseResistsMultiplier") > 0) creatureVars.creatureBaseResistsMultiplier = lua->getGlobalFloat("creatureBaseResistsMultiplier");
		if (lua->getGlobalFloat("creatureKineticMaxResists") >= 0 && lua->getGlobalFloat("creatureKineticMaxResists") <= 100) creatureVars.creatureKineticMaxResists = lua->getGlobalFloat("creatureKineticMaxResists");
		if (lua->getGlobalFloat("creatureEnergyMaxResists") >= 0 && lua->getGlobalFloat("creatureEnergyMaxResists") <= 100) creatureVars.creatureEnergyMaxResists = lua->getGlobalFloat("creatureEnergyMaxResists");
		if (lua->getGlobalFloat("creatureBlastMaxResists") >= 0 && lua->getGlobalFloat("creatureBlastMaxResists") <= 100) creatureVars.creatureBlastMaxResists = lua->getGlobalFloat("creatureBlastMaxResists");
		if (lua->getGlobalFloat("creatureHeatMaxResists") >= 0 && lua->getGlobalFloat("creatureHeatMaxResists") <= 100) creatureVars.creatureHeatMaxResists = lua->getGlobalFloat("creatureHeatMaxResists");
		if (lua->getGlobalFloat("creatureColdMaxResists") >= 0 && lua->getGlobalFloat("creatureColdMaxResists") <= 100) creatureVars.creatureColdMaxResists = lua->getGlobalFloat("creatureColdMaxResists");
		if (lua->getGlobalFloat("creatureElectricityMaxResists") >= 0 && lua->getGlobalFloat("creatureElectricityMaxResists") <= 100) creatureVars.creatureElectricityMaxResists = lua->getGlobalFloat("creatureElectricityMaxResists");
		if (lua->getGlobalFloat("creatureAcidMaxResists") >= 0 && lua->getGlobalFloat("creatureAcidMaxResists") <= 100) creatureVars.creatureAcidMaxResists = lua->getGlobalFloat("creatureAcidMaxResists");
		if (lua->getGlobalFloat("creatureStunMaxResists") >= 0 && lua->getGlobalFloat("creatureStunMaxResists") <= 100) creatureVars.creatureStunMaxResists = lua->getGlobalFloat("creatureStunMaxResists");
		if (lua->getGlobalFloat("creatureLightsaberMaxResists") >= 0 && lua->getGlobalFloat("creatureLightsaberMaxResists") <= 100) creatureVars.creatureLightsaberMaxResists = lua->getGlobalFloat("creatureLightsaberMaxResists");
		if (lua->getGlobalFloat("creatureWildSpawnDensity") >= 0) creatureVars.creatureWildSpawnDensity = lua->getGlobalFloat("creatureWildSpawnDensity");
		if (lua->getGlobalFloat("creatureSpawnElitePercentage") >= 0 && lua->getGlobalFloat("creatureSpawnElitePercentage") <= 100 && lua->getGlobalFloat("creatureSpawnElitePercentage") + lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100) creatureVars.creatureSpawnElitePercentage = 1000 - (lua->getGlobalFloat("creatureSpawnElitePercentage") * 10);
		if (lua->getGlobalFloat("creatureSpawnHeroicPercentage") >= 0 && lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100 && lua->getGlobalFloat("creatureSpawnElitePercentage") + lua->getGlobalFloat("creatureSpawnHeroicPercentage") <= 100) creatureVars.creatureSpawnHeroicPercentage = (1000 - lua->getGlobalFloat("creatureSpawnElitePercentage")) - (lua->getGlobalFloat("creatureSpawnHeroicPercentage") * 10);
		if (lua->getGlobalFloat("creatureModBaseScaleModifier") >= 0) creatureVars.creatureModBaseScaleModifier = lua->getGlobalFloat("creatureModBaseScaleModifier");
		if (lua->getGlobalFloat("creatureModBaseXPModifier") >= 0) creatureVars.creatureModBaseXPModifier = lua->getGlobalFloat("creatureModBaseXPModifier");
		if (lua->getGlobalFloat("creatureModBaseMeatAmountModifier") >= 0) creatureVars.creatureModBaseMeatAmountModifier = lua->getGlobalFloat("creatureModBaseMeatAmountModifier");
		if (lua->getGlobalFloat("creatureModBaseHideAmountModifier") >= 0) creatureVars.creatureModBaseHideAmountModifier = lua->getGlobalFloat("creatureModBaseHideAmountModifier");
		if (lua->getGlobalFloat("creatureModBaseBoneAmountModifier") >= 0) creatureVars.creatureModBaseBoneAmountModifier = lua->getGlobalFloat("creatureModBaseBoneAmountModifier");
		if (lua->getGlobalFloat("creatureModBaseMilkModifier") >= 0) creatureVars.creatureModBaseMilkModifier = lua->getGlobalFloat("creatureModBaseMilkModifier");
		if (lua->getGlobalFloat("creatureModBaseLevelModifier") >= 0) creatureVars.creatureModBaseLevelModifier = lua->getGlobalFloat("creatureModBaseLevelModifier");
		if (lua->getGlobalFloat("creatureModBaseChanceHitModifier") >= 0) creatureVars.creatureModBaseChanceHitModifier = lua->getGlobalFloat("creatureModBaseChanceHitModifier");
		if (lua->getGlobalFloat("creatureModBaseFerocityModifier") >= 0) creatureVars.creatureModBaseFerocityModifier = lua->getGlobalFloat("creatureModBaseFerocityModifier");
		if (lua->getGlobalFloat("creatureModBaseDamageMaxModifier") >= 0) creatureVars.creatureModBaseDamageMaxModifier = lua->getGlobalFloat("creatureModBaseDamageMaxModifier");
		if (lua->getGlobalFloat("creatureModBaseDamageMinModifier") >= 0) creatureVars.creatureModBaseDamageMinModifier = lua->getGlobalFloat("creatureModBaseDamageMinModifier");
		if (lua->getGlobalFloat("creatureModBaseHAMModifier") >= 0) creatureVars.creatureModBaseHAMModifier = lua->getGlobalFloat("creatureModBaseHAMModifier");
		if (lua->getGlobalFloat("creatureModBaseHAMMaxModifier") >= 0) creatureVars.creatureModBaseHAMMaxModifier = lua->getGlobalFloat("creatureModBaseHAMMaxModifier");
		if (lua->getGlobalFloat("creatureModBaseResistsModifier") >= 0) creatureVars.creatureModBaseResistsModifier = lua->getGlobalFloat("creatureModBaseResistsModifier");
		if (lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled") == true || lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled") == false) creatureVars.creatureAllCreatureCanSpawnBabyEnabled = lua->getGlobalBoolean("creatureAllCreatureCanSpawnBabyEnabled");
		if (lua->getGlobalFloat("creatureAllCreatureCanSpawnBabyChance") > 0) creatureVars.creatureAllCreatureCanSpawnBabyChance = lua->getGlobalFloat("creatureAllCreatureCanSpawnBabyChance");
		if (lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled") == true || lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled") == false) creatureVars.creatureBabyRandomDifficultyEnabled = lua->getGlobalBoolean("creatureBabyRandomDifficultyEnabled");
		if (lua->getGlobalInt("creatureBabySpawnChanceDestroyMissionLair") > 0) creatureVars.creatureBabySpawnChanceDestroyMissionLair = lua->getGlobalInt("creatureBabySpawnChanceDestroyMissionLair");
		if (lua->getGlobalInt("creatureBabySpawnChanceDynamicSpawn") > 0) creatureVars.creatureBabySpawnChanceDynamicSpawn = lua->getGlobalInt("creatureBabySpawnChanceDynamicSpawn");
		if (lua->getGlobalInt("creatureBabySpawnChanceDynamicLair") > 0) creatureVars.creatureBabySpawnChanceDynamicLair = lua->getGlobalInt("creatureBabySpawnChanceDynamicLair");
		if (lua->getGlobalBoolean("creatureShowRunSpeedEnabled") == true || lua->getGlobalBoolean("creatureShowRunSpeedEnabled") == false) creatureVars.creatureShowRunSpeedEnabled = lua->getGlobalBoolean("creatureShowRunSpeedEnabled");
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

bool CreatureVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t CreatureVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void CreatureVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

