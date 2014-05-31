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
xGLOBAL_RESOURCES