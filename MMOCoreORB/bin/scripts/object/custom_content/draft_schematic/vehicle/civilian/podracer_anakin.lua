object_draft_schematic_vehicle_civilian_podracer_anakin = object_draft_schematic_vehicle_civilian_shared_podracer_anakin:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Podracer Anakin",



--TEMPLATE SCHEMATIC POD************************************************************
	craftingToolTab = 16, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 1,


	xpType = "crafting_general",
	xp = 2600,

	assemblySkill = "general_assembly",
	experimentingSkill = "general_experimentation",
	customizationSkill = "vehicle_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n"},
	ingredientTitleNames = {"wiring_harness", "paint", "frame", "body_panel", "veh_autopilot_control_module", "turbine_control"},
	ingredientSlotType = {0, 0, 0, 2, 1, 1},
	resourceTypes = {"copper", "chemical", "steel", "object/tangible/component/vehicle/shared_custom_veh_body_panel.iff", "object/tangible/component/vehicle/shared_custom_veh_autopilot_control_module.iff", "object/tangible/component/vehicle/shared_custom_veh_turbine_control_module.iff"},
	resourceQuantities = {1500, 2500, 400, 10, 1, 2},
	contribution = {100, 100, 100, 100, 100, 100},

--********************************************************************************

	targetTemplate = "object/tangible/deed/vehicle_deed/podracer_anakin_deed.iff",

	additionalTemplates = {}
}

ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_podracer_anakin, "object/draft_schematic/vehicle/civilian/podracer_anakin.iff")
