/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * \file MeditateTask.h
 * \author Polonel
 * \date 08.04.2010
 */

#ifndef MEDITATETASK_H_
#define MEDITATETASK_H_

#include "engine/engine.h"
#include "server/chat/StringIdChatParameter.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/variables/playerXpVariables.h"
#include "server/zone/managers/variables/professionVariables.h"

class MeditateTask: public Task {
	ManagedReference<CreatureObject*> player;
	String moodString;

public:
	MeditateTask(CreatureObject* pl) {
		player = pl;
	}

	void setMoodString(const String& ms) {
		moodString = ms;
	}

	String getMoodString() {
		return moodString;
	}

	void run() {
		Locker playerLocker(player);

		try {
			Reference<MeditateTask*> meditateTask = player->getPendingTask("meditate").castTo<MeditateTask*>();
			int meditateMod = player->getSkillMod("meditate"); // get Meditate Skill Mod

			if (!player->isMeditating())
				return;

			int heal = 0;
			ZoneServer* server = player->getZoneServer();
			PlayerManager* playerManager = server->getPlayerManager();
			if (player->isBleeding() || player->isPoisoned() || player->isDiseased()) {
				if (player->isBleeding() && meditateMod >= 15)
					player->healDot(CreatureState::BLEEDING, ((15 * professionVars.professionTkaMeditateHealingMultiplier) + (meditateMod / 3)));
				else if (player->isPoisoned() && meditateMod >= 30)
					player->healDot(CreatureState::POISONED, ((15 * professionVars.professionTkaMeditateHealingMultiplier) + (meditateMod / 3)));
				else if (player->isDiseased() && meditateMod >= 45)
					player->healDot(CreatureState::DISEASED, ((15 * professionVars.professionTkaMeditateHealingMultiplier) + (meditateMod / 3)));

			} else if (meditateMod >= 75) { // Meditate SkillMod +75 for wound Healing..

				StringIdChatParameter healParams;

				//Here we are checking to see which pools have wounds, and we add them to a vector...
				Vector<uint8> woundedPools;
				for (uint8 i = 0; i < 9; ++i) {
					if (player->getWounds(i) > 0)
						woundedPools.add(i);
				}
				//Return without rescheduling because everything that can be healed has been?
				if (professionVars.professionTkaMeditateFatigueHealingEnabled == true) {
					if (woundedPools.size() <= 0 && player->getShockWounds() <= 0) {
						return;
					}
				} else {
					if (woundedPools.size() <= 0) {
						return;
					}
				}

				heal = (20 * professionVars.professionTkaMeditateHealingMultiplier) + System::random(10);
				int fatigueheal = 0;

				if (meditateMod >= 100) {
					heal = (30 * professionVars.professionTkaMeditateHealingMultiplier) + System::random(20);
					fatigueheal = (professionVars.professionTkaMeditateFatigueHealingAmount * professionVars.professionTkaMeditateHealingMultiplier) + System::random(20);
				}
				if (woundedPools.size() > 0) {				
					// Select a random Attribute that has wounds...
					uint8 pool = woundedPools.get(System::random(woundedPools.size() - 1));
					int wounds = player->getWounds(pool);
					//Cap the heal at the amount of wounds the creature has.
					heal = Math::min(wounds, heal);
					player->healWound(player, pool, heal, true, false);
					// Sending System healing Message (wounds)
					healParams.setStringId("teraskasi", "prose_curewound"); // [meditation] Your %TO wounds heal by %DI points.
					healParams.setTO(CreatureAttribute::getName(pool));
					healParams.setDI(heal);
					player->sendSystemMessage(healParams);
					if (playerXpVars.playerXpMeditateGrantsHealingXPEnabled == true) playerManager->awardExperience(player, "medical", heal * 0.5f, true);
				}
				if (professionVars.professionTkaMeditateFatigueHealingEnabled == true && player->getShockWounds() > 0) {
						int fatigue = player->getShockWounds();
						fatigueheal = Math::min(fatigue, fatigueheal / 2);
						player->addShockWounds(-fatigueheal, true, false);
						player->sendSystemMessage(" [meditate] Your Battle Fatigue recovers by " + std::to_string(fatigueheal) + " points.");
						if (playerXpVars.playerXpMeditateGrantsHealingXPEnabled == true) playerManager->awardExperience(player, "entertainer_healing", fatigueheal, true);
				}
			}
			
			if (meditateTask != nullptr) {
				meditateTask->reschedule(professionVars.professionTkaMeditateTickTime * 1000);
			} else {
				meditateTask->schedule(professionVars.professionTkaMeditateTickTime * 1000);
			}
		} catch ( Exception& e) {
			player->error("unreported exception caught in MeditateTask::activate");
		}
	}
};

#endif /* MEDITATETASK_H_ */
