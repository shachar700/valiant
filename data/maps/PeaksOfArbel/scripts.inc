.set LOCALID_VIGOROTH_1, 16
.set LOCALID_VIGOROTH_2, 15 
.set LOCALID_BEN, 26
.set LOCALID_AZRI, 12

PeaksOfArbel_MapScripts::
	.byte 0

PeaksOfArbel_EventScript_Box::
	msgbox PeaksOfArbel_Text_Box, MSGBOX_NPC
	end

PeaksOfArbel_EventScript_GruntG1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, PeaksOfArbel_Text_GruntG1Intro, PeaksOfArbel_Text_GruntG1Defeat
	msgbox PeaksOfArbel_Text_GruntG1PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntB1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, PeaksOfArbel_Text_GruntB1Intro, PeaksOfArbel_Text_GruntB1Defeat
	msgbox PeaksOfArbel_Text_GruntB1PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntB2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, PeaksOfArbel_Text_GruntB2Intro, PeaksOfArbel_Text_GruntB2Defeat
	msgbox PeaksOfArbel_Text_GruntB2PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntG2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, PeaksOfArbel_Text_GruntG2Intro, PeaksOfArbel_Text_GruntG2Defeat
	msgbox PeaksOfArbel_Text_GruntG2PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntB3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, PeaksOfArbel_Text_GruntB3Intro, PeaksOfArbel_Text_GruntB3Defeat
	msgbox PeaksOfArbel_Text_GruntB3PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntG3::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, PeaksOfArbel_Text_GruntG3Intro, PeaksOfArbel_Text_GruntG3Defeat
	msgbox PeaksOfArbel_Text_GruntG3PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_GruntB4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, PeaksOfArbel_Text_GruntB4Intro, PeaksOfArbel_Text_GruntB4Defeat
	msgbox PeaksOfArbel_Text_GruntB4PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_Scientist1::
	trainerbattle_single TRAINER_EDWIN_1, PeaksOfArbel_Text_Scientist1Intro, PeaksOfArbel_Text_Scientist1Defeat
	msgbox PeaksOfArbel_Text_Scientist1PostBattle, MSGBOX_AUTOCLOSE
	end

PeaksOfArbel_EventScript_Button1::
	lock
	goto_if_set FLAG_TEMP_1, PeaksOfArbel_EventScript_ButtonAlready
	msgbox PeaksOfArbel_Text_Button_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PeaksOfArbel_EventScript_ButtonDeclined
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_TEMP_1
	msgbox PeaksOfArbel_Text_Button_Accept, MSGBOX_AUTOCLOSE
	setobjectxyperm 1, 28, 30
	release
	end

PeaksOfArbel_EventScript_Button2::
	lock
	goto_if_set FLAG_TEMP_2, PeaksOfArbel_EventScript_ButtonAlready
	msgbox PeaksOfArbel_Text_Button_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PeaksOfArbel_EventScript_ButtonDeclined
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_TEMP_2
	msgbox PeaksOfArbel_Text_Button_Accept, MSGBOX_AUTOCLOSE
	setobjectxyperm 28, 19, 24
	release
	end

PeaksOfArbel_EventScript_Button3::
	lock
	goto_if_set FLAG_TEMP_3, PeaksOfArbel_EventScript_ButtonAlready
	msgbox PeaksOfArbel_Text_Button_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PeaksOfArbel_EventScript_ButtonDeclined
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_TEMP_3
	msgbox PeaksOfArbel_Text_Button_Accept, MSGBOX_AUTOCLOSE
	setobjectxyperm 29, 29, 19
	release
	end

PeaksOfArbel_EventScript_Button4::
	lock
	goto_if_set FLAG_TEMP_4, PeaksOfArbel_EventScript_ButtonAlready
	msgbox PeaksOfArbel_Text_Button_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PeaksOfArbel_EventScript_ButtonDeclined
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_TEMP_4
	msgbox PeaksOfArbel_Text_Button_Accept, MSGBOX_AUTOCLOSE
	setobjectxyperm 30, 32, 3
	release
	end

PeaksOfArbel_EventScript_Button5::
	lock
	goto_if_set FLAG_TEMP_5, PeaksOfArbel_EventScript_ButtonAlready
	msgbox PeaksOfArbel_Text_Button_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PeaksOfArbel_EventScript_ButtonDeclined
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setflag FLAG_TEMP_5
	msgbox PeaksOfArbel_Text_Button_Accept, MSGBOX_AUTOCLOSE
	setobjectxyperm 31, 18, 17
	release
	end

