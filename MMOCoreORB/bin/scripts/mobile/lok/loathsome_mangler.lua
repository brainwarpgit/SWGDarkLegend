loathsome_mangler = Creature:new {
	objectName = "@mob/creature_names:gurk_loathsome_mangler",
	socialGroup = "gurk",
	faction = "",
	mobType = MOB_HERBIVORE,
	level = 33,
	chanceHit = 0.4,
	damageMin = 335,
	damageMax = 380,
	baseXp = 3370,
	baseHAM = 8200,
	baseHAMmax = 10000,
	armor = 0,
	resists = {120,120,-1,0,0,0,0,0,-1},
	meatType = "meat_herbivore",
	meatAmount = 350,
	hideType = "hide_leathery",
	hideAmount = 276,
	boneType = "bone_mammal",
	boneAmount = 301,
	milk = 0,
	tamingChance = 0.05,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/gurk_hue.iff"},
	controlDeviceTemplate = "object/intangible/pet/gurk_hue.iff",
	scale = 1.2,
	lootGroups = {},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "unarmed",
	secondaryWeapon = "none",
	conversationTemplate = "",
	
	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = { {"dizzyattack",""}, {"intimidationattack",""} },
	secondaryAttacks = { }
}

CreatureTemplates:addCreatureTemplate(loathsome_mangler, "loathsome_mangler")
