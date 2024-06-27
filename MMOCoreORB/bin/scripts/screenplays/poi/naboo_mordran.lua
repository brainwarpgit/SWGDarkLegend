NabooMordranScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "NabooMordranScreenPlay",
	ScreenPSpawns = {
		--mordran respawns between 15-20 minutes
		{"naboo", "mordran_poiNabooMordran", 1200, -1969, 6.4, -5295, 45, 0},
		{"naboo", "outcast_gungan_poiNabooMordran", 300, -1967, 6.4, -5296, 45, 0},
		{"naboo", "outcast_gungan_poiNabooMordran", 300, -1964, 6.4, -5292, 45, 0},
		{"naboo", "outcast_gungan_poiNabooMordran", 300, -1966, 6.4, -5301, 45, 0},
		{"naboo", "gungan_reject_poiNabooMordran", 360, -1969, 6.4, -5291, 45, 0},
		{"naboo", "gungan_reject_poiNabooMordran", 360, -1969, 6.4, -5297, 45, 0},
		{"naboo", "exiled_gungan_poiNabooMordran", 360, -1966, 6.4, -5295, 45, 0},
		{"naboo", "exiled_gungan_poiNabooMordran", 360, -1963, 6.4, -5299, 45, 0},
	}
}

registerScreenPlay("NabooMordranScreenPlay", true)

function NabooMordranScreenPlay:start()
	if (isZoneEnabled("naboo")) then
		self:spawnScreenPMobiles()
	end
end

