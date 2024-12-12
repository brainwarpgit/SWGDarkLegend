#ifndef WEAPONVARIABLES_H_
#define WEAPONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class WeaponVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	WeaponVariables();
	~WeaponVariables();
	void startWeaponVariables();
};

extern WeaponVariables weaponVars;

#endif /*WEAPONVARIABLES_H_*/
