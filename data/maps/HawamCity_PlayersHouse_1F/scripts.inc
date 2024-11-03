.set LOCALID_MOM, 1
.set LOCALID_DAD, 2

HawamCity_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HawamCity_PlayersHouse_1F_Mapscript2_Init
	.byte 0

HawamCity_PlayersHouse_1F_Mapscript2_Init::
	map_script_2 VAR_HAWAM_CITY_INTRO_STATE, 1, HawamCity_PlayersHouse_1F_EventScript_Journey
	.2byte 0

HawamCity_PlayersHouse_1F_EventScript_Journey:
	goto HawamCity_PlayersHouse_1F_EventScript_Farewell
	end

HawamCity_PlayersHouse_1F_EventScript_Farewell::
	lock
	msgbox HawamCity_PlayersHouse_1F_Text_ComeCloser, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_PlayersHouse_1F_Movement_ToTheTable
	waitmovement 0
	msgbox HawamCity_PlayersHouse_1F_Text_Journey, MSGBOX_DEFAULT
	closemessage
	setvar VAR_HAWAM_CITY_INTRO_STATE, 2
	release
	end

HawamCity_PlayersHouse_1F_EventScript_MomTalks::
	msgbox HaifaCity_PlayersHouse_1F_Text_MomTalks, MSGBOX_NPC
	end

HawamCity_PlayersHouse_1F_EventScript_DadTalks::
	msgbox HaifaCity_PlayersHouse_1F_Text_DadTalks, MSGBOX_NPC
	end

HawamCity_PlayersHouse_1F_Text_ComeCloser:
	.string "{COLOR RED}MOM:{COLOR DARK_GRAY} Here you are!\n"
	.string "We've been waiting, come sit with us.$"

HawamCity_PlayersHouse_1F_Text_Journey:
	.string "{COLOR RED}MOM:{COLOR DARK_GRAY} I hope you are all packed up and\n"
	.string "ready to go for your adventure.\p"
	.string "Professor ARIA told us he'll give you\n"
	.string "your very first POKéMON.\p"
	.string "I subscribed you to the POKéMON CENTER\n"
	.string "so you could heal your POKéMON.\p"
	.string "Take care, make new friends and come\n"
	.string "home every now and then.\p"
	.string "We love you honey.$"

HaifaCity_PlayersHouse_1F_Text_MomTalks:
	.string "{COLOR RED}MOM:{COLOR DARK_GRAY} I love you honey.\n"
	.string "Take care on your journey.$"

HaifaCity_PlayersHouse_1F_Text_DadTalks:
	.string "{COLOR BLUE}DAD:{COLOR DARK_GRAY} Make sure you have\n"
	.string "everything for your trip.\p"
	.string "It's good to be on top of things.$"

HawamCity_PlayersHouse_1F_Movement_ToTheTable:
	walk_right
	walk_down
    walk_right
    walk_down
    walk_down
    walk_down
    walk_down   
    walk_down
    walk_right
    walk_up
	face_right
	step_end
