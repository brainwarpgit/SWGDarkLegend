AbandonedRebelBaseScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "AbandonedRebelBaseScreenPlay",

	ScreenPSpawns = {
		--inside perimeter near east building area
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6656.4, 30.0, 5552.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6661.4, 30.0, 5557.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6651.4, 30.0, 5547.4, -1, 0},
		{"dantooine", "rebel_commando_poiDantooineAbandonedRebelBase", 400, -6663.4, 30.0, 5562.4, -1, 0},

		{"dantooine", "rebel_recruiter_poiDantooineAbandonedRebelBase", 0, -6817, 46, 5511, 174, 0},
	}
}

registerScreenPlay("AbandonedRebelBaseScreenPlay", true)

function AbandonedRebelBaseScreenPlay:start()
	if (isZoneEnabled("dantooine")) then
		self:spawnScreenPMobiles()
	end
end


