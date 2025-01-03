--This is to be used for static spawns that are NOT part of caves, cities, dungeons, poi's, or other large screenplays.
DathomirStaticSpawnsSwScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "DathomirStaticSpawnsSwScreenPlay",

	lootContainers = {

	},

	lootLevel = 39,

	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 700000},
				{group = "junk", chance = 7500000},
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
		--destroyed imperial camp (-6467,-6722},
		{"dathomir", "specforce_marine", 300, -6455.5, 555.1, -6743.6, -33, 0, 0 , "neutral"},
		{"dathomir", "specforce_marine", 300, -6471.7, 553.5, -6741.9, 0, 0},
		{"dathomir", "specforce_marine", 300, -6476.2, 546.3, -6733.3, 33, 0},

		--lookout station (-4573,-6556},
		{"dathomir", "singing_mountain_clan_sentry", 360, -4573.5, 34.7, -6556.4, 138, 0},
		{"dathomir", "singing_mountain_clan_sentry", 360, -4595.5, 42.4, -6468.2, -108, 0},
		{"dathomir", "singing_mountain_clan_sentry", 360, -4661.4, 40.8, -6525.7, 99, 0},
		{"dathomir", "singing_mountain_clan_sentry", 360, -4621.5, 43.4, -6609.5, 144, 0},
		{"dathomir", "singing_mountain_clan_sentry", 360, -4513.5, 40.0, -6630.4, 122, 0},
		{"dathomir", "singing_mountain_clan_huntress", 360, -4570.5, 38.3, -6537.1, -118, 0},
		{"dathomir", "singing_mountain_clan_guardian", 1220, -4567.9, 37.1, -6549.1, -148, 0},

		--nightsister outcasts home (-3250,-6585},
		{"dathomir", "nightsister_outcast", 360, -3252.0, 99.4, -6585.6, 165, 0},
		{"dathomir", "nightsister_outcast", 360, -3252.0, 98.9, -6590.5, -15, 0},
		{"dathomir", "nightsister_outcast", 360, -3230.3, 101.4, -6588.9, 1, 0},

		--tie bomber debris (-986,-6391},
		{"dathomir", "imperial_probe_drone", 720, -988.8, 147.2, -6396.2, 4, 0},

		--floating rocks (-828,-5042},
		{"dathomir", "nightsister_rancor_tamer", 360, -821.0, 94.6, -5032.9, 15, 0},
		{"dathomir", "nightsister_rancor_tamer", 360, -830.3, 95.0, -5032.0, -25, 0},
		{"dathomir", "nightsister_rancor", 360, -835.5, 95.1, -5022.1, -165, 0},
		{"dathomir", "nightsister_enraged_rancor", 360, -825.0, 94.7, -5020.9, -170, 0},
		{"dathomir", "nightsister_rancor", 360, -815.7, 94.3, -5024.5, -160, 0},

		--torch (-2610 -4861},
		{"dathomir", "nightsister_spell_weaver", 600, -2610.4, 104.8, -4861.5, -90, 0},
		{"dathomir", "nightsister_spell_weaver", 600, -2614.7, 104.8, -4860.6, 90, 0},

		--destroyed rebel base + rancors (-4705,-4772},
		{"dathomir", "rancor_youth", 360, -4684.4, 90.1, -4809.9, -25, 0},
		{"dathomir", "rancor_youth", 360, -4667.4, 88.1, -4789.4, -55, 0},
		{"dathomir", "rancor_youth", 360, -4672.3, 88.5, -4782.3, -55, 0},
		{"dathomir", "rancor_youth", 360, -4675.3, 88.3, -4753.3, -90, 0},
		{"dathomir", "rancor_youth", 360, -4692.8, 89.0, -4712.8, -95, 0},
		{"dathomir", "rancor", 360, -4707.8, 90.2, -4738.5, 165, 0},
		{"dathomir", "rancor", 360, -4715.8, 90.6, -4742.4, 155, 0},
		{"dathomir", "rancor", 360, -4734.8, 91.2, -4752.4, -165, 0},
		{"dathomir", "bull_rancor", 360, -4728.4, 90.4, -4770.2, 105, 0},
		{"dathomir", "rancor", 360, -4725.0, 85.7, -4804.2, 54, 0},
		{"dathomir", "ancient_bull_rancor", 1800, -4710.4, 89.7, -4777.0, 45, 0},
		{"dathomir", "rancor", 360, -4762.8, 91.4, -4759.9, -15, 0},
		{"dathomir", "mutant_rancor", 360, -4766.7, 92.3, -4738.5, 55, 0},

		--empty hut (-6894,-4854},
		{"dathomir", "singing_mountain_clan_councilwoman", 7200, -6894.9, 461.8, -4853.8, 109, 0},

		--worship stone (-6953,-3032},
		{"dathomir", "nightsister_elder", 4220, -6953.8, 551.6, -3032.1, -45, 0},
		{"dathomir", "nightsister_protector", 720, -6946.5, 550.5, -3041.9, 135, 0},
		{"dathomir", "rancor_pygmy", 1200, -6995.6, 570.0, -3058.8, 93, 0},

		--tree hut (-5045,-2773},
		{"dathomir", "escaped_nightsister_slave", 360, -5038.1, 8.9, -2773.2, -35, 0},
		{"dathomir", "escaped_nightsister_slave", 360, -5041.1, 8.8, -2768.7, -135, 0},
		{"dathomir", "escaped_nightsister_slave", 360, -5045.6, 8.4, -2773.6, 55, 0},

		--singing mountain clan rock & hut (-2419,-3111},
		{"dathomir", "singing_mountain_clan_huntress", 360, -2419.4, 48.5, -3111.5, -8, 0},
		{"dathomir", "singing_mountain_clan_scout", 360, -2431.9, 55.7, -3091.8, -40, 0},

		--rock spire with skulls (-493,-2890},
		{"dathomir", "spiderclan_auspex", 3600, -493.1, 133.2, -2889.6, -117, 0, 0 , "explain"},

		--tower & stones (-443,-1156},
		{"dathomir", "nightsister_protector", 720, -444.9, 124.0, -1159.7, -118, 0},

		--nightsister stalkers home (-2933,-1025},
		{"dathomir", "nightsister_stalker", 360, -2931.6, 141.0, -1031.4, 58, 0},

		--nightsister guard camp (-4179,-854},
		{"dathomir", "nightsister_sentry", 360, -4198.1, 24.1, -858.1, -90, 0},
		{"dathomir", "nightsister_sentry", 360, -4192.7, 23.2, -846.4, -90, 0},
		{"dathomir", "nightsister_sentry", 360, -4171.9, 48.3, -877.5, -145, 0},
		{"dathomir", "nightsister_protector", 1220, -4185.4, 24.9, -863.4, -55, 0},
		{"dathomir", "nightsister_sentinel", 360, -4179.8, 24.9, -849.5, -145, 0},
		{"dathomir", "nightsister_ranger", 360, -4165.2, 24.4, -844.2, 45, 0},

		--floating rocks (-6628,-772},
		{"dathomir", "singing_mountain_clan_councilwoman", 4220, -6628.9, 327.5, -772.8, -22, 0},
		{"dathomir", "singing_mountain_clan_guardian", 1220, -6635.4, 323.5, -755.7, 22, 0},
		{"dathomir", "singing_mountain_clan_huntress", 360, -6624.7, 314.5, -740.3, 72, 0},
		{"dathomir", "singing_mountain_clan_huntress", 360, -6593.1, 281.5, -740.3, 90, 0},
		{"dathomir", "singing_mountain_clan_initiate", 360, -6573.8, 268.0, -741.4, 98, 0},
		{"dathomir", "singing_mountain_clan_sentry", 360, -6547.6, 261.7, -742.8, 115, 0},
	}
}

registerScreenPlay("DathomirStaticSpawnsSwScreenPlay", true)

function DathomirStaticSpawnsSwScreenPlay:start()
	if (isZoneEnabled("dathomir")) then
		self:spawnScreenPMobiles()
		self:initializeLootContainers()
	end
end

