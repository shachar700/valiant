KenkoriaCity_PrettyPetalFlowerShop_MapScripts::
	.byte 0

KenkoriaCity_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, KenkoriaCity_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
	msgbox KenkoriaCity_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	release
	end

KenkoriaCity_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
	msgbox KenkoriaCity_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox KenkoriaCity_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_WAILMER_PAIL
	addvar VAR_KEREN_CITY_GYM_STATE, 1
	release
	end

KenkoriaCity_EventScript_NoCelebiThisYear::
	msgbox KenkoriaCity_Text_NoCelebiThisYear, MSGBOX_NPC
	end

KenkoriaCity_PrettyPetalFlowerShop_Text_YouCanHaveThis:
	.string "Hello!\p"
	.string "The more attention you give to flowers,\n"
	.string "the more beautifully they bloom.\p"
	.string "There's a spark in your eyes when\n"
	.string "you look at the flowers.\p"
	.string "You can have this.$"

KenkoriaCity_PrettyPetalFlowerShop_Text_WailmerPailExplanation:
	.string "While BERRY plants are growing,\n"
	.string "water them with the WAILMER PAIL.\p"
	.string "Oh, another thing.\p"
	.string "If you don't pick BERRIES for a while,\n"
	.string "they'll drop off onto the ground.\l"
	.string "But they'll sprout again.\p"
	.string "Isn't that awesome?\n"
	.string "It's like they have the will to live.$"
	
KenkoriaCity_Text_NoCelebiThisYear:
	.string "This time of year CELEBI didn't appear\n"
	.string "to flourish our flowers.\p"
	.string "I wonder what happened…$"
