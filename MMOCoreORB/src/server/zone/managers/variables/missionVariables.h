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
};

extern MissionVariables missionVars;

#endif /*MISSIONVARIABLES_H_*/
