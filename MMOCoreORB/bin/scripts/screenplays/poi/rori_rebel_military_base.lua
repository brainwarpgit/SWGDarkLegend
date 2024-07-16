local ObjectManager = require("managers.object.object_manager")

RoriRebelMilitaryBaseScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	buildingID = 7555646,
	screenplayName = "RoriRebelMilitaryBaseScreenPlay",
	
	ScreenImperialSpawns = {
		-- Outside spot 1
		{"stormtrooper_commando_poiRoriRebelMilitaryBase", 360, -5307.530, 75.894, 5009.310, 82.711, 0, 0},
		{"stormtrooper_commando_poiRoriRebelMilitaryBase", 360, -5311.120, 76.009, 5012.210, 176.000, 0, 0},
		{"stormtrooper_captain_poiRoriRebelMilitaryBase", 360, -5313.580, 76.062, 5007.680, 80.422, 0, 0},
		-- Right tent
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5316.700, 76.001, 5070.840, 39.227, 0, 0},
		{"stormtrooper_medic_poiRoriRebelMilitaryBase", 360, -5318.290, 76.012, 5075.460, -177.504, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5319.400, 76.000, 5070.660, 0.794, 0, 0},
		-- Green factory
		{"stormtrooper_medic_poiRoriRebelMilitaryBase", 360, -5341.730, 76.000, 5087.920, 11.237, 0, 0},
		{"stormtrooper_sniper_poiRoriRebelMilitaryBase", 360, -5339.400, 76.000, 5087.770, 83.172, 0, 0},
		-- Right tower
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5334.020, 80.010, 5067.550, 135.727, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5334.660, 80.010, 5068.880, 34.843, 0, 7555646},
		-- Central lawn
		{"stormtrooper_commando_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5370, 76, getRandomNumber(16) + 5049, getRandomNumber(180) + -90, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5362.500, 76.000, 5067.360, -161.201, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5367.130, 76.000, 5066.420, 114.595, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5368.140, 76.000, 5061.860, 135.653, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5362.830, 76.000, 5061.750, 34.561, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"stormtrooper_sniper_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"stormtrooper_squad_leader_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"stormtrooper_medic_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"stormtrooper_rifleman_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		-- Left supplies
		{"stormtrooper_medic_poiRoriRebelMilitaryBase", 360, -5393.190, 76.000, 5062.330, 50.886, 0, 0},
		{"stormtrooper_captain_poiRoriRebelMilitaryBase", 360, -5397.430, 76.000, 5065.170, 71.564, 0, 0},
		-- Left tower
		{"stormtrooper_rifleman_poiRoriRebelMilitaryBase", 360, -5374.270, 80.010, 5034.760, 54.368, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5376.280, 80.010, 5037.600, 35.632, 0, 0},
		-- Left tent with food table
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5349.220, 76.000, 4995.770, -156.473, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5352.580, 76.000, 4995.850, 149.354, 0, 0},
		-- Ion-fusion generator
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5363.020, 76.000, 4999.490, 71.912, 0, 0},
		-- Central tower
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5330.110, 83.010, 5012.140, -173.436, 0, 0},
		{"stormtrooper_major_poiRoriRebelMilitaryBase", 360, -5323.650, 83.010, 5013.930, 90.476, 0, 0},
		{"stormtrooper_sniper_poiRoriRebelMilitaryBase", 360, -5324.660, 83.010, 5021.500, 11.254, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5327.590, 83.010, 5015.240, 127.087, 0, 0},
		-- Right building
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -3.753, 0.125, -1.790, 91.608, 7555645, 7555646},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, 0.208, 0.125, -5.539, 15.788, 7555642, 7555646},
		{"stormtrooper_squad_leader_poiRoriRebelMilitaryBase", 360, 4.173, 0.125, -3.947, 87.468, 7555644, 7555646},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, 3.233, 0.125, -2.203, 0.162, 7555644, 7555646},
		-- Left building
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, 0.616, 0.125, -5.619, 127.514, 7555635, 7555646},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, 3.865, 0.125, -4.194, 89.946, 7555637, 7555646},
		{"stormtrooper_colonel_poiRoriRebelMilitaryBase", 360, 3.633, 0.125, -2.190, 137.113, 7555637, 7555646},
		{"stormtrooper_rifleman_poiRoriRebelMilitaryBase", 360, 3.252, 0.125, 3.604, -91.859, 7555636, 7555646},
		-- Outside spot 2
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5337.310, 75.920, 4982.150, 109.938, 0, 0},
		{"stormtrooper_poiRoriRebelMilitaryBase", 360, -5331.610, 76.156, 4982.920, -121.976, 0, 0},
		-- Outside viewpoint hill
		{"stormtrooper_sniper_poiRoriRebelMilitaryBase", 360, -5249.920, 89.554, 4968.660, 137.738, 0, 0},
		{"stormtrooper_sniper_poiRoriRebelMilitaryBase", 360, -5253.200, 89.623, 4966.770, -168.074, 0, 0},
	},

	ScreenRebelSpawns = {
		-- Outside spot 1
		{"specforce_wilderness_operative_poiRoriRebelMilitaryBase", 360, -5307.530, 75.894, 5009.310, 82.711, 0, 0},
		{"specforce_wilderness_operative_poiRoriRebelMilitaryBase", 360, -5311.120, 76.009, 5012.210, 176.000, 0, 0},
		{"specforce_lieutenant_poiRoriRebelMilitaryBase", 360, -5313.580, 76.062, 5007.680, 80.422, 0, 0},
		-- Right tent
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5316.700, 76.001, 5070.840, 39.227, 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5318.290, 76.012, 5075.460, -177.504, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5319.400, 76.000, 5070.660, 0.794, 0, 0},
		-- Green factory
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5341.730, 76.000, 5087.920, 11.237, 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5339.400, 76.000, 5087.770, 83.172, 0, 0},
		-- Right tower
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5334.020, 80.010, 5067.550, 135.727, 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5334.660, 80.010, 5068.880, 34.843, 0, 0},
		-- Central lawn
		{"specforce_interrogator_poiRoriRebelMilitaryBase", 360, -5362.500, 76.000, 5067.360, -161.201, 0, 0},
		{"specforce_major_poiRoriRebelMilitaryBase", 360, -5367.130, 76.000, 5066.420, 114.595, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5368.140, 76.000, 5061.860, 135.653, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5362.830, 76.000, 5061.750, 34.561, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5334, 76, getRandomNumber(12) + 5035, getRandomNumber(360), 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"specforce_lieutenant_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 300, getRandomNumber(12) + -5357, 76, getRandomNumber(12) + 5008, getRandomNumber(360), 0, 0},
		-- Left supplies
		{"specforce_procurement_specialist_poiRoriRebelMilitaryBase", 360, -5393.190, 76.000, 5062.330, 50.886, 0, 0},
		{"specforce_procurement_specialist_poiRoriRebelMilitaryBase", 360, -5397.430, 76.000, 5065.170, 71.564, 0, 0},
		-- Left tower
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5374.270, 80.010, 5034.760, 54.368, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5376.280, 80.010, 5037.600, 35.632, 0, 0},
		-- Left tent with food table
		{"specforce_interrogator_poiRoriRebelMilitaryBase", 360, -5349.220, 76.000, 4995.770, -156.473, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5352.580, 76.000, 4995.850, 149.354, 0, 0},
		-- Ion-fusion generator
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5363.020, 76.000, 4999.490, 71.912, 0, 0},
		-- Central tower
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5330.110, 83.010, 5012.140, -173.436, 0, 0},
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -5323.650, 83.010, 5013.930, 90.476, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5324.660, 83.010, 5021.500, 11.254, 0, 0},
		{"rebel_specforce_captain_poiRoriRebelMilitaryBase", 360, -5327.590, 83.010, 5015.240, 127.087, 0, 0},
		-- Right building
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, -3.753, 0.125, -1.790, 91.608, 7555645, 7555646},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, 0.208, 0.125, -5.539, 15.788, 7555642, 7555646},
		{"rebel_specforce_sergeant_poiRoriRebelMilitaryBase", 360, 4.173, 0.125, -3.947, 87.468, 7555644, 7555646},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, 3.233, 0.125, -2.203, 0.162, 7555644, 7555646},
		-- Left building
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, 0.616, 0.125, -5.619, 127.514, 7555635, 7555646},
		{"specforce_technician_poiRoriRebelMilitaryBase", 360, 3.865, 0.125, -4.194, 89.946, 7555637, 7555646},
		{"rebel_specforce_colonel_poiRoriRebelMilitaryBase", 360, 3.633, 0.125, -2.190, 137.113, 7555637, 7555646},
		{"specforce_interrogator_poiRoriRebelMilitaryBase", 360, 3.252, 0.125, 3.604, -91.859, 7555636, 7555646},
		-- Outside spot 2
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5337.310, 75.920, 4982.150, 109.938, 0, 0},
		{"specforce_marine_poiRoriRebelMilitaryBase", 360, -5331.610, 76.156, 4982.920, -121.976, 0, 0},
		-- Outside viewpoint hill
		{"specforce_wilderness_operative_poiRoriRebelMilitaryBase", 360, -5249.920, 89.554, 4968.660, 137.738, 0, 0},
		{"specforce_wilderness_operative_poiRoriRebelMilitaryBase", 360, -5253.200, 89.623, 4966.770, -168.074, 0, 0},
	}
}

registerScreenPlay("RoriRebelMilitaryBaseScreenPlay", true)

function RoriRebelMilitaryBaseScreenPlay:start()
	if isZoneEnabled("rori") then
		local pBuilding = getSceneObject(self.buildingID)
		if (pBuilding ~= nil) then
			createObserver(FACTIONBASEFLIPPED, "RoriRebelMilitaryBaseScreenPlay", "flipBase", pBuilding)

			if getRandomNumber(100) >= 50 then
				self:spawnRebels(pBuilding)
			else
				self:spawnImperials(pBuilding)
			end
		end
	end
end

function RoriRebelMilitaryBaseScreenPlay:flipBase(pBuilding)
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

function RoriRebelMilitaryBaseScreenPlay:spawnImperials(pBuilding)
	if (pBuilding == nil) then
		return
	end
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONIMPERIAL)
	self:spawnImperialMobiles(pBuilding)
end

function RoriRebelMilitaryBaseScreenPlay:spawnRebels(pBuilding)
	if (pBuilding == nil) then
		return
	end
	BuildingObject(pBuilding):initializeStaticGCWBase(FACTIONREBEL)
	self:spawnRebelMobiles(pBuilding)
end
