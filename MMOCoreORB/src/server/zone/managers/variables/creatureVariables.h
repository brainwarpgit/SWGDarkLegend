#ifndef CREATUREVARIABLES_H_
#define CREATUREVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CreatureVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CreatureVariables();
	~CreatureVariables();
	void startCreatureVariables();
	//Creature
	bool creatureRandomDifficultyEnabled{false};
	int creatureMaxLevel{336};
	float creatureBaseScaleMultiplier{1};
	float creatureBaseXPMultiplier{1};
	float creatureBaseMeatAmountMultiplier{1};
	float creatureBaseHideAmountMultiplier{1};
	float creatureBaseBoneAmountMultiplier{1};
	float creatureBaseMilkMultiplier{1};
	float creatureBaseLevelMultiplier{1};
	float creatureBaseChanceHitMultiplier{1};
	float creatureBaseFerocityMultiplier{1};
	float creatureBaseDamageMaxMultiplier{1};
	float creatureBaseDamageMinMultiplier{1};
	float creatureBaseHAMMultiplier{1};
	float creatureBaseHAMMaxMultiplier{1};
	float creatureBaseResistsMultiplier{1};
	float creatureKineticMaxResists{100.0};
	float creatureEnergyMaxResists{100.0};
	float creatureBlastMaxResists{100.0};
	float creatureHeatMaxResists{100.0};
	float creatureColdMaxResists{100.0};
	float creatureElectricityMaxResists{100.0};
	float creatureAcidMaxResists{100.0};
	float creatureStunMaxResists{100.0};
	float creatureLightsaberMaxResists{100.0};
	float creatureWildSpawnDensity{32.0};
	float creatureSpawnElitePercentage{30};
	float creatureSpawnHeroicPercentage{10};
	float creatureModBaseScaleModifier{0};
	float creatureModBaseXPModifier{0};
	float creatureModBaseMeatAmountModifier{0};
	float creatureModBaseHideAmountModifier{0};
	float creatureModBaseBoneAmountModifier{0};
	float creatureModBaseMilkModifier{0};
	float creatureModBaseLevelModifier{0};
	float creatureModBaseChanceHitModifier{0};
	float creatureModBaseFerocityModifier{0};
	float creatureModBaseDamageMaxModifier{0};
	float creatureModBaseDamageMinModifier{0};
	float creatureModBaseHAMModifier{0};
	float creatureModBaseHAMMaxModifier{0};
	float creatureModBaseResistsModifier{0};
	bool creatureAllCreatureCanSpawnBabyEnabled{false};
	float creatureAllCreatureCanSpawnBabyChance{0.05};
	bool creatureBabyRandomDifficultyEnabled{false};
	int creatureBabySpawnChanceDestroyMissionLair{1000};
	int creatureBabySpawnChanceDynamicSpawn{500};
	int creatureBabySpawnChanceDynamicLair{500};
	bool creatureShowRunSpeedEnabled{false};
};

extern CreatureVariables creatureVars;

#endif /*CREATUREVARIABLES_H_*/
