--Copyright (C) 2007 <SWGEmu>

--This File is part of Core3.

--This program is free software; you can redistribute
--it and/or modify it under the terms of the GNU Lesser
--General Public License as published by the Free Software
--Foundation; either version 2 of the License,
--or (at your option) any later version.

--This program is distributed in the hope that it will be useful,
--but WITHOUT ANY WARRANTY; without even the implied warranty of
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
--See the GNU Lesser General Public License for
--more details.

--You should have received a copy of the GNU Lesser General
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

--Linking Engine3 statically or dynamically with other modules
--is making a combined work based on Engine3.
--Thus, the terms and conditions of the GNU Lesser General Public License
--cover the whole combination.

--In addition, as a special exception, the copyright holders of Engine3
--give you permission to combine Engine3 program with free software
--programs or libraries that are released under the GNU LGPL and with
--code included in the standard release of Core3 under the GNU LGPL
--license (or modified versions of such code, with unchanged license).
--You may copy and distribute such a system following the terms of the
--GNU LGPL for Engine3 and the licenses of the other code concerned,
--provided that you include the source code of that other code when
--and as the GNU LGPL requires distribution of source code.

--Note that people who make modified versions of Engine3 are not obligated
--to grant this special exception for their modified versions;
--it is their choice whether to do so. The GNU Lesser General Public License
--gives permission to release a modified version without this exception;
--this exception also makes it possible to release a modified version
--which carries forward this exception.

--Chance divisor for attribute bonus modifiers
levelChance = 100

--Chance dividend for attribute bonus modifiers
baseChance = 100
yellowChance = 800 --default 1000
exceptionalChance = 1600 --default 100000
legendaryChance = 3200 --default 1000000

--Multiplier values for bonus modifiers
baseModifier = 1 --default 1
yellowModifier = 8 --default 2
exceptionalModifier = 15 --default 8
legendaryModifier = 20 --default 9

--The chance for random skill mods to be on looted weapons/wearables
skillModChance = 1000 -- 1 in 1000 default 1000

-- Dot Distribution chance by DOT type. They must equate to 1.0
poisonDotChance = 0.50
diseaseDotChance = 0.35
fireDotChance = 0.15

-- Dot Distribution chance by HAM type. They must equate to 1.0
healthDotChance = 0.50
actionDotChance = 0.35
mindDotChance = 0.15

-- Value ranges for random dots on looted weapons (chance is set individually on the loot items)
randomDotAttribute = {0, 8} -- See CreatureAttributes.h in src for numbers.
randomDotStrength = {10, 100} -- poison x1.5, disease x0.5
randomDotDuration = {30, 120} -- disease x4.0, fire x1.5
randomDotPotency = {1, 50}
randomDotUses = {250, 4999}

-- Modifier applied to min/max junk values found in loot item lua
junkValueModifier = 2; --default 5

