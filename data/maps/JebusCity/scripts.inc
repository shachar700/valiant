JebusCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JebusCity_OnTransition
	.byte 0

JebusCity_OnTransition:
	setflag FLAG_VISITED_JEBUS_CITY
	end
