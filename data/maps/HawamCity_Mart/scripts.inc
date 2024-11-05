HawamCity_Mart_MapScripts::
	.byte 0

HawamCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart HawamCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
HawamCity_Mart_Pokemart:
.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

HawamCity_Mart_EventScript_OldLady::
	msgbox HawamCity_Mart_Text_OldLady, MSGBOX_NPC
	end

HawamCity_Mart_EventScript_OldLad::
	msgbox HawamCity_Mart_Text_OldLad, MSGBOX_NPC
	end

HawamCity_Mart_Text_OldLady:
	.string "I wish they were selling super potions.\n"
	.string "My Mightyena has more than 20 HP.$"

HawamCity_Mart_Text_OldLad:
	.string "if you buy 10 POKéBALLs you get one\n"
	.string "premiere ball free of charge.$"
