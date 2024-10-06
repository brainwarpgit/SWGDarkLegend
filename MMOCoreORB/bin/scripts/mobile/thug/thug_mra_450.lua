 thug_mra_450 = Creature:new {
	objectName = "@mob/creature_names:thug",
	randomNameType = NAME_GENERIC,
	randomNameTag = true,
	mobType = MOB_NPC,
	level = 1,
	chanceHit = .1,
	damageMin = 8,
	damageMax = 12,
	baseXp = 87,
	baseHAM = 1200,
	baseHAMmax = 1450,
	armor = 2,
	resists = {.2,.2,.2,.2,.2,.2,.2,.2,.1},
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
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,
	missionRandomAttack = 450,

	templates = {"thug_mra"},
	lootGroups = {
		{
			groups = {
				{group = "thug_tier_1", chance = 10000000}
			}
		}
	},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "thug_mra_ranged_weapons",
	secondaryWeapon = "thug_mra_melee_weapons",
	conversationTemplate = "",
	reactionStf = "@npc_reaction/slang",
	
	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = merge(marksmanmaster,riflemanmaster,pistoleermaster,carbineermaster),
	secondaryAttacks = merge(brawlermaster,tkamaster,pikemanmaster,fencermaster,swordsmanmaster),
}

CreatureTemplates:addCreatureTemplate(thug_mra_450, "thug_mra_450")
