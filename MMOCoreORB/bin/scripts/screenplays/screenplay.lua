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

Act = Object:new {

}

return ScreenPlay
