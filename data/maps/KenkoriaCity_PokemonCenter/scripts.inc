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
