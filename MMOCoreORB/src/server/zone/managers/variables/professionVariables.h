#ifndef PROFESSIONVARIABLES_H_
#define PROFESSIONVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class ProfessionVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	ProfessionVariables();
	~ProfessionVariables();
	void startProfessionVariables();
	//Artisan
	float professionArtisanSamplingMultiplier{1};
	float professionArtisanSamplingTime{25};
	bool professionArtisanSamplingMiniGameEnabled{true};
	bool professionArtisanSamplingRadioactiveWarningEnabled{true};
	bool professionArtisanSamplingCriticalEnabled{false};
	float professionArtisanSamplingCriticalMultiplier{1};
	float professionArtisanSamplingLegendaryCriticalMultiplier{1};
	bool professionArtisanSurveyExtendedDistanceEnabled{false};

	//Creature Handler
	int professionCreatureHandlerTamingMaxDistance{8};
	float professionCreatureHandlerTamingCycleTime{10};
	bool professionCreatureHandlerTrainingAlwaysSuccessfulEnabled{false};
	bool professionCreatureHandlerUntrainCreatureMountEnabled{false};
	bool professionCreatureHandlerSetDefaultPetCommandsEnabled{false};

	//Entertainer
	bool professionEntertainerHealsAllWoundsEnabled{false};
	float professionEntertainerWoundHealMultiplier{1};
	bool professionEntertainerBuffDurationCustomEnabled{false};
	float professionEntertainerBuffDuration{130};
	bool professionEntertainerAllBuffsMusicOrDanceEnabled{false};
	bool professionEntertainerBuffSelfEnabled{false};
	bool professionEntertainerInstantBuffEnabled{false};
	bool professionEntertainerBuffAnywhereEnabled{false};

	//Jedi
	bool professionJediForceCostToTuneEnabled{true};
	int professionJediKnightRequirementNumberOfMasters{2};
	float professionJediForceMeditateMultiplier{3};
	bool professionJediForceRunToggleEnabled{false};

	//Medic
	bool professionMedicHealingCriticalEnabled{false};
	float professionMedicHealingCriticalMultiplier{1};
	float professionMedicHealingLegendaryCriticalMultiplier{1};
	bool professionMedicOverwriteBuffEnabled{false};
	bool professionMedicWoundHealingAnywhereEnabled{false};
	bool professionMedicEnhanceHealingAnywhereEnabled{false};
	float professionMedicWoundHealingMultiplier{1};
	float professionMedicEnhanceHealingMultiplier{1};
	float professionMedicDamageHealingMultiplier{1};

	//Ranger
	int professionRangerAreaTrackDistance{512};
	float professionRangerAreaTrackCycleTime{6};
	bool professionRangerAreaTrackHighlightBabyEnabled{false};

	//Smuggler
	bool professionSmugglerNewSliceEnabled{false};
	float professionSmugglerTerminalSliceCooldown{2};
	bool professionSmugglerArmorSliceSocketsEnabled{false};
	bool professionSmugglerArmorPierceSliceEnabled{false};
	bool professionSmugglerWeaponPierceSliceEnabled{false};

	//TKA
	float professionTkaMeditateTickTime{5};
	float professionTkaMeditateHealingMultiplier{1};
	bool professionTkaMeditateFatigueHealingEnabled{false};
	float professionTkaMeditateFatigueHealingAmount{10};

	//Skills
	bool professionSkillsInstantMasterPoliticianEnabled{false};
	bool professionSkillsInstantMasterMerchantEnabled{false};
	bool professionSkillsStartTrainerTrainsAllSkillsEnabled{false};
};

extern ProfessionVariables professionVars;

#endif /*PROFESSIONVARIABLES_H_*/
