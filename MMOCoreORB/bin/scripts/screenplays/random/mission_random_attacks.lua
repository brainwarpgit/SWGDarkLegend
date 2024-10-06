local ObjectManager = require("managers.object.object_manager")
local QuestManager = require("managers.quest.quest_manager")
local Logger = require("utils.logger")

mission_random_attacks = ScreenPlay:new {
	debug = false,
}

function mission_random_attacks:startStepDelay(pPlayer)
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - START", LT_INFO) end
	if (pPlayer == nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - pPlayer nil", LT_INFO) end
		return
	end
	local selectedTime = tonumber(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime"))
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - selectedTime " .. selectedTime, LT_INFO) end
	local attackDelay = getRandomNumber(selectedTime, selectedTime + 15) * 60 * 1000
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - attackDelay " .. attackDelay, LT_INFO) end
	writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelay", attackDelay / 1000 + os.time())
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - currentDelay " .. attackDelay / 1000 + os.time(), LT_INFO) end
	writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelayStep", "Initial Encounter")
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - currentDelayStep", LT_INFO) end
	createEvent(attackDelay, "mission_random_attacks", "doDelayedStep", pPlayer, "")
	if (self.debug) then Logger:logEvent("DEBUG MRA startStepDelay - END", LT_INFO) end
end

function mission_random_attacks:doDelayedStep(pPlayer)
	if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - START", LT_INFO) end
	if (pPlayer == nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - pPlayer nil", LT_INFO) end
		return
	end
	
	local pGhost = CreatureObject(pPlayer):getPlayerObject()

	if (pGhost == nil or not PlayerObject(pGhost):isOnline()) then
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - pGhost nil", LT_INFO) end
		return
	end

	if (CreatureObject(pPlayer):isDead() or CreatureObject(pPlayer):isIncapacitated()) then -- or not Encounter:isPlayerInPositionForEncounter(pPlayer)) then
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - creature is dead or incapped and not in position for encounter", LT_INFO) end
		local selectedTime = tonumber(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime"))
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - selectedTime " .. selectedTime, LT_INFO) end
		local attackDelay = 5 * 60 * 1000
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - attackDelay " .. attackDelay, LT_INFO) end
		writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelay", attackDelay / 1000 + os.time())
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - currentDelay " .. attackDelay / 1000 + os.time(), LT_INFO) end
		writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelayStep", "Retry when outside city limits")
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - currentDelayStep", LT_INFO) end
		createEvent(attackDelay, "mission_random_attacks", "doDelayedStep", pPlayer, "")
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - looping to doDelayedStep", LT_INFO) end
		return
	end

	local encounterResult = true
	local selectedLevel = readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel")
	if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - selectedLevel " .. selectedLevel, LT_INFO) end
	
	if (selectedLevel ~= "0" and selectedLevel ~= nil) then 
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep2 - Continue to spawnMobile", LT_INFO) end
		encounterResult = mission_random_attacks:spawnMobile(pPlayer)
	else
		if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep2 - No Level Selected so end task", LT_INFO) end
		return
	end		
	if (self.debug) then Logger:logEvent("DEBUG MRA doDelayedStep - END", LT_INFO) end
end

function mission_random_attacks:spawnMobile(pPlayer)
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - START", LT_INFO) end
	if (pPlayer == nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - pPlayer nil", LT_INFO) end
		return
	end
	local planet = SceneObject(pPlayer):getZoneName()
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - planet " .. planet, LT_INFO) end
	local playerX = SceneObject(pPlayer):getPositionX()
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - playerX " .. playerX, LT_INFO) end
	local playerY = SceneObject(pPlayer):getPositionY()
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - playerY " .. playerY, LT_INFO) end
	local mobX = playerX - getRandomNumber(20, 40)
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - mobX " .. mobX, LT_INFO) end
	local mobY = playerY - getRandomNumber(20, 40)
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - mobY " .. mobY, LT_INFO) end
	local mobZ = getTerrainHeight(pPlayer, mobX, mobY)
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - mobZ " .. mobZ, LT_INFO) end
	local selectedLevel = readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel")
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - selectedLevel " .. selectedLevel, LT_INFO) end
	local pMobile = spawnMobile(planet, self:spawnRandomMobScreenP("thug_mra_" .. selectedLevel), -1, mobX, mobZ, mobY, 0, 0, false)
	if (pMobile ~= nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - pMobile not nil", LT_INFO) end
		AiAgent(pMobile):removeObjectFlag(AI_ESCORT)
		AiAgent(pMobile):removeObjectFlag(AI_FOLLOW)
		AiAgent(pMobile):setAITemplate()
		AiAgent(pMobile):addDefender(pPlayer)
	end
	local mobID = SceneObject(pMobile):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - mobID " .. mobID, LT_INFO) end
	local playerID = SceneObject(pPlayer):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - playerID " .. playerID, LT_INFO) end
	writeData(mobID .. ":mobID", mobID)
	writeData(mobID .. ":playerID", playerID)
	createObserver(CREATUREDESPAWNED, "mission_random_attacks", "onDespawnScreen", pMobile)
	if (self.debug) then Logger:logEvent("DEBUG MRA spawnMobile - END", LT_INFO) end

end

function ScreenPlay:onDespawnScreen(pMobile)
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - START", LT_INFO) end
	local mobID = SceneObject(pMobile):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - mobID " .. mobID, LT_INFO) end
	local playerID = readData(mobID .. ":playerID")
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - playerID " .. playerID, LT_INFO) end
	local pPlayer = getCreatureObject(playerID)
	if (pPlayer == nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - pPlayer is nil", LT_INFO) end
		return
	end
	if pMobile == nil then
		if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - pMobile is nil", LT_INFO) end
		return
	end
	local mobID = SceneObject(pMobile):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - mobID " .. mobID, LT_INFO) end
	local playerID = readData(mobID .. ":playerID")
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - playerID " .. playerID, LT_INFO) end
	local pPlayer = getCreatureObject(playerID)
	if (pPlayer == nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - pPlayer is nil", LT_INFO) end
		return
	end
	local selectedTime = tonumber(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime"))
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - selectedTime " .. selectedTime, LT_INFO) end
	local attackDelay = getRandomNumber(selectedTime, selectedTime + 15) * 60 * 1000
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - attackDelay " .. attackDelay, LT_INFO) end
	writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelay", attackDelay / 1000 + os.time())
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - currentDelay " .. attackDelay / 1000 + os.time(), LT_INFO) end
	writeScreenPlayData(pPlayer, "mission_random_attacks", "currentDelayStep", "Respawning Encounter")
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - currentDelayStep", LT_INFO) end
	deleteData(mobID .. ":mobID")
	deleteData(mobID .. ":playerID")
	local readSelectedLevel = tostring(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel"))
	local readDisableStep = tostring(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep"))
	if readDisableStep ~= "1" then
		createEvent(attackDelay, "mission_random_attacks", "respawnScreen", pPlayer, "")
	else
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedRange")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime") 
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTimeRange") 
		deleteScreenPlayData(pPlayer, "mission_random_attacks", "currentDelay")
		deleteScreenPlayData(pPlayer, "mission_random_attacks", "currentDelayStep")
		CreatureObject(pPlayer):sendSystemMessage("Random Mission Attacks have now been cleared.")
		return 1
	end
	if (self.debug) then Logger:logEvent("DEBUG MRA onDespawnScreen - END", LT_INFO) end
	return 1
end

function ScreenPlay:respawnScreen(pPlayer)
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - START", LT_INFO) end
	if pPlayer == nil then
		if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - pPlayer is nil", LT_INFO) end
		return
	end
	local planet = SceneObject(pPlayer):getZoneName()
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - planet " .. planet, LT_INFO) end
	local playerX = SceneObject(pPlayer):getPositionX()
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - playerX " .. playerX, LT_INFO) end
	local playerY = SceneObject(pPlayer):getPositionY()
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - playerY " .. playerY, LT_INFO) end
	local mobX = playerX - getRandomNumber(20, 40)
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - mobX " .. mobX, LT_INFO) end
	local mobY = playerY - getRandomNumber(20, 40)
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - mobY " .. mobY, LT_INFO) end
	local mobZ = getTerrainHeight(pPlayer, mobX, mobY)
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - mobZ " .. mobZ, LT_INFO) end
	local selectedLevel = readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel")
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - selectedLevel " .. selectedLevel, LT_INFO) end
	local pMobile = spawnMobile(planet, self:spawnRandomMobScreenP("thug_mra_" .. selectedLevel), -1, mobX, mobZ, mobY, 0, 0, false)
	if (pMobile ~= nil) then
		if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - pMobile not nil", LT_INFO) end
		AiAgent(pMobile):removeObjectFlag(AI_ESCORT)
		AiAgent(pMobile):removeObjectFlag(AI_FOLLOW)
		AiAgent(pMobile):setAITemplate()
		AiAgent(pMobile):addDefender(pPlayer)
	end
	local mobID = SceneObject(pMobile):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - mobID " .. mobID, LT_INFO) end
	local playerID = SceneObject(pPlayer):getObjectID()
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - playerID " .. playerID, LT_INFO) end
	writeData(mobID .. ":mobID", mobID)
	writeData(mobID .. ":playerID", playerID)
	createObserver(CREATUREDESPAWNED, "mission_random_attacks", "onDespawnScreen", pMobile)
	if (self.debug) then Logger:logEvent("DEBUG MRA respawnScreen - END", LT_INFO) end
end


