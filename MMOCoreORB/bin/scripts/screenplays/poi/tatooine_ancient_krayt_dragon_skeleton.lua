AncientKraytSkeletonScreenPlay = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "AncientKraytSkeletonScreenPlay",
	ScreenPSpawns = {
		{"tatooine", "krayt_dragon_grand_poiTatooineAncientKraytDragonSkeleton", 1800, -4555.0, 49.3, -4459.2, -116, 0},
		{"tatooine", "krayt_dragon_ancient_poiTatooineAncientKraytDragonSkeleton", 1800, -4713.1, 46.5, -4288.3, 50, 0},
		{"tatooine", "giant_canyon_krayt_dragon_poiTatooineAncientKraytDragonSkeleton", 1800, -4669.8, 30.1, -4477.7, 5, 0},
		{"tatooine", "canyon_krayt_dragon_poiTatooineAncientKraytDragonSkeleton", 1800, -4528.8, 28.3, -4302.4, 144, 0},
		{"tatooine", "juvenile_canyon_krayt_dragon_poiTatooineAncientKraytDragonSkeleton", 1200, -4521.3, 27.2, -4298.2, 144, 0},
		{"tatooine", "krayt_dragon_adolescent_poiTatooineAncientKraytDragonSkeleton", 1800, -4747.2, 32.5, -4424.8, -91, 0},
	}
}

registerScreenPlay("AncientKraytSkeletonScreenPlay", true)

function AncientKraytSkeletonScreenPlay:start()
	if (isZoneEnabled("tatooine")) then
		self:spawnScreenPMobiles()
	end
end

