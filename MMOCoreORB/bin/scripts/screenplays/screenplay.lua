local ObjectManager = require("managers.object.object_manager")

function printf(...) io.write(string.format(table.unpack({...}))) end

function writeData(key, data)
	writeSharedMemory(string.format(key), data)
end

function writeStringData(key, data)
	writeStringSharedMemory(string.format(key), string.format(data))
end

function deleteData(key)
	deleteSharedMemory(string.format(key))
end

function deleteStringData(key)
	deleteStringSharedMemory(string.format(key))
end

function readData(key)
	return readSharedMemory(string.format(key))
end

function readStringData(key)
	return readStringSharedMemory(string.format(key))
end

function writeVector3Data(key, x, z, y)
	writeVector3SharedMemory(string.format(key), x, z, y)
end

function readVector3Data(key)
	return readVector3SharedMemory(string.format(key))
end

function deleteVector3Data(key)
	deleteVector3SharedMemory(string.format(key))
end

ScreenPlay = Object:new {
	screenplayName = "",
	numerOfActs = 0,
	startingEvent = nil,

	lootContainers = {},
	lootLevel = 0,
	lootGroups = {},
	lootContainerRespawn = 1800 -- 30 minutes
}

function ScreenPlay:initializeLootContainers()
	for k,v in pairs(self.lootContainers) do
		local pContainer = getSceneObject(v)
		if (pContainer ~= nil) then
			createObserver(OPENCONTAINER, self.screenplayName, "spawnContainerLoot", pContainer)
			self:spawnContainerLoot(pContainer)

			local container = SceneObject(pContainer)
			container:setContainerDefaultAllowPermission(MOVEOUT + OPEN)
			container:setContainerComponent("PlaceableLootContainerComponent")
		end
	end
end

function ScreenPlay:spawnContainerLoot(pContainer)
	local container = SceneObject(pContainer)
	local time = getTimestamp()

	if (readData(container:getObjectID()) > time) then
		return 0
	end

	writeData(container:getObjectID(), time + self.lootContainerRespawn)

	--If it has loot already, then exit.
	if (container:getContainerObjectsSize() > 0) then
		return 0
	end

	createLootFromCollection(pContainer, self.lootGroups, self.lootLevel)

	return 0
end

function ScreenPlay:setMoodString(pNpc, mood)
	if pNpc == nil or not SceneObject(pNpc):isCreatureObject() then
		return
	end

	CreatureObject(pNpc):setMoodString(mood)
end

function ScreenPlay:setCustomName(pObj, name)
	if pObj == nil then
		return
	end

	SceneObject(pObj):setCustomObjectName(name)
end

function ScreenPlay:spawnScreenPMobiles()
	for i = 1, #self.ScreenPSpawns, 1 do
		local ScreenPSpawn = self.ScreenPSpawns[i]
		local pMobile = spawnMobile(ScreenPSpawn[1],self:spawnRandomMobScreenP(ScreenPSpawn[2]),-1,ScreenPSpawn[4],ScreenPSpawn[5],ScreenPSpawn[6],ScreenPSpawn[7],ScreenPSpawn[8])
		createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnScreenP", pMobile)
		local mobID = SceneObject(pMobile):getObjectID()
		writeData(mobID .. ":respawnTimer", ScreenPSpawn[3])
		writeData(mobID .. ":mobID", i)
	end
end



function ScreenPlay:spawnRandomMobScreenP(mobName)
	local mobs = {"", "_2", "_3"}
	local randomNumber = getRandomNumber(1000)
	local randomIndex
	if randomNumber > 900 then
		randomIndex = 3
	elseif randomNumber > 600 then
		randomIndex = 2
	else 
		randomIndex = 1
	end
	local randomMob = mobs[randomIndex]
	mobName = mobName .. randomMob
	return mobName
end

function ScreenPlay:onDespawnScreenP(pMobile)
	if pMobile == nil or not SceneObject(pMobile):isAiAgent() then
		return
	end
	local mobID = SceneObject(pMobile):getObjectID()
	local mobNum = readData(mobID .. ":mobID")
	local respawnTimer = readData(mobID .. ":respawnTimer")
	createEvent(respawnTimer * 1000, self.screenplayName, "respawnScreenP", nil, mobNum)
	deleteData(mobID .. ":mobID")
	deleteData(mobID .. ":respawnTimer")
	return 1
end

