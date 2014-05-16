#pragma once

#include <SFML/Graphics.hpp>

namespace yingge
{
	/* A class that contains logics which allows an drawable object to be made clickable.
	 * A drawable object can easily be made clickable by making the object class inherit
	 * this class, and call updateClick inside the object's update logic.
	 */
	class Clickable
	{
	private:
		bool m_clicked = false;		// Indicate whether the object is clicked or not.
		bool m_pressed = false;		// Indicate whether the keyboard is down or not.
		bool m_entered = false;		// Indicate whether the cursor has entered the object or not.
	protected:
		bool isClicked();			// Indicate whether the object is clicked or not.
		bool isPressed();			// Indicate whether the keyboard is down or not.
		bool isEntered();			// Indicate whether the cursor has entered the object or not.

		// Update the object to make sure update its click status.
		void updateClick(sf::FloatRect *f, sf::RenderWindow *w);

	public:
		std::string name = "";		// The name of the clickable object.
	};
}