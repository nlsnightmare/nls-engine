#pragma once
#include "./graphics/Camera.hpp"
#include "./game/LuaContext.hpp"
#include "./game/GameObject.hpp"

class GameManager
{
public:
    GameManager();
    virtual ~GameManager();

    void initialize_script();

    void loop(float dt);

    void collision_event(GameObject* src, GameObject* dst, float x, float y);
    void trigger_event(GameObject* src, GameObject* dst, float x, float y);
    static GameObject* add_entity(std::string name, std::string s);
    static int get_entity_index(GameObject* go);
private:
    LuaContext script;
    static std::vector<GameObject *> entities;
	static std::vector<int> entities_for_deletion;
	static void add_entity_to_removal_queue(GameObject* go);
    static void remove_entities();

    graphics::Camera* main_camera;
    std::function<void (float)> update_func;
};
