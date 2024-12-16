/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef VEHICLEDECAYTASK_H_
#define VEHICLEDECAYTASK_H_

#include "server/zone/objects/tangible/TangibleObject.h"
#include "templates/creature/VehicleObjectTemplate.h"

#include "server/zone/managers/variables/mountVariables.h"

class VehicleDecayTask : public Task {
	ManagedWeakReference<TangibleObject*> vehicleObj;
	bool initialDecay;

public:
	VehicleDecayTask(TangibleObject* veh) : Task() {
		vehicleObj = veh;
		initialDecay = true;
	}

	void run() {
		ManagedReference<TangibleObject*> vehicle = vehicleObj.get();

		if (vehicle == nullptr)
			return;

		Reference<VehicleObjectTemplate*> vehicleTemplate = cast<VehicleObjectTemplate*>(vehicle->getObjectTemplate());

		if (vehicleTemplate == nullptr)
			return;

		Locker locker(vehicle);

		vehicle->removePendingTask("decay");

		int decayCycle = vehicleTemplate->getDecayCycle();

		if (decayCycle == 0)
			decayCycle = mountVars.mountVehicleBaseDecayCycle;

		int decayRate = vehicleTemplate->getDecayRate();

		if (decayRate == 0)
			decayRate = mountVars.mountVehicleBaseDecayRate;

		if (initialDecay) {
			if (mountVars.mountVehicleInitialDecayEnabled == true) {
				vehicle->inflictDamage(vehicle, 0, decayRate / 2, true);
			}
			initialDecay = false;
		} else {
			vehicle->inflictDamage(vehicle, 0, decayRate, true);
		}

		vehicle->addPendingTask("decay", this, decayCycle * 1000);
	}
};

#endif /*VEHICLEDECAYTASK_H_*/
