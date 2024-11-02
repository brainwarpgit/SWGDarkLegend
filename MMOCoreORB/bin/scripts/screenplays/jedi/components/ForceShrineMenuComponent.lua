ForceShrineMenuComponent = {}

function ForceShrineMenuComponent:fillObjectMenuResponse(pSceneObject, pMenuResponse, pPlayer)
	local menuResponse = LuaObjectMenuResponse(pMenuResponse)
	local pObject = CreatureObject(pPlayer):getPlayerObject()
	if pObject == nil then
		CreatureObject(pPlayer):sendSystemMessage("Nil pObject")
	end
	
	if (CreatureObject(pPlayer):hasSkill("force_title_jedi_novice")) then
		menuResponse:addRadialMenuItem(120, 3, "@jedi_trials:meditate") -- Meditate
	end

	if (CreatureObject(pPlayer):hasSkill("force_title_jedi_rank_02")) then
		menuResponse:addRadialMenuItem(121, 3, "@force_rank:recover_jedi_items") -- Recover Jedi Items
	end

	if (not CreatureObject(pPlayer):hasSkill("force_title_jedi_novice")) then
		menuResponse:addRadialMenuItem(122, 3, "Become One with the Force!")
	end
	
	if (PlayerObject(pObject):isAdmin()) then
		menuResponse:addRadialMenuItem(123, 3, "Finish Village")
		menuResponse:addRadialMenuItem(124, 3, "Finish Padawan Trials")
		menuResponse:addRadialMenuItem(125, 3, "Finish Knight Trials")
	end
end

function ForceShrineMenuComponent:handleObjectMenuSelect(pObject, pPlayer, selectedID)
	if (pPlayer == nil or pObject == nil) then
		return 0
	end

	if (selectedID == 120 and (CreatureObject(pPlayer):hasSkill("force_title_jedi_novice"))) then
		if (CreatureObject(pPlayer):getPosture() ~= CROUCHED) then
			CreatureObject(pPlayer):sendSystemMessage("@jedi_trials:show_respect") -- Must respect
		else
			self:doMeditate(pObject, pPlayer)
		end
	elseif (selectedID == 121 and CreatureObject(pPlayer):hasSkill("force_title_jedi_rank_02")) then
		self:recoverRobe(pPlayer)
	elseif (selectedID == 122) then
		if (CreatureObject(pPlayer):getPosture() ~= CROUCHED) then
			CreatureObject(pPlayer):sendSystemMessage("To properly meditate here, you must do so respectfully.")
		else
			self:makeForceSensitive(pPlayer)
		end
	elseif (selectedID == 123) then
		if (CreatureObject(pPlayer):getPosture() ~= CROUCHED) then
			CreatureObject(pPlayer):sendSystemMessage("To properly meditate here, you must do so respectfully.")
		else
			FsOutro:completeVillageOutroFrog(pPlayer)
		end
	elseif (selectedID == 124) then
		if (CreatureObject(pPlayer):getPosture() ~= CROUCHED) then
			CreatureObject(pPlayer):sendSystemMessage("To properly meditate here, you must do so respectfully.")
		else
			JediTrials:unlockJediPadawan(pPlayer)
		end
	elseif (selectedID == 125) then
		if (CreatureObject(pPlayer):getPosture() ~= CROUCHED) then
			CreatureObject(pPlayer):sendSystemMessage("To properly meditate here, you must do so respectfully.")
		else
			JediTrials:unlockJediKnight(pPlayer)
		end
	end

	return 0
end

