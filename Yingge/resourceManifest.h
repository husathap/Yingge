#pragma once

#include "global.h"

// This file tells which resource to be loaded into the game.

// DO NOT TOUCH THIS AREA! //////////////////////////////////////////
#define GLOBAL_RESOURCES void loadResources() {
#define TEXTURE(name, path) yingge::textures->insert(std::pair<std::string, sf::Texture *>(#name, new sf::Texture())); yingge::textures->at(#name)->loadFromFile(path);
#define SOUND_BUFFER(name, path) yingge::soundBuffers->insert(std::pair<std::string, sf::SoundBuffer *>(#name, new sf::SoundBuffer())); yingge::soundBuffers->at(#name)->loadFromFile(path);
#define xGLOBAL_RESOURCES }
/////////////////////////////////////////////////////////////////////

GLOBAL_RESOURCES
	TEXTURE(room1, "resources/textures/room1.png")
	TEXTURE(trigger, "resources/textures/trigger.png")
	TEXTURE(gameover, "resources/textures/gameover.png")
	TEXTURE(vsbob, "resources/textures/vsbob.png")
	TEXTURE(algebra, "resources/textures/algebra.png")
	TEXTURE(vscrocobirdo, "resources/textures/vscrocobirdo.png")
	TEXTURE(statistics, "resources/textures/statistics.png")
	TEXTURE(vsyolobear, "resources/textures/vsyolobear.png")
	TEXTURE(logic, "resources/textures/logic.png")
	TEXTURE(classroom, "resources/textures/classroom.png")
	TEXTURE(science, "resources/textures/science.png")
	TEXTURE(divisor, "resources/textures/divisor.png")
	TEXTURE(regina, "resources/textures/regina.png")
	TEXTURE(bob, "resources/textures/bob.png")
	TEXTURE(crocobirdo, "resources/textures/crocobirdo.png")
	TEXTURE(yolobear, "resources/textures/yolobear.png")
	TEXTURE(hallway, "resources/textures/hallway.png")
	TEXTURE(underwater, "resources/textures/underwater.png")
	TEXTURE(nile, "resources/textures/nile.png")
	TEXTURE(metropolis, "resources/textures/metropolis.png")
	TEXTURE(mikepeterson, "resources/textures/mikepeterson.png")
	TEXTURE(ending, "resources/textures/ending.png")
	TEXTURE(badending, "resources/textures/badending.png")
xGLOBAL_RESOURCES