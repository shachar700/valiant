.set LOCALID_MAN_4, 12
.set LOCALID_SMASHMALEL, 8
.set LOCALID_SMASHFEMALE, 6
.set LOCALID_SMASHMALER, 7
.set LOCALID_POOCHYENA, 24
.set LOCALID_LITTLE_KID, 25
.set LOCALID_CELEBI, 22

RouteD_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteD_OnTransition
	.byte 0

RouteD_OnTransition:
	call_if_set FLAG_DEFEATED_KEREN_CITY_GYM, RouteD_EventScript_MoveShinyHunter
	call_if_set FLAG_DEFEATED_KENKORIA_CITY_GYM, RouteD_EventScript_MoveGrunts
	end

RouteD_EventScript_MoveGrunts:
	setobjectxyperm LOCALID_SMASHMALEL, 2, 12
	setobjectmovementtype LOCALID_SMASHMALEL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SMASHFEMALE, 4, 14
	setobjectmovementtype LOCALID_SMASHFEMALE, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_SMASHMALER, 6, 13
	setobjectmovementtype LOCALID_SMASHMALER, MOVEMENT_TYPE_FACE_UP
	return

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

RouteD_EventScript_Trigger_CelebiEncounter::
	lock
	special Script_FadeOutMapMusic
	applymovement OBJ_EVENT_ID_PLAYER, RouteD_Movement_MoveLeft
	waitmovement 0
	delay 50
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	msgbox RouteD_Text_CelebiCries, MSGBOX_DEFAULT
	waitmoncry
	msgbox RouteD_Text_AttackPooch, MSGBOX_DEFAULT
	waitmessage
	waitse
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	applymovement LOCALID_POOCHYENA, Common_Movement_WalkInPlaceFasterUp
	waitmoncry
	waitmovement 0
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	msgbox RouteD_Text_CelebiHurt, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	dofieldeffectsparkle 5, 12, 0
	waitfieldeffect FLDEFF_SPARKLE
	playfanfare MUS_AWAKEN_LEGEND
	setvar VAR_RESULT, 3
	playse SE_ORB
	special DoOrbEffect
	delay 150
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_POOCHYENA
	removeobject LOCALID_SMASHMALEL
	removeobject LOCALID_SMASHFEMALE
	removeobject LOCALID_SMASHMALER
	setobjectxyperm LOCALID_LITTLE_KID, 5, 13
	addobject LOCALID_LITTLE_KID
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	fadescreen FADE_FROM_BLACK
	delay 30
	special FadeOutOrbEffect
	waitstate
	delay 50
	msgbox RouteD_Text_LovesCelebi, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	applymovement LOCALID_CELEBI, RouteD_Movement_Celebi_Out
	delay 20
	applymovement LOCALID_LITTLE_KID, Common_Movement_FaceDown
	waitmovement 0
	msgbox RouteD_Text_Arr, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLE_KID, RouteD_Movement_WalkOut
	waitmovement 0
	removeobject LOCALID_LITTLE_KID
	setobjectxyperm LOCALID_LITTLE_KID, 53, 28
	fadescreen FADE_TO_BLACK
	addobject LOCALID_POOCHYENA
	addobject LOCALID_SMASHMALEL
	addobject LOCALID_SMASHFEMALE
	addobject LOCALID_SMASHMALER
	setweather WEATHER_NONE
	doweather
	fadescreen FADE_FROM_BLACK
	delay 30
	setobjectmovementtype LOCALID_SMASHMALEL, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_SMASHMALER, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_SMASHFEMALE, MOVEMENT_TYPE_LOOK_AROUND
	msgbox RouteD_Text_WhereDidCelebiGo, MSGBOX_DEFAULT
	removeobject LOCALID_POOCHYENA
	playse SE_BALL_OPEN
	setobjectxyperm 14, 5, 13
	addobject 14
	delay 50
	removeobject 14
	setobjectxyperm 14, 42, 11
	waitmessage
	closemessage
	applymovement LOCALID_SMASHFEMALE, RouteD_Movement_SmashFemaleMovesOut
	applymovement LOCALID_SMASHMALEL, RouteD_Movement_SmashMaleLMovesOut
	applymovement LOCALID_SMASHMALER, RouteD_Movement_SmashMaleRMovesOut
	waitmovement 0
	removeobject LOCALID_SMASHMALEL
	removeobject LOCALID_SMASHFEMALE
	removeobject LOCALID_SMASHMALER
	removeobject LOCALID_CELEBI
	setflag FLAG_HIDE_ROUTE_D_GRUNTS
	setflag FLAG_HIDE_ROUTE_D_CELEBI
	setvar VAR_KEREN_CITY_GYM_STATE, 6
	playbgm MUS_ROUTE104, FALSE
	release
	end

