GoliathCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoliathCity_OnTransition
	.byte 0

GoliathCity_OnTransition:
	setflag FLAG_VISITED_GOLIATH_CITY
	end
