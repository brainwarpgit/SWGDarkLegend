/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef DISMOUNTCOMMAND_H_
#define DISMOUNTCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/intangible/ControlDevice.h"
#include "templates/creature/SharedCreatureObjectTemplate.h"
#include "server/zone/packets/object/DataTransform.h"

#include "server/zone/managers/variables/mountVariables.h"
#include "server/globalVariables.h"

class DismountCommand : public QueueCommand {
	Vector<uint32> restrictedBuffCRCs;
	uint32 gallopCRC;

public:
	DismountCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
		gallopCRC = STRING_HASHCODE("gallop");

		restrictedBuffCRCs.add(gallopCRC); // Remove the old buff off of any players on dismount
		restrictedBuffCRCs.add(STRING_HASHCODE("burstrun"));
		restrictedBuffCRCs.add(STRING_HASHCODE("retreat"));
		restrictedBuffCRCs.add(BuffCRC::JEDI_FORCE_RUN_1);
		restrictedBuffCRCs.add(BuffCRC::JEDI_FORCE_RUN_2);
		restrictedBuffCRCs.add(BuffCRC::JEDI_FORCE_RUN_3);
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		PlayerObject* ghost = creature->getPlayerObject();
		
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->hasState(CreatureState::RIDINGMOUNT))
			return INVALIDSTATE;

		if (!creature->checkCooldownRecovery("mount_dismount")) {
			return GENERALERROR;
		}

		auto templateData = creature->getObjectTemplate();

		if (templateData == nullptr) {
			return GENERALERROR;
		}

		auto playerTemplate = dynamic_cast<SharedCreatureObjectTemplate*>(templateData);

		if (playerTemplate == nullptr) {
			return GENERALERROR;
		}

		creature->clearState(CreatureState::RIDINGMOUNT);

		ManagedReference<SceneObject*> mount = creature->getParent().get();
		ManagedReference<CreatureObject*> creatureMount = mount->asCreatureObject();
		auto mountTemplateData = creatureMount->getObjectTemplate();
		auto mountTemplate = dynamic_cast<SharedCreatureObjectTemplate*>(mountTemplateData);
		
		// Handle dismount, removal of gallop and storing of Jetpacks
		if (mount != nullptr && mount->isCreatureObject()) {
			handleMount(creature, mount);
		}

		// reapply speed buffs if they exist
		for (int i = 0; i < restrictedBuffCRCs.size(); i++) {
			uint32 buffCRC = restrictedBuffCRCs.get(i);

			if (creature->hasBuff(buffCRC)) {
				ManagedReference<Buff*> buff = creature->getBuff(buffCRC);

				if (buff != nullptr) {
					Locker lock(buff, creature);
					buff->applyAllModifiers();
				}
			}
		}

		SpeedMultiplierModChanges* changeBuffer = creature->getSpeedMultiplierModChanges();
		int bufferSize = changeBuffer->size();

		if (bufferSize > 5) {
			changeBuffer->remove(0);
		}

		changeBuffer->add(SpeedModChange(creature->getSpeedMultiplierMod()));

		Vector<FloatParam> speedTempl = playerTemplate->getSpeed();
		Vector<FloatParam> mountSpeedTempl = mountTemplate->getSpeed();

		// Reset Run Speed from template
		creature->setRunSpeed(globalVariables::playerDefaultRunSpeed * globalVariables::playerSpeedMultiplier);
		creatureMount->setRunSpeed(mountSpeedTempl.get(0));

 		// Reset Force Sensitive control mods to default.
		creature->updateSpeedAndAccelerationMods();
		creatureMount->updateSpeedAndAccelerationMods();

		// Update players stats in the database
		creature->updateToDatabase();
		creatureMount->updateToDatabase();

		creature->updateCooldownTimer("mount_dismount", 2000);
		creature->setNextAllowedMoveTime(500);

		// these are already removed off the player - Just remove it off the mount
		creature->removeMountedCombatSlow(false);

		if (mountVars.mountPetSpeedSameAsPlayerEnabled) {
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr) {
					pet->setRunSpeed(creature->getFullSpeed() * 3);
				}
			}
		}
		return SUCCESS;
	}

	void handleMount(CreatureObject* creature, SceneObject* mount) const {
		if (creature == nullptr || mount == nullptr) {
			return;
		}

		auto vehicle = mount->asCreatureObject();

		if (vehicle == nullptr) {
			return;
		}

		auto zone = vehicle->getZone();

		if (zone == nullptr) {
			return;
		}

		Locker clocker(vehicle, creature);

		vehicle->clearState(CreatureState::MOUNTEDCREATURE);

		// Handle dismounting player
		if (vehicle == creature->getParent().get()) {
			// Player will be sent to the vehicles position in the world
			Vector3 vehiclePosition = vehicle->getWorldPosition();

			float vehicleSpeed = vehicle->getCurrentSpeed();

			if (vehicleSpeed > 0) {
				// Get a position 1m back from the vehicles position
				float angle = vehicle->getDirection()->getRadians();

				angle = M_PI / 2 - angle;

				if (angle < 0) {
					float a = M_PI + angle;
					angle = M_PI + a;
				}

				vehiclePosition.setX(vehiclePosition.getX() + (Math::cos(angle) * -1.f));
				vehiclePosition.setY(vehiclePosition.getY() + (Math::sin(angle) * -1.f));
			}

			auto planetManager = zone->getPlanetManager();

			if (planetManager != nullptr) {
				auto terrainManager = planetManager->getTerrainManager();

				if (terrainManager != nullptr) {
					IntersectionResults intersections;
					CollisionManager::getWorldFloorCollisions(vehiclePosition.getX(), vehiclePosition.getY(), zone, &intersections, (CloseObjectsVector*)creature->getCloseObjects());
					vehiclePosition.setZ(planetManager->findClosestWorldFloor(vehiclePosition.getX(), vehiclePosition.getY(), vehiclePosition.getZ(), creature->getSwimHeight(), &intersections, (CloseObjectsVector*)creature->getCloseObjects()));
				}
			}

			// Transfer them into the zone
			zone->transferObject(creature, -1, false);

			creature->teleport(vehiclePosition.getX(), vehiclePosition.getZ(), vehiclePosition.getY(), 0);

			// debug markers
			/*
			Reference<SceneObject*> movementMarker = creature->getZoneServer()->createObject(STRING_HASHCODE("object/path_waypoint/path_waypoint.iff"), 0);

			Locker moveLock(movementMarker, creature);
			movementMarker->initializePosition(vehiclePosition.getX(), vehiclePosition.getZ(), vehiclePosition.getY());
			zone->transferObject(movementMarker, -1, true);
			moveLock.release();

			// END debug markers\
			*/

			ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

			if (playerManager != nullptr) {
				playerManager->updateSwimmingState(creature, vehiclePosition.getZ());
			}
		}

		// Remove gallop from mounts
		if (vehicle->hasBuff(gallopCRC)) {
			removeMountBuffs(vehicle);
		}

		// Store Jetpack
		ManagedReference<ControlDevice*> device = vehicle->getControlDevice().get();

		if (device != nullptr && (vehicle->getServerObjectCRC() == 0x32F87A54 || vehicle->getServerObjectCRC() == 0x3A19A20D || vehicle->getServerObjectCRC() == 0x5C3FA920)) { // Auto-store jetpack on dismount.
			device->storeObject(creature);
			creature->sendSystemMessage("@pet/pet_menu:jetpack_dismount"); // "You have been dismounted from the jetpack, and it has been stored."
		}

		if (vehicle->getParentID() == 0) {
			vehicle->setCurrentSpeed(0.f);
			vehicle->incrementMovementCounter();

			auto data = new DataTransform(vehicle);
			vehicle->broadcastMessage(data, false);
		}
	}

	void removeMountBuffs(CreatureObject* vehicle) const {
		if (vehicle == nullptr)
			return;

		ManagedReference<Buff*> buff = vehicle->getBuff(gallopCRC);

		if (buff == nullptr)
			return;

		Reference<CreatureObject*> vehicleRef = vehicle;

		Core::getTaskManager()->executeTask([vehicleRef, buff]() {
			Locker lock(vehicleRef);
			Locker buffLocker(buff, vehicleRef);

			buff->removeAllModifiers();
		}, "RemoveGallopModsLambda");
	}
};

#endif // DISMOUNTCOMMAND_H_
