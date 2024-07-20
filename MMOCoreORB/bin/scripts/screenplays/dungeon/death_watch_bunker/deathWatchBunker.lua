local ObjectManager = require("managers.object.object_manager")

DeathWatchBunkerScreenPlay = ScreenPlay:new {
	passkey = {
		hall = "object/tangible/dungeon/death_watch_bunker/passkey_hall.iff",
		storage = "object/tangible/dungeon/death_watch_bunker/passkey_storage.iff",
		mine = "object/tangible/dungeon/death_watch_bunker/passkey_mine.iff"
	},

	buildingIds = {
		outside = 5996315,
		entrance = 5996316,
		areaA = 5996326,
		areaB = 5996338,
		mines = 5996352,
		armorArea = 5996374,
		droidEngineerArea = 5996370,
		tailorArea = 5996368
	},

	bunkerItems = {
		alumMineral = "object/tangible/loot/dungeon/death_watch_bunker/mining_drill_reward.iff",
		mandoHelmet = "object/tangible/wearables/armor/mandalorian/armor_mandalorian_helmet.iff",
		mandoRebreather = "object/tangible/wearables/goggles/rebreather.iff",
		filter = "object/tangible/dungeon/death_watch_bunker/filter.iff",
		enhancedFilter = "object/tangible/dungeon/death_watch_bunker/enhanced_filter.iff",
		alumGel = "object/tangible/dungeon/death_watch_bunker/gel_packet.iff",
		medicine = "object/tangible/dungeon/death_watch_bunker/crazed_miner_medicine.iff",
		drillBattery = "object/tangible/dungeon/death_watch_bunker/drill_battery.iff",
		drillBatteryClean = "object/tangible/dungeon/death_watch_bunker/drill_battery_clean.iff",
		jetPackBase = "object/tangible/loot/dungeon/death_watch_bunker/jetpack_base.iff",
		jetPackStabilizer = "object/tangible/loot/dungeon/death_watch_bunker/jetpack_stabilizer.iff",
		ductedFan = "object/tangible/loot/dungeon/death_watch_bunker/ducted_fan.iff",
		injectorTank = "object/tangible/loot/dungeon/death_watch_bunker/fuel_injector_tank.iff",
		dispersionUnit = "object/tangible/loot/dungeon/death_watch_bunker/fuel_dispersion_unit.iff",
		binaryLiquid = "object/tangible/loot/dungeon/death_watch_bunker/binary_liquid.iff",
		protectiveLiquid = "object/tangible/loot/dungeon/death_watch_bunker/emulsion_protection.iff"
	},

	targetItems = {
		--Armorsmith Crafting Terminal
		{ "object/tangible/wearables/armor/mandalorian/armor_mandalorian_chest_plate.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_shoes.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_bicep_l.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_bicep_r.iff" },
		--Droid Engineer Crafting Terminal
		{ "object/tangible/wearables/armor/mandalorian/armor_mandalorian_helmet.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_bracer_l.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_bracer_r.iff" },
		--Tailor Crafting Terminal
		{ "object/tangible/wearables/armor/mandalorian/armor_mandalorian_leggings.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_gloves.iff",
			"object/tangible/wearables/armor/mandalorian/armor_mandalorian_belt.iff" },
		-- Jetpack Crafting Terminal
		{ "object/tangible/deed/vehicle_deed/jetpack_deed.iff" },
	},

	doorData = {
		{ cellAccess = 5996316, lockTime = 10, doorType = 1 }, -- Entrance
		{ cellAccess = 5996326, lockTime = 10, doorType = 2 }, -- Area A
		{ cellAccess = 5996338, lockTime = 10, doorType = 2 }, -- Area B
		{ cellAccess = 5996352, lockTime = 10, doorType = 2 }, -- Mines
		{ cellAccess = 5996374, lockTime = 6, doorType = 3 }, -- Armorsmith area
		{ cellAccess = 5996370, lockTime = 6, doorType = 3 }, -- DE area
		{ cellAccess = 5996368, lockTime = 6, doorType = 3 } -- Tailor area
	},

	states = {
		2,--entrance unlocked
		4,--terminal a unlocked
		8,--terminal b unlocked
		16,--terminal mines unlocked
		32,--armorsmith door unlocked
		64,--droidengineer door unlocked
		128--tailor door unlocked
	},

	doorMessages = {
		{ unlock = "@dungeon/death_watch:access_granted", lock = "@dungeon/death_watch:terminal_locked" },
		{ unlock = "@dungeon/death_watch:access_granted", lock = "@dungeon/death_watch:terminal_locked" },
		{ unlock = "@dungeon/death_watch:access_granted", lock = "@dungeon/death_watch:terminal_locked" },
		{ unlock = "@dungeon/death_watch:access_granted", lock = "@dungeon/death_watch:terminal_locked" },
		{ unlock = "@dungeon/death_watch:unlock_door", lock = "@dungeon/death_watch:room_in_use" },
		{ unlock = "@dungeon/death_watch:unlock_door", lock = "@dungeon/death_watch:room_in_use" },
		{ unlock = "@dungeon/death_watch:unlock_door", lock = "@dungeon/death_watch:room_in_use" }
	},

	requiredDoorItems = {
		{ },
		{ "object/tangible/dungeon/death_watch_bunker/passkey_hall.iff" },
		{ "object/tangible/dungeon/death_watch_bunker/passkey_storage.iff" },
		{ "object/tangible/dungeon/death_watch_bunker/passkey_mine.iff" },

		--ARMORSMITHDOOR
		{	"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_chest_plate.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_boots.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_bicep_l.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_bicep_r.iff"
		},

		--DROIDENGINEERDOOR
		{	"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_helmet.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_bracer_l.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_bracer_r.iff"
		},

		--TAILORDOOR
		{	"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_leggings.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_gloves.iff",
			"object/tangible/wearables/armor/bounty_hunter/armor_bounty_hunter_belt.iff" },

		-- Jetpack Crafting Terminal
		{ "object/tangible/deed/vehicle_deed/jetpack_deed.iff" },
	},

	partStrings = { "@dungeon/death_watch:armorsmith_items", "@dungeon/death_watch:droid_engineer_items", "@dungeon/death_watch:tailored_items" },

	terminalSkills = { "", "", "", "", "crafting_armorsmith_master", "crafting_droidengineer_master", "crafting_tailor_master", "crafting_artisan_master" },

	terminalSkillMessage = { "@dungeon/death_watch:master_armorsmith_required", "@dungeon/death_watch:master_droidengineer_required", "@dungeon/death_watch:master_tailor_required", "@dungeon/death_watch:master_artisan_required" },

	missingSkillMessage = { "", "", "", "", "@dungeon/death_watch:not_enough_armorsmith_skill", "@dungeon/death_watch:not_enough_droidengineer_skill", "@dungeon/death_watch:not_enough_tailor_skill" },

	mineCells = { 5996352, 5996353, 5996354, 5996355, 5996356, 5996357, 5996358, 5996359, 5996360, 5996361, 5996362, 5996363, 5996364,
		5996365, 5996366, 5996367, 5996369, 5996372, 5996373, 5996375, 5996376, 5996377 },

	deathWatchValveEffects = { {42.2316,-30.5,-72.5555}, {56.0941,-30.5,-61.251}, {73.7982,-30.5,-76.4291}, {55.5855,-30.5,-92.8} },
	ventDroidPatrolPoints = {
		{{-19.9,-52.0,-131.0,5996345},{6.0,-52.0,-130.8, 5996345},{5.4,-52.0,-120.4,5996379},{-6.2, -52, -120.8,5996379}},
		{{-21.8, -52, -117.4,5996379},{-21.8, -52, -114.3,5996379},{-5.7, -54.1, -112,5996379}},
	},

	spawnGroups = { "", "terminalAnextSpawn", "terminalBnextSpawn", "terminalCnextSpawn" },

	spawnEvents = { "", "spawnNextA", "spawnNextB", "spawnNextC" },

	containerRespawnTime = 20 * 60 * 1000, -- 20 minutes
	debrisRespawnTime = 10 * 60 * 1000, -- 10 minutes

	primaryArmorColors = { 48, 55, 60, 95, 111, 127, 135, 143 },
	secondaryArmorColors = { 42, 90, 236, 244, 252, 253, 254, 255 },
	screenplayName = "DeathWatchBunker",
	dungeonSpawns = {
		{"endor", "death_watch_overlord_dungeonDeathWatchBunker", 300, 118, -64, -94, -135, 5996349},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 110, -64, -92, 150, 5996349},
		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, 116, -64, -101, -156, 5996349},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 113, -64, -100.7, -36, 5996349},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 22.1, -64, -97, 110, 5996347},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 22.6, -64, -111.1, 128, 5996347},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 40.2, -64, -154.6, -71, 5996347},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 39.5, -64, -147.9, -116, 5996347},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 57, -64, -138.4, 50, 5996347},
		{"endor", "death_watch_black_sun_assassin_dungeonDeathWatchBunker", 300, 50.2, -64, -123.7, -73, 5996347},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 13.7, -54.8, -158.5, 169, 5996345},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 51.7, -52.0, -130.2, -42, 5996338},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, 30.2, -52.0, -116.9, 171, 5996338},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 30.1, -42, -103.1, -77, 5996338},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, 32.5, -42.0, -111.6, 65, 5996338},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, 36.3, -32.0, -107.3, -56, 5996338},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 40.2, -32, -112.6, 2, 5996338},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, 46.6, -32, -111.8, 74, 5996338},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 54.2, -32, -103.9, -82, 5996338},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 71.4, -32, -101.3, -86, 5996339},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 70.3, -32.0, -87.5, -116, 5996340},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 45.5, -32, -89.5, -100, 5996340},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 46.1, -32.0, -65.0, 53, 5996340},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 71.3, -32, -64.5, -126, 5996340},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 46.2, -32, -52.1, -107, 5996341},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 42.0, -32, -51.0, 114, 5996341},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, 92.9, -32.0, -96, -127, 5996342},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 95.5, -32, -88.9, 13, 5996342},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 88.2, -32, -85.2, -55, 5996342},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, 89.4, -32.0, -60.1, 71, 5996343},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, 89.6, -32, -64.7, 43, 5996343},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, 93.5, -32, -59, -119, 5996343},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 112, -32.0, -70.2, 178, 5996344},
		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, 109.9, -32, -83.3, 134, 5996344},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 113.5, -32, -83.9, -146, 5996344},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 6.4, -31.9, -89, -9, 5996337},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 5.9, -29.8, -66.6, -1, 5996336},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 36.5, -28, -56.7, -154, 5996336},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 36.0, -20, -92.2, -121, 5996336},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 24.6, -20, -91.5, -39, 5996336},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, 20.7, -20, -80.4, -65, 5996332},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, 24.2, -20, -32.3, -175, 5996333},
		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, 25.9, -20, -37.7, -158, 5996333},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 21.5, -20, -38.3, 95, 5996333},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -2.5, -20, -58.9, 178, 5996332},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -4.0, -20.0, -46.5, -7, 5996330},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -26.5, -20, -41.2, -90, 5996330},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -57.4, -20, -40.8, -89, 5996330},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -77.8, -20, -41.1, 103, 5996330},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -4.3, -24, -113.5, -15, 5996334},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -38.3, -32, -113, -92, 5996334},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -58.5, -32, -118.7, 10, 5996334},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -44.7, -32, -99.6, 41, 5996331},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -11.4, -32, -99.0, -23, 5996331},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -12.7, -32, -56.7, -166, 5996331},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, 4.3, -32, -32.1, -31, 5996335},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -1.4, -32.0, -34.5, 83, 5996335},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, -16.1, -12.0, 8.8, -37, 5996316},
		{"endor", "death_watch_black_sun_thug_dungeonDeathWatchBunker", 300, -15.1, -12.0, 13.5, -163, 5996316},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, -1.3, -12, 28.4, 22, 5996318},
		{"endor", "death_watch_black_sun_assassin_dungeonDeathWatchBunker", 300, 0.6, -12, 34.0, -80, 5996318},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, 6.3, -12.0, 31.0, -106, 5996318},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -57.1, -20, 27.8, -121, 5996319},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, -62.1, -20, 25.1, -63, 5996319},
		{"endor", "death_watch_black_sun_assassin_dungeonDeathWatchBunker", 300, -67.3, -20, 35.6, 131, 5996319},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -76.9, -20, 51.6, 82, 5996320},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -72.4, -20.0, 55.5, -69, 5996320},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -75, -20, 58.6, -165, 5996320},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -70.2, -20.0, 11.0, -123, 5996321},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -77.0, -20.0, 10.0, 127, 5996321},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -77.6, -20.0, -8.2, 61, 5996321},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -70.8, -20.0, -6.6, -20, 5996321},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, -79, -20, -24.8, -102, 5996322},
		{"endor", "death_watch_black_sun_thug_dungeonDeathWatchBunker", 300, -92.5, -20, -28.3, -37, 5996323},
		{"endor", "death_watch_black_sun_assassin_dungeonDeathWatchBunker", 300, -98.2, -20, -25.8, 114, 5996323},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, -112.6, -20, -53.3, -57, 5996323},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, -100.8, -22.0, -39.2, 41, 5996323},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -126, -20, -49.2, -164, 5996325},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -126, -20, -55.2, 55, 5996325},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -129.6, -20, -53.0, 37, 5996325},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, -125.9, -20, -28.1, 52, 5996324},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -127.9, -20, -22.5, 66, 5996324},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -124.8, -20, -21.8, 136, 5996324},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -59.5, -20, -52.4, -97, 5996326},
		{"endor", "death_watch_black_sun_thug_dungeonDeathWatchBunker", 300, -59.8, -20, -69.5, -155, 5996327},
		{"endor", "death_watch_black_sun_assassin_dungeonDeathWatchBunker", 300, -65.5, -20, -78.7, 58, 5996327},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, -56.9, -20, -74.4, 48, 5996327},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -72.2, -20, -98.8, -59, 5996326},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -73.9, -20, -90.8, -162, 5996326},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -91.8, -20, -81.7, 31, 5996326},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -85.8, -20, -81.9, 118, 5996326},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, -92.6, -20, -94.8, 54, 5996326},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -103, -20, -100.4, -154, 5996328},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -114.3, -20, -95.3, -77, 5996328},
		{"endor", "death_watch_black_sun_henchman_dungeonDeathWatchBunker", 300, -110.2, -20, -91.9, 56, 5996328},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, -108.3, -20.0, -101.7, 12, 5996328},

		{"endor", "death_watch_black_sun_thug_dungeonDeathWatchBunker", 300, -93.5, -20, -114.7, 21, 5996329},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -82.3, -20, -112.1, -50, 5996329},
		{"endor", "death_watch_black_sun_guard_dungeonDeathWatchBunker", 300, -38, -20, -46.3, 12, 5996330},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, -12.0, -22.0, -52.9, -92, 5996331},
		{"endor", "death_watch_scientist_dungeonDeathWatchBunker", 300, 20.9, -20, -55.8, 121, 5996332},
		{"endor", "death_watch_scientist_dungeonDeathWatchBunker", 300, 5, -22, -74.2, 65, 5996332},
		{"endor", "death_watch_scientist_dungeonDeathWatchBunker", 300, -1.3, -32, -79.8, 90, 5996337},
		{"endor", "death_watch_scientist_dungeonDeathWatchBunker", 300, 15.8, -32, -94.5, -109, 5996337},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -7.8, -52, -143.3, 159, 5996345},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -21.2, -52, -156.9, 19, 5996378},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -26.3, -52, -149.1, 129, 5996378},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -28.9, -52, -161.1, 111, 5996378},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, -16.7, -52, -168.4, -5, 5996378},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -9.6, -52, -153.4, -25, 5996378},

		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -11.5, -60.3, -293.4, -6, 5996354},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -8.2, -60, -229.9, -42, 5996354},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -43.8, -59.8, -296.8, 86, 5996356},
		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, -90.4, -59.8, -376.2, -31, 5996357},
		{"endor", "death_watch_bloodguard_dungeonDeathWatchBunker", 300, -97.2, -59.8, -374.0, 10, 5996357},
		{"endor", "death_watch_overlord_mines_dungeonDeathWatchBunker", 300, -127.1, -59.7, -379.2, 22, 5996357},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -122.3, -60.1, -376.4, 40, 5996357},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -128.3, -60.0, -370.1, 133, 5996357},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -121.8, -59.8, -362.7, -162, 5996357},

		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -223.6, -60.1, -217.0, -160, 5996373},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -185.1, -59.8, -217.1, -93, 5996375},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -178.1, -59.8, -217.0, 86, 5996375},

		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -181.0, -60.3, -231.9, 108, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -172.7, -60.0, -237.9, -16, 5996376},
		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -159.7, -59.7, -229.1, -141, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -159.9, -59.9, -243.6, -82, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -170.9, -60.0, -246.8, -19, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -183.0, -60.5, -237.7, 50, 5996376},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -185.6, -60.0, -244.1, 110, 5996376},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -183.4, -60.2, -257.1, -72, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -167.1, -60.5, -256.3, -70, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -168.5, -59.8, -264.2, -152, 5996376},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -177.8, -60.2, -259.9, 19, 5996376},

		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, -174.0, -59.8, -276.2, 0, 5996377},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -173.9, -59.8, -296.8, 178, 5996377},
		{"endor", "death_watch_ghost_dungeonDeathWatchBunker", 300, -174.2, -59.8, -316.7, 87, 5996377},

		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -156.6, -60.2, -312.6, -110, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -147.3, -60.2, -319.7, -74, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -129.5, -60.1, -318.3, 19, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -130.7, -60.0, -339.8, -22, 5996357},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -124.9, -59.8, -305.2, -156, 5996357},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -125.7, -60.0, -350.2, 1, 5996357},

		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -109.3, -59.5, -375.7, 103, 5996357},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -98.6, -59.7, -360.2, 17, 5996357},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -99.1, -59.9, -339.2, 30, 5996357},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -87.5, -59.4, -331.1, -10, 5996357},

		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -94.2, -59.8, -216.5, 175, 5996359},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -80, -59.8, -203.5, 179, 5996358},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -60.2, -60.1, -178.6, -112, 5996352},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -42.2, -60.0, -172.8, 10, 5996352},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -22.5, -60.0, -183.7, -165, 5996352},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -41.7, -59.8, -204.9, 0, 5996353},

		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -155.3, -60.0, -106.8, 88, 5996365},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -222.2, -60.0, -129.0, -4, 5996367},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -288.3, -60.0, -124.8, 88, 5996371},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -281.9, -60.0, -120.7, 177, 5996371},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -281.9, -60.0, -129.6, -3, 5996371},

		{"endor", "death_watch_wraith_dungeonDeathWatchBunker", 300, -2, -60.0, -172.6, 176, 5996352},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -12.5, -59.9, -203.6, 127, 5996354},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -10.8, -60.1, -207.2, -24, 5996354},

		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -6.6, -60.1, -222.5, -35, 5996354},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -13.1, -60.0, -216.9, 3, 5996354},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -16.9, -60.4, -247.1, 9, 5996354},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -8.1, -59.7, -279.9, -33, 5996354},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -13.7, -60.4, -252.0, -162, 5996354},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, 27.4, -61.8, -303.6, 19, 5996355},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, 27.4, -61.2, -305.8, -123, 5996355},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, 21.2, -60.2, -304.7, 63, 5996355},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -45.8, -59.8, -317.0, -4, 5996356},--should be a technician with ENEMEY bitmask
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -71.1, -60.1, -315.1, 95, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -113.1, -59.9, -321.3, -96, 5996357},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -100.7, -60.1, -314.8, 16, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -97.9, -59.8, -307.0, 29, 5996357},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -89.8, -59.9, -300.6, -142, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -90.0, -60.5, -287.3, -3, 5996357},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -98.5, -60.1, -279.1, 115, 5996357},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -91.7, -60.0, -258.1, -153, 5996357},

		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -123.1, -59.8, -199.8, -142, 5996360},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -118.8, -59.8, -153.4, -73, 5996361},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -129.2, -60.1, -163.1, 155, 5996361},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -124.3, -60.1, -150.7, 175, 5996361},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -120.4, -60.0, -136.9, 111, 5996361},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -127.8, -60.0, -137.8, 111, 5996361},
		{"endor", "death_watch_blastromech_dungeonDeathWatchBunker", 600, -135.4, -59.9, -143.6, 111, 5996361},

		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -95.9, -60.1, -139.1, 156, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -93.7, -59.7, -150.1, -65, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -75.9, -60.2, -152, -50, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -63.6, -60.1, -148.2, -81, 5996362},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -70.7, -59.8, -160.8, -43, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -58.3, -59.9, -136.6, -142, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -78.9, -59.9, -129.1, 72, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -71.6, -59.5, -124.7, -140, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -50.1, -59.5, -123.4, 128, 5996362},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -39.1, -60.1, -136.6, -116, 5996362},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -39.2, -59.7, -147.8, -80, 5996362},


		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -151.2, -59.5, -162.2, 21, 5996364},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -142.1, -60.1, -164.2, -86, 5996364},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -143.7, -59.9, -175.8, -96, 5996364},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -147.1, -60.2, -190.2, -1, 5996364},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -153, -60.2, -184.8, 131, 5996364},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -142.8, -60.7, -198.2, -89, 5996364},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -152.9, -60.1, -210.9, 24, 5996364},

		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -148.4, -59.8, -125.4, 147, 5996365},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -178, -59.8, -121.0, 84, 5996366},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -176.2, -60, -133.1, -108, 5996369},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -171.9, -60.1, -140.7, -49, 5996369},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -179.6, -60.2, -142.6, -3, 5996369},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -177.0, -60.0, -150.3, -14, 5996369},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -180.4, -60.2, -150.8, 39, 5996369},

		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -205.8, -59.8, -121.3, -90, 5996367},
		{"endor", "death_watch_s_battle_droid_dungeonDeathWatchBunker", 300, -207.8, -60, -138.8, -7, 5996372},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -202.7, -60.1, -141.4, -149, 5996372},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -212.6, -59.9, -157.8, 22, 5996372},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -204.1, -60.6, -173.9, -4, 5996372},
		{"endor", "death_watch_battle_droid_dungeonDeathWatchBunker", 300, -206.5, -60.4, -177.8, -175, 5996372},
		{"endor", "death_watch_mine_rat_dungeonDeathWatchBunker", 300, -210.7, -60.1, -194.4, 164, 5996372},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -210.3, -60.1, -203.2, 169, 5996372},
		{"endor", "death_watch_miner_dungeonDeathWatchBunker", 300, -207.2, -60.1, -203, 5, 5996372},
	}
}

