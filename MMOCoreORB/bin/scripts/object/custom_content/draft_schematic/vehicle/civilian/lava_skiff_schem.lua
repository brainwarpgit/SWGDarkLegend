object_draft_schematic_vehicle_civilian_lava_skiff_schem = object_draft_schematic_vehicle_civilian_shared_lava_skiff_schem:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Lava Skiff",

--TEMPLATE SCHEMATIC MEDIUM 1 No Color ************************************************************
	craftingToolTab = 16, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 1,


	xpType = "crafting_general",
	xp = 1800,

	assemblySkill = "general_assembly",
	experimentingSkill = "general_experimentation",
	customizationSkill = "vehicle_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n"},
	ingredientTitleNames = {"vehicle_body", "frame", "shielding", "body_panel", "turbine_control", "veh_gravity_pump"},
	ingredientSlotType = {0, 0, 0, 2, 1, 1},
	resourceTypes = {"metal", "metal", "steel_neutronium", "object/tangible/component/vehicle/shared_custom_veh_body_panel.iff", "object/tangible/component/vehicle/shared_custom_veh_turbine_control_module.iff", "object/tangible/component/vehicle/shared_custom_veh_gravity_pump.iff"},
	resourceQuantities = {1250, 2250, 400, 6, 2, 1},
	contribution = {100, 100, 100, 100, 100, 100},


--********************************************************************************
	targetTemplate = "object/tangible/deed/vehicle_deed/landspeeder_lava_skiff_deed.iff",

	additionalTemplates = {}
}

ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_lava_skiff_schem, "object/draft_schematic/vehicle/civilian/lava_skiff_schem.iff")
