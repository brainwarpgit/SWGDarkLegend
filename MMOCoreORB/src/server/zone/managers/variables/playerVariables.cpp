#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/playerVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

PlayerVariables playerVars;

PlayerVariables::PlayerVariables() : Logger("PlayerVariables") {}

PlayerVariables::~PlayerVariables() {}

void PlayerVariables::startPlayerVariables() {

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

bool PlayerVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/player_variables.lua";

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
		//Player 
		if (lua->getGlobalInt("playerMaxLots") > 0) playerVars.playerMaxLots = lua->getGlobalInt("playerMaxLots");
		if (lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled") == true || lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled") == false) playerVars.playerGlobalSafetyDepositEnabled = lua->getGlobalBoolean("playerGlobalSafetyDepositEnabled");
		if (lua->getGlobalFloat("playerShuttleBoardingDistance") > 0) playerVars.playerShuttleBoardingDistance = lua->getGlobalFloat("playerShuttleBoardingDistance");
		if (lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "tutorial" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dungeon1" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "yavin4" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dantooine" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "dathomir" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "endor" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase()   == "lok" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "rori" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "talus" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "naboo" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "corellia" || lua->getGlobalString("playerStatMigrationLocation").toLowerCase() == "tatooine") playerVars.playerStatMigrationLocation = lua->getGlobalString("playerStatMigrationLocation").toLowerCase();
		if (lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled") == true || lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled") == false) playerVars.playerStatMigrationSalonOnlyEnabled = lua->getGlobalBoolean("playerStatMigrationSalonOnlyEnabled");
		if (lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled") == true || lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled") == false) playerVars.playerStatMigrationAnyLocationEnabled = lua->getGlobalBoolean("playerStatMigrationAnyLocationEnabled");
		if (lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled") == true || lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled") == false) playerVars.playerStatMigrationClearBuffsEnabled = lua->getGlobalBoolean("playerStatMigrationClearBuffsEnabled");
		if (lua->getGlobalInt("playerWoundsonDeath") >= 0) playerVars.playerWoundsonDeath = lua->getGlobalInt("playerWoundsonDeath");
		if (lua->getGlobalBoolean("playerInsureWeaponsEnabled") == true || lua->getGlobalBoolean("playerInsureWeaponsEnabled") == false) playerVars.playerInsureWeaponsEnabled = lua->getGlobalBoolean("playerInsureWeaponsEnabled");
		if (lua->getGlobalFloat("playerHAMRegenSittingMultiplier") >= 0) playerVars.playerHAMRegenSittingMultiplier = lua->getGlobalFloat("playerHAMRegenSittingMultiplier");
		if (lua->getGlobalFloat("playerHAMRegenKneelingMultiplier") >= 0) playerVars.playerHAMRegenKneelingMultiplier = lua->getGlobalFloat("playerHAMRegenKneelingMultiplier");
		if (lua->getGlobalFloat("playerSpeedMultiplier") >= 1) playerVars.playerSpeedMultiplier = lua->getGlobalFloat("playerSpeedMultiplier");
		if (lua->getGlobalInt("playerMaxLevelNonCHMount") >= 1) playerVars.playerMaxLevelNonCHMount = lua->getGlobalInt("playerMaxLevelNonCHMount");
		if (lua->getGlobalBoolean("playerAttachmentSplittingEnabled") == true || lua->getGlobalBoolean("playerAttachmentSplittingEnabled") == false) playerVars.playerAttachmentSplittingEnabled = lua->getGlobalBoolean("playerAttachmentSplittingEnabled");
		if (lua->getGlobalInt("playerAttachmentSplittingCostPerPoint") >= 1) playerVars.playerAttachmentSplittingCostPerPoint = lua->getGlobalInt("playerAttachmentSplittingCostPerPoint");
		if (lua->getGlobalBoolean("playerAttachmentApplicationModEnabled") == true || lua->getGlobalBoolean("playerAttachmentApplicationModEnabled") == false) playerVars.playerAttachmentApplicationModEnabled = lua->getGlobalBoolean("playerAttachmentApplicationModEnabled");
		if (lua->getGlobalBoolean("playerBurstRunToggleEnabled") == true || lua->getGlobalBoolean("playerBurstRunToggleEnabled") == false) playerVars.playerBurstRunToggleEnabled = lua->getGlobalBoolean("playerBurstRunToggleEnabled");
		if (lua->getGlobalFloat("playerBurstRunCoolDownTimer") >= 0) playerVars.playerBurstRunCoolDownTimer = lua->getGlobalFloat("playerBurstRunCoolDownTimer");
		if (lua->getGlobalFloat("playerBurstRunDuration") >= 0) playerVars.playerBurstRunDuration = lua->getGlobalFloat("playerBurstRunDuration");
		if (lua->getGlobalFloat("playerBurstRunHamCost") >= 0) playerVars.playerBurstRunHamCost = lua->getGlobalFloat("playerBurstRunHamCost");
		if (lua->getGlobalFloat("playerBurstRunHamCostPercent") >= 0 && lua->getGlobalFloat("playerBurstRunHamCostPercent") <= 100) playerVars.playerBurstRunHamCostPercent = lua->getGlobalFloat("playerBurstRunHamCostPercent");
		if (lua->getGlobalFloat("playerBurstRunSpeedAndAccelerationModifier") >= 0) playerVars.playerBurstRunSpeedAndAccelerationModifier = lua->getGlobalFloat("playerBurstRunSpeedAndAccelerationModifier");
		if (lua->getGlobalFloat("playerDefaultRunSpeed") >= 0) playerVars.playerDefaultRunSpeed = lua->getGlobalFloat("playerDefaultRunSpeed");
		if (lua->getGlobalBoolean("playerClothingAttachmentSplittingEnabled") == true || lua->getGlobalBoolean("playerClothingAttachmentSplittingEnabled") == false) playerVars.playerClothingAttachmentSplittingEnabled = lua->getGlobalBoolean("playerClothingAttachmentSplittingEnabled");
		if (lua->getGlobalBoolean("playerArmorAttachmentSplittingEnabled") == true || lua->getGlobalBoolean("playerArmorAttachmentSplittingEnabled") == false) playerVars.playerArmorAttachmentSplittingEnabled = lua->getGlobalBoolean("playerArmorAttachmentSplittingEnabled");
		if (lua->getGlobalBoolean("playerWeaponAttachmentSplittingEnabled") == true || lua->getGlobalBoolean("playerWeaponAttachmentSplittingEnabled") == false) playerVars.playerWeaponAttachmentSplittingEnabled = lua->getGlobalBoolean("playerWeaponAttachmentSplittingEnabled");

		//Player Creation 
		if (lua->getGlobalInt("playerCreationNewCreationTime") >= 0) playerVars.playerCreationNewCreationTime = lua->getGlobalInt("playerCreationNewCreationTime");
		if (lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == true || lua->getGlobalBoolean("playerCreationAllLanguagesEnabled") == false) playerVars.playerCreationAllLanguagesEnabled = lua->getGlobalBoolean("playerCreationAllLanguagesEnabled");
		if (lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == true || lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled") == false) playerVars.playerCreationJoinGalaxyChatEnabled = lua->getGlobalBoolean("playerCreationJoinGalaxyChatEnabled");
		if (lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled") == true || lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled") == false) playerVars.playerCreationGrantAllNoviceSkillsEnabled = lua->getGlobalBoolean("playerCreationGrantAllNoviceSkillsEnabled");
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

bool PlayerVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t PlayerVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void PlayerVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

