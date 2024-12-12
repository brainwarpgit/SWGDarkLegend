#ifndef FACTIONVARIABLES_H_
#define FACTIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class FactionVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	FactionVariables();
	~FactionVariables();
	void startFactionVariables();
};

extern FactionVariables factionVars;

#endif /*FACTIONVARIABLES_H_*/
