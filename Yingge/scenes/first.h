#pragma once

#include "../core/scene.h"
#include "../scenes/intro.h"
#include <stdlib.h>
#include "../core/textButton.h"
#include "../setting.h"
#include "../global.h"
#include "../core/io.h"
#include "../core/sessionSetup.h"

class First : public yingge::Scene
{
private:
	sf::Texture titleTexture;
	sf::Sprite titleSprite;
	yingge::textButton buttonNewGame;
	yingge::textButton buttonContinue;
	yingge::textButton buttonAbout;
	yingge::textButton buttonExit;
public:
	bool update(sf::RenderWindow *w)
	{
		if (buttonNewGame.update(w))
		{
			delete yingge::session;
			yingge::session = new yingge::Session();
			yingge::setVariables(yingge::session);
			yingge::sceneManager->replaceScenes(new Intro());
		}

		if (buttonContinue.update(w))
		{
			yingge::sceneManager->overlayScene(new yingge::IO(false));
		}

		if (buttonExit.update(w))
		{
			yingge::sceneManager->exit();
		}

		return false;
	}

	void draw(sf::RenderWindow *w)
	{
		w->draw(titleSprite);
		w->draw(buttonNewGame);
		w->draw(buttonContinue);
		w->draw(buttonExit);
	}

	First()
	{
		titleTexture = sf::Texture();
		titleTexture.loadFromFile("resources/textures/title.jpg");
		titleSprite = sf::Sprite();
		titleSprite.setTexture(titleTexture);

		buttonNewGame = yingge::textButton();
		buttonNewGame.setFont(*yingge::defaultFont);
		buttonNewGame.setPosition(300, 410);
		buttonNewGame.setCharacterSize(30);
		buttonNewGame.setString("New Game");

		buttonContinue = yingge::textButton();
		buttonContinue.setFont(*yingge::defaultFont);
		buttonContinue.setPosition(300, 440);
		buttonContinue.setCharacterSize(30);
		buttonContinue.setString("Continue");

		buttonExit = yingge::textButton();
		buttonExit.setFont(*yingge::defaultFont);
		buttonExit.setPosition(300, 470);
		buttonExit.setCharacterSize(30);
		buttonExit.setString("Exit");
	}
};