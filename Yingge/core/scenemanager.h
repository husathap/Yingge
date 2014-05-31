#pragma once

#include "scene.h"
#include <deque>


namespace yingge 
{
	/* A container of the scenes that are currently being managed. Notably, this
	 * class uses singleton pattern. In the entire game, only one SceneManager can
	 * be created.
	 */
	class SceneManager 
	{
	private:
		sf::Clock m_clock;				// The clock that the scene uses for updating.
		std::deque<Scene *> m_scenes;	// The data structure that contains the scenes.
		SceneManager();					// The constructor for the scene.

		Scene *m_newScene = nullptr;	// The pointer for the scene to be added.
		bool m_clearScenes = false;		// Indicate whether all scenes should be removed or not.
		bool m_loadMode = false;		// Indicate whether the scene is loading or not.

		static bool m_hasInstance;		// Indicate whether the manager has already been created or not.
	public:
		void update(sf::RenderWindow *w);		// Update the current (top-layer) scene.
		void overlayScene(Scene* newScene);		// Put a new scene on top of the other scenes.
		void replaceScenes(Scene* newScene);	// Remove all scenes and put the new scene into the container.
		void exit();							// Exit the game.
		bool isBusy();							// Indicate whether the game is busy or not.
		static SceneManager *getInstance();		// This class is a singleton, so we use this instead of new.
		void toggleLoadMode();					// Switch on/off the loading mode.
	};
}