#ifndef LOOTVARIABLES_H_
#define LOOTVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class LootVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	LootVariables();
	~LootVariables();
	void startLootVariables();
};

extern LootVariables lootVars;

#endif /*LOOTVARIABLES_H_*/
