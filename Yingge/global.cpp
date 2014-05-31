#pragma once

#include "global.h" 

namespace yingge
{
	SceneManager *sceneManager = nullptr;
	sf::Font *defaultFont;
	sf::Music *defaultMusic;
	std::map<std::string, sf::Texture *> *textures;
	std::map<std::string, sf::SoundBuffer *> *soundBuffers;
	Session *session = nullptr;
	sf::Sprite *loadSprite;
	sf::Texture *loadTexture;
}