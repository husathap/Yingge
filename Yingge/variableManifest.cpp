#pragma once

#include "core/sessionSetup.h"

// DO NOT TOUCH THIS PART! /////////////////////////////////////////////////////////////
#define VARIABLES namespace yingge { void setVariables(yingge::Session *s) {
#define STRING(name) s->strings.insert(std::pair<std::string, std::string>(#name, ""));
#define NUMBER(name) s->numbers.insert(std::pair<std::string, double>(#name, 0));
#define BOOLEAN(name) s->booleans.insert(std::pair<std::string, bool>(#name, false));
#define xVARIABLES }}
////////////////////////////////////////////////////////////////////////////////////////

VARIABLES
	BOOLEAN(DefeatedCrocobirdo)
	BOOLEAN(DefeatedPyrite)
	BOOLEAN(DefeatedVug)
	BOOLEAN(DefeatedYOLOBear)
xVARIABLES