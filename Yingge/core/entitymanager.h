#pragma once

#include "entity.h"
#include "textbutton.h"
#include <list>

namespace yingge 
{
	/* A container for Entities. This container has the ability to update and
	 * draw Entities. It also manages the addition of new Entities and the
	 * removal of the old ones.
	 */
	class EntityManager
	{
	private:
		// The data structure that contains the Entities themselves.
		std::vector<Entity *> m_entities = std::vector<Entity *>();
		
	public:
		// The entities manipulation functions.
		void add(Entity *e);			// Add a new entity.
		void remove(std::string key);	// Remove an entity by its key.
		void remove(int ZOrder);		// Remove an entity by its ZOrder.

		void update(sf::RenderWindow *w);	// Update the Entities. Call this from a Scene's update logic.
		void draw(sf::RenderWindow *w);		// Draw the Entities. Call this from a Scene's drawing logic.
	};
}