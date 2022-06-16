#pragma once

namespace Scene
{
    class IScene
    {
    public:
        virtual ~IScene() = default;

        virtual void Init() = 0;

        virtual void Update() = 0;

        virtual void Render() = 0;

        virtual void Exit() = 0;
    };
}