/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef FSVILLAGECOMMAND_H_
#define FSVILLAGECOMMAND_H_

#include "server/zone/managers/director/DirectorManager.h"
#include "server/zone/managers/jedi/JediManager.h"

#include "server/zone/managers/variables/serverVariables.h"

class FsVillageCommand : public QueueCommand {
public:

	FsVillageCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		if (!serverVars.serverCommandfsVillageEnabled) {
			creature->sendSystemMessage("fsVillage is disabled.");
			return GENERALERROR;
		}
		
		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;
        
		if (JediManager::instance()->getJediProgressionType() != JediManager::VILLAGEJEDIPROGRESSION)
			return GENERALERROR;

		Lua* lua = DirectorManager::instance()->getLuaInstance();
		Reference<LuaFunction*> luaVillageCmd = lua->createFunction("VillageSui", "showMainPage", 0);
		*luaVillageCmd << creature;

		luaVillageCmd->callFunction();
		return SUCCESS;
	}

};

#endif //FSVILLAGECOMMAND_H_
