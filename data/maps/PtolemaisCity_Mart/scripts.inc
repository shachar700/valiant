PtolemaisCity_Mart_MapScripts::
	.byte 0

PtolemaisCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PtolemaisCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PtolemaisCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

PtolemaisCity_Mart_EventScript_Lady::
	msgbox PtolemaisCity_Mart_Text_Lady, MSGBOX_NPC
	end

PtolemaisCity_Mart_EventScript_Man::
	msgbox PtolemaisCity_Mart_Text_Man, MSGBOX_NPC
	end

PtolemaisCity_Mart_Text_Lady:
	.string "Look at all the items in the shop.\p"
	.string "I wish I had enough to buy it all.$"

PtolemaisCity_Mart_Text_Man:
	.string "My girlfriend likes to hang out here.\p"
	.string "We love to hang out in shopping marts\n"
	.string "and look at all the items.$"
