RancorCaveScreenPlay = ScreenPlay:new {
    numberOfActs = 1,
--4226, 2062 cave enterence
--ID 4335462
    screenplayName = "RancorCaveScreenPlay",

    lootContainers = {
		9815402,
        9815403,
        9815404,
        9815405,
        9815406,
        9815412
	},

	lootLevel = 26,

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 160000},
				{group = "junk", chance = 7240000},
				{group = "heavy_weapons_consumable", chance = 500000},
				{group = "rifles", chance = 500000},
				{group = "carbines", chance = 500000},
				{group = "pistols", chance = 500000},
				{group = "clothing_attachments", chance = 300000},
				{group = "armor_attachments", chance = 300000}
			},
			lootChance = 8000000
		}
	},

	lootContainerRespawn = 1800, -- 30 minutes
	
	ScreenPSpawns = {
	        --Cell[4335463]
		{"dathomir", "enraged_bull_rancor_caveDathomirRancorCave", 3600, -23.6, -27.5, -8.1, 87, 4335463},

		--Cell[4335464]
		{"dathomir", "enraged_rancor_caveDathomirRancorCave", 3600, -23.8, -42.4, -64.0, 0, 4335464},
		{"dathomir", "enraged_rancor_caveDathomirRancorCave", 3600, -50.6, -48.9, -61.7, 127, 4335464},
		{"dathomir", "gnarled_rancor_caveDathomirRancorCave", 3600, -49.1, -47.4, -12.0, 177, 4335464},
		{"dathomir", "enraged_rancor_caveDathomirRancorCave", 3600, -54.4, -68.3, -40.0, -82, 4335464},

		--Cell[4335473]
		{"dathomir", "enraged_bull_rancor_caveDathomirRancorCave", 3600, -93.4, -46.6, -128.6, 3, 4335473},
		  --Youths
		{"dathomir", "rancor_youth_caveDathomirRancorCave", 3600, -81.3, -46.2, -137.8, 152, 4335473},
		{"dathomir", "rancor_youth_caveDathomirRancorCave", 3600, -72.7, -45.6, -139.7, -123, 4335473},
		{"dathomir", "rancor_youth_caveDathomirRancorCave", 3600, -77.6, -45.8, -148.0, -19, 4335473},

		--Cell[4335465]
		{"dathomir", "mutant_rancor_caveDathomirRancorCave", 3600, -87.1, -62.2, -14.9, -178, 4335465},

		--Cell[4335466]
		{"dathomir", "gnarled_rancor_caveDathomirRancorCave", 3600, -79.0, -76.7, -89.2, 4, 4335466},

		--Cell[4335467]
		{"dathomir", "mutant_rancor_caveDathomirRancorCave", 3600, -95.4, -66.3, -109.3, 172, 4335467},

		--Cell[4335470]
		  --Mutant/Enraged
		{"dathomir", "enraged_bull_rancor_caveDathomirRancorCave", 3600, -130.4, -66.8, -107.7, 91, 4335470},
		  --Youths
		{"dathomir", "rancor_youth_caveDathomirRancorCave", 3600, -151.6, -66.5, -125.0, 69, 4335470},
		{"dathomir", "rancor_youth_caveDathomirRancorCave", 3600, -132.8, -66.6, -121.8, -82, 4335470},

		  --Ancient
		--Cell[4335471]
		{"dathomir", "ancient_bull_rancor_caveDathomirRancorCave", 5400, -189.9, -66.5, -102.1, 87, 4335471},
		{"dathomir", "ancient_bull_rancor_caveDathomirRancorCave", 5400, -4224.2, 25.3, -2091.7, 132, 0},
	}
}

registerScreenPlay("RancorCaveScreenPlay", true)

function RancorCaveScreenPlay:start()
	if (isZoneEnabled("dathomir")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
	end
end


