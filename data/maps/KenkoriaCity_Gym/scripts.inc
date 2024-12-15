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

KenkoriaCity_Gym_EventScript_RegularPot::
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Beauty_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Beauty_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl3_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Girl3_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman1_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman1_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman5_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman5_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman3_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman3_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_PokeFanF_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_PokeFanF_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
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
	call_if_unset FLAG_DECORATION_7, KenkoriaCity_Gym_EventScript_PokeFanF_PickedFlower
	return

KenkoriaCity_Gym_EventScript_PokeFanF_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_7
	closemessage
	return

@ End of PokeFanF

@ Start of Woman4

KenkoriaCity_Gym_EventScript_Woman4::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_VICKY, KenkoriaCity_Gym_EventScript_Woman4PotLocation
	playbgm MUS_ENCOUNTER_INTENSE, FALSE
	msgbox KenkoriaCity_Gym_Text_AlwaysMoving, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, KenkoriaCity_Gym_Text_RestWhenImDead
	msgbox KenkoriaCity_Gym_Text_Woman4PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Woman4PotLocation:
	msgbox KenkoriaCity_Gym_Text_Woman4PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Woman4_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman4_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman4_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman4_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Woman4_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_VICKY, KenkoriaCity_Gym_EventScript_Woman4_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Woman4_CheckIfPicked:
	call_if_unset FLAG_DECORATION_8, KenkoriaCity_Gym_EventScript_Woman4_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Woman4_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_8
	closemessage
	return

@ End of Woman4

@ Start of Picnicker

KenkoriaCity_Gym_EventScript_Picnicker::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_CELIA, KenkoriaCity_Gym_EventScript_PicnickerPotLocation
	playbgm MUS_ENCOUNTER_INTENSE, FALSE
	msgbox KenkoriaCity_Gym_Text_LoveWeed, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CELIA, KenkoriaCity_Gym_Text_BroThatWasRad
	msgbox KenkoriaCity_Gym_Text_PicnickerPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_PicnickerPotLocation:
	msgbox KenkoriaCity_Gym_Text_PicnickerPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Picnicker_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Picnicker_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Picnicker_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Picnicker_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Picnicker_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_CELIA, KenkoriaCity_Gym_EventScript_Picnicker_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Picnicker_CheckIfPicked:
	call_if_unset FLAG_DECORATION_9, KenkoriaCity_Gym_EventScript_Picnicker_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Picnicker_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_9
	closemessage
	return

@ End of Picnicker

@ Start of Woman2

KenkoriaCity_Gym_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_LYDIA_2, KenkoriaCity_Gym_EventScript_Woman2PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_GotACrush, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LYDIA_2, KenkoriaCity_Gym_Text_HopeMichalDidntSee
	msgbox KenkoriaCity_Gym_Text_Woman2PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Woman2PotLocation:
	msgbox KenkoriaCity_Gym_Text_Woman2PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Woman2_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman2_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Woman2_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Woman2_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Woman2_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_LYDIA_2, KenkoriaCity_Gym_EventScript_Woman2_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Woman2_CheckIfPicked:
	call_if_unset FLAG_DECORATION_10, KenkoriaCity_Gym_EventScript_Woman2_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Woman2_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_10
	closemessage
	return

@ End of Woman2

@ Start of Girl1

KenkoriaCity_Gym_EventScript_Girl1::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_CELINA, KenkoriaCity_Gym_EventScript_Girl1PotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_FlowersAreBeautiful, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CELINA, KenkoriaCity_Gym_Text_NoWay
	msgbox KenkoriaCity_Gym_Text_Girl1PotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_Girl1PotLocation:
	msgbox KenkoriaCity_Gym_Text_Girl1PotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Girl1_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl1_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Girl1_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Girl1_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Girl1_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_CELINA, KenkoriaCity_Gym_EventScript_Girl1_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Girl1_CheckIfPicked:
	call_if_unset FLAG_DECORATION_11, KenkoriaCity_Gym_EventScript_Girl1_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Girl1_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_11
	closemessage
	return

@ End of Girl1

@ Start of Lass

