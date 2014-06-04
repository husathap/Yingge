#pragma once

#include "../lang/cs.h"

CUTSCENE(Trigger)
	$ENTITY(entBackground)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(entBackground, "background", -1, GLOBAL_TEXTURE(trigger), 0, 0)
		ADD_ENTITY(entBackground)
	x$$CONSTRUCT

	LABEL(triggerOn)
		SET_BOOLEAN(trigger, false)
		TEXT("The trigger is ON. It will be turned OFF!")
		NAVIGATE(Room1)
	xLABEL

	LABEL(triggerOff)
		SET_BOOLEAN(trigger, true)
		TEXT("The trigger is OFF. It will be turned ON!")
		NAVIGATE(Room1)
	xLABEL

	MAIN
		IF(BOOLEAN(trigger), triggerOn)
		ELSE(triggerOff)
		xIF
	xMAIN
xCUTSCENE