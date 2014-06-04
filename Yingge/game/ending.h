#pragma once

#include "../lang/cs.h"

CUTSCENE(Ending)
	$ENTITY(background)
	$ENTITY(background2)
	$ENTITY(background3)
	$ENTITY(yolobear)
	$ENTITY(regina)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(mikepeterson), 0, 0)
		$$SIMPLE_ENTITY(background2, "background2", -1, GLOBAL_TEXTURE(ending), 0, 0)
		$$SIMPLE_ENTITY(background3, "background3", -1, GLOBAL_TEXTURE(badending), 0, 0)
	x$$CONSTRUCT

	LABEL(badEnd)
		TEXT("It turned out that the protagonist and Regina actually fall for each other! They end up marrying each other!")
		TEXT("Later on, Regina, through nepotism, is made a leader of a micronation and the protagonist is made into a cabinet.")
		REM_ENTITY("background2")
		ADD_ENTITY(background3)
		TEXT("Regina turns out to be a power hungry person and purges many of her cabinets. The protagonist doesn't survive the purge.")
		TEXT("Bad end!")
		NAVIGATE_TITLE
	xLABEL

	LABEL(neutralEnd)
		TEXT("It turned out that the protagonist and Regina didn't get along well. After the incidence, they go on their own separate ways.")
		TEXT("Neutral ending!")
		NAVIGATE_TITLE
	xLABEL

	MAIN
		ADD_ENTITY(background)
		TEXT("Mike Peterson: That YOLO swagger is finally banished into the Null Space! I shall send you home then!")
		REM_ENTITY("background")

		ADD_ENTITY(background2)
		TEXT("So finally, both the protagonist and Regina are sent home by Mike Peterson. This should serve as a lesson to not mess up other people's stuffs.")
		TEXT("During the course of the game, you and Regina are forced to bond to each other. Well, how did this go?")
		IF(NUMBER(reginaScore) >= 2, badEnd)
		ELSE(neutralEnd)
		xIF
	xMAIN
xCUTSCENE