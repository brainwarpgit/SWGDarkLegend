--This is to be used for static spawns that are NOT part of caves, cities, dungeons, poi's, or other large screenplays.
DantooineStaticSpawnsScreenPlay = ScreenPlay:new
{
	numberOfActs = 1,

	screenplayName = "DantooineStaticSpawnsScreenPlay",
	ScreenPSpawns = {
		--ancient abandoned Force Shrine (900, 1400},
		{"dantooine", "force_crystal_hunter", 7200,902.4,19.8,1395.4,-114,0,0,"angry"},
		{"dantooine", "force_crystal_hunter", 7200,892.3,21.2,1390.4,-176,0,0,"angry"},

		--old tower with green fire
		{"dantooine", "force_sensitive_renegade", 7200,-924.1,7.5,6917.9,72,0,0,"angry"},
		{"dantooine", "force_sensitive_renegade", 7200,-914.8,7.8,6904.4,155,0,0,"angry"},

		-- Vexed Voritor Lizard Spawn (-5500 -1800},
		{"dantooine", "vexed_voritor_lizard", 300, -5500, 15, -1780, getRandomNumber(360), 0},
		{"dantooine", "vexed_voritor_lizard", 300, -5502, 15, -1790, getRandomNumber(360), 0},
		{"dantooine", "vexed_voritor_lizard", 300, -5483, 15, -1777, getRandomNumber(360), 0},


		{"dantooine", "dark_jedi_master", 3600, -738.2, 1.7, 2103.9, 55, 0},

		--Need to add the rest of static spawns (Incomplete},.
	}
}

registerScreenPlay("DantooineStaticSpawnsScreenPlay", true)

function DantooineStaticSpawnsScreenPlay:start()
	if (isZoneEnabled("dantooine")) then
		self:spawnScreenPMobiles()
	end
end


