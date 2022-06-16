#include "Precompiled.h"

#include "SceneManager/SceneManager.h"
#include "Graphics\glhelper.h"

static void draw();
static void update();
static void init();
static void cleanup();

int main() {
  init();

  while (!glfwWindowShouldClose(GLHelper::ptr_window)) {

    update();

    draw();
  }
  cleanup();
}


static void update() {
  glfwPollEvents(); //For processing input events in event queue

  GLHelper::update_time(1.0); //Update fps

  SceneManager::GetInstance().currScene->Update();
  SceneManager::GetInstance().currScene->Render();
  
  //GLApp::update(); //Update objects (Frame buffer, depth buffer objects etc...)
}


static void draw() {
  //GLApp::draw(); //Render objects one after another into the back buffer

  glfwSwapBuffers(GLHelper::ptr_window);
}


static void init() {
  if (!GLHelper::init(2400, 1350, "GAM200 Game")) {
    std::cout << "Unable to create Game window" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  SceneManager::GetInstance().changescene(SCENE_STATE::SCENE_START);
  //GLApp::init();
}

static void cleanup() {}