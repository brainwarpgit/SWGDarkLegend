--My first code for SWGEmu!
--Coded By: NickWill86

EndorEwokTreeVillage01ScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "EndorEwokTreeVillage01ScreenPlay",
	planet = "endor",

	ScreenPSpawns = {
		--Tree # 1
		--On the ground
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,66,9,50,40,0, AI_STATIONARY},--FurthestEwokHutFromStairs(4/4)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,71.5,9,46.6,54,0, AI_STATIONARY},--EwokHutFromStairs(3/4)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,77,9,37,45,0, AI_STATIONARY},--GuardNearTikiTourch(2/4)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,78,9,40,135,0, AI_STATIONARY},--GuardNearTikiTourch(1/4)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,61,9,32,-135,0, AI_STATIONARY},--GuardingStairs
		--First Floor
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,66,19,48,135,0, AI_STATIONARY},--Guard
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,62,19,52,135,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,59,19,46,-30,0, AI_STATIONARY},--Hut
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,51,19,40,45,0, AI_STATIONARY},--OverLook#2
		--Second Floor(Top Floor)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,69,29,41,135,0, AI_STATIONARY},--Two Guards
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,70,29,42,135,0, AI_STATIONARY},--Two Guards
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,62,29,52,135,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,59,29,45,-45,0, AI_STATIONARY},--Hut#1
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,52,29,40,45,0, AI_STATIONARY},--OverLook#2
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,59,29,35,-135,0, AI_STATIONARY},--Hut#2

		--Tree # 2
		--On the ground
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,86.6,9,63.1,170,0, AI_STATIONARY},--FurthestEwokHutFromStairs(1/1)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,75.7,9,63.5,175,0, AI_STATIONARY},--GuardNearTikiTourch(1/4)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,83.3,9.3,79.8,48,0, AI_STATIONARY},--GuardingStairs
		--First Floor
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,80.5,19,66.6,-148,0, AI_STATIONARY},--Guard
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,86.4,19.1,67.1,144,0, AI_STATIONARY},--Hut
		--Second Floor
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,71,29.3,71.7,48,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,78.7,29.1,67,-149,0, AI_STATIONARY},--Hut
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,82.6,29.3,60.9,-4,0, AI_STATIONARY},--OverLook#2
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,86.1,29.1,77.5,38,0, AI_STATIONARY},--Hut#2

		--Tree # 3
		--On the ground
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,72.8,9,21.7,27,0, AI_STATIONARY},--GuardNearTikiTourch(3/3)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,75.6,9,24.5,-117,0, AI_STATIONARY},--GuardNearTikiTourch(2/3)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,93.4,9,19.1,-16,0, AI_STATIONARY},--GuardNearTikiTourch(1/3)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,81.5,9.3,3.1,-146,0, AI_STATIONARY},--GuardingStairs
		--First Floor
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,83.2,19,16.6,33,0, AI_STATIONARY},--Guard
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,77.7,19.1,13.9,-56,0, AI_STATIONARY},--Hut
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,71.2,19.3,10.4,62,0, AI_STATIONARY},--OverLook#1
		--Second Floor
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,93.8,29.3,10.9,-125,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,82.4,29.3,21.9,171,0, AI_STATIONARY},--OverLook#2
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,70.9,29.3,10.3,61,0, AI_STATIONARY},--OverLook#2
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,77.8,29,7.2,-124,0, AI_STATIONARY},--Hut

		--Tree # 4
		--On the ground
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,96.2,9,61.9,157,0, AI_STATIONARY},--GuardNearFire(2/2)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,98.8,9,59.3,-94,0, AI_STATIONARY},--GuardNearFire(1/2)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,112.7,9.3,71.4,159,0, AI_STATIONARY},--GuardingStairs
		--First Floor
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,99.2,19,73.8,-61,0, AI_STATIONARY},--Guard
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,101.1,19.1,67.4,-146,0, AI_STATIONARY},--Hut
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,105.3,19.3,61.2,-37,0, AI_STATIONARY},--OverLook#1
		--Second Floor
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,104.2,29.3,83.3,141,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,101.3,29.1,77.7,-36,0, AI_STATIONARY},--Hut#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,110.3,29,68.8,116,0, AI_STATIONARY},--Hut#2

		--Tree # 5
		--On the ground
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,95.5,9,36.7,-118,0, AI_STATIONARY},--FurthestEwokHutFromStairs(1/1)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,94.6,9,48.3,-9,0, AI_STATIONARY},--GuardNearFire(2/2)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,97.3,9,51,-78,0, AI_STATIONARY},--GuardNearFire(1/2)
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,112.5,9.3,39.5,126,0, AI_STATIONARY},--GuardingStairs
		--First Floor
		{"endor", "panshee_warrior_poiEndorEwokTreeVillage1", 300,93.7,19.3,40.1,50,0, AI_STATIONARY},--Guard
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,100,19.0,36.7,-124,0, AI_STATIONARY},--Hut
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,105.1,19.3,29.1,-35,0, AI_STATIONARY},--OverLook#1
		--Second Floor
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,104.4,29,46.6,7,0, AI_STATIONARY},--OverPassGuard#1
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,99,29,40.6,-88,0, AI_STATIONARY},--OverPassGuard#2
		{"endor", "panshee_tribesman_poiEndorEwokTreeVillage1", 300,105.5,29.3,29.1,-36,0, AI_STATIONARY},--OverLook#1
		{"endor", "panshee_shaman_poiEndorEwokTreeVillage1", 300,110.1,29.1,37.2,126,0, AI_STATIONARY},--Hut#1
	}
}

registerScreenPlay("EndorEwokTreeVillage01ScreenPlay", true)

function EndorEwokTreeVillage01ScreenPlay:start()
	if (isZoneEnabled(self.planet)) then
		self:spawnScreenPMobiles()
	end
end