registerScreenPlay("DeathWatchBunkerScreenPlay", true)

function DeathWatchBunkerScreenPlay:start()
	if (isZoneEnabled("endor")) then
		local pBunker = getSceneObject(5996314)

		if pBunker == nil then
			return 0
		end

		self:spawnObjects()
		self:spawnDungeonMobiles()
		self:spawnMobiles()
		self:setupPermissionGroups()

		writeData("dwb:ventDroidAvailable", 1)

		createEvent(1000 * 45, "DeathWatchBunkerScreenPlay", "poisonEvent", pBunker, "")
		createObserver(ENTEREDBUILDING, "DeathWatchBunkerScreenPlay", "onEnterDWB", pBunker)
		createObserver(EXITEDBUILDING, "DeathWatchBunkerScreenPlay", "onExitDWB", pBunker)
	end
end

function DeathWatchBunkerScreenPlay:setupPermissionGroups()
	for i = 1, #self.doorData, 1 do
		local pCell = getSceneObject(self.doorData[i].cellAccess)
		if pCell ~= nil then
			SceneObject(pCell):setContainerInheritPermissionsFromParent(false)
			SceneObject(pCell):clearContainerDefaultDenyPermission(WALKIN)
			SceneObject(pCell):clearContainerDefaultAllowPermission(WALKIN)
			SceneObject(pCell):setContainerAllowPermission("DeathWatchBunkerDoor" .. i, WALKIN)
			SceneObject(pCell):setContainerDenyPermission("DeathWatchBunkerDoor" .. i, MOVEIN)
		end
	end
