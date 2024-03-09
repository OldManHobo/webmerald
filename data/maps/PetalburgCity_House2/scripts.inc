PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "DATA is a recently discovered\n"
	.string "type of POKéMON.\p"
	.string "They possess the power to \n"
	.string "control technology, whatever\p"
	.string "that means...$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "I battled NORMAN once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for POKéMON.$"

