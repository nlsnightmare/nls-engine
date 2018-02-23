#pragma once
#include <string>
#include "LuaContext.hpp"

#include "../graphics/Sprite.hpp"
#include "../physics/BoxCollider2D.hpp"

using namespace graphics;

class GameObject: public Sprite
{
public:
    GameObject(std::string name, std::string s);

    std::string name;

    int get_ID();
    void set_ID(int val);

    void update(float dt);

    void attach_collider();
    static void set_lua_bindings(LuaContext& script);


    friend GameObject* new_gameobject(std::string name, std::string s);
    friend std::string GameObject_get_name(GameObject* go);
    friend void GameObject_set_position(GameObject* go, float x, float y, float z);
    friend void GameObject_translate(GameObject* go, float x, float y, float z);
    friend std::tuple<float, float, float> GameObject_get_position(GameObject* go);
    friend std::tuple<float, float, float> GameObject_get_scale(GameObject* go);
    friend void GameObject_set_scale(GameObject* go, float x, float y, float z);

private:
    physics::BoxCollider2D* m_col;

    int ID;
};


GameObject* new_gameobject(std::string name, std::string s);
std::string GameObject_get_name(GameObject* go);

void GameObject_set_position(GameObject* go, float x, float y, float z);
void GameObject_translate(GameObject* go, float x, float y, float z);
std::tuple<float, float, float> GameObject_get_position(GameObject* go);

std::tuple<float, float, float> GameObject_get_scale(GameObject* go);
void GameObject_set_scale(GameObject* go, float x, float y, float z);
