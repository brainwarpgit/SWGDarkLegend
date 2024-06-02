--Should all created players start with God Mode? 1 = yes, 0 = no
freeGodMode = 0;
--How many cash credits new characters start with after creating a character (changed during test phase, normal value is 100)
startingCash = 100
--startingCash = 100000
--How many bank credits new characters start with after creating a character (changed during test phase, normal value is 1000)
startingBank = 1000
--startingBank = 100000
--How many skill points a new characters start with
skillPoints = 250

professions = {
	"combat_brawler",
	"combat_marksman",
	"crafting_artisan",
	"jedi",
	"outdoors_scout",
	"science_medic",
	"social_entertainer"
}

marojMelon = "object/tangible/food/foraged/foraged_fruit_s1.iff"

professionSpecificItems = {
	combat_brawler = { },
	combat_marksman = { },
	crafting_artisan = { },
	jedi = { },
	outdoors_scout = { },
	science_medic = { },
	social_entertainer = { }
}

commonStartingItems = { marojMelon }
