#include "io.h"
#include "../global.h"
#include "../setting.h"
#include "jsoncons/json.hpp"
#include "../core/sceneNavigation.h"
#include <fstream>
#include <ctime>
#include <time.h>

namespace yingge
{
	bool IO::update(sf::RenderWindow *w)
	{
		for (unsigned int i = 0; i < IO::m_buttons.size(); i++)
		{
			if (IO::m_buttons[i]->update(w))
			{
				if (IO::save)
				{
					// Creating the time stamp node.
					std::time_t currentTime = std::time_t();
					std::tm convertedTime = tm();
					char buffer[256];

					std::time(&currentTime);

					localtime_s(&convertedTime, &currentTime);
					asctime_s(buffer, &convertedTime);

					for (unsigned int j = 0; j < 256; j++)
					{
						if (buffer[j] == '\n')
						{
							buffer[j] = '\0';
							break;
						}
					}

					jsoncons::json log;
					log["date_time"] = std::string(buffer);
					log["scene_name"] = yingge::session->sceneName;

					jsoncons::json bools;
					for (auto b : yingge::session->booleans)
						bools[b.first.c_str()] = b.second;

					jsoncons::json numbers;
					for (auto n : yingge::session->numbers)
						numbers[n.first.c_str()] = n.second;

					jsoncons::json strings;
					for (auto s : yingge::session->strings)
						strings[s.first.c_str()] = s.second.c_str();

					log["booleans"] = bools;
					log["numbers"] = numbers;
					log["strings"] = strings;

					std::ofstream str;

					str.open("logs/" + std::to_string(i) + ".json", std::ios::trunc);
					str << log.to_string();
					str.close();

					jsoncons::json man = jsoncons::json::parse_file("logs/manifest.json");
					std::vector<std::string> vecMan = man["logs"].as<std::vector<std::string>>();
					vecMan[i] = std::string(buffer);
					man["logs"] = vecMan;

					str.open("logs/manifest.json", std::ios::trunc);
					str << man.to_string();
					str.close();

					IO::createButtons(IO::save);
				}
				else
				{
					jsoncons::json log = jsoncons::json::parse_file("logs/" + std::to_string(i) + ".json");

					delete yingge::session;
					yingge::session = new yingge::Session();

					jsoncons::json bools = log["booleans"];
					for (auto b = bools.begin_members(); b != bools.end_members(); ++b)
					{
						yingge::session->booleans.insert(std::pair<std::string, bool>(b->name(), b->value().as<bool>()));
					}

					jsoncons::json numbers = log["numbers"];
					for (auto n = numbers.begin_members(); n != numbers.end_members(); ++n)
					{
						yingge::session->numbers.insert(std::pair<std::string, double>(n->name(), n->value().as<double>()));
					}

					jsoncons::json strings = log["strings"];
					for (auto s = numbers.begin_members(); s != numbers.end_members(); ++s)
					{
						yingge::session->strings.insert(std::pair<std::string, std::string>(s->name(), s->value().as<std::string>()));
					}

					yingge::sceneManager->replaceScenes(getScene(log["scene_name"].as<std::string>()));
					return true;
				}
			}
		}

		return IO::m_cancelButton.update(w);
	}

	void IO::draw(sf::RenderWindow *w)
	{
		w->draw(IO::m_background);
		w->draw(IO::m_txTitle);
		w->draw(IO::m_txDescription);

		for (auto b : IO::m_buttons)
			w->draw(*b);
		
		w->draw(IO::m_cancelButton);
	}

	IO::IO(bool save)
	{
		IO::save = save;

			
		// Load the texture.
		IO::m_txBackground = sf::Texture();
		IO::m_txBackground.loadFromFile("resources/textures/IO.png");
		IO::m_background = sf::Sprite();
		IO::m_background.setTexture(IO::m_txBackground);

		IO::m_buttons = std::vector<yingge::textButton *>();
		
		IO::m_cancelButton = yingge::textButton();
		IO::m_cancelButton.setCharacterSize(30);
		IO::m_cancelButton.setFont(*yingge::defaultFont);
		IO::m_cancelButton.setPosition(138, 500);
		IO::m_cancelButton.setString("Cancel");

		IO::m_txTitle = sf::Text();
		IO::m_txTitle.setCharacterSize(50);
		IO::m_txTitle.setFont(*yingge::defaultFont);
		IO::m_txTitle.setPosition(138, 0);
		if (save)
			IO::m_txTitle.setString("Save");
		else
			IO::m_txTitle.setString("Load");

		IO::m_txDescription = sf::Text();
		IO::m_txDescription.setCharacterSize(20);
		IO::m_txDescription.setFont(*yingge::defaultFont);
		IO::m_txDescription.setPosition(138, 70);
		if (save)
			IO::m_txDescription.setString("Saving on any non-empty log will overwrite it!");

		IO::createButtons(save);
	}

	void IO::createButtons(bool save)
	{
		// Clear all of the buttons if it can be done.
		if (IO::m_buttons.size() > 0)
		{
			for (unsigned int i = 0; i < IO::m_buttons.size(); i++)
				delete IO::m_buttons[i];

			IO::m_buttons.clear();
		}

		// Load the manifest.
		jsoncons::json jsonMan = jsoncons::json::parse_file("logs/manifest.json");
		std::vector<std::string> manData = std::vector<std::string>();

		for (auto m = jsonMan["logs"].begin_elements(); m != jsonMan["logs"].end_elements(); ++m)
			manData.push_back(m->as<std::string>());

		// Create the buttons.
		for (int i = 0; i < 5; i++)
		{
			yingge::textButton *tb = new yingge::textButton();
			tb->setCharacterSize(30);
			tb->setFont(*yingge::defaultFont);
			tb->setPosition(138, SCREEN_HEIGHT / 2 + (float)i * 30);

			if (manData[i] != "")
				tb->setString("Log #" + std::to_string(i + 1) + ": " + manData[i]);
			else
			{
				tb->setString("Log #" + std::to_string(i + 1) + ": Empty");
				if (!save)
					tb->isEnabled = false;
			}

			IO::m_buttons.push_back(tb);
		}
	}

	IO::~IO()
	{
		// Destroy all the buttons!
		for (unsigned int i = 0; i < IO::m_buttons.size(); i++)
		{
			delete IO::m_buttons[i];
		}
	}
}