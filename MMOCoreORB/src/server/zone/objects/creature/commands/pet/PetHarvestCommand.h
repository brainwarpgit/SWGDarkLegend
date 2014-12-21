
#ifndef PETHARVESTCOMMAND_H_
#define PETHARVESTCOMMAND_H_

#include "server/zone/objects/creature/commands/QueueCommand.h"
#include "server/zone/objects/creature/AiAgent.h"
#include "server/zone/objects/scene/ObserverEventType.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/tangible/components/droid/DroidHarvestModuleDataComponent.h"

class PetHarvestCommand : public QueueCommand {
public:
	PetHarvestCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {
	}


	int doQueueCommand(CreatureObject* creature, const uint64& targetID, const UnicodeString& arguments) {

		ManagedReference<PetControlDevice*> controlDevice = creature->getControlDevice().castTo<PetControlDevice*>();
		if (controlDevice == NULL)
			return GENERALERROR;

		ManagedReference<AiAgent*> pet = cast<AiAgent*>(creature);
		if( pet == NULL )
			return GENERALERROR;

		if (pet->hasRidingCreature())
			return GENERALERROR;

		ManagedReference<CreatureObject*> owner = pet->getLinkedCreature();
		Locker olock(owner);
		Reference<CreatureObject*> target = server->getZoneServer()->getObject(targetID, true).castTo<CreatureObject*>();

		if (target == NULL || !target->isCreature()) {
			owner->sendSystemMessage("@pet/droid_modules:invalid_harvest_target");
			return GENERALERROR;
		}

		if(!target->isDead()) {
			owner->sendSystemMessage("@pet/droid_modules:invalid_harvest_target");
			return GENERALERROR;
		}

		if(!target->isInRange(pet,64)) {
			owner->sendSystemMessage("@pet/droid_modules:corpse_too_far");
			return GENERALERROR;
		}
		Creature* cr = cast<Creature*>(target.get());
		if (cr->getZone() == NULL)
			return GENERALERROR;
		// Schedule the harvest task
		ManagedReference<DroidObject*> droid = cast<DroidObject*>(creature);
		if( droid == NULL )
			return GENERALERROR;

		DroidHarvestModuleDataComponent* module = cast<DroidHarvestModuleDataComponent*>(droid->getModule("harvest_module"));
		if(module == NULL) {
			return GENERALERROR;
		}

		// do actions now, this is queued command
		// Check if droid is spawned
		if( droid->getLocalZone() == NULL ){  // Not outdoors
			ManagedWeakReference<SceneObject*> parent = droid->getParent();
			if( parent == NULL || !parent.get()->isCellObject() ){ // Not indoors either
				return GENERALERROR;
			}
		}

		// Check droid states, droids cant harvest while in combat
		if( droid->isDead() || droid->isIncapacitated() || droid->isInCombat()){
			return GENERALERROR;
		}

		// Droid must have power
		if( !droid->hasPower() ){
			droid->showFlyText("npc_reaction/flytext","low_power", 204, 0, 0);  // "*Low Power*"
			return GENERALERROR;
		}

		if (!target->isInRange(droid,7)) { // this should run the droid to the target for harvesting
			droid->setTargetObject(target);
			droid->activateMovementEvent();
		}
		int harvestInterest = module->getHarvestInterest();
		int bonus = module->getHarvestPower();
		// we have all the info we need form the droid for now.
		Locker tpLock(owner,target);

		Vector<int> types;
		int type = 0;
		if (harvestInterest == DroidHarvestModuleDataComponent::INTREST_BONE && cr->getBoneType().isEmpty()) {
			owner->sendSystemMessage("@pet/droid_modules:target_type_not_found");
			return GENERALERROR;
		} else {
			type = 236;
		}
		if (harvestInterest == DroidHarvestModuleDataComponent::INTREST_HIDE && cr->getHideType().isEmpty()) {
			owner->sendSystemMessage("@pet/droid_modules:target_type_not_found");
			return GENERALERROR;
		} else {
			type = 235;
		}
		if (harvestInterest == DroidHarvestModuleDataComponent::INTREST_MEAT && cr->getMeatType().isEmpty()) {
			owner->sendSystemMessage("@pet/droid_modules:target_type_not_found");
			return GENERALERROR;
		} else {
			type = 234;
		}

		if (harvestInterest == DroidHarvestModuleDataComponent::INTREST_RANDOM) {
			// pick one at random
			if(!cr->getMeatType().isEmpty()) {
				types.add(234);
			}

			if(!cr->getHideType().isEmpty()) {
				types.add(235);
			}

			if(!cr->getBoneType().isEmpty()) {
				types.add(236);
			}
			if(types.size() > 0)
				type = types.get(System::random(types.size() -1));
		}

		if (type == 0) {
			owner->sendSystemMessage("@pet/droid_modules:no_resources_to_harvest");
			return GENERALERROR;
		}
		if (cr->getDnaState() == CreatureManager::DNADEATH) {
			owner->sendSystemMessage("@pet/droid_modules:no_resources_to_harvest");
			return GENERALERROR;
		}
		tpLock.release();

		Locker clock(target,droid);
		ManagedReference<CreatureManager*> manager = cr->getZone()->getCreatureManager();
		manager->droidHarvest(cr, droid, type,bonus);
		droid->restoreFollowObject();
		return SUCCESS;
	}

};


#endif /* PETHARVESTCOMMAND_H_ */