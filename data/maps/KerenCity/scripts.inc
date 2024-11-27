KerenCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KerenCity_OnTransition
	.byte 0

KerenCity_OnTransition::
	call_if_eq VAR_RIVAL_NOA, 1, KerenCity_EventScript_SetNoaOut
	end

KerenCity_EventScript_SetNoaOut::
	setflag FLAG_HIDE_ROUTE_C_RIVAL
	setvar VAR_RIVAL_NOA, 2
	end

KerenCity_EventScript_CitySign::
	msgbox KerenCity_Text_CitySign, MSGBOX_SIGN
	end

KerenCity_EventScript_ResearchFacilitySign::
	msgbox KerenCity_Text_ResearchFacilitySign, MSGBOX_SIGN
	end

KerenCity_EventScript_DanceFestival::
	msgbox KerenCity_Text_DanceFestival, MSGBOX_NPC
	end

KerenCity_EventScript_ThereIsACave::
	msgbox KerenCity_Text_ThereIsACave, MSGBOX_NPC
	end

KerenCity_EventScript_ShhImHiding::
	msgbox KerenCity_Text_ShhImHiding, MSGBOX_NPC
	end

KerenCity_EventScript_CollectingNectar::
	msgbox KerenCity_Text_CollectingNectar, MSGBOX_NPC
	end

KerenCity_EventScript_ResearchFacility::
	msgbox KerenCity_Text_ResearchFacility, MSGBOX_NPC
	end

KerenCity_EventScript_CelebiSighting::
	msgbox KerenCity_Text_CelebiSighting, MSGBOX_NPC
	end

KerenCity_EventScript_SawSmashSighting::
	msgbox KerenCity_Text_SawSmashSighting, MSGBOX_NPC
	end

KerenCity_EventScript_GymSign::
	msgbox KerenCity_Text_GymSign, MSGBOX_SIGN
	end

KerenCity_EventScript_EmployeeQuestionOpportunity::
	lockall
	faceplayer
	goto_if_unset FLAG_REPEL_QUESTION_ENCOUNTER, KerenCity_EventScript_EmployeeQuestion
	msgbox KerenCity_Text_Employee_LotsOfTallGrass, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

KerenCity_EventScript_EmployeeQuestion::
	msgbox KerenCity_Text_EmployeeQuestion MSGBOX_DEFAULT
	waitmessage
	multichoice 20, 1, MULTI_REPEL_QUESTION, 1
	goto_if_eq VAR_RESULT, 1, KerenCity_EventScript_EmployeeQuestion_GiveRepel
	msgbox KerenCity_EventScript_EmployeeQuestion_TooBad MSGBOX_DEFAULT
	setflag FLAG_REPEL_QUESTION_ENCOUNTER
	closemessage
	releaseall
	end

KerenCity_EventScript_EmployeeQuestion_GiveRepel:
	msgbox KerenCity_Text_EmployeeQuestion_GreatJob MSGBOX_DEFAULT
	giveitem ITEM_REPEL
	setflag FLAG_REPEL_QUESTION_ENCOUNTER
	closemessage
	releaseall
	end

KerenCity_Text_SawSmashSighting:
	.string "I thought I saw TEAM SMASH traveling\n"
	.string "around here.\p"
	.string "Ever since they started showing up we\n"
	.string "had less visitors coming to KEREN CITY.\p"
	.string "They've been blocking the routes for\n"
	.string "their own purposes.$"

KerenCity_Text_CelebiSighting:
	.string "We used to have CELEBI sighting when it\n"
	.string "was quiter around here.$"

KerenCity_Text_Employee_LotsOfTallGrass:
	.string "There is a lot of tall grass EAST of\n"
	.string "KEREN CITY.\p"
	.string "I hope you stack up on some REPELs.$"

KerenCity_EventScript_EmployeeQuestion_TooBad:
	.string "Aw that's too bad,\n"
	.string "Wrong answer.$"

KerenCity_Text_EmployeeQuestion_GreatJob:
	.string "Nice work.\n"
	.string "Here is your REPEL.$"

KerenCity_Text_EmployeeQuestion:
	.string "I'll give you this free REPEL if you can\n"
	.string "answer my question.\p"
	.string "You only have one chance so make it\n"
	.string "count.\p"
	.string "How many steps REPEL, SUPER REPEL, and\n"
	.string "MAX REPEL prevent certain wild POKéMON?$"

KerenCity_Text_CollectingNectar:
	.string "I'm collecting nectar so we can study\n"
	.string "it in the facility.$"

KerenCity_Text_ShhImHiding:
	.string "Shhh I'm hiding.\n"
	.string "I don't wanna do chores.$"

KerenCity_Text_ThereIsACave:
	.string "There is a cave in KEREN CITY up NORTH.\p"
	.string "I'm too afraid to go inside.$"

KerenCity_Text_GymSign:
	.string "KEREN CITY GYM\n"
	.string "Where fist and kick blossom.$"

KerenCity_Text_DanceFestival:
	.string "The Keren Dance Festival typically\n"
	.string "takes place in Summer each year, spanning\l"
	.string "three days and featuring a variety of\l"
	.string "performances, workshops, and events.\p"
	.string "It's one of HAWAM's largest and most\n"
	.string "celebrated cultural festivals.$"

KerenCity_Text_ResearchFacility:
	.string "This is a research facility.\p"
	.string "It was designed to study plants,\n"
	.string "flowers, and POKéMON.\p"
	.string "There is a strong connection between\n"
	.string "flowers and POKéMON.$"

KerenCity_Text_CitySign:
	.string "KEREN CITY\n"
	.string "Rocky land and viberant dance festival.$"

KerenCity_Text_ResearchFacilitySign:
	.string "KEREN CITY Research Facility$"
