#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


//#include <SFML/Graphics.hpp>
#include "global.h"
#include "scenes/first.h"
#include "core/io.h"
#include "setting.h"
#include "resourceManifest.h"
#include <SFML/System/Thread.hpp>

using namespace yingge;

bool loadFinished = false;

int main()
{
	// Pre-initialization
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Yingge");

	defaultFont = new sf::Font();
	defaultFont->loadFromFile("resources/fonts/default.ttf");

	defaultMusic = new sf::Music();

	textures = new std::map<std::string, sf::Texture *>();
	soundBuffers = new std::map<std::string, sf::SoundBuffer *>();

	sceneManager = SceneManager::getInstance();
	sceneManager->overlayScene(new First());

	session = new Session();

	if (!loadFinished)
	{
		// Draw loading screen stuff here:
		loadTexture = new sf::Texture();
		loadSprite = new sf::Sprite();

		loadTexture->loadFromFile("resources/textures/loading.png");
		loadSprite->setTexture(*loadTexture);
		loadSprite->setColor(sf::Color::White);
		loadSprite->setPosition(0, 0);

		window.clear();
		window.draw(*loadSprite);
		window.display();

		loadResources();
		loadFinished = true;
		

		goto INI_WINDOW;
	}
	else
	{
INI_WINDOW:
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// Update the scenes.
			sceneManager->update(&window);
			if (!sceneManager->isBusy())
				window.close();
		}
	}

	return 0;
}