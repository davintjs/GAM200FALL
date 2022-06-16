#pragma once

#include "../SceneManager/Scene.h"

class SceneUI final : public Scene::IScene
{
public:
    SceneUI();
    ~SceneUI() override;

    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Exit() override;
};