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
	msgbox RouteB_Text_RivalExplore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, RouteB_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, RouteB_EventScript_RivalApproachPlayer2
	msgbox RouteB_Text_Introduce, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, RouteB_Text_BenDefeat
	msgbox RouteB_Text_Fairwell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, RouteB_Movement_RivalLeaves
	setflag FLAG_HIDE_ROUTE_B_RIVAL
	setvar VAR_ROUTE_B_STATE, 1
	end

RouteB_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route1_Movement_RivalApproachPlayer1
	waitmovement 0
	return

RouteB_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route1_Movement_RivalApproachPlayer2
	waitmovement 0
	return

RouteB_Text_RivalExplore:
	.string "Where did I put it?$"

RouteB_Text_Introduce:
	.string "Oh hi there! I didn't notice you.\p"
	.string "My name is Ben. I'm a POKéMON researcher.\n"
	.string "and you are?\p"
	.string "Oh, so you are {PLAYER} who just started\n"
	.string "your journey. That's nice!\l"
	.string "How about a friendly battle?$"

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
	walk_up
	walk_up
	step_end
