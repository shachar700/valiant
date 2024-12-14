KenkoriaCity_GameCorner_MapScripts::
	.byte 0

@ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

KenkoriaCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NeedCoinCase
	message KenkoriaCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto KenkoriaCity_GameCorner_EventScript_ChooseCoinsDefault50

KenkoriaCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, KenkoriaCity_GameCorner_EventScript_Buy50Coins
	case 1, KenkoriaCity_GameCorner_EventScript_Buy500Coins
	goto KenkoriaCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
KenkoriaCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, KenkoriaCity_GameCorner_EventScript_Buy50Coins
	case 1, KenkoriaCity_GameCorner_EventScript_Buy500Coins
	goto KenkoriaCity_GameCorner_EventScript_CancelBuyCoins
	end

KenkoriaCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), KenkoriaCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

KenkoriaCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), KenkoriaCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

KenkoriaCity_GameCorner_EventScript_NeedCoinCase::
	msgbox KenkoriaCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox KenkoriaCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

KenkoriaCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox KenkoriaCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

KenkoriaCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox KenkoriaCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

KenkoriaCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, KenkoriaCity_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

KenkoriaCity_GameCorner_EventScript_ChooseTMPrizeMessage::
	message KenkoriaCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto KenkoriaCity_GameCorner_EventScript_ChooseTMPrize

KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize::
	message KenkoriaCity_GameCorner_Text_WhichPrize
	waitmessage
	goto KenkoriaCity_GameCorner_EventScript_ChooseTMPrize

KenkoriaCity_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, KenkoriaCity_GameCorner_EventScript_TMDoubleTeam
	case 1, KenkoriaCity_GameCorner_EventScript_TMPsychic
	case 2, KenkoriaCity_GameCorner_EventScript_TMFlamethrower
	case 3, KenkoriaCity_GameCorner_EventScript_TMThunderbolt
	case 4, KenkoriaCity_GameCorner_EventScript_TMIceBeam
	case 5, KenkoriaCity_GameCorner_EventScript_CancelTMSelect
	goto KenkoriaCity_GameCorner_EventScript_CancelTMSelect
	end

KenkoriaCity_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize

KenkoriaCity_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize

KenkoriaCity_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize

KenkoriaCity_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize

KenkoriaCity_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_ICE_BEAM
	setvar VAR_0x8004, ITEM_TM_ICE_BEAM
	goto KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize

KenkoriaCity_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox KenkoriaCity_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_GameCorner_EventScript_CancelTMSelect
	switch VAR_TEMP_1
	case 1, KenkoriaCity_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, KenkoriaCity_GameCorner_EventScript_BuyTMPsychic
	case 3, KenkoriaCity_GameCorner_EventScript_BuyTMFlamethrower
	case 4, KenkoriaCity_GameCorner_EventScript_BuyTMThunderbolt
	case 5, KenkoriaCity_GameCorner_EventScript_BuyTMIceBeam
	end

KenkoriaCity_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_ICE_BEAM
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_ICE_BEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox KenkoriaCity_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox KenkoriaCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto KenkoriaCity_GameCorner_EventScript_ReturnToChooseTMPrize
	end

KenkoriaCity_GameCorner_EventScript_CancelTMSelect::
	msgbox KenkoriaCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

KenkoriaCity_GameCorner_EventScript_Woman3::
	msgbox KenkoriaCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

KenkoriaCity_GameCorner_EventScript_Gentleman::
	msgbox KenkoriaCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

KenkoriaCity_GameCorner_EventScript_Hiker::
	msgbox KenkoriaCity_GameCorner_Text_MachineSwallowMyCoins, MSGBOX_NPC
	end


KenkoriaCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, KenkoriaCity_GameCorner_EventScript_TryGive20Coins
	msgbox KenkoriaCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, KenkoriaCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, KenkoriaCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox KenkoriaCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto KenkoriaCity_GameCorner_EventScript_PokefanMNormal
	end

KenkoriaCity_GameCorner_EventScript_PokefanMNormal::
	msgbox KenkoriaCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_OldMan2::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_Camper::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_OldWoman::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

KenkoriaCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_Artist::
	lock
	faceplayer
	msgbox KenkoriaCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto KenkoriaCity_GameCorner_EventScript_NPCReturnToSlots
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

KenkoriaCity_GameCorner_EventScript_NoCoinCase::
	msgbox KenkoriaCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

KenkoriaCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is MAUVILLE GAME CORNER.$"

KenkoriaCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

KenkoriaCity_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

KenkoriaCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

KenkoriaCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

KenkoriaCity_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

KenkoriaCity_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

KenkoriaCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

KenkoriaCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

KenkoriaCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

KenkoriaCity_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

KenkoriaCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

@ Unused
KenkoriaCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

KenkoriaCity_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

KenkoriaCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

KenkoriaCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
KenkoriaCity_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

KenkoriaCity_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

KenkoriaCity_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

KenkoriaCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

KenkoriaCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "I think the salesman outdoor\n"
	.string "had one. Go see him!$"

KenkoriaCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

KenkoriaCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "MAUVILLE has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

KenkoriaCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to\n"
	.string "pick a table.$"

KenkoriaCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

KenkoriaCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

KenkoriaCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

KenkoriaCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

KenkoriaCity_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

KenkoriaCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

KenkoriaCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"

KenkoriaCity_GameCorner_Text_MachineSwallowMyCoins:
	.string "The machine swallowed my coins.\n"
	.string "This is infuriating.$"
