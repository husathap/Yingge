#pragma once

#include "core/sceneNavigation.h"

#include "game/trigger.h"
#include "game/room1.h"
#include "game/intro.h"

#include "game/bob.h"
#include "game/crocobirdo.h"
#include "game/yolobear.h"
#include "game/hallway.h"
#include "game/roombfbob.h"
#include "game/roombfcrocobirdo.h"
#include "game/roombfyolobear.h"
#include "game/ending.h"

#include "game/gameover.h"

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
	SCENE(Hallway)
	
	SCENE(Crocobirdo)
	SCENE(Bob)
	SCENE(YOLOBear)

	SCENE(RoomBeforeBob)
	SCENE(RoomBeforeCrocobirdo)
	SCENE(RoomBeforeYOLOBear)
	SCENE(Ending)

	SCENE(GameOver)
	// ADD NEW SCENES THAT USE IO HERE:
	// SCENE(example)
xSCENES