function ForceShrineMenuComponent:doMeditate(pObject, pPlayer)
	if (tonumber(readScreenPlayData(pPlayer, "KnightTrials", "completedTrials")) == 1 and not CreatureObject(pPlayer):hasSkill("force_title_jedi_rank_03")) then
		KnightTrials:resetCompletedTrialsToStart(pPlayer)
	end

	if (not CreatureObject(pPlayer):hasSkill("force_title_jedi_rank_02") and CreatureObject(pPlayer):hasScreenPlayState(32, "VillageJediProgression")) then
		local currentTrial = JediTrials:getCurrentTrial(pPlayer)

		if (not JediTrials:isOnPadawanTrials(pPlayer)) then
			PadawanTrials:startPadawanTrials(pObject, pPlayer)
		elseif (currentTrial == 0) then
			PadawanTrials:startNextPadawanTrial(pObject, pPlayer)
		else
			PadawanTrials:showCurrentTrial(pObject, pPlayer)
		end
	elseif (JediTrials:isOnKnightTrials(pPlayer)) then
		local pPlayerShrine = KnightTrials:getTrialShrine(pPlayer)

		if (pPlayerShrine ~= nil and pObject ~= pPlayerShrine) then
			local correctShrineZone = SceneObject(pPlayerShrine):getZoneName()
			if (correctShrineZone ~= SceneObject(pObject):getZoneName()) then
				local messageString = LuaStringIdChatParameter("@jedi_trials:knight_shrine_reminder")
				messageString:setTO(getStringId("@jedi_trials:" .. correctShrineZone))
				CreatureObject(pPlayer):sendSystemMessage(messageString:_getObject())
			else
				CreatureObject(pPlayer):sendSystemMessage("@jedi_trials:knight_shrine_wrong")
			end
			return
		end

		local currentTrial = JediTrials:getCurrentTrial(pPlayer)
		local trialsCompleted = JediTrials:getTrialsCompleted(pPlayer)

		if (currentTrial == 0 and trialsCompleted == 0) then
			local sui = SuiMessageBox.new("KnightTrials", "startNextKnightTrial")
			sui.setTitle("@jedi_trials:knight_trials_title")
			sui.setPrompt("@jedi_trials:knight_trials_start_query")
			sui.setOkButtonText("@jedi_trials:button_yes")
			sui.setCancelButtonText("@jedi_trials:button_no")
			sui.sendTo(pPlayer)
		else
			KnightTrials:showCurrentTrial(pPlayer)
		end
	end
end

function ForceShrineMenuComponent:recoverRobe(pPlayer)
	local pInventory = SceneObject(pPlayer):getSlottedObject("inventory")

	if (pInventory == nil) then
		return
	end

	if (SceneObject(pInventory):isContainerFullRecursive()) then
		CreatureObject(pPlayer):sendSystemMessage("@jedi_spam:inventory_full_jedi_robe")
		return
	end

	if CreatureObject(pPlayer):hasSkill("force_title_jedi_rank_02") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_padawan.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_dark_novice") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_dark_s01.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_light_novice") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_light_s01.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_dark_rank_01") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_dark_s02.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_light_rank_01") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_light_s02.iff", -1)
	end
		if CreatureObject(pPlayer):hasSkill("force_rank_dark_rank_05") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_dark_s03.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_light_rank_05") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_light_s03.iff", -1)
	end
		if CreatureObject(pPlayer):hasSkill("force_rank_dark_rank_08") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_dark_s04.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_light_rank_08") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_light_s04.iff", -1)
	end
		if CreatureObject(pPlayer):hasSkill("force_rank_dark_rank_10") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_dark_s05.iff", -1)
	end
	if CreatureObject(pPlayer):hasSkill("force_rank_light_rank_10") then
		giveItem(pInventory, "object/tangible/wearables/robe/robe_jedi_light_s05.iff", -1)
	end
	
	CreatureObject(pPlayer):sendSystemMessage("@force_rank:items_recovered")
end

function ForceShrineMenuComponent:makeForceSensitive(pPlayer)

	local sui = SuiMessageBox.new("ForceShrineMenuComponent", "forceSelection") 
	
	sui.setTitle("Force Sensitive")

	local promptText = "Would you like to become Force Sensitive?\n\nIf you choose to accept, you will be visited by a mysterious character to begin your journey!\n\n\\#pcontrast1 It is recommended but not required to have at least 1 master profession before becoming Force Sensitive.\\#"

	sui.setPrompt(promptText)
	sui.setOkButtonText("Yes")
	sui.setCancelButtonText("No")
	
	sui.sendTo(pPlayer)
	
end

function ForceShrineMenuComponent:forceSelection(pPlayer, pSui, eventIndex, args)
	sayings = {
		"The Force is a guide, not a master. Let it flow through you, but do not seek to control it.",
		"Patience is the path to true understanding. The Force reveals itself to those who wait.",
		"Trust in the Force, but trust in yourself first. The two are one.",
		"Your connection to the Force is unique. Nurture it, and it will grow as you do.",
		"In stillness, you will find the Force. In motion, you will understand it.",
		"Balance within yourself, and the Force will be balance with you.",
		"The Force in all things, but it is strongest in those who seek it with a pure heart."
	}

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		CreatureObject(pPlayer):sendSystemMessage("Come back when you are ready to learn the ways of the Force.")
		return
	end
		
	VillageJediManagerCommon.setJediProgressionScreenPlayState(pPlayer, VILLAGE_JEDI_PROGRESSION_GLOWING)
	FsIntro:startPlayerOnIntro(pPlayer)
	CreatureObject(pPlayer):sendSystemMessage(sayings[getRandomNumber(#sayings)])	
end
