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
	//Admin
	String serverAdminTag{"SWGEmu-Admin"};

	//Auction
	int serverAuctionMaxBazaarPrice{20000};
	int serverAuctionMaxSales{25};
	int serverAuctionMaxSalesFee{20};
	int serverAuctionVendorExpirePeriod{30};
	int serverAuctionCommodityExpirePeriod{7};

	//Commands
	bool serverCommandCheckForceStatusCommandEnabled{true};
	bool serverCommandMeditateMergeEnabled{false};
	bool serverCommandObjectCreateAttachmentEnabled{false};
	bool serverCommandfsVillageEnabled{false};
	bool serverCommandRegrantSkillsEnabled{false};

	//Faction
	int serverFactionMaxRank{15};
	float serverFactionCapMultiplier{1};

	//Group
	int serverGroupMaxSize{20};

	//Player Payments
	bool serverPaymentCashAndBankEnabled{false};

	//Resources
	bool serverResourcesAddNameEnabled{false};
	int serverResourcesMinimumQuality{0};
	int serverResourcesMaximumQuality{1000};
	int serverResourcesContainerSize{100000};
	int serverResourcesResourceDeedSize{30000};

	//Server
	int serverDrawDistance{192};
	bool serverPlayersOnlineAtLoginEnabled{false};

	//Vendor
	bool serverVendorLowMaintenanceEmailEnabled{false};
	int serverVendorLowMaintenanceEmailWarningThreshold{360};
	bool serverVendorSkimSalesForMaintenanceEnabled{false};
	float serverVendorSkimSalesForMaintenancePercent{5};
};

extern ServerVariables serverVars;

#endif /*SERVERVARIABLES_H_*/