KenkoriaCity_Gym_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, KenkoriaCity_Gym_EventScript_WellDone
	goto_if_defeated TRAINER_CINDY_2, KenkoriaCity_Gym_EventScript_LassPotLocation
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	msgbox KenkoriaCity_Gym_Text_MichalHasPassion, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CINDY_2, KenkoriaCity_Gym_Text_GreatBattle
	msgbox KenkoriaCity_Gym_Text_LassPotLocation, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_LassPotLocation:
	msgbox KenkoriaCity_Gym_Text_LassPotLocation, MSGBOX_NPC
	end

KenkoriaCity_Gym_EventScript_Lass_PotA::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 1, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Lass_DecidesToWater
	release
	end

KenkoriaCity_Gym_EventScript_Lass_PotB::
	lock
	goto_if_eq VAR_KENKORIA_CITY_GYM_TRAINER_POTS, 0, KenkoriaCity_Gym_EventScript_RegularPot
	msgbox KenkoriaCity_Gym_Text_WaterPot, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KenkoriaCity_Gym_EventScript_Lass_DecidesToWater
	release
	end


KenkoriaCity_Gym_EventScript_Lass_DecidesToWater:
	@do watering animation
	special DoWateringBerryTreeAnim
	waitstate
	@if defated trainer and visited once
	call_if_defeated TRAINER_CINDY_2, KenkoriaCity_Gym_EventScript_Lass_CheckIfPicked
	release
	end

KenkoriaCity_Gym_EventScript_Lass_CheckIfPicked:
	call_if_unset FLAG_DECORATION_12, KenkoriaCity_Gym_EventScript_Lass_PickedFlower
	return

KenkoriaCity_Gym_EventScript_Lass_PickedFlower:
	playfanfare MUS_OBTAIN_ITEM
	msgbox KenkoriaCity_Gym_Text_ReceivedFlower, MSGBOX_DEFAULT
	waitfanfare
	addvar VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 1
	setflag FLAG_DECORATION_12
	closemessage
	return

@ End of Lass

KenkoriaCity_Gym_EventScript_Michal::
	lock
	goto_if_lt VAR_KENKORIA_CITY_GYM_FLOWERS_COUNTER, 10, KenkoriaCity_Gym_EventScript_NotEnoughFlowers
	trainerbattle_single TRAINER_WATTSON_1, KenkoriaCity_Gym_Text_MichalIntro, KenkoriaCity_Gym_Text_MichalDefeat, KenkoriaCity_Gym_EventScript_MichalDefeated, NO_MUSIC
	msgbox KenkoriaCity_Gym_Text_MichalPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

KenkoriaCity_Gym_EventScript_NotEnoughFlowers:
	msgbox KenkoriaCity_Gym_Text_NotEnoughFlowers, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Gym_EventScript_MichalDefeated::
	message KenkoriaCity_Gym_Text_ReceivedBloomBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainBloomBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_KENKORIA_CITY_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_KEREN_CITY_STATE, 1
	addvar VAR_KEREN_CITY_GYM_STATE, 1
	call KenkoriaCity_Gym_EventScript_GiveBulletSeed
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	return

KenkoriaCity_Gym_EventScript_GiveBulletSeed::
	giveitem ITEM_TM_BULLET_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox KenkoriaCity_Gym_Text_GiveBulletSeed, MSGBOX_DEFAULT
	return


KenkoriaCity_Gym_EventScript_Teala::
	lock
	faceplayer
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

KenkoriaCity_Gym_Text_NotEnoughFlowers:
	.string "Hello there and welcome to my POKéMON\n"
	.string "gym challenge.\p"
	.string "I'm MICHAL, I attend these flowers with\n"
	.string "my helpful assistants.\p"
	.string "Lets see how many flowers you have\n"
	.string "collected.\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "It seems like you haven't picked enough\n"
	.string "flowers to challenge me.\p"
	.string "Come to me when you got at least 10\n"
	.string "flowers in your possession.\p"
	.string "The lady at the center will tell you how\n"
	.string "many you got on you.$"

