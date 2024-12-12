#ifndef PLAYERVARIABLES_H_
#define PLAYERVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PlayerVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PlayerVariables();
	~PlayerVariables();
	void startPlayerVariables();
};

extern PlayerVariables playerVars;

#endif /*PLAYERVARIABLES_H_*/
