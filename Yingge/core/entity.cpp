#include "entity.h"

/* This file contains the default logic for Entity class. The default logic for
 * Entity class is to do fade-in once the entity is created and fade-out if its
 * deleteRequest is set to true.
 */
namespace yingge
{

	void Entity::update(sf::RenderWindow *w)
	{
		sf::Color c = Entity::getColor();
		int alpha = (int)c.a;

		if (stage == 0)
		{
			sf::Color c = Entity::getColor();
			Entity::setColor(sf::Color(c.r, c.g, c.b, 0));
			stage++;
		}
		else if (stage == 1)
		{
			alpha += 10;
			if (alpha < 255)
				Entity::setColor(sf::Color(c.r, c.g, c.b, (sf::Uint8)alpha));
			else
			{
				Entity::setColor(sf::Color(c.r, c.g, c.b, 255));
				stage++;
			}
		}
		else if (stage == 2)
		{
			if (deleteRequest == true)
				stage++;
		}
		else
		{
			alpha -= 10;

			if (alpha > 0)
				Entity::setColor(sf::Color(c.r, c.g, c.b, (sf::Uint8)alpha));
			else
			{
				Entity::setColor(sf::Color(c.r, c.g, c.b, 0));
				dead = true;
			}
		}
	}
}