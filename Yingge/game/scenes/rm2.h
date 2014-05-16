#pragma once

#include "../../core/room.h"
#include "rm1.h"
#include "../../global.h"

class rm2 : public yingge::Room
{
private:
	yingge::spriteButton sbPingu;
	yingge::spriteButton sbPingu2;
	sf::Texture txPingu;

	void toRoom1()
	{
		yingge::sceneManager->replaceScenes(getScene("rm1"));
	}

	void toRoom2()
	{
		rm2::unbindButton("sbPingu2");
	}
public:
	rm2()
	{
		//rm2::addSpriteButton();
		menu();
		yingge::session->sceneName = "rm2";

		txPingu = sf::Texture();
		txPingu.loadFromFile("resources/pingu.jpg");
		
		sbPingu.setTexture(txPingu);
		sbPingu.setPosition(300, 300);
		rm2::bindButton(&sbPingu, [this](){ toRoom1(); });

		sbPingu2.setTexture(txPingu);
		sbPingu2.setPosition(400, 300);
		sbPingu2.name = "sbPingu2";
		rm2::bindButton(&sbPingu2, [this](){ toRoom2(); });
	}
};