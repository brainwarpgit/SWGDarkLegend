#include "server/zone/managers/watcher/variableWatcher.h"
#include "server/zone/managers/variables/auctionVariables.h"
#include "server/zone/managers/variables/combatVariables.h"
#include "server/zone/managers/variables/craftingVariables.h"
#include "server/zone/managers/variables/creatureVariables.h"
#include "server/zone/managers/variables/factionVariables.h"
#include "server/zone/managers/variables/harvestVariables.h"
#include "server/zone/managers/variables/lootVariables.h"
#include "server/zone/managers/variables/missionVariables.h"
#include "server/zone/managers/variables/petVariables.h"
#include "server/zone/managers/variables/playerCreationVariables.h"
#include "server/zone/managers/variables/playerVariables.h"
#include "server/zone/managers/variables/playerXpVariables.h"
#include "server/zone/managers/variables/professionVariables.h"
#include "server/zone/managers/variables/resourceVariables.h"
#include "server/zone/managers/variables/serverVariables.h"
#include "server/zone/managers/variables/structureVariables.h"
#include "server/zone/managers/variables/vehicleVariables.h"
#include "server/zone/managers/variables/weaponVariables.h"
#include "server/zone/managers/variables/wearableVariables.h"

VariableWatcher varWatch;

VariableWatcher::VariableWatcher() : Logger("VariableWatcher") {}

VariableWatcher::~VariableWatcher() {}

void VariableWatcher::startVariableWatchers() {
	AuctionVariables* auctionVariables = new AuctionVariables();
	if (auctionVariables != nullptr) {
		info(true) << "Starting AuctionVariables Watcher.";
		auctionVariables->startAuctionVariables();
	}

	CombatVariables* combatVariables = new CombatVariables();
	if (combatVariables != nullptr) {
		info(true) << "Starting CombatVariables Watcher.";
		combatVariables->startCombatVariables();
	}

	CraftingVariables* craftingVariables = new CraftingVariables();
	if (craftingVariables != nullptr) {
		info(true) << "Starting CraftingVariables Watcher.";
		craftingVariables->startCraftingVariables();
	}

	CreatureVariables* creatureVariables = new CreatureVariables();
	if (creatureVariables != nullptr) {
		info(true) << "Starting CreatureVariables Watcher.";
		creatureVariables->startCreatureVariables();
	}

	FactionVariables* factionVariables = new FactionVariables();
	if (factionVariables != nullptr) {
		info(true) << "Starting FactionVariables Watcher.";
		factionVariables->startFactionVariables();
	}

	HarvestVariables* harvestVariables = new HarvestVariables();
	if (harvestVariables != nullptr) {
		info(true) << "Starting HarvestVariables Watcher.";
		harvestVariables->startHarvestVariables();
	}

	LootVariables* lootVariables = new LootVariables();
	if (lootVariables != nullptr) {
		info(true) << "Starting LootVariables Watcher.";
		lootVariables->startLootVariables();
	}

	MissionVariables* missionVariables = new MissionVariables();
	if (missionVariables != nullptr) {
		info(true) << "Starting MissionVariables Watcher.";
		missionVariables->startMissionVariables();
	}

	PetVariables* petVariables = new PetVariables();
	if (petVariables != nullptr) {
		info(true) << "Starting PetVariables Watcher.";
		petVariables->startPetVariables();
	}

	PlayerCreationVariables* playerCreationVariables = new PlayerCreationVariables();
	if (playerCreationVariables != nullptr) {
		info(true) << "Starting PlayerCreationVariables Watcher.";
		playerCreationVariables->startPlayerCreationVariables();
	}

	PlayerVariables* playerVariables = new PlayerVariables();
	if (playerVariables != nullptr) {
		info(true) << "Starting PlayerVariables Watcher.";
		playerVariables->startPlayerVariables();
	}

	PlayerXpVariables* playerXpVariables = new PlayerXpVariables();
	if (playerXpVariables != nullptr) {
		info(true) << "Starting PlayerXpVariables Watcher.";
		playerXpVariables->startPlayerXpVariables();
	}

	ProfessionVariables* professionVariables = new ProfessionVariables();
	if (professionVariables != nullptr) {
		info(true) << "Starting ProfessionVariables Watcher.";
		professionVariables->startProfessionVariables();
	}

	ResourceVariables* resourceVariables = new ResourceVariables();
	if (resourceVariables != nullptr) {
		info(true) << "Starting ResourceVariables Watcher.";
		resourceVariables->startResourceVariables();
	}

	ServerVariables* serverVariables = new ServerVariables();
	if (serverVariables != nullptr) {
		info(true) << "Starting ServerVariables Watcher.";
		serverVariables->startServerVariables();
	}

	StructureVariables* structureVariables = new StructureVariables();
	if (structureVariables != nullptr) {
		info(true) << "Starting StructureVariables Watcher.";
		structureVariables->startStructureVariables();
	}

	VehicleVariables* vehicleVariables = new VehicleVariables();
	if (vehicleVariables != nullptr) {
		info(true) << "Starting VehicleVariables Watcher.";
		vehicleVariables->startVehicleVariables();
	}

	WeaponVariables* weaponVariables = new WeaponVariables();
	if (weaponVariables != nullptr) {
		info(true) << "Starting WeaponVariables Watcher.";
		weaponVariables->startWeaponVariables();
	}

	WearableVariables* wearableVariables = new WearableVariables();
	if (wearableVariables != nullptr) {
		info(true) << "Starting WearableVariables Watcher.";
		wearableVariables->startWearableVariables();
	}
}
