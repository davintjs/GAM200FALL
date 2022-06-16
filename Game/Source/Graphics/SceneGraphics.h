#pragma once

#include "../SceneManager/Scene.h"

class SceneGraphics final : public Scene::IScene
{
public:
    SceneGraphics();
    ~SceneGraphics() override;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Exit() override;
};