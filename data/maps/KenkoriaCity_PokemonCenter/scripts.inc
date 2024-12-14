.set LOCALID_NURSE, 1

KenkoriaCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KenkoriaCity_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

KenkoriaCity_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_KENKORIA_CITY
	end

KenkoriaCity_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

KenkoriaCity_PokemonCenter_EventScript_BlackBelt::
	msgbox KenkoriaCity_PokemonCenter_Text_BlackBelt, MSGBOX_NPC
	end

KenkoriaCity_PokemonCenter_EventScript_Woman1::
	msgbox KenkoriaCity_PokemonCenter_Text_Woman1, MSGBOX_NPC
	end

KenkoriaCity_PokemonCenter_EventScript_Boy2::
	msgbox KenkoriaCity_PokemonCenter_Text_Boy2, MSGBOX_NPC
	end

KenkoriaCity_PokemonCenter_EventScript_Youngster::
	msgbox KenkoriaCity_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

KenkoriaCity_PokemonCenter_Text_BlackBelt:
	.string "There's a SAFARI ZONE EAST of here.\n"
	.string "My DUDUO is from there.$"

KenkoriaCity_PokemonCenter_Text_Woman1:
	.string "I wanted to get to PINPOINT CITY but I\n"
	.string "got blocked by TEAM SMASH.\p"
	.string "I had to run back to the POKéMON\n"
	.string "CENTER after battling with them.$"

KenkoriaCity_PokemonCenter_Text_Boy2:
	.string "We get a lot of visitors who want to\n"
	.string "resupply or obtain a bicycle.$"

KenkoriaCity_PokemonCenter_Text_Youngster:
	.string "MICHAL the gym leader is top notch.\n"
	.string "She is so cool and pretty.$"
