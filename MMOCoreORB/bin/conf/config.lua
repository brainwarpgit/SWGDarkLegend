--Copyright (C) 2007 <SWGEmu>

--This File is part of Core3.

--This program is free software; you can redistribute
--it and/or modify it under the terms of the GNU Lesser
--General Public License as published by the Free Software
--Foundation; either version 2 of the License,
--or (at your option) any later version.

--This program is distributed in the hope that it will be useful,
--but WITHOUT ANY WARRANTY; without even the implied warranty of
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
--See the GNU Lesser General Public License for
--more details.

--You should have received a copy of the GNU Lesser General
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

--Linking Engine3 statically or dynamically with other modules
--is making a combined work based on Engine3.
--Thus, the terms and conditions of the GNU Lesser General Public License
--cover the whole combination.

--In addition, as a special exception, the copyright holders of Engine3
--give you permission to combine Engine3 program with free software
--programs or libraries that are released under the GNU LGPL and with
--code included in the standard release of Core3 under the GNU LGPL
--license (or modified versions of such code, with unchanged license).
--You may copy and distribute such a system following the terms of the
--GNU LGPL for Engine3 and the licenses of the other code concerned,
--provided that you include the source code of that other code when
--and as the GNU LGPL requires distribution of source code.

--Note that people who make modified versions of Engine3 are not obligated
--to grant this special exception for their modified versions;
--it is their choice whether to do so. The GNU Lesser General Public License
--gives permission to release a modified version without this exception;
--this exception also makes it possible to release a modified version
--which carries forward this exception.
-- Core3 Config File
-- 0 = false, 1 = true

