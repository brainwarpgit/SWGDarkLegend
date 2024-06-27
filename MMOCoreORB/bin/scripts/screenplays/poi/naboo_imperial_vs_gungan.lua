local ObjectManager = require("managers.object.object_manager")

ImperialVsGunganScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "ImperialVsGunganScreenPlay",
	ScreenPSpawns = {
		{"naboo", "imperial_exterminator_poiNabooImperialVsGungan", 420, 4761.4, 10.7, -3823.9, -175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4742.5, 10.2, -3836.4, -165, 0},
		{"naboo", "plasma_thieving_swamp_trooper_captain_poiNabooImperialVsGungan", 300, 4791.3, 11.4, -3821.6, -167, 0},
		{"naboo", "imperial_exterminator_poiNabooImperialVsGungan", 300, 4759.2, 10.7, -3830.4, 72, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4757.2, 10.7, -3826.7, 72, 0},
		{"naboo", "plasma_thieving_swamp_trooper_captain_poiNabooImperialVsGungan", 300, 4784.7, 11.3, -3820.7, 95, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4768.4, 10.9, -3825.0, 35, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4781.3, 12.0, -3847.1, 161, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4740.9, 10.7, -3851.5, -90, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4784.3, 12.0, -3845.9, 160, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4778.3, 12.0, -3849.5, 170, 0},
		{"naboo", "plasma_thieving_swamp_trooper_captain_poiNabooImperialVsGungan", 300, 4768.7, 11.8, -3854.9, 175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4761.2, 11.8, -3856.0, 175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4754.7, 11.7, -3858.0, 175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4747.7, 11.6, -3859.1, 175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4726.2, 9.6, -3825.6, 175, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4712.3, 11.2, -3871.0, 15, 0},
		{"naboo", "plasma_thieving_swamp_trooper_poiNabooImperialVsGungan", 300, 4808.3, 11.7, -3836.6, 166, 0},
		{"naboo", "rebel_gungan_priest_poiNabooImperialVsGungan", 420, 4760.9, 13.7, -3894.2, 11, 0},
		{"naboo", "rebel_gungan_boss_poiNabooImperialVsGungan", 300, 4763.8, 28.2, -3929.1, 0, 0},
		{"naboo", "rebel_gungan_captain_poiNabooImperialVsGungan", 300, 4764.3, 28.2, -3922.5, -90, 0},
		{"naboo", "rebel_gungan_general_poiNabooImperialVsGungan", 300, 4755.2, 28.2, -3925.0, 0, 0},
		{"naboo", "rebel_gungan_captain_poiNabooImperialVsGungan", 300, 4757.7, 28.2, -3929.1, 0, 0},
		{"naboo", "rebel_gungan_war_chief_poiNabooImperialVsGungan", 300, 4755.2, 28.2, -3922.5, 180, 0},
		{"naboo", "rebel_gungan_guard_poiNabooImperialVsGungan", 300, 4767.2, 13.9, -3898.5, -90, 0},
		{"naboo", "rebel_gungan_guard_poiNabooImperialVsGungan", 300, 4751.1, 13.9, -3898.5, 90, 0},
		{"naboo", "rebel_gungan_war_chief_poiNabooImperialVsGungan", 300, 4750.8, 13.9, -3906.6, 0, 0},
		{"naboo", "rebel_gungan_war_chief_poiNabooImperialVsGungan", 300, 4767.1, 14.0, -3903.5, 0, 0},
		{"naboo", "rebel_gungan_kaadu_rider_poiNabooImperialVsGungan", 300, 4786.8, 14.7, -3924.9, 0, 0},
		{"naboo", "rebel_gungan_kaadu_rider_poiNabooImperialVsGungan", 300, 4789.3, 14.4, -3937.6, 0, 0},
		{"naboo", "gungan_kaadu_poiNabooImperialVsGungan", 300, 4784.3, 14.7, -3924.9, 0, 0},
		{"naboo", "gungan_kaadu_poiNabooImperialVsGungan", 300, 4786.8, 14.4, -3937.6, 0, 0},
		{"naboo", "gungan_falumpaset_poiNabooImperialVsGungan", 300, 4752.1, 13.1, -3948.2, -60, 0},
		{"naboo", "gungan_falumpaset_poiNabooImperialVsGungan", 300, 4736.4, 13.1, -3938.9, -15, 0},
		{"naboo", "rebel_gungan_bomber_poiNabooImperialVsGungan", 300, 4729.9, 13.2, -3914.7, 0, 0},
		{"naboo", "gungan_falumpaset_poiNabooImperialVsGungan", 300, 4727.5, 13.2, -3917.2, 0, 0},
		{"naboo", "rebel_gungan_priest_poiNabooImperialVsGungan", 300, 4730.8, 12.8, -3897.9, 20, 0},
		{"naboo", "rebel_gungan_priest_poiNabooImperialVsGungan", 300, 4751.0, 12.8, -3887.1, 2, 0},
		{"naboo", "rebel_gungan_grand_army_soldier_poiNabooImperialVsGungan", 300, 4766.8, 13.6, -3886.4, 0, 0},
		{"naboo", "rebel_gungan_grand_army_soldier_poiNabooImperialVsGungan", 300, 4753.0, 12.5, -3874.9, 10, 0},
		{"naboo", "rebel_gungan_grand_army_soldier_poiNabooImperialVsGungan", 300, 4780.4, 13.5, -3876.3, 0, 0},
		{"naboo", "rebel_gungan_grand_army_soldier_poiNabooImperialVsGungan", 300, 4791.8, 13.6, -3876.4, 0, 0},
		{"naboo", "rebel_gungan_scout_poiNabooImperialVsGungan", 300, 4727.9, 10.4, -3852.1, 44, 0},
		{"naboo", "rebel_gungan_scout_poiNabooImperialVsGungan", 300, 4811.4, 13.2, -3867.5, -34, 0},
		{"naboo", "rebel_gungan_scout_poiNabooImperialVsGungan", 300, 4802.3, 14.5, -3893.8, -24, 0},
		{"naboo", "rebel_gungan_bomber_poiNabooImperialVsGungan", 300, 4743.6, 12.2, -3876.0, 10, 0},
		{"naboo", "rebel_gungan_bomber_poiNabooImperialVsGungan", 300, 4761.9, 12.7, -3873.5, 15, 0},
		{"naboo", "rebel_gungan_guard_poiNabooImperialVsGungan", 300, 4772.4, 13.1, -3875.1, 13, 0},
	}
}

registerScreenPlay("ImperialVsGunganScreenPlay", true)

function ImperialVsGunganScreenPlay:start()
	if (isZoneEnabled("naboo")) then
		self:spawnScreenPMobiles()
	end
end
