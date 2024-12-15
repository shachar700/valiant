.equ LOCALID_SAILOR_CITY, 5
.equ LOCALID_SAILOR_SEA, 1
.equ LOCALID_BOAT_CITY, 21
.equ LOCALID_BOAT_SEA, 2

KenkoriaCity_MapScripts::
	.byte 0

KenkoriaCity_EventScript_BikeShopSign::
	msgbox KenkoriaCity_Text_BikeShopSign, MSGBOX_SIGN
	end

KenkoriaCity_EventScript_GymSign::
	msgbox KenkoriaCity_Text_GymSign, MSGBOX_SIGN
	end

KenkoriaCity_EventScript_CitySign::
	msgbox KenkoriaCity_Text_CitySign, MSGBOX_SIGN
	end

KenkoriaCity_EventScript_BikeGirl::
	msgbox KenkoriaCity_Text_BikeGirl, MSGBOX_NPC
	end

KenkoriaCity_EventScript_BikeBoy::
	msgbox KenkoriaCity_Text_BikeBoy, MSGBOX_NPC
	end

KenkoriaCity_EventScript_Elder::
	msgbox KenkoriaCity_Text_Elder, MSGBOX_NPC
	end

KenkoriaCity_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox KenkoriaCity_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

KenkoriaCity_EventScript_Beauty::
	msgbox KenkoriaCity_Text_Beauty, MSGBOX_NPC
	end

KenkoriaCity_EventScript_Boy2::
	msgbox KenkoriaCity_Text_Boy2, MSGBOX_NPC
	end

KenkoriaCity_EventScript_SalesMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, KenkoriaCity_EventScript_HappyGamba
	msgbox KenkoriaCity_Text_LikeToGamble, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_EventScript_DeclineSalesMan
	msgbox KenkoriaCity_Text_MeToo, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	waitmessage
	msgbox KenkoriaCity_Text_CheckGameCorner, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_EventScript_HappyGamba:
	msgbox KenkoriaCity_Text_HappyGamba, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_EventScript_DeclineSalesMan:
	msgbox KenkoriaCity_Text_DeclineSalesMan, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_EventScript_Sailor::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox KenkoriaCity_Text_SafariVisit5000, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_EventScript_DeclineSafariVisit
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_EventScript_NotEnoughMoney
	call KenkoriaCity_EventScript_RemoveMoney
	msgbox KenkoriaCity_Text_HereWeGo, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	@round trip to safari
	call KenkoriaCity_EventScript_StartSailToSafari
	msgbox KenkoriaSea_Text_WeHaveArrived, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_EventScript_NotEnoughMoney::
	msgbox KenkoriaCity_Text_YouHaventGotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KenkoriaCity_EventScript_DeclineSafariVisit::
	msgbox KenkoriaCity_Text_AlrightThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KenkoriaCity_EventScript_RemoveMoney::
	playse SE_SHOP
	removemoney 5000
	updatemoneybox
	return

KenkoriaCity_EventScript_StartSailToSafari::
	copyvar VAR_0x8008, VAR_SAILOR_LOCATION
	setvar VAR_SAILOR_LOCATION, 0
	setobjectsubpriority LOCALID_SAILOR_CITY, MAP_KENKORIA_CITY, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_CITY, 0
	applymovement LOCALID_SAILOR_CITY, KenkoriaCity_Movement_SailorBoardBoat
	waitmovement 0
	removeobject LOCALID_SAILOR_CITY
	switch VAR_FACING
	case DIR_NORTH, KenkoriaCity_EventScript_EnterBoatNorth
	case DIR_EAST, KenkoriaSea_EventScript_EnterBoatEast
	end

KenkoriaCity_EventScript_EnterBoatNorth:
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_Movement_PlayerEnterBoatNorth
	waitmovement 0
	call KenkoriaCity_EventScript_SailToSafari
	return

KenkoriaSea_EventScript_EnterBoatEast:
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_Movement_PlayerEnterBoatEast
	waitmovement 0
	call KenkoriaCity_EventScript_SailToSafari
	return

