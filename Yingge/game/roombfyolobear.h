#pragma once

#include "../lang/rm.h"
#include "../lang/cs.h"

CUTSCENE(Regina3)
	$ENTITY(regina)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 300, 250)
	x$$CONSTRUCT

	LABEL(choice1)
		SET_NUMBER(reginaScore, NUMBER(reginaScore) + 1)
		TEXT("Regina: Mmmm.... Thanks")
	xLABEL

	LABEL(choice2)
		TEXT("Regina: You're tearing me apart with your silence!")
	xLABEL

	LABEL(alreadyTalked)
		TEXT("Regina: I can smell a bear near here. My pink hair mutation also allows me to smell out bears.")
	xLABEL

	LABEL(talk)
		SET_BOOLEAN(regina3, true)
		TEXT("Regina: That was scary. That crocodile bird thing knows about uni-leve stats! How?")
		TEXT("Protagonist: ...")
		DECIDE("Pick the protagonist's response:", "Make out with Regina.", "Leave her be.")
		THEN_SELECT
			CASE(0, choice1)
			CASE(1, choice2)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(regina)
		IF(BOOLEAN(regina3), alreadyTalked)
		ELSE(talk)
		xIF
	xMAIN
xCUTSCENE

ROOM(RoomBeforeYOLOBear)
	$ENTITY(background)
	$TEXT_BUTTON(goRegina)
	$TEXT_BUTTON(goYOLOBear)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(metropolis), 0, 0)
		ADD_ENTITY(background)

		$$TEXT_BUTTON(goRegina, "Talk to Regina", 300, 350, 30)
		$$TEXT_BUTTON(goYOLOBear, "Move On", 300, 400, 30)

		BIND_W_EVENT_UNREG(goRegina, Regina3)
		BIND_W_EVENT(goYOLOBear, YOLOBear)
	x$$CONSTRUCT
xROOM