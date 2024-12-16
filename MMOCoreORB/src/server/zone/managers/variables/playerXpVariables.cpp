#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/playerXpVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

PlayerXpVariables playerXpVars;

PlayerXpVariables::PlayerXpVariables() : Logger("PlayerXpVariables") {}

PlayerXpVariables::~PlayerXpVariables() {}

void PlayerXpVariables::startPlayerXpVariables() {

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

bool PlayerXpVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/playerxp_variables.lua";

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
		//Player XP 
		if (lua->getGlobalBoolean("playerXpForagingXPEnabled") == true || lua->getGlobalBoolean("playerXpForagingXPEnabled") == false) playerXpVars.playerXpForagingXPEnabled = lua->getGlobalBoolean("playerXpForagingXPEnabled");
		if (lua->getGlobalBoolean("playerXpMilkingXPEnabled") == true || lua->getGlobalBoolean("playerXpMilkingXPEnabled") == false) playerXpVars.playerXpMilkingXPEnabled = lua->getGlobalBoolean("playerXpMilkingXPEnabled");
		if (lua->getGlobalBoolean("playerXpAwardSelfHealingXPEnabled") == true || lua->getGlobalBoolean("playerXpAwardSelfHealingXPEnabled") == false) playerXpVars.playerXpAwardSelfHealingXPEnabled = lua->getGlobalBoolean("playerXpAwardSelfHealingXPEnabled");
		if (lua->getGlobalBoolean("playerXpAwardPetHealingXPEnabled") == true || lua->getGlobalBoolean("playerXpAwardPetHealingXPEnabled") == false) playerXpVars.playerXpAwardPetHealingXPEnabled = lua->getGlobalBoolean("playerXpAwardPetHealingXPEnabled");
		if (lua->getGlobalBoolean("playerXpAwardXPWeaponSplitEnabled") == true || lua->getGlobalBoolean("playerXpAwardXPWeaponSplitEnabled") == false) playerXpVars.playerXpAwardXPWeaponSplitEnabled = lua->getGlobalBoolean("playerXpAwardXPWeaponSplitEnabled");
		if (lua->getGlobalFloat("playerXpDNASamplingXPMultiplier") > 0) playerXpVars.playerXpDNASamplingXPMultiplier = lua->getGlobalFloat("playerXpDNASamplingXPMultiplier");
		if (lua->getGlobalFloat("playerXpBountyHunterXPMultiplier") > 0) playerXpVars.playerXpBountyHunterXPMultiplier = lua->getGlobalFloat("playerXpBountyHunterXPMultiplier");
		if (lua->getGlobalFloat("playerXpWildernessSurvivalXPMultiplier") > 0) playerXpVars.playerXpWildernessSurvivalXPMultiplier = lua->getGlobalFloat("playerXpWildernessSurvivalXPMultiplier");
		if (lua->getGlobalFloat("playerXpCombatXPMultiplier") > 0) playerXpVars.playerXpCombatXPMultiplier = lua->getGlobalFloat("playerXpCombatXPMultiplier");
		if (lua->getGlobalFloat("playerXpOnehandedWeaponsXPMultiplier") > 0) playerXpVars.playerXpOnehandedWeaponsXPMultiplier = lua->getGlobalFloat("playerXpOnehandedWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpPolearmWeaponsXPMultiplier") > 0) playerXpVars.playerXpPolearmWeaponsXPMultiplier = lua->getGlobalFloat("playerXpPolearmWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpTwohandedWeaponsXPMultiplier") > 0) playerXpVars.playerXpTwohandedWeaponsXPMultiplier = lua->getGlobalFloat("playerXpTwohandedWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpUnarmedCombatXPMultiplier") > 0) playerXpVars.playerXpUnarmedCombatXPMultiplier = lua->getGlobalFloat("playerXpUnarmedCombatXPMultiplier");
		if (lua->getGlobalFloat("playerXpCarbineWeaponsXPMultiplier") > 0) playerXpVars.playerXpCarbineWeaponsXPMultiplier = lua->getGlobalFloat("playerXpCarbineWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpHeavyWeaponsXPMultiplier") > 0) playerXpVars.playerXpHeavyWeaponsXPMultiplier = lua->getGlobalFloat("playerXpHeavyWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpPistolWeaponsXPMultiplier") > 0) playerXpVars.playerXpPistolWeaponsXPMultiplier = lua->getGlobalFloat("playerXpPistolWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpRifleWeaponsXPMultiplier") > 0) playerXpVars.playerXpRifleWeaponsXPMultiplier = lua->getGlobalFloat("playerXpRifleWeaponsXPMultiplier");
		if (lua->getGlobalFloat("playerXpBioEngineerCraftingXPMultiplier") > 0) playerXpVars.playerXpBioEngineerCraftingXPMultiplier = lua->getGlobalFloat("playerXpBioEngineerCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpArmorCraftingXPMultiplier") > 0) playerXpVars.playerXpArmorCraftingXPMultiplier = lua->getGlobalFloat("playerXpArmorCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpTailoringXPMultiplier") > 0) playerXpVars.playerXpTailoringXPMultiplier = lua->getGlobalFloat("playerXpTailoringXPMultiplier");
		if (lua->getGlobalFloat("playerXpDroidCraftingXPMultiplier") > 0) playerXpVars.playerXpDroidCraftingXPMultiplier = lua->getGlobalFloat("playerXpDroidCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpFoodCraftingXPMultiplier") > 0) playerXpVars.playerXpFoodCraftingXPMultiplier = lua->getGlobalFloat("playerXpFoodCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpGeneralCraftingXPMultiplier") > 0) playerXpVars.playerXpGeneralCraftingXPMultiplier = lua->getGlobalFloat("playerXpGeneralCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpMedicineCraftingXPMultiplier") > 0) playerXpVars.playerXpMedicineCraftingXPMultiplier = lua->getGlobalFloat("playerXpMedicineCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpSpiceCraftingXPMultiplier") > 0) playerXpVars.playerXpSpiceCraftingXPMultiplier = lua->getGlobalFloat("playerXpSpiceCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpStructureCraftingXPMultiplier") > 0) playerXpVars.playerXpStructureCraftingXPMultiplier = lua->getGlobalFloat("playerXpStructureCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpWeaponCraftingXPMultiplier") > 0) playerXpVars.playerXpWeaponCraftingXPMultiplier = lua->getGlobalFloat("playerXpWeaponCraftingXPMultiplier");
		if (lua->getGlobalFloat("playerXpCreatureHandlingXPMultiplier") > 0) playerXpVars.playerXpCreatureHandlingXPMultiplier = lua->getGlobalFloat("playerXpCreatureHandlingXPMultiplier");
		if (lua->getGlobalFloat("playerXpDancingXPMultiplier") > 0) playerXpVars.playerXpDancingXPMultiplier = lua->getGlobalFloat("playerXpDancingXPMultiplier");
		if (lua->getGlobalFloat("playerXpEntertainerHealingXPMultiplier") > 0) playerXpVars.playerXpEntertainerHealingXPMultiplier = lua->getGlobalFloat("playerXpEntertainerHealingXPMultiplier");
		if (lua->getGlobalFloat("playerXpImageDesignerXPMultiplier") > 0) playerXpVars.playerXpImageDesignerXPMultiplier = lua->getGlobalFloat("playerXpImageDesignerXPMultiplier");
		if (lua->getGlobalFloat("playerXpJediXPMultiplier") > 0) playerXpVars.playerXpJediXPMultiplier = lua->getGlobalFloat("playerXpJediXPMultiplier");
		if (lua->getGlobalFloat("playerXpMedicalXPMultiplier") > 0) playerXpVars.playerXpMedicalXPMultiplier = lua->getGlobalFloat("playerXpMedicalXPMultiplier");
		if (lua->getGlobalFloat("playerXpMerchantXPMultiplier") > 0) playerXpVars.playerXpMerchantXPMultiplier = lua->getGlobalFloat("playerXpMerchantXPMultiplier");
		if (lua->getGlobalFloat("playerXpMusicianXPMultiplier") > 0) playerXpVars.playerXpMusicianXPMultiplier = lua->getGlobalFloat("playerXpMusicianXPMultiplier");
		if (lua->getGlobalFloat("playerXpPoliticalXPMultiplier") > 0) playerXpVars.playerXpPoliticalXPMultiplier = lua->getGlobalFloat("playerXpPoliticalXPMultiplier");
		if (lua->getGlobalFloat("playerXpSurveyingXPMultiplier") > 0) playerXpVars.playerXpSurveyingXPMultiplier = lua->getGlobalFloat("playerXpSurveyingXPMultiplier");
		if (lua->getGlobalFloat("playerXpScoutingXPMultiplier") > 0) playerXpVars.playerXpScoutingXPMultiplier = lua->getGlobalFloat("playerXpScoutingXPMultiplier");
		if (lua->getGlobalFloat("playerXpShipwrightXPMultiplier") > 0) playerXpVars.playerXpShipwrightXPMultiplier = lua->getGlobalFloat("playerXpShipwrightXPMultiplier");
		if (lua->getGlobalFloat("playerXpSlicingXPMultiplier") > 0) playerXpVars.playerXpSlicingXPMultiplier = lua->getGlobalFloat("playerXpSlicingXPMultiplier");
		if (lua->getGlobalFloat("playerXpStarshipCombatXPMultiplier") > 0) playerXpVars.playerXpStarshipCombatXPMultiplier = lua->getGlobalFloat("playerXpStarshipCombatXPMultiplier");
		if (lua->getGlobalFloat("playerXpSquadLeadershipXPMultiplier") > 0) playerXpVars.playerXpSquadLeadershipXPMultiplier = lua->getGlobalFloat("playerXpSquadLeadershipXPMultiplier");
		if (lua->getGlobalFloat("playerXpTrappingXPMultiplier") > 0) playerXpVars.playerXpTrappingXPMultiplier = lua->getGlobalFloat("playerXpTrappingXPMultiplier");
		if (lua->getGlobalInt("playerXpJediNegativeXPCap") <= 0 && lua->getGlobalInt("playerXpJediNegativeXPCap") >= 0) playerXpVars.playerXpJediNegativeXPCap = lua->getGlobalInt("playerXpJediNegativeXPCap");
		if (lua->getGlobalBoolean("playerXpJediAwardedCombatXPEnabled") == true || lua->getGlobalBoolean("playerXpJediAwardedCombatXPEnabled") == false) playerXpVars.playerXpJediAwardedCombatXPEnabled = lua->getGlobalBoolean("playerXpJediAwardedCombatXPEnabled");
		if (lua->getGlobalBoolean("playerXpJediPvEForceRankXPEnabled") == true || lua->getGlobalBoolean("playerXpJediPvEForceRankXPEnabled") == false) playerXpVars.playerXpJediPvEForceRankXPEnabled = lua->getGlobalBoolean("playerXpJediPvEForceRankXPEnabled");
		if (lua->getGlobalFloat("playerXpJediForceRankXPMultiplier") > 0) playerXpVars.playerXpJediForceRankXPMultiplier = lua->getGlobalFloat("playerXpJediForceRankXPMultiplier");
		if (lua->getGlobalBoolean("playerXpMeditateGrantsHealingXPEnabled") == true || lua->getGlobalBoolean("playerXpMeditateGrantsHealingXPEnabled") == false) playerXpVars.playerXpMeditateGrantsHealingXPEnabled = lua->getGlobalBoolean("playerXpMeditateGrantsHealingXPEnabled");
		if (lua->getGlobalBoolean("playerXpXPBasedOnLevelEnabled") == true || lua->getGlobalBoolean("playerXpXPBasedOnLevelEnabled") == false) playerXpVars.playerXpXPBasedOnLevelEnabled = lua->getGlobalBoolean("playerXpXPBasedOnLevelEnabled");
		if (lua->getGlobalBoolean("playerXpCHXPModEnabled") == true || lua->getGlobalBoolean("playerXpCHXPModEnabled") == false) playerXpVars.playerXpCHXPModEnabled = lua->getGlobalBoolean("playerXpCHXPModEnabled");
		if (lua->getGlobalBoolean("playerXpCHCombatXPEnabled") == true || lua->getGlobalBoolean("playerXpCHCombatXPEnabled") == false) playerXpVars.playerXpCHCombatXPEnabled = lua->getGlobalBoolean("playerXpCHCombatXPEnabled");
		if (lua->getGlobalFloat("playerXpCraftingPracticeXPMultiplier") >= 0) playerXpVars.playerXpCraftingPracticeXPMultiplier = lua->getGlobalFloat("playerXpCraftingPracticeXPMultiplier");
		if (lua->getGlobalBoolean("playerXpJediXPLossEnabled") == true || lua->getGlobalBoolean("playerXpJediXPLossEnabled") == false) playerXpVars.playerXpJediXPLossEnabled = lua->getGlobalBoolean("playerXpJediXPLossEnabled");
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

bool PlayerXpVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t PlayerXpVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void PlayerXpVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

