#pragma once
#include <string>
#include "LuaContext.hpp"

#include "../graphics/Sprite.hpp"

using namespace graphics;

class GameObject: public Sprite
{
public:
    GameObject(std::string name, std::string s);

    int a;
    std::string name;

    void update(float dt);

    static void set_lua_bindings(LuaContext& script);
private:
};


GameObject* new_gameobject(std::string name, std::string s);
std::string GameObject_get_name(GameObject* go);

void GameObject_set_position(GameObject* go, float x, float y, float z);
void GameObject_translate(GameObject* go, float x, float y, float z);
std::tuple<float, float, float> GameObject_get_position(GameObject* go);

std::tuple<float, float, float> GameObject_get_scale(GameObject* go);
void GameObject_set_scale(GameObject* go, float x, float y, float z);
