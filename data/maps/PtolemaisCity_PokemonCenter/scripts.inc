PtolemaisCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PtolemaisCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PtolemaisCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_PTOLEMAIS_CITY
	end

PtolemaisCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PtolemaisCity_PokemonCenter_EventScript_RichBoy::
	msgbox PtolemaisCity_PokemonCenter_Text_RichBoy, MSGBOX_NPC
	end

PtolemaisCity_PokemonCenter_EventScript_Dusclops::
	msgbox PtolemaisCity_PokemonCenter_Text_Dusclops, MSGBOX_NPC
	end

PtolemaisCity_PokemonCenter_EventScript_Youngster1::
	msgbox PtolemaisCity_PokemonCenter_Text_Youngster1, MSGBOX_NPC
	end

PtolemaisCity_PokemonCenter_EventScript_Youngster2::
	msgbox PtolemaisCity_PokemonCenter_Text_Youngster2, MSGBOX_NPC
	end

PtolemaisCity_PokemonCenter_Text_RichBoy:
	.string "There was a cute lady at the outskirts\n"
	.string "of PTOLEMAIS CITY.\p"
	.string "I wonder if she's single.$"

PtolemaisCity_PokemonCenter_Text_Dusclops:
	.string "Duuuuu…sc…\p"
	.string "Dusc…lops$"

PtolemaisCity_PokemonCenter_Text_Youngster1:
	.string "I've heard there was a secret chord\n"
	.string "That David played, and it pleased the\l"
	.string "Lord.\p"
	.string "But you don't really care for music,\n"
	.string "do you?$"

PtolemaisCity_PokemonCenter_Text_Youngster2:
	.string "My friend here likes to sing.\p"
	.string "I hope it attracts POKéMON\n"
	.string "in the wild.$"