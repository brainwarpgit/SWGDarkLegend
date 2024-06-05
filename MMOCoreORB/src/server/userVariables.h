// userVariables.h

#ifndef USER_VARIABLES_H
#define USER_VARIABLES_H

#include <string>
#include <unordered_map>

namespace userVariables {

	    struct UserVariable {
		std::string userName;
		float value;
	    };

	    extern std::unordered_map<std::string, UserVariable> variables;

	    void setUserVariable(const std::string& userVariable, const std::string& userName, const float& value);
	    float getUserVariable(const std::string& userVariable, const std::string& userName);

}

#endif // USER_VARIABLES_H
