.set LOCALID_BEN, 1

KerenCity_ResearchFacility_MapScripts::
	.byte 0

KerenCity_EventScript_BenTalks::
	goto_if_eq VAR_KEREN_CITY_STATE, 0, KerenCity_ResearchFacility_EventScript_GoodToSeeYou
	goto_if_eq VAR_KEREN_CITY_STATE, 1, KerenCity_ResearchFacility_EventScript_NectarResearch
	goto_if_eq VAR_KEREN_CITY_STATE, 2, KerenCity_ResearchFacility_EventScript_BenAlerts
	goto_if_eq VAR_KEREN_CITY_STATE, 3, KerenCity_ResearchFacility_EventScript_BenAsksForYouToDeliver
	end

@ VAR_KEREN_CITY_STATE at 0
KerenCity_ResearchFacility_EventScript_GoodToSeeYou::	
	msgbox KerenCity_ResearchFacility_Text_GoodToSeeYou, MSGBOX_NPC
	setvar VAR_KEREN_CITY_STATE, 1
	end

@ VAR_KEREN_CITY_STATE at 1
KerenCity_ResearchFacility_EventScript_NectarResearch::
	msgbox KerenCity_ResearchFacility_Text_NectarResearch, MSGBOX_NPC
	end

@ VAR_KEREN_CITY_STATE at 2
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
	setvar VAR_KEREN_CITY_STATE, 2
	releaseall
	end

@ VAR_KEREN_CITY_STATE at 3
KerenCity_ResearchFacility_EventScript_BenAsksForYouToDeliver::
	msgbox KerenCity_ResearchFacility_Text_BenAsksForYouToDeliver, MSGBOX_NPC
	end

KerenCity_ResearchFacility_EventScript_Scientist1::
	msgbox KerenCity_ResearchFacility_Text_Scientist1, MSGBOX_NPC
	end

KerenCity_ResearchFacility_EventScript_Scientist2::
	msgbox KerenCity_ResearchFacility_Text_Scientist2, MSGBOX_NPC
	end

KerenCity_ResearchFacility_EventScript_OldMan::
	msgbox KerenCity_ResearchFacility_Text_OldMan, MSGBOX_NPC
	end

KerenCity_ResearchFacility_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_PROF_AIDE_RESEARCH_FACILITY_EXP_SHARE, KerenCity_ResearchFacility_EventScript_AideGiveExpShare_Given
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num National seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num National caught
	msgbox KerenCity_ResearchFacility_Text_Aide_HelloImProfessor, MSGBOX_AUTOCLOSE
	compare VAR_0x8009, 15
	goto_if_ge KerenCity_ResearchFacility_AideGiveExpShare
	playse SE_PIN
	waitse
	delay 60
	msgbox KerenCity_ResearchFacility_Text_Aide_CatchMoreMons, MSGBOX_AUTOCLOSE
	release
	end

KerenCity_ResearchFacility_EventScript_AideGiveExpShare_Given::
	msgbox KerenCity_ResearchFacility_Text_Aide_TheExpShare, MSGBOX_AUTOCLOSE
	release
	end

KerenCity_ResearchFacility_AideGiveExpShare::
	playse SE_PIN
	waitse
	delay 60
	msgbox KerenCity_ResearchFacility_Text_Aide_CongratulationsHeresYourReward, MSGBOX_AUTOCLOSE
	giveitem ITEM_EXP_SHARE
	setflag FLAG_PROF_AIDE_RESEARCH_FACILITY_EXP_SHARE
	goto KerenCity_ResearchFacility_EventScript_AideGiveExpShare_Given
	end

KerenCity_ResearchFacility_Text_Scientist1:
	.string "We study POKéMON, flowers, fossils, you\n"
	.string "name it.$"

KerenCity_ResearchFacility_Text_Scientist2:
	.string "CELEBI loves flowers.\p"
	.string "That's why we planted many of them in\n"
	.string "KEREN CITY.$"

KerenCity_ResearchFacility_Text_OldMan:
	.string "Our gym leader loves Flowers.$"

KerenCity_ResearchFacility_Text_BenAsksForYouToDeliver:
	.string "I'm waiting for you to deliver the\n"
	.string "goods.$"

KerenCity_ResearchFacility_Text_GoodToSeeYou:
	.string "Oh hi there {PLAYER}\n"
	.string "It's good to see you.\p"
	.string "You've got the DEVON PARTS?\n"
	.string "That's good.\p"
	.string "That will allow the machines to have\n"
	.string "enough energy.$"

KerenCity_ResearchFacility_Text_NectarResearch:
	.string "I'm currently working on a research\n"
	.string "involving flower nectar.$"

KerenCity_ResearchFacility_Text_BenAlerts:
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

KerenCity_ResearchFacility_Text_Aide_HelloImProfessor:
	.string "Hello, there.\n"
	.string "I'm BEN's assistant.\p"
	.string "I can reward trainers who are\n"
	.string "working on their Pokédex.\p"
	.string "If you have caught 15 or more Pokémon,\n"
	.string "you will win a fabulous prize!\p"
	.string "Here, let me take a look at your\n"
	.string "Pokédex…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Hmhm…\p"
	.string "So, you've seen {STR_VAR_1} Pokémon,\n"
	.string "and you've caught {STR_VAR_2} Pokémon…$"

KerenCity_ResearchFacility_Text_Aide_CatchMoreMons:
	.string "I'm sorry…\n"
	.string "That's not quite 15 POKéMON\p"
	.string "Come back when you have caught more.$"

KerenCity_ResearchFacility_Text_Aide_TheExpShare:
	.string "The Exp. Share awards your Pokémon\n"
	.string "experience from a battle, even if\l"
	.string "they don't directly participate in it.\p"
	.string "I hope it helps you in your journey!$"

KerenCity_ResearchFacility_Text_Aide_CongratulationsHeresYourReward:
	.string "Congratulations!\p"
	.string "Here's your reward!$"


