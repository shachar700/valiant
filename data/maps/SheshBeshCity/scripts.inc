SheshBeshCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SheshBeshCity_OnTransition
	.byte 0

SheshBeshCity_OnTransition:
	setflag FLAG_VISITED_SHESH_BESH_CITY
	end
