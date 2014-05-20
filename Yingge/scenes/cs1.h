// CSC324 with C++!!!

// LAZY PROGRAMMING FOR THE WIN!

#pragma once

#include "../lang/cs.h"
//#include "rm1.h"

CUTSCENE(cs1)
	$TEXTURE(pingu)
	$ENTITY(e1)
	$ENTITY(e2)
	$ENTITY(e3)

	$$CONSTRUCT
		$$GLOBAL_TEXTURE(iNAME pingu, iSOURCE "resources/pingu.jpg")
		$$TEXTURE(iNAME pingu, iSOURCE "resources/pingu.jpg")
		$$SIMPLE_ENTITY(iNAME e1, iKEY "e1", iZORDER 0, iTEXTURE pingu, iX 0, iY 0)
		$$SIMPLE_ENTITY(e2, "e2", 0, pingu, 100, 100)
		$$SIMPLE_ENTITY(e3, "e3", 0, pingu, 200, 200)
		//$$SIMPLE_ENTITY(NAME e3, KEY "e3", ZORDER 0, GLOBAL_TEXTURE(pingu))
	x$$CONSTRUCT

	MAIN
		TEXT("Release the pingus!")
		PLAY_MUSIC("resources/music/Ganbare.ogg")
		ADD_ENTITY(iNAME e1)
		ADD_ENTITY(iNAME e2)
		ADD_ENTITY(iNAME e3)
		DECIDE(iQUESTION "Spare the pingus?", iANSWERS "Yes", "No") THEN_SELECT 
			CASE(0, spare) 
			DEFAULT(noSpare) 
		xTHEN_SELECT
	xMAIN

	LABEL(spare)
		STOP_MUSIC
		//GOTO_TITLE
		NAVIGATE(rm1)
	xLABEL

	LABEL(noSpare)
		PAUSE_MUSIC
		REM_ENTITY("e2")
		REM_ENTITY(0)
		RESUME_MUSIC
		TEXT("So unkind!")
		STOP_MUSIC
		NAVIGATE_TITLE
	xLABEL
xCUTSCENE