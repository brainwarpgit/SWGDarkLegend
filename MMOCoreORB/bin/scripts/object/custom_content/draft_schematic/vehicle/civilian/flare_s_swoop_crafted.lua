object_draft_schematic_vehicle_civilian_flare_s_swoop_crafted = object_draft_schematic_vehicle_civilian_shared_flare_s_swoop_crafted:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Flare S Swoop",


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
	ingredientTitleNames = {"wiring_harness", "paint", "frame", "body_panel", "engine_casing", "turbine_control"},
	ingredientSlotType = {0, 0, 0, 2, 1, 1},
	resourceTypes = {"copper", "chemical", "steel", "object/tangible/component/vehicle/shared_custom_veh_body_panel.iff", "object/tangible/component/vehicle/shared_custom_veh_engine_casing.iff", "object/tangible/component/vehicle/shared_custom_veh_turbine_control_module.iff"},
	resourceQuantities = {100, 200, 200, 10, 1, 1},
	contribution = {100, 100, 100, 100, 100, 100},

--********************************************************************************


	targetTemplate = "object/tangible/deed/vehicle_deed/flare_s_swoop_crafted.iff",

	additionalTemplates = {}
}
ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_flare_s_swoop_crafted, "object/draft_schematic/vehicle/civilian/flare_s_swoop_crafted.iff")
