PetalburgThicket_MapScripts::
	.byte 0

PetalburgThicket_EventScript_MysteriousVine::
	lock
	msgbox PetalburgThicket_Text_MysteriousVine, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, PetalburgThicket_EventScript_WarpToThicket
	end

PetalburgThicket_EventScript_WarpToThicket::
	warp MAP_PETALBURG_WOODS, 43, 4
	waitstate
	release
	end

PetalburgThicket_Text_MysteriousVine:
	.string "Light is coming from behind the trees.\n"
	.string "Go through?$"
