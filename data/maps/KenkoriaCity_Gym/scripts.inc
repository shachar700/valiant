.set LOCALID_RECEPTIONIST, 12

KenkoriaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KenkoriaCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KenkoriaCity_Gym_OnFrame
	.byte 0

KenkoriaCity_Gym_OnFrame:
	map_script_2 VAR_KEREN_CITY_GYM_STATE, 2, KenkoriaCity_Gym_EventScript_NoWailmerPail
	.2byte 0

KenkoriaCity_Gym_OnTransition:
	goto_if_eq VAR_KEREN_CITY_GYM_STATE, 3, KenkoriaCity_Gym_EventScript_InitPots
	end

KenkoriaCity_Gym_EventScript_InitPots:
	random 1024
	copyvar VAR_KENKORIA_CITY_GYM_TRAINER_POTS, VAR_RESULT
	setvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 0
	setvar VAR_KEREN_CITY_GYM_STATE, 4
	end

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

KenkoriaCity_Gym_EventScript_Receptionist::
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

KenkoriaCity_Gym_EventScript_Girl2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_DAISY, KenkoriaCity_Gym_Event_FlowerPotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_LetsBattle, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_DAISY, KenkoriaCity_Gym_Text_Ouchies
	msgbox KenkoriaCity_Gym_Text_FlowerPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_Event_FlowerPotLocation:
	msgbox KenkoriaCity_Gym_Text_FlowerPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_WellDone:
	msgbox KenkoriaCity_Gym_Text_WellDone, MSGBOX_NPC
	release
	end

KenkoriaCity_Gym_EventScript_Girl2_Pot::
	lock
	msgbox KenkoriaCity_Gym_Text_Girl2_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl2_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Girl2_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_DAISY, KenkoriaCity_Gym_EventScript_Girl2_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Girl2_CheckIfPicked:
	call_if_unset FLAG_KENKORIA_CITY_GYM_PICK_FLOWER, KenkoriaCity_Gym_EventScript_Girl2_BlueFlower
	return

KenkoriaCity_Gym_EventScript_Girl2_BlueFlower:
	@msgbox received blue flower
	@addvar var_counter_blue_flower
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_Girl2_BlueFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	closemessage
	return

KenkoriaCity_Gym_EventScript_Teala::
	lock
	faceplayer 
	msgbox KenkoriaCity_Gym_EventScript_Teala_LetsSee, MSGBOX_DEFAULT
	goto_if_eq VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 0, KenkoriaCity_Gym_EventScript_Teala_NoFlowers
	goto_if_eq VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1, KenkoriaCity_Gym_EventScript_Teala_OneFlower
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	buffernumberstring STR_VAR_1, VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER
	msgbox KenkoriaCity_Gym_Text_Teala_FlowerCounter, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Teala_NoFlowers:
	msgbox KenkoriaCity_Gym_Text_Teala_NoFlowers, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Teala_OneFlower:
	msgbox KenkoriaCity_Gym_Tesxt_Teala_OneFlower, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Teala_LetsSee:
	.string "Lets see how many flowers you have\n"
	.string "collected.\p"
	.string "… … …\n"
	.string "… … …$"

KenkoriaCity_Gym_Text_Teala_NoFlowers:
	.string "It seems like you haven't picked up any\n"
	.string "flowers yet.$"

KenkoriaCity_Gym_Tesxt_Teala_OneFlower:
	.string "You have collected 1 flower so far.\n"
	.string "Keep it up!$"

KenkoriaCity_Gym_Text_Teala_FlowerCounter:
	.string "You have collected {STR_VAR_1} flowers so far.\n"
	.string "Keep it up!$"

KenkoriaCity_Gym_Text_Girl2_BlueFlower:
	.string "{PLAYER} received a flower.$"

KenkoriaCity_Gym_Text_Girl2_WaterPot:
	.string "Water the plant?$"

KenkoriaCity_Gym_Text_Ouchies:
	.string "Ouchies. Good fight pal.$"

KenkoriaCity_Gym_Text_LetsBattle:
	.string "Lets battle! I'll show you where my plant\n"
	.string "is if you win.$"

KenkoriaCity_Gym_Text_FlowerPotLocation:
	.string "My flower pot is down from here to\n"
	.string "the left.$"

KenkoriaCity_Gym_Text_WellDone:
	.string "Well done beating the gym.$"

KenkoriaCity_Gym_Text_GymGuideAdvice:
	.string "Welcome to this unique flower shop gym\p"
	.string "In here you will have to find 15 flowers\n"
	.string "in different locations.\p"
	.string "You will have to battle trainers, water\n"
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
