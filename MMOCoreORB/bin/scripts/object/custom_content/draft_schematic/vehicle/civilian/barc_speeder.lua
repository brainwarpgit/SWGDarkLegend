object_draft_schematic_vehicle_civilian_barc_speeder = object_draft_schematic_vehicle_civilian_shared_barc_speeder:new {

	templateType = DRAFTSCHEMATIC,

	customObjectName = "BARC Speeder",

	craftingToolTab = 16, -- (See DraftSchematicObjectTemplate.h)
	complexity = 25,
	size = 1,
	factoryCrateSize = 0, 
	disableFactoryRun = true,

	xpType = "crafting_general",
	xp = 1800,

	assemblySkill = "general_assembly",
	experimentingSkill = "general_experimentation",
	customizationSkill = "clothing_customization",


	customizationOptions = {2},
	customizationStringNames = {"/private/index_color_1"},
	customizationDefaults = {7},


	ingredientTemplateNames = {"craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n", "craft_vehicle_ingredients_n"},
	ingredientTitleNames = {"vehicle_body", "structural_frame", "body_panel"},
	ingredientSlotType = {0, 0, 1},
	resourceTypes = {"metal_nonferrous", "metal_ferrous", "object/tangible/component/vehicle/shared_custom_veh_body_panel.iff"},
	resourceQuantities = {1125, 3125, 1},
	contribution = {100, 100, 100},

	targetTemplate = "object/tangible/deed/vehicle_deed/barc_speeder_deed.iff",

	additionalTemplates = {
			}
}
ObjectTemplates:addTemplate(object_draft_schematic_vehicle_civilian_barc_speeder, "object/draft_schematic/vehicle/civilian/barc_speeder.iff")
