/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef BURSTRUNFINISHEDEVENT_H_
#define BURSTRUNFINISHEDEVENT_H_

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/globalVariables.h"

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
		if (globalVariables::petSpeedSameAsPlayerEnabled) {
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr) {
					pet->setRunSpeed(pet->getRunSpeed() / globalVariables::playerBurstRunSpeedAndAccelerationModifier);
					pet->setAccelerationMultiplierMod(pet->getAccelerationMultiplierMod() / globalVariables::playerBurstRunSpeedAndAccelerationModifier);
				}
			}
		}
	}
};

#endif /*BURSTRUNFINISHEDEVENT_H_*/
