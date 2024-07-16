DrallCaveScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "DrallCaveScreenPlay",
	
	lootContainers = {
		6036047,
		6036048,
		6036049,
		6036050,
		6036051
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
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,14.2,-22.5,-7.6,-87,4275365},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,23.4,-27.8,-9,175,4275365},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,91.6,-46.5,-107,-94,4275369},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,89.9,-46.3,-117.6,-63,4275369},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,88.7,-62.1,-17.3,162,4275367},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,93.1,-62.6,-19.8,-108,4275367},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,90.6,-63.3,-23.8,10,4275367},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,96.9,-65.8,-111,-7,4275369},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,95.8,-66.6,-107.1,172,4275369},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,146.5,-67.3,-122.4,-40,4275372},
		{"corellia", "drall_patriot_caveCorelliaDrallCave",360,149.9,-67.1,-122.7,12,4275372},
		
		{"corellia", "drall_patriot_conqueror_caveCorelliaDrallCave",360,52,-48.7,-103.6,-1,4275374},
		{"corellia", "drall_patriot_conqueror_caveCorelliaDrallCave",360,91.5,-46.7,-143.1,-5,4275375},
		{"corellia", "drall_patriot_conqueror_caveCorelliaDrallCave",360,53.8,-68.2,-41.9,52,4275366},
		{"corellia", "drall_patriot_conqueror_caveCorelliaDrallCave",360,181.8,-66,-95.2,-111,4275373},
		
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,112.9,-66.8,-101.7,7,4275372},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,113.9,-66.8,-98.2,-162,4275372},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,92.7,-75.8,-67.9,-58,4275368},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,86.2,-76.7,-64.9,111,4275368},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,49.7,-48.5,-57.3,178,4275366},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,49.9,-48.4,-66,-8,4275366},
		{"corellia", "drall_patriot_foot_soldier_caveCorelliaDrallCave",360,30.9,-44.3,-69,88,4275366},
		
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,182.3,-65.8,-100.5,-82,4275373},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,86.1,-66.7,-139.5,-103,4275371},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,71.4,-66.2,-139.6,92,4275371},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,57.9,-68.3,-35.9,90,4275366},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,46.8,-47.2,-12.5,-173,4275366},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,48,-47,-7.2,98,4275366},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,94.9,-46.7,-136.7,-47,4275375},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,86.5,-46.8,-138.9,65,4275375},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,23,-42.3,-65.4,0,4275366},
		{"corellia", "drall_patriot_legionnaire_caveCorelliaDrallCave",360,23.7,-38.5,-33.6,-179,4275366},
	}
}

registerScreenPlay("DrallCaveScreenPlay", true)

function DrallCaveScreenPlay:start()
	if (isZoneEnabled("corellia")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
	end
end


