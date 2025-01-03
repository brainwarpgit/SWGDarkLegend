TatooineStaticSpawnsSouthScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "TatooineStaticSpawnsSouthScreenPlay",

	lootContainers = {	
		1106593 -- -5350 -4438
	},

	lootLevel = 26,

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 700000},
				{group = "junk", chance = 5500000},
				{group = "wearables_all", chance = 2000000},
				{group = "rifles", chance = 600000},
				{group = "pistols", chance = 600000},
				{group = "clothing_attachments", chance = 300000},
				{group = "armor_attachments", chance = 300000}
			},
			lootChance = 8000000
		}
	},

	lootContainerRespawn = 1800, -- 30 minutes

	ScreenPSpawns = {
		--Tusken King Quest (-5315,-4440},
		{"tatooine", "tusken_king_quest", 300, -5350.2, 40, -4442.5, 139, 0},	--entrance, spawns clock wise
		{"tatooine", "tusken_bantha", 300, -5342.5, 40, -4430.6, 151, 0},
		{"tatooine", "tusken_bantha", 300, -5323.2, 40, -4419.8, 157, 0},
		{"tatooine", "tusken_raider", 300, -5317.1, 40, -4423.1, 135, 0},
		{"tatooine", "tusken_sniper", 300, -5311.8, 40, -4424.3, -141, 0},
		{"tatooine", "tusken_war_master", 300, -5303.7, 40, -4424.9, -154, 0},
		{"tatooine", "tusken_guard", 300, -5297.9, 40, -4428.9, -134, 0},
		{"tatooine", "tusken_warlord", 300, -5295.4, 40, -4432.8, -81, 0},
		{"tatooine", "tusken_raid_hunter", 300, -5283.3, 40, -4435.6, 102, 0},
		{"tatooine", "tusken_bantha", 300, -5287.7, 40, -4438.9, 80, 0},
		{"tatooine", "tusken_raid_hunter", 300, -5284.1, 40, -4444.7, 70, 0},
		{"tatooine", "tusken_bantha", 300, -5303.4, 40, -4458.5, -35, 0},
		{"tatooine", "tusken_commoner", 300, -5319, 40, -4459.2, -7, 0},
		{"tatooine", "tusken_commoner", 300, -5313.2, 40, -4459.7, -12, 0},
		{"tatooine", "tusken_commoner", 300, -5317.3, 40, -4461.1, -2, 0},
		{"tatooine", "tusken_commoner", 300, -5327, 40, -4452.9, -75, 0},	--fire pit
		{"tatooine", "tusken_torture_lord", 300, -5335.5, 40, -4464.2, -8, 0},	--axe
		{"tatooine", "tusken_berserker", 300, -5350, 40, -4463.3, -25, 0},	--exit


		-- Big Game Hunt
		{"tatooine", "krayt_dragon_adolescent", 1800, -1151, 9, -318, -122, 0},
		{"tatooine", "krayt_dragon_adolescent", 1800, -1337, 9, -242, 112, 0},
		{"tatooine", "krayt_dragon_grand", 1800, -1263, 8, -327, -32, 0},
	}
}

registerScreenPlay("TatooineStaticSpawnsSouthScreenPlay", true)

function TatooineStaticSpawnsSouthScreenPlay:start()
	if (isZoneEnabled("tatooine")) then
		self:spawnScreenPMobiles()
		self:initializeLootContainers()
	end
end

