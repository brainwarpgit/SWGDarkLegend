dofile("scripts/managers/variables/mission_variables.lua")

padawan_the_ring_01_conv_handler = conv_handler:new {}

function padawan_the_ring_01_conv_handler:getInitialScreen(pPlayer, pNpc, pConvTemplate)
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

	local giverTrialNum = JediTrials:getTrialNumByName(pPlayer, "the_ring")
	local trialState = JediTrials:getTrialStateName(pPlayer, giverTrialNum)

	if (CreatureObject(pPlayer):hasScreenPlayState(1, trialState)) then
		return convoTemplate:getScreen("quest_completed")
	elseif (readData(playerID .. ":JediTrials:killedTarget") == 1) then
		return convoTemplate:getScreen("intro_killed_target")
	elseif (readData(playerID .. ":JediTrials:spokeToTarget01") == 1) then
		return convoTemplate:getScreen("intro_spoke_to_target")
	elseif (readData(playerID .. ":JediTrials:acceptedTask") == 1) then
		return convoTemplate:getScreen("intro_in_progress")
	else
		return convoTemplate:getScreen("intro")
	end

end

function padawan_the_ring_01_conv_handler:runScreenHandlers(pConvTemplate, pPlayer, pNpc, selectedOption, pConvScreen)
	local screen = LuaConversationScreen(pConvScreen)
	local screenID = screen:getScreenID()
	local pConvScreen = screen:cloneScreen()
	local clonedConversation = LuaConversationScreen(pConvScreen)
	local playerID = SceneObject(pPlayer):getObjectID()

	if (screenID == "im_doomed" or screenID == "rewards_not_monetary" or screenID == "would_have_stolen") then
		PadawanTrials:failTrial(pPlayer)
	elseif (screenID == "go_so_far") then
		PadawanTrials:passTrial(pPlayer)
		if missionJediPadawanTrialsGrantXPEnabled and missionJediPadawanTrailsXP ~= nil and missionJediPadawanTrailsXP > 0 then
			CreatureObject(pPlayer):awardExperience("jedi_general", missionJediPadawanTrailsXP, true)
		end
	elseif (screenID == "last_location") then
		writeData(playerID .. ":JediTrials:acceptedTask", 1)
		writeData(SceneObject(pNpc):getObjectID() .. ":destroyNpcOnExit", 1)
		PadawanTrials:createTargetLocation(pPlayer)
	end

	return pConvScreen
end
