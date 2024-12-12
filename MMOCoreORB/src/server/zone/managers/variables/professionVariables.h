#ifndef PROFESSIONVARIABLES_H_
#define PROFESSIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class ProfessionVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	ProfessionVariables();
	~ProfessionVariables();
	void startProfessionVariables();
};

extern ProfessionVariables professionVars;

#endif /*PROFESSIONVARIABLES_H_*/
