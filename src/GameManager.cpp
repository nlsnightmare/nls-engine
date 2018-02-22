#include "GameManager.hpp"
#include <fstream>
#include <iostream>
#include "Window.hpp"

std::vector<GameObject *> GameManager::entities;

using namespace graphics;

GameManager::GameManager()
{
    Shader::load_shaders("res/shaders/");
    Texture::load_textures("res/textures/");

    auto main_camera = new Camera(10, 10 * Window::instance->get_aspect_ratio(), Camera::CameraMode::ORTHOGRAPHIC);
    main_camera->make_main();

    initialize_script();
}

void GameManager::loop(float dt){
    using namespace graphics;
    if (Window::get_key_down(GLFW_KEY_ESCAPE)) {
	Window::instance->Close();
    }

    if (update_func)
	update_func(dt);
}


void GameManager::initialize_script(){

    std::ifstream src_code("./scripts/main.lua");
    
    //TODO: maybe move it to GameObject too?
    script.executeCode(
	"function include(file)\n"
	"n_file = './scripts/'..file\n"
	"require(n_file)\n"
	"end\n"
	);
    script.writeFunction("new_entity",&GameManager::add_entity);
    script.writeFunction("__get_key",&Window::get_key_down);

    GameObject::set_lua_bindings(script);
    script.executeCode(src_code);
    update_func = script.readVariable<std::function<void (float)>>("update");
}


GameObject* GameManager::add_entity(std::string name, std::string s){
    GameObject* go = new GameObject(name, s);
    entities.push_back(go);
    return go;
}

GameManager::~GameManager(){
    delete main_camera;
    for (auto it = entities.begin(); it != entities.end(); ++it) {
	delete *it;
    }
    Shader::delete_shaders();
    Texture::delete_textures();
}