lootableArmorAttachmentStatMods = {
	"aim",
	"alert",
	"anti_shock",
	"berserk",
	"blind_defense",
	"block",
	"burst_run",
	"camouflage",
	"camp",
	"carbine_accuracy",
	"carbine_aim",
	"carbine_hit_while_moving",
	"carbine_speed",
	"center_of_being_duration_onehandmelee",
	"center_of_being_duration_polearm",
	"center_of_being_duration_twohandmelee",
	"center_of_being_duration_unarmed",
	"combat_equillibrium",
	"combat_healing_ability",
	"combat_medic_effectiveness",
	"combat_medicine_assembly",
	"combat_medicine_experimentation",
	"counterattack",
	"creature_harvesting",
	"creature_hit_bonus",
	"creature_knowledge",
	"dizzy_defense",
	"dna_harvesting",
	"dodge",
	"droid_find_chance",
	"droid_find_speed",
	"droid_track_chance",
	"droid_track_speed",
	"droid_tracks",
	"feign_death",
	"foraging",
	"group_burst_run",
	"group_melee_defense",
	"group_ranged_defense",
	"group_slope_move",
	"healing_ability",
	"healing_injury_speed",
	"healing_injury_treatment",
	"healing_range",
	"healing_range_speed",
	"healing_wound_speed",
	"healing_wound_treatment",
	"heavy_acid_beam_accuracy",
	"heavy_acid_beam_speed",
	"heavy_flame_thrower_accuracy",
	"heavy_flame_thrower_speed",
	"heavy_lightning_beam_accuracy",
	"heavy_lightning_beam_speed",
	"heavy_particle_beam_accuracy",
	"heavy_particle_beam_speed",
	"heavy_rifle_acid_accuracy",
	"heavy_rifle_acid_speed",
	"heavy_rifle_lightning_accuracy",
	"heavy_rifle_lightning_speed",
	"heavy_rocket_launcher_accuracy",
	"heavy_rocket_launcher_speed",
	"intimidate",
	"intimidate_defense",
	"keep_creature",
	"knockdown_defense",
	"leadership",
	"mask_scent",
	"medical_foraging",
	"medicine_assembly",
	"medicine_experimentation",
	"meditate",
	"onehandmelee_accuracy",
	"onehandmelee_center_of_being_efficacy",
	"onehandmelee_speed",
	"onehandmelee_toughness",
	"pistol_accuracy",
	"pistol_accuracy_while_standing",
	"pistol_aim",
	"pistol_hit_while_moving",
	"pistol_speed",
	"polearm_accuracy",
	"polearm_center_of_being_efficacy",
	"polearm_speed",
	"polearm_toughness",
	"posture_change_down_defense",
	"posture_change_up_defense",
	"rescue",
	"rifle_accuracy",
	"rifle_aim",
	"rifle_concealment_chance",
	"rifle_hit_while_moving",
	"rifle_speed",
	"slope_move",
	"steadyaim",
	"stored_pets",
	"stun_defense",
	"take_cover",
	"tame_bonus",
	"tame_level",
	"taunt",
	"thrown_accuracy",
	"thrown_speed",
	"trapping",
	"twohandmelee_accuracy",
	"twohandmelee_center_of_being_efficacy",
	"twohandmelee_speed",
	"twohandmelee_toughness",
	"unarmed_accuracy",
	"unarmed_center_of_being_efficacy",
	"unarmed_damage",
	"unarmed_passive_defense",
	"unarmed_speed",
	"unarmed_toughness",
	"volley",
	"warcry"
}

lootableClothingAttachmentStatMods = {
	"armor_assembly",
	"armor_customization",
	"armor_experimentation",
	"armor_repair",
	"bio_engineer_assembly",
	"bio_engineer_experimentation",
	"blind_defense",
	"block",
	"burst_run",
	"clothing_assembly",
	"clothing_customization",
	"clothing_experimentation",
	"clothing_repair",
	"crafting_repair",
	"dizzy_defense",
	"dodge",
	"droid_assembly",
	"droid_customization",
	"droid_experimentation",
	"food_assembly",
	"food_experimentation",
	"force_assembly",
	"force_choke",
	"force_control_dark",
	"force_control_light",
	"force_defense",
	"force_experimentation",
	"force_failure_reduction",
	"force_luck",
	"force_manipulation_dark",
	"force_manipulation_light",
	"force_persuade",
	"force_power_dark",
	"force_power_light",
	"force_repair_bonus",
	"force_vehicle_control",
	"force_vehicle_speed",
	"forceintimidate_accuracy",
	"forceknockdown_accuracy",
	"forcelightning_accuracy",
	"forcethrow_accuracy",
	"forceweaken_accuracy",
	"general_assembly",
	"general_experimentation",
	"healing_dance_mind",
	"healing_dance_shock",
	"healing_dance_wound",
	"healing_music_mind",
	"healing_music_shock",
	"healing_music_wound",
	"intimidate_defense",
	"jedi_force_power_max",
	"jedi_force_power_regen",
	"jedi_saber_assembly",
	"jedi_saber_experimentation",
	"jedi_state_defense",
	"jedi_toughness",
	"knockdown_defense",
	"lightsaber_toughness",
	"luck",
	"melee_accuracy",
	"melee_defense",
	"melee_speed",
	"mindblast_accuracy",
	"onehandlightsaber_accuracy",
	"onehandlightsaber_speed",
	"onehandlightsaber_toughness",
	"polearmlightsaber_accuracy",
	"polearmlightsaber_speed",
	"polearmlightsaber_toughness",
	"ranged_accuracy",
	"ranged_defense",
	"ranged_speed",
	"saber_block",
	"slicing",
	"slope_move",
	"spice_assembly",
	"spice_experimentation",
	"structure_assembly",
	"structure_experimentation",
	"surveying",
	"twohandlightsaber_accuracy",
	"twohandlightsaber_speed",
	"twohandlightsaber_toughness",
	"weapon_assembly",
	"weapon_experimentation",
	"weapon_repair"
}

