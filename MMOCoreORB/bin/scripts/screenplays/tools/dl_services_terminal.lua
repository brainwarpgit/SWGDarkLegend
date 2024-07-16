swgdl_buff_terminal = ScreenPlay:new {
	numberOfActs = 1,
	healingFee = 0, -- Optional fee (in Credits) for healing wounds and battle fatigue
	woundFee = 0,
	resetFee = 0,
	--buffPets = 0, -- 0 = No, 1 = Yes. Will buff all the player's active pets Health/Action/Mind with the same boost as the player.
	--buffPetSecondaryStats = 0, -- 0 = No, 1 = Yes. Will also buff the pet's secondary stats.
	--buffs = {
	--	-- Legend: {name, price, duration in hours, health, strength, constitution, action, quickness, stamina, mind, focus, willpower},
	--	{"Starter Buff", 0, 2, 650, 650, 650, 650, 650, 650, 650, 650, 650},
	--	{"Basic Buff", 5000, 2, 800, 800, 800, 850, 800, 800, 800, 800, 800},
	--	{"Advanced Buff", 10000, 3, 1200, 800, 800, 1200, 800, 800, 1000, 800, 800},
	--	{"Apply Uber Buff", 25000, 4, 2200, 2000, 2000, 2200, 2000, 2000, 1300, 1000, 1000},
	--},
	termModel = "object/tangible/terminal/terminal_hq.iff",
	termName = "Dark Legend Services",
	terminals = {
		--Corellia
		{planetName = "corellia", x = -133.171, z = 28, y = -4711.01, ow = 0.76604, oy = -0.64279}, --Coronet Starport -V
		{planetName = "corellia", x = -5049.64, z = 21, y = -2304.52, ow = 0.937972, oy = 0.346712},  --Tyrena Starport -V
		{planetName = "corellia", x = 3330.38, z = 308, y = 5517.14, ow = 0.956783, oy = 0.290803}, --Doaba Guerfel Starport -V
		{planetName = "corellia", x = -3128.1, z = 31, y = 2809.5, ow = -0.0561584, oy = 0.998422}, --Kor Vella Starport -V
		{planetName = "corellia", x = -5564.29, z = 16.4893, y = -6054.59, ow = 0, oy = 1}, --Vreni Island Shuttleport -V
		{planetName = "corellia", x = 6938.57, z = 330.6, y = -5523.72, ow = 0.76604, oy = -0.64279}, --Bela Vistal Shuttleport B -V

		--Dantooine
		{planetName = "dantooine", x = 1585.28, z = 4, y = -6410.5, ow = 1, oy = 0}, --Pirate Outpost -V
		{planetName = "dantooine", x = -642.454, z = 3, y = 2491.93, ow = 0.38268, oy = 0.92388}, --Mining Outpost -V
		{planetName = "dantooine", x = -4224.39, z = 3, y = -2355.5, ow = 0, oy = 1}, --Imperial Outpost -V

		--Dathomir
		{planetName = "dathomir", x = 602.798, z = 6, y = 3095.56, ow = 0.25882, oy = -0.96593}, --Trade Outpost -V
		{planetName = "dathomir", x = -67.9026, z = 18, y = -1595.55, ow = 0.949123, oy = 0.314904}, --Science Outpost -V

		--Endor
		{planetName = "endor", x = -962.85, z = 73, y = 1557.51, ow = -0.360002, oy = 0.932952}, --Smuggler's Outpost -V
		{planetName = "endor", x = 3213.87, z = 24, y = -3494.5, ow = 1, oy = 0}, --Research Outpost -V

		--Lok
		{planetName = "lok", x = 464.677, z = 8.75806, y = 5506.49, ow = 0, oy = -1}, --Nym's Starport -X

		--Naboo
		{planetName = "naboo", x = 4803.7, z = 4.17, y = -4687.95, ow = 0.50000, oy = 0.86603}, --Moenia Starport -V
		{planetName = "naboo", x = -4860.75, z = 6.48, y = 4179.6, ow = 0.38268, oy = -0.92388}, --Theed Starport -V
		{planetName = "naboo", x = 5193.14, z = -192, y = 6680.25, ow = 0.999932, oy = -0.0116238}, --Kaadara Starport -V
		{planetName = "naboo", x = 1442.71, z = 13, y = 2782.55, ow = 0.64279, oy = -0.76604}, --Keren Starport -V
		{planetName = "naboo", x = -5489.12, z = -149.4, y = -9.02252, ow = 0.70711, oy = -0.70711}, --Lake Retreat Shuttleport -V
		{planetName = "naboo", x = 5337.31, z = 327.626, y = -1563.87, ow = 0.70711, oy = -0.70711}, --Dee'ja Peak Shuttleport -V

		--Rori
		{planetName = "rori", x = -5307.37, z = 80.1274, y = -2216.91, ow = 0.38268, oy = -0.92388}, --Narmle Starport -V
		{planetName = "rori", x = 5370.22, z = 80, y = 5666.04, ow = 0.721974, oy = -0.69192}, --Restuss Starport -V
		{planetName = "rori", x = 3676.29, z = 96, y = -6408.7, ow = 0, oy = -1}, --Rebel Outpost -V
		
		--Talus
		{planetName = "talus", x = 4447.08, z = 2, y = 5286.96, ow = 0.13053, oy = -0.99144}, -- Nashal Starport -V
		{planetName = "talus", x = 329.666, z = 6, y = -2924.69, ow = 0.70711, oy = 0.70711}, --Dearic Starport -V
		{planetName = "talus", x = -2224.26, z = 20, y = 2306.25, ow = 0.721282, oy = 0.692641}, --Imperial Outpost -V

		--Tatooine
		{planetName = "tatooine", x = 1280.28, z = 7, y = 3135.46, ow = 0.96593, oy = 0.25882}, -- Mos Entha Starport -V
		{planetName = "tatooine", x = 3534.38, z = 5, y = -4793.89, ow = 0.70711, oy = -0.70711}, -- Mos Eisley Starport -V
		{planetName = "tatooine", x = 41.6126, z = 52, y = -5352.57, ow = 0.99905, oy = 0.04362}, -- Anchorhead Shuttleport -V
		{planetName = "tatooine", x = -1271.98, z = 12, y = -3592.48, ow = 0.92388, oy = -0.38268}, -- Bestine Starport -V
		{planetName = "tatooine", x = -2904.34, z = 5, y = 2118.23, ow = 0.90631, oy = -0.42262}, -- Mos Espa Starport -V
		
		--Yavin4
		{planetName = "yavin4", x = -6926.93, z = 73, y = -5710.85, ow = 0.708587, oy = -0.705623}, --Labor Outpost -V
		{planetName = "yavin4", x = -277.785, z = 35, y = 4891.04, ow = 0, oy = -1}, --Mining Outpost -V
		{planetName = "yavin4", x = 4037.18, z = 37, y = -6221.91, ow = 0, oy = -1}, -- Imperial Outpost -V
	}
}

