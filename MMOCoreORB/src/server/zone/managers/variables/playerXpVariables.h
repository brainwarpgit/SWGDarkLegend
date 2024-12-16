#ifndef PLAYERXPVARIABLES_H_
#define PLAYERXPVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PlayerXpVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PlayerXpVariables();
	~PlayerXpVariables();
	void startPlayerXpVariables();
	//Player XP
	bool playerXpForagingXPEnabled{false};
	bool playerXpMilkingXPEnabled{false};
	bool playerXpAwardPetHealingXPEnabled{false};
	bool playerXpAwardSelfHealingXPEnabled{false};
	bool playerXpAwardXPWeaponSplitEnabled{false};
	float playerXpDNASamplingXPMultiplier{1};
	float playerXpBountyHunterXPMultiplier{1};
	float playerXpWildernessSurvivalXPMultiplier{1};
	float playerXpCombatXPMultiplier{0.1};
	float playerXpOnehandedWeaponsXPMultiplier{1};
	float playerXpPolearmWeaponsXPMultiplier{1};
	float playerXpTwohandedWeaponsXPMultiplier{1};
	float playerXpUnarmedCombatXPMultiplier{1};
	float playerXpCarbineWeaponsXPMultiplier{1};
	float playerXpHeavyWeaponsXPMultiplier{1};
	float playerXpPistolWeaponsXPMultiplier{1};
	float playerXpRifleWeaponsXPMultiplier{1};
	float playerXpBioEngineerCraftingXPMultiplier{1};
	float playerXpArmorCraftingXPMultiplier{1};
	float playerXpTailoringXPMultiplier{1};
	float playerXpDroidCraftingXPMultiplier{1};
	float playerXpFoodCraftingXPMultiplier{1};
	float playerXpGeneralCraftingXPMultiplier{1};
	float playerXpMedicineCraftingXPMultiplier{1};
	float playerXpSpiceCraftingXPMultiplier{1};
	float playerXpStructureCraftingXPMultiplier{1};
	float playerXpWeaponCraftingXPMultiplier{1};
	float playerXpCreatureHandlingXPMultiplier{1};
	float playerXpDancingXPMultiplier{1};
	float playerXpEntertainerHealingXPMultiplier{1};
	float playerXpImageDesignerXPMultiplier{1};
	float playerXpJediXPMultiplier{0.2};
	float playerXpMedicalXPMultiplier{1};
	float playerXpMerchantXPMultiplier{1};
	float playerXpMusicianXPMultiplier{1};
	float playerXpPoliticalXPMultiplier{1};
	float playerXpSurveyingXPMultiplier{1};
	float playerXpScoutingXPMultiplier{1};
	float playerXpShipwrightXPMultiplier{1};
	float playerXpSlicingXPMultiplier{1};
	float playerXpStarshipCombatXPMultiplier{1};
	float playerXpSquadLeadershipXPMultiplier{1};
	float playerXpTrappingXPMultiplier{1};
	int playerXpJediNegativeXPCap{-10000000};
	bool playerXpJediAwardedCombatXPEnabled{false};
	bool playerXpJediPvEForceRankXPEnabled{false};
	float playerXpJediForceRankXPMultiplier{0.05};
	float playerXpMeditateGrantsHealingXPEnabled{1};
	bool playerXpXPBasedOnLevelEnabled{true};
	bool playerXpCHXPModEnabled{false};
	bool playerXpCHCombatXPEnabled{false};
	float playerXpCraftingPracticeXPMultiplier{1.05};
	bool playerXpJediXPLossEnabled{true};
};

extern PlayerXpVariables playerXpVars;

#endif /*PLAYERXPVARIABLES_H_*/
