#pragma once

#include "scene.h"
#include "textButton.h"
#include <vector>

namespace yingge
{
	class IO : public yingge::Scene
	{
	private:
		std::vector<yingge::textButton *> m_buttons;
		yingge::textButton m_cancelButton;
		sf::Text m_txTitle;
		sf::Text m_txDescription;
		sf::Texture m_txBackground;
		sf::Sprite m_background;

		bool save;
	public:
		bool update(sf::RenderWindow *w);
		void draw(sf::RenderWindow *w);
		void createButtons(bool save);

		IO(bool save);
		~IO();
	};
}