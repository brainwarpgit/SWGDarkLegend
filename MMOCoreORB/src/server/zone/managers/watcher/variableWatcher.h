#ifndef VARIABLEWATCHER_H_
#define VARIABLEWATCHER_H_

#include "engine/log/Logger.h"

class VariableWatcher : public Logger {

public:
	VariableWatcher();
	~VariableWatcher();
	void startVariableWatchers();
	bool stopWatch{false};
	long threadReloadTime{1};
};

extern VariableWatcher varWatch;

#endif /* VARIABLEWATCHER_H_ */