end

function DeathWatchBunkerScreenPlay:givePermission(pPlayer, permissionGroup)
	local pGhost = CreatureObject(pPlayer):getPlayerObject()

	if (pGhost ~= nil and not PlayerObject(pGhost):hasPermissionGroup(permissionGroup)) then
		PlayerObject(pGhost):addPermissionGroup(permissionGroup, true)
	end
end

function DeathWatchBunkerScreenPlay:removePermission(pPlayer, permissionGroup)
	local pGhost = CreatureObject(pPlayer):getPlayerObject()

	if (pGhost == nil) then
		return
	end

	if (PlayerObject(pGhost):hasPermissionGroup(permissionGroup)) then
		PlayerObject(pGhost):removePermissionGroup(permissionGroup, true)
	end
end

function DeathWatchBunkerScreenPlay:hasPermission(pPlayer, permissionGroup)
	local pGhost = CreatureObject(pPlayer):getPlayerObject()

	if (pGhost == nil) then
		return false
	end

	return PlayerObject(pGhost):hasPermissionGroup(permissionGroup)
end

function DeathWatchBunkerScreenPlay:spawnMobiles()
	for i,v in ipairs(deathWatchQuestNpcs) do
		if (isZoneEnabled(v[8])) then
			local pMobile = spawnMobile(v[8], v[1], v[2], v[3], v[4], v[5], v[6], v[7])

			if (pMobile ~= nil) then
				writeData("dwb:questMobile" .. i, SceneObject(pMobile):getObjectID())
			end
		end
	end
end

