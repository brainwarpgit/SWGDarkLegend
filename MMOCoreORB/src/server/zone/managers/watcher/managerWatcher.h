#ifndef MANAGERWATCHER_H_
#define MANAGERWATCHER_H_

#include <string>
#include <ctime>
#include <functional>
#include <unordered_map>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "engine/log/Logger.h"

namespace managerWatcher {

	void startWatching(const std::function<void()>& loadConfigFunction, const std::string& managerName);
	void stopWatching();
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	extern bool stopWatch;
	extern std::unordered_map<std::string, time_t> fileModifiedTimes;

}

#endif /* MANAGERWATCHER_H_ */