registerScreenPlay("swgdl_buff_terminal", true)

function swgdl_buff_terminal:start()
	-- Spawn terminals
	for i = 1, #self.terminals, 1 do
		local pTerminal = spawnSceneObject(self.terminals[i].planetName, self.termModel , self.terminals[i].x, self.terminals[i].z, self.terminals[i].y, 0, self.terminals[i].ow, 0, self.terminals[i].oy, 0)
		if (pTerminal ~= nil) then
			-- Add menu and custom name
			SceneObject(pTerminal):setObjectMenuComponent("swgdl_buff_terminal_menu_component")
			SceneObject(pTerminal):setCustomObjectName(self.termName)
		end
	end
end


-- UI Window Functions

function swgdl_buff_terminal:openWindow(pCreatureObject, pUsingObject)
	local sui = SuiListBox.new("swgdl_buff_terminal", "defaultCallback")

	-- Using object ID, stored in PageData
	if (pUsingObject == nil) then
		sui.setTargetNetworkId(0)
	else
		sui.setTargetNetworkId(SceneObject(pUsingObject):getObjectID())
	end

	sui.setForceCloseDistance(16)

	sui.setTitle("Medical Terminal")
	
	local message = "Please select a service below." -- \n\nNotice: \nAll current buffs (of all types) will be removed when purchasing a buff from this terminal. Therefore, you should save your consumable buffs for after you've purchased a terminal buff."
	
	--if (self.buffPets == 1) then
	--	message = message .. "\n\nAll of your currently active pets will also recieve a buff to their "
	--	
	--	if (self.buffPetSecondaryStats == 1) then 
	--		message = message .. "primary and secondary stats."
	--	else 
	--		message = message .. "primary stats."
	--	end
	--else
	--	message = message .. "\n\nNo buffs will be applied to your pets."
	--end
	
	sui.setPrompt(message)

	--sui.add("Remove My Buffs and Empty My Stomach", "")
	--sui.add("Remove Buffs from My Active Pets", "")
	
	local healMessage = "Heal My Wounds and Battle Fatigue"
	
	if (self.healingFee > 0) then
		healMessage = healMessage .. " (" .. tostring(self.healingFee) .. "cr)"
	end
	
	sui.add(healMessage, "")

	local woundMessage = "Full Wounds and Fatigue"
	
	if (self.woundFee > 0) then
		woundMessage = healMessage .. " (" .. tostring(self.woundFee) .. "cr)"
	end
	
	sui.add(woundMessage, "")
