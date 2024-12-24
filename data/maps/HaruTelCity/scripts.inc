HaruTelCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HaruTelCity_OnTransition
	.byte 0

HaruTelCity_OnTransition:
	setflag FLAG_VISITED_HARU_TEL_CITY
	end
