KenkoriaCity_Houses_MapScripts::
	.byte 0

KenkoriaCity_Houses_Eventscript_OldWoman::
	lock
	faceplayer
	msgbox KenkoriaCity_Houses_Text_OldWoman, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KenkoriaCity_Houses_Eventscript_ShouldFight
	msgbox KenkoriaCity_Houses_Text_NiceSpar, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Houses_Eventscript_ShouldFight:
	msgbox KenkoriaCity_Houses_Text_ShouldFight, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Houses_Eventscript_Man1::
	msgbox KenkoriaCity_Houses_Text_Man1, MSGBOX_NPC
	end
	
KenkoriaCity_Houses_Eventscript_Boy1::
	msgbox KenkoriaCity_Houses_Text_Boy1, MSGBOX_NPC
	end

KenkoriaCity_Houses_Eventscript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, KenkoriaCity_Houses_Eventscript_PassedTime
	msgbox KenkoriaCity_Houses_Text_Woman1, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage
	release
	end

KenkoriaCity_Houses_Eventscript_PassedTime:
	msgbox KenkoriaCity_Houses_Text_PassedTime, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_Houses_Text_OldWoman:
	.string "Hello there young trainer.\p"
	.string "Have you battled my grand daughter\n"
	.string "MICHAL already?$"

KenkoriaCity_Houses_Text_ShouldFight:
	.string "Well you should battle her.\n"
	.string "She'll give you rough time, I'm sure of it.$"

KenkoriaCity_Houses_Text_NiceSpar:
	.string "How did it go?\n"
	.string "I hope you had a nice spar.$"

KenkoriaCity_Houses_Text_Man1:
	.string "I've been thinking of moving to HAWAM\n"
	.string "CITY. This city is too crowded.$"

KenkoriaCity_Houses_Text_Boy1:
	.string "My father told me CELEBI used to come\n"
	.string "here often. I've only seen it once.$"

KenkoriaCity_Houses_Text_Woman1:
	.string "My late husband has passed away\n"
	.string "recently. He was a gold miner.\p"
	.string "He left me this HM. You can have it.$"

KenkoriaCity_Houses_Text_PassedTime:
	.string "Passed time was cherished.\n"
	.string "Rest in peace.$"
