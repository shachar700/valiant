.set LOCALID_BIRCH, 1

HawamCity_MapScripts::
	.byte 0

HawamCity_EventScript_ProfApproachesTrigger1::
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_FaceRight
	waitmovement 0
	goto HawamCity_EventScript_ProfApproaches
	end

HawamCity_EventScript_ProfApproachesTrigger2::
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_FaceRight
	waitmovement 0
	goto HawamCity_EventScript_ProfApproaches
	end

HawamCity_EventScript_ProfApproachesTrigger3::
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_FaceRight
	waitmovement 0
	goto HawamCity_EventScript_ProfApproaches
	end

HawamCity_EventScript_ProfApproaches::
	call_if_eq VAR_0x8008, 2, HawamCity_MoveProfOneDown
	call_if_eq VAR_0x8008, 3, HawamCity_MoveProfTwoDown
	applymovement LOCALID_BIRCH, HawamCity_Movement_ProfGoesLeft
	waitmovement 0
	playse SE_PIN
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, HawamCity_Movement_WalkInPlace
	waitmovement 0
	applymovement LOCALID_BIRCH, HawamCity_Movement_ProfComesCloser
	waitmovement 0
	msgbox HawamCity_Text_ProfIntro, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_BIRCH, HawamCity_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_WalkRight
	waitmovement 0
	call_if_eq VAR_0x8008, 2, HawamCity_Movement_ProfAndPlayerOneUp
	call_if_eq VAR_0x8008, 3, HawamCity_Movement_ProfAndPlayerTwoUp
	opendoor 39, 40
	waitdooranim
	applymovement LOCALID_BIRCH, HawamCity_Movement_ProfEntersHouse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_PlayerEntersHouse
	waitmovement 0
	closedoor 39, 40
	waitdooranim
	setflag FLAG_HIDE_HAWAM_CITY_PROF
	setvar VAR_HAWAM_CITY_INTRO_STATE, 3
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	warpsilent MAP_HAWAM_CITY_PROFESSOR_ARIAS_HOUSE, 6, 5
	waitstate
	release
	end

HawamCity_MoveProfOneDown:
	setobjectxy LOCALID_BIRCH 37,41
	return

HawamCity_MoveProfTwoDown:
	setobjectxy LOCALID_BIRCH 37,42
	return

HawamCity_Movement_ProfAndPlayerOneUp::
	applymovement LOCALID_BIRCH, HawamCity_Movement_WalkOneUp
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_WalkOneUp
	waitmovement 0
	return

HawamCity_Movement_ProfAndPlayerTwoUp::
	applymovement LOCALID_BIRCH, HawamCity_Movement_WalkTwoUp
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_WalkTwoUp
	waitmovement 0
	return

HawamCity_Text_ProfIntro:
	.string "{COLOR GREEN}PROF ARIA:{COLOR DARK_GRAY} Oh hello there {PLAYER}!\p"
	.string "I came here to let you know that\n"
	.string "your very first POKéMON is\l"
	.string "waiting for you.\p"
	.string "Follow me to my house.$"

HawamCity_Movement_FaceRight:
	face_right
	step_end

HawamCity_Movement_WalkOneUp:
	walk_up
	step_end

HawamCity_Movement_WalkTwoUp:
	walk_up
	walk_up
	step_end

HawamCity_Movement_ProfGoesLeft:
	walk_left
	walk_left
	step_end

HawamCity_Movement_ProfComesCloser:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

HawamCity_Movement_WalkInPlace:
	walk_in_place_slow_left
	step_end

HawamCity_Movement_WalkRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HawamCity_Movement_ProfEntersHouse:
	walk_up
	set_invisible
	step_end

HawamCity_Movement_PlayerEntersHouse:
	walk_right
	walk_up
	set_invisible
	step_end
