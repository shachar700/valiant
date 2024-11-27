.set LOCALID_BEN, 1

KerenCity_ResearchFacility_MapScripts::
	.byte 0

KerenCity_ResearchFacility_EventScript_BenAlerts::
	lockall
	applymovement LOCALID_BEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BEN, Common_Movement_Delay48
	waitmovement 0 
	applymovement LOCALID_BEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox KerenCity_ResearchFacility_Text_BenAlerts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES,  KerenCity_ResearchFacility_EventScript_AgreeToHelp
	goto_if_eq VAR_RESULT, NO,  KerenCity_ResearchFacility_EventScript_DeclineHelping
	end

KerenCity_ResearchFacility_EventScript_DeclineHelping:
	msgbox KerenCity_ResearchFacility_Text_NoRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, KerenCity_ResearchFacility_EventScript_AgreeToHelp
	goto_if_eq VAR_RESULT, NO, KerenCity_ResearchFacility_EventScript_DeclineHelping
	end	

KerenCity_ResearchFacility_EventScript_AgreeToHelp:
	msgbox KerenCity_ResearchFacility_Text_ImGladYouAgree, MSGBOX_DEFAULT
	releaseall
	end

KerenCity_ResearchFacility_Text_BenAlerts:
	.string "Oh hi there {PLAYER}\n"
	.string "It's good to see you.\p"
	.string "You've got the DEVON PARTS?\n"
	.string "That's good.\p"
	.string "That will allow our machines to have\n"
	.string "enough energy.\p"
	.string "As for the matter in hands…\p"
	.string "Somebody stole valuable data from our\n"
	.string "research facility.\p"
	.string "I assume it's TEAM SMASH as they are\n"
	.string "known for wreaking havoc.\p"
	.string "Data about plants, flowers, POKéMON,\n"
	.string "gem stones, and fossils. All stolen.\p"
	.string "They haven't entered the facility so\n"
	.string "they must have hacked their way in.\p"
	.string "Good thing they didn't find my research\n"
	.string "about CELEBI and the IRIS flowers.\p"
	.string "There is a strong connection between\n"
	.string "CELEBI, IRIS and the gem ZIRCON.\p"
	.string "I'm not going to risk it and go out\n"
	.string "there while TEAM SMASH looks for ways\l"
	.string "to harnest power and control.\p"
	.string "They want to control this region and\n"
	.string "have us be on their mercy.\p"
	.string "I'm not going to let that happen.\p"
	.string "Could you perhaps help me at getting\n"
	.string "this valuable data to PROFESSOR ARIA?$"

KerenCity_ResearchFacility_Text_NoRefuse:
	.string "There's too much risk at hand.\n"
	.string "Can you please escort this data?$"

KerenCity_ResearchFacility_Text_ImGladYouAgree:
	.string "I'm glad you agree.$"