KenkoriaCity_EventScript_SailToSafari::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_CITY
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_CITY, KenkoriaCity_Movement_SailToSafari
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_Movement_SailToSafari
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_SEA
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_Movement_ExitBoatSafari
	waitmovement 0
	setobjectxyperm LOCALID_SAILOR_SEA, 61, 36
	addobject LOCALID_SAILOR_SEA
	setobjectsubpriority LOCALID_SAILOR_SEA, MAP_KENKORIA_SEA, 0
	applymovement LOCALID_SAILOR_SEA, KenkoriaCity_Movement_SailorExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_SAILOR_KENKORIA_SEA
	addobject LOCALID_BOAT_SEA
	clearflag FLAG_HIDE_SAILOR_BOAT_KENKORIA_SEA
	setflag FLAG_HIDE_SAILOR_BOAT_KENKORIA_CITY
	hideobjectat LOCALID_BOAT_CITY, MAP_KENKORIA_CITY
	copyvar VAR_SAILOR_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_CITY
	resetobjectsubpriority LOCALID_SAILOR_SEA, MAP_KENKORIA_SEA
	copyobjectxytoperm LOCALID_SAILOR_SEA
	return

KenkoriaCity_Movement_SailorBoardBoat:
	walk_up
	step_end

KenkoriaCity_Movement_PlayerEnterBoatNorth:
	walk_up
	walk_up
	step_end

KenkoriaCity_Movement_PlayerEnterBoatEast:
	walk_right
	walk_up
	step_end

KenkoriaCity_Movement_SailToSafari:
	walk_up
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

KenkoriaCity_Movement_ExitBoatSafari:
	walk_down
	walk_right
	face_left
	step_end

KenkoriaCity_Movement_SailorExitBoat:
	walk_down
	face_right
	step_end


KenkoriaCity_Text_SafariVisit5000:
	.string "I can give you a round-trip ride to\n"
	.string "KENKORIA's SAFARI ZONE for ¥5000.$"

KenkoriaCity_Text_YouHaventGotEnoughMoney:
	.string "You don't have enough money.$"

KenkoriaCity_Text_AlrightThen:
	.string "Alright then.$"

KenkoriaCity_Text_HereWeGo:
	.string "Here we go.$"

KenkoriaSea_Text_WeHaveArrived:
	.string "We have arrived.\n"
	.string "Let me know when you want to go back.$"

KenkoriaCity_Text_SailorLandedInKenkoriaCity:
	.string "We are back in KENKORIA CITY.\n"
	.string "Let me know when you wanna sail again.$"

KenkoriaCity_Text_BikeShopSign:
	.string "KENKORIA CITY Bike Shop\n"
	.string "“Get your new shiny bicycle today!”$"

KenkoriaCity_Text_GymSign:
	.string "KENKORIA CITY Gym\n"
	.string "“Bring your Wailmer Pail with you.”$"

KenkoriaCity_Text_CitySign:
	.string "KENKORIA CITY\n"
	.string "A city on the WEST of KENKORIA SEA.$"

KenkoriaCity_Text_BikeGirl:
	.string "Welcome to KENKORIA CITY!\n"
	.string "In here you can obtain a bicycle.$"

KenkoriaCity_Text_BikeBoy:
	.string "KENKORIA CITY has a lot to offer in\n"
	.string "terms of supplies.\p"
	.string "You should stack on some items from\n"
	.string "the mart.$"

KenkoriaCity_Text_Elder:
	.string "I like to come sit here and watch the sea\n"
	.string "from the bench.\p"
	.string "It's nice to relax and take it easy from\n"
	.string "time to time.$"

KenkoriaCity_Text_Zigzagoon:
	.string "Zig zig$"

KenkoriaCity_Text_Beauty:
	.string "KENKORIA CITY Gym has a lot of women in it.\p"
	.string "They are all there to make sure the\n"
	.string "flowers grow as beautiful as they can be.\p"
	.string "We are looking for CELEBI to visit so that\n"
	.string "the plants will flourish.$"

KenkoriaCity_Text_Boy2:
	.string "There's a rumor about a trainer that came\n"
	.string "from KENKORIA CITY.\p"
	.string "They travelled to the woods to find\n"
	.string "CELEBI to learn about its mysteries.\p"
	.string "Rumor says the trainer got sucked into\n"
	.string "a wormhole and never came back.\p"
	.string "Now that's a scary tail.$"

KenkoriaCity_Text_LikeToGamble:
	.string "Hey pal, do you like to gamble?$"

KenkoriaCity_Text_DeclineSalesMan:
	.string "That's unfortunate.$"

KenkoriaCity_Text_MeToo:
	.string "Me too. We are best of buddies.\p"
	.string "Since I like you so much, I'd like you to\n"
	.string "have this COIN CASE.$"

KenkoriaCity_Text_CheckGameCorner:
	.string "It will keep your coins in check.\p"
	.string "Speaking of in check, how about you\n"
	.string "check our lovely game corner?$"

KenkoriaCity_Text_HappyGamba:
	.string "Happy gambling. Visit our game corner.\n"
	.string "May the odds be ever in your favor,\l"
	.string "and in your pocket.$"