Core3 = {
	------Server Make Options------
	MakeLogin = 1,
	MakeZone = 1,
	MakePing = 1,
	MakeStatus = 1,
--	MakeWeb = 0,

	------ORB Server Config------
	ORB = "",
	ORBPort = 44419,

	------Main Database Config------
	DBHost = "127.0.0.1",
	DBPort = 3306,
	DBName = "swgemu",
	DBUser = "swgemu",
	DBPass = "123456",
--	DBInstances = 2,
	DBSecret = "swgemus3cr37!", -- Change this! This value should be unique and of reasonable length.

	------Login Server Config------
	LoginPort = 44453,
	LoginProcessingThreads = 1,
	LoginAllowedConnections = 3000,
	LoginRequiredVersion = "20050408-18:00",

	------Mantis Database Config------
	MantisHost = "127.0.0.1",
	MantisPort = 3306,
	MantisName = "swgemu",
	MantisUser = "swgemu",
	MantisPass = "123456",
	MantisPrfx = "mantis_", -- The prefix for your mantis tables.

	------Metrics Server Config------
	MetricsHost = "127.0.0.1",
	MetricsPort = 8125,
	MetricsPrefix = "",

	------Ping Server Config------
	PingPort = 44462,
	PingAllowedConnections = 3000,

	------Zone Server config------
	ZoneProcessingThreads = 10,
	ZoneAllowedConnections = 30000,
	ZoneGalaxyID = 2, --The actual zone server's galaxyID. Should coordinate with your login server.
	ZonePortsBalancer = 1,
	ZonerServerPort = 0,

	-------- GROUND ZONES -------
	ZonesEnabled = {
		-------- PRE-CU ZONES -------
		"corellia",
		"dantooine",
		"dathomir",
		"dungeon1",
		"endor",
		"lok",
		"naboo",
		"rori",
		"talus",
		"tatooine",
		"tutorial",
		"yavin4",
		-------- NEW CONTENT ZONES -------
		--"chandrila",
		--"coruscant",
		"dungeon2",
		--"hoth",
		--"kaas",
		--"kashyyyk",
		--"kashyyyk_hunting",
		--"kashyyyk_rryatt_trail",
		--"kashyyyk_main",
		--"kashyyyk_south_dungeons",
		--"kashyyyk_north_dungeons",
		--"kashyyyk_pob_dungeons",
		--"kashyyyk_dead_forest",
		--"mandalore",
		--"moraband",
		--"mustafar",
		--"taanab",
		-------- TEST ZONES -------
		--"09",
		--"10",
		--"11",
		--"character_farm",
		--"cinco_city_test_m5",
		--"creature_test",
		--"endor_asommers",
		--"floratest",
		--"godclient_test",
		--"otoh_gunga",
		--"rivertest",
		--"runtimerules",
		--"simple",
		--"taanab",
		--"test_wearables",
		--"umbra",
		--"watertabletest",
	},
	-------- SPACE ZONES -------
	SpaceZonesEnabled = {
		"space_corellia",
		"space_dantooine",
		"space_dathomir",
		"space_endor",
		"space_heavy1",
		"space_light1",
		"space_lok",
		"space_naboo",
		"space_tatooine",
		"space_yavin4"
		---- TEST ZONES ----
		--"space_09",
		--"space_corellia_2",
		--"space_env",
		--"space_halos",
		--"space_naboo_2",
		--"space_tatooine_2",
	},

	------TRE config------
	TrePath = "/home/swgemu/workspace/tre",
	TreFiles = {
		--"SWGDL_update_02.tre",
		"SWGDL_update_01.tre",
		"mtg_patch_023.tre",
		"mtg_patch_022.tre",
		"mtg_planets.tre",
		"mtg_patch_021.tre",
		--"mtg_patch_020.tre",
		"mtg_patch_019.tre",
		"mtg_patch_018.tre",
		"mtg_patch_017.tre",
		"mtg_patch_016.tre",
		"mtg_patch_015.tre",
		"mtg_patch_014.tre",
		"mtg_patch_013_configurable_02.tre",
		"mtg_patch_012_configurable_01.tre",
		"mtg_patch_011_files_01.tre",
		"mtg_patch_010_object_01.tre",
		"mtg_patch_009_Shader_01.tre",
		"mtg_patch_008_texture_04.tre",
		"mtg_patch_007_texture_03.tre",
		"mtg_patch_006_texture_02.tre",
		"mtg_patch_005_texture_01.tre",
		"mtg_patch_004_appearance_04.tre",
		"mtg_patch_003_appearance_03.tre",
		"mtg_patch_002_appearance_02.tre",
		"mtg_patch_001_appearance_01.tre"
	},

	------Status Server Config------
	StatusPort = 44455,
	StatusAllowedConnections = 500,
	StatusInterval = 30, -- interval to check if zone is locked up (in seconds)

	------Web Server Config------
--	WebPorts = 44460, -- Can be multiple ports 44460,44461
--	WebAccessLog = "../log/webaccess.log",
--	WebErrorLog = "../log/weberror.log",
--	WebSessionTimeout = 600, -- Length that inactive web sessions expire

	------Logging Config------
	LogFile = "log/core3.log",
	LogFileLevel = 4, -- -1 NONE, 0 FATAL, 1 ERROR, 2 WARNING, 3 LOG, 4 INFO, 5 DEBUG
	LogJSON = 0, -- global log output in JSON format
	LogSync = 0, -- flush global log file after each write
	LuaLogJSON = 0,
	PathfinderLogJSON = 0,
	PlayerLogLevel = 4, -- -1 NONE, 0 FATAL, 1 ERROR, 2 WARNING, 3 LOG, 4 INFO, 5 DEBUG
	MaxLogLines = 1000000, -- how often to rotate log (currently only log/player.log rotates)
	RotateLogSizeMB = 100, -- Size to Rotate Logs in MB
	RotateLogAtStart = 0,
	OnlineLogSeconds = 300,
	OnlineLogSize = 100000000,
	LogOnlineOnSessionChange = 1,
	
	------REST Server Config------
	RESTServerPort = 0,

	------Account Config------
	InactiveAccountTitle = "Account Disabled",
	InactiveAccountText = "The server administrators have disabled your account.",

	------Character Config------
	CleanupMailCount = 25000,
--	DeleteCharacters = 10, -- How often in minutes to purge deleted characters
	PurgeDeletedCharacters = 10,
	SameAccountTipsAreFree = 0,
	
	------Extra Config ------
	MaxNavMeshJobs = 6,
	MaxAuctionSearchJobs = 1,
	DumpObjFiles = 1,
	ProgressMonitors = "false",
	UnloadContainers = 1, -- Whether to unload container contents from RAM after the container hasn't been accessed for a time
	UseMetrics = 0,
	PvpMode = 0,
	MOTD = "Welcome to SWGEmu!",
	Revision = "",
	SessionStatsSeconds = 3600,
	

	------Server Config------
	CharacterBuilderEnabled = "true",
	AutoReg = 1,
	RegistrationMessage = "Automatic registration is currently disabled.  Please contact the administrators of the server in order to get an authorized account.",

	------TOS Config------
	TermsOfServiceVersion = 0,
	TermsOfService = "",
}

