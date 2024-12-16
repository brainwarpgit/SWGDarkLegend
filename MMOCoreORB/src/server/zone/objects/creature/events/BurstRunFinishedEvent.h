/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef BURSTRUNFINISHEDEVENT_H_
#define BURSTRUNFINISHEDEVENT_H_

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/variables/mountVariables.h"
#include "server/zone/managers/variables/playerVariables.h"

class BurstRunFinishedEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	BurstRunFinishedEvent(CreatureObject* cr) : Task() {
		creo = cr;
	}

	void run() {
		ManagedReference<CreatureObject*> creature = creo.get();
		PlayerObject* ghost = creo.get()->getPlayerObject();
	
		if (creature == nullptr)
			return;

		Locker locker(creature);

		creature->removePendingTask("burst_run_finished");
		if (mountVars.mountPetSpeedSameAsPlayerEnabled) {
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr) {
					pet->setRunSpeed(pet->getRunSpeed() / playerVars.playerBurstRunSpeedAndAccelerationModifier);
					pet->setAccelerationMultiplierMod(pet->getAccelerationMultiplierMod() / playerVars.playerBurstRunSpeedAndAccelerationModifier);
				}
			}
		}
	}
};

#endif /*BURSTRUNFINISHEDEVENT_H_*/
