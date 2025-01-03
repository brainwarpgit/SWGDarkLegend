RoriBlackSunOutpostBunkerScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	--location 4851 -1080 (part 2 of 'Secrets of the Syren' questline)
	screenplayName = "RoriBlackSunOutpostBunkerScreenPlay",

	ScreenPSpawns = {
		--outside
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 4838.6, 76.1, -1084.6, -130, 0},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 4842.2, 76.2, -1090.2, -130, 0},

		--inside ground level
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 0.0, 0.3, 2.6, 177, 3566198},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, -3.7, 0.3, -4.5, -2, 3566198},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, -3.9, 0.3, -4.0, -91, 3566199},
		--inside first level down
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 19.0, -12.0, 28.7, -94, 3566202},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 22.9, -12.0, 35.9, -16, 3566202},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 17.5, -12.0, 60.2, -174, 3566204},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, -3.5, -12.0, 75.6, -101, 3566206},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 3.6, -12.0, 79.3, 178, 3566206},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 34.7, -12.0, 73.7, -47, 3566213},
		--inside second level down
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 33.5, -20.0, 111.7, 175, 3566214},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 45.8, -20.0, 112.5, 173, 3566215},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 46.0, -20.0, 108.6, -4, 3566215},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 50.9, -20.0, 106.6, -52, 3566215},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 50.7, -20.0, 115.1, -132, 3566215},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 47.6, -20.0, 126.3, 179, 3566234},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 48.8, -20.0, 133.4, -94, 3566235},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 55.7, -20.0, 135.1, -100, 3566235},
		{"rori", "black_sun_initiate_caveRoriBlackSunOutpostBunker", 300, 39.3, -20.0, 135.1, 82, 3566235},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 47.8, -20.0, 146.2, -179, 3566235},
		{"rori", "black_sun_smuggler_caveRoriBlackSunOutpostBunker", 300, 47.6, -20.0, 151.4, 177, 3566235},
		{"rori", "insane_miner_caveRoriBlackSunOutpostBunker", 600, 105.7, -20.0, 110.6, 85, 3566240},
		{"rori", "black_sun_minion_caveRoriBlackSunOutpostBunker", 300, 44.3, -20.0, 150.0, -94, 3566235},
		--medical area where the quest npc (Tover Blackmoor}, stands
		{"rori", "technician_caveRoriBlackSunOutpostBunker", 600, 44.6, -20.0, 157.6, -9, 3566235},
		--elevator shaft closet without any button to go down
		{"rori", "blood_thirsty_borgle_caveRoriBlackSunOutpostBunker", 600, -7.3, -12.0, 59.0, 79, 3566207},
	}
}

registerScreenPlay("RoriBlackSunOutpostBunkerScreenPlay", true)

function RoriBlackSunOutpostBunkerScreenPlay:start()
	if (isZoneEnabled("rori")) then
		self:spawnScreenPMobiles()
	end
end

