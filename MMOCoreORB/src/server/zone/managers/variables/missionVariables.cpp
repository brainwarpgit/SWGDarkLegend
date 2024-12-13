#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/missionVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

MissionVariables missionVars;

MissionVariables::MissionVariables() : Logger("MissionVariables") {}

MissionVariables::~MissionVariables() {}

void MissionVariables::startMissionVariables() {

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

bool MissionVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/mission_variables.lua";

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
		//Mission 
		if (lua->getGlobalInt("missionBountyExpirationTime") > 0) missionVars.missionBountyExpirationTime = lua->getGlobalInt("missionBountyExpirationTime");
		if (lua->getGlobalInt("missionExpirationTime") > 0) missionVars.missionExpirationTime = lua->getGlobalInt("missionExpirationTime");
		if (lua->getGlobalInt("missionMaxCount") > 0) missionVars.missionMaxCount = lua->getGlobalInt("missionMaxCount");
		if (lua->getGlobalInt("missionListCount") > 0) missionVars.missionListCount = lua->getGlobalInt("missionListCount");
		if (lua->getGlobalBoolean("missionNameAndLevelEnabled") == true || lua->getGlobalBoolean("missionNameAndLevelEnabled") == false) missionVars.missionNameAndLevelEnabled = lua->getGlobalBoolean("missionNameAndLevelEnabled");
		if (lua->getGlobalBoolean("missionDirectionSelectionEnabled") == true || lua->getGlobalBoolean("missionDirectionSelectionEnabled") == false) missionVars.missionDirectionSelectionEnabled = lua->getGlobalBoolean("missionDirectionSelectionEnabled");
		if (lua->getGlobalBoolean("missionLevelSelectionEnabled") == true || lua->getGlobalBoolean("missionLevelSelectionEnabled") == false) missionVars.missionLevelSelectionEnabled = lua->getGlobalBoolean("missionLevelSelectionEnabled");
		if (lua->getGlobalInt("missionRewardMultiplier") > 0) missionVars.missionRewardMultiplier = lua->getGlobalInt("missionRewardMultiplier");
		if (lua->getGlobalBoolean("missionRandomAttacksEnabled") == true || lua->getGlobalBoolean("missionRandomAttacksEnabled") == false) missionVars.missionRandomAttacksEnabled = lua->getGlobalBoolean("missionRandomAttacksEnabled");
		if (lua->getGlobalBoolean("missionSurveyMissionRewardsResourcesEnabled") == true || lua->getGlobalBoolean("missionSurveyMissionRewardsResourcesEnabled") == false) missionVars.missionSurveyMissionRewardsResourcesEnabled = lua->getGlobalBoolean("missionSurveyMissionRewardsResourcesEnabled");
		if (lua->getGlobalFloat("missionSurveyMissionRewardsResourcesMultiplier") > 0) missionVars.missionSurveyMissionRewardsResourcesMultiplier = lua->getGlobalFloat("missionSurveyMissionRewardsResourcesMultiplier");
		if (lua->getGlobalBoolean("missionSurveyMissionLimitToLessThanNinetyEnabled") == true || lua->getGlobalBoolean("missionSurveyMissionLimitToLessThanNinetyEnabled") == false) missionVars.missionSurveyMissionLimitToLessThanNinetyEnabled = lua->getGlobalBoolean("missionSurveyMissionLimitToLessThanNinetyEnabled");
		if (lua->getGlobalBoolean("missionSurveyMissionEnableMoreResourcesEnabled") == true || lua->getGlobalBoolean("missionSurveyMissionEnableMoreResourcesEnabled") == false) missionVars.missionSurveyMissionEnableMoreResourcesEnabled = lua->getGlobalBoolean("missionSurveyMissionEnableMoreResourcesEnabled");
		if (lua->getGlobalFloat("missionSurveyMissionCompletionDistance") >= 0) missionVars.missionSurveyMissionCompletionDistance = lua->getGlobalFloat("missionSurveyMissionCompletionDistance");
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

bool MissionVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t MissionVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void MissionVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

