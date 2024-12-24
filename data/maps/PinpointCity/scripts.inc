PinpointCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PinpointCity_OnTransition
	.byte 0

PinpointCity_OnTransition:
	setflag FLAG_VISITED_PINPOINT_CITY
	end
