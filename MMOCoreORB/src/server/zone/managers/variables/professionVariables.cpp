#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/professionVariables.h"
#include "engine/lua/Lua.h"
#include <sys/stat.h>
#include <thread>
#include <string>

ProfessionVariables professionVars;

ProfessionVariables::ProfessionVariables() : Logger("ProfessionVariables") {}

ProfessionVariables::~ProfessionVariables() {}

void ProfessionVariables::startProfessionVariables() {

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

bool ProfessionVariables::loadConfigData() {
	const std::string luaFilePath = "scripts/managers/variables/profession_variables.lua";

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
		if (lua->getGlobalInt("professionArtisanSamplingMultiplier") > 0) professionVars.professionArtisanSamplingMultiplier = lua->getGlobalInt("professionArtisanSamplingMultiplier");
		if (lua->getGlobalInt("professionArtisanSamplingTime") >= 0) professionVars.professionArtisanSamplingTime = lua->getGlobalInt("professionArtisanSamplingTime");
		if (lua->getGlobalBoolean("professionArtisanSamplingMiniGameEnabled") == true || lua->getGlobalBoolean("professionArtisanSamplingMiniGameEnabled") == false) professionVars.professionArtisanSamplingMiniGameEnabled = lua->getGlobalBoolean("professionArtisanSamplingMiniGameEnabled");
		if (lua->getGlobalBoolean("professionArtisanSamplingRadioactiveWarningEnabled") == true || lua->getGlobalBoolean("professionArtisanSamplingRadioactiveWarningEnabled") == false) professionVars.professionArtisanSamplingRadioactiveWarningEnabled = lua->getGlobalBoolean("professionArtisanSamplingRadioactiveWarningEnabled");
		if (lua->getGlobalBoolean("professionArtisanSamplingCriticalEnabled") == true || lua->getGlobalBoolean("professionArtisanSamplingCriticalEnabled") == false) professionVars.professionArtisanSamplingCriticalEnabled = lua->getGlobalBoolean("professionArtisanSamplingCriticalEnabled");
		if (lua->getGlobalFloat("professionArtisanSamplingCriticalMultiplier") >= 1) professionVars.professionArtisanSamplingCriticalMultiplier = lua->getGlobalFloat("professionArtisanSamplingCriticalMultiplier");
		if (lua->getGlobalFloat("professionArtisanSamplingLegendaryCriticalMultiplier") >= 1) professionVars.professionArtisanSamplingLegendaryCriticalMultiplier = lua->getGlobalFloat("professionArtisanSamplingLegendaryCriticalMultiplier");
		if (lua->getGlobalBoolean("professionArtisanSurveyExtendedDistanceEnabled") == true || lua->getGlobalBoolean("professionArtisanSurveyExtendedDistanceEnabled") == false) professionVars.professionArtisanSurveyExtendedDistanceEnabled = lua->getGlobalBoolean("professionArtisanSurveyExtendedDistanceEnabled");

		//Creature Handler 
		if (lua->getGlobalInt("professionCreatureHandlerTamingMaxDistance") > 0) professionVars.professionCreatureHandlerTamingMaxDistance = lua->getGlobalInt("professionCreatureHandlerTamingMaxDistance");
		if (lua->getGlobalFloat("professionCreatureHandlerTamingCycleTime") > 0) professionVars.professionCreatureHandlerTamingCycleTime = lua->getGlobalFloat("professionCreatureHandlerTamingCycleTime");
		if (lua->getGlobalBoolean("professionCreatureHandlerTrainingAlwaysSuccessfulEnabled") == true || lua->getGlobalBoolean("professionCreatureHandlerTrainingAlwaysSuccessfulEnabled") == false) professionVars.professionCreatureHandlerTrainingAlwaysSuccessfulEnabled = lua->getGlobalBoolean("professionCreatureHandlerTrainingAlwaysSuccessfulEnabled");
		if (lua->getGlobalBoolean("professionCreatureHandlerUntrainCreatureMountEnabled") == true || lua->getGlobalBoolean("professionCreatureHandlerUntrainCreatureMountEnabled") == false) professionVars.professionCreatureHandlerUntrainCreatureMountEnabled = lua->getGlobalBoolean("professionCreatureHandlerUntrainCreatureMountEnabled");
		if (lua->getGlobalBoolean("professionCreatureHandlerSetDefaultPetCommandsEnabled") == true || lua->getGlobalBoolean("professionCreatureHandlerSetDefaultPetCommandsEnabled") == false) professionVars.professionCreatureHandlerSetDefaultPetCommandsEnabled = lua->getGlobalBoolean("professionCreatureHandlerSetDefaultPetCommandsEnabled");

		//Entertainer
		if (lua->getGlobalBoolean("professionEntertainerHealsAllWoundsEnabled") == true || lua->getGlobalBoolean("professionEntertainerHealsAllWoundsEnabled") == false) professionVars.professionEntertainerHealsAllWoundsEnabled = lua->getGlobalBoolean("professionEntertainerHealsAllWoundsEnabled");
		if (lua->getGlobalFloat("professionEntertainerWoundHealMultiplier") >= 0) professionVars.professionEntertainerWoundHealMultiplier = lua->getGlobalFloat("professionEntertainerWoundHealMultiplier");
		if (lua->getGlobalBoolean("professionEntertainerBuffDurationCustomEnabled") == true || lua->getGlobalBoolean("professionEntertainerBuffDurationCustomEnabled") == false) professionVars.professionEntertainerBuffDurationCustomEnabled = lua->getGlobalBoolean("professionEntertainerBuffDurationCustomEnabled");
		if (lua->getGlobalFloat("professionEntertainerBuffDuration") >= 0) professionVars.professionEntertainerBuffDuration = lua->getGlobalFloat("professionEntertainerBuffDuration");
		if (lua->getGlobalBoolean("professionEntertainerAllBuffsMusicOrDanceEnabled") == true || lua->getGlobalBoolean("professionEntertainerAllBuffsMusicOrDanceEnabled") == false) professionVars.professionEntertainerAllBuffsMusicOrDanceEnabled = lua->getGlobalBoolean("professionEntertainerAllBuffsMusicOrDanceEnabled");
		if (lua->getGlobalBoolean("professionEntertainerBuffSelfEnabled") == true || lua->getGlobalBoolean("professionEntertainerBuffSelfEnabled") == false) professionVars.professionEntertainerBuffSelfEnabled = lua->getGlobalBoolean("professionEntertainerBuffSelfEnabled");
		if (lua->getGlobalBoolean("professionEntertainerInstantBuffEnabled") == true || lua->getGlobalBoolean("professionEntertainerInstantBuffEnabled") == false) professionVars.professionEntertainerInstantBuffEnabled = lua->getGlobalBoolean("professionEntertainerInstantBuffEnabled");
		if (lua->getGlobalBoolean("professionEntertainerBuffAnywhereEnabled") == true || lua->getGlobalBoolean("professionEntertainerBuffAnywhereEnabled") == false) professionVars.professionEntertainerBuffAnywhereEnabled = lua->getGlobalBoolean("professionEntertainerBuffAnywhereEnabled");

		//Jedi 
		if (lua->getGlobalBoolean("professionJediForceCostToTuneEnabled") == true || lua->getGlobalBoolean("professionJediForceCostToTuneEnabled") == false) professionVars.professionJediForceCostToTuneEnabled = lua->getGlobalBoolean("professionJediForceCostToTuneEnabled");
		if (lua->getGlobalInt("professionJediKnightRequirementNumberOfMasters") >= 0) professionVars.professionJediKnightRequirementNumberOfMasters = lua->getGlobalInt("professionJediKnightRequirementNumberOfMasters");
		if (lua->getGlobalFloat("professionJediForceMeditateMultiplier") >= 0) professionVars.professionJediForceMeditateMultiplier = lua->getGlobalFloat("professionJediForceMeditateMultiplier");
		if (lua->getGlobalBoolean("professionJediForceRunToggleEnabled") == true || lua->getGlobalBoolean("professionJediForceRunToggleEnabled") == false) professionVars.professionJediForceRunToggleEnabled = lua->getGlobalBoolean("professionJediForceRunToggleEnabled");

		//Medic
		if (lua->getGlobalBoolean("professionMedicOverwriteBuffEnabled") == true || lua->getGlobalBoolean("professionMedicOverwriteBuffEnabled") == false) professionVars.professionMedicOverwriteBuffEnabled = lua->getGlobalBoolean("professionMedicOverwriteBuffEnabled");
		if (lua->getGlobalBoolean("professionMedicWoundHealingAnywhereEnabled") == true || lua->getGlobalBoolean("professionMedicWoundHealingAnywhereEnabled") == false) professionVars.professionMedicWoundHealingAnywhereEnabled = lua->getGlobalBoolean("professionMedicWoundHealingAnywhereEnabled");
		if (lua->getGlobalBoolean("professionMedicEnhanceHealingAnywhereEnabled") == true || lua->getGlobalBoolean("professionMedicEnhanceHealingAnywhereEnabled") == false) professionVars.professionMedicEnhanceHealingAnywhereEnabled = lua->getGlobalBoolean("professionMedicEnhanceHealingAnywhereEnabled");
		if (lua->getGlobalInt("professionMedicWoundHealingMultiplier") > 0) professionVars.professionMedicWoundHealingMultiplier = lua->getGlobalInt("professionMedicWoundHealingMultiplier");
		if (lua->getGlobalInt("professionMedicEnhanceHealingMultiplier") > 0) professionVars.professionMedicEnhanceHealingMultiplier = lua->getGlobalInt("professionMedicEnhanceHealingMultiplier");
		if (lua->getGlobalInt("professionMedicDamageHealingMultiplier") > 0) professionVars.professionMedicDamageHealingMultiplier = lua->getGlobalInt("professionMedicDamageHealingMultiplier");			
		if (lua->getGlobalBoolean("professionMedicHealingCriticalEnabled") == true || lua->getGlobalBoolean("professionMedicHealingCriticalEnabled") == false) professionVars.professionMedicHealingCriticalEnabled = lua->getGlobalBoolean("professionMedicHealingCriticalEnabled");
		if (lua->getGlobalFloat("professionMedicHealingCriticalMultiplier") >= 1) professionVars.professionMedicHealingCriticalMultiplier = lua->getGlobalFloat("professionMedicHealingCriticalMultiplier");
		if (lua->getGlobalFloat("professionMedicHealingLegendaryCriticalMultiplier") >= 1) professionVars.professionMedicHealingLegendaryCriticalMultiplier = lua->getGlobalFloat("professionMedicHealingLegendaryCriticalMultiplier");

		//Ranger
		if (lua->getGlobalInt("professionRangerAreaTrackDistance") > 0) professionVars.professionRangerAreaTrackDistance = lua->getGlobalInt("professionRangerAreaTrackDistance");
		if (lua->getGlobalFloat("professionRangerAreaTrackCycleTime") >= 0) professionVars.professionRangerAreaTrackCycleTime = lua->getGlobalFloat("professionRangerAreaTrackCycleTime");
		if (lua->getGlobalBoolean("professionRangerAreaTrackHighlightBabyEnabled") == true || lua->getGlobalBoolean("professionRangerAreaTrackHighlightBabyEnabled") == false) professionVars.professionRangerAreaTrackHighlightBabyEnabled = lua->getGlobalBoolean("professionRangerAreaTrackHighlightBabyEnabled");

		//Slicing
		if (lua->getGlobalBoolean("professionSmugglerNewSliceEnabled") == true || lua->getGlobalBoolean("professionSmugglerNewSliceEnabled") == false) professionVars.professionSmugglerNewSliceEnabled = lua->getGlobalBoolean("professionSmugglerNewSliceEnabled");
		if (lua->getGlobalFloat("professionSmugglerTerminalSliceCooldown") >= 0) professionVars.professionSmugglerTerminalSliceCooldown = lua->getGlobalFloat("professionSmugglerTerminalSliceCooldown");
		if (lua->getGlobalBoolean("professionSmugglerArmorSliceSocketsEnabled") == true || lua->getGlobalBoolean("professionSmugglerArmorSliceSocketsEnabled") == false) professionVars.professionSmugglerArmorSliceSocketsEnabled = lua->getGlobalBoolean("professionSmugglerArmorSliceSocketsEnabled");
		if (lua->getGlobalBoolean("professionSmugglerArmorPierceSliceEnabled") == true || lua->getGlobalBoolean("professionSmugglerArmorPierceSliceEnabled") == false) professionVars.professionSmugglerArmorPierceSliceEnabled = lua->getGlobalBoolean("professionSmugglerArmorPierceSliceEnabled");
		if (lua->getGlobalBoolean("professionSmugglerWeaponPierceSliceEnabled") == true || lua->getGlobalBoolean("professionSmugglerWeaponPierceSliceEnabled") == false) professionVars.professionSmugglerWeaponPierceSliceEnabled = lua->getGlobalBoolean("professionSmugglerWeaponPierceSliceEnabled");

		//TKA
		if (lua->getGlobalFloat("professionTkaMeditateHealingMultiplier") >= 0) professionVars.professionTkaMeditateHealingMultiplier = lua->getGlobalFloat("professionTkaMeditateHealingMultiplier");
		if (lua->getGlobalBoolean("professionTkaMeditateFatigueHealingEnabled") == true || lua->getGlobalBoolean("professionTkaMeditateFatigueHealingEnabled") == false) professionVars.professionTkaMeditateFatigueHealingEnabled = lua->getGlobalBoolean("professionTkaMeditateFatigueHealingEnabled");
		if (lua->getGlobalInt("professionTkaMeditateFatigueHealingAmount") > 0) professionVars.professionTkaMeditateFatigueHealingAmount = lua->getGlobalInt("professionTkaMeditateFatigueHealingAmount");			
		if (lua->getGlobalFloat("professionTkaMeditateTickTime") >= 0) professionVars.professionTkaMeditateTickTime = lua->getGlobalFloat("professionTkaMeditateTickTime");

		//Skills
		if (lua->getGlobalBoolean("professionSkillsInstantMasterPoliticianEnabled") == true || lua->getGlobalBoolean("professionSkillsInstantMasterPoliticianEnabled") == false) professionVars.professionSkillsInstantMasterPoliticianEnabled = lua->getGlobalBoolean("professionSkillsInstantMasterPoliticianEnabled");
		if (lua->getGlobalBoolean("professionSkillsInstantMasterMerchantEnabled") == true || lua->getGlobalBoolean("professionSkillsInstantMasterMerchantEnabled") == false) professionVars.professionSkillsInstantMasterMerchantEnabled = lua->getGlobalBoolean("professionSkillsInstantMasterMerchantEnabled");
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

bool ProfessionVariables::fileExists(const std::string& filePath) {
	return (access(filePath.c_str(), F_OK) != -1);
}

time_t ProfessionVariables::getFileModifiedTime(const std::string& filePath) {
	struct stat fileInfo;
	if (stat(filePath.c_str(), &fileInfo) != 0) {
		info(true) << "Error getting file status for: " << filePath;
		return 0;
	}
	return fileInfo.st_mtime;
}

void ProfessionVariables::startWatching(const std::function<void()>& loadConfigFunction) {
	while (!varWatch.stopWatch) {
		std::this_thread::sleep_for(std::chrono::seconds(varWatch.threadReloadTime));
		loadConfigData();
	}
	info(true) << "Stopping Variable Watcher.";
}

