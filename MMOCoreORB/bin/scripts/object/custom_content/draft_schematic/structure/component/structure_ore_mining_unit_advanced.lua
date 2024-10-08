object_draft_schematic_structure_component_structure_ore_mining_unit_advanced = object_draft_schematic_structure_component_shared_structure_ore_mining_unit_advanced:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Ore Mining Unit",

	craftingToolTab = 1024, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 1,
	factoryCrateSize = 100,
	factoryCrateType = "object/factory/factory_crate_installation.iff",
   
	xpType = "crafting_structure_general",
	xp = 1200,

	assemblySkill = "structure_assembly",
	experimentingSkill = "structure_experimentation",
	customizationSkill = "structure_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n"},
	ingredientTitleNames = {"bore_head", "bore_positioning_arm", "ore_transport_auger_and_conveyors", "load_bearing_joints_and_fittings", "charge_and_thermal_regulation_medium"},
	ingredientSlotType = {0, 0, 0, 0, 0},
	resourceTypes = {"steel", "steel", "metal", "steel", "gas_inert"},
	resourceQuantities = {1000, 1500, 1500, 1200, 750},
	contribution = {100, 100, 100, 100, 100},

	targetTemplate = "object/tangible/component/structure/ore_mining_unit.iff",

	additionalTemplates = {}
}

ObjectTemplates:addTemplate(object_draft_schematic_structure_component_structure_ore_mining_unit_advanced, "object/draft_schematic/structure/component/structure_ore_mining_unit_advanced.iff")
