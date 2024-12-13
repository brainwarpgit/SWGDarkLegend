#ifndef LOOTVARIABLES_H_
#define LOOTVARIABLES_H_

#include "engine/log/Logger.h"
#include <ctime>

class LootVariables : public Logger {

private:
	bool loadConfigData();
	void stopWatching();
	void startWatching(const std::function<void()>& loadConfigFunction);
	time_t getFileModifiedTime(const std::string& filePath);
	bool fileExists(const std::string& filePath);
	time_t lastModifiedTime{0};

public:
	LootVariables();
	~LootVariables();
	void startLootVariables();
	//Loot
	int lootDistance{16};
	bool lootAreaEnabled{false};
	float lootCreditMultiplier{1};
	int lootAttachmentMax{25};
	int lootAttachmentMin{1};
	int lootAttachmentMaxLevel{250};
	bool lootAttachmentNameEnabled{false};
	int lootAttachmentModCount{2};
	int lootDropAttachmentModCount{2};
	bool lootCreditLuckModifier{false};
	int lootMaxLevel{300};
	int lootMinLevel{1};
	bool lootShowForceCostDecimalEnabled{false};
	bool lootRareColorCrystalsEnabled{false};
	bool lootGroupCreditsSplitEnabled{true};
	float lootChanceMultiplier{1};
	float lootResourceMultiplier{1};
	bool lootYellowModifierNameEnabled{false};
	String lootYellowModifierName{"Enhanced"};
	float lootLegendaryDamageModifier{1};
	float lootExceptionalDamageModifier{2};
	float lootYellowDamageModifier{8};
	float lootBaseDamageModifier{9};
	bool lootUseLootModifiersForDamageModifiersEnabled{false};
	float lootArmorMaxResists{60};
	bool lootNewLootQualityNamingEnabled{false};
	bool lootModifiersAffectLightsaberCrystalsEnabled{false};
	bool lootLevelToItemDescriptionEnabled{false};
	bool lootModifierToItemDescriptionEnabled{false};
	bool lootQualityToItemDescriptionEnabled{false};
	bool lootSocketsOnWearablesEnabled{false};
	bool lootSocketsOnWearableContainersEnabled{true};
	bool lootColorCrystalColorInNameEnabled{false};
};

extern LootVariables lootVars;

#endif /*LOOTVARIABLES_H_*/
