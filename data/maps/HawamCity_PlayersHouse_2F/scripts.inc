.set LOCALID_MOM, 1

HawamCity_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HawamCity_PlayersHouse_2F_Mapscript2_Init
	.byte 0

HawamCity_PlayersHouse_2F_Mapscript2_Init:
	map_script_2 VAR_HAWAM_CITY_INTRO_STATE, 0, HawamCity_PlayersHouse_2F_EventScript_MeetMom
	.2byte 0	

HawamCity_PlayersHouse_2F_EventScript_MeetMom::
	lockall
	playse SE_EXIT
	delay 10
    applymovement LOCALID_MOM, HawamCity_PlayersHouse_2F_Movement_MomEntersRoom   
	waitmovement 0
	playse SE_PIN	
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	msgbox HawamCity_PlayersHouse_2F_Text_GoodMorning, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, HawamCity_PlayersHouse_2F_Movement_MomExitsRoom   
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_PLAYERS_HOUSE_2F_MOM
	setvar VAR_HAWAM_CITY_INTRO_STATE, 1
    releaseall
    end

HawamCity_PlayersHouse_2F_EventScript_Mudkip_Doll::
	msgbox HawamCity_PlayersHouse_2F_Text_Mudkip_Doll, MSGBOX_SIGN

HawamCity_PlayersHouse_2F_EventScript_Clock::
	msgbox HawamCity_PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_SIGN
	end

HawamCity_PlayersHouse_2F_EventScript_PC::
	lockall
	goto HawamCity_PlayersHouse_2F_EventScript_CheckPlayersPC
	end

HawamCity_PlayersHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

HawamCity_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

HawamCity_PlayersHouse_2F_Text_Mudkip_Doll:
	.string "It's my Mudkip doll\p"
	.string "Better leave it right where it is.$"

HawamCity_PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Probably low battery.$"

HawamCity_PlayersHouse_2F_Text_GoodMorning:
	.string "{COLOR RED}MOM:{COLOR DARK_GRAY} Good morning sunshine! I hope you\n"
	.string "had a wonderful rest.\p"
	.string "We are waiting for you downstairs.$"

HawamCity_PlayersHouse_2F_Movement_MomEntersRoom:
	walk_right
	walk_right
	walk_in_place_slow_right
	delay_16
    walk_in_place_right
	step_end

HawamCity_PlayersHouse_2F_Movement_MomExitsRoom:
	walk_in_place_slow_left
	walk_left
	walk_left
	step_end