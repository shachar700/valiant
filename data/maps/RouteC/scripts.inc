.set LOCALID_SCIENTIST, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_MAIN_GRUNT, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_GRUNT_4, 5

RouteC_MapScripts::
	.byte 0

RouteC_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, RouteC_Text_Grunt1Intro, RouteC_Text_Grunt1Defeat
	msgbox RouteC_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RouteC_EventScript_Grunts_Trigger::
	lock
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RouteC_Text_MainGruntIntro, MSGBOX_DEFAULT
	applymovement LOCALID_MAIN_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAIN_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	delay 50
	applymovement LOCALID_MAIN_GRUNT, RouteC_Movement_GruntMovesToPlayer
	waitmovement 0
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, RouteC_EventScript_GruntBattleIntro, RouteC_EventScript_GruntBattleDefeat
	msgbox RouteC_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_PARTS
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAIN_GRUNT
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_ROUTE_C_GRUNTS
	@ talk to scientist
	applymovement LOCALID_SCIENTIST, RouteC_Movement_ScientistMovesToPlayer
	waitmovement 0
	msgbox RouteC_Text_ScientistThanksPlayer, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_FROM_BLACK
	removeobject LOCALID_SCIENTIST
	delay 30
	setflag FLAG_HIDE_ROUTE_C_SCIENTIST
	setvar VAR_ROUTE_STATE, 2
	release
	end

RouteC_EventScript_BetaSign::
	msgbox RouteC_Text_BetaSign, MSGBOX_NPC
	end

RouteC_Text_Grunt1Intro:
	.string "Hey there!\n"
	.string "I can't let you pass right now!$"

RouteC_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "I lost it!$"

RouteC_Text_Grunt1PostBattle:
	.string "I took the loss for the TEAM,\n"
	.string "but I did my job…$"

RouteC_Text_MainGruntIntro:
	.string "Give us all the information you have.\p"
	.string "I already gave you everything.\p"
	.string "That is not enough! We are missing key\n"
	.string "components that will help us control it.\p"
	.string "This is all I have. Really.\p"
	.string "Well you are coming with us then…$"

RouteC_EventScript_GruntBattleIntro:
	.string "Who are you? and why are you\n"
	.string "eavesdropping?\p"
	.string "Well you are about to regret that.$"

RouteC_EventScript_GruntBattleDefeat:
	.string "Ugh! I can't believe it.$"


RouteC_Text_GruntTakePackage:
	.string "This is plain not right…\p"
	.string "The BOSS told us this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All we had to do was steal some package\n"
	.string "data from a scientist who lives in.\l"
	.string "PTOLEMAIS CITY.\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"

RouteC_Text_ScientistThanksPlayer:
	.string "Thank you for saving me!\p"
	.string "I was getting worried there\n"
	.string "that I would get kidnapped!\p"
	.string "They wanted to take information\n"
	.string "about time travel and CELEBI.\p"
	.string "I gave them what I had but they\n"
	.string "seeked something specific.\p"
	.string "Data that got stolen from us.\p"
	.string "I hope they leave us alone because\n"
	.string "my heart can't take it.\p"
	.string "I would not survive in their custody.\p"
	.string "Well look at me rambling, I'm going\n"
	.string "to take a hot bath and relax. Bye.$"

RouteC_Text_BetaSign:
	.string "Thank you for playing Beta 1\n"
	.string "of POKéMON Valiant!\p"
	.string "Please leave feedback or report bugs\n"
	.string "in the discord server:\p"
	.string "https://discord.gg/sFrX7AS6HC\p"
	.string "I hope you enjoyed! :)$"

RouteC_Movement_GruntMovesToPlayer:
	walk_left
	face_down
	step_end

RouteC_Movement_ScientistMovesToPlayer:
	walk_left
	walk_down
	walk_down
	step_end