function ScreenPlay:respawnScreenP(mob, spawnNumber)
	local ScreenPSpawn = self.ScreenPSpawns[tonumber(spawnNumber)]
	local pMobile = spawnMobile(ScreenPSpawn[1],self:spawnRandomMobScreenP(ScreenPSpawn[2]),-1,ScreenPSpawn[4],ScreenPSpawn[5],ScreenPSpawn[6],ScreenPSpawn[7],ScreenPSpawn[8])
	createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnScreenP", pMobile)
	local mobID = SceneObject(pMobile):getObjectID()
	writeData(mobID .. ":respawnTimer", ScreenPSpawn[3])
	writeData(mobID .. ":mobID", spawnNumber)
end

function ScreenPlay:spawnRoriGiantBarkMiteCaveMobiles()
	for i = 1, #self.RoriGiantBarkMiteSpawns, 1 do
		local RoriGiantBarkMiteSpawn = self.RoriGiantBarkMiteSpawns[i]
		local pMobile = spawnMobile(RoriGiantBarkMiteSpawn[1],self:spawnRandomMobScreenP(RoriGiantBarkMiteSpawn[2]),-1,RoriGiantBarkMiteSpawn[4],RoriGiantBarkMiteSpawn[5],RoriGiantBarkMiteSpawn[6],RoriGiantBarkMiteSpawn[7],RoriGiantBarkMiteSpawn[8])
		if string.find(RoriGiantBarkMiteSpawn[2], "giant_mutant_bark_mite") then
			self:registerRoriGiantBarkMiteLootObserver(pMobile, "Mite")
		elseif string.find(RoriGiantBarkMiteSpawn[2], "mutant_bark_mite_hatchling") then
			self:registerRoriGiantBarkMiteLootObserver(pMobile, "Hatchling")
		elseif string.find(RoriGiantBarkMiteSpawn[2], "mutant_bark_mite_worker") then
			self:registerRoriGiantBarkMiteLootObserver(pMobile, "Worker")
		elseif string.find(RoriGiantBarkMiteSpawn[2], "mutant_bark_mite_soldier") then
			self:registerRoriGiantBarkMiteLootObserver(pMobile, "Soldier")
		elseif string.find(RoriGiantBarkMiteSpawn[2], "mutant_bark_mite_queen") then
			self:registerRoriGiantBarkMiteLootObserver(pMobile, "Queen")
		end		
		createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnRoriGiantBarkMite", pMobile)
		local mobID = SceneObject(pMobile):getObjectID()
		writeData(mobID .. ":respawnTimer", RoriGiantBarkMiteSpawn[3])
		writeData(mobID .. ":mobID", i)
	end
end

function ScreenPlay:registerRoriGiantBarkMiteLootObserver(mobile, type)
	if (mobile == nil) then
		return
	end
	createObserver(LOOTCREATURE, "RishaSinan", "notifyLoot" .. type, mobile)
end

function ScreenPlay:onDespawnRoriGiantBarkMite(pMobile)
	if pMobile == nil or not SceneObject(pMobile):isAiAgent() then
		return
	end
	local mobID = SceneObject(pMobile):getObjectID()
	local mobNum = readData(mobID .. ":mobID")
	local respawnTimer = readData(mobID .. ":respawnTimer")
	createEvent(respawnTimer * 1000, self.screenplayName, "respawnRoriGiantBarkMite", nil, mobNum)
	deleteData(mobID .. ":mobID")
	deleteData(mobID .. ":respawnTimer")
	return 1
end

function ScreenPlay:respawnRoriGiantBarkMite(mob, spawnNumber)
	local RoriGiantBarkMiteSpawn = self.RoriGiantBarkMiteSpawns[tonumber(spawnNumber)]
	local pMobile = spawnMobile(RoriGiantBarkMiteSpawn[1],self:spawnRandomMobScreenP(RoriGiantBarkMiteSpawn[2]),-1,RoriGiantBarkMiteSpawn[4],RoriGiantBarkMiteSpawn[5],RoriGiantBarkMiteSpawn[6],RoriGiantBarkMiteSpawn[7],RoriGiantBarkMiteSpawn[8])
	if string.find(RoriGiantBarkMiteSpawn[1], "Mite") then
		self:registerRoriGiantBarkMiteLootObserver(pMobile, "Mite")
	elseif string.find(RoriGiantBarkMiteSpawn[1], "Hatchling") then
		self:registerRoriGiantBarkMiteLootObserver(pMobile, "Hatchling")
	elseif string.find(RoriGiantBarkMiteSpawn[1], "Worker") then
		self:registerRoriGiantBarkMiteLootObserver(pMobile, "Worker")
	elseif string.find(RoriGiantBarkMiteSpawn[1], "Soldier") then
		self:registerRoriGiantBarkMiteLootObserver(pMobile, "Soldier")
	elseif string.find(RoriGiantBarkMiteSpawn[1], "Queen") then
		self:registerRoriGiantBarkMiteLootObserver(pMobile, "Queen")
	end		
	createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnRoriGiantBarkMite", pMobile)
	local mobID = SceneObject(pMobile):getObjectID()
	writeData(mobID .. ":respawnTimer", RoriGiantBarkMiteSpawn[3])
	writeData(mobID .. ":mobID", spawnNumber)
