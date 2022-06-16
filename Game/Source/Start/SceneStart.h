#pragma once

#include "../SceneManager/Scene.h"

class SceneStart final : public Scene::IScene
{
public:
    SceneStart();
    ~SceneStart() override;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Exit() override;
};