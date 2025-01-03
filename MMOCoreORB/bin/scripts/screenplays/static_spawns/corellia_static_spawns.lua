--This is to be used for static spawns that are NOT part of caves, cities, dungeons, poi's, or other large screenplays.
local ObjectManager = require("managers.object.object_manager")

CorelliaStaticSpawnsScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "CorelliaStaticSpawnsScreenPlay",

	turretRespawn = 300, -- In Seconds

	turret = { template = "object/installation/turret/turret_dish_sm.iff", x = 4111.26, z = 24, y = -1274.28 },

	ScreenPSpawns = {
		--random Power Plant (643 -429},
		{"corellia", "twilek_slave", 60,621.013,26.31,-435.848,-50,0,0,"sad"},
		{"corellia", "surgical_droid_21b", 60,632.614,26.8166,-438.739,135,0,0,"neutral"},
		{"corellia", "twilek_slave", 60,637.195,26.9908,-434.182,135,0,0,"npc_use_terminal_high"},
		{"corellia", "r4", 60,637.837,27.0342,-433.138,-172,0,0,"neutral"},
		{"corellia", "r5", 60,620.512,26.3006,-437.168,-25,0,0,"worried"},
		{"corellia", "seeker", 60,626.362,26.6092,-440.824,-45,0,0,"neutral"},
		{"corellia", "contractor", 60,618.957,26.2465,-433.424,130,0,0,"angry"},
	
		--Rebels vs Imps (4112 -1252}, Smoking small Rebel base
		{"corellia", "rebel_army_captain", 360,5.2,0.1,-3.6,-93,6036092},
		{"corellia", "rebel_medic", 360,-4.4,0.1,-1.2,-11,6036093},
		{"corellia", "rebel_commando", 360,4110.3,24,-1260.3,-179,0},
		{"corellia", "rebel_commando", 360,4113.2,24,-1260.4,-179,0},
		{"corellia", "rebel_trooper", 360,4096.2,24,-1271.5,83,0},
		{"corellia", "rebel_first_lieutenant", 360,4098.3,24,-1271.4,-91,0},
		{"corellia", "at_st", 360,4110.43,24.008,-1297.13,7,0},
		{"corellia", "stormtrooper", 360, 4106.75,23.9281,-1295.73,7,0},
		{"corellia", "stormtrooper", 360,4117.07,24.2994,-1293.08,-7,0},
		{"corellia", "imperial_sergeant", 360, 4115.11,24.0521,-1289.97,-5,0},
		{"corellia", "imperial_trooper", 360, 4142.95,24,-1267.66,-77,0},
		{"corellia", "imperial_trooper", 360, 4132.13,24,-1269.63,-75,0},
		{"corellia", "imperial_trooper", 360, 4075.41,26.4493,-1269.93,90,0},
		{"corellia", "imperial_trooper", 360, 4066.41,35.4493,-1268.93,90,0},

				-- Research Camp (-1421 1980},
		{"corellia", "commoner_technician", 360, -1416.0, 85.2822, 1985.7, 25, 0},
		{"corellia", "scientist", 1, -1419.6, 85.2822, 1985.4, -55, 0},
		{"corellia", "r4", 1, -1423.0, 85.2822, 1986.6, 93, 0},
		{"corellia", "scientist", 1, -1424.6, 85.2822, 1977.2, -9, 0},
		{"corellia", "scientist", 1, -1425.6, 85.2822, 1979.5, 139, 0},

		--Abandoned Tower (4950, 2900},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + 4976, 3.5, getRandomNumber(5) + 2888, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + 4976, 3.5, getRandomNumber(5) + 2888, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + 4976, 3.5, getRandomNumber(5) + 2888, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + 4976, 3.5, getRandomNumber(5) + 2888, getRandomNumber(360), 0},

		--Forgotten Spires (750, 2500},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + 755, 393.6, getRandomNumber(10) + 2509, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + 755, 393.6, getRandomNumber(10) + 2509, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + 755, 393.6, getRandomNumber(10) + 2509, getRandomNumber(360), 0},

		--Mysterious Shrine (-6900, 4500},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -6919, 449.7, getRandomNumber(5) + 4506, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -6919, 449.7, getRandomNumber(5) + 4506, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -6919, 449.7, getRandomNumber(5) + 4506, getRandomNumber(360), 0},

		--Rock Formations (-1650, 6850},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + -1686, 375.3, getRandomNumber(10) + 6885, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + -1686, 375.3, getRandomNumber(10) + 6885, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(10) + -1686, 375.3, getRandomNumber(10) + 6885, getRandomNumber(360), 0},

		--Weather Station (-7400, -3900},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -7482, 236.8, getRandomNumber(5) + -3955, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -7482, 236.8, getRandomNumber(5) + -3955, getRandomNumber(360), 0},
		{"corellia", "vicious_slice_hound", 300, getRandomNumber(5) + -7482, 236.8, getRandomNumber(5) + -3955, getRandomNumber(360), 0},
	}
}

