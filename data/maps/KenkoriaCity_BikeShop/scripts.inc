.set LOCALID_OFEK, 2

KenkoriaCity_BikeShop_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, KenkoriaCity_BikeShop_OnLoad
	.byte 0

KenkoriaCity_BikeShop_OnLoad:
	call_if_set FLAG_RECEIVED_BIKE, KenkoriaCity_BikeShop_EventScript_EmptyBike
	end

KenkoriaCity_BikeShop_EventScript_EmptyBike::
	setmetatile 10, 7, METATILE_BikeShop_StandLeft, TRUE
	setmetatile 11, 7, METATILE_BikeShop_StandRight, TRUE
	return

KenkoriaCity_BikeShop_EventScript_Ofek::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, KenkoriaCity_BikeShop_EventScript_EnjoyYourNewBike
	msgbox KenkoriaCity_BikeShop_Text_Greetings, MSGBOX_DEFAULT
	showmoneybox 0, 0
	msgbox KenkoriaCity_BikeShop_Text_BikePrice, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_BikeShop_EventScript_DeclineBuying
	checkmoney 50000
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_BikeShop_EventScript_NotEnoughMoney
	call KenkoriaCity_BikeShop_EventScript_RemoveMoney
	msgbox KenkoriaCity_BikeShop_Text_GladToDoBusinessWithYou, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	switch VAR_FACING
	case DIR_NORTH, KenkoriaCity_BikeShop_EventScript_TalkOfekNorth
	case DIR_EAST, KenkoriaCity_BikeShop_EventScript_TalkOfekEast
	case DIR_WEST, KenkoriaCity_BikeShop_EventScript_TalkOfekWest
	end

KenkoriaCity_BikeShop_EventScript_EnjoyYourNewBike:
	msgbox KenkoriaCity_BikeShop_Text_EnjoyYourNewBike, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_BikeShop_EventScript_TalkOfekWest:
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_BikeShop_Movement_PlayerDownOne
	waitmovement 0
	applymovement LOCALID_OFEK, KenkoriaCity_BikeShop_Movement_OfekGoToBike
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekWest
	waitmovement 0
	goto KenkoriaCity_BikeShop_EventScript_GiveBike
	end

KenkoriaCity_BikeShop_EventScript_TalkOfekEast:
	applymovement LOCALID_OFEK, KenkoriaCity_BikeShop_Movement_OfekGoToBike
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekEast
	waitmovement 0
	goto KenkoriaCity_BikeShop_EventScript_GiveBike

KenkoriaCity_BikeShop_EventScript_TalkOfekNorth:
	applymovement LOCALID_OFEK, KenkoriaCity_BikeShop_Movement_OfekGoToBike
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekNorth
	waitmovement 0
	goto KenkoriaCity_BikeShop_EventScript_GiveBike


KenkoriaCity_BikeShop_EventScript_GiveBike::
	setmetatile 10, 7, METATILE_BikeShop_StandLeft, TRUE
	setmetatile 11, 7, METATILE_BikeShop_StandRight, TRUE
	special DrawWholeMapView
	delay 50
	applymovement LOCALID_OFEK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KenkoriaCity_BikeShop_Text_GiveBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	release
	end

KenkoriaCity_BikeShop_EventScript_DeclineBuying:
	msgbox KenkoriaCity_BikeShop_Text_FineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KenkoriaCity_BikeShop_EventScript_NotEnoughMoney:
	msgbox KenkoriaCity_BikeShop_Text_YouHaventGotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

KenkoriaCity_BikeShop_EventScript_RemoveMoney::
	playse SE_SHOP
	removemoney 50000
	updatemoneybox
	return

KenkoriaCity_BikeShop_EventScript_Woman1::
	msgbox KenkoriaCity_BikeShop_Text_Woman1, MSGBOX_NPC
	end

KenkoriaCity_BikeShop_EventScript_Man5::
	msgbox KenkoriaCity_BikeShop_Text_Man5, MSGBOX_NPC
	end

KenkoriaCity_BikeShop_Movement_OfekGoToBike:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

KenkoriaCity_BikeShop_Movement_PlayerDownOne:
	walk_down
	step_end

KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekWest:
	walk_down
	walk_right
	step_end

KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekEast:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

KenkoriaCity_BikeShop_Movement_PlayerGoesToOfekNorth:
	walk_down
	walk_right
	walk_right
	step_end

KenkoriaCity_BikeShop_Text_Greetings:
	.string "Greetings trainer.\n"
	.string "Welcome to my Bike Shop.\p"
	.string "I'm OFEK, I own this store.\n"
	.string "I sell Bicycles to trainers.\p"
	.string "Since there's only one bike store,\n"
	.string "My prices are a bit… … pricey.$"

KenkoriaCity_BikeShop_Text_BikePrice:
	.string "I'll give you a brand new Bicycle for\n"
	.string "¥50,000, free of taxes. What do you say?$"

KenkoriaCity_BikeShop_Text_YouHaventGotEnoughMoney:
	.string "It seems you are short on cash.\n"
	.string "Come back to me when you are serious.$"

KenkoriaCity_BikeShop_Text_FineThen:
	.string "Fine then, stop wasting my time.$"

KenkoriaCity_BikeShop_Text_GladToDoBusinessWithYou:
	.string "I'm glad to do business with you.\n"
	.string "Let me grab your new Bike.$"

KenkoriaCity_BikeShop_Text_GiveBike:
	.string "Here's your new bicycle.\n"
	.string "Enjoy!$"

KenkoriaCity_BikeShop_Text_EnjoyYourNewBike:
	.string "Enjoy your new bike.$"

KenkoriaCity_BikeShop_Text_Woman1:
	.string "Which bicycle should I get?$"

KenkoriaCity_BikeShop_Text_Man5:
	.string "I ordered a snowboard from PINPOINT CITY.\n"
	.string "The package got delayed. Hmmmm… … …$"
