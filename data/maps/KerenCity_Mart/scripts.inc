KerenCity_Mart_MapScripts::
	.byte 0

KerenCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart KerenCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
KerenCity_Mart_Pokemart:
.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

KerenCity_Mart_EventScript_Lass::
	msgbox KerenCity_Mart_Text_Lass, MSGBOX_NPC
	end

KerenCity_Mart_EventScript_BugCatcher::
	msgbox KerenCity_Mart_Text_BugCatcher, MSGBOX_NPC
	end

KerenCity_Mart_Text_Lass:
	.string "Good thing they sell REPELs.\p"
	.string "Next route is going to be wild.$"

KerenCity_Mart_Text_BugCatcher:
	.string "So many flowers!\n"
	.string "My BUG POKéMON will be pleased.$"