PeaksOfArbel_EventScript_ButtonDeclined:
	msgbox PeaksOfArbel_Text_Button_Nothing, MSGBOX_AUTOCLOSE
	release
	end

PeaksOfArbel_EventScript_ButtonAlready:
	msgbox PeaksOfArbel_Text_Button_Already, MSGBOX_AUTOCLOSE
	release
	end

PeaksOfArbel_EventScript_Scientist2::
	msgbox PeaksOfArbel_Text_Scientist2, MSGBOX_NPC
	end

PeaksOfArbel_EventScript_GruntB5::
	msgbox PeaksOfArbel_Text_GruntB5, MSGBOX_NPC
	end

PeaksOfArbel_EventScript_GruntG4::
	msgbox PeaksOfArbel_Text_GruntG4, MSGBOX_NPC
	end

PeaksOfArbel_Trigger_Azri::
	lockall
	fadedefaultbgm
	playbgm MUS_ENCOUNTER_MAGMA, TRUE
	applymovement LOCALID_AZRI, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_AZRI, PeaksOfArbel_MOvement_AzriWalksForward
	waitmovement 0 
	msgbox PeaksOfArbel_Text_AzriIntro, MSGBOX_DEFAULT
	closemessage
	@ben walks in 
	clearflag FLAG_HIDE_ROUTE_B_RIVAL
	addobject LOCALID_BEN
	applymovement LOCALID_BEN, PeaksOfARbel_Movement_BenEnters
	waitmovement 0
	msgbox PeaksOfArbel_Text_BenIntro, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BEN, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, PeaksOfArbel_Movement_PlayersMoveDownToBen
	waitmovement 0
	msgbox PeaksOfArbel_Text_BenPlayerAreYouReady, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BEN, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement 18, PeaksOfArbel_Movement_GruntApproachesPlayer
	waitmovement 0
	goto PeaksOfArbel_EventScript_ChoosePartyForMultiBattle
	end

PeaksOfArbel_EventScript_ChoosePartyForMultiBattle::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, PeaksOfArbel_EventScript_DoBenMultiBattle
	special LoadPlayerParty
	goto PeaksOfArbel_EventScript_ChoosePartyForMultiBattle

PeaksOfArbel_EventScript_DoBenMultiBattle::
	@ fadeinbgm 0
	multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, PeaksOfArbel_Text_ThisIsNotOver, TRAINER_TABITHA_MOSSDEEP, PeaksOfArbel_Text_NajeebDefeat, PARTNER_BEN
	switch VAR_RESULT
	case 1, PeaksOfArbel_EventScript_DefeatedAzriNajib
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_B_RIVAL
	special SetCB2WhiteOut
	waitstate

PeaksOfArbel_EventScript_DefeatedAzriNajib::
	msgbox PeaksOfArbel_Text_AzriConfused, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 18, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_AZRI, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 60
	applymovement 18, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_AZRI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PeaksOfArbel_Text_AzriDefeat, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_PEAKS_OF_ARBEL_TEAM_SMASH
	removeobject LOCALID_AZRI
	removeobject 18 @NAJEEB/Boy5
	removeobject 17 @Girl4
	removeobject 14 @Scientist2
	removeobject 13 @Boy4
	removeobject 21 @Scientist1
	removeobject 11 @Girl3
	removeobject 10 @Boy3
	removeobject 9  @Girl2
	removeobject 20 @Boy2
	removeobject 27 @Boy1
	removeobject 24 @Girl1
	@hide grunts and set vars and flags
	fadescreen FADE_FROM_BLACK
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject LOCALID_BEN, DIR_EAST
	msgbox PeaksOfArbel_Text_BenhankYouComeSeeMeAtMyResearchFacility, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@remove ben
	setflag FLAG_HIDE_ROUTE_B_RIVAL
	clearflag FLAG_HIDE_PEAKS_OF_ARBEL_TRAVELERS
	removeobject LOCALID_BEN
	setvar VAR_KEREN_CITY_GYM_STATE, 7
	fadescreen FADE_FROM_BLACK
#ifdef BUGFIX
	releaseall
#endif
	end

