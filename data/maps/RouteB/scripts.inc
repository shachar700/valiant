.set LOCALID_RIVAL, 1

RouteB_MapScripts::
	.byte 0

RouteB_EventScript_Rival_Trigger1::
	setvar VAR_0x8008, 1
	goto RouteB_EventScript_RivalBattle
	end

RouteB_EventScript_Rival_Trigger2::
	setvar VAR_0x8008, 2
	goto RouteB_EventScript_RivalBattle
	end

RouteB_EventScript_RivalBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox RouteB_Text_RivalExplore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 60
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 1, RouteB_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, RouteB_EventScript_RivalApproachPlayer2
	msgbox RouteB_Text_Introduce, MSGBOX_DEFAULT
	waitmessage
	msgbox RouteB_Text_CanYouCatch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RouteB_EventScript_Tutorial
	msgbox RouteB_Text_Introduce2, MSGBOX_DEFAULT
	waitmessage
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, RouteB_Text_BenDefeat
	msgbox RouteB_Text_Fairwell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, RouteB_Movement_RivalLeaves
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_ROUTE_B_RIVAL
	setvar VAR_ROUTE_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

RouteB_EventScript_Tutorial:
	special StartWallyTutorialBattle
	return

RouteB_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route1_Movement_RivalApproachPlayer1
	waitmovement 0
	return

RouteB_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route1_Movement_RivalApproachPlayer2
	waitmovement 0
	return

RouteB_EventScript_Dor::
	trainerbattle_single TRAINER_CALVIN_1, RouteB_Text_DorIntro, RouteB_Text_DorDefeated
	msgbox RouteB_Text_DorPostBattle, MSGBOX_AUTOCLOSE
	end

RouteB_EventScript_Yuval::
	trainerbattle_single TRAINER_ALLEN, RouteB_Text_YuvalIntro, RouteB_Text_YuvalDefeated
	msgbox RouteB_Text_YuvalPostBattle, MSGBOX_AUTOCLOSE
	end

RouteB_EventScript_Yogev::
	trainerbattle_single TRAINER_RICK, RouteB_Text_YogevIntro, RouteB_Text_YogevDefeated
	msgbox RouteB_Text_YogevPostBattle, MSGBOX_AUTOCLOSE
	end

RouteB_EventScript_Dana::
	trainerbattle_single TRAINER_TIANA, RouteB_Text_DanaIntro, RouteB_Text_DanaDefeated
	msgbox RouteB_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RouteB_Text_RivalExplore:
	.string "Where did I put it?$"

RouteB_Text_Introduce:
	.string "Oh hi there! I didn't notice you.\p"
	.string "My name is Ben. I'm a POKéMON researcher.\n"
	.string "and you are?\p"
	.string "Oh, so you are {PLAYER} who just started\n"
	.string "your journey.\p"
	.string "That's nice!$"

RouteB_Text_Introduce2:
	.string "How about a friendly battle?$"

RouteB_Text_CanYouCatch:
	.string "Do you know how to catch wild POKéMON?\n"
	.string "I can show you if you don't know.$"

RouteB_Text_BenDefeat:
	.string "BEN: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"

RouteB_Text_Fairwell:
	.string "It was fun battling you.\n"
	.string "I'm going to find what I dropped.$"

Route1_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

Route1_Movement_RivalApproachPlayer2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

RouteB_Movement_RivalLeaves:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
