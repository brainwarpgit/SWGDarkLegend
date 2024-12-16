/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef GALLOPFINISHEDEVENT_H_
#define GALLOPFINISHEDEVENT_H_

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/variables/mountVariables.h"

class GallopFinishedEvent : public Task {
	ManagedWeakReference<CreatureObject*> creo;

public:
	GallopFinishedEvent(CreatureObject* cr) : Task() {
		creo = cr;
	}

	void run() {
		ManagedReference<CreatureObject*> creature = creo.get();
		if (creature == nullptr)
			return;
			
		ManagedReference<SceneObject*> parent = creature->getParent().get();
		PlayerObject* ghost = creo.get()->getPlayerObject();
		ManagedReference<CreatureObject*> mount = cast<CreatureObject*>(parent.get());
		if (mount == nullptr)
			return;
		
		PetManager* petManager = creature->getZoneServer()->getPetManager();
		ManagedReference<PetControlDevice*> pcd = mount->getControlDevice().get().castTo<PetControlDevice*>();
		if (pcd == nullptr)
			return;

		SharedObjectTemplate* objectTemplate = pcd->getObjectTemplate();
		if (objectTemplate == nullptr)
			return;

		MountSpeedData* mountSpeedData = petManager->getMountSpeedData(objectTemplate->getAppearanceFilename());
		if (mountSpeedData == nullptr)
			return;

		float magnitude = mountSpeedData->getGallopSpeedMultiplier();
		
		
		Locker locker(creature);

		uint32 crc = STRING_HASHCODE("gallop");
		
		creature->removePendingTask("gallop_finished");
		creature->setRunSpeed(creature->getRunSpeed() / magnitude);
		creature->setAccelerationMultiplierMod(creature->getAccelerationMultiplierMod() / magnitude);
		if (mountVars.mountPetSpeedSameAsPlayerEnabled) {
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr && mount->getObjectID() != pet->getObjectID()) {
					pet->setRunSpeed(pet->getRunSpeed() / magnitude);
					pet->setAccelerationMultiplierMod(pet->getAccelerationMultiplierMod() / magnitude);
				}
			}
		}
	}
};

#endif /*GALLOPFINISHEDEVENT_H_*/
