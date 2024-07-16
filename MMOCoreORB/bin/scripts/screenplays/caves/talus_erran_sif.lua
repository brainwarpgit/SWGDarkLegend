TalusErranSifScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TalusErranSifScreenPlay",

	lootContainers = {
		134417,
		134416,
		134414,
		134415,
		134413,
		134412,
		9815510
	},

	lootLevel = 26,

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 160000},
				{group = "junk", chance = 8240000},
				{group = "weapons_all", chance = 1000000},
				{group = "clothing_attachments", chance = 300000},
				{group = "armor_attachments", chance = 300000}
			},
			lootChance = 8000000
		}
	},

	lootContainerRespawn = 1800, -- 30 minutes
	
	ScreenPSpawns = {
		{"talus", "erran_sif_caveTalusErranSif", 300, -4.9, -13.8, -16.5, 14, 9815433},
		{"talus", "hirsch_sif_caveTalusErranSif", 300, -8.0, -13.8, -12.5, 63, 9815433},
		{"talus", "doak_sif_caveTalusErranSif", 300, 1.9, -13.8, -12.9, -38, 9815433},
		{"talus", "rodian_sif_02_caveTalusErranSif", 300, -7.0, -13.8, 1.7, 110, 9815433},
		{"talus", "trandoshan_sif_02_caveTalusErranSif", 300, 4.1, -6.8, -2.2, -48, 9815431},
		{"talus", "trandoshan_sif_02_caveTalusErranSif", 300, 7.0, -6.8, -2.6, 164, 9815431},
		{"talus", "rodian_sif_02_caveTalusErranSif", 300, 4.8, -6.8, -9.0, 164, 9815431},	
		{"talus", "trandoshan_sif_02_caveTalusErranSif", 300, 4.2, -6.8, -15.3, -112, 9815430},
		{"talus", "rodian_sif_caveTalusErranSif", 300, 6.3, -6.8, -15.7, -92, 9815430},
		{"talus", "trandoshan_sif_02_caveTalusErranSif", 300, -1.1, -6.8, -6.3, -63, 9815429},
		{"talus", "rodian_sif_02_caveTalusErranSif", 300, -3.7, 0.3, -2.2, -9, 9815426},
		{"talus", "sif_mercenary_caveTalusErranSif", 300, 2143.4, 122.0, -5610.2, -44, 0},
		{"talus", "trandoshan_sif_02_caveTalusErranSif", 300, 2152.0, 122.0, -5611.0, 68, 0},
	}
}
 
registerScreenPlay("TalusErranSifScreenPlay", true)
 
function TalusErranSifScreenPlay:start()
	if (isZoneEnabled("talus")) then
		self:initializeLootContainers()
		self:spawnScreenPMobiles()
        end
end

