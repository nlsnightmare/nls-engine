#include "GameManager.hpp"
#include <fstream>
#include <iostream>
#include "Window.hpp"
#include "Log.hpp"

std::vector<GameObject *> GameManager::entities;
std::vector<int> GameManager::entities_for_deletion;

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
    if (update_func)
	update_func(dt);



    remove_entities();
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

    script.writeFunction("log",&logging::log);
    script.writeFunction("new_entity",&GameManager::add_entity);
    script.writeFunction("entity_get_id",&GameManager::get_entity_index);
    script.writeFunction("__get_key",&Window::get_key);
    script.writeFunction("__get_key_down",&Window::get_key_down);
    script.writeFunction("entity_delete",&GameManager::add_entity_to_removal_queue);

    GameObject::set_lua_bindings(script);
    script.executeCode(src_code);
    update_func = script.readVariable<std::function<void (float)>>("update");
}


GameObject* GameManager::add_entity(std::string name, std::string s){
    GameObject* go = new GameObject(name, s);
    int id = entities.size();
    entities.push_back(go);
    go->set_ID(id);
    return go;
}

int GameManager::get_entity_index(GameObject* ptr){
    for (auto i = 0; i < entities.size(); ++i) {
	if (entities[i] == ptr)
	    return i;
    }
    return -1;
}

void GameManager::add_entity_to_removal_queue(GameObject* go){
    log_message("Adding an entity for deletion!");
    int i = get_entity_index(go);
    if (i != -1) {
	entities_for_deletion.push_back(i);
    }
}

void GameManager::remove_entities(){
    if (entities_for_deletion.size() > 0) {
	log_message("removing " + std::to_string(entities_for_deletion.size()));
    }
    //FIXME: this deletes all entities, which it shouldn't do
    for(auto i : entities_for_deletion){
	GameObject* go = entities.at(i);
	delete go;
	entities.erase(entities.begin() + i);
    }
    entities_for_deletion.clear();
}


//TODO maybe use the CollisionData struct?
void GameManager::trigger_event(GameObject* src, GameObject* dst, float x, float y){
    log_message("trigger entered!!!");
    int srcID = src->get_ID();
    int dstID = dst->get_ID();
    script.writeVariable("__temp0",std::unordered_map<std::string, float>{
	    {"x", x},
	    {"y", y}
	});

    script.writeVariable("__srcid", srcID);
    script.writeVariable("__dstid", dstID);
    script.executeCode(
	"__src_e = find_entity(__srcid);"
	"__dst_e = find_entity(__dstid);"
	"safe_call(__src_e,'on_trigger',__dst_e,__temp0)"
	);
}

//TODO maybe use the CollisionData struct?
//FIXME: this should be moved to physics engine
void GameManager::collision_event(GameObject* src, GameObject* dst, float x, float y){
    int srcID = src->get_ID();
    int dstID = dst->get_ID();
    script.writeVariable("__temp0",std::unordered_map<std::string, float>{
	    {"x", x},
	    {"y", y}
	});

    script.writeVariable("__srcid", srcID);
    script.writeVariable("__dstid", dstID);
    script.executeCode(
	"__src_e = find_entity(__srcid);"
	"__dst_e = find_entity(__dstid);"
	"safe_call(__src_e,'on_collision',__dst_e,__temp0)"
	);
}

GameManager::~GameManager(){
    for (auto it = entities.begin(); it != entities.end(); ++it) {
	delete *it;
    }
    Shader::delete_shaders();
    Texture::delete_textures();

    // delete main_camera;
}