registerScreenPlay("CorelliaStaticSpawnsScreenPlay", true)

function CorelliaStaticSpawnsScreenPlay:start()
	if (isZoneEnabled("corellia")) then
		self:spawnScreenPMobiles()
		self:spawnSceneObjects()
	end
end

function CorelliaStaticSpawnsScreenPlay:spawnSceneObjects()
	local turretData = self.turret
	local pTurret = spawnSceneObject("corellia", turretData.template, turretData.x, turretData.z, turretData.y, 0, 0, 0, -1, 0)

	if pTurret ~= nil then
		local turret = TangibleObject(pTurret)
		turret:setFaction(FACTIONREBEL)
		turret:setPvpStatusBitmask(1)

		createObserver(OBJECTDESTRUCTION, "CorelliaStaticSpawnsScreenPlay", "notifyTurretDestroyed", pTurret)
	end

	spawnSceneObject("corellia", "object/static/vehicle/static_speeder_bike.iff", 615.7, 26.1, -434.0, 0, math.rad(84) )
	spawnSceneObject("corellia", "object/static/structure/general/droid_probedroid_powerdown.iff", 640.5, 27.1, -424.0, 0, math.rad(-138) )

	-- Research Camp (-1421 1980)
	spawnSceneObject("corellia", "object/tangible/furniture/all/frn_all_toolchest_lg_s01.iff", -1415.72, 85.2822, 1987.44, 0, -0.2, 0, 0.9, 0 )
	spawnSceneObject("corellia", "object/tangible/furniture/all/frn_all_toolchest_med_s01.iff", -1414.63, 85.2822, 1986.44, 0, -0.4, 0, 0.9, 0 )
	spawnSceneObject("corellia", "object/tangible/camp/campfire_logs_smoldering.iff", -1424.5, 85.2822, 1978.57, 0, 1, 0, 0, 0 )
	spawnSceneObject("corellia", "object/tangible/camp/camp_light_s2.iff", -1419.5, 85.2822, 1981.3, 0, 1, 0, 0, 0 )
	spawnSceneObject("corellia", "object/tangible/camp/camp_light_s2.iff", -1423.3, 85.2822, 1981.3, 0, 1, 0, 0, 0 )
	spawnSceneObject("corellia", "object/tangible/camp/camp_stool_tall.iff", -1419.5, 85.2822, 1978.6, 0, 1, 0, 0, 0 )
	spawnSceneObject("corellia", "object/tangible/camp/camp_stool_tall.iff", -1420.0, 85.2822, 1976.9, 0, 1, 0, 0, 0 )

end

function CorelliaStaticSpawnsScreenPlay:notifyTurretDestroyed(pTurret, pPlayer)
	if (pTurret == nil) then
		return 1
	end

	createEvent(self.turretRespawn * 1000, "CorelliaStaticSpawnsScreenPlay", "respawnTurret", "", "")

	return 1
end

function CorelliaStaticSpawnsScreenPlay:respawnTurret()
	local turretData = self.turret
	local pTurret = spawnSceneObject("corellia", turretData.template, turretData.x, turretData.z, turretData.y, 0, 0, 0, -1, 0)

	if pTurret ~= nil then
		local turret = TangibleObject(pTurret)
		turret:setFaction(FACTIONREBEL)
		turret:setPvpStatusBitmask(1)

		createObserver(OBJECTDESTRUCTION, "CorelliaStaticSpawnsScreenPlay", "notifyTurretDestroyed", pTurret)
	end
end

