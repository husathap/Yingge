#pragma once

#include "core/sessionSetup.h"

#define VARIABLES namespace yingge { void setVariables(yingge::Session *s) {
#define STRING(name) s->strings.insert(std::pair<std::string, std::string>(#name, ""));
#define NUMBER(name) s->numbers.insert(std::pair<std::string, double>(#name, 0));
#define BOOLEAN(name) s->booleans.insert(std::pair<std::string, bool>(#name, false));
#define xVARIABLES }}

VARIABLES
	STRING(Test)
	NUMBER(Test)
xVARIABLES