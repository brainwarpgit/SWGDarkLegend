-- Allows players to choose to enable and set levels of random attacks 

mission_random_attacks_choice_admin = ScreenPlay:new {
	numberOfActs = 1,
	
	levels = {
		{levelRange = "FIX ERRORS Random Attacks", levelSelect = "1000"},
		{levelRange = "Show Variables", levelSelect = "1001"},
	},
}

function mission_random_attacks_choice_admin:start()

end

function mission_random_attacks_choice_admin:openWindow(pPlayer)
	if (pPlayer == nil) then
		return
	end

	self:showLevels(pPlayer)
end

function mission_random_attacks_choice_admin:showLevels(pPlayer)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return
	end

	local sui = SuiListBox.new("mission_random_attacks_choice_admin", "levelSelection")

	sui.setTargetNetworkId(SceneObject(pPlayer):getObjectID())

	sui.setTitle("Random Attack Level Selection")

	local promptText = "This is the admin menu for testing this process"

	sui.setPrompt(promptText)

	for i = 1,  #self.levels, 1 do
		sui.add(self.levels[i].levelRange, "")
	end

	sui.sendTo(pPlayer)
end

function mission_random_attacks_choice_admin:levelSelection(pPlayer, pSui, eventIndex, args)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return 
	end

	if (args == "-1") then
		CreatureObject(pPlayer):sendSystemMessage("No option was selected...")
		return
	end

	local selectedLevelIndex = tonumber(args)+1

	local selectedLevel = tostring(self.levels[selectedLevelIndex].levelSelect)
	
	if (selectedLevel == "1000") then
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedRange")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime")
		deleteScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTimeRange")
		CreatureObject(pPlayer):sendSystemMessage("Resetting stuff.")
		return
	end
	
	if (selectedLevel == "1001") then
		CreatureObject(pPlayer):sendSystemMessage("disableStep: " .. readScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep"))
		CreatureObject(pPlayer):sendSystemMessage("selectedLevel: " .. readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel"))
		CreatureObject(pPlayer):sendSystemMessage("selectedRange: " .. readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedRange"))
		CreatureObject(pPlayer):sendSystemMessage("selectedTime: " .. readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime"))
		CreatureObject(pPlayer):sendSystemMessage("selectedTimeRange: " .. readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTimeRange"))
		return
	end
end
