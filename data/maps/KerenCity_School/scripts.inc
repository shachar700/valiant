KerenCity_School_MapScripts::
	.byte 0

KerenCity_School_EventScript_Blackboard::
	lockall
	msgbox KerenCity_School_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end	


KerenCity_School_EventScript_ChooseBlackboardTopic::
	message KerenCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, KerenCity_School_EventScript_Poison
	case 1, KerenCity_School_EventScript_Paralysis
	case 2, KerenCity_School_EventScript_Sleep
	case 3, KerenCity_School_EventScript_Burn
	case 4, KerenCity_School_EventScript_Freeze
	case 5, KerenCity_School_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, KerenCity_School_EventScript_ExitTopicSelect
	end

KerenCity_School_EventScript_Poison::
	msgbox KerenCity_School_Text_ExplainPoison, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end

KerenCity_School_EventScript_Paralysis::
	msgbox KerenCity_School_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end

KerenCity_School_EventScript_Sleep::
	msgbox KerenCity_School_Text_ExplainSleep, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end

KerenCity_School_EventScript_Burn::
	msgbox KerenCity_School_Text_ExplainBurn, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end

KerenCity_School_EventScript_Freeze::
	msgbox KerenCity_School_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto KerenCity_School_EventScript_ChooseBlackboardTopic
	end

KerenCity_School_EventScript_ExitTopicSelect::
	releaseall
	end

KerenCity_School_EventScript_StudentNotebook::
	msgbox KerenCity_School_Text_StudentsNotes, MSGBOX_SIGN
	end

KerenCity_School_EventScript_EmptyNotebook::
	msgbox KerenCity_School_Text_EmptyNotebook, MSGBOX_SIGN
	end


KerenCity_School_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, KerenCity_School_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, KerenCity_School_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, KerenCity_School_EventScript_TeacherCheckOnStudentsWest
	msgbox KerenCity_School_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end


KerenCity_School_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, KerenCity_School_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

KerenCity_School_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, KerenCity_School_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

KerenCity_School_EventScript_GaveQuickClaw::
	msgbox KerenCity_School_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

KerenCity_School_EventScript_RichBoy::
	msgbox KerenCity_School_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end


KerenCity_School_Eventscript_LittleBoy3Right::
	msgbox KerenCity_School_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

KerenCity_School_Eventscript_LittleBoy3Left::
	msgbox KerenCity_School_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

KerenCity_School_Eventscript_GameboyKid::
	msgbox KerenCity_School_Text_GameboyKid, MSGBOX_NPC
	end

KerenCity_School_Eventscript_LittleGirlRight::
	msgbox KerenCity_School_Text_ArtClass, MSGBOX_NPC
	end

KerenCity_School_Eventscript_LittleGirlLeft::
	msgbox KerenCity_School_Text_Past, MSGBOX_NPC
	end

KerenCity_School_Eventscript_LittleBoy::
	msgbox KerenCity_School_Text_LittleBoy, MSGBOX_NPC
	end

KerenCity_School_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

KerenCity_School_Movement_TeacherCheckOnStudentsWest:
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	face_right
	step_end

KerenCity_School_Movement_TeacherCheckOnStudentsEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	face_left
	step_end

KerenCity_School_Text_BlackboardListsStatusChanges:
	.string "The blackboard lists status changes\n"
	.string "that may affect POKéMON in battle.$"

KerenCity_School_Text_ReadWhichTopic:
	.string "Which topic do you want to read?$"

KerenCity_School_Text_ExplainPoison:
	.string "If a POKéMON is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned POKéMON's HP will drop\n"
	.string "while it is traveling.\p"
	.string "Heal a poisoning using an ANTIDOTE.$"

KerenCity_School_Text_ExplainParalysis:
	.string "If a POKéMON becomes paralyzed,\n"
	.string "its SPEED drops.\p"
	.string "It may also not be able to move while\n"
	.string "it is in battle.\p"
	.string "Paralysis remains after battle.\n"
	.string "Cure it using a PARLYZ HEAL.$"

KerenCity_School_Text_ExplainSleep:
	.string "If a POKéMON falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "A POKéMON may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Wake it up using an AWAKENING.$"

KerenCity_School_Text_ExplainBurn:
	.string "A burn reduces ATTACK power, and it\n"
	.string "steadily reduces the victim's HP.\p"
	.string "A burn lingers after battle.\n"
	.string "Cure a burn using a BURN HEAL.$"

KerenCity_School_Text_ExplainFreeze:
	.string "If a POKéMON is frozen, it becomes\n"
	.string "completely helpless.\p"
	.string "It will remain frozen after battle.\n"
	.string "Thaw it out using an ICE HEAL.$"

KerenCity_School_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Students who don't study get a little\n"
	.string "taste of my QUICK CLAW.\p"
	.string "Whether or not you are a good student \n"
	.string "will be evident from the way you use\l"
	.string "this item.$"

KerenCity_School_Text_ExplainQuickClaw:
	.string "A POKéMON holding the QUICK CLAW will\n"
	.string "occasionally speed up and get to move\l"
	.string "before its opponent.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by POKéMON.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"

KerenCity_School_Text_GameboyKid:
	.string "I'm trading POKéMON with my friend\n"
	.string "right now.$"

KerenCity_School_Text_PokemontCantUseManMadeItems:
	.string "POKéMON can hold items, but they\n"
	.string "don't know what to do with man-made\l"
	.string "items like POTION and ANTIDOTE.$"

KerenCity_School_Text_ConfusedPokemonAttacksItself:
	.string "You know how some POKéMON moves can\n"
	.string "confuse a POKéMON?\p"
	.string "A confused POKéMON will sometimes\n"
	.string "attack itself without meaning to.\p"
	.string "But once it leaves battle, it will\n"
	.string "return to normal.$"

KerenCity_School_Text_PokemonHealItselfWithBerry:
	.string "A POKéMON holding a BERRY will heal\n"
	.string "itself…\p"
	.string "There are many kinds of items that\n"
	.string "POKéMON can hold…\p"
	.string "Boy, it sure is hard taking notes\n"
	.string "down…$"

KerenCity_School_Text_StudentsNotes:
	.string "It's this student's notebook…\p"
	.string "POKéMON are to be caught using\n"
	.string "POKé BALLS.\p"
	.string "Up to six POKéMON can accompany\n"
	.string "a TRAINER.\p"
	.string "A TRAINER is someone who catches\n"
	.string "POKéMON, raises them, and battles\l"
	.string "with them.\p"
	.string "A TRAINER's mission is to defeat\n"
	.string "the strong TRAINERS who await\l"
	.string "challengers in POKéMON GYMS.$"

KerenCity_School_Text_EmptyNotebook:
	.string "An empty notebook…$"

KerenCity_School_Text_ArtClass:
	.string "I thought this was art class.$"

KerenCity_School_Text_Past:
	.string "My papa told me CELEBI was here in the\n"
	.string "PAST.\p"
	.string "Why is it not here now?$"

KerenCity_School_Text_LittleBoy:
	.string "I can't really draw but it's therapeutic\n"
	.string "for me.$"
