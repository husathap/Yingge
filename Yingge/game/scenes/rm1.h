#pragma once

#include "../../core/room.h"
#include "../../global.h"
//#include "rm2.h"
#include "../sceneNavigation.h"
#include "../../lang/cs.h"
#include "../../lang/rm.h"

CUTSCENE(Nenshi) 
	$$NO_CONSTRUCT

	MAIN
		TEXT("Hi. My name is Naheed Nenshi, and I would like to thank you for sparing the pingus.")
		TEXT("I can take you to one of the pingus that you have saved.")
		NAVIGATE(rm2)
	xMAIN
xCUTSCENE

ROOM(rm1)
	$SPRITE_BUTTON(sbNenshi)
	$TEXTURE(txNenshi)

	$$CONSTRUCT
		$$TEXTURE(txNenshi, "resources/textures/nenshi.jpg")
		$$SPRITE_BUTTON(sbNenshi, txNenshi, 200, 200)

		BIND_W_EVENT(sbNenshi, Nenshi)
	x$$CONSTRUCT
xROOM

/*class rm1 : public yingge::Room
{
private:
	yingge::spriteButton sbNenshi;
	sf::Texture txNenshi;

	void ToRoom2()
	{
		//yingge::sceneManager->replaceScenes(getScene("rm2"));
		yingge::sceneManager->overlayScene(new Nenshi());
	}
public:
	std::string saveName = "rm1";
	rm1()
	{
		txNenshi = sf::Texture();
		txNenshi.loadFromFile("resources/textures/nenshi.jpg");

		sbNenshi = yingge::spriteButton();
		sbNenshi.setTexture(txNenshi);
		sbNenshi.setPosition(200, 200);

		rm1::bindButton(&sbNenshi, [this](){ ToRoom2(); });
	}
};*/