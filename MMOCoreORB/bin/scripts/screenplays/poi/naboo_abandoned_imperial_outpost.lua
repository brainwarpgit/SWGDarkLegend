NabooAbandonedImperialOutputScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "NabooAbandonedImperialOutputScreenPlay",
	ScreenPSpawns = {
		-- Outside
		{"naboo", "thief_poiNabooAbandonedImperialOutpost", 300, 964.6, 261.1, -1345.6, 158, 0},
		{"naboo", "scavenger_poiNabooAbandonedImperialOutpost", 300, 975.0, 262.2, -1332.9, -132, 0},	
		-- Corridor
		{"naboo", "nightspider_poiNabooAbandonedImperialOutpost", 300, 3.8, 0.5, -3.6, -62, 7825776},
		{"naboo", "nightspider_poiNabooAbandonedImperialOutpost", 300, 3.8, 0.5, 2.9, 172, 7825777},
		{"naboo", "nightspider_poiNabooAbandonedImperialOutpost", 300, -1.9, 2.0, 3.4, 66, 7825777},
		-- Top floor
		{"naboo", "nightspider_poiNabooAbandonedImperialOutpost", 300, 971.0, 267.5, -1341.7, 113, 0 },
		{"naboo", "nightspider_aggressor_poiNabooAbandonedImperialOutpost", 300, 974.1, 267.5, -1341.9, -121, 0 },
		{"naboo", "nightspider_poison_spitter_poiNabooAbandonedImperialOutpost", 300, 977.1, 267.5, -1343.6, -173, 0 },
		{"naboo", "nightspider_aggressor_poiNabooAbandonedImperialOutpost", 300, 972.2, 267.5, -1345.1, 7, 0 },
	}
}

registerScreenPlay("NabooAbandonedImperialOutputScreenPlay", true)

function NabooAbandonedImperialOutputScreenPlay:start()
	if (isZoneEnabled("naboo")) then
		self:spawnScreenPMobiles()
	end
end

