#include <fstream>
#include <iostream>
#include "GameObject.hpp"

GameObject::GameObject(std::string script)
    : Sprite(Texture::get("container.jpg"))
{
    std::ifstream src_file(script);

    m_lua.writeVariable("go", this);
    m_lua.executeCode("print(2)");
    m_lua.writeVariable("__transform", (Sprite*)this);
    // m_lua.executeCode("go.t = __transform");
    m_lua.registerFunction("rot", &GameObject::rotate);
    m_lua.executeCode(src_file);
    m_updateFunc = m_lua.readVariable<std::function<void(float)>>("update");
}

void GameObject::update(float dt){
    m_updateFunc(dt);
}

void GameObject::test(){
    std::cout << "test" << std::endl;
}
