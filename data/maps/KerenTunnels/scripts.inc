.set LOCALID_BAG, 20

KerenTunnels_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION KerenTunnels_OnTransition
	.byte 0

KerenTunnels_OnTransition:
	call_if_set FLAG_OBTAINED_OLD_FLASHLIGHT, KerenTunnels_OnTransition_Lighter
	setflashlevel 7
	end

KerenTunnels_OnTransition_Lighter:
	setflashlevel 6
	end

KerenTunnels_EventScript_Ilan::
	trainerbattle_single TRAINER_BRICE, KerenTunnels_Text_HereIcome, KerenTunnels_Text_UghITried
	msgbox KerenTunnels_Text_ShouldveBroughtFlashlight, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Or::
	trainerbattle_single TRAINER_TAKAO, KerenTunnels_Text_CantSeeMuch, KerenTunnels_Text_OofILost
	msgbox KerenTunnels_Text_IDontNeedToSee, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Gal::
	trainerbattle_single TRAINER_DREW, KerenTunnels_Text_HealingItems, KerenTunnels_Text_MoreItems
	msgbox KerenTunnels_Text_MoreTraining, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Ronit::
	trainerbattle_single TRAINER_AUTUMN, KerenTunnels_Text_IveHeardAboutTeamSmash, KerenTunnels_Text_GoodBattle
	msgbox KerenTunnels_Text_TheyScareMe, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Dan::
	trainerbattle_single TRAINER_EDWARD, KerenTunnels_Text_PsychicMons, KerenTunnels_Text_ForseenFuture
	msgbox KerenTunnels_Text_ThereIsMore, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Boaz::
	trainerbattle_single TRAINER_BILLY, KerenTunnels_Text_WhereAmI, KerenTunnels_Text_WhyAmIHere
	msgbox KerenTunnels_Text_IDontRemember, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Dion::
	trainerbattle_single TRAINER_JOSH, KerenTunnels_Text_ImGladToBeHere, KerenTunnels_Text_ShouldveSeenIt
	msgbox KerenTunnels_Text_ThereIsSoMuchHere, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Kobi::
	trainerbattle_single TRAINER_SAWYER_1, KerenTunnels_Text_RockySide, KerenTunnels_Text_TooStrong
	msgbox KerenTunnels_Text_WellBattled, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Bar::
	trainerbattle_single TRAINER_VICTOR, KerenTunnels_Text_AreYouOk, KerenTunnels_Text_ExcellentBattle
	msgbox KerenTunnels_Text_SplendidWorkThere, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Daniel_F::
	trainerbattle_single TRAINER_HALEY_1, KerenTunnels_Text_CuteMons, KerenTunnels_Text_YouHurtThem
	msgbox KerenTunnels_Text_ThereAreMoreMons, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Idan::
	trainerbattle_single TRAINER_LARRY, KerenTunnels_Text_IveHeardThereAreFossils, KerenTunnels_Text_GoingToRest
	msgbox KerenTunnels_Text_GameOn, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Yoav::
	trainerbattle_single TRAINER_ELI, KerenTunnels_Text_CommotionHappening, KerenTunnels_Text_StrongForces
	msgbox KerenTunnels_Text_WhatWasIt, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Daniel_M::
	trainerbattle_single TRAINER_DAVIS, KerenTunnels_Text_BugPokemon, KerenTunnels_Text_SoManyOfThem
	msgbox KerenTunnels_Text_IGaveItMyAll, MSGBOX_AUTOCLOSE
	end

KerenTunnels_EventScript_Bag::
	lock
	giveitem ITEM_OLD_FLASHLIGHT
	removeobject LOCALID_BAG
	animateflash 6
	setflashlevel 6
	setflag FLAG_OBTAINED_OLD_FLASHLIGHT
	release
	end

KerenTunnels_Text_HereIcome:
	.string "Watch out for my POKéMON.$"

KerenTunnels_Text_UghITried:
	.string "Ugh!\n"
	.string "I tried…$"

KerenTunnels_Text_ShouldveBroughtFlashlight:
	.string "You should have brought flashlight.$"

KerenTunnels_Text_CantSeeMuch:
	.string "I can't see much but that won't\n"
	.string "stop me.$"

