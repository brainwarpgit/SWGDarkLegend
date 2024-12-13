#ifndef COMBATVARIABLES_H_
#define COMBATVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CombatVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CombatVariables();
	~CombatVariables();
	void startCombatVariables();
	//Combat
	float combatDamageMeleeWeaponMultiplier{1};
	float combatDamageUnarmedWeaponMultiplier{1};
	float combatDamageOneHandWeaponMultiplier{1};
	float combatDamageTwoHandWeaponMultiplier{1};
	float combatDamagePolearmWeaponMultiplier{1};
	float combatDamageRangedWeaponMultiplier{1};
	float combatDamagePistolWeaponMultiplier{1};
	float combatDamageCarbineWeaponMultiplier{1};
	float combatDamageRifleWeaponMultiplier{1};
	float combatDamageThrownWeaponMultiplier{1};
	float combatDamageHeavyWeaponMultiplier{1};
	float combatDamageSpecialHeavyWeaponMultiplier{1};
	float combatDamageMineWeaponMultiplier{1};
	float combatDamageJediWeaponMultiplier{1};
	float combatDamageJediOneHandWeaponMultiplier{1};
	float combatDamageJediTwoHandWeaponMultiplier{1};
	float combatDamageJediPolearmWeaponMultiplier{1};
	float combatDamageJediForcePowerMultiplier{1};
	float combatDamageAllMultiplier{1};
	bool combatCriticalDamageEnabled{false};
	float combatCriticalMultiplier{1};
	float combatLegendaryCriticalMultiplier{1};
};

extern CombatVariables combatVars;

#endif /*COMBATVARIABLES_H_*/
