#include "GameObject.hpp"
#include <iostream>
#include "../physics/PhysicsEngine.hpp"

using namespace graphics;

GameObject::GameObject(std::string name, std::string s)
    : Sprite(Texture::get(name))
{
    this->name = s;

    attach_collider();
}

GameObject::~GameObject(){
    //TODO: move it to the collider destructor
    physics::PhysicsEngine::remove_collider(m_col);
}




void GameObject::set_lua_bindings(LuaContext& script){
    script.writeFunction("entity_get_name",&GameObject_get_name);
    script.writeFunction("entity_set_position",&GameObject_set_position);
    script.writeFunction("entity_get_scale",&GameObject_get_scale);
    script.writeFunction("entity_set_scale",&GameObject_set_scale);
    script.writeFunction("entity_translate",&GameObject_translate);
    script.writeFunction("entity_get_position",&GameObject_get_position);
    script.writeFunction("entity_set_mass",&GameObject_set_mass);
    script.writeFunction("entity_get_mass",&GameObject_get_mass);
    script.writeFunction("entity_set_trigger",&GameObject_set_trigger);
    script.writeFunction("entity_get_trigger",&GameObject_get_trigger);
}

void GameObject::attach_collider(){
    using namespace physics;
    auto pos = get_position();
    float x = pos.x;
    float y = pos.x;
    
    auto scale = get_scale();
    float w = scale.x;
    float h = scale.y;

    m_col = new BoxCollider2D(x,y,w,h, this);
    m_col->is_trigger = false;
    // m_col->is_trigger = true;
    PhysicsEngine::register_collider(m_col);
}


std::tuple<float, float, float> GameObject_get_position(GameObject* go){
    auto p = go->get_position();
    return std::make_tuple(p.x, p.y, p.z);
}


void GameObject_set_position(GameObject* go, float x, float y, float z){
    go->m_col->set_pos(x,y);
    go->set_position(x, y, z);
}

void GameObject_translate(GameObject* go, float x, float y, float z){
    go->m_col->move(x,y);
    go->translate(x, y, z);
}

std::string GameObject_get_name(GameObject* go){
    return go->name;
}

std::tuple<float, float, float> GameObject_get_scale(GameObject* go){
    auto scale = go->get_scale();
    return std::make_tuple(scale.x, scale.y, scale.z);
}
void GameObject_set_scale(GameObject* go, float x, float y, float z){
    go->m_col->resize(x,y);
    go->scale(x, y, z);
}

void GameObject_set_mass(GameObject* go, float val){
    go->set_mass(val);
}

float GameObject_get_mass(GameObject* go){
    return go->get_mass();
}

void GameObject_set_trigger(GameObject* go, bool val){
    go->get_collider()->is_trigger = true;
}
bool GameObject_get_trigger(GameObject* go){
    return go->get_collider()->is_trigger;
}
