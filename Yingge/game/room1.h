#pragma once

#include "../lang/rm.h"

ROOM(Room1)
$ENTITY(entBackground)
$TEXT_BUTTON(triggerTest)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(entBackground, "background", -1, GLOBAL_TEXTURE(room1), 0, 0)
		ADD_ENTITY(entBackground)
		$$TEXT_BUTTON(triggerTest, "Test Trigger", 100, 100, 30);

		BIND_W_NAVIGATE(triggerTest, Trigger)
	x$$CONSTRUCT
xROOM