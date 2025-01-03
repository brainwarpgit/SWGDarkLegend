local ObjectManager = require("managers.object.object_manager")

TalusDetainmentCenterScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TalusDetainmentCenterScreenPlay",

	buildingID = 9686208,

--9686208 bunker imperial detainment center
--9686346 terminal hq
--9686357 override terminal
--9686389 power regulator
--9686393 security terminal
--9686398 uplink terminal
	ScreenRebelSpawns = {
		{"rebel_staff_corporal_caveTalusDetainmentCenter", 300, 5.3, -9.0, 29.7, -1, 9686212, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, 6.9, -9.0, 33.9, 0, 9686212, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, 0.0, -9.0, 33.9, -6, 9686212, 9686208},
		{"rebel_warrant_officer_i_caveTalusDetainmentCenter", 300, -48.1, -9.0, -6.6, 90, 9686214, 9686208},
		{"rebel_corporal_caveTalusDetainmentCenter", 300, -58.4, -9.0, 3.2, 0, 9686214, 9686208},
		{"specforce_technician_caveTalusDetainmentCenter", 300, -78.2, -9.0, 21.5,  173, 9686214, 9686208},
		{"rebel_staff_corporal_caveTalusDetainmentCenter", 300, -52.0, -9.0, 61.6, 88, 9686214, 9686208},
		{"specforce_technician_caveTalusDetainmentCenter", 300, -57.0, -9.0, 58.7, -90, 9686214, 9686208},
		{"specforce_technician_caveTalusDetainmentCenter", 300, -57.0, -9.0, 47.0, -96, 9686214, 9686208},
		{"specforce_technician_caveTalusDetainmentCenter", 300, -52.0, -9.0, 43.3, 91, 9686214, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, -47.0, -9.0, 26.0, -176, 9686213, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, -31.2, -9.0, 28.8, -2, 9686213, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, 14.5, -17.0, 59.8, 85, 9686215, 9686208},
		{"specforce_marine_caveTalusDetainmentCenter", 300, 26.0, -17.0, 67.0, 73, 9686215, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 25.0, -17.0, 58.8, -125, 9686215, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 34.2, -17.0, 66.9, 4, 9686215, 9686208},
		{"rebel_army_captain_caveTalusDetainmentCenter", 300, 34.6, -17.0, 61.0, 98, 9686215, 9686208},
		{"senior_specforce_infiltrator_caveTalusDetainmentCenter", 300, -17.3, -23.0, 227.3, 168, 9686222, 9686208},
		{"senior_specforce_infiltrator_caveTalusDetainmentCenter", 300, -18.0, -23.0, 232.7, -102, 9686222, 9686208},
		{"rebel_lieutenant_colonel_caveTalusDetainmentCenter", 300, -25.5, -23.0, 233.4, -93, 9686222, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 14.0, -23.0, 192.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 14.0, -23.0, 189.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 14.0, -23.0, 186.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 14.0, -23.0, 183.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 10.0, -23.0, 192.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 10.0, -23.0, 189.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 10.0, -23.0, 186.3, 0, 9686217, 9686208},
		{"rebel_trooper_caveTalusDetainmentCenter", 300, 10.0, -23.0, 183.3, 0, 9686217, 9686208},
		{"rebel_first_lieutenant_caveTalusDetainmentCenter", 300, 6.8, -23.0, 203.1, -9, 9686217, 9686208},
		{"rebel_lieutenant_general_caveTalusDetainmentCenter", 600, -79.8, -23.0, 259.1, 89, 9686223, 9686208},
		{"specops_alliance_free_agent_caveTalusDetainmentCenter", 600, 43.2, -23.0, 278.3, -177, 9686225, 9686208},
		{"lesser_prophet_of_the_light_side_caveTalusDetainmentCenter", 10800, -3.7, -23.0, 269.5, 90, 9686224, 9686208},
	},
	
	ScreenImperialSpawns = {
		{"imperial_staff_corporal_caveTalusDetainmentCenter", 300, 3.5, -9.0, 32.6, 179, 9686212, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, 4.8, -9.0, 35.1, 179, 9686212, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, 2.2, -9.0, 35.1, 179, 9686212, 9686208},
		{"imperial_warrant_officer_i_caveTalusDetainmentCenter", 300, -52.6, -9.0, -6.6, -88, 9686214, 9686208},
		{"imperial_private_caveTalusDetainmentCenter", 300, -58.4, -9.0, 7.1, 150, 9686214, 9686208},
		{"imperial_noncom_caveTalusDetainmentCenter", 300, -72.9, -9.0, 21.2,  165, 9686214, 9686208},
		{"imperial_staff_corporal_caveTalusDetainmentCenter", 300, -54.5, -9.0, 67.1, 179, 9686214, 9686208},
		{"imperial_noncom_caveTalusDetainmentCenter", 300, -52.3, -9.0, 63.2, 90, 9686214, 9686208},
		{"imperial_noncom_caveTalusDetainmentCenter", 300, -53.2, -9.0, 59.0, 90, 9686214, 9686208},
		{"imperial_noncom_caveTalusDetainmentCenter", 300, -57.0, -9.0, 60.9, -120, 9686214, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, -24.9, -9.0, 28.5, 90, 9686213, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, -24.8, -9.0, 26.0, 90, 9686213, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, 12.1, -17.0, 65.0, 179, 9686215, 9686208},
		{"command_security_guard_caveTalusDetainmentCenter", 300, 12.1, -17.0, 62.0, -1, 9686215, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, 30.4, -17.0, 60.7, 1, 9686215, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, 30.4, -17.0, 65.9, 179, 9686215, 9686208},
		{"imperial_army_captain_caveTalusDetainmentCenter", 300, 34.5, -17.0, 63.5, -90, 9686215, 9686208},
		{"dark_trooper_caveTalusDetainmentCenter", 300, -1.2, -23.0, 225.4, 179, 9686222, 9686208},
		{"dark_trooper_caveTalusDetainmentCenter", 300, -3.8, -23.0, 225.4, 179, 9686222, 9686208},
		{"imperial_first_lieutenant_caveTalusDetainmentCenter", 300, -19.8, -23.0, 234.4, 179, 9686222, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, 1.0, -23.0, 192.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -2.0, -23.0, 192.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -5.0, -23.0, 192.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -8.0, -23.0, 192.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, 1.0, -23.0, 196.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -2.0, -23.0, 196.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -5.0, -23.0, 196.3, 90, 9686217, 9686208},
		{"stormtrooper_caveTalusDetainmentCenter", 300, -8.0, -23.0, 196.3, 90, 9686217, 9686208},
		{"imperial_first_lieutenant_caveTalusDetainmentCenter", 300, 7.1, -23.0, 198.5, -135, 9686217, 9686208},
		{"imperial_inquisitor_caveTalusDetainmentCenter", 900, -80.5, -23.0, 259.4, 88, 9686223, 9686208},
		{"stormtrooper_colonel_caveTalusDetainmentCenter", 600, 45.2, -23.0, 276.3, -179, 9686225, 9686208},
		{"senior_prophet_of_the_dark_side_caveTalusDetainmentCenter", 10800, -2.7, -23.0, 268.5, 90, 9686224, 9686208},
	}
}

