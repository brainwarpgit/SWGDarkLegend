NabooAmidalasBeachScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "NabooAmidalasBeachScreenPlay",
	ScreenPSpawns = {
		--Outside
		{"naboo", "informant_npc_lvl_2", 0,-5548,-150,-13,225,0},
		{"naboo", "informant_npc_lvl_2", 0,-5476,-150,-76,270,0},
		{"naboo", "junk_sheani", 0, -5496.62, -150, -71.39, -4, 0},
	}
}

registerScreenPlay("NabooAmidalasBeachScreenPlay", true)

function NabooAmidalasBeachScreenPlay:start()
	if (isZoneEnabled("naboo")) then
		self:spawnScreenPMobiles()
	end
end

