AbandonedRebelBaseScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "AbandonedRebelBaseScreenPlay",

	planet = "dantooine",

	ScreenPSpawns = {
		--inside perimeter near east building area
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6656.4, 30.0, 5552.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6661.4, 30.0, 5557.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6651.4, 30.0, 5547.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6663.4, 30.0, 5562.4, -1, 0},

		{"dantooine", "rebel_recruiter_poiDantooineAbandonedRebelBase", 0, -6817, 46, 5511, 174, 0},

		--inside main building
		{"dantooine", "vrovel_poiDantooineAbandonedRebelBase", 60, -1.1, 1.0, 0.5, 177, 6555560, ""},
		{"dantooine", "ezkiel_poiDantooineAbandonedRebelBase", 60, -3.2, 1.0, 7.9, 11, 6555560, ""}
	}
}

registerScreenPlay("AbandonedRebelBaseScreenPlay", true)

function AbandonedRebelBaseScreenPlay:start()
	if (isZoneEnabled(self.planet)) then
		self:spawnScreenPMobiles()
	end
end

