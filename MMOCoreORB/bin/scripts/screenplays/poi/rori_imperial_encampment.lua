local ObjectManager = require("managers.object.object_manager")

RoriImperialEncampmentScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "RoriImperialEncampmentScreenPlay",

	buildingID = 2935404,
	
	ScreenRebelSpawns = {
		--inside the walls (not in buildings, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5506.5, 75.9, -5661.1, 90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5506.5, 75.9, -5666.9, 90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5502.5, 75.9, -5664.0, 90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5623.5, 75.9, -5665.5, -90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5623.5, 75.9, -5658.7, -90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5627.5, 75.9, -5661.6, -90, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5599.3, 75.9, -5633.7, 180, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5595.8, 75.9, -5633.7, 180, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5532.3, 75.9, -5633.7, 180, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5527.8, 75.9, -5633.7, 180, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5599.3, 75.9, -5690.0, 0, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5595.8, 75.9, -5690.0, 0, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5532.3, 75.9, -5690.0, 0, 0, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, -5527.8, 75.9, -5690.0, 0, 0, 2935404},
		{"rebel_trooper_poiRoriImperialEncampment", 300, -5569.1, 75.9, -5630.4, 0, 0, 2935404},
		{"rebel_trooper_poiRoriImperialEncampment", 300, -5562.1, 75.9, -5630.4, 0, 0, 2935404},
		--towers
		{"senior_specforce_pathfinder_poiRoriImperialEncampment", 300, -5510.3, 82.9, -5702.1, 135, 0, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, -5516.1, 82.9, -5702.4, 180, 0, 2935404},
		{"senior_specforce_pathfinder_poiRoriImperialEncampment", 300, -5508.7, 82.9, -5630.7, 90, 0, 2935404},
		{"senior_specforce_heavy_weapons_specialist_poiRoriImperialEncampment", 300, -5509.3, 82.9, -5623.6, 45, 0, 2935404},
		{"rebel_colonel_poiRoriImperialEncampment", 300, -5514.7, 82.9, -5622.7, 0, 0, 2935404},
		{"senior_specforce_pathfinder_poiRoriImperialEncampment", 300, -5612.8, 83.0, -5623.3, 0, 0, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, -5618.4, 83.0, -5623.7, -45, 0, 2935404},
		{"senior_specforce_pathfinder_poiRoriImperialEncampment", 300, -5619.4, 82.6, -5696.9, -90, 0, 2935404},
		{"senior_specforce_heavy_weapons_specialist_poiRoriImperialEncampment", 300, -5618.5, 82.6, -5702.6, -135, 0, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, -5613.1, 82.6, -5703.4, 180, 0, 2935404},
		--buildings
		{"specforce_major_poiRoriImperialEncampment", 300, 4.9, 0.0, -2.0, -135, 3475375, 2935404},
		{"senior_specforce_heavy_weapons_specialist_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 3475373, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, -3.8, 0.0, -3.6, 90, 3475376, 2935404},
		{"senior_specforce_marine_poiRoriImperialEncampment", 300, 0.0, 0.0, -3.6, 0, 3475366, 2935404},
		{"senior_specforce_heavy_weapons_specialist_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 3475366, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, 0.0, 0.0, -1.0, 0, 3475366, 2935404},
		{"senior_specforce_heavy_weapons_specialist_poiRoriImperialEncampment", 300, 3.9, 0.0, 2.1, 90, 2935496, 2935404},
		{"senior_specforce_lieutenant_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 2935495, 2935404},
		--main building
		{"rebel_surface_marshall_poiRoriImperialEncampment", 300, 1.4, 1.0, 9.9, -90, 2935406, 2935404},
		{"rebel_surface_marshall_poiRoriImperialEncampment", 300, 6.4, 1.0, -7.2, -90, 2935406, 2935404},
		{"rebel_surface_marshall_poiRoriImperialEncampment", 300, 0.0, 1.0, 0.9, 0, 2935406, 2935404},
		{"rebel_first_lieutenant_poiRoriImperialEncampment", 300, 15.7, 1.0, 15.2, 90, 2935407, 2935404},
		{"rebel_surface_marshall_poiRoriImperialEncampment", 300, -17.7, 1.0, 16.5, 180, 2935408, 2935404},
		{"rebel_major_poiRoriImperialEncampment", 300, 18.3, 1.0, -19.7, -45, 2935410, 2935404},
		{"rebel_medic_poiRoriImperialEncampment", 300, 11.7, 1.0, -19.5, 0, 2935410, 2935404},
		{"rebel_trooper_poiRoriImperialEncampment", 300, -17.5, 1.0, -19.6, 45, 2935412, 2935404},
		{"rebel_trooper_poiRoriImperialEncampment", 300, -9.2, 7.0, -13.5, 0, 2935414, 2935404},
		{"rebel_trooper_poiRoriImperialEncampment", 300, -11.7, 7.0, -13.5, 0, 2935414, 2935404},
		{"rebel_major_poiRoriImperialEncampment", 300, -11.5, 7.0, 9.3, 90, 2935415, 2935404},
		{"rebel_lieutenant_colonel_poiRoriImperialEncampment", 300, -9.1, 7.0, 12.5, 0, 2935415, 2935404},
		{"rebel_first_lieutenant_poiRoriImperialEncampment", 300, 0.0, 7.0, 12.6, 0, 2935415, 2935404},
		{"rebel_medic_poiRoriImperialEncampment", 300, 14.1, 7.0, 11.8, 60, 2935416, 2935404},
	},
	
	ScreenImperialSpawns = {
		{"at_st_poiRoriImperialEncampment", 720, -5597.3, 75.9, -5660.5, 0, 0, 2935404},
		{"at_st_poiRoriImperialEncampment", 720, -5531.5, 75.9, -5660.5, 180, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5506.5, 75.9, -5661.1, 90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5506.5, 75.9, -5666.9, 90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5502.5, 75.9, -5664.0, 90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5623.5, 75.9, -5665.5, -90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5623.5, 75.9, -5658.7, -90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5627.5, 75.9, -5661.6, -90, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5599.3, 75.9, -5633.7, 180, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5595.8, 75.9, -5633.7, 180, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5532.3, 75.9, -5633.7, 180, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5527.8, 75.9, -5633.7, 180, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5599.3, 75.9, -5690.0, 0, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5595.8, 75.9, -5690.0, 0, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5532.3, 75.9, -5690.0, 0, 0, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, -5527.8, 75.9, -5690.0, 0, 0, 2935404},
		{"assault_trooper_poiRoriImperialEncampment", 300, -5569.1, 75.9, -5630.4, 0, 0, 2935404},
		{"assault_trooper_poiRoriImperialEncampment", 300, -5562.1, 75.9, -5630.4, 0, 0, 2935404},
		--towers
		{"stormtrooper_sniper_poiRoriImperialEncampment", 300, -5510.3, 82.9, -5702.1, 135, 0, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, -5516.1, 82.9, -5702.4, 180, 0, 2935404},
		{"stormtrooper_sniper_poiRoriImperialEncampment", 300, -5508.7, 82.9, -5630.7, 90, 0, 2935404},
		{"stormtrooper_rifleman_poiRoriImperialEncampment", 300, -5509.3, 82.9, -5623.6, 45, 0, 2935404},
		{"stormtrooper_colonel_poiRoriImperialEncampment", 300, -5514.7, 82.9, -5622.7, 0, 0, 2935404},
		{"stormtrooper_sniper_poiRoriImperialEncampment", 300, -5612.8, 83.0, -5623.3, 0, 0, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, -5618.4, 83.0, -5623.7, -45, 0, 2935404},
		{"stormtrooper_sniper_poiRoriImperialEncampment", 300, -5619.4, 82.6, -5696.9, -90, 0, 2935404},
		{"stormtrooper_rifleman_poiRoriImperialEncampment", 300, -5618.5, 82.6, -5702.6, -135, 0, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, -5613.1, 82.6, -5703.4, 180, 0, 2935404},
		--buildings
		{"stormtrooper_captain_poiRoriImperialEncampment", 300, 4.9, 0.0, -2.0, -135, 3475375, 2935404},
		{"stormtrooper_rifleman_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 3475373, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, -3.8, 0.0, -3.6, 90, 3475376, 2935404},
		{"stormtrooper_poiRoriImperialEncampment", 300, 0.0, 0.0, -3.6, 0, 3475366, 2935404},
		{"stormtrooper_rifleman_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 3475366, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, 0.0, 0.0, -1.0, 0, 3475366, 2935404},
		{"stormtrooper_rifleman_poiRoriImperialEncampment", 300, 3.9, 0.0, 2.1, 90, 2935496, 2935404},
		{"stormtrooper_squad_leader_poiRoriImperialEncampment", 300, 0.0, 0.0, -5.3, 0, 2935495, 2935404},
		--main building
		{"dark_trooper_poiRoriImperialEncampment", 300, 1.4, 1.0, 9.9, -90, 2935406, 2935404},
		{"dark_trooper_poiRoriImperialEncampment", 300, 6.4, 1.0, -7.2, -90, 2935406, 2935404},
		{"dark_trooper_poiRoriImperialEncampment", 300, 0.0, 1.0, 0.9, 0, 2935406, 2935404},
		{"imperial_first_lieutenant_poiRoriImperialEncampment", 300, 15.7, 1.0, 15.2, 90, 2935407, 2935404},
		{"imperial_private_poiRoriImperialEncampment", 300, -17.7, 1.0, 16.5, 180, 2935408, 2935404},
		{"imperial_major_poiRoriImperialEncampment", 300, 18.3, 1.0, -19.7, -45, 2935410, 2935404},
		{"imperial_medic_poiRoriImperialEncampment", 300, 11.7, 1.0, -19.5, 0, 2935410, 2935404},
		{"imperial_private_poiRoriImperialEncampment", 300, -17.5, 1.0, -19.6, 45, 2935412, 2935404},
		{"dark_trooper_poiRoriImperialEncampment", 300, -9.2, 7.0, -13.5, 0, 2935414, 2935404},
		{"dark_trooper_poiRoriImperialEncampment", 300, -11.7, 7.0, -13.5, 0, 2935414, 2935404},
		{"imperial_major_poiRoriImperialEncampment", 300, -11.5, 7.0, 9.3, 90, 2935415, 2935404},
		{"imperial_lieutenant_colonel_poiRoriImperialEncampment", 300, -9.1, 7.0, 12.5, 0, 2935415, 2935404},
		{"imperial_first_lieutenant_poiRoriImperialEncampment", 300, 0.0, 7.0, 12.6, 0, 2935415, 2935404},
		{"imperial_medic_poiRoriImperialEncampment", 300, 14.1, 7.0, 11.8, 60, 2935416, 2935404},
	},

	ScreenPSpawns = {
		--outside the walls
		{"rori", "thug_poiRoriImperialEncampment", 300, -5574.1, 75.9, -5759.4, 120, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5559.4, 75.9, -5761.8, 90, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5557.3, 75.9, -5773.4, 0, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5562.1, 75.9, -5772.7, -90, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5569.1, 75.9, -5778.4, -30, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5551.1, 75.9, -5782.5, 30, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5559.1, 75.9, -5781.4, -75, 0},
		{"rori", "thug_poiRoriImperialEncampment", 300, -5562.1, 75.9, -5784.3, 45, 0},
	}
}

registerScreenPlay("RoriImperialEncampmentScreenPlay", true)

function RoriImperialEncampmentScreenPlay:start()
	if isZoneEnabled("rori") then
		local pBuilding = getSceneObject(self.buildingID)
		self:spawnScreenPMobiles()
		if (pBuilding ~= nil) then
			createObserver(FACTIONBASEFLIPPED, "RoriImperialEncampmentScreenPlay", "flipBase", pBuilding)
			if getRandomNumber(100) >= 50 then
				self:spawnRebels(pBuilding)
			else
				self:spawnImperials(pBuilding)
			end
		end
	end
end

function RoriImperialEncampmentScreenPlay:flipBase(pBuilding)
	if (pBuilding == nil) then
		return 1
	end
	BuildingObject(pBuilding):destroyChildObjects()
	if BuildingObject(pBuilding):getFaction() == FACTIONIMPERIAL then
		self:spawnRebels(pBuilding)
	else
		self:spawnImperials(pBuilding)
	end
	return 0
end

function RoriImperialEncampmentScreenPlay:spawnImperials(pBuilding)
	if (pBuilding == nil) then
		return
	end
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONIMPERIAL)
	self:spawnImperialMobiles(pBuilding)
end

function RoriImperialEncampmentScreenPlay:spawnRebels(pBuilding)
	if (pBuilding == nil) then
		return
	end
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONREBEL)
	self:spawnRebelMobiles(pBuilding)
end

