PeaksOfArbel_MapScripts::
	.byte 0

PeaksOfArbel_EventScript_Box::
	msgbox PeaksOfArbel_Text_Box, MSGBOX_NPC
	end

PeaksOfArbel_Text_Box:
	.string "It says on the box:\n"
	.string "PROPERTY OF TEAM SMASH.\p"
	.string "Tasked with blocking unwanted guests.$"

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
