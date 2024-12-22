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

KenkoriaCity_Mart_EventScript_MysteryGiftMan::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	msgbox KenkoriaCity_Mart_Text_MysteryGiftMan_Hi, MSGBOX_DEFAULT
	waitmessage
	bufferstring STR_VAR_1, Text_Happy2025
	special DoWaldaNamingScreen @STR_VAR_2 is given by player
	waitstate
	goto_if_eq VAR_RESULT, FALSE, KenkoriaCity_Mart_EventScript_MysteryGiftMan_Decline
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	msgbox KenkoriaCity_Mart_Text_MysteryGiftMan_Correct, MSGBOX_DEFAULT
	bufferspeciesname STR_VAR_1, SPECIES_PORYGON
	givemon SPECIES_PORYGON, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, KenkoriaCity_Mart_EventScript_SendPorygonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, KenkoriaCity_Mart_EventScript_SendPorygonToPC 
	release
	end

KenkoriaCity_Mart_EventScript_SendPorygonToParty::
	call KenkoriaCity_Mart_EventScript_ReceivedPorygon
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_Mart_EventScript_MysteryGiftMan_Exit
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto KenkoriaCity_Mart_EventScript_MysteryGiftMan_Exit
	end

KenkoriaCity_Mart_EventScript_SendPorygonToPC::
	call KenkoriaCity_Mart_EventScript_ReceivedPorygon
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_Mart_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto KenkoriaCity_Mart_EventScript_CyndaquilTransferredToPC
	end

KenkoriaCity_Mart_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto KenkoriaCity_Mart_EventScript_MysteryGiftMan_Exit
	end

KenkoriaCity_Mart_EventScript_ReceivedPorygon::
	playfanfare MUS_OBTAIN_ITEM
	message KenkoriaCity_Mart_Text_ReceivedPorygon
	waitmessage
	waitfanfare
	return

KenkoriaCity_Mart_EventScript_MysteryGiftMan_Decline::	
	msgbox KenkoriaCity_Mart_Text_MysteryGiftMan_Decline, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Mart_EventScript_MysteryGiftMan_Exit::
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_KENKORIA_CITY_MART_MYSTERYGIFT_MAN_1
	removeobject 6
	delay 30
	fadescreen FADE_FROM_BLACK
	closemessage
	release
	end

KenkoriaCity_Mart_Text_OhYouDontKnow:
	.string "Oh you don't know…$"

KenkoriaCity_Mart_Text_OhYouDontKnow2:
	.string "Oh you don't know… unfortunate.$"

KenkoriaCity_Mart_Text_MysteryGiftMan_Correct:
	.string "That's correct, here you go.\n"
	.string "Here is your prize.$"

KenkoriaCity_Mart_Text_MysteryGiftMan_Hi:
	.string "Hi I'm here in the now but not later.\n"
	.string "Do you recall what is is?$"

KenkoriaCity_Mart_Text_MysteryGiftMan_Decline:
	.string "That's incorrect.$"

Text_Happy2025:
	.string "Happy 2025…$"

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

KenkoriaCity_Mart_Text_ReceivedPorygon:
	.string "{PLAYER} received PORYGON\n"
	.string "from the MYSTERY GIFT MAN!$"
