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
	random 2
	copyvar VAR_KENKORIA_CITY_GYM_TRAINER_POTS, VAR_RESULT
	setvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 0
	setvar VAR_KEREN_CITY_GYM_STATE, 4
	closemessage
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
	goto_if_defeated TRAINER_DAISY, KenkoriaCity_Gym_Event_Girl2_FlowerPotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_LetsBattle, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_DAISY, KenkoriaCity_Gym_Text_Ouchies
	msgbox KenkoriaCity_Gym_Text_Girl2_FlowerPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_Event_Girl2_FlowerPotLocation:
	msgbox KenkoriaCity_Gym_Text_Girl2_FlowerPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_WellDone:
	msgbox KenkoriaCity_Gym_Text_WellDone, MSGBOX_NPC
	release
	end

KenkoriaCity_Gym_EventScript_RegularPot:
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_RegularPot_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_RegularPot_DecidesToWater:
	special DoWateringBerryTreeAnim
	waitstate
	release
	end

@ Start of Girl 2

KenkoriaCity_Gym_EventScript_Girl2_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl2_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Girl2_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	call_if_unset FLAG_DECORATION_1, KenkoriaCity_Gym_EventScript_Girl2_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Girl2_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_1
	closemessage
	return

@ End of Girl 2

@ Start of Beauty

KenkoriaCity_Gym_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_MELISSA, KenkoriaCity_Gym_EventScript_BeautyPotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_HiCutie, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_MELISSA, KenkoriaCity_Gym_Text_NotFair
	msgbox KenkoriaCity_Gym_Text_BeautyPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_BeautyPotLocation:
	msgbox KenkoriaCity_Gym_Text_BeautyPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Beauty_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Beauty_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Beauty_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Beauty_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Beauty_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Beauty_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Beauty_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_MELISSA, KenkoriaCity_Gym_EventScript_Beauty_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Beauty_CheckIfPicked:
	call_if_unset FLAG_DECORATION_2, KenkoriaCity_Gym_EventScript_Beauty_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Beauty_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_2
	closemessage
	return

@ End of Beauty

@ Start of Girl3

KenkoriaCity_Gym_EventScript_Girl3::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_BROOKE_1, KenkoriaCity_Gym_EventScript_Girl3PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_StrongVibes, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_BROOKE_1, KenkoriaCity_Gym_Text_SweetVictory
	msgbox KenkoriaCity_Gym_Text_Girl3PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Girl3PotLocation:
	msgbox KenkoriaCity_Gym_Text_Girl3PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Girl3_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Girl3_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl3_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Girl3_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Girl3_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl3_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Girl3_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_BROOKE_1, KenkoriaCity_Gym_EventScript_Girl3_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Girl3_CheckIfPicked:
	call_if_unset FLAG_DECORATION_3, KenkoriaCity_Gym_EventScript_Girl3_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Girl3_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_3
	closemessage
	return

@ End of Girl3

@ Start of Woman1

KenkoriaCity_Gym_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_CINDY_1, KenkoriaCity_Gym_EventScript_Woman1PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_FlowersAndGrass, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_CINDY_1, KenkoriaCity_Gym_Text_ImprovementsRequired
	msgbox KenkoriaCity_Gym_Text_Woman1PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Woman1PotLocation:
	msgbox KenkoriaCity_Gym_Text_Woman1PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Woman1_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman1_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman1_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman1_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman1_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman1_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Woman1_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_CINDY_1, KenkoriaCity_Gym_EventScript_Woman1_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Woman1_CheckIfPicked:
	call_if_unset FLAG_DECORATION_4, KenkoriaCity_Gym_EventScript_Woman1_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Woman1_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_4
	closemessage
	return

@ End of Woman1

@ Start of Woman5

