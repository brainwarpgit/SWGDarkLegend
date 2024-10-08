object_draft_schematic_structure_wod_sm_hut = object_draft_schematic_structure_shared_wod_sm_hut:new {
	templateType = DRAFTSCHEMATIC,

	customObjectName = "Deed for: Small Hut",

	craftingToolTab = 1024, -- (See DraftSchematicObjectTemplate.h)
	complexity = 13,
	size = 10,
	factoryCrateSize = 1,
	factoryCrateType = "object/factory/factory_crate_installation.iff",
   
	xpType = "crafting_structure_general",
	xp = 2400,

	assemblySkill = "structure_assembly",
	experimentingSkill = "structure_experimentation",
	customizationSkill = "structure_customization",

	customizationOptions = {},
	customizationStringNames = {},
	customizationDefaults = {},

	ingredientTemplateNames = {"craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n", "craft_structure_ingredients_n"},
	ingredientTitleNames = {"tent_frame", "insulation_and_covering", "foundation", "fiberplast_tent_covering", "reinforced_secondary_covering"},
	ingredientSlotType = {0, 0, 0, 2, 1},
	resourceTypes = {"metal", "hide", "ore", "object/tangible/component/clothing/shared_fiberplast_panel.iff", "object/tangible/component/clothing/shared_reinforced_fiber_panels.iff"},
	resourceQuantities = {400, 600, 200, 20, 4},
	contribution = {100, 100, 100, 100, 100},

	targetTemplate = "object/tangible/deed/player_house_deed/sm_hut_deed.iff",

	additionalTemplates = {	}
}

ObjectTemplates:addTemplate(object_draft_schematic_structure_wod_sm_hut, "object/draft_schematic/structure/wod_sm_hut.iff")
