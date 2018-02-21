#include "LuaScript.hpp"
#include <iostream>

LuaScript::LuaScript(std::string filename){
    m_state = luaL_newstate();
    luaL_openlibs(m_state);
    bool error = luaL_loadfilex(m_state, filename.c_str(), NULL);

    if (error) {
	std::cout << "error loading file " << filename << std::endl;
	std::cout << lua_tostring(m_state, -1) << std::endl;
    }


}

bool LuaScript::execute(){
    if (!m_state) return false;

    return lua_pcall(m_state, 0, 0, 0);
}



LuaScript::~LuaScript(){
    if (m_state) {
	lua_close(m_state);
    }
}

    
void LuaScript::set(const std::string& name, float arg){
    lua_pushnumber(m_state, arg);
    lua_setglobal(m_state, name.c_str());
}

void LuaScript::set(const std::string& name, int arg){
    lua_pushnumber(m_state, arg);
    lua_setglobal(m_state, name.c_str());
}
void LuaScript::set(const std::string& name, std::string s){
    lua_pushstring(m_state, s.c_str());
    lua_setglobal(m_state, name.c_str());
}

void LuaScript::set(const std::string& name, lua_CFunction arg){
    lua_pushcfunction(m_state, arg);
    lua_setglobal(m_state, name.c_str());
}


void LuaScript::display_error(std::string msg){
    std::cout << "Lua Error!" << std::endl;
    std::cout << msg << std::endl;
}
