Yavin4ImperialBaseScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	planet = "yavin4",

	screenplayName = "Yavin4ImperialBaseScreenPlay",
	
	ScreenPSpawns = {
		{"yavin4", "junk_dealer", 0, 4028, 37, -6246, 0, 0},
		{"yavin4", "at_st_poiYavin4ImperialBase", 720, 4028.7, 37.0, -6349.5, 175, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4025.1, 18.6, -6509.2, 180, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4021.6, 18.8, -6509.2, 180, 0},
		{"yavin4", "stormtrooper_bombardier_poiYavin4ImperialBase", 300, 4013.6, 38.1, -6324.8, 90, 0},
		{"yavin4", "stormtrooper_sniper_poiYavin4ImperialBase", 300, 4000.6, 36.9, -6289.3, 90, 0},
		{"yavin4", "imperial_colonel_poiYavin4ImperialBase", 300, 4051.7, 36.9, -6255.1, 90, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4051.7, 36.9, -6258.6, 0, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4008.7, 36.9, -6215.6, 180, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4004.8, 36.9, -6251.1, 0, 0},
		{"yavin4", "stormtrooper_poiYavin4ImperialBase", 300, 4052.7, 36.9, -6214.8, -180, 0},
		{"yavin4", "commoner_technician_poiYavin4ImperialBase", 300, 4001.0, 36.9, -6229.8, -75, 0},
		{"yavin4", "commoner_poiYavin4ImperialBase", 300, 3993.0, 36.9, -6269.1, 45, 0},
		{"yavin4", "commoner_old_poiYavin4ImperialBase", 300, 3996.7, 36.9, -6270.0, 0, 0},
		{"yavin4", "commoner_poiYavin4ImperialBase", 300, 3997.0, 36.9, -6267.2, -135, 0},
		{"yavin4", "pilot_poiYavin4ImperialBase", 300, 4050.0, 36.9, -6226.2, -35, 0},
		{"yavin4", "pilot_poiYavin4ImperialBase", 300, 4038.4, 36.9, -6244.6, -163, 0},
		{"yavin4", "stormtrooper_medic_poiYavin4ImperialBase", 300, 4.0, 0, 2.2, 90, 8735498},
		{"yavin4", "haymir_rendundi_poiYavin4ImperialBase", 300, 0, 0, -5.6, 0, 8735497},
		{"yavin4", "imperial_medic_poiYavin4ImperialBase", 300, 4.9, 0, 1.5, 90, 8735519},
		{"yavin4", "imperial_trooper_poiYavin4ImperialBase", 300, 0, 0, -5.6, 0, 8735518},
		{"yavin4", "alozen_poiYavin4ImperialBase", 300, 0.003, 0.125, -5.558, 0, 8735518, ""},
		{"yavin4", "barlow_poiYavin4ImperialBase", 60, 4028.91, 37, -6201.62, 150, 0, "npc_imperial"}
	}

}

registerScreenPlay("Yavin4ImperialBaseScreenPlay", true)

function Yavin4ImperialBaseScreenPlay:start()
	if (isZoneEnabled(self.planet)) then
		self:spawnScreenPMobiles()
	end
end

