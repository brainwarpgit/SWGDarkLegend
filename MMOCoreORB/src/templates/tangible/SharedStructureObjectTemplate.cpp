/*
 * SharedStructureObjectTemplate.cpp
 *
 *  Created on: May 22, 2010
 *      Author: crush
 */


#include "SharedStructureObjectTemplate.h"
#include "server/globalVariables.h"


void SharedStructureObjectTemplate::readObject(LuaObject* templateData) {
	SharedTangibleObjectTemplate::readObject(templateData);

	lotSize = templateData->getByteField("lotSize");

	if (globalVariables::structureBaseMaintenanceRateMultiplier > 0) {
		baseMaintenanceRate = templateData->getIntField("baseMaintenanceRate") * globalVariables::structureBaseMaintenanceRateMultiplier;
	} else {
		baseMaintenanceRate = templateData->getIntField("baseMaintenanceRate");
	}

	if (globalVariables::structureBasePowerRateMultiplier > 0) {
		basePowerRate = templateData->getIntField("basePowerRate") * globalVariables::structureBasePowerRateMultiplier;
	} else {
		basePowerRate = templateData->getIntField("basePowerRate");
	}

	if (globalVariables::structureAllowAllZonesEnabled == true) {
		allowedZones = {"corellia", "talus", "dathomir", "endor", "lok", "naboo", "rori", "tatooine", "yavin4", "dantooine"};
	} else {
		LuaObject allowzones = templateData->getObjectField("allowedZones");
		allowedZones.removeAll(); //Make sure it's empty...

		for (int i = 1; i <= allowzones.getTableSize(); ++i) {
			allowedZones.put(allowzones.getStringAt(i));
		}

		allowzones.pop();
	}

	cityRankRequired = templateData->getByteField("cityRankRequired");

	constructionMarkerTemplate = templateData->getStringField("constructionMarker");

	abilityRequired = templateData->getStringField("abilityRequired");

	uniqueStructure = templateData->getBooleanField("uniqueStructure");

	if (globalVariables::cityMaintenanceBaseMultiplier > 0) {
		cityMaintenanceBase = templateData->getIntField("cityMaintenanceBase") * globalVariables::cityMaintenanceBaseMultiplier;
	} else {
		cityMaintenanceBase = templateData->getIntField("cityMaintenanceBase");
	}
	
	if (globalVariables::cityMaintenanceRateMultiplier > 0) {
		cityMaintenanceRate = templateData->getIntField("cityMaintenanceRate") * globalVariables::cityMaintenanceRateMultiplier;
	} else {
		cityMaintenanceRate = templateData->getIntField("cityMaintenanceRate");
	}

}
