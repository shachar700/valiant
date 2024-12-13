KerenCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KerenCity_Gym_OnTransition
	.byte 0

KerenCity_Gym_OnTransition:
	call KerenCity_Gym_EventScript_SetFlashLevel
	end

KerenCity_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, KerenCity_Gym_EventScript_SetLightsOn
	call KerenCity_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, KerenCity_Gym_EventScript_SetFlashLevel8
	goto_if_eq VAR_0x8000, 2, KerenCity_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 3, KerenCity_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 4, KerenCity_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 5, KerenCity_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 6, KerenCity_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 7, KerenCity_Gym_EventScript_SetFlashLevel2
	goto KerenCity_Gym_EventScript_SetFlashLevel1

KerenCity_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
KerenCity_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

KerenCity_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

KerenCity_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

KerenCity_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

KerenCity_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

KerenCity_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

KerenCity_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

@ Darkest
KerenCity_Gym_EventScript_SetFlashLevel8::
	setflashlevel 8
	return

KerenCity_Gym_EventScript_BrightenRoom::
	call KerenCity_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, KerenCity_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, KerenCity_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, KerenCity_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, KerenCity_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, KerenCity_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, KerenCity_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, KerenCity_Gym_EventScript_AnimateFlash6Trainers
	goto_if_eq VAR_0x8000, 7, KerenCity_Gym_EventScript_AnimateFlash7Trainers

KerenCity_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
KerenCity_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 7
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 6
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 5
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 4
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 3
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 2
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlash7Trainers::
	playse SE_SWITCH
	animateflash 1
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call KerenCity_Gym_EventScript_SetFlashLevel
	return

KerenCity_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, KerenCity_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, KerenCity_Gym_EventScript_CheckMia
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckMia::
	goto_if_not_defeated TRAINER_MARC, KerenCity_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, KerenCity_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, KerenCity_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, KerenCity_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, KerenCity_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1

KerenCity_Gym_EventScript_StopCountingTrainers::
	return

KerenCity_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, KerenCity_Gym_Text_BrawlyIntro, KerenCity_Gym_Text_BrawlyDefeat, KerenCity_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	msgbox KerenCity_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

KerenCity_Gym_EventScript_BrawlyDefeated::
	call KerenCity_Gym_EventScript_AnimateFlashFullBrightness
	message KerenCity_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox KerenCity_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_KEREN_CITY_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_KEREN_CITY_GYM_STATE, 1
	call KerenCity_Gym_EventScript_GiveBulkUp
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	return

KerenCity_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox KerenCity_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

KerenCity_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_RHETT, KerenCity_Gym_Text_TakaoIntro, KerenCity_Gym_Text_TakaoDefeat, KerenCity_Gym_EventScript_TakaoBrightenRoom
	msgbox KerenCity_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_TakaoBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, KerenCity_Gym_Text_JocelynIntro, KerenCity_Gym_Text_JocelynDefeat, KerenCity_Gym_EventScript_JocelynBrightenRoom
	msgbox KerenCity_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_JocelynBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, KerenCity_Gym_Text_LauraIntro, KerenCity_Gym_Text_LauraDefeat, KerenCity_Gym_EventScript_LauraBrightenRoom
	msgbox KerenCity_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_LauraBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, KerenCity_Gym_Text_BrendenIntro, KerenCity_Gym_Text_BrendenDefeat, KerenCity_Gym_EventScript_BrendenBrightenRoom
	msgbox KerenCity_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_BrendenBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, KerenCity_Gym_Text_CristianIntro, KerenCity_Gym_Text_CristianDefeat, KerenCity_Gym_EventScript_CristianBrightenRoom
	msgbox KerenCity_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_CristianBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, KerenCity_Gym_Text_LilithIntro, KerenCity_Gym_Text_LilithDefeat, KerenCity_Gym_EventScript_LilithBrightenRoom
	msgbox KerenCity_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_LilithBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_Gym_EventScript_Mia::
	trainerbattle_single TRAINER_MARC, KerenCity_Gym_Text_MiaIntro, KerenCity_Gym_Text_MiaDefeat, KerenCity_Gym_EventScript_MiaBrightenRoom
	msgbox KerenCity_Gym_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_MiaBrightenRoom::
	call KerenCity_Gym_EventScript_BrightenRoom
	release
	end

KerenCity_EventScript_Freddy::
	trainerbattle_single TRAINER_JOHNSON, KerenCity_Gym_Text_FreddyIntro, KerenCity_Gym_Text_FreddyDefeat
	msgbox KerenCity_Gym_Text_FreddyPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_EventScript_Ram::
	trainerbattle_single TRAINER_WYATT, KerenCity_Gym_Text_RamIntro, KerenCity_Gym_Text_RamDefeat
	msgbox KerenCity_Gym_Text_RamPostBattle, MSGBOX_AUTOCLOSE
	end

KerenCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KEREN_CITY_GYM, KerenCity_Gym_EventScript_GymGuidePostVictory
	msgbox KerenCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

KerenCity_Gym_EventScript_GymGuidePostVictory::
	msgbox KerenCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

KerenCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, KerenCity_Gym_EventScript_GymStatueCertified
	goto KerenCity_Gym_EventScript_GymStatue
	end

KerenCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, KerenCity_Gym_EventScript_GymStatueCertified
	goto KerenCity_Gym_EventScript_GymStatue
	end

KerenCity_Gym_EventScript_GymStatueCertified::
	msgbox KerenCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

KerenCity_Gym_EventScript_GymStatue::
	msgbox KerenCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

KerenCity_Gym_Text_GymGuideAdvice:
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAA\p"
	.string "You spooked me.\p"
	.string "It's too dark in here. If you beat the\n"
	.string "trainers here it will lighten up.\p"
	.string "It is known. Yes. It is known.\p"
	.string "Anyway, AMIT loves to train his\n"
	.string "FIGHTING-type POKéMON in the dark.\p"
	.string "That's why we can't really see in here.\p"
	.string "Going against him with low level\n"
	.string "POKéMON is asking for trouble.\p"
	.string "FIGHTING POKéMON will lay a serious\n"
	.string "punch on NORMAL POKéMON,\l"
	.string "so be careful!\p"
	.string "Hey, okay, go for it!$"

KerenCity_Gym_Text_GymGuidePostVictory:
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

KerenCity_Gym_Text_TakaoIntro:
	.string "I hope you brought power because here\n"
	.string "I come! Might on!$"

KerenCity_Gym_Text_TakaoDefeat:
	.string "That was not enough power…$"

KerenCity_Gym_Text_TakaoPostBattle:
	.string "Your skill got the best of my strength!\n"
	.string "Your technique is incredible!$"

KerenCity_Gym_Text_JocelynIntro:
	.string "You are almost there\n"
	.string "I guess you want more trainig!\p"
	.string "Count me in. I'll crush you!$"

KerenCity_Gym_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

KerenCity_Gym_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

KerenCity_Gym_Text_LauraIntro:
	.string "Can you see me now?\n"
	.string "It's not my fault if you can't!$"

KerenCity_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

KerenCity_Gym_Text_LauraPostBattle:
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see my POKéMON's face…$"

KerenCity_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

KerenCity_Gym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

KerenCity_Gym_Text_MiaIntro:
	.string "This gym is so cool.\n"
	.string "I could stay here forever.$"

KerenCity_Gym_Text_MiaDefeat:
	.string "That is okay.\n"
	.string "You can now proceed.$"

KerenCity_Gym_Text_MiaPostBattle:
	.string "When I was young, I wanted to beat the\n"
	.string "gym leader but now I help him.$"

KerenCity_Gym_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

KerenCity_Gym_Text_BrendenIntro:
	.string "I'll show you the story of\n"
	.string "a sailing man!$"

KerenCity_Gym_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

KerenCity_Gym_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

KerenCity_Gym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

KerenCity_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

KerenCity_Gym_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"

KerenCity_Gym_Text_FreddyIntro:

KerenCity_Gym_Text_FreddyIntro:
	.string "No rest for the wicked.\p"
	.string "I love to climb walls but there's no\n"
	.string "walls to climb here.$"

KerenCity_Gym_Text_FreddyDefeat:
	.string "Good one.$"

KerenCity_Gym_Text_FreddyPostBattle:
	.string "I definitely need more training.\n"
	.string "I should climb more.$"

KerenCity_Gym_Text_RamIntro:
	.string "My POKéMON are not afraid of the dark.\p"
	.string "I am though.$"
KerenCity_Gym_Text_RamDefeat:
	.string "Grr you got me fair and square.$"

KerenCity_Gym_Text_RamPostBattle:
	.string "Nice battle.\n"
	.string "I can tell you've been training.$"

KerenCity_Gym_Text_BrawlyIntro:
	.string "I'm AMIT!\n"
	.string "KEREN's GYM LEADER!\p"
	.string "I've been training here all my life,\n"
	.string "mastering martial arts, I've grown tough\l"
	.string "blooming in the dark spaces!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

KerenCity_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! You made a much bigger\n"
	.string "impact than I expected!\p"
	.string "You thrashed me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

KerenCity_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the EXTREME BADGE\n"
	.string "from AMIT.$"

KerenCity_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The EXTREME BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

KerenCity_Gym_Text_ExplainBulkUp:
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

KerenCity_Gym_Text_BrawlyPostBattle:
	.string "I can see your talent becoming a giant\n"
	.string "force that stops at nothing,\l"
	.string "you'll overcome all TRAINERS one day!$"

KerenCity_Gym_Text_GymStatue:
	.string "KEREN CITY POKéMON GYM$"

KerenCity_Gym_Text_GymStatueCertified:
	.string "KEREN CITY POKéMON GYM\p"
	.string "AMIT'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
