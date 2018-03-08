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
    ~GameObject();

    std::string name;

    inline int get_ID() const { return m_ID; };
    inline void set_ID(int val) { m_ID = val; };
    inline float get_mass() const { return m_mass; };
    inline void set_mass(float val) { m_mass = val; };
    

    void update(float dt);

    void attach_collider();
    inline physics::BoxCollider2D* get_collider() const { return m_col; };
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

    int m_ID;
    float m_mass;
};


GameObject* new_gameobject(std::string name, std::string s);
std::string GameObject_get_name(GameObject* go);

void GameObject_set_position(GameObject* go, float x, float y, float z);
void GameObject_translate(GameObject* go, float x, float y, float z);
std::tuple<float, float, float> GameObject_get_position(GameObject* go);

std::tuple<float, float, float> GameObject_get_scale(GameObject* go);
void GameObject_set_scale(GameObject* go, float x, float y, float z);
void GameObject_set_mass(GameObject* go, float val);
float GameObject_get_mass(GameObject* go);

void GameObject_set_trigger(GameObject* go, bool val);
bool GameObject_get_trigger(GameObject* go);
