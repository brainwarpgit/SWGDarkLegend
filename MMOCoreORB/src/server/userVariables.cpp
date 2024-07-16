// userVariables.cpp

#include "server/userVariables.h"

namespace userVariables {

	std::unordered_map<std::string, UserVariable> variables;
	
	void setUserVariable(const std::string& userVariable, const std::string& userName, const float& value) {
	    variables[userVariable] = { userName, value };
	}

	float getUserVariable(const std::string& userVariable, const std::string& userName) {
	    auto it = variables.find(userVariable);
	    if (it != variables.end() && it->second.userName == userName) {
		return it->second.value;
	    } else {
		// Return a default-constructed value if the key doesn't exist
		return 0;
	    }
	}

}
