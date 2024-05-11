DewfordShore_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DewfordShore_OnLoad
	.byte 0

DewfordShore_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, DewfordShore_EventScript_CloseDewfordCave
	end

DewfordShore_EventScript_CloseDewfordCave::
	setmetatile 31, 20, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 31, 21, METATILE_General_RockWall_SandBase, TRUE
	return

DewfordShore_EventScript_Sign::
	msgbox DewfordShore_Text_Sign, MSGBOX_SIGN
	end

DewfordShore_EventScript_Jean::
	trainerbattle_single TRAINER_JEAN, DewfordShore_Text_JeanIntro, DewfordShore_Text_JeanDefeat
	msgbox DewfordShore_Text_JeanPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Trevor::
	trainerbattle_single TRAINER_TREVOR, DewfordShore_Text_TrevorIntro, DewfordShore_Text_TrevorDefeat
	msgbox DewfordShore_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Chayton::
	trainerbattle_single TRAINER_CHAYTON, DewfordShore_Text_ChaytonIntro, DewfordShore_Text_ChaytonDefeat
	msgbox DewfordShore_Text_ChaytonPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Emily::
	trainerbattle_single TRAINER_EMILY, DewfordShore_Text_EmilyIntro, DewfordShore_Text_EmilyDefeat
	msgbox DewfordShore_Text_EmilyPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Brittany::
	trainerbattle_single TRAINER_BRITTANY, DewfordShore_Text_BrittanyIntro, DewfordShore_Text_BrittanyDefeat
	msgbox DewfordShore_Text_BrittanyPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Christopher::
	trainerbattle_single TRAINER_CHRISTOPHER, DewfordShore_Text_ChristopherIntro, DewfordShore_Text_ChristopherDefeat
	msgbox DewfordShore_Text_ChristopherPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordShore_EventScript_Circe0::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_DEWFORD_SHORE_CIRCE, DewfordShore_EventScript_GrudgeTutor
	checktrainerflag TRAINER_JEAN
	goto_if 1, DewfordShore_EventScript_Circe1
	msgbox DewfordShore_Text_Circe0, MSGBOX_DEFAULT
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe1:
	checktrainerflag TRAINER_TREVOR
	goto_if 1, DewfordShore_EventScript_Circe2
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe2:
	checktrainerflag TRAINER_CHAYTON
	goto_if 1, DewfordShore_EventScript_Circe3
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe3:
	checktrainerflag TRAINER_EMILY
	goto_if 1, DewfordShore_EventScript_Circe4
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe4:
	checktrainerflag TRAINER_BRITTANY
	goto_if 1, DewfordShore_EventScript_Circe5
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe5:
	checktrainerflag TRAINER_CHRISTOPHER
	goto_if 1, DewfordShore_EventScript_Circe6
	goto DewfordShore_EventScript_Circe7

DewfordShore_EventScript_Circe6:
	trainerbattle_single TRAINER_CIRCE, DewfordShore_Text_Circe6, DewfordShore_Text_CirceDefeat, DewfordShore_EventScript_GrudgeTutor
	setflag FLAG_BEAT_DEWFORD_SHORE_CIRCE
	end

DewfordShore_EventScript_Circe7:
	msgbox DewfordShore_Text_Circe7, MSGBOX_NPC
	end

DewfordShore_EventScript_GrudgeTutor::
	lock
	faceplayer
	msgbox DewfordShore_Text_Grudge_Teach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordShore_EventScript_GrudgeDeclined
	msgbox DewfordShore_Text_GrudgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_GRUDGE
	call DewfordShore_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, DewfordShore_EventScript_GrudgeDeclined
	goto DewfordShore_EventScript_GrudgeTaught
	end

DewfordShore_EventScript_GrudgeDeclined::
	msgbox DewfordShore_Text_GrudgeDeclined, MSGBOX_DEFAULT
	release
	end

DewfordShore_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

DewfordShore_EventScript_GrudgeTaught::
	msgbox DewfordShore_Text_GrudgeTaught, MSGBOX_DEFAULT
	release
	end

DewfordShore_Text_Sign:
	.string "DEWFORD SHORES\n"
	.string "Please avoid littering the dunes!$"

DewfordShore_Text_Circe0:
	.string "Oooooh, these CAMPERS and PICNICKERS!\n"
	.string "How I loathe them!\p"
	.string "They challenged me to a POKéMON fight\n"
	.string "but I lost…\p"
	.string "The others didn't even help and laughed\n"
	.string "at me!\p"
	.string "If you could avenge me by beating them\n"
	.string "all, that would be very helpful of you.$"

DewfordShore_Text_Circe7:
	.string "What are you waiting for?\n"
	.string "Go ahead and defeat them!\p"
	.string "Unless you are with them and are just\n"
	.string "here to make fun of me?\p"
	.string "Just you wait until I get my occult\n"
	.string "powers back…$"

DewfordShore_Text_Circe6:
	.string "I'm finally avenged!\p"
	.string "You're sure strong, can I challenge\n"
	.string "you to a POKéMON fight?$"

DewfordShore_Text_Grudge_Teach:
	.string "I can make your Pokémon use their\n"
	.string "resentment to weaken their opponents.\p"
	.string "Are you interested?$"

DewfordShore_Text_GrudgeDeclined:
	.string "Hatred's power sure is strong.\p"
	.string "You're making a big mistake by refusing\n"
	.string "my offer.$"

DewfordShore_Text_GrudgeWhichMon:
	.string "Which one of your POKéMON is\n"
	.string "ready to recieve my hex?$"

DewfordShore_Text_GrudgeTaught:
	.string "Come see me again if you want\n"
	.string "another one of your POKéMON to be\l"
	.string "bewitched… Heeheehee…$"

DewfordShore_Text_CirceDefeat:
	.string "Drat… Not again…$"

