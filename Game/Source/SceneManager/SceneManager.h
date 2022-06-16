#pragma once

#include "Scene.h"

enum class SCENE_STATE 
{
	SCENE_DEFAULT,
	SCENE_START, //Empty scene

	SCENE_GRAPHICS,
	SCENE_PHYSICS,
	SCENE_UI
};

class SceneManager
{
private:
	static SceneManager* scene_instance;
	SceneManager() = default;
	~SceneManager() = default;
public:
	SCENE_STATE state{ SCENE_STATE::SCENE_DEFAULT }; //Initial empty scene
	SCENE_STATE nextState{ SCENE_STATE::SCENE_DEFAULT };
	Scene::IScene* currScene = nullptr;
	
	static SceneManager& GetInstance();
	static void ReleaseInstance();

	void changescene(SCENE_STATE nextScene);
	void update();
	void exit();
};