--for i = 1, #self.buffs, 1 do
	--	sui.add("Apply " .. self.buffs[i][1] .. " (" .. tostring(self.buffs[i][2]) .. "cr/" .. tostring(self.buffs[i][3]) .. "h)", "")
	--end

	local resetMessage = "Reset Buffs"
	
	if (self.resetFee > 0) then
		resetMessage = resetMessage .. " (" .. tostring(self.resetFee) .. "cr)"
	end
	
	sui.add(resetMessage, "")
	
	sui.sendTo(pCreatureObject)
end

function swgdl_buff_terminal:defaultCallback(pPlayer, pSui, eventIndex, args)
	local cancelPressed = (eventIndex == 1)

	if (cancelPressed) then
		return
	end

	if (args == "-1") then
		CreatureObject(pPlayer):sendSystemMessage("No option was selected, please try again.")
		return
	end

	local selectedOption = tonumber(args) + 1
	
	if (selectedOption == 1) then
	--	self:removePlayerBuffs(pPlayer)
	--elseif (selectedOption == 2) then
	--	self:removePetBuffs(pPlayer)
	--elseif (selectedOption == 3) then
		self:healWounds(pPlayer)
	--elseif (selectedOption > 3) then
	--	self:applyBuff(pPlayer, selectedOption - 3) -- The -3 is to compensate for the first four entries in the menu
	elseif (selectedOption == 2) then
		self:woundWounds(pPlayer)
	elseif (selectedOption == 3) then
		self:removePlayerBuffs(pPlayer)
	end
end


-- Buff Functions

function swgdl_buff_terminal:removePlayerBuffs(pPlayer)
	CreatureObject(pPlayer):removeBuffs()
	CreatureObject(pPlayer):emptyStomach()
	CreatureObject(pPlayer):sendSystemMessage("Your buffs have been removed and your stomach is now empty.")
end

function swgdl_buff_terminal:removePetBuffs(pPlayer)
	local numberOfPets = CreatureObject(pPlayer):getActivePetsSize()
		
	if (numberOfPets > 0) then
		for i = 1, numberOfPets, 1 do
			local pPet = CreatureObject(pPlayer):getActivePet(i - 1)
			CreatureObject(pPet):removeBuffs()
		end
		
		CreatureObject(pPlayer):sendSystemMessage("Your pet's buffs have been removed.")
	else
		CreatureObject(pPlayer):sendSystemMessage("You didn't have any pets out, so no buffs were removed. Please call a pet and try again.")
	end
end

