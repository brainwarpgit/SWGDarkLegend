EndorMarauderStrongholdScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "EndorMarauderStrongholdScreenPlay",

	ScreenPSpawns = {
		{"endor", "grassland_blood_marauder_poiEndorMarauderStronghold", 1200, -4702.4, 82.0, -2284.3, -179, 0, 0, "angry"},
		{"endor", "marauder_poiEndorMarauderStronghold", 1200, -4715.4, 82.0, -2272.4, -48, 0, AI_STATIONARY, "npc_sitting_table_eating"},
		{"endor", "marauder_poiEndorMarauderStronghold", 900, -4668.1, 82.2, -2276.4, -85, 0},
		{"endor", "marauder_poiEndorMarauderStronghold", 900, -4667.7, 82.3, -2270.5, -85, 0},
		{"endor", "marauder_poiEndorMarauderStronghold", 900, -4623.3, 92.0, -2277.5, -23, 0},
		{"endor", "marauder_poiEndorMarauderStronghold", 900, -4598.4, 98.8, -2268.2, -127, 0},
		{"endor", "marauder_poiEndorMarauderStronghold", 900, -4598.0, 98.9, -2277.2, -69, 0},
	}
}

registerScreenPlay("EndorMarauderStrongholdScreenPlay", true)

function EndorMarauderStrongholdScreenPlay:start()
	if (isZoneEnabled("endor")) then
		self:spawnScreenPMobiles()
	end
end