lootableArmorStatMods = {
	"aim",
	"alert",
	"anti_shock",
	"berserk",
	"blind_defense",
	"block",
	"burst_run",
	"camouflage",
	"camp",
	"combat_equillibrium",
	"combat_healing_ability",
	"combat_medic_effectiveness",
	"combat_medicine_assembly",
	"combat_medicine_experimentation",
	"counterattack",
	"creature_harvesting",
	"creature_hit_bonus",
	"creature_knowledge",
	"dizzy_defense",
	"dna_harvesting",
	"dodge",
	"droid_find_chance",
	"droid_find_speed",
	"droid_track_chance",
	"droid_track_speed",
	"droid_tracks",
	"feign_death",
	"foraging",
	"group_burst_run",
	"group_melee_defense",
	"group_ranged_defense",
	"group_slope_move",
	"healing_ability",
	"healing_injury_speed",
	"healing_injury_treatment",
	"healing_range",
	"healing_range_speed",
	"healing_wound_speed",
	"healing_wound_treatment",
	"intimidate",
	"intimidate_defense",
	"keep_creature",
	"knockdown_defense",
	"leadership",
	"mask_scent",
	"medical_foraging",
	"meditate",
	"rescue",
	"slope_move",
	"steadyaim",
	"stored_pets",
	"stun_defense",
	"take_cover",
	"tame_bonus",
	"tame_level",
	"taunt",
	"trapping",
	"volley",
	"warcry"
}

lootableClothingStatMods = {
	"armor_assembly",
	"armor_customization",
	"armor_experimentation",
	"armor_repair",
	"bio_engineer_assembly",
	"bio_engineer_experimentation",
	"blind_defense",
	"block",
	"burst_run",
	"clothing_assembly",
	"clothing_customization",
	"clothing_experimentation",
	"clothing_repair",
	"crafting_repair",
	"dizzy_defense",
	"dodge",
	"droid_assembly",
	"droid_customization",
	"droid_experimentation",
	"food_assembly",
	"food_experimentation",
	"force_assembly",
	"force_choke",
	"force_control_dark",
	"force_control_light",
	"force_defense",
	"force_experimentation",
	"force_failure_reduction",
	"force_luck",
	"force_manipulation_dark",
	"force_manipulation_light",
	"force_persuade",
	"force_power_dark",
	"force_power_light",
	"force_repair_bonus",
	"force_vehicle_control",
	"force_vehicle_speed",
	"forceintimidate_accuracy",
	"forceknockdown_accuracy",
	"forcelightning_accuracy",
	"forcethrow_accuracy",
	"forceweaken_accuracy",
	"general_assembly",
	"general_experimentation",
	"healing_dance_mind",
	"healing_dance_shock",
	"healing_dance_wound",
	"healing_music_mind",
	"healing_music_shock",
	"healing_music_wound",
	"intimidate_defense",
	"jedi_force_power_max",
	"jedi_force_power_regen",
	"jedi_saber_assembly",
	"jedi_saber_experimentation",
	"jedi_state_defense",
	"jedi_toughness",
	"knockdown_defense",
	"lightsaber_toughness",
	"luck",
	"medicine_assembly",
	"medicine_experimentation",
	"melee_accuracy",
	"melee_defense",
	"melee_speed",
	"mindblast_accuracy",
	"onehandlightsaber_accuracy",
	"onehandlightsaber_speed",
	"onehandlightsaber_toughness",
	"polearmlightsaber_accuracy",
	"polearmlightsaber_speed",
	"polearmlightsaber_toughness",
	"ranged_accuracy",
	"ranged_defense",
	"ranged_speed",
	"saber_block",
	"slicing",
	"slope_move",
	"spice_assembly",
	"spice_experimentation",
	"structure_assembly",
	"structure_experimentation",
	"surveying",
	"tame_bonus",
	"tame_level",
	"twohandlightsaber_accuracy",
	"twohandlightsaber_speed",
	"twohandlightsaber_toughness",
	"weapon_assembly",
	"weapon_experimentation",
	"weapon_repair"
}

lootableOneHandedMeleeStatMods = {
	"alert",
	"berserk",
	"blind_defense",
	"center_of_being_duration_onehandmelee",
	"combat_equillibrium",
	"dizzy_defense",
	"dodge",
	"intimidate",
	"intimidate_defense",
	"knockdown_defense",
	"melee_defense",
	"onehandmelee_accuracy",
	"onehandmelee_center_of_being_efficacy",
	"onehandmelee_speed",
	"onehandmelee_toughness",
	"posture_change_down_defense",
	"ranged_defense",
	"taunt",
	"warcry"
}

lootableTwoHandedMeleeStatMods = {
	"berserk",
	"blind_defense",
	"center_of_being_duration_twohandmelee",
	"counterattack",
	"dizzy_defense",
	"intimidate",
	"intimidate_defense",
	"knockdown_defense",
	"melee_defense",
	"posture_change_down_defense",
	"ranged_defense",
	"stun_defense",
	"taunt",
	"twohandmelee_accuracy",
	"twohandmelee_center_of_being_efficacy",
	"twohandmelee_speed",
	"twohandmelee_toughness",
	"warcry"
}