function swgdl_buff_terminal:healWounds(pPlayer)
	local price = self.healingFee

	if (price > 0) then
		local playerCash = CreatureObject(pPlayer):getCashCredits()
		local playerBank = CreatureObject(pPlayer):getBankCredits()

		if (playerCash + playerBank < price) then
			CreatureObject(pPlayer):sendSystemMessage("Insufficient Funds: You require " .. tostring(self.healingFee) .. " credits in cash to use the healing service.")
			return
		end
		
		if (playerCash > price) then
			CreatureObject(pPlayer):subtractCashCredits(price)
		else
			local diff = price - playerCash
			CreatureObject(pPlayer):subtractCashCredits(playerCash)
			CreatureObject(pPlayer):setBankCredits(playerBank-diff)
		end		
	end

	for i = 0, 8 do
		CreatureObject(pPlayer):setWounds(i, 0)
	end
	
	CreatureObject(pPlayer):setShockWounds(0)
	CreatureObject(pPlayer):sendSystemMessage("Your wounds have been healed and your mind is at ease.")
end

function swgdl_buff_terminal:woundWounds(pPlayer)
	local price = self.woundFee

	if (price > 0) then
		local playerCash = CreatureObject(pPlayer):getCashCredits()
		local playerBank = CreatureObject(pPlayer):getBankCredits()

		if (playerCash + playerBank < price) then
			CreatureObject(pPlayer):sendSystemMessage("Insufficient Funds: You require " .. tostring(self.woundFee) .. " credits in cash to use the wounding service.")
			return
		end
		
		if (playerCash > price) then
			CreatureObject(pPlayer):subtractCashCredits(price)
		else
			local diff = price - playerCash
			CreatureObject(pPlayer):subtractCashCredits(playerCash)
			CreatureObject(pPlayer):setBankCredits(playerBank-diff)
		end		
	end

	for i = 0, 8 do
		CreatureObject(pPlayer):setWounds(i, 5000)
	end
	
	CreatureObject(pPlayer):setShockWounds(1000)
	CreatureObject(pPlayer):sendSystemMessage("You have been wounded and your mind is a wreck.")
end

function swgdl_buff_terminal:applyBuff(pPlayer, buffSelected)
	local duration = self.buffs[buffSelected][3] * 60  * 60
	local price = self.buffs[buffSelected][2]
	
	if (price > 0)then
		local playerCash = CreatureObject(pPlayer):getCashCredits()
		local playerBank = CreatureObject(pPlayer):getBankCredits()

		if (playerCash + playerBank < price) then
			CreatureObject(pPlayer):sendSystemMessage("Insufficient Funds: You require " .. tostring(self.healingFee) .. " credits in cash to use the healing service.")
			return
		end
		
		if (playerCash > price) then
			CreatureObject(pPlayer):subtractCashCredits(price)
		else
			local diff = price - playerCash
			CreatureObject(pPlayer):subtractCashCredits(playerCash)
			CreatureObject(pPlayer):setBankCredits(playerBank-diff)
		end	
	end
	
	CreatureObject(pPlayer):removeBuffs()
	CreatureObject(pPlayer):emptyStomach()
	
	CreatureObject(pPlayer):buffSingleStat("health", self.buffs[buffSelected][4], duration)
	CreatureObject(pPlayer):buffSingleStat("strength", self.buffs[buffSelected][5], duration)
	CreatureObject(pPlayer):buffSingleStat("constitution", self.buffs[buffSelected][6], duration)
	CreatureObject(pPlayer):buffSingleStat("action", self.buffs[buffSelected][7], duration)
	CreatureObject(pPlayer):buffSingleStat("quickness", self.buffs[buffSelected][8], duration)
	CreatureObject(pPlayer):buffSingleStat("stamina", self.buffs[buffSelected][9], duration)
	CreatureObject(pPlayer):buffSingleStat("mind", self.buffs[buffSelected][10], duration)
	CreatureObject(pPlayer):buffSingleStat("focus", self.buffs[buffSelected][11], duration)
	CreatureObject(pPlayer):buffSingleStat("willpower", self.buffs[buffSelected][12], duration)
	
	CreatureObject(pPlayer):sendSystemMessage("Your buffs have been applied. They will last for " .. tostring(self.buffs[buffSelected][3]) .. " hours.")
	
	if (self.buffPets == 1) then
		local numberOfPets = CreatureObject(pPlayer):getActivePetsSize()
		
		if (numberOfPets > 0) then
			for i = 1, numberOfPets, 1 do
				local pPet = CreatureObject(pPlayer):getActivePet(i - 1)
				
				CreatureObject(pPet):removeBuffs()
		
				CreatureObject(pPet):buffSingleStat("health", self.buffs[buffSelected][4], duration)
				CreatureObject(pPet):buffSingleStat("action", self.buffs[buffSelected][7], duration)
				CreatureObject(pPet):buffSingleStat("mind", self.buffs[buffSelected][10], duration)
				
				if (self.buffPetSecondaryStats == 1) then
					CreatureObject(pPet):buffSingleStat("strength", self.buffs[buffSelected][5], duration)
					CreatureObject(pPet):buffSingleStat("constitution", self.buffs[buffSelected][6], duration)
					CreatureObject(pPet):buffSingleStat("quickness", self.buffs[buffSelected][8], duration)
					CreatureObject(pPet):buffSingleStat("stamina", self.buffs[buffSelected][9], duration)
					CreatureObject(pPet):buffSingleStat("focus", self.buffs[buffSelected][11], duration)
					CreatureObject(pPet):buffSingleStat("willpower", self.buffs[buffSelected][12], duration)
				end
			end
			
			CreatureObject(pPlayer):sendSystemMessage("Your active pets have also been buffed.")
		end
	end
