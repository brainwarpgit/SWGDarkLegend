#ifndef PLAYERCREATIONVARIABLES_H_
#define PLAYERCREATIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PlayerCreationVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PlayerCreationVariables();
	~PlayerCreationVariables();
	void startPlayerCreationVariables();
};

extern PlayerCreationVariables playerCreationVars;

#endif /*PLAYERCREATIONVARIABLES_H_*/
