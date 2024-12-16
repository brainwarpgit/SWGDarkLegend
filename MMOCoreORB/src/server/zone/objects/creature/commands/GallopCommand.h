/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef GALLOPCOMMAND_H_
#define GALLOPCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/buffs/GallopBuff.h"
#include "server/zone/objects/creature/events/GallopNotifyAvailableEvent.h"
#include "server/zone/objects/creature/events/GallopFinishedEvent.h"

#include "server/zone/managers/variables/mountVariables.h"
#include "server/globalVariables.h"

class GallopCommand : public QueueCommand {
public:

	GallopCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		PlayerObject* ghost = creature->getPlayerObject();
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<SceneObject*> parent = creature->getParent().get();

		if (parent == nullptr || !parent->isMount()) {
			creature->sendSystemMessage("@combat_effects:not_mounted"); // You cannot perform this command without a mount.
			return GENERALERROR;
		}

		ManagedReference<CreatureObject*> mount = cast<CreatureObject*>(parent.get());
		if (mount == nullptr)
			return GENERALERROR;

		PetManager* petManager = server->getZoneServer()->getPetManager();
		ManagedReference<PetControlDevice*> pcd = mount->getControlDevice().get().castTo<PetControlDevice*>();
		if (petManager == nullptr || pcd == nullptr)
			return GENERALERROR;

		SharedObjectTemplate* objectTemplate = pcd->getObjectTemplate();
		if (objectTemplate == nullptr)
			return GENERALERROR;

		MountSpeedData* mountSpeedData = petManager->getMountSpeedData(objectTemplate->getAppearanceFilename());
		if (mountSpeedData == nullptr)
			return GENERALERROR;

		float runSpeed = mountSpeedData->getRunSpeed();
		int duration = mountSpeedData->getGallopDuration();
		float magnitude = mountSpeedData->getGallopSpeedMultiplier();
		int cooldown = mountSpeedData->getGallopCooldown();

		Locker crossLocker(mount, creature);

		uint32 crc = STRING_HASHCODE("gallop");

		if (mount->hasBuff(crc) || creature->hasBuff(crc)) {
			if (mountVars.mountPetGallopToggleEnabled) {
				creature->removeBuff(STRING_HASHCODE("gallop"));
				creature->removePendingTask("gallop_finished");
				creature->setRunSpeed(creature->getRunSpeed() / magnitude);
				creature->setAccelerationMultiplierMod(creature->getAccelerationMultiplierMod() / magnitude);
			} else {
				creature->sendSystemMessage("@combat_effects:already_galloping"); // You are already galloping!
				return GENERALERROR;
			}
			if (mountVars.mountPetSpeedSameAsPlayerEnabled) {
				for (int i = 0; i < ghost->getActivePetsSize(); i++) {
					ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
					if (pet != nullptr && mount->getObjectID() != pet->getObjectID()) {
						pet->setRunSpeed(pet->getRunSpeed() / magnitude);
						pet->setAccelerationMultiplierMod(pet->getAccelerationMultiplierMod() / magnitude);
					}
				}
			}	
			return false;
		}

		if (!mount->checkCooldownRecovery("gallop")) {
			creature->sendSystemMessage("@combat_effects:mount_tired"); // Your mount is too tired to gallop.
			return GENERALERROR;
		}

		if (mountVars.mountPetGallopToggleEnabled) {
			float health = mount->getMaxHAM(CreatureAttribute::HEALTH) * (mountVars.mountPetGallopDamagePercent / 100);
			float action = mount->getMaxHAM(CreatureAttribute::ACTION) * (mountVars.mountPetGallopDamagePercent / 100);
			float mind = mount->getMaxHAM(CreatureAttribute::MIND) * (mountVars.mountPetGallopDamagePercent / 100);
				
			if (mount->getHAM(CreatureAttribute::HEALTH) <= health || mount->getHAM(CreatureAttribute::ACTION) <= action || mount->getHAM(CreatureAttribute::MIND) <= mind) {
				creature->sendSystemMessage("@combat_effects:mount_tired"); // Your mount is too tired to gallop.
				return GENERALERROR;
			}

			mount->inflictDamage(mount, CreatureAttribute::HEALTH, health, true);
			mount->inflictDamage(mount, CreatureAttribute::ACTION, action, true);
			mount->inflictDamage(mount, CreatureAttribute::MIND, mind, true);
		}	
	
		StringIdChatParameter startStringId("combat_effects", "gallop_start"); // Your mount runs as fast as it can.
		StringIdChatParameter endStringId("combat_effects", "gallop_stop"); // Your mount is winded and slows down.

		ManagedReference<GallopBuff*> buff = new GallopBuff(creature, crc, duration);

		Locker locker(buff);

		buff->setStartMessage(startStringId);
		buff->setEndMessage(endStringId);
		if (!mountVars.mountPetSpeedSameAsPlayerEnabled) {
			creature->setRunSpeed(runSpeed * globalVariables::playerSpeedMultiplier);
			buff->setSpeedMultiplierMod(magnitude);
			buff->setAccelerationMultiplierMod(magnitude);
			creature->addBuff(buff);
			mount->updateCooldownTimer("gallop", (cooldown + duration) * 1000);
		} else {
			creature->setRunSpeed(creature->getRunSpeed() * magnitude);
			creature->setAccelerationMultiplierMod(creature->getAccelerationMultiplierMod() * magnitude);
			creature->addBuff(buff);
			mount->updateCooldownTimer("gallop", (cooldown + duration) * 1000);
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr && mount->getObjectID() != pet->getObjectID()) {
					pet->setRunSpeed(pet->getRunSpeed() * magnitude);
					pet->setAccelerationMultiplierMod(pet->getAccelerationMultiplierMod() * magnitude);
				}
			}
		}
		
		if (!mountVars.mountPetGallopToggleEnabled) {
			Reference<GallopNotifyAvailableEvent*> task = new GallopNotifyAvailableEvent(creature);
			creature->addPendingTask("gallop_notify", task, (cooldown + duration) * 1000);
		} else {
			Reference<GallopFinishedEvent*> finishTask = new GallopFinishedEvent(creature);
			creature->addPendingTask("gallop_finished", finishTask, (duration * 1000));
		}

		return SUCCESS;
	}

};

#endif //GALLOPCOMMAND_H_