end


-- Radial Menu Functions

swgdl_buff_terminal_menu_component = { }

function swgdl_buff_terminal_menu_component:fillObjectMenuResponse(pSceneObject, pMenuResponse, pPlayer)
	local menuResponse = LuaObjectMenuResponse(pMenuResponse)
	menuResponse:addRadialMenuItem(20, 3, "Use Terminal")
	--menuResponse:addRadialMenuItem(120, 3, "About Buffs")
end

function swgdl_buff_terminal_menu_component:handleObjectMenuSelect(pObject, pPlayer, selectedID)
	if (pPlayer == nil or pObject == nil) then
		return 0
	end
	
	if CreatureObject(pPlayer):isInCombat() then
		CreatureObject(pPlayer):sendSystemMessage("Terminal services are not available while you are in combat.")
		return 0
	end
	
	if (selectedID == 20) then
		swgdl_buff_terminal:openWindow(pPlayer, pObject)
	elseif (selectedID == 120) then
		local suiManager = LuaSuiManager()
		local helpMessage = "This window shows the stats that are increased for each buff type, as well as their price and duration.\n\n"
		
		for i = 1, #swgdl_buff_terminal.buffs, 1 do
			helpMessage = helpMessage .. swgdl_buff_terminal.buffs[i][1] .. " (" .. tostring(swgdl_buff_terminal.buffs[i][2]) .. "cr/" .. tostring(swgdl_buff_terminal.buffs[i][3]) .. "h):\n" -- BuffName (1234cr/2h):
			helpMessage = helpMessage .. "- - - - - - - - - - - - -\n"
			helpMessage = helpMessage .. "Health: " .. swgdl_buff_terminal.buffs[i][4] .. "\n"
			helpMessage = helpMessage .. "Strength: " .. swgdl_buff_terminal.buffs[i][5] .. "\n"
			helpMessage = helpMessage .. "Constitution: " .. swgdl_buff_terminal.buffs[i][6] .. "\n"
			helpMessage = helpMessage .. "Action: " .. swgdl_buff_terminal.buffs[i][7] .. "\n"
			helpMessage = helpMessage .. "Quickness: " .. swgdl_buff_terminal.buffs[i][8] .. "\n"
			helpMessage = helpMessage .. "Stamina: " .. swgdl_buff_terminal.buffs[i][9] .. "\n"
			helpMessage = helpMessage .. "Mind: " .. swgdl_buff_terminal.buffs[i][10] .. "\n"
			helpMessage = helpMessage .. "Focus: " .. swgdl_buff_terminal.buffs[i][11] .. "\n"
			helpMessage = helpMessage .. "Willpower: " .. swgdl_buff_terminal.buffs[i][12] .. "\n\n"
		end
		
		suiManager:sendMessageBox(pObject, pPlayer, "About Buffs", helpMessage, "@ok", "swgdl_buff_terminal_menu_component", "noCallback")
	end 
	
	return 0
end

function swgdl_buff_terminal_menu_component:noCallback(pPlayer, pSui, eventIndex)
	-- do nothing
end
