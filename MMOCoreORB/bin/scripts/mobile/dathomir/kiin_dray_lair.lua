kiin_dray_lair = Creature:new {
	objectName = "@mob/creature_names:gaping_spider_recluse_giant_kiin_dray",
	socialGroup = "spider_nightsister",
	faction = "spider_nightsister",
	mobType = MOB_CARNIVORE,
	level = 450,
	chanceHit = 16.96,
	damageMin = 2963,
	damageMax = 4891,
	baseXp = 11953,
	baseHAM = 146370,
	baseHAMmax = 178500,
	armor = 3,
	resists = {80,80,80,80,80,80,80,80,40},
	meatType = "meat_insect",
	meatAmount = 11,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 8,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER + STALKER,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/gaping_spider_recluse_giant_kiin_dray.iff"},
	scale = 4.0,
	lootGroups = {},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "object/weapon/ranged/creature/creature_spit_spray_red.iff",
	secondaryWeapon = "unarmed",
	conversationTemplate = "",

	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = { {"creatureareapoison",""}, {"strongpoison",""} },
	secondaryAttacks = { {"creatureareapoison",""}, {"strongpoison",""} }
}

CreatureTemplates:addCreatureTemplate(kiin_dray_lair, "kiin_dray_lair")
