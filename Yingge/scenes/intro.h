#pragma once

#include "../lang/cs.h"

CUTSCENE(Intro)
	$$NO_CONSTRUCT

	MAIN
		TEXT("Hello. This is a demo of the project.")
		TEXT("This demo aims to demonstrate various features of the projects and the technique of creating ad-hoc programming language.")
		TEXT("I will send you to a room so you can explore more.")
		NAVIGATE(Room1)
	xMAIN
xCUTSCENE