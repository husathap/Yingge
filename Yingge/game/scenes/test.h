/*#pragma once

#include "../../core/scene.h"
#include <stdlib.h>
#include <functional>
#include "../../core/textButton.h"
#include "../../setting.h"

namespace game {
	namespace scenes {
		// This is a test scene. This scene will have a randomly moving doge.
		class first : public yingge::Scene
		{
		private:
			sf::Texture dogeTexture;
			sf::Color color;
			std::deque<sf::Sprite> dogeSprites;
			std::deque<std::function<void()>> lambs = std::deque<std::function<void()>>();
			yingge::textButton tb;
		public:
			bool update(sf::RenderWindow *w)
			{
				if (tb.update(w))
					yingge::sceneManager->exit();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					return true;
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					yingge::sceneManager->overlayScene(new first());
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
					yingge::sceneManager->replaceScenes(new first());
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					first::lambs.push_front([this]() 
					{
						dogeSprites.push_front(sf::Sprite());
						dogeSprites[0].setTexture(dogeTexture);
						dogeSprites[0].setScale(0.3f, 0.3f);
						dogeSprites[0].setPosition(rand() % 800, rand() % 600);
						dogeSprites[0].setColor(color);
						//yingge::sceneManager->replaceScenes(new first());
					});
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
				{
					if (!first::lambs.empty())
					{
						first::lambs.front()();
						first::lambs.pop_front();
					}
				}

				for (unsigned int i = 0; i < first::dogeSprites.size(); i++)
				{
					sf::Vector2<float> curPos = dogeSprites[i].getPosition();
					if (rand() % 100 >= 50)
					{
						curPos.x += rand() % 10;
						curPos.y += rand() % 10;
					}
					else
					{
						curPos.x -= rand() % 10;
						curPos.y -= rand() % 10;
					}
					dogeSprites[i].setPosition(curPos);
				}
				return false;
			}

			void draw(sf::RenderWindow *w)
			{
				for (unsigned int i = 0; i < first::dogeSprites.size(); i++)
					w->draw(dogeSprites[i]);

				w->draw(tb);
			}

			first()
			{
				dogeTexture = sf::Texture();
				dogeTexture.loadFromFile("resources/doge.jpg");
				dogeSprites = std::deque<sf::Sprite>();
				dogeSprites.push_front(sf::Sprite());
				dogeSprites[0].setTexture(dogeTexture);
				dogeSprites[0].setScale(0.3f, 0.3f);
				dogeSprites[0].setPosition(rand() % 800, rand() % 600);
				first::color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
				dogeSprites[0].setColor(first::color);

				tb = yingge::textButton();
				tb.setFont(*yingge::defaultFont);
				tb.setPosition(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
				tb.setCharacterSize(30);
				tb.setString("Bye!");
			}
		};
	}
}*/