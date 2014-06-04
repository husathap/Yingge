#pragma once

#include "../lang/cs.h"

CUTSCENE(Intro)
	$ENTITY(background)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(classroom), 0, 0)
	x$$CONSTRUCT

	MAIN
		TEXT("Hello. This game is only for dogfooding purposes. So it's not guaranteed to be fun. It's only to test out the engine's usability.")
		ADD_ENTITY(background)
		TEXT("???: Hello, Mr. Axson here. Today I shall introduce you to limits! They are wonderful and allow you to finally grasp that mythical creature calculus.")
		TEXT("Axson: Those who are sleepy and don't want high mark in my class, you are excused to sleep.")
		TEXT("Protagonist: (thinking) I am already a math prodigy with 90% on the previous test. This section will also be pathetic!")
		TEXT("Protagonist: ... ZZZ")
		REM_ENTITY("background")
		ADD_ENTITY(background)
		TEXT("Axson: Hey, kiddo. The school is over!")
		NAVIGATE(Hallway)
	xMAIN
xCUTSCENE