Core3.AccountManager = {
	CreatedDateFirstConnect = false,
	HolocronTicketsEnabled = false,
}

Core3.AiAgent = {
	AiAgentLoadTesting = false,
	ConsoleThrottle = 100,
	LogLevel = 2,
	Verbose = false,
}

Core3.AuctionItem = {
	ExportOnDestroy = false,
}

Core3.AuctionManager = {
	LogLevel = -1,
	Startup = {
	ExpireInvalid = false,
	}
}

Core3.ChatManager = {
	PvpBroadcastChannel = false,
}

Core3.CombatManager = {
	AllowSameAccountLinkDeadBeneficialActions = true,
}

Core3.CommandConfigManager = {
	DumpAdminCommand = false,
}

Core3.DirectorManager = {
	SlowLoadMs = 1000,
}

Core3.FrsManager = {
	ImmediateMaintXpDeduction = false,
}

Core3.GCWManager = {
	useCovertOvertSystem = false,
}

Core3.Login = {
	EnableSessionId = false,
	SessionDuration = "00:15",
}

Core3.LootManager = {
	DebugAttributes = false,
}

Core3.LuaEngine = {
	LogLevel = 1,
	LuaEventLogLevel = 4,
}

Core3.MissionManager = {
	AnonymousBountyTerminals = false,
	IncludeFactionPets = true,
	ListRequestCooldown = 1400,
	MaxBountiesPerJedi = 5,
	PlayerBountyCooldown = true,
	PlayerBountyCooldownTime = 86400000, -- 24 hour default
	PrivateStructureJediMissions = false,
}

Core3.NameManager = {
	FilterTable = oldFilterWords,
}

Core3.PlanetManager = { -- Only for Debugging Used Defaults, can be changed.
	ShuttleportAwayTime = 300,
	ShuttleportLandedTime = 120,
	ShuttleportLandingTime = 11,
	StarportAwayTime = 60,
	StarportLandedTime = 120,
	StarportLandingTime = 14,
}

Core3.PlayerCreationManager = {
	--EnableTutorial = false, --uncomment to force Tutorial on or off.   leave commented for player choice.
	MaxCharactersPerGalaxy = 4,
}

Core3.PlayerManager = {
	AdvancedWaypoints = true,
	DisableGroupVisibility = true,
	GalaxyWideGrouping = true,
	ValidClientVersion = "20050408-18:00",
	WipeFillingOnClone = true,
}

Core3.PlayerObject = {
	AlwaysSafeLogout = true, --default false
	LinkDeadDelay = 60, -- default 180 in seconds
}

Core3.Regions = {
	minimumLairSpawnInterval = 5000,
	spawnCheckRange = 64,
}

Core3.RESTServer = {
	APIToken = "",
	LogLevel = 4,
	exportDir = "log/exports/api/%Y-%m-%d/%H/",
	SSLCertFile = "",
	SSLKeyFile = "",
	WorkerThreads = 4,
}

Core3.SceneObject = {
	exportDir = "log/exports/%Y-%m-%d/%H/",
}

Core3.ShipAiAgent = {
	LogLevel = 2,
}

Core3.ShuttleZoneComponent = {
	BootDelay = 60000, -- default 300000 in milliseconds
}

Core3.SpaceZone = {
	ThreadsDefault = 1,
}

Core3.StructureMaintenanceTask = {
	AllowBankPayments = true,
}


Core3.StructureManager = {
	EnhancedFurnitureRotate = true,
}

Core3.StructureObject = {
	MaintenanceBootDelay = 600,
}

Core3.TangibleObject = {
	ForceNoTradeMessage = "",
	ForceNoTradeADKMessage = "",
	NoTradeMessage = "",
}

Core3.TransactionLog = {
	LogLevel = 5,
	WorkerThreads = 4,
}	

Core3.TreManager = {
	LatestTre = "SWGDL_update_02.tre",
	ReloadStrings = true,
}

Core3.Tweaks = {
	StructureObject = {
		DestroyOrphans = false,
	}
}

Core3.Zone = {
	ThreadsDefault = 1,
}
-- NOTE: conf/config-local.lua is parsed after this file if it exists
