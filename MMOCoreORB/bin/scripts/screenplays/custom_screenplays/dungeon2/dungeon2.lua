dungeon2 = ScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "dungeon2",

}

registerScreenPlay("dungeon2", true)

function dungeon2:start()
	if (isZoneEnabled("dungeon2")) then
		--self:spawnSceneObjects()
		--self:spawnMobiles()
		spawnSceneObject("dungeon2","object/tangible/travel/ticket_collector/ticket_collector.iff", 84.1, 0.8, 60.4 , 14200971, math.rad(295))
		spawnSceneObject("dungeon2","object/tangible/terminal/terminal_travel.iff", 80.4, 0.9, 53.0, 14200971, math.rad(295))
		spawnSceneObject("dungeon2", "object/creature/npc/theme_park/lambda_shuttle.iff", 91.0, 0.9, 52.1, 14200971, math.rad(265))

	end
end