KenkoriaCity_Gym_EventScript_Woman5::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_RACHEL, KenkoriaCity_Gym_EventScript_Woman5PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_LiftsSpirit, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_RACHEL, KenkoriaCity_Gym_Text_IShouldLiftHerSpirit
	msgbox KenkoriaCity_Gym_Text_Woman5PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Woman5PotLocation:
	msgbox KenkoriaCity_Gym_Text_Woman5PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Woman5_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman5_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman5_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman5_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman5_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman5_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Woman5_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_RACHEL, KenkoriaCity_Gym_EventScript_Woman5_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Woman5_CheckIfPicked:
	call_if_unset FLAG_DECORATION_5, KenkoriaCity_Gym_EventScript_Woman5_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Woman5_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_5
	closemessage
	return

@ End of Woman5

@ Start of Woman3

KenkoriaCity_Gym_EventScript_Woman3::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_ROSE_1, KenkoriaCity_Gym_EventScript_Woman3PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_AlwaysRight, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_ROSE_1, KenkoriaCity_Gym_Text_EvenWhenImWrong
	msgbox KenkoriaCity_Gym_Text_Woman3PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Woman3PotLocation:
	msgbox KenkoriaCity_Gym_Text_Woman3PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Woman3_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman3_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman3_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman3_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_Woman3_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman3_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Woman3_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_ROSE_1, KenkoriaCity_Gym_EventScript_Woman3_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Woman3_CheckIfPicked:
	call_if_unset FLAG_DECORATION_6, KenkoriaCity_Gym_EventScript_Woman3_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Woman3_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_6
	closemessage
	return

@ End of Woman3

@ Start of PokeFanF

KenkoriaCity_Gym_EventScript_PokeFanF::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_VICTORIA, KenkoriaCity_Gym_EventScript_PokeFanFPotLocation
	playbgm MUS_ENCOUNTER_TWINS, FALSE
	msgbox KenkoriaCity_Gym_Text_OldAsMe, MSGBOX_DEFAULT
	clearflag FLAG_KENKORIA_CITY_GYM_PICK_FLOWER
	trainerbattle_no_intro TRAINER_VICTORIA, KenkoriaCity_Gym_Text_IShouldRest
	msgbox KenkoriaCity_Gym_Text_PokeFanFPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_PokeFanFPotLocation:
	msgbox KenkoriaCity_Gym_Text_PokeFanFPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_PokeFanF_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_PokeFanF_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_PokeFanF_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_PokeFanF_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_PokeFanF_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_PokeFanF_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_PokeFanF_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_VICTORIA, KenkoriaCity_Gym_EventScript_PokeFanF_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_PokeFanF_CheckIfPicked:
	call_if_unset FLAG_DECORATION_6, KenkoriaCity_Gym_EventScript_PokeFanF_PickedFlower
	return

KenkoriaCity_Gym_EventScript_PokeFanF_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_6
	closemessage
	return

@ End of PokeFanF


KenkoriaCity_Gym_EventScript_Teala::
	lock
	faceplayer 
	@delete when done testing
	buffernumberstring STR_VAR_2, VAR_KENKORIA_CITY_GYM_TRAINER_POTS
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
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

KenkoriaCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, KenkoriaCity_Gym_EventScript_GymStatueCertified
	goto KenkoriaCity_Gym_EventScript_GymStatue
	end

KenkoriaCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, KenkoriaCity_Gym_EventScript_GymStatueCertified
	goto KenkoriaCity_Gym_EventScript_GymStatue
	end

KenkoriaCity_Gym_EventScript_GymStatueCertified::
	msgbox KenkoriaCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

KenkoriaCity_Gym_EventScript_GymStatue::
	msgbox KenkoriaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

KenkoriaCity_Gym_EventScript_Teala_LetsSee:
	.string "Lets see how many flowers you have\n"
	.string "collected. (Test: {STR_VAR_2})\p"
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

KenkoriaCity_Gym_Text_ReceivedFlower:
	.string "{PLAYER} received a flower.$"

