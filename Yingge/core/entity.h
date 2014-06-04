#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace yingge
{
	/* A class that is basically sf::Sprite but made smarter. An entity can be updated.
	 * It is also has a ZOrder and also has a key which allows it and its buddies to be
	 * manipulated at the same time.
	 */
	class Entity : public sf::Sprite
	{
	private:
		int stage = 0;		// A private variable to help with the default fade-in/out effect.
	public:
		int ZOrder = 0;			// Indicate the layer that the entity will be drawn in.
		std::string key = "";	// Key that the entity will be referred as.

		virtual void update(sf::RenderWindow *w);		// Update the entity.


		/* The variables dead and deleteRequest are very important to an Entity's life cycle.
		 * In the current design, an Entity works with an EntityManager. When the manager is
		 * called to remove an Entity. The Entity is actually not removed immediately. What the
		 * remove does is to set the Entity's deleteRequest to true.
		 *
		 * Once deleteRequest is set to true, the Entity begins to prepared to be deleted. In the
		 * default case, the Entity fades out from the screen. When the Entity is ready to be
		 * deleted, dead is set to true. Only then, the manager will actually remove the Entity
		 * from the memory.
		 */
		bool dead = false;			// Indicate whether the entity should be killed off or not.
		bool deleteRequest = false; // Send this as a signal to the entity that it should kill itself.

		// This allows the entity to be reused.
		void reset();
	};
}