#include "GameObject.hpp"

using namespace graphics;

GameObject::GameObject(std::string name, std::string s)
    : Sprite(Texture::get(name))
{
    this->name = s;
}

void GameObject::set_lua_bindings(LuaContext& script){
    script.writeFunction("entity_get_name",&GameObject_get_name);
    script.writeFunction("entity_set_position",&GameObject_set_position);
    script.writeFunction("entity_get_position",&GameObject_get_position);
    script.writeFunction("entity_get_x",&GameObject_get_x);
}

std::tuple<float, float, float> GameObject_get_position(GameObject* go){
    auto p = go->get_position();
    return std::make_tuple(p.x, p.y, p.z);
}


void GameObject_set_position(GameObject* go, float x, float y, float z){
    go->set_position(x, y, z);
}

float GameObject_get_x(GameObject* go){
    auto p = go->get_position();
    return p.x;
}
std::string GameObject_get_name(GameObject* go){
    return go->name;
}
