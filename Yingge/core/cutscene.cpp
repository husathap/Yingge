#include "cutscene.h"
#include "../game/first.h"
#include "../global.h"
#include "wraptext.h"

/* This file contains the logic for Cutscene class. The documentation of each members
 * in the class is in cutscene.h.
 */

namespace yingge 
{
	// These two lines are for static declarations. C++ is annoying.
	sf::Sprite *Cutscene::m_decideSprite = nullptr;
	sf::Texture *Cutscene::m_decideTexture = nullptr;

	bool Cutscene::update(sf::RenderWindow *w)
	{
		// Load stuffs that are required for the game.
		if (Cutscene::m_decideSprite == nullptr)
		{
			Cutscene::m_decideTexture = new sf::Texture();
			Cutscene::m_decideTexture->loadFromFile("resources/textures/decision.jpg");
			Cutscene::m_decideSprite = new sf::Sprite();
			Cutscene::m_decideSprite->setTexture(*Cutscene::m_decideTexture);
		}

		// If there is a decision to be made, the game is paused until a decision is made.
		// Otherwise, keep updating the command.
		if (Cutscene::m_answers.size() > 0)
		{
			bool returnTrue = false;
			// Update each button until a result can be obtained.
			for (unsigned int i = 0; i < Cutscene::m_answers.size(); i++)
			{
				if (Cutscene::m_answers[i]->update(w))
				{
					decision = i;
					returnTrue = true;
				}
			}

			// If a result is obtained then perform memory clean up.
			if (returnTrue)
			{
				for (unsigned int i = 0; i < Cutscene::m_answers.size(); i++)
					delete Cutscene::m_answers[i];

				Cutscene::m_answers = std::vector<yingge::textButton *>();
				return Cutscene::m_commands.empty();
			}

			return false;
		}
		else
		{
			if (Cutscene::m_commands[0]())
			{
				Cutscene::m_commands.pop_front();
			}

			Cutscene::m_entities.update(w);
			Cutscene::updateClick(&m_rect, w);

			return Cutscene::m_commands.empty();
		}
	}

	void Cutscene::draw(sf::RenderWindow *w)
	{
		Cutscene::m_entities.draw(w);

		// Draw the decision.
		if (Cutscene::m_answers.size() > 0)
		{
			w->draw(*Cutscene::m_decideSprite);
			w->draw(Cutscene::m_question);

			for (unsigned int i = 0; i < Cutscene::m_answers.size(); i++)
				w->draw(*Cutscene::m_answers[i]);
		}

		// Draw the text.
		if (Cutscene::m_text.getString() != "")
		{
			w->draw(Cutscene::m_textBackground);
			w->draw(Cutscene::m_text);
		}
	}

	void Cutscene::addEntity(yingge::Entity *e)
	{
		Cutscene::m_commands.push_back([this, e]() 
		{ 
			m_entities.add(e);
			return true;
		});
		
		Cutscene::m_commands.push_back([this]()
		{
			return isClicked();
		});
	}

	void Cutscene::removeEntity(std::string key)
	{
		Cutscene::m_commands.push_back([this, key]()
		{
			m_entities.remove(key);
			return true;
		});
	}

	void Cutscene::removeEntity(int ZOrder)
	{
		Cutscene::m_commands.push_back([this, ZOrder]()
		{
			m_entities.remove(ZOrder);
			return true;
		});
	}

	void Cutscene::playMusic(std::string songPath)
	{
		Cutscene::m_commands.push_back([this, songPath]()
		{
			yingge::defaultMusic->openFromFile(songPath);
			yingge::defaultMusic->setLoop(true);
			yingge::defaultMusic->play();
			return true;
		});
	}

	void Cutscene::pauseMusic()
	{
		Cutscene::m_commands.push_back([this]()
		{
			yingge::defaultMusic->pause();
			return true;
		});
	}

	void Cutscene::resumeMusic()
	{
		Cutscene::m_commands.push_back([this]()
		{
			yingge::defaultMusic->play();
			return true;
		});
	}

