#ifndef EQUIPABLEVARIABLES_H_
#define EQUIPABLEVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class EquipableVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	EquipableVariables();
	~EquipableVariables();
	void startEquipableVariables();
};

extern EquipableVariables equipableVars;

#endif /*EQUIPABLEVARIABLES_H_*/
