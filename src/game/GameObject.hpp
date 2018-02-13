#pragma once
#include <string>
#include "LuaContext.hpp"
#include "../graphics/Sprite.hpp"


using namespace graphics;

class GameObject: public Sprite
{
public:
    GameObject(std::string script);

    void test();
    void update(float dt);

private:
    LuaContext m_lua;
    Sprite* m_sprite;
    std::function<void (float)> m_updateFunc;
};

