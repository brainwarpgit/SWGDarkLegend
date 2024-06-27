TatooineImperialOasisBaseScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TatooineImperialOasisBaseScreenPlay",
	ScreenPSpawns = {
		{"tatooine", "artisan_poiTatooineImperialOasisBase",60,-1.1,1.0,10.0,142,6016532, AI_STATIONARY, "npc_sitting_chair"},
		{"tatooine", "agriculturalist_poiTatooineImperialOasisBase",60,1.4,1.0,9.7,-134,6016532, AI_STATIONARY, "npc_sitting_chair"},
		{"tatooine", "commoner_tatooine_poiTatooineImperialOasisBase",60,7.7,-3.4,9.5,-42,6016536, AI_STATIONARY, "npc_sitting_table_eating"},
		{"tatooine", "commoner_fat_poiTatooineImperialOasisBase",60,10.0,-4.0,-1.6,-88,6016537, AI_STATIONARY, "npc_sitting_chair"},
		{"tatooine", "entertainer_poiTatooineImperialOasisBase",60,8.9,-4.0,-1.5,90,6016537, 0, "happy"},
		{"tatooine", "scientist_poiTatooineImperialOasisBase",60,-7.6,-10.0,-9.6,175,6016539, AI_STATIONARY, "npc_use_terminal_high"},
		{"tatooine", "r5_poiTatooineImperialOasisBase",60,-8.7,-10.0,-9.6,106,6016539, 0, "happy"},
		{"tatooine", "imperial_stealth_operative_poiTatooineImperialOasisBase",60,-1.9,-9.5,-3.8,65,6016541, AI_STATIONARY, "npc_sitting_chair"},
		{"tatooine", "shadowy_figure_poiTatooineImperialOasisBase",60,-0.3,-9.5,-2.4,-157,6016541, AI_STATIONARY, "npc_sitting_chair"},
		{"tatooine", "seeker_poiTatooineImperialOasisBase",60,-1.0,-9.5,1.8,-120,6016538, 0, "neutral"},
		{"tatooine", "scientist_poiTatooineImperialOasisBase",60,-7.3,-10.0,-10.3,177,6016507, AI_STATIONARY, "npc_use_terminal_low"},
		{"tatooine", "chiss_male_poiTatooineImperialOasisBase",60,8.0,-3.4,7.4,169,6016504, 0, "happy"},
		{"tatooine", "chiss_female_poiTatooineImperialOasisBase",60,8.1,-3.4,6.2,0,6016504, 0, "nervous"},
		{"tatooine", "noble_poiTatooineImperialOasisBase",60,10.4,0.4,5.6,-141,6016499, 0, "neutral"},
		{"tatooine", "info_broker_poiTatooineImperialOasisBase",60,10.4,0.4,4.4,0,6016499, 0, "conversation"},
		{"tatooine", "rebel_obscureops_agent_poiTatooineImperialOasisBase",60,5.3,0.1,-4.2,88,1289937, AI_STATIONARY, "npc_use_terminal_low"},
		{"tatooine", "imperial_stealth_operative_poiTatooineImperialOasisBase",60,4.3,0.1,-3.2,130,1289937, 0, "threaten"},
		{"tatooine", "contractor_poiTatooineImperialOasisBase",60,-2.3,0.1,-3.1,8,1289938, AI_STATIONARY, "npc_use_terminal_low"},
		{"tatooine", "medic_poiTatooineImperialOasisBase",60,-5.0,0.1,1.7,-145,1289934, AI_STATIONARY, "npc_use_terminal_low"},
		--Outside
		{"tatooine", "bounty_hunter_poiTatooineImperialOasisBase",60,-5284.9,7.1,2714.4,-97,0, 0, "neutral"},
		{"tatooine", "seeker_poiTatooineImperialOasisBase",60,-5285.6,7.2,2713.7,-100,0, 0, "neutral"},
		{"tatooine", "farmer_rancher_poiTatooineImperialOasisBase",60,-5250,0,2733.3,-13,0, AI_STATIONARY, "fishing"},
		{"tatooine", "bounty_hunter_poiTatooineImperialOasisBase",60,-5284.9,9.1,2675.2,48,0, 0, "angry"},
		{"tatooine", "trainer_commando",0,-5292,6.76132,2718,183,0},
		{"tatooine", "informant_npc_lvl_2",0,-5284,9.1,2676,240,0},
		{"tatooine", "informant_npc_lvl_1",0,-5296,8.5,2654,0,0},
		{"tatooine", "imperial_recruiter",0,-5340,4.7,2736,149,0},
		{"tatooine", "dark_trooper_poiTatooineImperialOasisBase",360,-5360,8.0,2748.6,130,0},
		{"tatooine", "dark_trooper_poiTatooineImperialOasisBase",360,-5357.5,8.0,2751.4,130,0},
		{"tatooine", "elite_sand_trooper_poiTatooineImperialOasisBase",360,-5343.4,4.7,2733,120,0},
		{"tatooine", "imperial_probe_drone_poiTatooineImperialOasisBase",360,-5322.4,7.1,2711.5,179,0},
		{"tatooine", "sand_trooper_poiTatooineImperialOasisBase",360,-5289.8,7.5,2707,30,0},
		{"tatooine", "sand_trooper_poiTatooineImperialOasisBase",360,-5292.8,7.2,2709.2,40,0},
		{"tatooine", "storm_commando_poiTatooineImperialOasisBase",600,-5310.7,8.5,2660.7,3,0},
		{"tatooine", "storm_commando_poiTatooineImperialOasisBase",600,-5304.0,8.5,2660.6,-7,0},
		{"tatooine", "sand_trooper_poiTatooineImperialOasisBase",360,-5361.6,8.5,2661.8,-93,0},
		{"tatooine", "sand_trooper_poiTatooineImperialOasisBase",360,-5362.5,7.6,2673.5,-120,0},
		{"tatooine", "stormtrooper_sniper_poiTatooineImperialOasisBase",360,-5339.1,7.5,2673.3,-97,0},
	}
}

registerScreenPlay("TatooineImperialOasisBaseScreenPlay", true)

function TatooineImperialOasisBaseScreenPlay:start()
	if (isZoneEnabled("tatooine")) then
		self:spawnScreenPMobiles()
	end
end

