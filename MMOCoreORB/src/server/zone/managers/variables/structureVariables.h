#ifndef STRUCTUREVARIABLES_H_
#define STRUCTUREVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class StructureVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	StructureVariables();
	~StructureVariables();
	void startStructureVariables();
};

extern StructureVariables structureVars;

#endif /*STRUCTUREVARIABLES_H_*/
