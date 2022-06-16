#pragma once

#include "../SceneManager/Scene.h"

class ScenePhysics final : public Scene::IScene
{
public:
    ScenePhysics();
    ~ScenePhysics() override;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Exit() override;
};