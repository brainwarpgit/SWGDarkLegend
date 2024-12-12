#ifndef VEHICLEVARIABLES_H_
#define VEHICLEVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class VehicleVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	VehicleVariables();
	~VehicleVariables();
	void startVehicleVariables();
};

extern VehicleVariables vehicleVars;

#endif /*VEHICLEVARIABLES_H_*/
