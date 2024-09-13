trainer_dark_sentinel = Creature:new {
	objectName = "@mob/creature_names:dark_jedi_sentinel",
	customName = "Sith Council Member",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	mobType = MOB_NPC,
	socialGroup = "",
	faction = "",
	level = 1,
	chanceHit = 500,
	damageMin = 7500,
	damageMax = 10000,
	baseXp = 1,
	baseHAM = 2000000,
	baseHAMmax = 25000000,
	armor = 3,
	resists = {95,95,95,95,95,95,95,95,95},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = KILLER + PACK + HERD,
	optionsBitmask = CONVERSABLE,
	diet = HERBIVORE,
	--customAiMap = "enclaveSentinel",

	templates = { "dark_jedi" },
	lootGroups = {},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "dark_jedi_weapons_gen4",
	secondaryWeapon = "dark_jedi_weapons_ranged",
	conversationTemplate = "darkfrsTrainerConvoTemplate",

	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = merge(lightsabermaster,forcepowermaster),
	secondaryAttacks = forcepowermaster
}

CreatureTemplates:addCreatureTemplate(trainer_dark_sentinel, "trainer_dark_sentinel")
