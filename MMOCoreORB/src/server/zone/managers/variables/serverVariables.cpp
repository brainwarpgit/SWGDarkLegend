#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/serverVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

ServerVariables serverVars;

ServerVariables::ServerVariables() : Logger("ServerVariables") {}

ServerVariables::~ServerVariables() {}

void ServerVariables::startServerVariables() {

	if (!loadConfigData()) {
		info(true) << "loadConfigData() FAILED";
		return;
	}
	std::thread reloadThread([this] { 
		startWatching(
			[this] {
				loadConfigData();
				}
			);
	});
	reloadThread.detach();

}

bool ServerVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/server_variables.lua";

	bool initialLoad = false;
	
	if (!fileExists(luaFilePath)) {
		return 0;
	}

	time_t modifiedTime = getFileModifiedTime(luaFilePath);

	if (modifiedTime == lastModifiedTime) {
		return true;
	}

	if (lastModifiedTime == 0) {
		info(true) << "Initial Load of " << luaFilePath;
		initialLoad = true;
	} else {
		info(true) << "Reloading due to change in " << luaFilePath;
	}

	lastModifiedTime = modifiedTime;
	
	Lua* lua = new Lua();
	lua->init();

	if (!lua->runFile(luaFilePath.c_str())) {
		info(true) << "Failed to load file " << luaFilePath;
		delete lua;
		lua = nullptr;
		return false;
	}

	try {
			//Auction
			if (lua->getGlobalInt("serverAuctionMaxBazaarPrice") > 0) serverVars.serverAuctionMaxBazaarPrice = lua->getGlobalInt("serverAuctionMaxBazaarPrice");
			if (lua->getGlobalInt("serverAuctionMaxSales") > 0) serverVars.serverAuctionMaxSales = lua->getGlobalInt("serverAuctionMaxSales");
			if (lua->getGlobalInt("serverAuctionMaxSalesFee") >= 0) serverVars.serverAuctionMaxSalesFee = lua->getGlobalInt("serverAuctionMaxSalesFee");
			if (lua->getGlobalInt("serverAuctionVendorExpirePeriod") > 0) serverVars.serverAuctionVendorExpirePeriod = lua->getGlobalInt("serverAuctionVendorExpirePeriod");
			if (lua->getGlobalInt("serverAuctionCommodityExpirePeriod") > 0) serverVars.serverAuctionCommodityExpirePeriod = lua->getGlobalInt("serverAuctionCommodityExpirePeriod");

			//Command 
			if (lua->getGlobalBoolean("serverCommandCheckForceStatusCommandEnabled") == true || lua->getGlobalBoolean("serverCommandCheckForceStatusCommandEnabled") == false) serverVars.serverCommandCheckForceStatusCommandEnabled = lua->getGlobalBoolean("serverCommandCheckForceStatusCommandEnabled");
			if (lua->getGlobalBoolean("serverCommandMeditateMergeEnabled") == true || lua->getGlobalBoolean("serverCommandMeditateMergeEnabled") == false) serverVars.serverCommandMeditateMergeEnabled = lua->getGlobalBoolean("serverCommandMeditateMergeEnabled");
			if (lua->getGlobalBoolean("serverCommandObjectCreateAttachmentEnabled") == true || lua->getGlobalBoolean("serverCommandObjectCreateAttachmentEnabled") == false) serverVars.serverCommandObjectCreateAttachmentEnabled = lua->getGlobalBoolean("serverCommandObjectCreateAttachmentEnabled");
			if (lua->getGlobalBoolean("serverCommandfsVillageEnabled") == true || lua->getGlobalBoolean("serverCommandfsVillageEnabled") == false) serverVars.serverCommandfsVillageEnabled = lua->getGlobalBoolean("serverCommandfsVillageEnabled");
			if (lua->getGlobalBoolean("serverCommandRegrantSkillsEnabled") == true || lua->getGlobalBoolean("serverCommandRegrantSkillsEnabled") == false) serverVars.serverCommandRegrantSkillsEnabled = lua->getGlobalBoolean("serverCommandRegrantSkillsEnabled");

			//Faction 
			if (lua->getGlobalInt("serverFactionMaxRank") >= 1 && lua->getGlobalInt("serverFactionMaxRank") <= 21) serverVars.serverFactionMaxRank = lua->getGlobalInt("serverFactionMaxRank");
			if (lua->getGlobalFloat("serverFactionCapMultiplier") > 0) serverVars.serverFactionCapMultiplier = lua->getGlobalFloat("serverFactionCapMultiplier");

			//Group
			if (lua->getGlobalInt("serverGroupMaxSize") >= 2) serverVars.serverGroupMaxSize = lua->getGlobalInt("serverGroupMaxSize");
			
			//Player Payments
			if (lua->getGlobalBoolean("serverPaymentCashAndBankEnabled") == true || lua->getGlobalBoolean("serverPaymentCashAndBankEnabled") == false) serverVars.serverPaymentCashAndBankEnabled = lua->getGlobalBoolean("serverPaymentCashAndBankEnabled");

			//Resources 
			if (lua->getGlobalBoolean("serverResourcesAddNameEnabled") == true || lua->getGlobalBoolean("serverResourcesAddNameEnabled") == false) serverVars.serverResourcesAddNameEnabled = lua->getGlobalBoolean("serverResourcesAddNameEnabled");
			if (lua->getGlobalInt("serverResourcesMinimumQuality") >= 0 && lua->getGlobalInt("serverResourcesMinimumQuality") <= lua->getGlobalInt("serverResourcesMaximumQuality")) serverVars.serverResourcesMinimumQuality = lua->getGlobalInt("serverResourcesMinimumQuality");
			if (lua->getGlobalInt("serverResourcesMaximumQuality") <= 1000 && lua->getGlobalInt("serverResourcesMaximumQuality") >= lua->getGlobalInt("serverResourcesMinimumQuality")) serverVars.serverResourcesMaximumQuality = lua->getGlobalInt("serverResourcesMaximumQuality");
			if (lua->getGlobalInt("serverResourcesContainerSize") > 0) serverVars.serverResourcesContainerSize = lua->getGlobalInt("serverResourcesContainerSize");
			if (lua->getGlobalInt("serverResourcesResourceDeedSize") > 0) serverVars.serverResourcesResourceDeedSize = lua->getGlobalInt("serverResourcesResourceDeedSize");
			
			//Server
			if (lua->getGlobalFloat("serverDrawDistance") > 0) serverVars.serverDrawDistance = lua->getGlobalFloat("serverDrawDistance");
			if (lua->getGlobalBoolean("serverPlayersOnlineAtLoginEnabled") == true || lua->getGlobalBoolean("serverPlayersOnlineAtLoginEnabled") == false) serverVars.serverPlayersOnlineAtLoginEnabled = lua->getGlobalBoolean("serverPlayersOnlineAtLoginEnabled");

			//Vendor
			if (lua->getGlobalBoolean("serverVendorLowMaintenanceEmailEnabled") == true || lua->getGlobalBoolean("serverVendorLowMaintenanceEmailEnabled") == false) serverVars.serverVendorLowMaintenanceEmailEnabled = lua->getGlobalBoolean("serverVendorLowMaintenanceEmailEnabled");
			if (lua->getGlobalInt("serverVendorLowMaintenanceEmailWarningThreshold") > 0) serverVars.serverVendorLowMaintenanceEmailWarningThreshold = lua->getGlobalInt("serverVendorLowMaintenanceEmailWarningThreshold");
			if (lua->getGlobalBoolean("serverVendorSkimSalesForMaintenanceEnabled") == true || lua->getGlobalBoolean("serverVendorSkimSalesForMaintenanceEnabled") == false) serverVars.serverVendorSkimSalesForMaintenanceEnabled = lua->getGlobalBoolean("serverVendorSkimSalesForMaintenanceEnabled");
			if (lua->getGlobalFloat("serverVendorSkimSalesForMaintenancePercent") > 0) serverVars.serverVendorSkimSalesForMaintenancePercent = lua->getGlobalFloat("serverVendorSkimSalesForMaintenancePercent");
	} catch (const Exception& e) {
		info(true) << "Error retrieving LUA varaibles: " << e.what();
		return false;
	}

	if (initialLoad) {
		info(true) << "Initial Load Completed.";
	} else{
		info(true) << "Reload Completed.";
	}
	
	delete lua;
	lua = nullptr;

	return true;
}

bool ServerVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t ServerVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void ServerVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

