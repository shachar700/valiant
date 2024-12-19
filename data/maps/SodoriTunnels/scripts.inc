SodoriTunnels_MapScripts::
	.byte 0

SodoriTunnels_EventScript_Hiker::
	msgbox SodoriTunnels_Text_Hiker, MSGBOX_NPC
	end

SodoriTunnels_EventScript_PsychicM::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SodoriTunnels_EventScript_ReceivedFlash
	msgbox SodoriTunnels_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SodoriTunnels_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

SodoriTunnels_EventScript_ReceivedFlash::
	msgbox SodoriTunnels_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

SodoriTunnels_Text_Hiker:
	.string "The tunnels are blocked due to\n"
	.string "rockslide.\p"
	.string "I can't explore the POKéMON\n"
	.string "living here.$"

SodoriTunnels_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "Those guys who came by earlier…\n"
	.string "TEAM SMASH, I think it was.\p"
	.string "They knew how to use FLASH, as they\n"
	.string "were using POKéMON that knew FLASH.\p"
	.string "Well, since I'm not planning to enter,\n"
	.string "You can have this HM05 FLASH.\p"
	.string "Here you go, I'll pass this on to you.$"

SodoriTunnels_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.$"
