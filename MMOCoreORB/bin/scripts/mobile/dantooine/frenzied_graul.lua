frenzied_graul = Creature:new {
	objectName = "@mob/creature_names:frenzied_graul",
	socialGroup = "graul",
	faction = "",
	mobType = MOB_CARNIVORE,
	level = 56,
	chanceHit = 0.5,
	damageMin = 445,
	damageMax = 600,
	baseXp = 5464,
	baseHAM = 9500,
	baseHAMmax = 11700,
	armor = 1,
	resists = {165,135,190,190,190,-1,5,5,-1},
	meatType = "meat_carnivore",
	meatAmount = 1000,
	hideType = "hide_leathery",
	hideAmount = 950,
	boneType = "bone_mammal",
	boneAmount = 855,
	milk = 0,
	tamingChance = 0.01,
	ferocity = 15,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/frenzied_graul.iff"},
	hues = { 24, 25, 26, 27, 28, 29, 30, 31 },
	controlDeviceTemplate = "object/intangible/pet/graul_hue.iff",
	scale = 1.2,
	lootGroups = {},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "unarmed",
	secondaryWeapon = "none",
	conversationTemplate = "",
	
	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = { {"creatureareableeding",""}, {"stunattack",""} },
	secondaryAttacks = { }
}

CreatureTemplates:addCreatureTemplate(frenzied_graul, "frenzied_graul")
