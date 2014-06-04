#include "entitymanager.h"

/* This file contains the logic for EntityManager class. The documentation
 * for the class can be read in entitymanager.h.
 */

namespace yingge
{
	// Adding a new entity into the manager.
	void EntityManager::add(Entity *e)
	{
		if (EntityManager::m_entities.empty())
		{
			EntityManager::m_entities.push_back(e);
		}
		else if (e->ZOrder >= EntityManager::m_entities.back()->ZOrder)
			EntityManager::m_entities.push_back(e);
		else
		{
			auto i = EntityManager::m_entities.begin();
			while (i != EntityManager::m_entities.end())
			{
				Entity *iptr = *i._Ptr;
				if (e->ZOrder < iptr->ZOrder)
				{
					EntityManager::m_entities.insert(i, e);
					break;
				}
				i++;
			}
		}
	}

	void EntityManager::remove(std::string key)
	{
		for (auto i = EntityManager::m_entities.begin(); i != EntityManager::m_entities.end(); i++)
		{
			Entity *iptr = *(i._Ptr);
			if (key == iptr->key)
				iptr->deleteRequest = true;
		}
	}

	void EntityManager::remove(int ZOrder)
	{
		for (auto i = EntityManager::m_entities.begin(); i != EntityManager::m_entities.end(); i++)
		{
			Entity *iptr = *(i._Ptr);
			if (ZOrder == iptr->ZOrder)
				iptr->deleteRequest = true;
		}
	}

	void EntityManager::update(sf::RenderWindow *w)
	{
		// Remove all dead m_entities.
		unsigned int i = 0;
		while (i < EntityManager::m_entities.size())
		{
			if (EntityManager::m_entities[i]->dead)
			{
				EntityManager::m_entities[i]->dead = false;
				EntityManager::m_entities[i]->deleteRequest = false;
				EntityManager::m_entities[i]->reset();
				EntityManager::m_entities.erase(EntityManager::m_entities.begin() + i);
				i--;
			}
			else
			{
				EntityManager::m_entities[i]->update(w);
			}
			i++;
		}
	}

	void EntityManager::draw(sf::RenderWindow *w)
	{
		for (auto i : EntityManager::m_entities)
		{
			w->draw(*i);
		}
	}
}