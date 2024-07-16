TalusChunkerBunkerScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TalusChunkerBunkerScreenPlay",

	lootContainers = {
		7955606,
		7955613
	},

	lootLevel = 15,

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 160000},
				{group = "junk", chance = 7740000},
				{group = "weapons_all", chance = 1500000},
				{group = "clothing_attachments", chance = 300000},
				{group = "armor_attachments", chance = 300000}
			},
			lootChance = 8000000
		}
	},

	lootContainerRespawn = 1800, -- 30 minutes
	
	ScreenPSpawns = {
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 1382.5, 29.0, 1465.2, 119,  0},
		{"talus", "chunker_punk_caveTalusChunkerBunker", 300, 1370.0, 29.0, 1456.8, -177, 0},
   		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 1366.9, 29.0, 1468.9, -83, 0},
	
		{"talus", "chunker_goon_caveTalusChunkerBunker", 300, -2.6, -12.0, 33.1, -150, 7955555},
		{"talus", "chunker_pest_caveTalusChunkerBunker", 300, -0.8, -12.0, 27.0, 165, 7955555},
		{"talus", "chunker_mooch_caveTalusChunkerBunker", 300, 6.3, -12.0, 27.2, 70, 7955555},
		{"talus", "chunker_swindler_caveTalusChunkerBunker", 300, 6.0, -12.0, 35.5, 100, 7955555},
		
		{"talus", "chunker_goon_caveTalusChunkerBunker", 300, 35.1, -12.0, 34.0, 96, 7955556},
		{"talus", "chunker_braggart_caveTalusChunkerBunker", 300, 32.1, -12.0, 27.2, -73, 7955556},
		{"talus", "chunker_creep_caveTalusChunkerBunker", 300, 27.3, -12.0, 33.9, -98, 7955556},
		{"talus", "chunker_creep_caveTalusChunkerBunker", 300, 26.0, -12.0, 26.2, -22, 7955556},

		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, 9.5, -16.0, 62.7, 151, 7955558},
		{"talus", "chunker_creep_caveTalusChunkerBunker", 300, -1.1, -16.0, 56.7, -121, 7955558},
		{"talus", "chunker_braggart_caveTalusChunkerBunker", 300, -3.7, -16.0, 58.4, -169, 7955558},
		{"talus", "chunker_braggart_caveTalusChunkerBunker", 300, -3.0, -16.0, 63.6, -100, 7955558},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, -9.1, -16.0, 81.8, 91, 7955558},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, -13.3, -16.0, 75.4, 77, 7955558},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, -24.6, -14.9, 78.8, -90, 7955558},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, 4.0, -16.0, 84.5, -1, 7955558},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, 19.4, -16.0, 83.1, -104, 7955558},
		{"talus", "chunker_goon_caveTalusChunkerBunker", 300, 19.0, -16.0, 76.1, -86, 7955558},
		{"talus", "chunker_goon_caveTalusChunkerBunker", 300, 30.7, -16.0, 79.5, -2, 7955558},

		{"talus", "chunker_bruiser_caveTalusChunkerBunker", 300, -42.7, -14.0, 79.0, 90, 7955575},
		{"talus", "chunker_bruiser_caveTalusChunkerBunker", 300, -35.9, -14.0, 73.4, -179, 7955575},
		{"talus", "chunker_bruiser_caveTalusChunkerBunker", 300, -33.9, -14.0, 82.2, 108, 7955575},

		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 41.4, -16.9, 60.0, 48, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 50.3, -16.0, 68.9, -3, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 54.6, -16.0, 63.1, 106, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 69.2, -16.0, 59.1, 128, 7955574},
		{"talus", "chunker_swindler_caveTalusChunkerBunker", 300, 79.0, -16.0, 58.7, 88, 7955574},
		{"talus", "chunker_swindler_caveTalusChunkerBunker", 300, 80.2, -16.0, 65.8, 46, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 81.5, -16.0, 74.8, 118, 7955574},
		{"talus", "chunker_swindler_caveTalusChunkerBunker", 300, 77.6, -16.0, 84.9, -7, 7955574},
		{"talus", "chunker_bully_caveTalusChunkerBunker", 300, 67.0, -16.0, 80.9, -110, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 55.0, -16.0, 75.9, -164, 7955574},
		{"talus", "chunker_nitwit_caveTalusChunkerBunker", 300, 45.9, -16.0, 85.8, -38, 7955574},
	}
}
 
registerScreenPlay("TalusChunkerBunkerScreenPlay", true)
 
function TalusChunkerBunkerScreenPlay:start()
	if (isZoneEnabled("talus")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
        end
end

