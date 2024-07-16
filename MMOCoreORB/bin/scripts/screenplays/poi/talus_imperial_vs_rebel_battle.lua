TalusImperialVsRebelBattleScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TalusImperialVsRebelBattleScreenPlay",
	ScreenPSpawns = {
		{"talus", "imperial_pilot_poiTalusImperialVsRebelBattle", 870, -2455.5, 41.1, 3867.2, 155, 0, 0, "worried"},
		{"talus", "imperial_army_captain_poiTalusImperialVsRebelBattle", 870, -2417.4, 38.0, 3678.8, 130, 0, 0, "angry"},
		{"talus", "imperial_probe_drone_poiTalusImperialVsRebelBattle", 870, -2423, 38.0, 3677.7, 125, 0},
		{"talus", "imperial_pilot_poiTalusImperialVsRebelBattle", 870, -2571.5, 28.9, 3824.2, -55, 0, 0, "angry"},
		{"talus", "comm_operator_poiTalusImperialVsRebelBattle", 870, -2415.6, 38.0, 3650.4, -63, 0, 0, "sad"},
		{"talus", "rebel_trooper_poiTalusImperialVsRebelBattle", 870, -2539.5, 38.0, 3710.5, -27, 0, 0, "happy"},
		{"talus", "rebel_scout_poiTalusImperialVsRebelBattle", 870, -2543.6, 38.1, 3729.2, -19, 0, 0, "nervous"},
		{"talus", "rebel_major_general_poiTalusImperialVsRebelBattle", 870, -2538.3, 38.0, 3708.5, 100, 0, 0, "calm"},
	}
}

registerScreenPlay("TalusImperialVsRebelBattleScreenPlay", true)

function TalusImperialVsRebelBattleScreenPlay:start()
	if (isZoneEnabled("talus")) then
		self:spawnScreenPMobiles()
	end
end

