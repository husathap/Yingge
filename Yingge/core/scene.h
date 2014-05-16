#pragma once

#include <SFML/Graphics.hpp>

/* An object that represent a scene that is being run. */
namespace yingge 
{
	class Scene 
	{
	public:
		virtual bool update(sf::RenderWindow *w) = 0;
		virtual void draw(sf::RenderWindow *w) = 0;
	};
}
