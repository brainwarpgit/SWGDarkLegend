--Admin
serverAdminTag = "SWGDL-Admin"

--Auction
serverAuctionMaxBazaarPrice = 10000000 --default 20000
serverAuctionMaxSales = 1000 --default 25
serverAuctionMaxSalesFee = 0 --default 20 in credits
serverAuctionVendorExpirePeriod = 60 --default 30 in days
serverAuctionCommodityExpirePeriod = 30 --default 7 in days

--Commands
serverCommandCheckForceStatusCommandEnabled = true --default true
serverCommandMeditateMergeEnabled = true --default false   merges /meditate and /forcemeditate together so it works if you have the skill from either.
serverCommandObjectCreateAttachmentEnabled = true --default false
serverCommandfsVillageEnabled = true --default false
serverCommandRegrantSkillsEnabled = true --default false

--Faction
serverFactionMaxRank = 21 --default 15  max 21
serverFactionCapMultiplier = 100 --default 1

--Group
serverGroupMaxSize = 50 --default 20

--Player Payments
serverPaymentCashAndBankEnabled = true --default false Auction/CityManager/Structure/RepairVehicle

--Resources
serverResourcesAddNameEnabled = true --default false
serverResourcesMinimumQuality = 1000 --default 0
serverResourcesMaximumQuality = 1000 --default 1000
serverResourcesContainerSize = 10000000 --default 100000
serverResourcesResourceDeedSize = 300000 --default 30000

--Server
serverDrawDistance = 512 --default 192
serverPlayersOnlineAtLoginEnabled = true --default false

--Vendor
serverVendorLowMaintenanceEmailEnabled = true --default false
serverVendorLowMaintenanceEmailWarningThreshold = 360 --default 360 in credits
serverVendorSkimSalesForMaintenanceEnabled = true --default false
serverVendorSkimSalesForMaintenancePercent = 5 --default 5 in percent
