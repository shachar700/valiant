KerenCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KerenCity_OnTransition
	.byte 0

KerenCity_OnTransition::
	call_if_eq VAR_RIVAL_NOA, 1, KerenCity_EventScript_SetNoaOut
	end

KerenCity_EventScript_SetNoaOut::
	setflag FLAG_HIDE_ROUTE_C_RIVAL
	setvar VAR_RIVAL_NOA, 2
	end
