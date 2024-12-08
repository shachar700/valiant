.set LOCALID_RECEPTIONIST, 12

KenkoriaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KenkoriaCity_Gym_OnFrame
	.byte 0

KenkoriaCity_Gym_OnFrame:
	map_script_2 VAR_KEREN_CITY_GYM_STATE, 2, KenkoriaCity_Gym_EventScript_NoWailmerPail
	.2byte 0

KenkoriaCity_Gym_EventScript_NoWailmerPail:
	lock
	playse SE_PIN
	applymovement LOCALID_RECEPTIONIST, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	applymovement LOCALID_RECEPTIONIST, KenkoriaCity_Gym_Movement_ApproachPlayer
	waitmovement 0
	msgbox KenkoriaCity_Text_NoWailmerPail, MSGBOX_DEFAULT
	applymovement LOCALID_RECEPTIONIST, KenkoriaCity_Gym_Movement_GoBackToSpot
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, KenkoriaCity_Gym_Movement_PlayerWalksDown
	warp MAP_KENKORIA_CITY, 21, 20
	waitstate
	release
	end

KenkoriaCity_Gym_EventScript_Receptionist:
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_GymGuidePostVictory
	msgbox KenkoriaCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Gym_EventScript_GymGuidePostVictory::
	msgbox KenkoriaCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Gym_Text_GymGuideAdvice:
	.string "Welcome to this unique flower gym\p"
	.string "In here you will have to find\n"
	.string "{COLOR BLUE}3 blue{COLOR DARK_GRAY}, {COLOR RED}3 red{COLOR DARK_GRAY}, and {COLOR GREEN}3 green flowers{COLOR DARK_GRAY}.\p"
	.string "You will need to battle trainers, water\n"
	.string "plants and obtain flowers in that order.\p"
	.string "Each trainer has its own plant pot.\p"
	.string "You'll get a flower from the pot,\n"
	.string "in return for battling them.\p"
	.string "You'd need to water the plant pot.\p"
	.string "Good luck!$"

KenkoriaCity_Gym_Text_GymGuidePostVictory:
	.string "Well done dear!\n"
	.string "You've crushed this gym challenge.\p"
	.string "Strive and flourish like the flowers.$"

KenkoriaCity_Text_NoWailmerPail:
	.string "Oh hello dear!\p"
	.string "Welcome to the KENKORIA CITY Gym!\n"
	.string "You'd need Wailmer Pail to proceed.\p"
	.string "You can get one from the flower shop\n"
	.string "in this city, SOUTH-WEST of here.$"

KenkoriaCity_Gym_Movement_ApproachPlayer:
	walk_down
	walk_right
	face_down
	delay_8
	step_end

KenkoriaCity_Gym_Movement_GoBackToSpot:
	walk_left
	walk_up
	face_down
	delay_8
	step_end

KenkoriaCity_Gym_Movement_PlayerWalksDown:
	walk_in_place_faster_down
	step_end
