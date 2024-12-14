KenkoriaSea_MapScripts::
	.byte 0

KenkoriaSea_EventScript_Sailor::
	lock
	faceplayer
	msgbox KenkoriaSea_Text_GoBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaSea_EventScript_DeclineToSail
	msgbox KenkoriaSea_Text_LetsGo, MSGBOX_DEFAULT
	closemessage
	goto KenkoriaSea_EventScript_StartSailToCity
	end

KenkoriaSea_EventScript_DeclineToSail::
	msgbox KenkoriaSea_Text_TellMeWhenYouWantToGoBack, MSGBOX_DEFAULT
	release
	end

KenkoriaSea_EventScript_StartSailToCity::
	copyvar VAR_0x8008, VAR_SAILOR_LOCATION
	setvar VAR_SAILOR_LOCATION, 0
	setobjectsubpriority LOCALID_SAILOR_SEA, MAP_KENKORIA_SEA, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_SEA, 0
	applymovement LOCALID_SAILOR_SEA, KenkoriaSea_Movement_SailorEnterBoat
	waitmovement 0
	removeobject LOCALID_SAILOR_SEA
	switch VAR_FACING
	case DIR_NORTH, KenkoriaSea_EventScript_EnterBoatNorth
	case DIR_WEST, KenkoriaSea_EventScript_EnterBoatWest
	end

KenkoriaSea_EventScript_EnterBoatNorth::
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaSea_Movement_PlayerEnterBoatNorth
	waitmovement 0
	goto KenkoriaSea_EventScript_DoSailToCity
	end

KenkoriaSea_EventScript_EnterBoatWest::
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaSea_Movement_PlayerEnterBoatWest
	waitmovement 0
	goto KenkoriaSea_EventScript_DoSailToCity
	end

KenkoriaSea_EventScript_DoSailToCity::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_SEA
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_SEA, KenkoriaSea_Movement_SailToCity
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaSea_Movement_SailToCity
	waitmovement 0
	delay 50
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_CITY
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaSea_Movement_PlayerExitBoat
	waitmovement 0
	addobject LOCALID_BOAT_CITY
	clearflag FLAG_HIDE_SAILOR_BOAT_KENKORIA_CITY
	setobjectxyperm LOCALID_SAILOR_CITY, 39, 26
	addobject LOCALID_SAILOR_CITY
	setobjectsubpriority LOCALID_SAILOR_CITY, MAP_KENKORIA_CITY, 0
	applymovement LOCALID_SAILOR_CITY, KenkoriaSea_Movement_SailorExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_SAILOR_KENKORIA_CITY
	setflag FLAG_HIDE_SAILOR_BOAT_KENKORIA_SEA
	hideobjectat LOCALID_BOAT_SEA, MAP_KENKORIA_SEA
	msgbox KenkoriaCity_Text_SailorLandedInKenkoriaCity, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_SAILOR_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_KENKORIA_SEA
	resetobjectsubpriority LOCALID_SAILOR_CITY, MAP_KENKORIA_CITY
	copyobjectxytoperm LOCALID_SAILOR_CITY
	release
	end

KenkoriaSea_Movement_SailToCity:
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

KenkoriaSea_Movement_PlayerExitBoat:
	walk_down
	walk_left
	face_right
	step_end

KenkoriaSea_Movement_SailorExitBoat:
	walk_down
	face_left
	step_end

KenkoriaSea_Movement_SailorEnterBoat:
	walk_up
	step_end

KenkoriaSea_Movement_PlayerEnterBoatNorth:
	walk_up
	walk_up
	step_end

KenkoriaSea_Movement_PlayerEnterBoatWest:
	walk_left
	walk_up
	step_end

KenkoriaSea_Text_GoBack:
	.string "Would you like to go back to\n"
	.string "KENKORIA CITY?$"

KenkoriaSea_Text_LetsGo:
	.string "Lets go.$"

KenkoriaSea_Text_TellMeWhenYouWantToGoBack:
	.string "Alright, tell me when you want to go\n"
	.string "back.$"