RouteD_EventScript_Ester::
	trainerbattle_single TRAINER_LEAH, RouteD_Text_ThereIsADarkCave, RouteD_Text_Mysteries
	msgbox RouteD_Text_NoPass, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_David::
	trainerbattle_single TRAINER_GREG, RouteD_Text_GonnaWin, RouteD_Text_NotHappening
	msgbox RouteD_Text_ShouldveTrainedHarder, MSGBOX_AUTOCLOSE
	end

RouteD_EventScript_BetaSign::
	msgbox RouteD_Text_BetaSign, MSGBOX_SIGN
	end

RouteD_EventScript_Snorlax::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_NORMAL
	msgbox RouteD_Text_Snorlax, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEVIED_HAPPY_MEAL, RouteD_EventScript_SnorlaxHappyMeal
	waitmoncry
	release
	end

RouteD_EventScript_SnorlaxHappyMeal::
	msgbox RouteD_Text_SnorlaxSniffing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0, RouteD_EventScript_SnorlaxDeclinedHappyMeal
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_NORMAL
	removeitem ITEM_HAPPY_MEAL
	msgbox RouteD_Text_SnorlaxMunching, MSGBOX_DEFAULT
	waitmoncry
	applymovement 25, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	msgbox RouteD_Text_SnorlaxAttacks, MSGBOX_AUTOCLOSE
	setwildbattle SPECIES_SNORLAX, 30, ITEM_SITRUS_BERRY
	dowildbattle
	playmoncry SPECIES_SNORLAX, CRY_MODE_FAINT
	waitmoncry
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject 25
	setflag FLAG_HIDE_ROUTE_D_SNORLAX
	fadescreen FADE_FROM_BLACK
	release
	end




RouteD_EventScript_SnorlaxDeclinedHappyMeal::
	release
	end

RouteD_Movement_Celebi_Out:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RouteD_Movement_SmashFemaleMovesOut:
	walk_left
	walk_left
	walk_left
	step_end

RouteD_Movement_SmashMaleLMovesOut:
	walk_left
	step_end

RouteD_Movement_SmashMaleRMovesOut:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RouteD_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

RouteD_Movement_MoveLeft:
	walk_left
	walk_left
	walk_left
	step_end

RouteD_Movement_WalkOut:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RouteD_Text_ThereIsADarkCave:
	.string "There is a dark cave ahead. It is bound\n"
	.string "to have good treasures in it.$"

RouteD_Text_Mysteries:
	.string "Mystries lie ahead. I want to discover them.$"

RouteD_Text_NoPass:
	.string "No pass in this path.\n"
	.string "As I have learned in the past.$"

RouteD_Text_GonnaWin:
	.string "My BUG POKéMON are gonna win.\n"
	.string "I'm sure of it.$"
	
RouteD_Text_NotHappening:
	.string "Uh uh this is not happening.$"

RouteD_Text_ShouldveTrainedHarder:
	.string "I should've trained harder.\n"
	.string "The gym challenge is waiting for me.$"

RouteD_Text_CelebiCries:
	.string "{COLOR GREEN}CELEBI:{COLOR DARK_GRAY} Cele…biiiii…$"

RouteD_Text_CelebiHurt:
	.string "{COLOR GREEN}CELEBI:{COLOR DARK_GRAY} Cele… biii!!!$"

RouteD_Text_LovesCelebi:
	.string "Little Kid: Please CELEBI, don't go away.\n"
	.string "I need you. You are my remedy.$"

RouteD_Text_Arr:
	.string "Arr… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … You will regret that.$"

RouteD_Text_AttackPooch:
	.string "Female Grunt: POOCHYENA, bite CELEBI!$"

RouteD_Text_WhereDidCelebiGo:
	.string "Female Grunt: Where did he go?!\n"
	.string "How is this possible?\p"
	.string "Lets go to the cave\n"
	.string "CELEBI must be in it.\l"
	.string "POOCHYENA, return.$"

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

RouteD_Text_BetaSign:
	.string "Thank you for playing Beta 2\n"
	.string "of POKéMON Valiant!\p"
	.string "Official thread is in Pokecommunity.\p"
	.string "Please leave feedback or report bugs\n"
	.string "there or in the discord server:\p"
	.string "https://discord.gg/wcEwv9bytW\p"
	.string "I hope you enjoyed!\n"
	.string "ROM HACK made by Shahar.$"

RouteD_Text_Snorlax:
	.string "Snor… … …\p"
	.string "A SNORLAX is snoring and blocking the\n"
	.string "way.$"

RouteD_Text_SnorlaxSniffing:
	.string "SNORLAX is sniffing a warm meal.\n"
	.string "Awaken by the good smell.\p"
	.string "Give Happy Meal to SNORLAX?$"

RouteD_Text_SnorlaxMunching:
	.string "SNORLAX is munching the HAPPY MEAL\n"
	.string "making it very happy.\p"
	.string "Woke by its senses it notices {PLAYER},\n"
	.string "making it protective.$"

RouteD_Text_SnorlaxAttacks:
	.string "SNORLAX attacks.$"