PeaksOfArbel_EventScript_Vigoroth1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_ENCOUNTER
	delay 40
	msgbox PeaksOfArbel_Text_Vigoroth, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_VIGOROTH, 30, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_VIGOROTH, CRY_MODE_FAINT
	waitmoncry
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject LOCALID_VIGOROTH_1
	setflag FLAG_HIDE_VIGOROTH_1
	fadescreen FADE_FROM_BLACK
	release
	end

PeaksOfArbel_EventScript_Vigoroth2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_ENCOUNTER
	delay 40
	msgbox PeaksOfArbel_Text_Vigoroth, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_VIGOROTH, 30, ITEM_NONE
	dowildbattle
	playmoncry SPECIES_VIGOROTH, CRY_MODE_FAINT
	waitmoncry
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject LOCALID_VIGOROTH_2
	setflag FLAG_HIDE_VIGOROTH_2
	fadescreen FADE_FROM_BLACK
	release
	end

PeaksOfArbel_EventScript_Hiker::
	msgbox PeaksOfArbel_Text_Hiker, MSGBOX_NPC
	end

PeaksOfArbel_EventScript_Maniac::
	msgbox PeaksOfArbel_Text_Maniac, MSGBOX_NPC
	end

PeaksOfARbel_Movement_BenEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

PeaksOfArbel_MOvement_AzriWalksForward:
	walk_down
	step_end

PeaksOfArbel_Movement_GruntApproachesPlayer:
	walk_down
	walk_left
	walk_left
	step_end

PeaksOfArbel_Movement_PlayersMoveDownToBen:
	walk_down
	face_left
	step_end

PeaksOfArbel_Text_Box:
	.string "It says on the box:\n"
	.string "PROPERTY OF TEAM SMASH.\p"
	.string "Tasked with blocking unwanted guests.$"

PeaksOfArbel_Text_GruntB5:
	.string "No entry past this point.$"

PeaksOfArbel_Text_GruntG4:
	.string "We are digging for zircon gems.$"

PeaksOfArbel_Text_Vigoroth:
	.string "Vigo Vigoroth!$"

PeaksOfArbel_Text_Button_Question:
	.string "Push the button?$"

PeaksOfArbel_Text_Button_Accept:
	.string "Button activated.$"

PeaksOfArbel_Text_Button_Nothing:
	.string "Button was not pushed.$"

PeaksOfArbel_Text_Button_Already:
	.string "Button already activated.$"

PeaksOfArbel_Text_GruntG1Intro:
	.string "CELEBI? There's no CELEBI in here.\n"
	.string "This area is off-limit.$"

PeaksOfArbel_Text_GruntG1Defeat:
	.string "This was not the plan.$"

PeaksOfArbel_Text_GruntG1PostBattle:
	.string "Good luck finding your place around\n"
	.string "here.$"

PeaksOfArbel_Text_GruntB1Intro:
	.string "You are tresspassing.\n"
	.string "Why are you here in this cave?$"

PeaksOfArbel_Text_GruntB1Defeat:
	.string "… … …\n"
	.string "… … …\p"
	.string "Impossible.$"

PeaksOfArbel_Text_GruntB1PostBattle:
	.string "Do you think I'll tell you how to\n"
	.string "proceed? No way.$"

PeaksOfArbel_Text_GruntB2Intro:
	.string "This cave is not for the faint of heart.$"

PeaksOfArbel_Text_GruntB2Defeat:
	.string "You've outmatched my POKéMON.$"

PeaksOfArbel_Text_GruntB2PostBattle:
	.string "I'm not gonna tell you why we are here.\n"
	.string "You are not gonna stop us.$"

PeaksOfArbel_Text_GruntG2Intro:
	.string "This cave is ours. Beat it punk.$"

PeaksOfArbel_Text_GruntG2Defeat:
	.string "Not fair. No way.$"

PeaksOfArbel_Text_GruntG2PostBattle:
	.string "I have been guarding here for a while\n"
	.string "now.$"

PeaksOfArbel_Text_GruntB3Intro:
	.string "This area is not for kids. You should go\n"
	.string "back home to your mommy.$"

PeaksOfArbel_Text_GruntB3Defeat:
	.string "Ugh Argh Err…$"

PeaksOfArbel_Text_GruntB3PostBattle:
	.string "I got out skilled by a kid. Oof.$"

