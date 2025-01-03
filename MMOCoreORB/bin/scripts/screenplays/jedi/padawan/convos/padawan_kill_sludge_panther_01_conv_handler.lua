dofile("scripts/managers/variables/mission_variables.lua")

padawan_kill_sludge_panther_01_conv_handler = conv_handler:new {}

function padawan_kill_sludge_panther_01_conv_handler:getInitialScreen(pPlayer, pNpc, pConvTemplate)
	local convoTemplate = LuaConversationTemplate(pConvTemplate)
	local trialOwnerID = readData(SceneObject(pNpc):getObjectID() .. ":ownerID")
	local playerID = SceneObject(pPlayer):getObjectID()

	if (trialOwnerID ~= playerID) then
		return convoTemplate:getScreen("not_quest_owner")
	end

	if (not JediTrials:isOnPadawanTrials(pPlayer)) then
		writeData(SceneObject(pNpc):getObjectID() .. ":destroyNpcOnExit", 1)
		return convoTemplate:getScreen("not_quest_owner")
	end

	local giverTrialNum = JediTrials:getTrialNumByName(pPlayer, "kill_sludge_panther")
	local trialState = JediTrials:getTrialStateName(pPlayer, giverTrialNum)

	if (CreatureObject(pPlayer):hasScreenPlayState(1, trialState)) then
		return convoTemplate:getScreen("quest_completed")
	elseif (PadawanTrials:hasCompletedHunt(pPlayer)) then
		return convoTemplate:getScreen("intro_reached_goal")
	elseif (readData(playerID .. ":JediTrials:acceptedTask") == 1) then
		return convoTemplate:getScreen("intro_in_progress")
	else
		return convoTemplate:getScreen("intro")
	end
end

function padawan_kill_sludge_panther_01_conv_handler:runScreenHandlers(pConvTemplate, pPlayer, pNpc, selectedOption, pConvScreen)
	local screen = LuaConversationScreen(pConvScreen)
	local screenID = screen:getScreenID()
	local playerID = SceneObject(pPlayer):getObjectID()

	if (screenID == "intro_reached_goal") then
		PadawanTrials:passTrial(pPlayer)
		if missionJediPadawanTrialsGrantXPEnabled and missionJediPadawanTrailsXP ~= nil and missionJediPadawanTrailsXP > 0 then
			CreatureObject(pPlayer):awardExperience("jedi_general", missionJediPadawanTrailsXP, true)
		end
	elseif (screenID == "find_and_kill") then
		PadawanTrials:setupHuntTrial(pPlayer)
		writeData(playerID .. ":JediTrials:acceptedTask", 1)
		writeData(SceneObject(pNpc):getObjectID() .. ":destroyNpcOnExit", 1)

		local pGhost = CreatureObject(pPlayer):getPlayerObject()

		if (pGhost ~= nil) then
			PlayerObject(pGhost):removeWaypointBySpecialType(WAYPOINTQUESTTASK)
		end
	end

	return pConvScreen
end
