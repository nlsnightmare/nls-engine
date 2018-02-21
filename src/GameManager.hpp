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

    static GameObject* add_entity(std::string name, std::string s);
private:
    LuaContext script;
    static std::vector<GameObject *> entities;

    graphics::Camera* main_camera;

    std::function<void (float)> update_func;
};
