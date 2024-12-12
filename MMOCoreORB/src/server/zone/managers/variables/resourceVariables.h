#ifndef RESOURCEVARIABLES_H_
#define RESOURCEVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class ResourceVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	ResourceVariables();
	~ResourceVariables();
	void startResourceVariables();
};

extern ResourceVariables resourceVars;

#endif /*RESOURCEVARIABLES_H_*/
