.set LOCALID_SMASHFEMALE, 5

PtolemaisCity_MapScripts::
	.byte 0

PtolemaisCity_EventScript_SmashFemale::
	msgbox PtolemaisCity_Text_SmashFemale, MSGBOX_NPC
	end

PtolemaisCity_EventScript_CitySign::
	msgbox PtolemaisCity_Text_CitySign, MSGBOX_SIGN
	end

PtolemaisCity_EventScript_GymSign::
	msgbox PtolemaisCity_Text_GymSign, MSGBOX_SIGN
	end

PtolemaisCity_EventScript_SmashFemale_Trigger::
	lockall
	applymovement LOCALID_SMASHFEMALE, Common_Movement_FacePlayer
	applymovement LOCALID_SMASHFEMALE, Common_Movement_ExclamationMark
	waitmovement 30
	applymovement OBJ_EVENT_ID_PLAYER PtolemaisCity_Movement_FaceUp
	waitmovement 30
	msgbox PtolemaisCity_Text_SmashFemale_Wonderful, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER PtolemaisCity_Movement_WalkLeft
	waitmovement 0
	release
	end

PtolemaisCity_EventScript_Fisherman::
	msgbox PtolemaisCity_Text_Fisherman, MSGBOX_NPC
	end

PtolemaisCity_EventScript_LittleGirl::
	msgbox PtolemaisCity_Text_LittleGirl, MSGBOX_NPC
	end

PtolemaisCity_EventScript_LittleBoy::
	msgbox PtolemaisCity_Text_LittleBoy, MSGBOX_NPC
	end	

PtolemaisCity_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, PtolemaisCity_EventScript_HowsFishing
	msgbox PtolemaisCity_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PtolemaisCity_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, PtolemaisCity_EventScript_NotGettingItchToFish
	end

PtolemaisCity_EventScript_GiveOldRod::
	msgbox PtolemaisCity_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox PtolemaisCity_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_EventScript_NotGettingItchToFish::
	msgbox PtolemaisCity_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_EventScript_HowsFishing::
	message PtolemaisCity_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, PtolemaisCity_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, PtolemaisCity_EventScript_FishingNotSoGood
	end

PtolemaisCity_EventScript_FishingExcellent::
	msgbox PtolemaisCity_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_EventScript_FishingNotSoGood::
	msgbox PtolemaisCity_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_Text_CitySign:
	.string "PTOLEMAIS CITY\n"
	.string "Beautiful beach with lovely view.$"

PtolemaisCity_Text_SmashFemale:
	.string "Scram! You are hurting my vibes.$"

PtolemaisCity_Text_SmashFemale_Wonderful:
	.string "This city is beautiful. It's close to the\n"
	.string "coast, and has many houses. Plenty of\l"
	.string "people. Good grounds, wonderful view.\l"
	.string "I wish there was something we could do\l"
	.string "here, or maybe we can.\p"
	.string "Hmm…\p"
	.string "You are still here though.\p"
	.string "Scram! Don't you see I'm up to\n"
	.string "something?!$"

PtolemaisCity_Text_Fisherman:
	.string "I can't get a single POKéMON on my rod.\n"
	.string "Is the coast here empty?\l"
	.string "or am I in the wrong coast side?$"

PtolemaisCity_Text_GettingItchToFish:
	.string "There are so many fish POKéMON in the sea.\p"
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"

PtolemaisCity_Text_GiveYouOneOfMyRods:
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing RODS.$"

PtolemaisCity_Text_ThrowInFishingAdvice:
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

PtolemaisCity_Text_ThatsTooBadThen:
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"

PtolemaisCity_Text_HowsYourFishing:
	.string "Yo!\n"
	.string "How's your fishing?$"

PtolemaisCity_Text_GreatHaulInSomeBigOnes:
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"

PtolemaisCity_Text_FishingAdvice:
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

PtolemaisCity_Text_LittleGirl:
	.string "Not many people know our gym leader,\n"
	.string "Ido, who barely goes outside for\l"
	.string "some sun light.\p"
	.string "I wish they went out to get\n"
	.string "some vitmain D.$"

PtolemaisCity_Text_LittleBoy:
	.string "I love the beach.\n"
	.string "I wish I could stay here forever.$"

PtolemaisCity_Text_GymSign:
	.string "PTOLEMAIS CITY GYM\n"
	.string "No stones left unturned.$"

PtolemaisCity_Movement_FaceUp:
	face_up
	step_end

PtolemaisCity_Movement_WalkLeft:
	walk_left
	step_end
