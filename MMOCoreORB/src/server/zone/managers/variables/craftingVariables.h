#ifndef CRAFTINGVARIABLES_H_
#define CRAFTINGVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class CraftingVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	CraftingVariables();
	~CraftingVariables();
	void startCraftingVariables();
	//Crafting
	int craftingFactoryCrateMaxSize{100};
	float craftingFactoryRunTimeMultiplier{8};
	float craftingToolCraftTimeMultiplier{2};
	int craftingMaxSockets{4};
	int craftingMinSocketMod{60};
	int craftingMaxSocketMod{175};
	bool craftingNewGenerateSocketsEnabled{false};
	bool craftingWearableContainerSocketsEnabled{false};
	bool craftingNewAssemblyEnabled{false};
	bool craftingNewExperimentEnabled{false};
	bool craftingNewRepairEnabled{false};
	bool craftingRepairBrokenEnabled{false};
	float craftingRepairMaxMod{0.8};
	bool craftingCraftedItemsBetterThanLootEnabled{false};
	float craftingCraftedItemsBetterThanLootModifier{1};
	float craftingKineticMaxResists{100};
	float craftingEnergyMaxResists{100};
	float craftingBlastMaxResists{100};
	float craftingHeatMaxResists{100};
	float craftingColdMaxResists{100};
	float craftingElectricityMaxResists{100};
	float craftingAcidMaxResists{100};
	float craftingStunMaxResists{100};
	float craftingLightsaberMaxResists{100};
	float craftingAssemblyModifier{0};
	bool craftingWhileEntertainingEnabled{false};
};

extern CraftingVariables craftingVars;

#endif /*CRAFTINGVARIABLES_H_*/
