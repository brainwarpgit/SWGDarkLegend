TalusBinayrePirateBunkerScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TalusBinayrePirateBunkerScreenPlay",

	lootContainers = {
		8095746,
		8095745,
		8095744,
		178364,
		8095603,
	},

	lootLevel = 20,

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
		{"talus", "binayre_chief_caveTalusBinayrePirateBunker", 300, 12.6, -11.5, -20.7, 162, 6075880},
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, 19.2, -11.5, -20.3, -27, 6075880},
		{"talus", "binayre_smuggler_caveTalusBinayrePirateBunker", 300, 12.8, -13.8, -15.7, 179, 6075880},
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, 17.0, -13.8, -4.9, -90, 6075880},
		{"talus", "binayre_swindler_caveTalusBinayrePirateBunker", 300, 14.1, -13.8, 3.8, -60, 6075879},
		{"talus", "binayre_smuggler_caveTalusBinayrePirateBunker", 300, 16.7, -13.8, 7.6, 42, 6075879},
		{"talus", "binayre_pirate_caveTalusBinayrePirateBunker", 300, 14.4, -13.8, 14.3, -80, 6075879},
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, 8.4, -13.8, 11.8, -44, 6075878},	
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, 5.7, -13.8, 12.2, -90, 6075878},	
		{"talus", "binayre_scalawag_caveTalusBinayrePirateBunker", 300, -3.3, -13.8, 9.2, 178, 6075878},	
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, -4.9, -13.7, 1.6, 165, 6075877},	
		{"talus", "binayre_pirate_caveTalusBinayrePirateBunker", 300, -3.6, -13.7, -1.7, -31, 6075877},
		{"talus", "binayre_ruffian_caveTalusBinayrePirateBunker", 300, -2.4, -13.7, -7.9, 143, 6075877},
		{"talus", "binayre_pirate_caveTalusBinayrePirateBunker", 300, -1.7, -13.7, -10.6, -7, 6075877},
		{"talus", "binayre_scalawag_caveTalusBinayrePirateBunker", 300, 6.2, -6.8, -7.2, -15, 6075875},
		{"talus", "binayre_smuggler_caveTalusBinayrePirateBunker", 300, 3.0, -6.8, -6.3, 25, 6075875},
		{"talus", "binayre_scalawag_caveTalusBinayrePirateBunker", 300, 2.5, -6.8, -2.8, 141, 6075875},
		{"talus", "binayre_scalawag_caveTalusBinayrePirateBunker", 300, 6.4, -6.8, -3.0, -160, 6075875},
		{"talus", "binayre_hooligan_caveTalusBinayrePirateBunker", 300, -2.4, 0.3, -3.5, -50, 6075873},
		{"talus", "binayre_pirate_caveTalusBinayrePirateBunker", 300, 0.5, 0.3, 3.5, -16, 6075872},
		{"talus", "binayre_hooligan_caveTalusBinayrePirateBunker", 300, 5567.8, 102.0, -4073.0, -128, 0},
		{"talus", "binayre_hooligan_caveTalusBinayrePirateBunker", 300, 5567.1, 102.0, -4085.6, -51, 0},
	}
} 
registerScreenPlay("TalusBinayrePirateBunkerScreenPlay", true)
 
function TalusBinayrePirateBunkerScreenPlay:start()
	if (isZoneEnabled("talus")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
        end
end

