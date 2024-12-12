#ifndef AUCTIONVARIABLES_H_
#define AUCTIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class AuctionVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	AuctionVariables();
	~AuctionVariables();
	void startAuctionVariables();
};

extern AuctionVariables auctionVars;

#endif /*AUCTIONVARIABLES_H_*/
