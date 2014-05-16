#include "sceneNavigation.h"
#include "scenes/rm1.h"
#include "scenes/rm2.h"

#define SCENES yingge::Scene *getScene(std::string name) {
#define SCENE(n) if (name == #n) return (yingge::Scene *)new n();
#define xSCENES return nullptr; }


SCENES
	SCENE(rm1)
	SCENE(rm2)
xSCENES