registerScreenPlay("TalusDetainmentCenterScreenPlay", true)

function TalusDetainmentCenterScreenPlay:start()
	if (isZoneEnabled("talus")) then
		local pBuilding = getSceneObject(self.buildingID)
		createObserver(FACTIONBASEFLIPPED, "TalusDetainmentCenterScreenPlay", "flipBase", pBuilding)

		if getRandomNumber(100) >= 50 then
			self:spawnRebels(pBuilding)
		else
			self:spawnImperials(pBuilding)
		end
	end
end

function TalusDetainmentCenterScreenPlay:flipBase(pBuilding)
	if (pBuilding == nil) then
		return 1
	end

	BuildingObject(pBuilding):destroyChildObjects()

	if BuildingObject(pBuilding):getFaction() == FACTIONIMPERIAL then
		self:spawnRebels(pBuilding)
	elseif BuildingObject(pBuilding):getFaction() == FACTIONREBEL then
		self:spawnImperials(pBuilding)
	end

	return 0
end

function TalusDetainmentCenterScreenPlay:spawnImperials(pBuilding)
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONIMPERIAL)

	BuildingObject(pBuilding):spawnChildSceneObject("object/tangible/gcw/flip_banner_onpole_imperial.iff", 3.5, -9.0, 35.1, 9686212, 1, 0, 0, 0)

	self:spawnImperialMobiles(pBuilding)

end

function TalusDetainmentCenterScreenPlay:spawnRebels(pBuilding)
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONREBEL)

	BuildingObject(pBuilding):spawnChildSceneObject("object/tangible/gcw/flip_banner_onpole_rebel.iff", 3.5, -9.0, 35.1, 9686212, 1, 0, 0, 0)

	self:spawnRebelMobiles(pBuilding)

end