	void Cutscene::stopMusic()
	{
		Cutscene::m_commands.push_back([this]()
		{
			yingge::defaultMusic->stop();
			return true;
		});
	}

	void Cutscene::navigate(yingge::Scene *newScene)
	{
		Cutscene::m_commands.push_back([this, newScene]()
		{
			yingge::sceneManager->replaceScenes(newScene);
			return false;
		});
	}

	void Cutscene::navigateFirst()
	{
		Cutscene::m_commands.push_back([this]()
		{
			yingge::sceneManager->replaceScenes(new First());
			return false;
		});
	}

	void Cutscene::decide(std::string que, std::vector<std::string> ans)
	{
		Cutscene::m_commands.push_back([this, que, ans]() {
			m_question = sf::Text();
			m_question.setFont(*yingge::defaultFont);
			m_question.setPosition(180, 20);
			m_question.setCharacterSize(30);
			m_question.setString(wrapText(que, SCREEN_WIDTH - 220, *yingge::defaultFont, 30));
			m_question.setColor(sf::Color(255, 255, 255, 255));

			float y = SCREEN_HEIGHT / 2;
			m_answers = std::vector<yingge::textButton *>();
			for (auto a = ans.begin(); a != ans.end(); a++)
			{
				yingge::textButton *button = new yingge::textButton();
				button->setFont(*yingge::defaultFont);
				button->setPosition(180, y);
				button->setCharacterSize(30);
				button->setString(*a);
				button->setColor(sf::Color(255, 255, 255, 255));
				y += 30;

				m_answers.push_back(button);
			}

			m_decideBackground.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
			m_decideBackground.setFillColor(sf::Color(0, 74, 127, 255));

			return true;
		});

		Cutscene::m_commands.push_back([this]()
		{
			for (unsigned int i = 0; i < m_answers.size(); i++)
				delete m_answers[i];

			return true;
		});

		Cutscene::m_commands.push_back([this]()
		{
			return isClicked();
		});
	}

	void Cutscene::text(std::string s)
	{
		Cutscene::m_commands.push_back([this, s]()
		{
			sf::String cs = wrapText(sf::String(s), SCREEN_WIDTH - 50, *yingge::defaultFont, 20);
			
			m_text.setString(cs);
			m_text.setFont(*yingge::defaultFont);
			m_text.setColor(sf::Color(255, 255, 255, 0));
			m_text.setCharacterSize(20);
			m_text.setPosition(20, 20);

			m_textBackground.setFillColor(sf::Color(100, 100, 100, 0));
			m_textBackground.setSize(sf::Vector2f(SCREEN_WIDTH, m_text.getLocalBounds().height + 50));
			return true;
		});

		Cutscene::m_commands.push_back([this]()
		{
			// Fade in effect.
			int curAlpha = (int)m_textBackground.getFillColor().a;
			curAlpha += 10;

			if (curAlpha < 255)
			{
				m_text.setColor(sf::Color(255, 255, 255, (sf::Uint8)curAlpha));
				m_textBackground.setFillColor(sf::Color(100, 100, 100, (sf::Uint8)curAlpha));
				return false;
			}
			else
			{
				m_text.setColor(sf::Color(255, 255, 255, 255));
				m_textBackground.setFillColor(sf::Color(100, 100, 100, 255));
				return true;
			}

			// Interrupt the fade in if the mouse is clicked.
			if (isClicked())
			{
				m_text.setColor(sf::Color(255, 255, 255, 255));
				m_textBackground.setFillColor(sf::Color(0, 0, 0, 255));
				return true;
			}
		});

		Cutscene::m_commands.push_back([this]()
		{
			if (isClicked())
			{
				m_text = sf::Text();
				return true;
			}

			return false;
		});
	}

	void Cutscene::then(std::function<void()> f)
	{
		Cutscene::m_commands.push_back([this, f]()
		{
			f();
			return true;
		});
	}
}