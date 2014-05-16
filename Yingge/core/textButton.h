#pragma once

#include <SFML/Graphics.hpp>
#include "clickable.h"

namespace yingge
{
	/* A class that represents a button control. This is basically
	 * sf::Text with yingge::Clickable in it. 
	 */
	class textButton : public sf::Text, public yingge::Clickable
	{
	public:
		bool isEnabled = true;		// Indicate whether the button is enabled or not.

		// Update the button. The function returns true if the button is clicked.
		bool update(sf::RenderWindow *w)
		{
			textButton::updateClick(&textButton::getGlobalBounds(), w);

			if (textButton::isEnabled)
			{
				if (textButton::isEntered())
					textButton::setColor(sf::Color(225, 102, 0));
				else
					textButton::setColor(sf::Color::White);

				return textButton::isClicked();
			}
			else
			{
				textButton::setColor(sf::Color(100, 100, 100));
				return false;
			}
		}
	};
}