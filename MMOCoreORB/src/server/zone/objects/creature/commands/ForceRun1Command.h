/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#ifndef FORCERUN1COMMAND_H_
#define FORCERUN1COMMAND_H_

#include "JediQueueCommand.h"

#include "server/zone/managers/variables/petVariables.h"
#include "server/globalVariables.h"

class ForceRun1Command : public JediQueueCommand {
public:

	ForceRun1Command(const String& name, ZoneProcessServer* server)
	: JediQueueCommand(name, server) {
		// BuffCRC's, first one is used.
		buffCRC = BuffCRC::JEDI_FORCE_RUN_1;
    
        // If these are active they will block buff use
		blockingCRCs.add(BuffCRC::JEDI_FORCE_RUN_2);
		blockingCRCs.add(BuffCRC::JEDI_FORCE_RUN_3);
    
    
		// Skill mods.
		skillMods.put("force_run", 1);
		skillMods.put("slope_move", 33);
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		int res = creature->hasBuff(buffCRC) ? NOSTACKJEDIBUFF : doJediSelfBuffCommand(creature);

		if (res == NOSTACKJEDIBUFF) {
			if (globalVariables::playerJediForceRunToggleEnabled == false) {
				creature->sendSystemMessage("@jedi_spam:already_force_running"); // You are already force running.
				return GENERALERROR;
			} else {
				creature->sendSystemMessage("You feel the Force leave your body, and you return to normal movement speed."); // Toggle Force Run off.
				creature->removeBuff(BuffCRC::JEDI_FORCE_RUN_1);
				if (petVars.petSpeedSameAsPlayerEnabled) {
					PlayerObject* ghost = creature->getPlayerObject();
					for (int i = 0; i < ghost->getActivePetsSize(); i++) {
						ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
						if (pet != nullptr) {
							pet->setRunSpeed(creature->getFullSpeed() * 3);
						}
					}
				}
			}
		}
		// Return if something is in error.
		if (res != SUCCESS) {
			return res;
		}

		// SPECIAL - For Force Run.
		if (creature->hasBuff(STRING_HASHCODE("burstrun")) || creature->hasBuff(STRING_HASHCODE("retreat"))) {
			creature->removeBuff(STRING_HASHCODE("burstrun"));
			creature->removeBuff(STRING_HASHCODE("retreat"));
			creature->removeBuff(STRING_HASHCODE("gallop"));
		}

		if (petVars.petSpeedSameAsPlayerEnabled) {
			PlayerObject* ghost = creature->getPlayerObject();
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr) {
					pet->setRunSpeed(creature->getFullSpeed() * 3);
				}
			}
		}

		// Return.
		return SUCCESS;
	}

};

#endif //FORCERUN1COMMAND_H_
