Yavin4LaborOutpostScreenPlay = CityScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "Yavin4LaborOutpostScreenPlay",

	planet = "yavin4",

	stationaryCommoners = {"commoner", "commoner_fat", "commoner_old"},
	stationaryNpcs = {"bodyguard", "bounty_hunter", "businessman", "chiss_female", "chiss_male", "commoner_technician", "explorer", "fringer", "gambler", "medic", "mercenary", "miner",  "pilot", "scientist", "slicer"},

	--{respawn, x, z, y, direction, cell, mood}
	stationaryMobiles = {
		{1, 7.3, 0.6, -6.7, -149, 3035379, "npc_standing_drinking"}, {1, 5.8, 0.6, -6.2, -141, 3035379, "angry"}, {1, -6.8, 0.6, 6.3, 179, 3035377, "npc_sitting_chair"}, {1, -6.8, 0.6, 5.0, 1, 3035377, "happy"},
		{1, -6.1, 0.6, -3.8, -102, 3035374, "sad"}, {1, -6.1, 0.6, -4.8, -10, 3035374, "npc_consoling"},
	},

	mobiles = {
		{"eker", 60, -3.9, 0.6, 1.2, -144, 3035372, ""},
		{"aqzow", 60, 1.9, 0.6, 1.7, 40, 3035376, ""},
		
		{"junk_dealer", 0, -6982, 73, -5751, 20, 0, ""},
	}
}

registerScreenPlay("Yavin4LaborOutpostScreenPlay", true)

function Yavin4LaborOutpostScreenPlay:start()
	if (isZoneEnabled(self.planet)) then
		self:spawnStaticMobiles()
		self:spawnStationaryMobiles()
	end
end

