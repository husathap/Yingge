#pragma once

#include "scene.h"
#include <functional>
#include <deque>
#include <list>
#include "entitymanager.h"
#include "clickable.h"
#include "../setting.h"

namespace yingge {

	/* Cutscene is used to make a new cutscene for the game. Derive a class to make
	 * a dialogue between characters or PowerPoint-like static cutscenes.
	 */
	class Cutscene : public yingge::Scene, public yingge::Clickable
	{
	protected:
		yingge::EntityManager m_entities;
		std::deque<std::function<bool()>> m_commands;
		sf::FloatRect m_rect = sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		// Variables for making decision.
		sf::Text m_question;
		std::vector<yingge::textButton *> m_answers = std::vector<yingge::textButton *>();
		sf::RectangleShape m_decideBackground = sf::RectangleShape();
		static sf::Sprite *m_decideSprite;
		static sf::Texture *m_decideTexture;

		// Variables for having a text.
		sf::Text m_text = sf::Text();
		sf::RectangleShape m_textBackground = sf::RectangleShape();
	public:
		bool update(sf::RenderWindow *w);
		void draw(sf::RenderWindow *w);

		// Entity manipulation function.
		void addEntity(yingge::Entity *e);
		void removeEntity(std::string key);
		void removeEntity(int ZOrder);

		// The text manipulation function.
		void text(std::string s);

		// Decision manipulation function.
		void decide(std::string que, std::vector<std::string> ans);
		unsigned int decision;
		void then(std::function<void()> f);

		// Music manipulation function.
		void playMusic(std::string songPath);
		void pauseMusic();
		void resumeMusic();
		void stopMusic();

		void navigate(yingge::Scene *newScene);
		void navigateFirst();
	};
}