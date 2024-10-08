object_draft_schematic_structure_component_structure_turbo_fluidic_drilling_pumping_unit_advanced = object_draft_schematic_structure_component_shared_structure_turbo_fluidic_drilling_pumping_unit_advanced:new {

	templateType = DRAFTSCHEMATIC,

	customObjectName = "Turbo Fluidic Drilling Pump Unit",

	craftingToolTab = 1024, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 6,
	factoryCrateSize = 100,
	factoryCrateType = "object/factory/factory_crate_installation.iff",
   
	xpType = "crafting_structure_general",
	xp = 1380,

	assemblySkill = "structure_assembly",
	experimentingSkill = "structure_experimentation",
	customizationSkill = "structure_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n"},
	ingredientTitleNames = {"bore_head", "well_head_positioning_and_piping", "fluid_hoses", "pump_unit", "sealant_and_shock_absorbing_buffers"},
	ingredientSlotType = {0, 0, 0, 0, 0},
	resourceTypes = {"steel", "metal", "chemical", "metal", "chemical"},
	resourceQuantities = {1200, 1500, 2400, 600, 1200},
	contribution = {100, 100, 100, 100, 100},

	targetTemplate = "object/tangible/component/structure/turbo_fluidic_drilling_pumping_unit.iff",

	additionalTemplates = {}
}

ObjectTemplates:addTemplate(object_draft_schematic_structure_component_structure_turbo_fluidic_drilling_pumping_unit_advanced, "object/draft_schematic/structure/component/structure_turbo_fluidic_drilling_pumping_unit_advanced.iff")
