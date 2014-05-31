#pragma once

#include "core/sceneNavigation.h"

#include "scenes/trigger.h"
#include "scenes/room1.h"
#include "scenes/intro.h"

/* This file is used to register a new scene for the game.
 */

// DO NOT CHANGE THIS PART! ////////////////////////////////////////
#define SCENES namespace yingge { yingge::Scene *getScene(std::string name) {
#define SCENE(n) if (name == #n) return (yingge::Scene *)new n();
#define xSCENES return nullptr; }}
////////////////////////////////////////////////////////////////////

SCENES
	SCENE(Intro)
	SCENE(Trigger)
	SCENE(Room1)
	
	// ADD NEW SCENES THAT USE IO HERE:
	// SCENE(example)
xSCENES