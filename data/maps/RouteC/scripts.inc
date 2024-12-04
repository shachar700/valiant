.set LOCALID_SCIENTIST, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_MAIN_GRUNT, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_GRUNT_4, 5
.set LOCALID_RIVAL, 11

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
	msgbox RouteC_EventScript_GruntBattleIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RouteC_EventScript_GruntBattleDefeat
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
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SCIENTIST
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_ROUTE_C_SCIENTIST
	setvar VAR_ROUTE_STATE, 2
	release
	end

RouteC_EventScript_Rival::
	lockall
	goto_if_eq VAR_RIVAL_NOA, 0, RouteC_EventScript_InitiateRivalSequence
	faceplayer
	msgbox RouteC_Text_LovelyView, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RouteC_EventScript_InitiateRivalSequence::
	msgbox RouteC_Text_NoaWonderfulPokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox RouteC_Text_NoaLetsBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, RouteC_Text_NoaDefeated
	msgbox RouteC_Text_GreatBattle, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	setvar VAR_RIVAL_NOA, 1
	closemessage
	releaseall
	end

@RouteC_EventScript_BetaSign::
@	msgbox RouteC_Text_BetaSign, MSGBOX_NPC
@	end

RouteC_EventScript_ScribbledSign::
	msgbox RouteC_Text_ScribbledSign, MSGBOX_NPC
	end

RouteC_EventScript_Kfir::
	trainerbattle_single TRAINER_LYLE, RouteC_Text_GoBugPokemonTeam, RouteC_Text_ICouldntWin
	msgbox RouteC_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

RouteC_EventScript_Noy::
	trainerbattle_single TRAINER_JOSE, RouteC_Text_CatMons, RouteC_Text_MoreCats
	msgbox RouteC_Text_MaybeDogs, MSGBOX_AUTOCLOSE
	end

RouteC_EventScript_Tal::
	trainerbattle_single TRAINER_DOUG, RouteC_Text_IHopeYouBroughtFlashlight, RouteC_Text_ThereIsACave
	msgbox RouteC_Text_MoreRockMons, MSGBOX_AUTOCLOSE
	end

RouteC_EventScript_Noa_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox RouteC_Text_NoaRival, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE_STATE, 3
	release
	end

RouteC_EventScript_Braille_Flames::
	lockall
	braillemsgbox RouteC_Braille_Flames
	closemessage
	releaseall
	end

RouteC_EventScript_Braille_Waves::
	lockall
	braillemsgbox RouteC_Braille_Waves
	closemessage
	releaseall
	end

RouteC_EventScript_Braille_Lightning::
	lockall
	braillemsgbox RouteC_Braille_Lightning
	closemessage
	releaseall
	end

RouteC_Braille_Flames:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "FOUR PINS\n"
	.braille "IN YOUR LIMB$"

RouteC_Braille_Waves:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "SIX BIRDS\n"
	.braille "HELD IN POCKET$"

RouteC_Braille_Lightning:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "SIT AND RELAX\n"
	.braille "RIGHT FOR ME$"

RouteC_Text_NoaRival:
	.string "{COLOR RED}NOA:{COLOR DARK_GRAY} Hey {PLAYER}!\n"
	.string "It's good to see you here.\p"
	.string "I'm glad you started your journey.\p"
	.string "I was worried I'll be traveling alone\n"
	.string "all the way to the POKéMON LEAGUE.\p"
	.string "I'm going to be training here for a\n"
	.string "bit so you are welcome to challenge me.\p"
	.string "I'm warning you though,\n"
	.string "I have more experience than you.\p"
	.string "So it will be tough for you to face me.\p"
	.string "There is something I want to give you.\n"
	.string "If you can beat me, I'll give it to you.$"

RouteC_Text_LovelyView:
	.string "{COLOR RED}NOA:{COLOR DARK_GRAY} What a lovely view from here.\n"
	.string "I could stay here for hours.$"

RouteC_Text_NoaWonderfulPokemon:
	.string "{COLOR RED}NOA:{COLOR DARK_GRAY} Such a wonderful POKéMON is PINSIR.$"

RouteC_Text_NoaLetsBattle:
	.string "{COLOR RED}NOA:{COLOR DARK_GRAY} I'm glad you showed up.\p"
	.string "There is a beautiful view from here so I \n"
	.string "like to come here after my training.\p"
	.string "I hope you are ready to face me in\n"
	.string "battle.$"

RouteC_Text_NoaDefeated:
	.string "Oh, that was a close one!$"

RouteC_Text_GreatBattle:
	.string "That was a great battle.\p"
	.string "I'm going to rest here for a bit.\p"
	.string "As promised here is your reward.$"

RouteC_Text_IHopeYouBroughtFlashlight:
	.string "I hope you brought a flashlight\n"
	.string "because there is a cave up ahead!$"

RouteC_Text_ThereIsACave:
	.string "There is a dark cave up ahead!$"

RouteC_Text_MoreRockMons:
	.string "I should've caught more\n"
	.string "ROCK POKéMON.$"

RouteC_Text_CatMons:
	.string "I have cat POKéMON\n"
	.string "that will surprise you!$"

RouteC_Text_MoreCats:
	.string "Ugh! I wish I had more cats.$"

RouteC_Text_MaybeDogs:
	.string "Maybe I should catch some dogs.$"	

RouteC_Text_GoBugPokemonTeam:
	.string "Go my BUG POKéMON team!$"

RouteC_Text_ICouldntWin:
	.string "I couldn't win.\n"
	.string "I hope next time I'll win.$"

RouteC_Text_ImOutOfPokeBalls:
	.string "I am out of Pokéballs.$"

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
	.string "data from a scientist who lives in\l"
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

@RouteC_Text_BetaSign:
@	.string "Thank you for playing Beta 1\n"
@	.string "of POKéMON Valiant!\p"
@	.string "Please leave feedback or report bugs\n"
@	.string "in the discord server:\p"
@	.string "https://discord.gg/wcEwv9bytW\p"
@	.string "I hope you enjoyed!$"

RouteC_Text_ScribbledSign:
	.string "The sign got scribbled and erased.$"

RouteC_Movement_GruntMovesToPlayer:
	walk_left
	face_down
	step_end

RouteC_Movement_ScientistMovesToPlayer:
	walk_left
	walk_down
	walk_down
	step_end
