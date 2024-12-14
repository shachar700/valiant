KenkoriaCity_Mart_MapScripts::
	.byte 0

KenkoriaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart KenkoriaCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
KenkoriaCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

KenkoriaCity_Mart_EventScript_FatMan::
	msgbox KenkoriaCity_Mart_Text_FatMan, MSGBOX_NPC
	end

KenkoriaCity_Mart_EventScript_Girl2::
	msgbox KenkoriaCity_Mart_Text_Girl2, MSGBOX_NPC
	end

KenkoriaCity_Mart_EventScript_GameBoyKidL::
	msgbox KenkoriaCity_Mart_Text_GameBoyKidL, MSGBOX_NPC
	end

KenkoriaCity_Mart_EventScript_GameBoyKidR::
	msgbox KenkoriaCity_Mart_Text_GameBoyKidR, MSGBOX_NPC
	end

KenkoriaCity_Mart_Text_FatMan:
	.string "I can't find REVIVEs in this mart.\p"
	.string "I don't want to run back to the POKéMON\n"
	.string "CENTER if my POKéMON gets fainted.$"

KenkoriaCity_Mart_Text_Girl2:
	.string "The POKéMON in ROUTE D were too fast\n"
	.string "for my SKITTY.$"

KenkoriaCity_Mart_Text_GameBoyKidL:
	.string "I'm trading my SPINDA,\n"
	.string "It's very exciting.$"

KenkoriaCity_Mart_Text_GameBoyKidR:
	.string "Goodbye KECLEON, you were always\n"
	.string "missing and you will be missed.$"
