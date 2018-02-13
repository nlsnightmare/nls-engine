#include "GameManager.hpp"
#include "Window.hpp"
#include <iostream>
#include "./graphics/low_level/Shader.hpp"



using namespace graphics;
GameManager::GameManager(){
    Shader::load_shaders("res/shaders/");
    Texture::load_textures("res/textures/");

    go = new GameObject("test.lua");

    auto main_camera = new Camera(10, 10 * Window::instance->get_aspect_ratio(), Camera::CameraMode::ORTHOGRAPHIC);
    main_camera->make_main();

}

void GameManager::loop(float dt){
    using namespace graphics;
    if (Window::get_key_down(GLFW_KEY_ESCAPE)) {
	Window::instance->Close();
    }


    
    go->update(dt);

}

GameManager::~GameManager(){
    delete main_camera;
    delete player;
    Shader::delete_shaders();
}
