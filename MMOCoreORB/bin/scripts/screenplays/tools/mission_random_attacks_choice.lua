-- Allows players to choose to enable and set levels of random attacks 

mission_random_attacks_choice = ScreenPlay:new {
	numberOfActs = 1,
	
	levels = {
		{levelRange = "Level 1-50", levelSelect = "01"},
		{levelRange = "Level 51-100", levelSelect = "51"}, 
		{levelRange = "Level 101-150", levelSelect = "101"}, 
		{levelRange = "Level 151-200", levelSelect = "151"}, 
		{levelRange = "Level 201-250", levelSelect = "201"}, 
		{levelRange = "Level 251-300", levelSelect = "251"}, 
		{levelRange = "Level 301-350", levelSelect = "301"}, 
		{levelRange = "Level 351-400", levelSelect = "351"}, 
		{levelRange = "Level 401-450", levelSelect = "401"},
		{levelRange = "Level 450", levelSelect = "450"},
	},
	
	levelsDisable = {
		{levelRange = "Disable Random Attacks", levelSelect = "0"},
	},

	times = {
		{timeRange = "15 - 30 Mintues", timeSelect = "15"},
		{timeRange = "30 - 45 Minutes", timeSelect = "30"},
		{timeRange = "45 - 60 Minutes", timeSelect = "45"},
		{timeRange = "1 - 1.25 Hours", timeSelect = "60"},
		{timeRange = "1.25 - 1.5 Hours", timeSelect = "75"},
		{timeRange = "1.5 - 1.75 Hours", timeSelect = "90"},
		{timeRange = "1.75 - 2 Hours", timeSelect = "105"},
	},
}

function mission_random_attacks_choice:start()

end

function mission_random_attacks_choice:openWindow(pPlayer)
	if (pPlayer == nil) then
		return
	end

	self:showLevels(pPlayer)
end

function mission_random_attacks_choice:showLevels(pPlayer)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return
	end

	local sui = SuiListBox.new("mission_random_attacks_choice", "levelSelection")

	sui.setTargetNetworkId(SceneObject(pPlayer):getObjectID())

	sui.setTitle("Random Attack Level Selection")

	local promptText = "Use this menu to select a random attack level range.  The next screen will take you to the random attack time range.  Selecting anything other than Disabled, enables this feature.  Be warned, selecting levels higher than you are, could result in a painful death."

	sui.setPrompt(promptText)

	local readSelectedLevel = tostring(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel"))
	local readDisableStep = tostring(readScreenPlayData(pPlayer,"mission_random_attacks_choice", "disableStep"))
	if ((readSelectedLevel == "0" or readSelectedLevel == "") and (readDisableStep ~= "0" or readDisableStep == "")) then
		for i = 1,  #self.levels, 1 do
			sui.add(self.levels[i].levelRange, "")
		end
		writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "levelChoice", "enable")
	else
		sui.add(self.levelsDisable[1].levelRange, "")
		writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "levelChoice", "disable")
	end

	sui.sendTo(pPlayer)
end

function mission_random_attacks_choice:levelSelection(pPlayer, pSui, eventIndex, args)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return 
	end

	if (args == "-1") then
		CreatureObject(pPlayer):sendSystemMessage("No level was selected...")
		return
	end

	local selectedLevelIndex = tonumber(args)+1

	local readLevelChoice = tostring(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "levelChoice"))
		
	local selectedLevel= ""
	local selectedRange = ""
	
	if readLevelChoice == "enable" then
		selectedLevel = tostring(self.levels[selectedLevelIndex].levelSelect)
		selectedRange = self.levels[selectedLevelIndex].levelRange
	else
		selectedLevel = tostring(self.levelsDisable[selectedLevelIndex].levelSelect)
		selectedRange = self.levelsDisable[selectedLevelIndex].levelRange
	end 	
	
	if (selectedLevel == "0") then
		local readDisableStep = tostring(readScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep"))
		if readDisableStep == "1" then
			CreatureObject(pPlayer):sendSystemMessage("You are still waiting for your last attack.  If you would like to skip this, please logout and log back in.")
			return
		end
		CreatureObject(pPlayer):sendSystemMessage("You have disabled random attacks. You may be attacked one more time before you can re-enable this feature!")
		writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep", "1")
		return
	else
		writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedLevel", tostring(selectedLevel))
		writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedRange", selectedRange)
		self:showTimeRange(pPlayer)
	end

end

function mission_random_attacks_choice:showTimeRange(pPlayer)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return
	end

	local sui = SuiListBox.new("mission_random_attacks_choice", "timeSelection")

	sui.setTargetNetworkId(SceneObject(pPlayer):getObjectID())

	sui.setTitle("Random Attack Time Selection")

	local promptText = "Use this menu to select a random attack time range."

	sui.setPrompt(promptText)

	for i = 1,  #self.times, 1 do
		sui.add(self.times[i].timeRange, "")
	end

	sui.sendTo(pPlayer)
end

function mission_random_attacks_choice:timeSelection(pPlayer, pSui, eventIndex, args)

	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return 
	end

	if (args == "-1") then
		CreatureObject(pPlayer):sendSystemMessage("No time was selected...")
		return
	end

	local selectedTimeIndex = tonumber(args)+1
	local selectedTime = self.times[selectedTimeIndex].timeSelect
	local selectedTimeRange = self.times[selectedTimeIndex].timeRange
	local selectedRange = readScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedRange")

	writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTime", selectedTime) 
	writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "selectedTimeRange", selectedTimeRange) 
	writeScreenPlayData(pPlayer, "mission_random_attacks_choice", "disableStep", "0")
	
	CreatureObject(pPlayer):sendSystemMessage("You have selected and selected a random attack level of " .. selectedRange .. " every " .. selectedTimeRange)
	
	mission_random_attacks:startStepDelay(pPlayer)
end
