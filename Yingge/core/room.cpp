#include "room.h"
#include "../game/first.h"
#include "io.h"

namespace yingge
{	
	void Room::menu()
	{
		Room::m_tbSave = yingge::textButton();
		Room::m_tbSave.setFont(*yingge::defaultFont);
		Room::m_tbSave.setString("Save");
		Room::m_tbSave.setCharacterSize(28);
		Room::m_tbSave.setPosition(20, SCREEN_HEIGHT - 40);

		Room::m_tbExit = yingge::textButton();
		Room::m_tbExit.setFont(*yingge::defaultFont);
		Room::m_tbExit.setString("Exit");
		Room::m_tbExit.setCharacterSize(28);
		Room::m_tbExit.setPosition(100, SCREEN_HEIGHT - 40);
	}

	void Room::bindButton(yingge::textButton *t, std::function<void()> f)
	{
		// Make sure that there is clickable with the same name.
		for (textButtonEventPair p : Room::m_textButtons)
		{
			if (p.first->name == t->name)
				return;		// TODO: Implement exception system here.
		}

		Room::m_textButtons.push_back(textButtonEventPair(t, f));
	}

	void Room::bindButton(yingge::spriteButton *s, std::function<void()> f)
	{
		// Make sure that there is clickable with the same name.
		for (spriteButtonEventPair p : Room::m_spriteButtons)
		{
			if (p.first->name == s->name)
				return;		// TODO: Implement exception system here.
		}

		Room::m_spriteButtons.push_back(spriteButtonEventPair(s, f));
	}

	void Room::unbindButton(std::string name)
	{
		for (unsigned int i = 0; i != Room::m_textButtons.size(); i++)
		{
			if (Room::m_textButtons[i].first->name == name)
			{
				Room::m_textButtonRemReqs.insert(name);
				break;
			}

		}

		for (unsigned int i = 0; i != Room::m_spriteButtons.size(); i++)
		{
			if (Room::m_spriteButtons[i].first->name == name)
			{
				Room::m_spriteButtonRemReqs.insert(name);
				break;
			}

		}
	}

	bool Room::update(sf::RenderWindow *w)
	{
		if (!Room::m_initialized)
		{
			Room::m_initialized = true;
		}
		else
		{

			// Clear all unwanted clickables before moving on.
			for (std::string s : Room::m_spriteButtonRemReqs)
			{
				for (unsigned int i = 0; i < Room::m_spriteButtons.size(); i++)
				{
					if (s == Room::m_spriteButtons[i].first->name)
					{
						Room::m_spriteButtons.erase(Room::m_spriteButtons.begin() + i);
						i--;
						break;
					}
				}
			}
			Room::m_spriteButtonRemReqs.clear();

			for (std::string s : Room::m_textButtonRemReqs)
			{
				for (unsigned int i = 0; i < Room::m_textButtons.size(); i++)
				{
					if (s == Room::m_textButtons[i].first->name)
					{
						Room::m_textButtons.erase(Room::m_textButtons.begin() + i);
						i--;
						break;
					}
				}
			}
			Room::m_textButtonRemReqs.clear();

			// Now updates.
			for (auto s : Room::m_spriteButtons)
			{
				if (s.first->update(w))
					s.second();
			}

			for (auto t : Room::m_textButtons)
			{
				if (t.first->update(w))
					t.second();
			}

			m_entities.update(w);

			if (m_tbSave.update(w))
			{
				yingge::sceneManager->overlayScene(new yingge::IO(true));
			}

			if (m_tbExit.update(w))
			{
				yingge::sceneManager->replaceScenes(new First());
			}
		}

		return false;
	}

	void Room::draw(sf::RenderWindow *w)
	{
		m_entities.draw(w);
		for (auto s : Room::m_spriteButtons)
			w->draw(*s.first);

		for (auto t : Room::m_textButtons)
			w->draw(*t.first);
		w->draw(m_tbSave);
		w->draw(m_tbExit);
	}

	void Room::addEntity(yingge::Entity *e)
	{
		Room::m_entities.add(e);
	}

	void Room::removeEntity(std::string key)
	{
		Room::m_entities.remove(key);
	}

	void Room::removeEntity(int ZOrder)
	{
		Room::m_entities.remove(ZOrder);
	}
}