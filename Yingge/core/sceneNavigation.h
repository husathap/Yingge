#pragma once

/* This file contains a header for a method that helps to get a pointer to a new scene.
 */

#include <string>
#include "scene.h"

namespace yingge 
{
	yingge::Scene *getScene(std::string name);
}