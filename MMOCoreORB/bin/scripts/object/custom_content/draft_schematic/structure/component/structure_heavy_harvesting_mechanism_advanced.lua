object_draft_schematic_structure_component_structure_heavy_harvesting_mechanism_advanced = object_draft_schematic_structure_component_shared_structure_heavy_harvesting_mechanism_advanced:new {

	templateType = DRAFTSCHEMATIC,

	customObjectName = "Advanced Heavy Harvesting Mechanism",

	craftingToolTab = 1024, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 8,
	factoryCrateSize = 100,
	factoryCrateType = "object/factory/factory_crate_installation.iff",
   
	xpType = "crafting_structure_general",
	xp = 1340,

	assemblySkill = "structure_assembly",
	experimentingSkill = "structure_experimentation",
	customizationSkill = "structure_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n"},
	ingredientTitleNames = {"manipulator_unit", "bio_controller", "fluid_hoses", "pump_unit", "sealant_and_shock_absorbing_buffers"},
	ingredientSlotType = {0, 0, 0, 0, 0},
	resourceTypes = {"steel", "steel", "chemical", "metal", "chemical"},
	resourceQuantities = {1000, 1500, 2500, 500, 1200},
	contribution = {100, 100, 100, 100, 100},

	targetTemplate = "object/tangible/component/structure/heavy_harvesting_mechanism.iff",

	additionalTemplates = {}
}

ObjectTemplates:addTemplate(object_draft_schematic_structure_component_structure_heavy_harvesting_mechanism_advanced, "object/draft_schematic/structure/component/structure_heavy_harvesting_mechanism_advanced.iff")
