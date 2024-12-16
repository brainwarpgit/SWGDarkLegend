#ifndef PLAYERVARIABLES_H_
#define PLAYERVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class PlayerVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	PlayerVariables();
	~PlayerVariables();
	void startPlayerVariables();
	//Player
	int playerMaxLots{10};
	bool playerGlobalSafetyDepositEnabled{false};
	float playerShuttleBoardingDistance{25};
	String playerStatMigrationLocation{"tutorial"};
	bool playerStatMigrationSalonOnlyEnabled{false};
	bool playerStatMigrationAnyLocationEnabled{false};
	bool playerStatMigrationClearBuffsEnabled{false};
	int playerWoundsonDeath{100};
	bool playerInsureWeaponsEnabled{false};
	float playerHAMRegenSittingMultiplier{1};
	float playerHAMRegenKneelingMultiplier{1};
	float playerSpeedMultiplier{1};
	int playerMaxLevelNonCHMount{10};
	bool playerAttachmentSplittingEnabled{false};
	int playerAttachmentSplittingCostPerPoint{1000};
	bool playerAttachmentApplicationModEnabled{false};
	bool playerBurstRunToggleEnabled{false};
	int playerBurstRunCoolDownTimer{300};
	int playerBurstRunDuration{30};
	int playerBurstRunHamCost{100};
	float playerBurstRunSpeedAndAccelerationModifier{1.866};
	float playerDefaultRunSpeed{1.866};
	int playerBurstRunHamCostPercent{0};
	bool playerClothingAttachmentSplittingEnabled{false};
	bool playerArmorAttachmentSplittingEnabled{false};
	bool playerWeaponAttachmentSplittingEnabled{false};

	//Player Creation
	int playerCreationNewCreationTime{60};
	bool playerCreationAllLanguagesEnabled{false};
	bool playerCreationJoinGalaxyChatEnabled{false};
	bool playerCreationGrantAllNoviceSkillsEnabled{false};
};

extern PlayerVariables playerVars;

#endif /*PLAYERVARIABLES_H_*/
