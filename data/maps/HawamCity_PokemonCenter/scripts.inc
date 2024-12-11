.set LOCALID_NURSE, 1

HawamCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HawamCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

HawamCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_HAWAM_CITY
	end

HawamCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

HawamCity_PokemonCenter_EventScript_Boy::
	msgbox HawamCity_PokemonCenter_Text_Boy, MSGBOX_NPC
	end

HawamCity_PokemonCenter_EventScript_Gentleman::
	msgbox HawamCity_PokemonCenter_Text_Gentleman, MSGBOX_NPC
	end

HawamCity_PokemonCenter_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox HawamCity_PokemonCenter_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

HawamCity_PokemonCenter_Text_Gentleman:
	.string "I feel the safest when I'm at the\n"
	.string "POKéMON Center.\p"
	.string "There are too many scandals going\n"
	.string "around outside.$"

HawamCity_PokemonCenter_Text_Boy:
	.string "My Skitty was not feeling so well\n"
	.string "so I took her to the POKéMON Center.\p"
	.string "I'm worried that it will happen when\n"
	.string "I'm far off HAWAM CITY.$"

HawamCity_PokemonCenter_Text_Skitty:
	.string "Skitti Ski$"
