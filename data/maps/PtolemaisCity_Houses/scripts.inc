PtolemaisCity_Houses_MapScripts::
	.byte 0

PtolemaisCity_Houses_EventScript_OldWomanM::
	msgbox PtolemaisCity_Houses_Text_OldWomanM, MSGBOX_NPC
	end

PtolemaisCity_Houses_EventScript_Scientist::
	msgbox PtolemaisCity_Houses_Text_Scientist, MSGBOX_NPC
	end

PtolemaisCity_Houses_EventScript_Cutterman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, PtolemaisCity_CuttersHouse_EventScript_ExplainCut
	msgbox PtolemaisCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox PtolemaisCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_CuttersHouse_EventScript_ExplainCut::
	msgbox PtolemaisCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

PtolemaisCity_Houses_EventScript_SchoolKidM::
	msgbox PtolemaisCity_Houses_Text_SchoolKidM, MSGBOX_NPC
	end

PtolemaisCity_Houses_EventScript_Lass::
	msgbox PtolemaisCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

PtolemaisCity_Houses_Text_OldWomanM:
	.string "It's a lovely day outside.\n"
	.string "I hope you got some sunlight.$"

PtolemaisCity_Houses_Text_Scientist:
	.string "I wanted to go EAST but a\n"
	.string "lady started rambling there.\p"
	.string "I hope she goes away soon.$"

PtolemaisCity_Houses_Text_SchoolKidM:
	.string "I hope you know your POKéMON\n"
	.string "type advantages.\p"
	.string "In-case you don't, our gym leader\n"
	.string "IDO uses WATER type POKéMON.\p"
	.string "That means GRASS and ELECTRIC\n"
	.string "are super-effective against it.\p"
	.string "I've heard there are some POKéMON\n"
	.string "nearby with those types.$"

PtolemaisCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

PtolemaisCity_CuttersHouse_Text_ExplainCut:
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the SOOTHING BADGE.$"

PtolemaisCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "PtolemaisCity, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"
