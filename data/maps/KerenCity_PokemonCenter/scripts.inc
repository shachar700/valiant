KerenCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KerenCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

KerenCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_KEREN_CITY
	end

KerenCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

KerenCity_PokemonCenter_EventScript_Youngster::
	msgbox KerenCity_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end
	
KerenCity_PokemonCenter_EventScript_Poochyena::
	msgbox KerenCity_PokemonCenter_Text_Poochyena, MSGBOX_NPC
	end

KerenCity_PokemonCenter_EventScript_Girl::
	msgbox KerenCity_PokemonCenter_Text_Girl, MSGBOX_NPC
	end

KerenCity_PokemonCenter_EventScript_Boy::
	msgbox KerenCity_PokemonCenter_Text_Boy, MSGBOX_NPC
	end

KerenCity_PokemonCenter_EventScript_Camper::
	msgbox KerenCity_PokemonCenter_Text_Camper, MSGBOX_NPC
	end

KerenCity_PokemonCenter_Text_Youngster:
	.string "My POOCHYENA had some rough time\n"
	.string "against the trainers nearby.\p"
	.string "We had to come to the POKéMON Center.$"

KerenCity_PokemonCenter_Text_Poochyena:
	.string "Poochi Pooch$"

KerenCity_PokemonCenter_Text_Girl:
	.string "The gem stone ZIRCON is very beautiful.\n"
	.string "I wish my boyfriend would give me one.$"

KerenCity_PokemonCenter_Text_Boy:
	.string "I like to collect rocks.\n"
	.string "I have a collection back home.$"

KerenCity_PokemonCenter_Text_Camper:
	.string "I tried to beat the gym leader\n"
	.string "but his POKéMON were too feisty.$"