end

function ScreenPlay:spawnImperialMobiles(pBuilding)
 	for i = 1, #self.ScreenImperialSpawns, 1 do
		local ScreenImperialSpawn = self.ScreenImperialSpawns[i]
		local pMobile = spawnMobile(ScreenImperialSpawn[1],self:spawnRandomMobScreenP(ScreenImperialSpawn[2]),-1,ScreenImperialSpawn[4],ScreenImperialSpawn[5],ScreenImperialSpawn[6],ScreenImperialSpawn[7],ScreenImperialSpawn[8])
		createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnImperialScreenP", pMobile)
		local mobID = SceneObject(pMobile):getObjectID()
		writeData(mobID .. ":respawnTimer", ScreenImperialSpawn[3])
		writeData(mobID .. ":mobID", i)
	end
end



function ScreenPlay:spawnRebelMobiles(pBuilding)
	for i = 1, #self.ScreenRebelSpawns, 1 do
		local ScreenRebelSpawn = self.ScreenRebelSpawns[i]
		local pMobile = spawnMobile(ScreenRebelSpawn[1],self:spawnRandomMobScreenP(ScreenRebelSpawn[2]),-1,ScreenRebelSpawn[4],ScreenRebelSpawn[5],ScreenRebelSpawn[6],ScreenRebelSpawn[7],ScreenRebelSpawn[8])
		createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnRebelScreenP", pMobile)
		local mobID = SceneObject(pMobile):getObjectID()
		writeData(mobID .. ":respawnTimer", ScreenRebelSpawn[3])
		writeData(mobID .. ":mobID", i)
	end
end


function ScreenPlay:onDespawnRebelScreenP(pMobile, p, pBuilding)
	if pMobile == nil or not SceneObject(pMobile):isAiAgent() then
		return
	end
	local mobID = SceneObject(pMobile):getObjectID()
	local mobNum = readData(mobID .. ":mobID")
	local respawnTimer = readData(mobID .. ":respawnTimer")
	createEvent(respawnTimer * 1000, self.screenplayName, "respawnRebelScreenP", nil, mobNum)
	deleteData(mobID .. ":mobID")
	deleteData(mobID .. ":respawnTimer")
	return 1
end

function ScreenPlay:onDespawnImperialScreenP(pMobile, p, pBuilding)
	if pMobile == nil or not SceneObject(pMobile):isAiAgent() then
		return
	end
	local mobID = SceneObject(pMobile):getObjectID()
	local mobNum = readData(mobID .. ":mobID")
	local respawnTimer = readData(mobID .. ":respawnTimer")
	createEvent(respawnTimer * 1000, self.screenplayName, "respawnImperialScreenP", nil, mobNum)
	deleteData(mobID .. ":mobID")
	deleteData(mobID .. ":respawnTimer")
	return 1
end

function ScreenPlay:respawnRebelScreenP(mob, spawnNumber)
	local ScreenRebelSpawn = self.ScreenRebelSpawns[tonumber(spawnNumber)]
	local pMobile = spawnMobile(ScreenRebelSpawn[1],self:spawnRandomMobScreenP(ScreenRebelSpawn[2]),-1,ScreenRebelSpawn[4],ScreenRebelSpawn[5],ScreenRebelSpawn[6],ScreenRebelSpawn[7],ScreenRebelSpawn[8])
	createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnRebelScreenP", pMobile)
	local mobID = SceneObject(pMobile):getObjectID()
	writeData(mobID .. ":respawnTimer", ScreenRebelSpawn[3])
	writeData(mobID .. ":mobID", spawnNumber)
end

function ScreenPlay:respawnImperialScreenP(mob, spawnNumber)
	local ScreenImperialSpawn = self.ScreenImperialSpawns[tonumber(spawnNumber)]
	local pMobile = spawnMobile(ScreenImperialSpawn[1],self:spawnRandomMobScreenP(ScreenImperialSpawn[2]),-1,ScreenImperialSpawn[4],ScreenImperialSpawn[5],ScreenImperialSpawn[6],ScreenImperialSpawn[7],ScreenImperialSpawn[8])
	createObserver(CREATUREDESPAWNED, self.screenplayName, "onDespawnImperialScreenP", pMobile)
	local mobID = SceneObject(pMobile):getObjectID()
	writeData(mobID .. ":respawnTimer", ScreenImperialSpawn[3])
	writeData(mobID .. ":mobID", spawnNumber)
end

Act = Object:new {

}

return ScreenPlay
