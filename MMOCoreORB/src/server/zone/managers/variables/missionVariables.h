#ifndef MISSIONVARIABLES_H_
#define MISSIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class MissionVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	MissionVariables();
	~MissionVariables();
	void startMissionVariables();
	//Mission
	int missionBountyExpirationTime{48};
	int missionExpirationTime{48};
	int missionMaxCount{2};
	int missionListCount{6};
	bool missionNameAndLevelEnabled{false};
	bool missionDirectionSelectionEnabled{false};
	bool missionLevelSelectionEnabled{false};
	int missionRewardMultiplier{1};
	bool missionRandomAttacksEnabled{false};
	bool missionSurveyMissionRewardsResourcesEnabled{false};
	float missionSurveyMissionRewardsResourcesMultiplier{1};
	bool missionSurveyMissionLimitToLessThanNinetyEnabled{false};
	bool missionSurveyMissionEnableMoreResourcesEnabled{false};
	float missionSurveyMissionCompletionDistance{1024};
};

extern MissionVariables missionVars;

#endif /*MISSIONVARIABLES_H_*/
