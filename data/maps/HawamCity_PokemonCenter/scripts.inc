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

