#include "globalVariables.h"
#include "engine/lua/Lua.h"

namespace globalVariables {

//Variables
	
//Initializer
	bool loadConfigData() {
	    	Lua* lua = new Lua();
		lua->init();			
		if (!lua->runFile("scripts/managers/global_variables.lua")) {
			delete lua;
			return false;
		}
		try {
			
		} catch (const Exception& e) {
			delete lua;
			return false;
		}
		delete lua;
		return true;
	}
	
// Static initializer to run loadConfigData when globalVariables.cpp is initialized
	namespace {
		struct GlobalsInitializer {
			GlobalsInitializer() {
				if (!loadConfigData()) {
					//std::cerr << "Failed to load config data." << std::endl;
				}
			}
		};
		GlobalsInitializer globalsInitializer;  // This will run at program startup
	}
}

