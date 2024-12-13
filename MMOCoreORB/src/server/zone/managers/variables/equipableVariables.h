#ifndef EQUIPABLEVARIABLES_H_
#define EQUIPABLEVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class EquipableVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	EquipableVariables();
	~EquipableVariables();
	void startEquipableVariables();
	//Armor
	float equipableArmorPSGDecayRateMultiplier{0.2};
	float equipableArmorDecayRateMultiplier{0.2};
	float equipableArmorMaxArmorUnSliced{80};
	float equipableArmorMaxArmorSliced{90};

	//Weapon
	int equipableWeaponDecayRateChance{5};
	int equipableWeaponDecayRateWithPowerUpChance{10};
	float equipableWeaponCrystalDamagePerTick{1};
	float equipableWeaponDamagePerTicket{1};

	//Wearables
	bool equipableWearablesFactionEnabled{true};
	bool equipableWearablesAllPlayerRacesEnabled{false};
	bool equipableWearablesBackpackWipeEnabled{false};
	bool equipableWearablesChangeWearableColorsEnabled{false};
};

extern EquipableVariables equipableVars;

#endif /*EQUIPABLEVARIABLES_H_*/
