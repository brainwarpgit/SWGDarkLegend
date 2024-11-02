
/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#ifndef FORCERUN3COMMAND_H_
#define FORCERUN3COMMAND_H_

#include "server/zone/objects/creature/buffs/PrivateSkillMultiplierBuff.h"
#include "JediQueueCommand.h"
#include "server/globalVariables.h"

class ForceRun3Command : public JediQueueCommand {
public:
	ForceRun3Command(const String& name, ZoneProcessServer* server) : JediQueueCommand(name, server) {
		// BuffCRC's, first one is used.
		buffCRC = BuffCRC::JEDI_FORCE_RUN_3;

		// If these are active they will block buff use
		blockingCRCs.add(BuffCRC::JEDI_FORCE_RUN_1);
		blockingCRCs.add(BuffCRC::JEDI_FORCE_RUN_2);

		skillMods.put("force_run", 3);
		skillMods.put("slope_move", 99);
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		int res = creature->hasBuff(buffCRC) ? NOSTACKJEDIBUFF : doJediSelfBuffCommand(creature);

		uint32 crc = STRING_HASHCODE("pet_damage_divisor");

		if (res == NOSTACKJEDIBUFF) {
			if (globalVariables::playerJediForceRunToggleEnabled == false) {
				creature->sendSystemMessage("@jedi_spam:already_force_running"); // You are already force running.
				return GENERALERROR;
			} else {
				creature->sendSystemMessage("You feel the Force leave your body, and you return to normal movement speed."); // Toggle Force Run off.
				creature->removeBuff(BuffCRC::JEDI_FORCE_RUN_3);
				if (globalVariables::petSpeedSameAsPlayerEnabled) {
					PlayerObject* ghost = creature->getPlayerObject();
					for (int i = 0; i < ghost->getActivePetsSize(); i++) {
						ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
						if (pet != nullptr) {
							pet->removeBuff(crc);
							pet->setRunSpeed(creature->getFullSpeed() * 3);
						}
					}
				}
			}
		}

		if (res != SUCCESS) {
			return res;
		}

		// need to apply the damage reduction in a separate buff so that the multiplication and division applies right
		Buff* buff = creature->getBuff(BuffCRC::JEDI_FORCE_RUN_3);
		if (buff == nullptr)
			return GENERALERROR;

		ManagedReference<PrivateSkillMultiplierBuff*> multBuff = new PrivateSkillMultiplierBuff(creature, name.hashCode(), duration, BuffType::JEDI);

		Locker locker(multBuff);

		multBuff->setSkillModifier("private_damage_divisor", 20);

		creature->addBuff(multBuff);

		locker.release();

		Locker blocker(buff);

		buff->addSecondaryBuffCRC(multBuff->getBuffCRC());

		if (creature->hasBuff(STRING_HASHCODE("burstrun")) || creature->hasBuff(STRING_HASHCODE("retreat"))) {
			creature->removeBuff(STRING_HASHCODE("burstrun"));
			creature->removeBuff(STRING_HASHCODE("retreat"));
		}
		
		if (globalVariables::petSpeedSameAsPlayerEnabled) {
			PlayerObject* ghost = creature->getPlayerObject();
			ManagedReference<Buff*> petBuff = new Buff(creature, crc, duration, BuffType::SKILL);
			Locker petLocker(petBuff);
			for (int i = 0; i < ghost->getActivePetsSize(); i++) {
				ManagedReference<AiAgent*> pet = ghost->getActivePet(i);
				if (pet != nullptr and petBuff != nullptr) {
					pet->addBuff(petBuff);
					pet->setRunSpeed(creature->getFullSpeed() * 3);
				}	
			}
			petLocker.release();
		}

		return SUCCESS;
	}

};

#endif //FORCERUN3COMMAND_H_
