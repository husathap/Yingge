#pragma once

#include <SFML/Graphics.hpp>
#include "clickable.h"

namespace yingge
{
	/* A class that represents a button control. This is basically
	 * sf::Sprite with yingge::Clickable in it.
	 */
	class spriteButton : public sf::Sprite, public yingge::Clickable
	{
	public:
		bool isEnabled = true;		// Indicate whether the button is enabled or not.

		// Update the button. The function returns true if the button is clicked.
		bool update(sf::RenderWindow *w)
		{
			spriteButton::updateClick(&spriteButton::getGlobalBounds(), w);

			if (spriteButton::isEnabled)
			{
				if (spriteButton::isEntered())
					spriteButton::setColor(sf::Color::Yellow);
				else
					spriteButton::setColor(sf::Color::White);

				return spriteButton::isClicked();
			}

			return false;
		}
	};
}