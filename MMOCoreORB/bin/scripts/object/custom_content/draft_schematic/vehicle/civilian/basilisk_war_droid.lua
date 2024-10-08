object_draft_schematic_vehicle_civilian_basilisk_war_droid = object_draft_schematic_vehicle_civilian_shared_basilisk_war_droid:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Basilisk War Droid",


--TEMPLATE SCHEMATIC Small WITH COLOR************************************************************
	craftingToolTab = 16, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 1,


	xpType = "crafting_general",
	xp = 1800,

	assemblySkill = "general_assembly",
	experimentingSkill = "general_experimentation",
	customizationSkill = "vehicle_customization",

	customizationOptions = {2},
	customizationStringNames = {"/private/index_color_1"},
	customizationDefaults = {41},

	ingredientTemplateNames = {"craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n"},
	ingredientTitleNames = {"wiring_harness", "paint", "frame", "armor_plating", "power_plant", "vehicle_reactor_unit"},
	ingredientSlotType = {0, 0, 0, 2, 1, 1},
	resourceTypes = {"copper", "chemical", "steel", "object/tangible/component/vehicle/shared_armor_plating_mk3.iff", "object/tangible/component/vehicle/shared_veh_power_plant_mk3.iff", "object/tangible/component/vehicle/shared_reactor_unit.iff"},
	resourceQuantities = {100, 200, 200, 10, 1, 1},
	contribution = {100, 100, 100, 100, 100, 100},

--********************************************************************************


	targetTemplate = "object/tangible/deed/vehicle_deed/basilisk_war_droid.iff",

	additionalTemplates = {}
}
ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_basilisk_war_droid, "object/draft_schematic/vehicle/civilian/basilisk_war_droid.iff")
