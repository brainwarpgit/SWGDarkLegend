LokKimogilaTownScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "LokKimogilaTownScreenPlay",
	ScreenPSpawns = {
		{"lok", "giant_dune_kimogila_poiLokKimogilaTown", 1800, -17.6, 11.9, 2725.2, 159, 0},
		{"lok", "kimogila_poiLokKimogilaTown", 1800, -137.4, 11.9, 2656.9, -97, 0},
		{"lok", "kimogila_poiLokKimogilaTown", 1800, -118.0, 11.9, 2653.5, -116, 0},
		{"lok", "cas_vankoo_poiLokKimogilaTown", 1800, -12.4, 12.0, 2695.0, -38, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -89.7, 12.0, 2720.2, -18, 0},	
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -87.6, 12.0, 2711.8, 157, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -78.3, 12.0, 2712.4, 70, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -83.2, 12.0, 2704.0, -136, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -73.4, 12.0, 2690.9, -138, 0},	
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -90.6, 12.0, 2688.6, -127, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -82.4, 12.0, 2682.7, 62, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -75.1, 12.0, 2690.9, -169, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -92.7, 12.0, 2678.6, -138, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -90.0, 12.0, 2685.8, -2, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -64.3, 12.0, 2727.8, 12, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -51.5, 12.0, 2713.2, 95, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -46.8, 12.0, 2723.0, 89, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -37.9, 12.0, 2716.7, 133, 0},
		{"lok", "kimo_commoner_poiLokKimogilaTown", 300, -38.7, 12.0, 2729.2, 14, 0},
	}
}

registerScreenPlay("LokKimogilaTownScreenPlay", true)

function LokKimogilaTownScreenPlay:start()
	if (isZoneEnabled("lok")) then
		self:spawnScreenPMobiles()
	end
end

