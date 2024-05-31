--Global Variables added by SWGDarkLegend

--Auction
auctionMaxBazaarPrice = 10000000 --default 20000
auctionMaxSales = 1000 --default 25
auctionMaxSalesFee = 0 --default 20 in credits
auctionVendorExpirePeriod = 60 --default 30 in days
auctionCommodityExpirePeriod = 30 --default 7 in days

--Crafting
craftingFactoryCrateMaxSize = 1000 --default 100
craftingFactoryRunTimeMultiplier = 0 --default 8
craftingToolCraftTimeMultiplier = 0 --default 2

--Creature
creatureMaxLevel = 450 --default 336 Pulled from mobiles
creatureBaseScaleMultiplier = 1 --default 1
creatureBaseXpMultiplier = 1 --default 1
creatureBaseMeatAmountMultiplier = 1 --default 1
creatureBaseHideAmountMultiplier = 1 --default 1
creatureBaseBoneAmountMultiplier = 1 --default 1
creatureBaseMilkMultiplier = 1 --default 1
creatureBaseLevelMultiplier = 1 --default 1
creatureBaseChanceHitMultiplier = 0.1 --default 1
creatureBaseFerocityMultiplier = 0.1 --default 1
creatureBaseDamageMaxMultiplier = 0.1 --default 1
creatureBaseDamageMinMultiplier = 0.1 --default 1
creatureBaseHAMMultiplier = 0.1 --default 1
creatureBaseHAMMaxMultiplier = 0.1 --default 1
creatureBaseResistsMultipliers = 0.1 --default 1
creatureKineticMaxResists = 80.0 --default 100.0
creatureEnergyMaxResists = 80.0 --default 100.0
creatureBlastMaxResists = 80.0 --default 100.0
creatureHeatMaxResists = 80.0 --default 100.0
creatureColdMaxResists = 80.0 --default 100.0
creatureElectricityMaxResists = 80.0 --default 100.0
creatureAcidMaxResists = 80.0--default 100.0
creatureStunMaxResists = 40.0 --default 100.0
creatureLightsaberMaxResists = 0.0 --default 100.0

--Faction
factionMaxRank = 21 --default 15  max 21

--Harvest
harvestDistance = 64 --default 10 (Distance does not affect menu options.   They are still greyed out past the default..  must use /harvest)
harvestAreaEnabled = true --default false
harvestAreaCommandOnlyEnabled = true --default false
harvestMultiplier = 2 --default 1
harvestMilkTime = 5 --default 10 in seconds
harvestDNASampleDistance = 64 --default 16  

--Loot
lootDistance = 64 --default 16 (Distance does not affect menu options.   They are still greyed out past the default..  must use /loot all)
lootAreaEnabled = true --default false
lootCreditMultiplier = 2 --default 1

--Mission
missionBountyExpirationTime = 48 --default 48 in hours
missionExpirationTime = 48 --default 48 in hours
missionMaxCount = 5 --default 2
missionListCount = 25 --default 6
missionNameAndLevelEnabled = true --default false destroy terminals?
missionDirectionSelectionEnabled = true --default false all mission terminals?
missionLevelSelectionEnabled = true --default false destroy / faction terminals
missionRewardMultiplier = 2 --default 1

--Pet
petCallTime = 0 --default 15 in seconds
petGrowthCycleTime = 0 --default 720 in minutes
petGrowthStagesToGrown = 10 --default 10
petStoreInCombatEnabled = true --default false

--Player
playerSamplingMultiplier = 10 --default 1
playerSamplingTime = 10 --default 25 in seconds
playerSamplingMiniGameEnabled = false --default true
playerSamplingRadioactiveWarningEnabled = false --default true
playerMaxLots = 20 --default 10
playerGlobalSafetyDepositEnabled = true --default false
playerShuttleBoardingDistance = 300 --default 25
playerStatMigrationLocation = "tutorial" --default "tutorial" -- isn't used when statMigrateAnyLocationEnabled is true
playerStatMigrationSalonOnlyEnabled = false --default false
playerStatMigrationAnyLocationEnabled = true --default false
playerStatMigrationClearBuffsEnabled = true --default false
playerWoundsonDeath = 500 --default 100
playerBackpackWipeEnabled = true --default false
playerChangeWearableColorsEnabled = true --default false

--Player Creation
playerCreationNewCreationTime = 5 --default 60 in minutes
playerCreationAllLanguagesEnabled = true --default false

--Resources
resourcesAddNameEnabled = true --default false
resourcesMinimumQuality = 750 --default 0
resourcesMaximumQuality = 1000 --default 1000
resourcesContainerSize = 10000000 --default 100000

--Skills
skillsInstantMasterPoliticianEnabled = true --default false
skillsInstantMasterMerchantEnabled = true --default false

--Structure
structureMaxItemsPerLot = 500 --default 100
structureMaxCivicBuildingItems = 1000 --default 250
structureMaxZeroLotBuildingItems = 1000 --default 400
structureMaxItemsPerStructure = 2500 --default 400
structureMaxItemsEnabled = false --default true
structureShowHouseMaxItemsEnabled = true --default false

--Vehicle
vehicleBaseDecayCycle = 600 -- default 600 in seconds
vehicleBaseDecayRate = 15 --default 15
vehicleInitialDecayEnabled = false --default true
vehicleCallTime = 0 --default 15 in seconds
vehicleStoreInCombatEnabled = true --default false