KenkoriaCity_Gym_Text_MichalIntro:
	.string "I'm MICHAL, I run this flower shop gym.\p"
	.string "This city has developed into a modern\n"
	.string "city with roads and bikes.\p"
	.string "We are still staying connected to earth\n"
	.string "with our attention to the planet.\p"
	.string "It seems like you have collected\n"
	.string "enough flowers to challenge me,\l"
	.string "after tending with the Wailmer Pail.\p"
	.string "Lets see if you are good in battle as\n"
	.string "much as you are good at gardening.$"

KenkoriaCity_Gym_Text_MichalDefeat:
	.string "Wow! Such power! Such performance!\n"
	.string "You have beaten my powerful team!\p"
	.string "You've got me, I'm very impressed.\n"
	.string "Please, take this GYM BADGE.$"

KenkoriaCity_Gym_Text_ReceivedBloomBadge:
	.string "{PLAYER} received the BLOOM BADGE\n"
	.string "from MICHAL.$"

MauvilleCity_Gym_Text_ExplainBloomBadgeTakeThis:
	.string "With the BLOOM BADGE, POKéMON can\n"
	.string "use ROCK SMASH out of battle.\p"
	.string "And, it will make your POKéMON a little\n"
	.string "bit faster, too.\p"
	.string "Hmm…\n"
	.string "You should take this, too!$"

KenkoriaCity_Gym_Text_GiveBulletSeed:
	.string "That TM09 contains Bullet Seed.\p"
	.string "It shoots 2 to 5 seeds in a row to\n"
	.string "strike your opponent into submission!\p"
	.string "… … … … … …$"

KenkoriaCity_Gym_Text_MichalPostBattle:
	.string "Good luck in your future endeavors. I\n"
	.string "hope you had fun tending the flowers.$"

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

KenkoriaCity_Gym_Text_Girl3PotLocation:
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

KenkoriaCity_Gym_Text_AlwaysMoving:
	.string "I'm always moving to keep myself busy.$"

KenkoriaCity_Gym_Text_RestWhenImDead:
	.string "I'll rest when I die.$"

KenkoriaCity_Gym_Text_Woman4PotLocation:
	.string "I like my flowers at the center of\n"
	.string "attention.$"

KenkoriaCity_Gym_Text_LoveWeed:
	.string "I love weed. It's so relaxing.$"

KenkoriaCity_Gym_Text_BroThatWasRad:
	.string "Bro… that was rad…$"

KenkoriaCity_Gym_Text_PicnickerPotLocation:
	.string "My weed is somewhere around here…\n"
	.string "I'm sure of it…$"

KenkoriaCity_Gym_Text_GotACrush:
	.string "I got a crush on MICHAL\n"
	.string "I hope she feels the same way.$"

KenkoriaCity_Gym_Text_HopeMichalDidntSee:
	.string "Ugh I hope MICHAL didn't see that.$"

KenkoriaCity_Gym_Text_Woman2PotLocation:
	.string "I've put my flower pot near MICHAL so\n"
	.string "that she will notice me.$"

KenkoriaCity_Gym_Text_FlowersAreBeautiful:
	.string "Flowers are beautiful.\n"
	.string "Don't you think?$"

KenkoriaCity_Gym_Text_NoWay:
	.string "No way… how did that happen?$"

KenkoriaCity_Gym_Text_Girl1PotLocation:
	.string "I like to see my flower pot when I walk\n"
	.string "through the gym to the shelves.\p"
	.string "I go through the right corridor and\n"
	.string "smell its scent.$"

KenkoriaCity_Gym_Text_MichalHasPassion:
	.string "MICHAL has strong passion towards\n"
	.string "POKéMON, people and plants.\p"
	.string "She encourages so many people to do\n"
	.string "good in life.$"

KenkoriaCity_Gym_Text_GreatBattle:
	.string "That was a great battle.\n"
	.string "I got outmatched.$"

KenkoriaCity_Gym_Text_LassPotLocation:
	.string "My plant could be a flower or weed,\n"
	.string "It's hard to recall, indeed.\p"
	.string "It could be near or far away,\n"
	.string "Or tiny or grand, who's to say?$"

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
