#ifndef CREATUREVARIABLES_H_
#define CREATUREVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CreatureVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CreatureVariables();
	~CreatureVariables();
	void startCreatureVariables();
};

extern CreatureVariables creatureVars;

#endif /*CREATUREVARIABLES_H_*/
