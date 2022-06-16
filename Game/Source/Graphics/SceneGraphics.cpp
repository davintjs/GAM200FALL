#include "../Precompiled.h"
#include "SceneGraphics.h"

SceneGraphics::SceneGraphics() = default;

SceneGraphics::~SceneGraphics()
{
    Exit();
}

void SceneGraphics::Init()
{
    std::cout << "Now in SceneGraphics scene" << std::endl;
}

void SceneGraphics::Update()
{
    
}

void SceneGraphics::Render()
{

}

void SceneGraphics::Exit()
{

}