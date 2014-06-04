#pragma once

#include "../lang/rm.h"
#include "../lang/cs.h"

CUTSCENE(Regina2)
	$ENTITY(regina)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 300, 250)
	x$$CONSTRUCT

	LABEL(choice1)
		SET_NUMBER(reginaScore, NUMBER(reginaScore) + 1)
		TEXT("Regina: Thank you for the hug!")
	xLABEL

	LABEL(choice2)
		TEXT("Regina: It's my hair, isn't it?")
	xLABEL

	LABEL(alreadyTalked)
		TEXT("Regina: Let's us go find YOLO Bear!")
	xLABEL

	LABEL(talk)
		SET_BOOLEAN(regina2, true)
		TEXT("Regina: That fish was actually brutal. I could have helped you, but I was scared I forgot all the maths. Can you hug me?")
		TEXT("Protagonist: ...")
		DECIDE("Pick the protagonist's response:", "Yes.", "No!")
		THEN_SELECT
			CASE(0, choice1)
			CASE(1, choice2)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(regina)
		IF(BOOLEAN(regina2), alreadyTalked)
		ELSE(talk)
		xIF
	xMAIN
xCUTSCENE

ROOM(RoomBeforeCrocobirdo)
	$ENTITY(background)
	$TEXT_BUTTON(goRegina)
	$TEXT_BUTTON(goCrocobirdo)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(nile), 0, 0)
		ADD_ENTITY(background)

		$$TEXT_BUTTON(goRegina, "Talk to Regina", 350, 350, 30)
		$$TEXT_BUTTON(goCrocobirdo, "Move On", 350, 430, 30)

		BIND_W_EVENT_UNREG(goRegina, Regina2)
		BIND_W_EVENT(goCrocobirdo, Crocobirdo)
	x$$CONSTRUCT
xROOM