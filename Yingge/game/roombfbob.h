#pragma once

#include "../lang/rm.h"
#include "../lang/cs.h"

CUTSCENE(Regina1)
	$ENTITY(regina)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 300, 250)
	x$$CONSTRUCT

	LABEL(choice1)
		SET_NUMBER(reginaScore, NUMBER(reginaScore) + 1)
		TEXT("Regina: Thank you for your encouragement!")
	xLABEL

	LABEL(choice2)
		TEXT("Regina: Fine! I'm not scared... Not a bit!")
	xLABEL

	LABEL(alreadyTalked)
		TEXT("Regina: I don't have anything else to say... Please let's us go on and find YOLO Bear!")
	xLABEL

	LABEL(talk)
		SET_BOOLEAN(regina1, true)
		TEXT("Regina: I'm a bit scared... What should I do?")
		TEXT("Protagonist: ...")
		DECIDE("Pick the protagonist's response:", "I'll protect you.", "You coward!")
		THEN_SELECT
			CASE(0, choice1)
			CASE(1, choice2)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(regina)
		IF(BOOLEAN(regina1), alreadyTalked)
		ELSE(talk)
		xIF
	xMAIN
xCUTSCENE

ROOM(RoomBeforeBob)
	$ENTITY(background)
	$TEXT_BUTTON(goRegina)
	$TEXT_BUTTON(goBob)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(underwater), 0, 0)
		ADD_ENTITY(background)

		$$TEXT_BUTTON(goRegina, "Talk to Regina", 450, 450, 30)
		$$TEXT_BUTTON(goBob, "Move On", 450, 300, 30)

		BIND_W_EVENT_UNREG(goRegina, Regina1)
		BIND_W_EVENT(goBob, Bob)
	x$$CONSTRUCT
xROOM