function DeathWatchBunkerScreenPlay:spawnObjects()
	local spawnedSceneObject = LuaSceneObject(nil)
	local spawnedPointer

	-- Door Access Terminal Outside
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -18.016,-12,-8.55806, 5996315, 1, 0, 0, 0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		writeData(5996314 .. ":dwb:access1", spawnedSceneObject:getObjectID())
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 1)
	end

	-- Outside locked door message
	local pActiveArea = spawnActiveArea("endor", "object/active_area.iff", -4680.6, 0.4, 4324.5, 5, 5996315)
	if pActiveArea ~= nil then
		createObserver(ENTEREDAREA, "DeathWatchBunkerScreenPlay", "notifyEnteredOutsideLockedDoorArea", pActiveArea)
	end

	-- Door Access Terminal A
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -84.4526,-20,-50.504,5996323,-0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		writeData(5996314 .. ":dwb:access2", spawnedSceneObject:getObjectID())
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 2)
	end

	-- Door Access Terminal B
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -8.3714,-32,-95.3985,5996331,-0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		writeData(5996314 .. ":dwb:access3", spawnedSceneObject:getObjectID())
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 3)
	end

	-- Door Access Terminal Mines
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", 26.1493,-64,-95.4288,5996347,0,0,1,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		writeData(5996314 .. ":dwb:access4", spawnedSceneObject:getObjectID())
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 4)
	end

	-- Voice Recognition Terminal
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/terminal_free_s1.iff",74.7941,-54,-143.444,5996348,-0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Voice Control Terminal")
		writeData("dwb:voiceControlTerminal", spawnedSceneObject:getObjectID())
	end

	-- Voice Terminal Instruction message
	local pActiveArea = spawnActiveArea("endor", "object/active_area.iff", -4588, -41.6, 4182.3, 10, 5996348)
	if pActiveArea ~= nil then
		createObserver(ENTEREDAREA, "DeathWatchBunkerScreenPlay", "notifyEnteredVoiceTerminalArea", pActiveArea)
	end

	--Blastromech
	local spawn = deathWatchSpecialSpawns["bombdroid"]
	local spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		CreatureObject(spawnedPointer):setPvpStatusBitmask(0)
		CreatureObject(spawnedPointer):setCustomObjectName("R2-M2")
		writeData("dwb:bombDroid", SceneObject(spawnedPointer):getObjectID())
		createEvent(100, "DeathWatchBunkerScreenPlay", "setBombDroidTemplate", spawnedPointer, "")
	end

	-- Bomb Droid Debris
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/invulnerable_debris.iff", 112.552,-63.7,-116.21,5996348,0.925444,0,0.378885,0)

	if (spawnedPointer ~= nil) then
		writeData("dwb:bombDebris", SceneObject(spawnedPointer):getObjectID())
	end

	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/invulnerable_debris.iff", 113.134,-63.8,-149.44,5996348,0.376442,0,0.92644,0)

	if (spawnedPointer ~= nil) then
		writeData("dwb:bombDebris2", SceneObject(spawnedPointer):getObjectID())
	end

	-- Armorsmith Access Terminal
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -232.11,-60,-219.996,5996373,0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Armorsmith Crafting Room Entry Terminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 5)
	end

	-- Droid Engineer Crafting Room Entry Terminal
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -230.09,-60,-124.003,5996367,0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Droid Engineer Crafting Room Entry Terminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 6)
	end

	-- Master Armorsmith Crafting Droid
	local spawn = deathWatchSpecialSpawns["armorsmithdroid"]

	spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		CreatureObject(spawnedPointer):setPvpStatusBitmask(0)

		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Crafting Droid")
		spawnedSceneObject:setContainerComponent("deathWatchCraftingDroid")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 1)
	end

	-- Armorsmith Crafting Terminal (Biceps, Chest, Boots)
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/terminal_free_s1.iff",-246.097,-60,-245.163,5996374,1,0,0,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Mandalorian Engineering Unit")
		spawnedSceneObject:setObjectMenuComponent("deathWatchMandalorianCraftingTerminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 1)
		writeData("dwb:craftingTerminal1:terminalID", spawnedSceneObject:getObjectID())
	end

	-- Master Droid Engineer Crafting Droid
	spawn = deathWatchSpecialSpawns["droidengineerdroid"]
	spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		CreatureObject(spawnedPointer):setPvpStatusBitmask(0)

		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Crafting Droid")
		spawnedSceneObject:setContainerComponent("deathWatchCraftingDroid")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 2)
	end

	-- Master Droid Engineer Crafting Terminal (Bracer, Helmet)
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/terminal_free_s1.iff",-234.536,-40,-84.8062,5996370,1,0,0,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Mandalorian Engineering Unit")
		spawnedSceneObject:setObjectMenuComponent("deathWatchMandalorianCraftingTerminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 2)
		writeData("dwb:craftingTerminal2:terminalID", spawnedSceneObject:getObjectID())
	end

	-- Master Tailor Crafting Droid
	spawn = deathWatchSpecialSpawns["tailordroid"]
	spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		CreatureObject(spawnedPointer):setPvpStatusBitmask(0)

		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Crafting Droid")
		spawnedSceneObject:setContainerComponent("deathWatchCraftingDroid")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 3)
	end

	-- Tailor Crafting Terminal (Pants, Gloves, Belt)
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/terminal_free_s1.iff",-141.981,-60,-74.3199,5996368,1,0,0,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Mandalorian Engineering Unit")
		spawnedSceneObject:setObjectMenuComponent("deathWatchMandalorianCraftingTerminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 3)
		writeData("dwb:craftingTerminal3:terminalID", spawnedSceneObject:getObjectID())
	end

	-- Jetpack Crafting Droid
	spawn = deathWatchSpecialSpawns["jetpackdroid"]
	spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		CreatureObject(spawnedPointer):setPvpStatusBitmask(0)

		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Jetpack Crafting Droid")
		spawnedSceneObject:setContainerComponent("deathWatchJetpackCraftingDroid")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 4)
	end

	-- Master Artisan Crafting Terminal (Jetpack)
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/terminal_free_s1.iff",-265.425,-50.0002,-84.957,5996370,1,0,0,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Mandalorian Engineering Unit")
		spawnedSceneObject:setObjectMenuComponent("deathWatchMandalorianCraftingTerminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:craftingterminal", 4)
		writeData("dwb:craftingTerminal4:terminalID", spawnedSceneObject:getObjectID())
	end

	-- Tailor Access Terminal
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/door_control_terminal.iff", -151.045,-60,-98.8703,5996365,0,0,1,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Tailor Crafting Room Entry Terminal")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:accessEnabled", 1)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 7)
	end

	-- Spawn Haldo
	local halnum = getRandomNumber(1,3)
	spawn = deathWatchSpecialSpawns["haldo" .. halnum]
	spawnedPointer = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "haldoDamage", spawnedPointer)
	end

	-- Water Pressure Valve Control A
	spawnedPointer = spawnSceneObject("endor","object/tangible/terminal/terminal_water_pressure.iff",42.2316,-32,-72.5555,5996340,-0.707107,0,-0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setObjectMenuComponent("deathWatchWaterValve")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 1)
		writeData("dwb:valve1", 1)
		self:spawnValveEffect(1, 1)
	end

	-- Water Pressure Valve Control B
	spawnedPointer = spawnSceneObject("endor","object/tangible/terminal/terminal_water_pressure.iff",56.0941,-32,-61.251,5996340,0,0,-1,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setObjectMenuComponent("deathWatchWaterValve")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 2)
		writeData("dwb:valve2", 1)
		self:spawnValveEffect(2, 1)
	end

	-- Water Pressure Valve Control C
	spawnedPointer = spawnSceneObject("endor","object/tangible/terminal/terminal_water_pressure.iff",73.7982,-32,-76.4291,5996340,0.707107,0,-0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setObjectMenuComponent("deathWatchWaterValve")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 3)
		deleteData("dwb:valve3")
		self:spawnValveEffect(3, 0)
	end

	-- Water Pressure Valve Control D
	spawnedPointer = spawnSceneObject("endor","object/tangible/terminal/terminal_water_pressure.iff",55.5855,-32,-92.8,5996340,1,0,0,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		spawnedSceneObject:setObjectMenuComponent("deathWatchWaterValve")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:terminal", 4)
		writeData("dwb:valve4", 1)
		self:spawnValveEffect(4, 1)
	end

	-- Rebreather Filter Dispenser
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/filter_dispenser.iff",-12.8382,-52,-147.565,5996378,0,0,1,0)

	-- Rebreather Workbench
	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/workbench.iff",-16.2596,-52,-147.091,5996378,0,0,1,0)

	-- Loot Boxes
	spawnedPointer = spawnSceneObject("endor", "object/tangible/container/general/tech_chest.iff", -3.10801,-12,36.7064,5996318,0,0,-1,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		self:setLootBoxPermissions(spawnedPointer)
		spawnedSceneObject:setCustomObjectName("Chest")
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:lootbox", 1)
		createEvent(1000, "DeathWatchBunkerScreenPlay", "refillContainer", spawnedPointer, "")
		createObserver(OPENCONTAINER, "DeathWatchBunkerScreenPlay", "boxLooted", spawnedPointer)
	end

	spawnedPointer = spawnSceneObject("endor", "object/tangible/dungeon/coal_bin_container.iff",6.01353,-32,-102.05,5996337,0.707107,0,0.707107,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		self:setLootBoxPermissions(spawnedPointer)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:lootbox", 2)
		createEvent(1000, "DeathWatchBunkerScreenPlay", "refillContainer", spawnedPointer, "")
		createObserver(OPENCONTAINER, "DeathWatchBunkerScreenPlay", "boxLooted", spawnedPointer)
	end

	spawnedPointer = spawnSceneObject("endor", "object/tangible/container/loot/placable_loot_crate_tech_armoire.iff", -2.78947,-32,-27.1899,5996335,0,0,1,0)

	if (spawnedPointer ~= nil) then
		spawnedSceneObject:_setObject(spawnedPointer)
		self:setLootBoxPermissions(spawnedPointer)
		writeData(spawnedSceneObject:getObjectID() .. ":dwb:lootbox", 3)
		createEvent(1000, "DeathWatchBunkerScreenPlay", "refillContainer", spawnedPointer, "")
		createObserver(OPENCONTAINER, "DeathWatchBunkerScreenPlay", "boxLooted", spawnedPointer)
	end
end

function DeathWatchBunkerScreenPlay:setBombDroidTemplate(pDroid)
	AiAgent(pDroid):setMovementState(AI_PATROLLING)
end

function DeathWatchBunkerScreenPlay:setLootBoxPermissions(pContainer)
	SceneObject(pContainer):setContainerInheritPermissionsFromParent(false)
	SceneObject(pContainer):setContainerDefaultDenyPermission(MOVEIN)
	SceneObject(pContainer):setContainerDefaultAllowPermission(OPEN + MOVEOUT)
end

function DeathWatchBunkerScreenPlay:onEnterDWB(sceneObject, pCreature)
	if (not SceneObject(pCreature):isPlayerCreature()) then
		return 0
	end

	createObserver(SPATIALCHATSENT, "DeathWatchBunkerScreenPlay", "notifyTerminalChatSent", pCreature)

	self:lockAll(pCreature)

	return 0
end

function DeathWatchBunkerScreenPlay:onExitDWB(sceneObject, pCreature, long)
	if (not SceneObject(pCreature):isPlayerCreature() == true) then
		return 0
	end

	if long == self.buildingIds.outside or long == 0 then
		self:lockAll(pCreature)
	end

	dropObserver(SPATIALCHATSENT, "DeathWatchBunkerScreenPlay", "notifyTerminalChatSent", pCreature)

	return 0
end

function DeathWatchBunkerScreenPlay:diedWhileCrafting(pCreature, pAttacker, long)
	if pCreature == nil then
		return 1
	end

	local creatureID = SceneObject(pCreature):getObjectID()

	if readData(creatureID .. ":dwb:currentlycrafting") ~= 0 then
		local termNumber = readData(creatureID .. ":dwb:terminal")
		local terminalID = readData("dwb:craftingTerminal" .. termNumber .. ":terminalID")

		if terminalID ~= 0 then
			local pTerminal = getSceneObject(terminalID)
			if pTerminal ~= nil then
				CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:died_during_crafting")
				self:stopCraftingProcess(pCreature, pTerminal, false, true)
			end
		end
	end

	return 1
end

function DeathWatchBunkerScreenPlay:enableAccess(pSceneObject)
	if (pSceneObject == nil) then
		return
	end

	writeData(SceneObject(pSceneObject):getObjectID() .. ":dwb:accessEnabled", 1)
end

function DeathWatchBunkerScreenPlay:respawnHaldo(creatureObject)
	local halNum = getRandomNumber(1,3)
	local spawn = deathWatchSpecialSpawns["haldo" .. halNum]
	local pMobile = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

	if (pMobile ~= nil) then
		createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "haldoDamage", pMobile)
	end
end

function DeathWatchBunkerScreenPlay:boxLooted(pSceneObject, pCreature)

	local objectID = SceneObject(pSceneObject):getObjectID()

	if readData(objectID .. ":dwb:spawned") ~= 1 then
		local boxId = readData(objectID .. ":dwb:lootbox")
		writeData(objectID .. ":dwb:spawned", 1)

		--spawn enemies
		if boxId == 1 then
			local spawn = deathWatchSpecialSpawns["lootbox1mob1"]
			local pMobile = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

			if (pMobile ~= nil) then
				createEvent(self.containerRespawnTime, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
			end
		elseif boxId == 2 then
			local spawn = deathWatchSpecialSpawns["lootbox2mob1"]
			local pMobile = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

			if (pMobile ~= nil) then
				createEvent(self.containerRespawnTime, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
			end
		elseif boxId == 3 then
			local spawn = deathWatchSpecialSpawns["lootbox3mob1"]
			local pMobile = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

			if (pMobile ~= nil) then
				createEvent(self.containerRespawnTime, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
			end

			local spawn = deathWatchSpecialSpawns["lootbox3mob2"]
			pMobile = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

			if (pMobile ~= nil) then
				createEvent(self.containerRespawnTime, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
			end
		end

		createEvent(self.containerRespawnTime, "DeathWatchBunkerScreenPlay", "refillContainer", pSceneObject, "")
	end

	return 0
end

function DeathWatchBunkerScreenPlay:despawnMobile(pMobile)
	if (pMobile == nil) then
		return
	end

	if (CreatureObject(pMobile):isInCombat()) then
		createEvent(15 * 1000, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
		return
	end

	SceneObject(pMobile):destroyObjectFromWorld()
end

function DeathWatchBunkerScreenPlay:refillContainer(pSceneObject)
	if (pSceneObject == nil) then
		return
	end

	if (SceneObject(pSceneObject):getContainerObjectsSize() == 0) then
		deleteData(SceneObject(pSceneObject):getObjectID() .. ":dwb:spawned")

		createLoot(pSceneObject, "death_watch_bunker_lootbox", 1, false)
		if getRandomNumber(100) > 95 then
			createLoot(pSceneObject, "death_watch_bunker_lootbox", 1, false)
		end
	end
end

function DeathWatchBunkerScreenPlay:poisonEvent(pSceneObject)
	if (readData("dwb:ventsEnabled") == 0) then
		for i,v in ipairs(self.mineCells) do
			local pCell = getSceneObject(v)
			if pCell ~= nil then
				local cellSize = SceneObject(pCell):getContainerObjectsSize()

				for j = 0, cellSize - 1, 1 do
					local pObject = SceneObject(pCell):getContainerObject(j)

					if pObject ~= nil then
						if (SceneObject(pObject):isPlayerCreature() and not self:hasRebreather(pObject)
							and not CreatureObject(pObject):isDead()
							and (not CreatureObject(pObject):isIncapacitated() or CreatureObject(pObject):isFeigningDeath())) then
							createEvent(500, "DeathWatchBunkerScreenPlay", "doPoison", pObject, "")
						end
					end
				end
			end
		end
	end
	createEvent(1000 * 45, "DeathWatchBunkerScreenPlay", "poisonEvent", pSceneObject, "")
end

function DeathWatchBunkerScreenPlay:timeWarning(pCreature)
	if pCreature == nil then
		return
	end

	if (readData(CreatureObject(pCreature):getObjectID() .. ":teleportedFromBunker") == 1) then
		return
	end

	if (CreatureObject(pCreature):isGrouped()) then
		local groupSize = CreatureObject(pCreature):getGroupSize()

		for i = 0, groupSize - 1, 1 do
			local pMember = CreatureObject(pCreature):getGroupMember(i)
			if pMember ~= nil then
				if CreatureObject(pMember):getParentID() > 5996313 and CreatureObject(pMember):getParentID() < 5996380 then
					CreatureObject(pMember):sendSystemMessage("@dungeon/death_watch:thirty_seconds")
				end
			end
		end
	else
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:thirty_seconds")
	end
end

function DeathWatchBunkerScreenPlay:isInBunker(parentID)
	if parentID > 5996313 and parentID < 5996380 then
		return true
	end

	return false
end

function DeathWatchBunkerScreenPlay:removeFromBunker(pCreature)
	if (pCreature == nil) then
		return 0
	end

	local playerID = SceneObject(pCreature):getObjectID()

	if readData(playerID .. ":dwb:currentlycrafting") ~= 0 then
		local termNumber = readData(playerID .. ":dwb:terminal")
		local terminalID = readData("dwb:craftingTerminal" .. termNumber .. ":terminalID")

		if terminalID ~= 0 then
			local pTerminal = getSceneObject(terminalID)
			if pTerminal ~= nil then
				self:stopCraftingProcess(pCreature, pTerminal, false, false)
			end
		end
	end

	-- This will eject the crafter and any other player the crafter was grouped with when they accessed the crafting room
	local dwbGroup = readStringVectorSharedMemory(playerID .. ":DeathWatchBUnker:CraftersGroup:")

	for i = 1, #dwbGroup, 1 do
		local memberID = tonumber(dwbGroup[i])
		local pMember = getSceneObject(memberID)

		if (pMember ~= nil and self:isInBunker(SceneObject(pMember):getParentID())) then
			createEvent(500, "DeathWatchBunkerScreenPlay", "teleportPlayer", pMember, "")
		end
	end

	deleteStringVectorSharedMemory(playerID .. ":DeathWatchBUnker:CraftersGroup:")
end

function DeathWatchBunkerScreenPlay:teleportPlayer(pCreature)
	if (pCreature == nil) then
		return 0
	end

	local creatureID = SceneObject(pCreature):getObjectID()
	local parentID = SceneObject(pCreature):getParentID()
	if (readData(creatureID .. ":teleportedFromBunker") == 1 or parentID == self.buildingIds.outside or parentID == 0) then
		return 0
	end

	writeData(creatureID .. ":teleportedFromBunker", 1)
	CreatureObject(pCreature):teleport(-4657, 14.4, 4322.3, 0)
	self:lockAll(pCreature)
end

function DeathWatchBunkerScreenPlay:notifyEnteredVoiceTerminalArea(pArea, pPlayer)
	if (not SceneObject(pPlayer):isPlayerCreature()) then
		return 0
	end

	CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:rc_mouse_instructions")

	return 0
end

function DeathWatchBunkerScreenPlay:notifyTerminalChatSent(pPlayer, pChatMessage)
	if (pPlayer == nil or not SceneObject(pPlayer):isPlayerCreature() or pChatMessage == nil) then
		return 0
	end

	local terminalID = readData("dwb:voiceControlTerminal")
	local pTerminal = getSceneObject(terminalID)

	if (pTerminal == nil or not SceneObject(pTerminal):isInRangeWithObject(pPlayer, 10)) then
		return 0
	elseif (not SceneObject(pTerminal):isInRangeWithObject(pPlayer, 3)) then
		CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:too_far_from_terminal")
		return 0
	end

	local bombDroidHandlerID = readData("dwb:bombDroidHandler")
	local terminalUserID = CreatureObject(pPlayer):getObjectID()

	if (bombDroidHandlerID == 0) then
		writeData("dwb:bombDroidHandler", terminalUserID)
		writeData("dwb:bombDroidHandlerLastUse", os.time())
	elseif (bombDroidHandlerID ~= terminalUserID) then
		local lastTerminalUse = readData("dwb:bombDroidHandlerLastUse")

		if (os.difftime(os.time(), lastTerminalUse) < 120) then
			CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:terminal_in_use")
			return 0
		else
			writeData("dwb:bombDroidHandler", terminalUserID)
			writeData("dwb:bombDroidHandlerLastUse", os.time())
		end
	end

	local spatialMsg = getChatMessage(pChatMessage)

	if (spatialMsg == nil or spatialMsg == "") then
		printLuaError("Invalid spatial message from player " .. SceneObject(pPlayer):getDisplayedName())
		return 0
	end

	local tokenizer = {}
	for word in spatialMsg:gmatch("%w+") do table.insert(tokenizer, word) end

	local spatialCommand = tokenizer[1]

	if (spatialCommand == nil or spatialCommand == "") then
		printLuaError("Invalid spatial command from player " .. SceneObject(pPlayer):getDisplayedName() .. ", spatial message: " .. spatialMsg)
		return 0
	end

	writeStringData("dwb:bombDroidHandlerLastSpatialCommand", spatialCommand)

	local moveDistance = 0

	if (tokenizer[2] ~= nil) then
		moveDistance = tonumber(tokenizer[2])

		if (moveDistance == nil) then
			return 0
		end

		if (moveDistance > 10) then
			moveDistance = 10
		elseif (moveDistance <= 0) then
			moveDistance = 1
		end
	end

	writeData("dwb:bombDroidHandlerLastMoveDistance", moveDistance)

	local bombDroidID = readData("dwb:bombDroid")
	local pBombDroid = getSceneObject(bombDroidID)

	createEvent(500, "DeathWatchBunkerScreenPlay", "doBombDroidAction", pBombDroid, "")

	return 0
end

function DeathWatchBunkerScreenPlay:doBombDroidAction(pBombDroid)
	local spatialCommand = readStringData("dwb:bombDroidHandlerLastSpatialCommand")

	if (spatialCommand == "reset" and pBombDroid == nil) then
		self:respawnBombDroid()
		return
	end

	if (pBombDroid == nil or not SceneObject(pBombDroid):isAiAgent()) then
		return
	end

	if (spatialCommand == "detonate") then
		CreatureObject(pBombDroid):playEffect("clienteffect/combat_grenade_proton.cef", "")
		CreatureObject(pBombDroid):inflictDamage(pBombDroid, 0, 1000000, 1)
		self:bombDroidDetonated(pBombDroid)
		writeData("dwb:lastDroidDetonate", os.time())
		return
	end

	local moveDistance = readData("dwb:bombDroidHandlerLastMoveDistance")

	local droidLoc = { x = SceneObject(pBombDroid):getPositionX(), z = SceneObject(pBombDroid):getPositionZ(), y = SceneObject(pBombDroid):getPositionY(), cell = SceneObject(pBombDroid):getParentID() }

	if (spatialCommand == "forward") then
		droidLoc.x = droidLoc.x + moveDistance
		if (droidLoc.x > 115) then
			droidLoc.x = 115
		end
	elseif (spatialCommand == "backward") then
		droidLoc.x = droidLoc.x - moveDistance
		if (droidLoc.x < 76) then
			droidLoc.x = 76
		end
	elseif (spatialCommand == "left") then
		droidLoc.y = droidLoc.y + moveDistance
		if (droidLoc.y > -114) then
			droidLoc.y = -114
		end
	elseif (spatialCommand == "right") then
		droidLoc.y = droidLoc.y - moveDistance
		if (droidLoc.y < -152) then
			droidLoc.y = -152
		end
	end

	AiAgent(pBombDroid):setNextPosition(droidLoc.x, droidLoc.z, droidLoc.y, droidLoc.cell)
end

function DeathWatchBunkerScreenPlay:notifyEnteredVoiceTerminalArea(pArea, pPlayer)
	if (not SceneObject(pPlayer):isPlayerCreature()) then
		return 0
	end

	CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:rc_mouse_instructions")
	return 0
end

function DeathWatchBunkerScreenPlay:notifyEnteredOutsideLockedDoorArea(pArea, pPlayer)
	if (not SceneObject(pPlayer):isPlayerCreature()) then
		return 0
	end

	if (not CreatureObject(pPlayer):hasScreenPlayState(1, "death_watch_bunker")) then
		CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:entrance_denied")
	end

	return 0
end

function DeathWatchBunkerScreenPlay:bombDroidDetonated(pBombDroid)
	if (pBombDroid == nil) then
		return 1
	end

	local debrisID = readData("dwb:bombDebris")
	local debrisID2 = readData("dwb:bombDebris2")

	local pDebris = getSceneObject(debrisID)
	local pDebris2 = getSceneObject(debrisID2)

	if (pDebris == nil and pDebris2 == nil) then
		return 1
	end

	if (pDebris ~= nil and SceneObject(pBombDroid):isInRangeWithObject(pDebris, 5)) then
		SceneObject(pDebris):playEffect("clienteffect/combat_grenade_proton.cef", "")
		createEvent(500, "DeathWatchBunkerScreenPlay", "destroyDebris", pDebris, "")
	elseif (pDebris2 ~= nil and SceneObject(pBombDroid):isInRangeWithObject(pDebris2, 5)) then
		SceneObject(pDebris2):playEffect("clienteffect/combat_grenade_proton.cef", "")
		createEvent(500, "DeathWatchBunkerScreenPlay", "destroyDebris", pDebris2, "")
	end

	createEvent(2000, "DeathWatchBunkerScreenPlay", "despawnCreature", pBombDroid, "")
	deleteData("dwb:bombDroid")

	return 1
end

function DeathWatchBunkerScreenPlay:respawnDebris(pOldDebris)
	if (pOldDebris == nil) then
		return
	end

	local oldDebrisID = SceneObject(pOldDebris):getObjectID()

	if (oldDebrisID == readData("dwb:bombDebris")) then
		local pDebris = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/invulnerable_debris.iff", 112.552,-64,-116.21,5996348,0.925444,0,0.378885,0)
		writeData("dwb:bombDebris", SceneObject(pDebris):getObjectID())
	elseif (oldDebrisID == readData("dwb:bombDebris2")) then
		local pDebris = spawnSceneObject("endor", "object/tangible/dungeon/death_watch_bunker/invulnerable_debris.iff", 113.134,-64,-149.44,5996348,0.376442,0,0.92644,0)
		writeData("dwb:bombDebris2", SceneObject(pDebris):getObjectID())
	end
end

function DeathWatchBunkerScreenPlay:destroyDebris(pDebris)
	if (pDebris ~= nil) then
		createEvent(self.debrisRespawnTime, "DeathWatchBunkerScreenPlay", "respawnDebris", pDebris, "")
		SceneObject(pDebris):destroyObjectFromWorld()
	end
end

function DeathWatchBunkerScreenPlay:respawnBombDroid(pDroid)
	local spawn = deathWatchSpecialSpawns["bombdroid"]
	local pBombDroid = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])
	CreatureObject(pBombDroid):setPvpStatusBitmask(0)
	CreatureObject(pBombDroid):setCustomObjectName("R2-M2")
	writeData("dwb:bombDroid", SceneObject(pBombDroid):getObjectID())
	createEvent(100, "DeathWatchBunkerScreenPlay", "setBombDroidTemplate", pBombDroid, "")
end

function DeathWatchBunkerScreenPlay:haldoTimer(pCreature)
	if (not CreatureObject(pCreature):hasScreenPlayState(4, "death_watch_foreman_stage")) then
		CreatureObject(pCreature):removeScreenPlayState(1, "death_watch_foreman_stage")
		CreatureObject(pCreature):removeScreenPlayState(2, "death_watch_foreman_stage")
		CreatureObject(pCreature):removeScreenPlayState(4, "death_watch_foreman_stage")
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:haldo_failed")
		if (not CreatureObject(pCreature):hasScreenPlayState(2, "death_watch_haldo")) then
			CreatureObject(pCreature):removeScreenPlayState(1, "death_watch_haldo")
		end
	end
end

function DeathWatchBunkerScreenPlay:haldoKilled(pHaldo, pPlayer)
	createEvent(1000 * 240, "DeathWatchBunkerScreenPlay", "respawnHaldo", pPlayer, "")
	if (CreatureObject(pPlayer):hasScreenPlayState(2, "death_watch_foreman_stage") and not CreatureObject(pPlayer):hasScreenPlayState(4, "death_watch_foreman_stage")) then
		local pInventory = CreatureObject(pPlayer):getSlottedObject("inventory")
		if (pInventory == nil) then
			CreatureObject(pPlayer):sendSystemMessage("Error: Unable to find player inventory.")
		else
			if (SceneObject(pInventory):isContainerFullRecursive() == true) then
				CreatureObject(pPlayer):sendSystemMessage("@error_message:inv_full")
				return 1
			else
				local pBattery = getContainerObjectByTemplate(pInventory, "object/tangible/dungeon/death_watch_bunker/drill_battery.iff", true)
				if (pBattery == nil) then
					pBattery = giveItem(pInventory,"object/tangible/dungeon/death_watch_bunker/drill_battery.iff", -1)
					if (pBattery == nil) then
						CreatureObject(pPlayer):sendSystemMessage("Error: Unable to generate item.")
					else
						CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:recovered_battery")
						CreatureObject(pPlayer):setScreenPlayState(4, "death_watch_haldo")
					end
				end
			end
		end
	end

	return 1
end

function DeathWatchBunkerScreenPlay:haldoDamage(pHaldo, pPlayer, damage)
	if pHaldo == nil or pPlayer == nil then
		return 1
	end

	if ((CreatureObject(pHaldo):getHAM(0) <= (CreatureObject(pHaldo):getMaxHAM(0) * 0.9)) or (CreatureObject(pHaldo):getHAM(3) <= (CreatureObject(pHaldo):getMaxHAM(3) * 0.9)) or (CreatureObject(pHaldo):getHAM(6) <= (CreatureObject(pHaldo):getMaxHAM(6) * 0.9))) then
		local spawnLoc = { x = CreatureObject(pHaldo):getPositionX(), z = CreatureObject(pHaldo):getPositionZ(), y = CreatureObject(pHaldo):getPositionY(), cell = CreatureObject(pHaldo):getParentID(), angle = CreatureObject(pHaldo):getDirectionAngle() }
		local spawnHam = { h = CreatureObject(pHaldo):getHAM(0), a = CreatureObject(pHaldo):getHAM(3), m = CreatureObject(pHaldo):getHAM(6) }
		SceneObject(pHaldo):destroyObjectFromWorld()

		local pNewHaldo = spawnMobile("endor", "mand_bunker_crazed_miner_converse_dungeonDeathWatchBunker", 0, spawnLoc.x, spawnLoc.z, spawnLoc.y, spawnLoc.angle, spawnLoc.cell)

		if (pNewHaldo == nil) then
			return 1
		end

		CreatureObject(pNewHaldo):setPvpStatusBitmask(0)
		CreatureObject(pNewHaldo):setHAM(0, spawnHam.h)
		CreatureObject(pNewHaldo):setHAM(3, spawnHam.a)
		CreatureObject(pNewHaldo):setHAM(6, spawnHam.m)

		spatialChat(pNewHaldo, "@dungeon/death_watch:help_me")

		return 1
	else
		return 0
	end
end

function DeathWatchBunkerScreenPlay:spawnAggroHaldo(pOldHaldo, pPlayer)
	local spawnLoc = { x = CreatureObject(pOldHaldo):getPositionX(), z = CreatureObject(pOldHaldo):getPositionZ(), y = CreatureObject(pOldHaldo):getPositionY(), cell = CreatureObject(pOldHaldo):getParentID(), angle = CreatureObject(pOldHaldo):getDirectionAngle() }
	local spawnHam = { h = CreatureObject(pOldHaldo):getHAM(0), a = CreatureObject(pOldHaldo):getHAM(3), m = CreatureObject(pOldHaldo):getHAM(6) }
	SceneObject(pOldHaldo):destroyObjectFromWorld()

	local pNewHaldo = spawnMobile("endor", "mand_bunker_crazed_miner_dungeonDeathWatchBunker", 0, spawnLoc.x, spawnLoc.z, spawnLoc.y, spawnLoc.angle, spawnLoc.cell)

	if (pNewHaldo == nil) then
		return
	end

	CreatureObject(pNewHaldo):setHAM(0, spawnHam.h)
	CreatureObject(pNewHaldo):setHAM(3, spawnHam.a)
	CreatureObject(pNewHaldo):setHAM(6, spawnHam.m)

	createObserver(OBJECTDESTRUCTION, "DeathWatchBunkerScreenPlay", "haldoKilled", pNewHaldo)
	spatialChat(pNewHaldo, "@conversation/death_watch_insane_miner:s_99f3d3be")
	CreatureObject(pNewHaldo):engageCombat(pPlayer)
end

function DeathWatchBunkerScreenPlay:pumpTimer(pPlayer)
	if (not CreatureObject(pPlayer):hasScreenPlayState(64, "death_watch_foreman_stage")) then
		CreatureObject(pPlayer):removeScreenPlayState(32, "death_watch_foreman_stage")
		CreatureObject(pPlayer):setScreenPlayState(2, "death_watch_foreman_stage_failed")
		CreatureObject(pPlayer):sendSystemMessage("@dungeon/death_watch:water_pressure_failed")
	end
end

function DeathWatchBunkerScreenPlay:destroyIngredient(pIngredient)
	if pIngredient ~= nil then
		SceneObject(pIngredient):destroyObjectFromWorld()
		SceneObject(pIngredient):destroyObjectFromDatabase()
	end
end

--------------------------------------------------------------
--   Key Spawn Events                                        -
--------------------------------------------------------------
function DeathWatchBunkerScreenPlay:spawnDefender(spawnData, spawnName)
	local pMobile = spawnMobile("endor", spawnData[1], spawnData[2], spawnData[3], spawnData[4], spawnData[5], spawnData[6], spawnData[7])

	if (pMobile ~= nil) then
		AiAgent(pMobile):addObjectFlag(AI_STATIONARY)

		createEvent(300 * 1000, "DeathWatchBunkerScreenPlay", "despawnMobile", pMobile, "")
		createEvent(10, "DeathWatchBunkerScreenPlay", "startDefenderPath", pMobile, spawnName)
	end

	return pMobile
end

function DeathWatchBunkerScreenPlay:startDefenderPath(pMobile, spawnName)
	if (pMobile == nil) then
		return
	end

	local patrolPoint

	if (string.find(spawnName, "rageon_vart")) then
		local waveNum = tonumber(string.sub(spawnName, 12))
		patrolPoint = deathWatchPatrolPoints.rageon_vart[waveNum]
	elseif (string.find(spawnName, "klin_nif")) then
		local waveNum = tonumber(string.sub(spawnName, 9))
		patrolPoint = deathWatchPatrolPoints.klin_nif[waveNum]
	elseif (string.find(spawnName, "fenri_dalso")) then
		local waveNum = tonumber(string.sub(spawnName, 12))
		patrolPoint = deathWatchPatrolPoints.fenri_dalso[waveNum]
	else
		printLuaError("DeathWatchBunkerScreenPlay:startDefenderPath, invalid spawnName " .. spawnName)
	end

	local randomX = (-5 + getRandomNumber(10)) / 10
	local randomY = (-5 + getRandomNumber(10)) / 10

	local pCell = getSceneObject(patrolPoint[4])

	if (pCell == nil) then
		printLuaError("Invalid cellid " .. patrolPoint[4] .. " in DeathWatchBunkerScreenPlay:startDefenderPath for spawn " .. spawnName)
		return
	end

	AiAgent(pMobile):setNextPosition(patrolPoint[1] + randomX, patrolPoint[2], patrolPoint[3] + randomY, patrolPoint[4])
end

function DeathWatchBunkerScreenPlay:spawnNextA(pCreature)
	if (pCreature == nil) then
		return
	end

	local nextSpawn = readData(5996314 .. ":dwb:terminalAnextSpawn")

	if nextSpawn == 0 then
		return
	elseif nextSpawn == 1 then
		writeData(5996314 .. ":dwb:terminalAnextSpawn", 2)
		local spawn = deathWatchSpecialSpawns["rageon_vart_assist1"]
		local pDefender = self:spawnDefender(spawn, "rageon_vart1")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnADefenderDamageReceived", pDefender)
		end
	elseif nextSpawn == 2 then
		writeData(5996314 .. ":dwb:terminalAnextSpawn", 3)
		local spawn = deathWatchSpecialSpawns["rageon_vart_assist1"]
		local pDefender = self:spawnDefender(spawn, "rageon_vart2")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnADefenderDamageReceived", pDefender)
		end

		spawn = deathWatchSpecialSpawns["rageon_vart_assist2"]
		self:spawnDefender(spawn, "rageon_vart2")
	else
		deleteData(5996314 .. ":dwb:terminalAnextSpawn")

		local spawn = deathWatchSpecialSpawns["rageon_vart_assist1"]
		self:spawnDefender(spawn, "rageon_vart1")

		spawn = deathWatchSpecialSpawns["rageon_vart_assist2"]
		self:spawnDefender(spawn, "rageon_vart3")

		spawn = deathWatchSpecialSpawns["rageon_vart"]
		self:spawnDefender(spawn, "rageon_vart1")
	end
end

function DeathWatchBunkerScreenPlay:spawnADefenderDamageReceived(pDefender, pPlayer, damage)
	if pDefender == nil then
		return 1
	end

	spatialChat(pDefender, "@dungeon/death_watch:call_back_up")
	createEvent(30 * 1000, "DeathWatchBunkerScreenPlay", "spawnNextA", pPlayer, "")

	return 1
end

function DeathWatchBunkerScreenPlay:spawnNextB(pCreature)
	if (pCreature == nil) then
		return 0
	end

	local nextSpawn = readData(5996314 .. ":dwb:terminalBnextSpawn")

	if nextSpawn == 0 then
		return 0
	elseif nextSpawn == 1 then
		writeData(5996314 .. ":dwb:terminalBnextSpawn", 2)
		local spawn = deathWatchSpecialSpawns["klin_nif_assist1"]
		local pDefender = self:spawnDefender(spawn, "klin_nif1")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnBDefenderDamageReceived", pDefender)
		end
	elseif nextSpawn == 2 then
		writeData(5996314 .. ":dwb:terminalBnextSpawn", 3)
		local spawn = deathWatchSpecialSpawns["klin_nif_assist1"]
		local pDefender = self:spawnDefender(spawn, "klin_nif1")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnBDefenderDamageReceived", pDefender)
		end

		spawn = deathWatchSpecialSpawns["klin_nif_assist2"]
		pDefender = self:spawnDefender(spawn, "klin_nif2")
	else
		deleteData(5996314 .. ":dwb:terminalBnextSpawn")
		local spawn = deathWatchSpecialSpawns["klin_nif_assist1"]
		self:spawnDefender(spawn, "klin_nif1")

		local spawn = deathWatchSpecialSpawns["klin_nif_assist2"]
		self:spawnDefender(spawn, "klin_nif2")

		local spawn = deathWatchSpecialSpawns["klin_nif"]
		self:spawnDefender(spawn, "klin_nif3")
	end
end

function DeathWatchBunkerScreenPlay:spawnBDefenderDamageReceived(pDefender, pPlayer, damage)
	if pDefender == nil then
		return 1
	end

	local defenderID = SceneObject(pDefender):getObjectID()

	spatialChat(pDefender, "@dungeon/death_watch:call_back_up")
	createEvent(30 * 1000, "DeathWatchBunkerScreenPlay", "spawnNextB", pPlayer, "")

	return 1
end

function DeathWatchBunkerScreenPlay:spawnNextC(creatureObject)
	if (creatureObject == nil) then
		return 0
	end

	local nextSpawn = readData(5996314 .. ":dwb:terminalCnextSpawn")
	if nextSpawn == 0 then
		return 0
	elseif nextSpawn == 1 then
		writeData(5996314 .. ":dwb:terminalCnextSpawn", 2)
		local spawn = deathWatchSpecialSpawns["fenri_dalso_assist1"]
		local pDefender = self:spawnDefender(spawn, "fenri_dalso1")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnCDefenderDamageReceived", pDefender)
		end
	elseif nextSpawn == 2 then
		writeData(5996314 .. ":dwb:terminalCnextSpawn", 3)
		local spawn = deathWatchSpecialSpawns["fenri_dalso_assist1"]
		local pDefender = self:spawnDefender(spawn, "fenri_dalso2")

		if (pDefender ~= nil) then
			createObserver(DAMAGERECEIVED, "DeathWatchBunkerScreenPlay", "spawnCDefenderDamageReceived", pDefender)
		end

		spawn = deathWatchSpecialSpawns["fenri_dalso_assist2"]
		self:spawnDefender(spawn, "fenri_dalso2")
	else
		deleteData(5996314 .. ":dwb:terminalCnextSpawn")
		local spawn = deathWatchSpecialSpawns["fenri_dalso_assist1"]
		self:spawnDefender(spawn, "fenri_dalso3")

		spawn = deathWatchSpecialSpawns["fenri_dalso_assist2"]
		self:spawnDefender(spawn, "fenri_dalso3")

		spawn = deathWatchSpecialSpawns["fenri_dalso_assist3"]
		self:spawnDefender(spawn, "fenri_dalso3")

		spawn = deathWatchSpecialSpawns["fenri_dalso_assist4"]
		self:spawnDefender(spawn, "fenri_dalso3")

		spawn = deathWatchSpecialSpawns["fenri_dalso"]
		self:spawnDefender(spawn, "fenri_dalso1")
	end
end

function DeathWatchBunkerScreenPlay:spawnCDefenderDamageReceived(pDefender, pPlayer, damage)
	if pDefender == nil then
		return 1
	end

	local defenderID = SceneObject(pDefender):getObjectID()

	spatialChat(pDefender, "@dungeon/death_watch:call_back_up")
	createEvent(30 * 1000, "DeathWatchBunkerScreenPlay", "spawnNextC", pPlayer, "")

	return 1
end

--   DeathWatchBunkerScreenPlay whether a creature has sufficient skill to access a particular crafting room
function DeathWatchBunkerScreenPlay:hasRequiredSkill(room, pCreature)
	if (room < 1 or room > 8) then
		return false
	end

	return CreatureObject(pCreature):hasSkill(self.terminalSkills[room])
end

-- Checks whether a creature has an Alum Mineral
function DeathWatchBunkerScreenPlay:hasAlumMineral(pCreature)
	if pCreature == nil then
		return false
	end

	local pInventory = SceneObject(pCreature):getSlottedObject("inventory")

	if (pInventory == nil) then
		return false
	end

	return getContainerObjectByTemplate(pInventory, self.bunkerItems.alumMineral, true) ~= nil
end

-- Checks whether a creature has all necessary items to access a particular crafting room  -
function DeathWatchBunkerScreenPlay:findRequiredItem(room, pCreature)
	if (pCreature == nil) then
		return nil
	end

	if (room < 1 or room > 7) then
		return nil
	end

	local pInventory = SceneObject(pCreature):getSlottedObject("inventory")

	if (pInventory == nil) then
		return nil
	end

	local table = self.requiredDoorItems[room]

	for i,v in ipairs(table) do
		local pObj = getContainerObjectByTemplate(pInventory, v, true)
		if (pObj ~= nil) then
			return pObj
		end
	end
	return nil
end

--   Checks whether a creature has sufficient protection against alum mine poison  -
function DeathWatchBunkerScreenPlay:hasRebreather(pSceneObject)
	local pRebreather = SceneObject(pSceneObject):getSlottedObject("eyes")

	if (pRebreather == nil) then
		return false
	end

	local headSlot = SceneObject(pRebreather):getTemplateObjectPath()

	if (headSlot == self.bunkerItems.mandoRebreather) then
		return SceneObject(pRebreather):getCustomObjectName() == "Advanced Rebreather"
	elseif (headSlot == self.bunkerItems.mandoHelmet) then
		return true
	end
	return false
end

--   Inflict poison damage on a creature
function DeathWatchBunkerScreenPlay:doPoison(pCreature)
	if pCreature == nil then
		return 0
	end

	CreatureObject(pCreature):inflictDamage(pCreature, 0, 100, 0)
	CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:bad_air")
end

--   Lock all restricted cells to a creature  -
function DeathWatchBunkerScreenPlay:lockAll(pCreature)
	CreatureObject(pCreature):removeScreenPlayState(2, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(4, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(8, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(16, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(32, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(64, "death_watch_bunker")
	CreatureObject(pCreature):removeScreenPlayState(128, "death_watch_bunker")

	for i = 1, #self.doorData, 1 do
		self:removePermission(pCreature, "DeathWatchBunkerDoor" .. i)
	end

	CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:relock")
end

function DeathWatchBunkerScreenPlay:spawnDefenders(number, pCreature)
	if number < 1 or number > 4 then
		return 0
	end

	if number == 1 then
		local spawn = deathWatchSpecialSpawns["entrance1"]
		local pMobile1 = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])
		spawn = deathWatchSpecialSpawns["entrance2"]
		local pMobile2 = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])

		if pCreature ~= nil then
			if (pMobile1 ~= nil) then
				CreatureObject(pMobile1):engageCombat(pCreature)
			end

			if (pMobile2 ~= nil) then
				CreatureObject(pMobile2):engageCombat(pCreature)
			end
		end
	else
		writeData(5996314 .. ":dwb:" .. self.spawnGroups[number], 1)
		createEvent(2 * 1000, "DeathWatchBunkerScreenPlay", self.spawnEvents[number], pCreature, "")
	end
end

function DeathWatchBunkerScreenPlay:unlockForGroup(number, pCreature, cells)
	-- screenplaystates for login/logout
	if (CreatureObject(pCreature):isGrouped()) then
		local groupSize = CreatureObject(pCreature):getGroupSize()

		for i = 0, groupSize - 1, 1 do
			local pMember = CreatureObject(pCreature):getGroupMember(i)

			if pMember ~= nil then
				local groupMember = LuaCreatureObject(pMember)

				local parentID = groupMember:getParentID()

				if (cells and parentID > 5996313 and parentID < 5996380) or ((not cells) and groupMember:getZoneName() == "endor") then
					groupMember:setScreenPlayState(self.states[number], "death_watch_bunker")
					self:givePermission(pMember, "DeathWatchBunkerDoor" .. number)
					groupMember:sendSystemMessage(self.doorMessages[number].unlock)
				end
			end
		end
	else
		CreatureObject(pCreature):setScreenPlayState(self.states[number], "death_watch_bunker")
		self:givePermission(pCreature, "DeathWatchBunkerDoor" .. number)
		CreatureObject(pCreature):sendSystemMessage(self.doorMessages[number].unlock)
	end
end

function DeathWatchBunkerScreenPlay:checkDoor(pSceneObject, pCreature)
	if pCreature == nil or pSceneObject == nil then
		return
	end

	local doorEnabled = readData(SceneObject(pSceneObject):getObjectID() .. ":dwb:accessEnabled")
	local doorNumber = readData(SceneObject(pSceneObject):getObjectID() .. ":dwb:terminal")

	local doorType = self.doorData[doorNumber].doorType

	if doorType == 1 then
		if not CreatureObject(pCreature):hasScreenPlayState(1, "death_watch_bunker") then
			if (doorEnabled == 0) then
				CreatureObject(pCreature):sendSystemMessage(self.doorMessages[doorNumber].lock)
				return
			end

			CreatureObject(pCreature):sendGroupMessage("@dungeon/death_watch:airlock_backup")
			self:spawnDefenders(doorNumber, pCreature)
		else
			self:unlockForGroup(doorNumber, pCreature, false)
			return
		end
	elseif doorType == 2 then
		local requiredItem = self:findRequiredItem(doorNumber, pCreature)
		if (requiredItem == nil) then
			if (doorEnabled == 0) then
				CreatureObject(pCreature):sendSystemMessage(self.doorMessages[doorNumber].lock)
				return
			end

			CreatureObject(pCreature):sendGroupMessage("@dungeon/death_watch:denied_access")
			self:spawnDefenders(doorNumber, pCreature)
		else
			self:unlockForGroup(doorNumber, pCreature, true)
			SceneObject(requiredItem):destroyObjectFromWorld()
			SceneObject(requiredItem):destroyObjectFromDatabase()
			return
		end
	elseif doorType == 3 then
		if (doorEnabled == 0) then
			CreatureObject(pCreature):sendSystemMessage(self.doorMessages[doorNumber].lock)
			return
		end

		if (self:findRequiredItem(doorNumber, pCreature) == nil or self:hasAlumMineral(pCreature) == false) then
			CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:not_enough_ingredients")
			return
		end

		if (self:hasRequiredSkill(doorNumber, pCreature) == false) then
			CreatureObject(pCreature):sendSystemMessage(self.missingSkillMessage[doorNumber])
			return
		end

		self:unlockForGroup(doorNumber, pCreature, true)

		local pCell = getSceneObject(self.doorData[doorNumber].cellAccess)

		if pCell == nil then
			return
		end

		local crafterID = SceneObject(pCreature):getObjectID()
		local groupMembers = {}

		if (CreatureObject(pCreature):isGrouped()) then
			local groupSize = CreatureObject(pCreature):getGroupSize()

			for i = 0, groupSize - 1, 1 do
				local pMember = CreatureObject(pCreature):getGroupMember(i)

				if pMember ~= nil then
					local memberID = CreatureObject(pMember):getObjectID()
					deleteData(memberID .. ":teleportedFromBunker")

					groupMembers[#groupMembers + 1] = tostring(memberID)
				end
			end
		else
			deleteData(CreatureObject(pCreature):getObjectID() .. ":teleportedFromBunker")
			groupMembers[#groupMembers + 1] = tostring(crafterID)
		end

		writeStringVectorSharedMemory(crafterID .. ":DeathWatchBUnker:CraftersGroup:", groupMembers)

		createEvent(1000 * 60 * 5, "DeathWatchBunkerScreenPlay", "removeFromBunker", pCreature, "")
		createEvent(1000 * 60 * 4.5, "DeathWatchBunkerScreenPlay", "timeWarning", pCreature, "")
		createEvent(1000 * 60 * 5.5, "DeathWatchBunkerScreenPlay", "despawnCellMobiles", pCell, "")
	end

	deleteData(SceneObject(pSceneObject):getObjectID() .. ":dwb:accessEnabled")
	createEvent(1000 * 60 * self.doorData[doorNumber].lockTime, "DeathWatchBunkerScreenPlay", "enableAccess", pSceneObject, "")
end

function DeathWatchBunkerScreenPlay:despawnCellMobiles(pCell)
	if pCell == nil then
		return
	end

	local cellSize = SceneObject(pCell):getContainerObjectsSize()
	for i = 0, cellSize - 1, 1 do
		local pObject = SceneObject(pCell):getContainerObject(i)
		if pObject ~= nil then
			if SceneObject(pObject):isCreatureObject() then
				local template = SceneObject(pObject):getTemplateObjectPath()

				if string.find(template, "death_watch") ~= nil or string.find(template, "battle_droid") ~= nil then
					createEvent(1000, "DeathWatchBunkerScreenPlay", "despawnCreature", pObject, "")
				end
			end
		end
	end
end

function DeathWatchBunkerScreenPlay:despawnCreature(pObject)
	if pObject ~= nil then
		SceneObject(pObject):destroyObjectFromWorld()
	end
end

function DeathWatchBunkerScreenPlay:startForemanQuestStage(number, pCreature)
	if pCreature == nil then
		return
	end

	if number == 1 then
		createEvent(1000 * 60 * 60, "DeathWatchBunkerScreenPlay", "haldoTimer", pCreature, "")
	elseif number == 2 then
		createEvent(1000 * 60 * 60, "DeathWatchBunkerScreenPlay", "pumpTimer", pCreature, "")
	end
end

function DeathWatchBunkerScreenPlay:storeTime(pCreature)
	if pCreature ~= nil then
		local time = os.time()
		writeScreenPlayData(pCreature, "DeathWatchBunkerScreenPlay", "time", time)
	end
end

function DeathWatchBunkerScreenPlay:checkTime(pCreature)
	if pCreature == nil then
		return false
	end

	local currentTime = os.time()
	local receivedTime = readScreenPlayData(pCreature, "DeathWatchBunkerScreenPlay", "time")

	-- Fix for people who had done the quest prior to Publish 7
	if (receivedTime == "") then
		receivedTime = readScreenPlayData(pCreature, "DWB", "time")
	end

	if receivedTime == "" then
		return false
	end

	local seconds = os.difftime(currentTime, receivedTime)

	if (seconds > 216000) then --more then 60 hours passed
		return true
	end

	return false
end

function DeathWatchBunkerScreenPlay:cancelCrafting(pTerm)
	if pTerm == nil then
		return
	end

	local terminalID = SceneObject(pTerm):getObjectID()

	local number = readData(terminalID .. ":dwb:craftingterminal")
	local statusPrefix = "dwb:craftingTerminal" .. number .. ":"

	local isCrafting = readData(statusPrefix .. "currentlycrafting")

	if isCrafting > 0 and isCrafting < 4 then
		if (readData(statusPrefix .. "stepStartTime") == 0 or os.difftime(os.time(), readData(statusPrefix .. "stepStartTime")) < 30) then
			return
		end

		local id = readData(statusPrefix .. "user")
		if id ~= 0 then
			local pCreature = getSceneObject(id)
			if pCreature ~= nil then
				CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:took_too_long")
				self:stopCraftingProcess(pCreature, pTerm, false, true)
			end
		end
	end
end

function DeathWatchBunkerScreenPlay:stopCraftingProcess(pCreature, pTerm, successful, teleport)
	if pCreature == nil or pTerm == nil then
		return
	end

	local terminalID = SceneObject(pTerm):getObjectID()
	local playerID = SceneObject(pCreature):getObjectID()
	local number = readData(terminalID .. ":dwb:craftingterminal")
	local statusPrefix = "dwb:craftingTerminal" .. number .. ":"

	local target = readData(statusPrefix .. "targetitemindex")

	deleteData(playerID .. ":dwb:currentlycrafting")
	deleteData(playerID .. ":dwb:terminal")
	deleteData(statusPrefix .. "currentlycrafting")
	deleteData(statusPrefix .. "stepStartTime")
	deleteData(statusPrefix .. "user")
	deleteData(statusPrefix .. "targetitemindex")
	deleteData(statusPrefix .. "alummineral")
	deleteData(statusPrefix .. "jetpackbase")
	deleteData(statusPrefix .. "jetpackstabilizer")
	deleteData(statusPrefix .. "ductedfan")
	deleteData(statusPrefix .. "injectortank")
	deleteData(statusPrefix .. "dispersionunit")
	deleteData(statusPrefix .. "binary")
	deleteData(statusPrefix .. "protective")
	deleteData(statusPrefix .. "bharmorpart")

	if successful == true then
		local pInventory = SceneObject(pCreature):getSlottedObject("inventory")

		if (pInventory == nil) then
			return 0
		end

		local targetItems = self.targetItems[number]
		local pReward = giveItem(pInventory, targetItems[target], -1)


		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:crafting_finished")

		if (pReward == nil) then
			CreatureObject(pCreature):sendSystemMessage("Error: Unable to generate item.")
			return 0
		end

		if (number ~= 4) then
			TangibleObject(pReward):setCustomizationVariable("/private/index_color_1", self.primaryArmorColors[getRandomNumber(1,8)])
			TangibleObject(pReward):setCustomizationVariable("/private/index_color_2", self.secondaryArmorColors[getRandomNumber(1,8)])
		end
	end

	if teleport == true then
		if (number == 4) then
			createEvent(5000, "DeathWatchBunkerScreenPlay", "removeFromBunker", pCreature, "")
		else
			createEvent(500, "DeathWatchBunkerScreenPlay", "teleportPlayer", pCreature, "")
		end
	end
end

function DeathWatchBunkerScreenPlay:sendUseTerminalMessage(pCreature)
	if pCreature ~= nil then
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:use_terminal")
	end
end

function DeathWatchBunkerScreenPlay:swapValveState(pCreature, valveNumber, notifyPlayer)
	local curState = readData("dwb:valve" .. valveNumber)
	local newState

	if (curState == 1) then
		if (notifyPlayer) then
			CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:valve_off")
		end
		curState = 0
	else
		if (notifyPlayer) then
			CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:valve_on")
		end
		curState = 1
	end
	writeData("dwb:valve" .. valveNumber, curState)

	self:spawnValveEffect(valveNumber, curState)
end

function DeathWatchBunkerScreenPlay:spawnValveEffect(valveNumber, valveState)
	local effectID = readData("dwb:valve_effect" .. valveNumber)
	local pEffect = getSceneObject(effectID)

	if (pEffect ~= nil) then
		SceneObject(pEffect):destroyObjectFromWorld()
	end

	local pValveEffect
	local valveData = self.deathWatchValveEffects[valveNumber]
	if (valveState == 1) then
		pValveEffect = spawnSceneObject("endor","object/static/particle/pt_light_streetlamp_green.iff",valveData[1],valveData[2],valveData[3],5996340,0,0,0,0)
	else
		pValveEffect = spawnSceneObject("endor","object/static/particle/pt_light_streetlamp_red.iff",valveData[1],valveData[2],valveData[3],5996340,0,0,0,0)
	end

	if (pValveEffect ~= nil) then
		writeData("dwb:valve_effect" .. valveNumber, SceneObject(pValveEffect):getObjectID())
	end
end

function DeathWatchBunkerScreenPlay:doValveSwitch(pCreature, valveNumber)
	if valveNumber == 1 then
		self:swapValveState(pCreature, 1, true)
		self:swapValveState(pCreature, 4, false)
	elseif valveNumber == 2 then
		self:swapValveState(pCreature, 2, true)
		self:swapValveState(pCreature, 3, false)
	elseif valveNumber == 3 then
		self:swapValveState(pCreature, 2, false)
		self:swapValveState(pCreature, 3, true)
		self:swapValveState(pCreature, 4, false)
	elseif valveNumber == 4 then
		self:swapValveState(pCreature, 1, false)
		self:swapValveState(pCreature, 3, false)
		self:swapValveState(pCreature, 4, true)
	end

	local state1 = readData("dwb:valve1")
	local state2 = readData("dwb:valve2")
	local state3 = readData("dwb:valve3")
	local state4 = readData("dwb:valve4")

	if (state1 == 1 and state2 == 1 and state3 == 1 and state4 == 1) then
		playClientEffectLoc(pCreature, "clienteffect/dth_watch_water_pressure.cef", "endor", CreatureObject(pCreature):getPositionX(), CreatureObject(pCreature):getPositionZ(), CreatureObject(pCreature):getPositionY(), CreatureObject(pCreature):getParentID())
		CreatureObject(pCreature):setScreenPlayState(64, "death_watch_foreman_stage")
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:restored_pressure")
		-- Reset valves to starting state with A, B and D active
		self:swapValveState(pCreature, 3, false)
	end
end

function DeathWatchBunkerScreenPlay:startCraftingProcess(pCreature, pTerminal)
	if pCreature == nil or pTerminal == nil then
		return
	end

	local playerID = CreatureObject(pCreature):getObjectID()
	local number = readData(SceneObject(pTerminal):getObjectID() .. ":dwb:craftingterminal")
	local statusPrefix = "dwb:craftingTerminal" .. number .. ":"

	writeData(statusPrefix .. "stepStartTime", os.time())
	createEvent(1000 * 30, "DeathWatchBunkerScreenPlay", "cancelCrafting", pTerminal, "")
	createEvent(1000, "DeathWatchBunkerScreenPlay", "sendUseTerminalMessage", pCreature, "")
	writeData(playerID .. ":dwb:currentlycrafting", 1)
	writeData(playerID .. ":dwb:terminal", number)
	writeData(statusPrefix .. "currentlycrafting", 1)
	createObserver(OBJECTDESTRUCTION, "DeathWatchBunkerScreenPlay", "diedWhileCrafting", pCreature)
end

function DeathWatchBunkerScreenPlay:nextCraftingStep(pTerm)
	if pTerm == nil then
		return
	end

	local terminalID = SceneObject(pTerm):getObjectID()

	local number = readData(terminalID .. ":dwb:craftingterminal")
	local statusPrefix = "dwb:craftingTerminal" .. number .. ":"

	writeData(statusPrefix .. "currentlycrafting", 3)
	local creoId = readData(statusPrefix .. "user")
	if creoId ~= 0 then
		local pCreature = getSceneObject(creoId)
		self:sendUseTerminalMessage(pCreature)
		writeData(statusPrefix .. "stepStartTime", os.time())
		createEvent(1000 * 30, "DeathWatchBunkerScreenPlay", "cancelCrafting", pTerm, "")
	end
end

function DeathWatchBunkerScreenPlay:finishCraftingStep(pTerm)
	if pTerm == nil then
		return
	end

	local number = readData(SceneObject(pTerm):getObjectID() .. ":dwb:craftingterminal")

	local creoId = readData("dwb:craftingTerminal" .. number .. ":user")
	if creoId ~= 0 then
		local pCreature = getSceneObject(creoId)
		if pCreature ~= nil then
			self:stopCraftingProcess(pCreature, pTerm, true, true)
		end
	end
end

function DeathWatchBunkerScreenPlay:getObjOwner(pObj)
	local pPlayerInv = SceneObject(pObj):getParent()

	if (pPlayerInv == nil) then
		return nil
	end

	local parent = SceneObject(pPlayerInv):getParent()

	if (parent == nil) then
		return nil
	end

	if (SceneObject(parent):isCreatureObject()) then
		return parent
	end

	return nil
end

function DeathWatchBunkerScreenPlay:craftingConfirmCallback(pCreature, pSui, eventIndex)
	local cancelPressed = (eventIndex == 1)
	local suiBox = LuaSuiBox(pSui)
	local pUsingObject = suiBox:getUsingObject()

	if (pUsingObject == nil or cancelPressed) then
		return 0
	end

	local usingID = SceneObject(pUsingObject):getObjectID()
	local number = readData(usingID .. ":dwb:craftingterminal")
	local statusPrefix = "dwb:craftingTerminal" .. number .. ":"

	local step = readData(statusPrefix .. "currentlycrafting")

	if step == 1 then
		writeData(statusPrefix .. "currentlycrafting", 2)
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:alum_process_begun")
		writeData(statusPrefix .. "stepStartTime", 0)
		createEvent(10 * 1000, "DeathWatchBunkerScreenPlay", "nextCraftingStep", pUsingObject, "")
	elseif step == 3 then
		writeData(statusPrefix .. "currentlycrafting", 4)
		CreatureObject(pCreature):sendSystemMessage("@dungeon/death_watch:aeration_process_begun")
		createEvent(10 * 1000, "DeathWatchBunkerScreenPlay", "finishCraftingStep", pUsingObject, "")
	end

	return 0
end

function DeathWatchBunkerScreenPlay:doVentDroidStep(pDroid)
	local curStep = readData("dwb:ventDroidStep")

	local pCell = getSceneObject(5996379)

	if (pCell == nil) then
		return
	end

	if (curStep == -1) then
		return
	end

	if (curStep == 0) then -- Initial spawn at technician, wait 10 secs
		local spawn = deathWatchSpecialSpawns["ventdroid"]
		pDroid = spawnMobile("endor", spawn[1], spawn[2], spawn[3], spawn[4], spawn[5], spawn[6], spawn[7])
		SceneObject(pDroid):setCustomObjectName("Ventilation Repair Droid")
		CreatureObject(pDroid):setPvpStatusBitmask(0)
		createObserver(DESTINATIONREACHED, "DeathWatchBunkerScreenPlay", "ventDroidDestinationReached", pDroid)
		AiAgent(pDroid):addObjectFlag(AI_NOAIAGGRO)
		AiAgent(pDroid):addObjectFlag(AI_FOLLOW)
		AiAgent(pDroid):setMovementState(AI_PATROLLING)
		createEvent(10 * 1000, "DeathWatchBunkerScreenPlay", "doVentDroidStep", pDroid, "")
		writeData("dwb:ventDroidStep", curStep + 1)
	elseif (curStep == 1) then -- Move to toolbox
		self:sendMessageToCell(5996345, "@dungeon/death_watch:protect_tools")
		self:sendMessageToCell(5996378, "@dungeon/death_watch:protect_tools")
		self:sendMessageToCell(5996379, "@dungeon/death_watch:protect_tools")
		self:doVentDroidMove(pDroid)
	elseif (curStep == 2) then -- Wait 120 seconds
		self:sendMessageToCell(5996379, "@dungeon/death_watch:protect_tools")
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -7.4, -52, -119.1, 120, 5996379)
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -4.6, -52, -117.2, 172, 5996379)
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -3.1, -52, -120.7, -113, 5996379)
		createEvent(120 * 1000, "DeathWatchBunkerScreenPlay", "doVentDroidStep", pDroid, "")
		writeData("dwb:ventDroidStep", curStep + 1)
	elseif (curStep == 3) then -- move to first center boxed area
		self:sendMessageToCell(5996379, "@dungeon/death_watch:protect_fix")
		self:doVentDroidMove(pDroid)
	elseif (curStep == 4) then -- Start repair effect, wait 120 seconds
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -1.9, -54.1, -112.9, -66, 5996379)
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -1.7, -54.1, -110.0, -137, 5996379)
		spawnMobile("endor", "death_watch_bloodguard_dungeonDeathWatchBunker_3", 0, -8.3, -54.1, -113.9, 83, 5996379)
		SceneObject(pDroid):updateDirection(0)
		local pValveEffect = spawnSceneObject("endor","object/static/particle/pt_poi_droid_weld_sparks.iff",-6.0, -53.2, -112,5996379,0.707,0.707,0,0)
		if (pValveEffect ~= nil) then
			writeData("dwb:ventDroidEffectID", SceneObject(pValveEffect):getObjectID())
		end
		createEvent(120 * 1000, "DeathWatchBunkerScreenPlay", "doVentDroidStep", pDroid, "")
		writeData("dwb:ventDroidStep", curStep + 1)
	elseif (curStep == 5) then -- End effect, Despawn droid, complete quest
		local effectID = readData("dwb:ventDroidEffectID")
		local pEffect = getSceneObject(effectID)
		if (pEffect ~= nil) then
			SceneObject(pEffect):destroyObjectFromWorld()
		end

		local starterID = readData("dwb:droidEscortStarter")

		local pStarter = getSceneObject(starterID)

		SceneObject(pDroid):destroyObjectFromWorld()
		deleteData("dwb:ventDroidEffectID")
		deleteData("dwb:ventDroidStep")
		self:sendMessageToCell(5996378, "@dungeon/death_watch:ventilation_repair")
		self:sendMessageToCell(5996379, "@dungeon/death_watch:ventilation_repair")
		deleteData("dwb:droidEscortStatus")
		deleteData("dwb:droidEscortStarter")
		writeData("dwb:ventsEnabled", 1)


		if (pStarter == nil) then
			return
		end

		CreatureObject(pStarter):setScreenPlayState(2, "death_watch_bunker_technician_sidequest")

		createEvent(60 * 60 * 1000, "DeathWatchBunkerScreenPlay", "disableVents", pStarter, "") -- Disable vents after an hour
	end
end

function DeathWatchBunkerScreenPlay:ventDroidDestinationReached(pDroid)
	createEvent(1500, "DeathWatchBunkerScreenPlay", "doVentDroidMove", pDroid, "")
	return 0
end

function DeathWatchBunkerScreenPlay:doVentDroidMove(pDroid)
	local curStep = readData("dwb:ventDroidStep")
	local patrolPoints
	if (curStep == 1) then
		patrolPoints = self.ventDroidPatrolPoints[1]
	elseif (curStep == 3) then
		patrolPoints = self.ventDroidPatrolPoints[2]
	else
		printf("ERROR: DeathWatchBunkerScreenPlay:doVentDroidMove called on wrong step.\n")
		return
	end

	local patrolPointCount = #patrolPoints
	local onCurrentPoint = readData("dwb:ventDroidCurrentPoint")

	if (onCurrentPoint == patrolPointCount) then
		deleteData("dwb:ventDroidCurrentPoint")
		writeData("dwb:ventDroidStep", curStep + 1)
		self:doVentDroidStep(pDroid)
		return
	end

	local nextPoint = patrolPoints[onCurrentPoint + 1]

	AiAgent(pDroid):setNextPosition(nextPoint[1], nextPoint[2], nextPoint[3], nextPoint[4])

	writeData("dwb:ventDroidCurrentPoint", onCurrentPoint + 1)
end

function DeathWatchBunkerScreenPlay:disableVents()
	deleteData("dwb:ventsEnabled")
end

-- Not used until droid is made attackable by spawns
function DeathWatchBunkerScreenPlay:failVentEscort(pDroid)
	deleteData("dwb:droidEscortStatus")
	deleteData("dwb:droidEscortStarter")
	deleteData("dwb:ventDroidAvailable")
	writeData("dwb:ventDroidStep", -1)
	self:sendMessageToCell(5996379, "@dungeon/death_watch:repair_failed")
	self:sendMessageToCell(5996378, "@dungeon/death_watch:repair_failed")
	createEvent(5 * 60 * 1000, "DeathWatchBunkerScreenPlay", "createNewVentDroid", pDroid, "") -- New vent droid available 5 mins after failing
end

function DeathWatchBunkerScreenPlay:createNewVentDroid()
	writeData("dwb:ventDroidAvailable", 1)
	deleteData("dwb:ventDroidStep")
end

function DeathWatchBunkerScreenPlay:sendMessageToCell(cellID, string)
	local pCell = getSceneObject(cellID)

	if pCell == nil then
		return
	end

	local cellSize = SceneObject(pCell):getContainerObjectsSize()
	for i = 0, cellSize - 1, 1 do
		local pObject = SceneObject(pCell):getContainerObject(i)
		if pObject ~= nil then
			if SceneObject(pObject):isPlayerCreature() then
				CreatureObject(pObject):sendSystemMessage(string)
			end
		end
	end
end
