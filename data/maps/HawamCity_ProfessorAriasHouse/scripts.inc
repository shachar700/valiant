.set LOCALID_BIRCH, 1

HawamCity_ProfessorAriasHouse_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE HawamCity_ProfessorAriasHouse_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE HawamCity_ProfessorAriasHouse_OnFrame
	.byte 0

HawamCity_ProfessorAriasHouse_OnWarp:
	map_script_2 VAR_TEMP_0, 0, HawamCity_ProfessorAriasHouse_EventScript_PlayerTurnNorth
	.2byte 0

HawamCity_ProfessorAriasHouse_OnFrame:
	map_script_2 VAR_HAWAM_CITY_INTRO_STATE, 3, HawamCity_ProfessorAriasHouse_EventText_Intro

HawamCity_ProfessorAriasHouse_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

HawamCity_ProfessorAriasHouse_EventText_Intro::
	lock
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 10
	msgbox HawamCity_ProfessorAriasHouse_Text_GiveMon, MSGBOX_DEFAULT
	call HawamCity_ProfessorAriasHouse_EventText_GiveStarter
	release
	end

HawamCity_ProfessorAriasHouse_EventText_GiveStarter::
	msgbox HawamCity_ProfessorAriasHouse_Text_Question
	waitmessage
	multichoice 20, 1, MULTI_CHOOSE_STARTER, 1
	compare VAR_RESULT, 0
	goto_if_eq PlayerChoosesStarter_Dratini
	compare VAR_RESULT, 1
	goto_if_eq PlayerChoosesStarter_Larvitar
	compare VAR_RESULT, 2
	goto_if_eq PlayerChoosesStarter_Bagon
	compare VAR_RESULT, 3
	goto_if_eq PlayerChoosesStarter_Beldum
	return

PlayerChoosesStarter_Dratini:
	bufferspeciesname STR_VAR_1, SPECIES_DRATINI
	setvar VAR_STARTER_CHOICE, SPECIES_DRATINI
	goto HawamCity_ProfessorAriasHouse_EventScript_ShowStarter
	return

PlayerChoosesStarter_Larvitar:
	bufferspeciesname STR_VAR_1, SPECIES_LARVITAR
	setvar VAR_STARTER_CHOICE, SPECIES_LARVITAR
	goto HawamCity_ProfessorAriasHouse_EventScript_ShowStarter
	return

PlayerChoosesStarter_Bagon:
	bufferspeciesname STR_VAR_1, SPECIES_BAGON
	setvar VAR_STARTER_CHOICE, SPECIES_BAGON
	goto HawamCity_ProfessorAriasHouse_EventScript_ShowStarter
	return

PlayerChoosesStarter_Beldum:
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	setvar VAR_STARTER_CHOICE, SPECIES_BELDUM
	goto HawamCity_ProfessorAriasHouse_EventScript_ShowStarter
	return

HawamCity_ProfessorAriasHouse_EventScript_ShowStarter::
	showmonpic VAR_STARTER_CHOICE, 10, 3
	playmoncry VAR_STARTER_CHOICE, 0
	msgbox HawamCity_ProfessorAriasHouse_Text_Confirm, MSGBOX_YESNO
	waitmessage
	waitmoncry
	compare VAR_RESULT, NO
	goto_if_eq HawamCity_ProfessorAriasHouse_EventScript_PickAgain
	hidemonpic
	setflag FLAG_SYS_POKEMON_GET
	givemon VAR_STARTER_CHOICE, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	msgbox HawamCity_ProfessorAriasHouse_Text_Received, MSGBOX_DEFAULT
	waitfanfare
	msgbox HawamCity_ProfessorAriasHouse_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	waitmessage
	goto_if_eq VAR_RESULT, YES, HawamCity_ProfessorAriasHouse_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, HawamCity_ProfessorAriasHouse_EventScript_VentureForth

HawamCity_ProfessorAriasHouse_EventScript_PickAgain:
	hidemonpic
	goto HawamCity_ProfessorAriasHouse_EventText_GiveStarter

HawamCity_ProfessorAriasHouse_EventScript_NicknameStarter:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto HawamCity_ProfessorAriasHouse_EventScript_VentureForth

HawamCity_ProfessorAriasHouse_EventScript_VentureForth:
	msgbox HawamCity_ProfessorAriasHouse_Text_VentureForth, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_HAWAM_CITY_INTRO_STATE, 4
	callnative UpdateFollowingPokemon
	releaseall
	end

HawamCity_ProfessorAriasHouse_Text_VentureForth:
	.string "Venture forth and enjoy the journey.\p"
	.string "I'll keep an eye on your progress.$"


HawamCity_ProfessorAriasHouse_Text_GiveMon:
	.string "I've been preparing these POKèMON for\n"
	.string "you.\p"
	.string "I'm gonna let you choose one of the baby\n"
	.string "POKéMON that got hatched recently.\p"
	.string "As you know I study the\n"
	.string "pseudo-legendary POKéMON.\l"
	.string "so you'll select one of those.\p"
	.string "Choose wisely.$"

HawamCity_ProfessorAriasHouse_Text_Question:
	.string "Which starter will you choose?$"

HawamCity_ProfessorAriasHouse_Text_Confirm:
	.string "Do you want to choose {STR_VAR_1}?$"

HawamCity_ProfessorAriasHouse_Text_Received:
	.string "{PLAYER} Recieved {STR_VAR_1}!$"

HawamCity_ProfessorAriasHouse_Text_WhyNotGiveNicknameToMon:
	.string "While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"




