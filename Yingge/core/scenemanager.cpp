#include "scenemanager.h"
#include "../global.h"

/* This file contains the logic for SceneManager class. For the
 * documentation of the class, read scenemanager.h.
 */

namespace yingge 
{
	// Initialize the static value.
	bool SceneManager::m_hasInstance = false;

	SceneManager::SceneManager()
	{
		if (!SceneManager::m_hasInstance)
		{
			SceneManager::m_clock = sf::Clock();
			m_scenes = std::deque<Scene *>();
		}
		else
		{
			_exit(-1);
		}
	}

	void SceneManager::update(sf::RenderWindow *w)
	{
		// Check if there is any scene to be destroyed or not.
		if (SceneManager::m_clearScenes)
		{
			SceneManager::m_clearScenes = false;

			for (unsigned int i = 0; i < SceneManager::m_scenes.size(); i++)
				delete SceneManager::m_scenes[i];

			SceneManager::m_scenes.clear();
		}

		// If there is any element to be attached to the front, then do it!
		if (SceneManager::m_newScene != nullptr)
		{
			SceneManager::m_scenes.push_front(SceneManager::m_newScene);
			SceneManager::m_newScene = nullptr;
		}

		// Update the current (top) scene.
		if (SceneManager::m_clock.getElapsedTime().asMicroseconds() >= 16667)
		{

			SceneManager::m_clock.restart();

			if (!SceneManager::m_scenes.empty())
			{
				// Update the scene and if it is done, pop it out.
				if (SceneManager::m_scenes.front()->update(w))
				{
					Scene *target = SceneManager::m_scenes.front();
					SceneManager::m_scenes.pop_front();
					delete target;
				}
			}
		}

		// Draw the scenes.
		w->clear();

		unsigned int i = SceneManager::m_scenes.size();
		while (i >= 1)
		{
			SceneManager::m_scenes[i - 1]->draw(w);
			i--;
		}

		w->display();
	}

	void SceneManager::overlayScene(Scene *newScene)
	{
		SceneManager::m_newScene = newScene;
	}

	void SceneManager::replaceScenes(Scene *newScene)
	{
		SceneManager::m_newScene = newScene;
		SceneManager::m_clearScenes = true;
	}

	void SceneManager::exit()
	{
		SceneManager::m_newScene = nullptr;
		SceneManager::m_clearScenes = true;
	}

	bool SceneManager::isBusy()
	{
		return !SceneManager::m_scenes.empty();
	}

	SceneManager *SceneManager::getInstance()
	{
		SceneManager* instance = new SceneManager();
		return instance;
	}
}