KerenTunnels_Text_OofILost:
	.string "Oof I lost,\n"
	.string "I can't believe it.$"

KerenTunnels_Text_IDontNeedToSee:
	.string "I don't need to see to train my\n"
	.string "POKéMON.$"

KerenTunnels_Text_HealingItems:
	.string "I hope you brought some healing items\n"
	.string "because this cave is full of trainers.$"

KerenTunnels_Text_MoreItems:
	.string "Good thing I brought some\n"
	.string "healing items.$"

KerenTunnels_Text_MoreTraining:
	.string "My Sandshrew could use more training.$"

KerenTunnels_Text_IveHeardAboutTeamSmash:
	.string "I've heard about team SMASH.\n"
	.string "They are scary People.\p"
	.string "I hope I don't get to ecnounter them.$"

KerenTunnels_Text_GoodBattle:
	.string "Good job!\n"
	.string "That was a good battle.$"

KerenTunnels_Text_TheyScareMe:
	.string "Team SMASH scares me.$"

KerenTunnels_Text_PsychicMons:
	.string "Lets see how you face my PSYCHIC\n"
	.string "POKéMON.$"

KerenTunnels_Text_ForseenFuture:
	.string "I've seen that coming.$"

KerenTunnels_Text_ThereIsMore:
	.string "There is more than meets the eye.$"

KerenTunnels_Text_WhereAmI:
	.string "Where am I?$"

KerenTunnels_Text_WhyAmIHere:
	.string "Why am I here?$"

KerenTunnels_Text_IDontRemember:
	.string "I don't remember getting here.$"

KerenTunnels_Text_ImGladToBeHere:
	.string "I'm glad to be here.\n"
	.string "There are so many trainers to battle.$"
KerenTunnels_Text_ShouldveSeenIt:
	.string "Well, I should have seen it coming.$"

KerenTunnels_Text_ThereIsSoMuchHere:
	.string "There is so much to do here.\n"
	.string "Too bad it's so dark in here.$"

KerenTunnels_Text_RockySide:
	.string "You got me rocking and grooving.\n"
	.string "It's easy to get lost in here.$"
KerenTunnels_Text_TooStrong:
	.string "Your POKéMON are too strong for me.$"

KerenTunnels_Text_WellBattled:
	.string "Well battled trainer.\n"
	.string "There is more to this cave,\l"
	.string "That's why I'm going to explore it.$"

KerenTunnels_Text_AreYouOk:
	.string "So many trainers, right?\n"
	.string "Are you okay with all those battles?$"

KerenTunnels_Text_ExcellentBattle:
	.string "Excellent Battle there.\n"
	.string "You fought splendidly.$"

KerenTunnels_Text_SplendidWorkThere:
	.string "Splendid work. My ELECTRIC POKéMON\n"
	.string "couldn't stand a chance."

KerenTunnels_Text_CuteMons:
	.string "My POKéMON are cute.\n"
	.string "Let's battle!$"

KerenTunnels_Text_YouHurtThem:
	.string "Look at what you did!\n"
	.string "You hurt them!$"

KerenTunnels_Text_ThereAreMoreMons:
	.string "Hmm, there are more POKéMON here to\n"
	.string "grab.$"

KerenTunnels_Text_IveHeardThereAreFossils:
	.string "I've heard there are fossils in this\n"
	.string "cave.\p"
	.string "I couldn't find them though.$"

KerenTunnels_Text_GoingToRest:
	.string "I'm going to rest a bit.$"

KerenTunnels_Text_GameOn:
	.string "Think you can find those fossils before\n"
	.string "me? Game on.$"

KerenTunnels_Text_CommotionHappening:
	.string "There is a lot of commotion happening\n"
	.string "around here.$"

KerenTunnels_Text_StrongForces:
	.string "What a battle!\n"
	.string "Such strong forces.$"

KerenTunnels_Text_WhatWasIt:
	.string "What was it that brought all of those\n"
	.string "trainers here? I wonder.$"

KerenTunnels_Text_BugPokemon:	
	.string "I've got so many BUG POKéMON.\n"
	.string "Lets see how you do.$"

KerenTunnels_Text_SoManyOfThem:
	.string "Ugh, but I brought so many of them.$"

KerenTunnels_Text_IGaveItMyAll:
	.string "I gave it my all.$"
