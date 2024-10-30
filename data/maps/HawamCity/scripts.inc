HawamCity_MapScripts::
	.byte 0

HawamCity_EventScript_Give_Mon::
	lockall
	msgbox HawamCity_Text_HeyBitch, MSGBOX_NPC
	setflag FLAG_SYS_POKEMON_GET
	givemon SPECIES_BELDUM, 5	
	givemon SPECIES_DRATINI, 5
	givemon SPECIES_LARVITAR, 5
	releaseall
	end

HawamCity_Text_HeyBitch:
	.string "Hey Bitch.$"
	