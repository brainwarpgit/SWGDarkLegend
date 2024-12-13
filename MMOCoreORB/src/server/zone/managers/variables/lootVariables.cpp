#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/lootVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

LootVariables lootVars;

LootVariables::LootVariables() : Logger("LootVariables") {}

LootVariables::~LootVariables() {}

void LootVariables::startLootVariables() {

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

bool LootVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/loot_variables.lua";

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
		//Loot 
		if (lua->getGlobalInt("lootDistance") > 0) lootVars.lootDistance = lua->getGlobalInt("lootDistance");
		if (lua->getGlobalBoolean("lootAreaEnabled") == true || lua->getGlobalBoolean("lootAreaEnabled") == false) lootVars.lootAreaEnabled = lua->getGlobalBoolean("lootAreaEnabled");
		if (lua->getGlobalFloat("lootCreditMultiplier") > 0) lootVars.lootCreditMultiplier = lua->getGlobalFloat("lootCreditMultiplier");
		if (lua->getGlobalInt("lootAttachmentMax") > 0) lootVars.lootAttachmentMax = lua->getGlobalInt("lootAttachmentMax");
		if (lua->getGlobalInt("lootAttachmentMin") > 0) lootVars.lootAttachmentMin = lua->getGlobalInt("lootAttachmentMin");
		if (lua->getGlobalInt("lootAttachmentMaxLevel") > 0 && lua->getGlobalInt("lootAttachmentMaxLevel") <= lua->getGlobalInt("creatureMaxLevel")) lootVars.lootAttachmentMaxLevel = lua->getGlobalInt("lootAttachmentMaxLevel");
		if (lua->getGlobalInt("lootAttachmentModCount") > 0) lootVars.lootAttachmentModCount = lua->getGlobalInt("lootAttachmentModCount");
		if (lua->getGlobalInt("lootDropAttachmentModCount") > 0) lootVars.lootDropAttachmentModCount = lua->getGlobalInt("lootDropAttachmentModCount");
		if (lua->getGlobalBoolean("lootAttachmentNameEnabled") == true || lua->getGlobalBoolean("lootAttachmentNameEnabled") == false) lootVars.lootAttachmentNameEnabled = lua->getGlobalBoolean("lootAttachmentNameEnabled");
		if (lua->getGlobalBoolean("lootCreditLuckModifier") == true || lua->getGlobalBoolean("lootCreditLuckModifier") == false) lootVars.lootCreditLuckModifier = lua->getGlobalBoolean("lootCreditLuckModifier");
		if (lua->getGlobalInt("lootMaxLevel") > 0 && lua->getGlobalInt("lootMaxLevel") <= lua->getGlobalInt("creatureMaxLevel")) lootVars.lootMaxLevel = lua->getGlobalInt("lootMaxLevel");
		if (lua->getGlobalInt("lootMinLevel") > 0 && lua->getGlobalInt("lootMinLevel") < lua->getGlobalInt("lootMaxLevel")) lootVars.lootMinLevel = lua->getGlobalInt("lootMinLevel");
		if (lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == true || lua->getGlobalBoolean("lootShowForceCostDecimalEnabled") == false) lootVars.lootShowForceCostDecimalEnabled = lua->getGlobalBoolean("lootShowForceCostDecimalEnabled");
		if (lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == true || lua->getGlobalBoolean("lootRareColorCrystalsEnabled") == false) lootVars.lootRareColorCrystalsEnabled = lua->getGlobalBoolean("lootRareColorCrystalsEnabled");
		if (lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == true || lua->getGlobalBoolean("lootGroupCreditsSplitEnabled") == false) lootVars.lootGroupCreditsSplitEnabled = lua->getGlobalBoolean("lootGroupCreditsSplitEnabled");
		if (lua->getGlobalFloat("lootChanceMultiplier") > 0) lootVars.lootChanceMultiplier = lua->getGlobalFloat("lootChanceMultiplier");
		if (lua->getGlobalFloat("lootResourceMultiplier") > 0) lootVars.lootResourceMultiplier = lua->getGlobalFloat("lootResourceMultiplier");
		if (lua->getGlobalBoolean("lootYellowModifierNameEnabled") == true || lua->getGlobalBoolean("lootYellowModifierNameEnabled") == false) lootVars.lootYellowModifierNameEnabled = lua->getGlobalBoolean("lootYellowModifierNameEnabled");
		if (lua->getGlobalBoolean("lootYellowModifierNameEnabled") == true && lua->getGlobalString("lootYellowModifierName") !=  "") lootVars.lootYellowModifierName = lua->getGlobalString("lootYellowModifierName");
		if (lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled") == true || lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled") == false) lootVars.lootUseLootModifiersForDamageModifiersEnabled = lua->getGlobalBoolean("lootUseLootModifiersForDamageModifiersEnabled");
		if (lua->getGlobalFloat("lootArmorMaxResists") > 0 && lua->getGlobalFloat("lootArmorMaxResists") <= lua->getGlobalFloat("playerMaxArmorUnSliced")) lootVars.lootArmorMaxResists = lua->getGlobalFloat("lootArmorMaxResists");
		if (lua->getGlobalBoolean("lootNewLootQualityNamingEnabled") == true || lua->getGlobalBoolean("lootNewLootQualityNamingEnabled") == false) lootVars.lootNewLootQualityNamingEnabled = lua->getGlobalBoolean("lootNewLootQualityNamingEnabled");
		if (lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled") == true || lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled") == false) lootVars.lootModifiersAffectLightsaberCrystalsEnabled = lua->getGlobalBoolean("lootModifiersAffectLightsaberCrystalsEnabled");
		if (lua->getGlobalBoolean("lootLevelToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootNewLootQualityNaminlootLevelToItemDescriptionEnabledgEnabled") == false) lootVars.lootLevelToItemDescriptionEnabled = lua->getGlobalBoolean("lootLevelToItemDescriptionEnabled");
		if (lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled") == false) lootVars.lootModifierToItemDescriptionEnabled = lua->getGlobalBoolean("lootModifierToItemDescriptionEnabled");
		if (lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled") == true || lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled") == false) lootVars.lootQualityToItemDescriptionEnabled = lua->getGlobalBoolean("lootQualityToItemDescriptionEnabled");
		if (lua->getGlobalBoolean("lootSocketsOnWearablesEnabled") == true || lua->getGlobalBoolean("lootSocketsOnWearablesEnabled") == false) lootVars.lootSocketsOnWearablesEnabled = lua->getGlobalBoolean("lootSocketsOnWearablesEnabled");
		if (lua->getGlobalBoolean("lootSocketsOnWearableContainersEnabled") == true || lua->getGlobalBoolean("lootSocketsOnWearableContainersEnabled") == false) lootVars.lootSocketsOnWearableContainersEnabled = lua->getGlobalBoolean("lootSocketsOnWearableContainersEnabled");
		if (lua->getGlobalBoolean("lootColorCrystalColorInNameEnabled") == true || lua->getGlobalBoolean("lootColorCrystalColorInNameEnabled") == false) lootVars.lootColorCrystalColorInNameEnabled = lua->getGlobalBoolean("lootColorCrystalColorInNameEnabled");

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

bool LootVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t LootVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void LootVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

