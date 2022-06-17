#include "../Precompiled.h"
#include "SceneManager.h"

#include "../Graphics/SceneGraphics.h"
#include "../Physics/ScenePhysics.h"
#include "../UI/SceneUI.h"
#include "../Start/SceneStart.h"

SceneManager* SceneManager::scene_instance = nullptr;

SceneManager& SceneManager::GetInstance()
{
	if (scene_instance == nullptr)
	{
		scene_instance = new SceneManager();
	}
	return *scene_instance;
}

void SceneManager::ReleaseInstance()
{
	delete scene_instance->currScene;
	delete scene_instance;
	scene_instance = nullptr;
}

void SceneManager::changescene(const SCENE_STATE nextScene)
{
	nextState = nextScene;
	if (currScene == nullptr)
	{
		update();
	}
}

void SceneManager::update()
{
	if (nextState == SCENE_STATE::SCENE_DEFAULT)
	{
		return;
	}

	if (nextState == state)
	{
		state = nextState;
		nextState = SCENE_STATE::SCENE_DEFAULT;
		delete currScene;

		switch (state)
		{
		case SCENE_STATE::SCENE_START:
			currScene = new SceneStart();
			break;
		case SCENE_STATE::SCENE_GRAPHICS:
			currScene = new SceneGraphics();
			break;
		case SCENE_STATE::SCENE_PHYSICS:
			currScene = new ScenePhysics();
			break;
		case SCENE_STATE::SCENE_UI:
			currScene = new SceneUI();
			break;
		default:
			break;
		}
		currScene->Init();
	}
	else if (state != nextState)
	{
        state = nextState;
        nextState = SCENE_STATE::SCENE_DEFAULT;
        delete currScene;

        switch (state)
        {
		case SCENE_STATE::SCENE_START:
			currScene = new SceneStart();
			break;
		case SCENE_STATE::SCENE_GRAPHICS:
			currScene = new SceneGraphics();
			break;
		case SCENE_STATE::SCENE_PHYSICS:
			currScene = new ScenePhysics();
			break;
		case SCENE_STATE::SCENE_UI:
			currScene = new SceneUI();
			break;
		default:
			break;
        }
        currScene->Init();
	}
}

void SceneManager::exit()
{
	delete currScene;
}