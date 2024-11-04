PtolemaisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PtolemaisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PtolemaisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PtolemaisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PtolemaisCity_Gym_1F_OnTransition
	.byte 0

PtolemaisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

PtolemaisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

PtolemaisCity_Gym_1F_OnLoad:
	call PtolemaisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

PtolemaisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 15, PtolemaisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 41, PtolemaisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 89, PtolemaisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 9, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 9, 5, METATILE_SootopolisGym_Stairs, FALSE
PtolemaisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 10, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 10, 11, METATILE_SootopolisGym_Stairs, FALSE
PtolemaisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
PtolemaisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

PtolemaisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 15, PtolemaisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 41, PtolemaisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 89, PtolemaisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, PtolemaisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

PtolemaisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call PtolemaisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

PtolemaisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call PtolemaisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

PtolemaisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call PtolemaisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

PtolemaisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, PtolemaisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_PTOLEMAIS_CITY_GYM_B1F
	waitstate
	end

PtolemaisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

PtolemaisCity_Gym_1F_EventScript_Ido::
	trainerbattle_single TRAINER_JUAN_1, PtolemaisCity_Gym_1F_Text_IdoIntro, PtolemaisCity_Gym_1F_Text_IdoDefeat, PtolemaisCity_Gym_1F_EventScript_IdoDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, PtolemaisCity_Gym_1F_EventScript_GiveWaterPulse2
	msgbox PtolemaisCity_Gym_1F_Text_IdoPostBattle, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_Gym_1F_EventScript_IdoDefeated::
	message PtolemaisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PtolemaisCity_Gym_1F_Text_ExplainSoothingBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setvar VAR_PTOLEMAIS_CITY_STATE, 1
	setflag FLAG_HIDE_PTOLEMAIS_CITY_SMASH_FEMALE
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call PtolemaisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	release
	end

PtolemaisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox PtolemaisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

PtolemaisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox PtolemaisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

PtolemaisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, PtolemaisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox PtolemaisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox PtolemaisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, PtolemaisCity_Gym_1F_EventScript_GymStatueCertified
	goto PtolemaisCity_Gym_1F_EventScript_GymStatue
	end

PtolemaisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PtolemaisCity_Gym_1F_EventScript_GymStatueCertified
	goto PtolemaisCity_Gym_1F_EventScript_GymStatue
	end

PtolemaisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox PtolemaisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PtolemaisCity_Gym_1F_EventScript_GymStatue::
	msgbox PtolemaisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PtolemaisCity_Gym_1F_EventScript_Trigger::
	setvar VAR_TEMP_0, 1
	callnative RemoveFollowingPokemon
	end

PtolemaisCity_Gym_1F_EventScript_Trigger2::
	setvar VAR_TEMP_0, 0
	callnative UpdateFollowingPokemon
	end

PtolemaisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Hello there trainer.\n"
	.string "I'm here to give you advice\p"
	.string "PTOLEMAIS's GYM LEADER IDO is\n"
	.string "a gym leader of WATER-type POKéMON.\p"
	.string "And, to get to IDO, an icy floor\n"
	.string "will slow your progress…\p"
	.string "My advice to you is this…\p"
	.string "Get a lot of POéMON so that in-case\n"
	.string "of an emergency you have that backup.\p"
	.string "go get them champ in the making!$"

PtolemaisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! You've beaten IDO, who\n"
	.string "is no joke for a beginner!\p"
	.string "Check your TRAINER CARD.\p"
	.string "The SOOTHING BADGE you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the CHAMPIONSHIP!\p"
	.string "That's got to feel awesome!$"

PtolemaisCity_Gym_1F_Text_IdoIntro:
	.string "Welcome to the PTOLEMAIS CITY GYM!\p"
	.string "I'm IDO the gym leader and I specialise in\n"
	.string "WATER type POKéMON.\p"
	.string "There is something very soothing in\n"
	.string "water and in being close to the beach.\l"
	.string "I hope you see it too.\p"
	.string "I hope you are ready and brought\n"
	.string "some power because here I come!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
PtolemaisCity_Gym_1F_Text_IdoDefeat:
	.string "Ahahaha, excellent!\n"
	.string "Very well, you are the winner.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha! I shall reward you\n"
	.string "with this, the SOOTHING BADGE!$"

PtolemaisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the SOOTHING BADGE\n"
	.string "from IDO.$"

PtolemaisCity_Gym_1F_Text_ExplainSoothingBadgeTakeThis:
	.string "The SOOTHING BADGE heightens the\n"
	.string "ATTACK power of your POKéMON.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

PtolemaisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "The TECHNICAL MACHINE I handed you\n"
	.string "contains WATER PULSE.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

PtolemaisCity_Gym_1F_Text_IdoPostBattle:
	.string "You should challenge the other\n"
	.string "GYM LEADERS in their respective cities.\p"
	.string "By battling many GYMs, you should\n"
	.string "learn many powerful moves.$"

PtolemaisCity_Gym_1F_Text_GymStatue:
	.string "PTOLEMAIS CITY POKéMON GYM$"

PtolemaisCity_Gym_1F_Text_GymStatueCertified:
	.string "PTOLEMAIS CITY POKéMON GYM\p"
	.string "IDO'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"


