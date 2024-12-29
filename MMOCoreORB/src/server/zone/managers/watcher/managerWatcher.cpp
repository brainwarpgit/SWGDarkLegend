#include "server/zone/managers/watcher/managerWatcher.h"
#include "conf/ConfigManager.h"

namespace managerWatcher {

	bool stopWatch = false;
	std::unordered_map<std::string, time_t> fileModifiedTimes;
	
	bool fileExists(const std::string& filePath) {
		return (access(filePath.c_str(), F_OK) != -1);
	}

	time_t getFileModifiedTime(const std::string& filePath) {
		struct stat fileInfo;
		if (stat(filePath.c_str(), &fileInfo) != 0) {
			std::cerr << "Error getting file status for: " << filePath << std::endl;
			return 0;
		}
		return fileInfo.st_mtime;
	}

	void startWatching(const std::function<void()>& loadConfigFunction, const std::string& managerName) {
		while (!stopWatch) {
			auto config = ConfigManager::instance();
			long threadReloadTime = config->getInt("Core3.threadReloadTime", 10);
			std::this_thread::sleep_for(std::chrono::seconds(threadReloadTime));
			loadConfigFunction();
		}
		Logger::console.info(true) << managerName << " - stopManagerWatcher called. Ending startWatching()";
	}

	void stopWatching() {
		stopWatch = true;
	}

}

