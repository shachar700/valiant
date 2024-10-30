.set LOCALID_CELEBI, 4

SerenityLake_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SerenityLake_OnTransition
	.byte 0

SerenityLake_OnTransition:
	setflag FLAG_SYS_B_DASH
	end

SerenityLake_EventScript_Celebi::
	lockall
	setrespawn HEAL_LOCATION_HAWAM_CITY
	applymovement LOCALID_CELEBI, CelebiApproaches
	waitmovement 0
	playmoncry SPECIES_CELEBI, 0
	msgbox SerenityLake_Text_Celebi, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_CELEBI, CelebiLeaves
	waitmovement 0
	warp MAP_HAWAM_CITY_PLAYERS_HOUSE_2F, 8, 5
	waitstate
	releaseall
	end

SerenityLake_EventScript_Sign::
	msgbox SerenityLake_Text_Sign, MSGBOX_SIGN
	end

SerenityLake_EventScript_SmashFemale::
	msgbox SerenityLake_Text_SmashFemale, MSGBOX_NPC
	end

SerenityLake_EventScript_SmashMale1::
	msgbox SerenityLake_Text_SmashMale1, MSGBOX_NPC
	end

SerenityLake_EventScript_SmashMale2::
	msgbox SerenityLake_Text_SmashMale2, MSGBOX_NPC
	end

SerenityLake_Text_Celebi::
	.string "{COLOR GREEN}Celebi:{COLOR DARK_GRAY} Cele...biiiii...\p"
	.string "The sound coming from Celebi's voice\n"
	.string "sounded like a stress signal.$"

SerenityLake_Text_Sign:
	.string "Serenity Lake\n"
	.string "Relaxing resident for POKéMON.$"

SerenityLake_Text_SmashFemale:
	.string "Serenity Lake has been known to be a\n"
	.string "relaxing resident for POKéMON.\p"
	.string "It's deep in the woods so people can not\n"
	.string "reach it so easily.$"

SerenityLake_Text_SmashMale1:
	.string "Do not interfere, kid.\p"
	.string "We are investigating the Serenity Lake.$"

SerenityLake_Text_SmashMale2:
	.string "Woah kid, where did you come from?\p"
	.string "Team SMASH is not yet suitable for kids\n"
	.string "to join.$"

CelebiApproaches:
	walk_down
	walk_down
	face_right
	delay_16
	face_left
	delay_16
	face_down
	step_end
	
CelebiLeaves:
	walk_up	
	walk_up	
	walk_up	
	walk_up	
	delay_8
	step_end
