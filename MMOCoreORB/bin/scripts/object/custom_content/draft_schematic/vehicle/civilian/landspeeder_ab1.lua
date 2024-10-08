object_draft_schematic_vehicle_civilian_landspeeder_ab1 = object_draft_schematic_vehicle_civilian_shared_landspeeder_ab1:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "AB-1 Landspeeder",


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
	resourceTypes = {"copper", "chemical", "steel", "object/tangible/component/vehicle/shared_armor_plating_mk1.iff", "object/tangible/component/vehicle/shared_veh_power_plant_mk1.iff", "object/tangible/component/vehicle/shared_reactor_unit.iff"},
	resourceQuantities = {100, 200, 200, 10, 1, 1},
	contribution = {100, 100, 100, 100, 100, 100},

--********************************************************************************


	targetTemplate = "object/tangible/deed/vehicle_deed/landspeeder_ab1_deed.iff",

	additionalTemplates = {}
}
ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_landspeeder_ab1, "object/draft_schematic/vehicle/civilian/landspeeder_ab1.iff")
