RoriPoacherVsCreatureBattleScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "RoriPoacherVsCreatureBattleScreenPlay",
	planet = "rori",
	
	ScreenPSpawns = {
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 770.1, 82.3, -2084.4, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 770.1, 82.3, -2084.4, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 770.1, 82.3, -2084.4, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 748.8, 85.5 -2090.7, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 748.8, 85.5 -2090.7, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 752.1, 85.7, -2082.7, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 752.1, 85.7, -2082.7, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 765.9, 82.7, -2086.3, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 765.9, 82.7, -2086.3, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 765.9, 82.7, -2086.3, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 781.5, 82.6, -2073.7, 0, 0},
		{"rori", "poacher_poiRoriPoacherVsCreatureBattle", 300, 781.5, 82.6, -2073.7, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 772.2, 84.1, -2068.5, 0, 0},
		{"rori", "hunter_poiRoriPoacherVsCreatureBattle", 300, 772.2, 84.1, -2068.5, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 735.8, 89.2, -2074.9, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 735.8, 89.2, -2074.9, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 735.8, 89.2, -2074.9, 0, 0},
		{"rori", "vicious_squall_poiRoriPoacherVsCreatureBattle", 300, 785.7, 81.1, -2059.9, 0, 0},
		{"rori", "vicious_squall_poiRoriPoacherVsCreatureBattle", 300, 785.7, 81.1, -2059.9, 0, 0},
		{"rori", "vicious_squall_poiRoriPoacherVsCreatureBattle", 300, 785.7, 81.1, -2059.9, 0, 0},
		{"rori", "female_squall_poiRoriPoacherVsCreatureBattle", 300, 781.8, 81.4, -2048.4, 0, 0},
		{"rori", "female_squall_poiRoriPoacherVsCreatureBattle", 300, 781.8, 81.4, -2048.4, 0, 0},
		{"rori", "male_squall_poiRoriPoacherVsCreatureBattle", 300, 790.6, 78.9, -2036.8, 0, 0},
		{"rori", "male_squall_poiRoriPoacherVsCreatureBattle", 300, 790.6, 78.9, -2036.8, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 714.6, 93.6, -2063.5, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 714.6, 93.6, -2063.5, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 722.2, 91.2, -2076.5, 0, 0},
		{"rori", "vrobal_poiRoriPoacherVsCreatureBattle", 300, 722.2, 91.2, -2076.5, 0, 0},
	}
}

registerScreenPlay("RoriPoacherVsCreatureBattleScreenPlay", true)

function RoriPoacherVsCreatureBattleScreenPlay:start()
	if (isZoneEnabled(self.planet)) then
		self:spawnScreenPMobiles()
	end
end

