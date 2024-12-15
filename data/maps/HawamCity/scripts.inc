.set LOCALID_BIRCH, 1

HawamCity_MapScripts::
	.byte 0

HawamCity_EventScript_ProfApproachesTrigger1::
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto HawamCity_EventScript_ProfApproaches
	end

HawamCity_EventScript_ProfApproachesTrigger2::
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto HawamCity_EventScript_ProfApproaches
	end

HawamCity_EventScript_ProfApproachesTrigger3::
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
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

HawamCity_EventScript_BlockSouth_Trigger::
	lock
	goto_if_set FLAG_RECEIVED_BIKE HawamCity_EventScript_Worried
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	msgbox HawamCity_Text_Man_Block, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_GoOneUp
	waitmovement 0
	release
	end

HawamCity_EventScript_Worried::
	msgbox HawamCity_Text_Worried, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, HawamCity_Movement_GoOneUp
	waitmovement 0
	release
	end

HawamCity_EventScript_GymDoor::
	lockall
	goto_if_set FLAG_HAWAM_CITY_GYM_DOOR_OPENED, HawamCity_EventScript_TheDoorIsOpen
	msgbox HawamCity_EventScript_GymIsLocked, MSGBOX_SIGN

	@ if (flag) {}
	@ Do this when you want the gym door to open ->
	@ setmetatile 3, 8, METATILE_Gym_Door_Unlocked, TRUE
	@ special DrawWholeMapView
	
	releaseall
	end

HawamCity_EventScript_TheDoorIsOpen::
	msgbox HawamCity_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

HawamCity_EventScript_LittleBoy::
	msgbox HawamCity_Text_LittleKid, MSGBOX_NPC
	end

HawamCity_EventScript_LittleGirl::
	msgbox HawamCity_Text_LittleGirl, MSGBOX_NPC
	end

HawamCity_EventScript_FatMan::
	msgbox HawamCity_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

HawamCity_EventScript_Boy::
	msgbox HawamCity_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

HawamCity_EventScript_Gentleman::
	msgbox HawamCity_Text_Gentleman, MSGBOX_NPC
	end


HawamCity_EventScript_Girl::
	msgbox HawamCity_Text_Girl, MSGBOX_NPC
	end


HawamCity_EventScript_Man::
	msgbox HawamCity_Text_Man, MSGBOX_NPC
	end

HawamCity_EventScript_PlayersMailbox::
	msgbox HawamCity_Text_PlayersMailbox, MSGBOX_SIGN
	end

HawamCity_EventScript_ProfessorAriasMailbox::
	msgbox HawamCity_Text_ProfessorAriasMailbox, MSGBOX_SIGN
	end

HawamCity_EventScript_NoasMailbox::
	msgbox HawamCity_Text_NoasMailbox, MSGBOX_SIGN
	end

HawamCity_EventScript_CitySign::
	msgbox HawamCity_Text_CitySign, MSGBOX_SIGN
	end

HawamCity_EventScript_GymSign::
	msgbox HawamCity_Text_GymSign, MSGBOX_SIGN
	end

HawamCity_Text_Worried:
	.string "The gym leader JONAH, went to SODORI\n"
	.string "TUNNELS and haven't come back yet.\p"
	.string "I'm worried about him. Could you\n"
	.string "please check it out?$"

HawamCity_Text_ProfIntro:
	.string "{COLOR GREEN}PROF ARIA:{COLOR DARK_GRAY} Oh hello there {PLAYER}!\p"
	.string "I came here to let you know that\n"
	.string "your very first POKéMON is\l"
	.string "waiting for you.\p"
	.string "Follow me to my house.$"

HawamCity_EventScript_GymIsLocked:
	.string "The door is locked.\p"
	.string "“The gym leader went to errands.”$"

HawamCity_Text_TheDoorIsOpen:
	.string "The door is open.$"

HawamCity_Text_LittleKid:
	.string "Weeeeeeeeeeeeee.$"

HawamCity_Text_LittleGirl:
	.string "Help me! I'm getting chased.$"

HawamCity_Text_CanUsePCToStoreItems:
	.string "I never thought of the day people could\n"
	.string "store items in the clouds.\p"
	.string "The power of science is astounding!$"

HawamCity_Text_BirchSpendsDaysInLab:
	.string "PROF. ARAUCARIA is a very messy guy.\n"
	.string "His house has piles of books and trash\l"
	.string "all over the place…\p"
	.string "He should really clean up his\n"
	.string "working space.$"

HawamCity_Text_Gentleman:
	.string "I've been living in Hawam City all my life.\n"
	.string "It's peaceful and quiet here.$"

HawamCity_Text_Girl:
	.string "I wanted to buy SUPER POTIONS but they\n"
	.string "only have POTIONS in Hawam City.$"

HawamCity_Text_Man:
	.string "To the SOUTH is the city of spring,\n"
	.string "HARUTEL CITY.\p"
	.string "You'd need a bicycle if you want to\n"
	.string "travel the roads SOUTH.\l"
	.string "You can get one from KENKORIA CITY\l"
	.string "to the NORTH-EAST.$"

HawamCity_Text_Man_Block:
	.string "You'd need a bike if you want to\n"
	.string "go SOUTH.\p"
	.string "There's a bike shop NORTH-EAST\n"
	.string "of here in KENKORIA CITY.$"

HawamCity_Text_PlayersMailbox:
	.string "My family's mailbox…\n"
	.string "None of the letters are for me though.$"

HawamCity_Text_ProfessorAriasMailbox:
	.string "PROF. ARAUCARIA'S mailbox…\n"
	.string "It's full of letters.$"

HawamCity_Text_NoasMailbox:
	.string "Noa's family mailbox…\n"
	.string "It would be rude to sniff around.$"

HawamCity_Text_CitySign:
	.string "HAWAM CITY\n"
	.string "A vibrant coastal city.$"

HawamCity_Text_GymSign:
	.string "HAWAM CITY GYM\n"
	.string "Jona soars the blue sky.$"

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

HawamCity_Movement_GoOneUp:
	walk_up
	step_end
