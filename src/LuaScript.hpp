#pragma once
#include <string>

extern "C"{
#include <lua5.3/lua.h>
#include <lua5.3/lauxlib.h>
#include <lua5.3/lualib.h>
}

class LuaScript
{
public:
    LuaScript(std::string filename);
    ~LuaScript();

    bool execute();

    void set(const std::string& name, float arg);
    void set(const std::string& name, int arg);
    void set(const std::string& name, std::string arg);
    void set(const std::string& name, lua_CFunction arg);


    template<typename T>
    inline T get(const std::string& name);

protected:
    lua_State* m_state;
    void display_error(std::string msg);
    
};

template<>
inline int LuaScript::get(const std::string& name){
    lua_getglobal(m_state, name.c_str());
    if (!lua_isnumber(m_state, -1))
    {
	display_error(std::string( "variable" ) + name + " is not an integer!");
	return 0;
    }

    return (int)lua_tonumber(m_state, -1);
}

template<>
inline float LuaScript::get(const std::string& name){
    lua_getglobal(m_state, name.c_str());
    if (!lua_isnumber(m_state, -1))
    {
	display_error(std::string( "variable" ) + name + " is not an float!");
	return 0;
    }

    return (float)lua_tonumber(m_state, -1);
}

template<>
inline std::string LuaScript::get(const std::string& name){
    lua_getglobal(m_state, name.c_str());
    if (!lua_isstring(m_state, -1))
    {
	display_error(std::string( "variable [" ) + name + "] is not a string!");
	return "";
    }

    return (std::string)lua_tostring(m_state, -1);
}
