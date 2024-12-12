#ifndef CRAFTINGVARIABLES_H_
#define CRAFTINGVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CraftingVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CraftingVariables();
	~CraftingVariables();
	void startCraftingVariables();
};

extern CraftingVariables craftingVars;

#endif /*CRAFTINGVARIABLES_H_*/
