PeaksOfArbel_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PeaksOfArbel_2F_OnFrame
	.byte 0

PeaksOfArbel_2F_OnFrame:
	map_script_2 VAR_KEREN_CITY_GYM_STATE, 7, PeaksOfArbel_2F_EventScript_MoveTrucks
	.2byte 0

PeaksOfArbel_2F_EventScript_MoveTrucks::
	lock
	delay 30
	playse SE_PIN
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_TRUCK_MOVE
	applymovement 1, PeaksOfArbel_2F_Movement_TrucksOut
	applymovement 2, PeaksOfArbel_2F_Movement_TrucksOut
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	setflag FLAG_HIDE_PEAKS_OF_ARBEL_2F_TRUCKS
	setvar VAR_KEREN_CITY_GYM_STATE, 8
	delay 40
	release
	end

PeaksOfArbel_2F_Movement_TrucksOut:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PeaksOfArbel_2F_EventScript_HappyMeal::
	lock
	removeobject 6
	giveitem ITEM_HAPPY_MEAL
	setflag FLAG_HIDE_PEAKS_OF_ARBEL_2F_HAPPY_MEAL
	setflag FLAG_RECEVIED_HAPPY_MEAL
	release
	end