PeaksOfArbel_Text_GruntG3Intro:
	.string "Our boss keeps us on our toes for any\n"
	.string "intruders. We can't let them intervene.$"

PeaksOfArbel_Text_GruntG3Defeat:
	.string "This is unacceptable.$"

PeaksOfArbel_Text_GruntG3PostBattle:
	.string "Keep your eyes open.\n"
	.string "I wanna see them.$"

PeaksOfArbel_Text_GruntB4Intro:
	.string "What are we doing here?\n"
	.string "It's none of your business.$"

PeaksOfArbel_Text_GruntB4Defeat:
	.string "My DONPHAN. No…$"

PeaksOfArbel_Text_GruntB4PostBattle:
	.string "We are drilling and excavating.\n"
	.string "My DONPHAN is helping.$"

PeaksOfArbel_Text_Scientist1Intro:
	.string "The science behind cave treasures is\n"
	.string "astounding.$"

PeaksOfArbel_Text_Scientist1Defeat:
	.string "This is not correct. Not in my equation.$"

PeaksOfArbel_Text_Scientist1PostBattle:
	.string "What can we expect from what comes next?\n"
	.string "This is so exciting.$"

PeaksOfArbel_Text_Scientist2:
	.string "I need to wait for a POKéMON to push\n"
	.string "this boulder every time.$"

PeaksOfArbel_Text_AzriIntro:
	.string "So you are the pesk who's been meddling\n"
	.string "with my plans?\p"
	.string "{PLAYER}, right?\n"
	.string "I got eyes everywhere.\p"
	.string "I'm AZRI, the leader of TEAM SMASH.$"

PeaksOfArbel_Text_BenIntro:
	.string "{COLOR BLUE}BEN{COLOR DARK_GRAY}: Stop with this insane excavation of\n"
	.string "the ZIRCON gems.\p"
	.string "Those are not yours\n"
	.string "for the taking.$"

PeaksOfArbel_Text_AzriRevealsPlan:
	.string "{COLOR RED}AZRI{COLOR DARK_GRAY}: What we do in this cave is our own\n"
	.string "concern. This is none of your business.\p"
	.string "If you think you can stop us, then think\n"
	.string "again. I'm not going to let that happen.\p"
	.string "Those ZIRCON ORBs are already taken.\n"
	.string "these gems, along with the power of CELEBI\l"
	.string "will allow us to travel through time.\l"
	.string "So these converstaion will cease to exit.\p"
	.string "The flower nectars will sustain CELEBI's\n"
	.string "mind under our influence.\p"
	.string "We WILL catch that mystical beast.\n"
	.string "Mark my words.$"

PeaksOfArbel_Text_BenPlayerAreYouReady:
	.string "{PLAYER}, are you ready?\n"
	.string "This is not going to be an easy fight.\p"
	.string "We gotta get those goons outta here.\n"
	.string "Pick your strongest POKéMON for this.$"

PeaksOfArbel_Text_ThisIsNotOver:
	.string "This is not over…\n"
	.string "Not in a million years.$"

PeaksOfArbel_Text_NajeebDefeat:
	.string "I'm with our leader…$"

PeaksOfArbel_Text_AzriConfused:
	.string "This is outrageous.$"

PeaksOfArbel_Text_AzriDefeat:
	.string "Hehehe this was not suppose to happen…\n"
	.string "The gem stones are far off by now\p"
	.string "Our trucks have already left.\p"
	.string "We are going, this place is now useless\n"
	.string "to us. Don't follow us or you'll regret it.$"

PeaksOfArbel_Text_BenhankYouComeSeeMeAtMyResearchFacility:
	.string "{COLOR BLUE}BEN{COLOR DARK_GRAY}: Whew, that was intense.\n"
	.string "{PLAYER}, thank you.\p"
	.string "I have somethign to give you as\n"
	.string "thanks for your support.\p"
	.string "Please come see me at the KEREN\n"
	.string "Research Facility after this.\n"
	.string "Oh yeah, I don't live in PTOLEMAIS CITY.\n"
	.string "I live right here in KEREN CITY.$"

PeaksOfArbel_Text_Hiker:
	.string "Now that TEAM SMASH is gone, I can\n"
	.string "finally explore the cave.$"

PeaksOfArbel_Text_Maniac:
	.string "I want to reach the top of the peaks.\n"
	.string "I wonder what's up there.$"
