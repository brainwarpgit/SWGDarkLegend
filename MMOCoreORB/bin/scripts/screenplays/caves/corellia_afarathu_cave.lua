AfarathuCaveScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	
	screenplayName = "AfarathuCaveScreenPlay",
	
	lootContainers = {
		8075612,
		8075613,
		8075614,
		8075615,
		8075616
	},
	
	lootLevel = 26,	

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 200000},
				{group = "junk", chance = 7600000},
				{group = "heavy_weapons_consumable", chance = 500000},
				{group = "rifles", chance = 500000},
				{group = "carbines", chance = 500000},
				{group = "pistols", chance = 500000},
				{group = "clothing_attachments", chance = 100000},
				{group = "armor_attachments", chance = 100000}
			},
			lootChance = 8000000
		}					
	},
	
	lootContainerRespawn = 1800, -- 30 minutes
	
	ScreenPSpawns = {
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, -2489.6, 17, 2920.0, 0, 0},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, -2494.0, 18, 2913.6, 0, 0},

		-- inside cave
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, -0.6, -13.7, -8.3, 0, 6035620},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, 11.3, -14.2, -5.5, 0, 6035620},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, 9.7, -23.9, -28.3, 0, 6035621},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, -11.3, -30.7, -27.1, 0, 6035621},

		{"corellia", "afarathu_cult_follower_caveCorelliaAfarathuCave", 300, -1.8, -40.7, -74.1, 0, 6035622},
		{"corellia", "afarathu_cult_follower_caveCorelliaAfarathuCave", 300, 2.6, -40.4, -62.4, 0, 6035622},
		{"corellia", "afarathu_cult_follower_caveCorelliaAfarathuCave", 300, 3.4, -41.0, -72.6, 0, 6035622},

		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, 49.3, -46.8, -53.7, 0, 6035623},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, 43.8, -46.1, -95.1, 0, 6035623},
		{"corellia", "afarathu_ruffian_caveCorelliaAfarathuCave", 300, 23.6, -45.7, -102.8, 0, 6035623},

		{"corellia", "afarathu_savage_caveCorelliaAfarathuCave", 300, -1.7, -45.8, -147.8, 0, 6035624},
		{"corellia", "afarathu_savage_caveCorelliaAfarathuCave", 300, -11.0, -44.4, -136.4, 0, 6035624},
		{"corellia", "afarathu_savage_caveCorelliaAfarathuCave", 300, -4.2, -64.0, -234.2, 0, 6035626},
		{"corellia", "afarathu_savage_caveCorelliaAfarathuCave", 300, -21.7, -65.4, -244.6, 0, 6035626},

		{"corellia", "afarathu_cult_follower_caveCorelliaAfarathuCave", 300, -95.3, -73.7, -170.0, 0, 6035627},
		{"corellia", "afarathu_brute_caveCorelliaAfarathuCave", 300, -83.5, -71.6, -169.2, 0, 6035627},
		{"corellia", "afarathu_brute_caveCorelliaAfarathuCave", 300, -100.5, -72.9, -159.1, 0, 6035627},
		{"corellia", "afarathu_brute_caveCorelliaAfarathuCave", 300, -111.7, -69.4, -170.6, 0, 6035627},

		{"corellia", "afarathu_brute_caveCorelliaAfarathuCave", 300, -85.4, -101.5, -111.2, 0, 6035630},
		{"corellia", "afarathu_brute_caveCorelliaAfarathuCave", 300, -92.8, -101.1, -111.9, 0, 6035630},
		{"corellia", "afarathu_cult_leader_caveCorelliaAfarathuCave", 300, -90.7, -101.1, -104.8, 0, 6035630},
	}
}

registerScreenPlay("AfarathuCaveScreenPlay", true)

function AfarathuCaveScreenPlay:start()
	if (isZoneEnabled("corellia")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
	end
end
