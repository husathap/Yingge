#pragma once

#include <functional>
#include <set>
#include "scene.h"
#include "spriteButton.h"
#include "entitymanager.h"

namespace yingge
{
	class Room : public yingge::Scene
	{
		typedef std::pair<yingge::textButton *, std::function<void()>> textButtonEventPair;
		typedef std::pair<yingge::spriteButton *, std::function<void()>> spriteButtonEventPair;

	protected:
		yingge::textButton m_tbSave;
		yingge::textButton m_tbExit;
		void menu();
		
	private:
		std::vector<textButtonEventPair> m_textButtons = std::vector<textButtonEventPair>();
		std::vector<spriteButtonEventPair> m_spriteButtons = std::vector<spriteButtonEventPair>();
		std::set<std::string> m_textButtonRemReqs = std::set<std::string>();
		std::set<std::string> m_spriteButtonRemReqs = std::set<std::string>();

		yingge::EntityManager m_entities = yingge::EntityManager();
		
		bool m_initialized = false;
	public:
		yingge::textButton saveButton;
		yingge::textButton inventoryButton;

		bool update(sf::RenderWindow *w);
		void draw(sf::RenderWindow *w);

		void bindButton(yingge::textButton *t, std::function<void()> f);
		void bindButton(yingge::spriteButton *s, std::function<void()> f);
		void unbindButton(std::string name);

		// Entity manipulation function.
		void addEntity(yingge::Entity *e);
		void removeEntity(std::string key);
		void removeEntity(int ZOrder);
	};
}