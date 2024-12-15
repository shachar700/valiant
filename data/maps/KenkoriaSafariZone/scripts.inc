KenkoriaSafariZone_MapScripts::
	.byte 0

KenkoriaSafariZone_EventScript_Man3::
	msgbox KenkoriaSafariZone_Text_Man3, MSGBOX_NPC
	end

KenkoriaSafariZone_EventScript_Hiker::
	msgbox KenkoriaSafariZone_Text_Hiker, MSGBOX_NPC
	end

KenkoriaSafariZone_EventScript_Picnicker::
	msgbox KenkoriaSafariZone_Text_Picnicker, MSGBOX_NPC
	end

KenkoriaSafariZone_EventScript_Lass::
	msgbox KenkoriaSafariZone_Text_Lass, MSGBOX_NPC
	end

KenkoriaSafariZone_Text_Man3:
	.string "I'm looking for a NATU but it's too rare.$"

KenkoriaSafariZone_Text_Hiker:
	.string "DODUO will be great for the KENKORIA\n"
	.string "GYM.$"

KenkoriaSafariZone_Text_Picnicker:
	.string "The SAFARI ZONE has unique POKéMON.\n"
	.string "I hope I can catch some for my team.$"

KenkoriaSafariZone_Text_Lass:
	.string "There are some items scattered here.\n"
	.string "I think I saw one under a tree.$"
