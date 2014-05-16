#include "clickable.h"

/* This file contains the inner coding of Clickable class. To read the
 * documentation of the class, refer to clickable.h.
 */

namespace yingge 
{
	bool Clickable::isEntered()
	{
		return Clickable::m_entered;
	}

	bool Clickable::isPressed()
	{
		return Clickable::m_pressed;
	}

	bool Clickable::isClicked()
	{
		if (Clickable::m_clicked)
		{
			Clickable::m_clicked = false;
			return true;
		}

		return false;
	}

	void Clickable::updateClick(sf::FloatRect *f, sf::RenderWindow *w)
	{
		// Get the current mouse position.
		sf::Vector2i mousePosi = sf::Mouse::getPosition(*w);
		sf::Vector2f mousePos = sf::Vector2f((float)mousePosi.x, (float)mousePosi.y);

		if (f->contains(mousePos))
		{
			// If the cursor is inside the button.

			// If the cursor was previously not inside, switch the text
			// and the entered value.
			if (!Clickable::m_entered)
			{
				Clickable::m_entered = true;
			}

			// Check for clicking. If the mouse key if down, then
			// set pressed to true. Otherwise, check if pressed is
			// true or not. If so, then there is a clicking.
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Clickable::m_pressed = true;
			}
			else
			{
				if (Clickable::m_pressed)
				{
					Clickable::m_clicked = true;
					Clickable::m_pressed = false;
					Clickable::m_entered = false;
				}
			}
		}
		else
		{
			// If the cursor is outside the button.

			// Reset the pressed variable. This makes sure that clicking
			// is only valid while the cursor is inside the button.
			Clickable::m_pressed = false;

			// If the cursor was previously inside, swtich the text
			// and the entered value.
			if (Clickable::m_entered)
			{
				Clickable::m_entered = false;
			}
		}
	}
}