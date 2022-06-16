//Starting scene of the application
//Add keys for different scenes here

#include "../Precompiled.h"
#include "SceneStart.h"
#include "../Graphics/glhelper.h"
#include "../SceneManager/SceneManager.h"

SceneStart::SceneStart() = default;

GLboolean keystateGLast = GL_FALSE;
GLboolean keystatePLast = GL_FALSE;
GLboolean keystateULast = GL_FALSE;

SceneStart::~SceneStart()
{
    Exit();
}

void SceneStart::Init()
{
    std::cout << "Starting from SceneStart scene" << std::endl;
}

void SceneStart::Update()
{
    if (GLHelper::keystateG && keystateGLast != GLHelper::keystateG)
    {
        SceneManager::GetInstance().changescene(SCENE_STATE::SCENE_GRAPHICS);
    }

    if (GLHelper::keystateP && keystatePLast != GLHelper::keystateP)
    {
        SceneManager::GetInstance().changescene(SCENE_STATE::SCENE_PHYSICS);
    }
    
    if (GLHelper::keystateU && keystateULast != GLHelper::keystateU)
    {
        SceneManager::GetInstance().changescene(SCENE_STATE::SCENE_UI);
    }

    keystateGLast = GLHelper::keystateG;
    keystatePLast = GLHelper::keystateP;
    keystateULast = GLHelper::keystateU;

    SceneManager::GetInstance().update();
}

void SceneStart::Render()
{

}

void SceneStart::Exit()
{

}