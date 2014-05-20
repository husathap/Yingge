#include "core/sceneNavigation.h"
#include "scenes/rm1.h"
#include "scenes/rm2.h"

/* This file is used to register a new scene for the game.
 */

// DO NOT CHANGE THIS PART! ////////////////////////////////////////
#define SCENES namespace yingge { yingge::Scene *getScene(std::string name) {
#define SCENE(n) if (name == #n) return (yingge::Scene *)new n();
#define xSCENES return nullptr; }}
////////////////////////////////////////////////////////////////////

SCENES
	SCENE(rm1)
	SCENE(rm2)

	// ADD NEW SCENES THAT USE IO HERE:
	// SCENE(example)
xSCENES