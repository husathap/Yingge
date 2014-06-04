#pragma once

#include "../lang/cs.h"

CUTSCENE(GameOver)
	$ENTITY(background)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(gameover), 0, 0)
	x$$CONSTRUCT

	MAIN
		ADD_ENTITY(background)
		NAVIGATE_TITLE
	xMAIN
xCUTSCENE