lootableUnarmedStatMods = {
	"berserk",
	"blind_defense",
	"center_of_being_duration_unarmed",
	"combat_equillibrium",
	"dizzy_defense",
	"intimidate",
	"knockdown_defense",
	"meditate",
	"melee_defense",
	"posture_change_down_defense",
	"ranged_defense",
	"stun_defense",
	"taunt",
	"unarmed_accuracy",
	"unarmed_center_of_being_efficacy",
	"unarmed_damage",
	"unarmed_passive_defense",
	"unarmed_speed",
	"unarmed_toughness",
	"warcry"
}

lootablePistolStatMods = {
	"aim",
	"alert",
	"blind_defense",
	"dizzy_defense",
	"dodge",
	"knockdown_defense",
	"melee_defense",
	"pistol_accuracy",
	"pistol_accuracy_while_standing",
	"pistol_aim",
	"pistol_hit_while_moving",
	"pistol_speed",
	"posture_change_down_defense",
	"ranged_defense",
	"stun_defense"
}

lootableRifleStatMods = {
	"aim",
	"alert",
	"blind_defense",
	"block",
	"dizzy_defense",
	"melee_defense",
	"posture_change_up_defense",
	"ranged_defense",
	"rifle_accuracy",
	"rifle_aim",
	"rifle_concealment_chance",
	"rifle_hit_while_moving",
	"rifle_speed",
	"stun_defense",
	"take_cover"
}

lootableCarbineStatMods = {
	"aim",
	"alert",
	"carbine_accuracy",
	"carbine_aim",
	"carbine_hit_while_moving",
	"carbine_speed",
	"counterattack",
	"intimidate_defense",
	"knockdown_defense",
	"ranged_defense"
}

lootablePolearmStatMods = {
	"berserk",
	"blind_defense",
	"block",
	"center_of_being_duration_polearm",
	"dizzy_defense",
	"intimidate",
	"knockdown_defense",
	"melee_defense",
	"polearm_accuracy",
	"polearm_center_of_being_efficacy",
	"polearm_speed",
	"polearm_toughness",
	"posture_change_down_defense",
	"ranged_defense",
	"stun_defense",
	"taunt",
	"warcry"
}

lootableHeavyWeaponStatMods = {
	"aim",
	"alert",
	"berserk",
	"heavy_acid_beam_accuracy",
	"heavy_acid_beam_speed",
	"heavy_flame_thrower_accuracy",
	"heavy_flame_thrower_speed",
	"heavy_lightning_beam_accuracy",
	"heavy_lightning_beam_speed",
	"heavy_particle_beam_accuracy",
	"heavy_particle_beam_speed",
	"heavy_rifle_acid_accuracy",
	"heavy_rifle_acid_speed",
	"heavy_rifle_lightning_accuracy",
	"heavy_rifle_lightning_speed",
	"heavy_rocket_launcher_accuracy",
	"heavy_rocket_launcher_speed",
	"intimidate",
	"knockdown_defense",
	"melee_defense",
	"ranged_defense",
	"taunt",
	"thrown_accuracy",
	"thrown_speed",
	"warcry"
}

-- Values used to generate lightsaber crystal stats
jediCrystalStats = {
	lightsaber_module_force_crystal = {
		minDamage = 20,
		maxDamage = 50,
		minHitpoints = 900,
		maxHitpoints = 1400,
		minHealthSac = -6,
		maxHealthSac = -9,
		minActionSac = -6,
		maxActionSac = -9,
		minMindSac = -6,
		maxMindSac = -9,
		minAttackSpeed = -0.3,
		maxAttackSpeed = -0.6,
		minForceCost = -5.0,
		maxForceCost = -9.9,
		minWoundChance = 2,
		maxWoundChance = 4,
	},
	lightsaber_module_krayt_dragon_pearl = {
		minDamage = 20,
		maxDamage = 50,
		minHitpoints = 900,
		maxHitpoints = 1400,
		minHealthSac = -6,
		maxHealthSac = -9,
		minActionSac = -6,
		maxActionSac = -9,
		minMindSac = -6,
		maxMindSac = -9,
		minAttackSpeed = -0.3,
		maxAttackSpeed = -0.6,
		minForceCost = -5.0,
		maxForceCost = -9.9,
		minWoundChance = 2,
		maxWoundChance = 4,
	}
}
