--Admin
adminTag = "SWGDL-Admin"

--Auction
auctionMaxBazaarPrice = 10000000 --default 20000
auctionMaxSales = 1000 --default 25
auctionMaxSalesFee = 0 --default 20 in credits
auctionVendorExpirePeriod = 60 --default 30 in days
auctionCommodityExpirePeriod = 30 --default 7 in days

--Commands
commandCheckForceStatusCommandEnabled = true --default true
commandMeditateMergeEnabled = true --default false   merges /meditate and /forcemeditate together so it works if you have the skill from either.
commandObjectCreateAttachmentEnabled = true --default false
commandfsVillageEnabled = true --default false
commandRegrantSkillsEnabled = true --default false

--Faction
factionMaxRank = 21 --default 15  max 21
factionCapMultiplier = 100 --default 1

--Group
groupMaxSize = 50 --default 20

--Player Payments
playerPaymentCashAndBankEnabled = true --default false Auction/CityManager/Structure/RepairVehicle
playerPlayersOnlineAtLoginEnabled = true --default false

--Resources
resourcesAddNameEnabled = true --default false
resourcesMinimumQuality = 1000 --default 0
resourcesMaximumQuality = 1000 --default 1000
resourcesContainerSize = 10000000 --default 100000
resourcesResourceDeedSize = 300000 --default 30000

--Server
serverDrawDistance = 512 --default 192

--Vehicle
vehicleBaseDecayCycle = 600 -- default 600 in seconds
vehicleBaseDecayRate = 15 --default 15
vehicleInitialDecayEnabled = false --default true
vehicleCallTime = 0 --default 15 in seconds
vehicleStoreInCombatEnabled = true --default false
vehicleShowVehicleSpeedEnabled = true --default false

--Vendor
vendorLowMaintenanceEmailEnabled = true --default false
vendorLowMaintenanceEmailWarningThreshold = 360 --default 360 in credits
vendorSkimSalesForMaintenanceEnabled = true --default false
vendorSkimSalesForMaintenancePercent = 5 --default 5 in percent
