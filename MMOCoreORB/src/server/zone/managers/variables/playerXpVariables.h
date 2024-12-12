#ifndef PLAYERXPVARIABLES_H_
#define PLAYERXPVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PlayerXpVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PlayerXpVariables();
	~PlayerXpVariables();
	void startPlayerXpVariables();
};

extern PlayerXpVariables playerXpVars;

#endif /*PLAYERXPVARIABLES_H_*/
