.set LOCALID_MAN_4, 12

RouteD_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteD_OnTransition
	.byte 0

RouteD_OnTransition:
	call_if_set FLAG_DEFEATED_KEREN_GYM, RouteD_EventScript_MoveShinyHunter
	end

RouteD_EventScript_MoveShinyHunter:
	setobjectxyperm LOCALID_MAN_4, 16, 38
	setobjectmovementtype LOCALID_MAN_4, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	return	

RouteD_MoveShinyHunter:
	setobjectxy LOCALID_MAN_4, 16, 38
	end

RouteD_EventScript_Trigger_ShinyHunt::
	lock
	playse SE_PIN
	applymovement LOCALID_MAN_4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAN_4, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RouteD_Text_Trigger_ShinyHunt, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RouteD_Movement_PlayerStepBack
	waitmovement 0
	release
	end

RouteD_EventScript_Man_4::
	msgbox RouteD_Text_Man_4, MSGBOX_NPC
	end

RouteD_EventScript_Boy_3::
	msgbox RouteD_Text_Boy_3, MSGBOX_NPC
	end

RouteD_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

RouteD_Text_Trigger_ShinyHunt:
	.string "I'm shiny hunting ILLUMISE and VULBEAT.\n"
	.string "Please come back later!\l"
	.string "Maybe after you get KEREN's gym badge.$"

RouteD_Text_Man_4:
	.string "Ugh I couldn't find them.\n"
	.string "Why is it so difficult,\l"
	.string "to find shiny POKéMON, that is.$"

RouteD_Text_Boy_3:
	.string "So much tall grass in this route!\p"
	.string "You can use {COLOR RED}HM01 CUT{COLOR DARK_GRAY} to clear a path.\n"
	.string "Just teach it to one of your POKéMON\l"
	.string "and use it on tall grass.$"
