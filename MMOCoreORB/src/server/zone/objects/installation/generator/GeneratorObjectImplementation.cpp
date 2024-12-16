/*
 * GeneratorObjectImplementation.cpp
 *
 *  Created on: 15/06/2010
 *      Author: victor
 */

#include "server/zone/objects/installation/generator/GeneratorObject.h"
#include "server/zone/packets/harvester/HarvesterObjectMessage7.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/packets/harvester/ResourceHarvesterActivatePageMessage.h"

#include "server/zone/managers/variables/structureVariables.h"

void GeneratorObjectImplementation::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	if (!isOnAdminList(player))
		return;

	InstallationObjectImplementation::fillObjectMenuResponse(menuResponse, player);

	if (structureVars.structureInstallationResourcesRetrieveAllEnabled == true) {
		menuResponse->addRadialMenuItemToRadialID(118, 79, 3, "Retreive all resources"); //Empty Harvester
	}
	if (structureVars.structureInstallationQuickAddMaintenanceEnabled == true) {
		menuResponse->addRadialMenuItemToRadialID(118, 80, 3, UnicodeString("+ " + std::to_string(structureVars.structureInstallationQuickAddMaintenanceAmount) + "k Maintenance")); //k maint
	}
	menuResponse->addRadialMenuItemToRadialID(118, 78, 3, "@harvester:manage"); //Operate Machinery
}

void GeneratorObjectImplementation::synchronizedUIListen(CreatureObject* player, int value) {
	if (!player->isPlayerCreature() || !isOnAdminList(player) || getZone() == nullptr)
		return;

	addOperator(player);

	updateInstallationWork();

	HarvesterObjectMessage7* msg = new HarvesterObjectMessage7(_this.getReferenceUnsafeStaticCast());
	player->sendMessage(msg);

	activateUiSync();
}

void GeneratorObjectImplementation::synchronizedUIStopListen(CreatureObject* player, int value) {
	if (!player->isPlayerCreature())
		return;

	removeOperator(player);
}

int GeneratorObjectImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	if (!isOnAdminList(player))
		return 1;

	switch (selectedID) {
		// Stack adding in harvester empty/power/maint quick addd
	case 80: { // k maint
		quickAddMaint(player, structureVars.structureInstallationQuickAddMaintenanceAmount * 1000);
		break;
	}
	case 79: { // Retrieve all from Harvester
		quickRetrieveAllResources(player);
		break;
	}
	case 78: {
		ResourceHarvesterActivatePageMessage* rhapm = new ResourceHarvesterActivatePageMessage(getObjectID());
		player->sendMessage(rhapm);
		break;
	}

	default:
		return InstallationObjectImplementation::handleObjectMenuSelect(player, selectedID);
	}

	return 0;
}

String GeneratorObjectImplementation::getRedeedMessage() {
	if (isActive())
		return "destroy_deactivate_first";

	if (getHopperSize() > 0)
		return "destroy_empty_hopper";

	return "";
}
