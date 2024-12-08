.set LOCALID_MAN_4, 12

RouteD_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteD_OnTransition
	.byte 0

RouteD_OnTransition:
	call_if_set FLAG_DEFEATED_KEREN_CITY_GYM, RouteD_EventScript_MoveShinyHunter
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

RouteD_EventScript_Liem::
	trainerbattle_single TRAINER_HEIDI, RouteD_Text_SoMuchGrass, RouteD_Text_WhyDidYouWin
	msgbox RouteD_Text_IHaveToGoNow, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Erez::
	trainerbattle_single TRAINER_WILTON_1, RouteD_Text_CheckThisOut, RouteD_Text_NotEnoughElectricity
	msgbox RouteD_Text_WishYouGoodLuck, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Raz::
	trainerbattle_single TRAINER_DYLAN_1, RouteD_Text_OsuHereIGo, RouteD_Text_NetGain
	msgbox RouteD_Text_Practice, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Alisa::
	trainerbattle_single TRAINER_MADELINE_1, RouteD_Text_FleeFromMyBeauty, RouteD_Text_DefeatTooPretty
	msgbox RouteD_Text_DirectBeauty, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Shlomi::
	trainerbattle_single TRAINER_TRENT_1, RouteD_Text_WeAreGonnaExcel, RouteD_Text_YesYes
	msgbox RouteD_Text_IllGetYouNextTime, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Idan::
	trainerbattle_single TRAINER_TRAVIS, RouteD_Text_SmashGrunts, RouteD_Text_TriumphOverFear
	msgbox RouteD_Text_TooManyGrunts, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Micah::
	trainerbattle_single TRAINER_STEVE_1, RouteD_Text_CrazyTimes, RouteD_Text_SuchPower
	msgbox RouteD_Text_DontWasteYourPower, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_Roni::
	trainerbattle_single TRAINER_MARIA_1, RouteD_Text_HardWorkMakesIt, RouteD_Text_NoWay
	msgbox RouteD_Text_YouDidGoodBackThere, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_SmashGruntLeft::
	msgbox RouteD_Text_SmashGruntLeft, MSGBOX_NPC
	end

RouteD_EventScript_SmashGruntMiddle::
	msgbox RouteD_Text_SmashGruntMiddle, MSGBOX_NPC
	end

RouteD_EventScript_SmashGruntRight::
	msgbox RouteD_Text_SmashGruntRight, MSGBOX_NPC
	end

RouteD_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

RouteD_Text_SmashGruntLeft:
	.string "There's no going NORTH from here.\n"
	.string "Too many wildlife ramping.$"

RouteD_Text_SmashGruntMiddle:
	.string "No one passes through here,\n"
	.string "We are not gonna let it happen.$"

RouteD_Text_SmashGruntRight:
	.string "… … …\n"
	.string "… … …\p"
	.string "The route is blocked.$"

RouteD_Text_HardWorkMakesIt:
	.string "Hard work makes it worth your while.$"

RouteD_Text_NoWay:
	.string "No way you beat me.$"

RouteD_Text_YouDidGoodBackThere:
	.string "You did good back there.\n"
	.string "I should learn from your moves.$"

RouteD_Text_CrazyTimes:
	.string "Crazy times we're living in.\n"
	.string "TEAM SMASH is up to something.$"

RouteD_Text_SuchPower:
	.string "Such power.\n"
	.string "You need to use that.$"

RouteD_Text_DontWasteYourPower:
	.string "Don't waste your power on me.\n"
	.string "There's gonna be more fighting coming.$"

RouteD_Text_SmashGrunts:
	.string "SMASH grunts all over the place.\n"
	.string "They are making me scared.$"

RouteD_Text_TriumphOverFear:
	.string "Triumph over fear.$"

RouteD_Text_TooManyGrunts:
	.string "Too many grunts to take them all out.\n"
	.string "Someone needs to do something.$"

RouteD_Text_WeAreGonnaExcel:
	.string "We are gonna excel in this climb.$"

RouteD_Text_YesYes:
	.string "Yes… Yes… more effort is needed.$"

RouteD_Text_IllGetYouNextTime:
	.string "I'll get you next time for sure.$"

RouteD_Text_FleeFromMyBeauty:
	.string "You better flee from my beauty,\n"
	.string "No more running.$"

RouteD_Text_DefeatTooPretty:
	.string "Ugh Defeat.\n"
	.string "Probably too pretty to fight.$"

RouteD_Text_DirectBeauty:
	.string "Direct beauty comes from hard work.$"

RouteD_Text_OsuHereIGo:
	.string "Osu! Here I go!$"

RouteD_Text_NetGain:
	.string "Net gain 100%$"

RouteD_Text_Practice:
	.string "Practice makes perfect.\n"
	.string "Gotta run some more.$"

RouteD_Text_CheckThisOut:
	.string "Check this out,\n"
	.string "My ELECTRIKE are ready to rumble.$"

RouteD_Text_NotEnoughElectricity:
	.string "Not enough electricity in the air.$"

RouteD_Text_WishYouGoodLuck:
	.string "I wish you good luck in your endeavors.$"

RouteD_Text_SoMuchGrass:
	.string "There's so much tall grass in ROUTE D.\n"
	.string "Lets see who can come on top.$"

RouteD_Text_WhyDidYouWin:
	.string "Oof… Why did you win?$"

RouteD_Text_IHaveToGoNow:
	.string "I have to go now to heal my POKéMON.$"

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