KenkoriaCity_Gym_Text_WaterPot:
	.string "Water the plant?$"

KenkoriaCity_Gym_Text_Ouchies:
	.string "Ouchies. Good fight pal.$"

KenkoriaCity_Gym_Text_LetsBattle:
	.string "Lets battle! I'll show you where my plant\n"
	.string "is if you win.$"

KenkoriaCity_Gym_Text_Girl2_FlowerPotLocation:
	.string "My flower pot is to the left.$"

KenkoriaCity_Gym_Text_HiCutie:
	.string "Hi cutie! Hope you are ready for some\n"
	.string "GRASS type POKéMON!$"

KenkoriaCity_Gym_Text_NotFair:
	.string "Not fair! I was blinking.$"

KenkoriaCity_Gym_Text_BeautyPotLocation:
	.string "A flower frozen in time's embrace,\n"
	.string "No sunlight warms this vibrant place.\p"
	.string "Its petals rest on crafted ground,\n"
	.string "The beauty pot lies just around.$"

KenkoriaCity_Gym_Text_StrongVibes:
	.string "I'm sensing strong vibes from you.\n"
	.string "Lets see you in battle.$"

KenkoriaCity_Gym_Text_SweetVictory:
	.string "Sweet victory.\n"
	.string "From your end.$"

KenkoriaCity_Gym_EventScript_Girl3PotLocation:
	.string "You see my flower pot when you first\n"
	.string "enter the gym.$"

KenkoriaCity_Gym_Text_FlowersAndGrass:
	.string "Flowers and grass are pretty, ain't\n"
	.string "them?\p"
	.string "The grass blades are vibrant with\n"
	.string "colors.$"

KenkoriaCity_Gym_Text_ImprovementsRequired:
	.string "Improvements are required.\n"
	.string "My BULBASAUR gave its best.$"

KenkoriaCity_Gym_Text_Woman1PotLocation:
	.string "My flowers are in the bin.$"

KenkoriaCity_Gym_Text_LiftsSpirit:
	.string "My GRASS POKéMON always lift my spirit\n"
	.string "when I feel down or depressed.$"

KenkoriaCity_Gym_Text_IShouldLiftHerSpirit:
	.string "I should lift their spirit too.$"

KenkoriaCity_Gym_Text_Woman5PotLocation:
	.string "My flowers are red or white like me.$"

KenkoriaCity_Gym_Text_AlwaysRight:
	.string "I'm always right. We should battle so\n"
	.string "I can prove it to you.$"

KenkoriaCity_Gym_Text_EvenWhenImWrong:
	.string "Even when I'm wrong I'm right.$"

KenkoriaCity_Gym_Text_Woman3PotLocation:
	.string "I adore POKéBALLs.\n"
	.string "My flower pot is just like me.\p"
	.string "I'm always right.\n"
	.string "Even when I'm wrong.$"

KenkoriaCity_Gym_Text_OldAsMe:
	.string "When you become as old as I am, you\n"
	.string "tend to slow things down.\p"
	.string "There's tomorrow we can attend to.$"

KenkoriaCity_Gym_Text_IShouldRest:
	.string "Great battle!\n"
	.string "I should take a rest.$"

KenkoriaCity_Gym_Text_PokeFanFPotLocation:
	.string "When I tend my flowers I bring a stool.$"

KenkoriaCity_Gym_Text_WellDone:
	.string "Well done beating the gym.$"

KenkoriaCity_Gym_Text_GymGuideAdvice:
	.string "Welcome to this unique flower shop gym.\p"
	.string "In here you will have to find 10 flowers\n"
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

KenkoriaCity_Gym_Text_GymStatue:
	.string "KENKORIA CITY POKéMON GYM$"

KenkoriaCity_Gym_Text_GymStatueCertified:
	.string "KENKORIA CITY POKéMON GYM\p"
	.string "MICHAL'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

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
