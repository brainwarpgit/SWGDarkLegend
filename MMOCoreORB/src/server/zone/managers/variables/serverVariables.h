#ifndef SERVERVARIABLES_H_
#define SERVERVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class ServerVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	ServerVariables();
	~ServerVariables();
	void startServerVariables();
};

extern ServerVariables serverVars;

#endif /*SERVERVARIABLES_H_*/
