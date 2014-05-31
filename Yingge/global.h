#pragma once

#include "core/scenemanager.h"
#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include "core/session.h"

namespace yingge
{
	extern SceneManager *sceneManager;
	extern sf::Font *defaultFont;
	extern sf::Music *defaultMusic;
	extern std::map<std::string, sf::Texture *> *textures;
	extern std::map<std::string, sf::SoundBuffer *> *soundBuffers;
	extern yingge::Session *session;

	extern sf::Sprite *loadSprite;
	extern sf::Texture *loadTexture;
}