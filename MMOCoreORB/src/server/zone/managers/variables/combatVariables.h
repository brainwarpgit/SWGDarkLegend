#ifndef COMBATVARIABLES_H_
#define COMBATVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CombatVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CombatVariables();
	~CombatVariables();
	void startCombatVariables();
};

extern CombatVariables combatVars;

#endif /*COMBATVARIABLES_H_*/
