cmake_minimum_required(VERSION 2.4)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(nls-engine)

set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0)
# CMAKE_CXX_FLAGS("-std=c++1z -lGL -lglfw -lGLEW -lboost_system -lboost_filesystem -llua5.3")

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(nls-engine ./src/main.cpp)

add_library(nls-engine ./src/GameManager.cpp)
add_library(nls-engine ./src/LuaScript.cpp)
add_library(nls-engine ./src/Window.cpp)

add_executable(nls-engine ./src/game/GameObject.cpp)
add_executable(nls-engine ./src/game/GameObject.hpp)
add_executable(nls-engine ./src/game/LuaContext.hpp)

add_executable(nls-engine ./src/graphics/Camera.cpp)
add_executable(nls-engine ./src/graphics/Sprite.cpp)
add_executable(nls-engine ./src/graphics/SpriteRenderer.cpp)

add_executable(nls-engine ./src/graphics/low_level/ArrayBuffer.cpp)
add_executable(nls-engine ./src/graphics/low_level/IndexBuffer.cpp)
add_executable(nls-engine ./src/graphics/low_level/Shader.cpp)
add_executable(nls-engine ./src/graphics/low_level/Texture.cpp)
add_executable(nls-engine ./src/graphics/low_level/VertexArray.cpp)
add_executable(nls-engine ./src/graphics/low_level/stb_image.cpp)

add_executable(nls-engine ./src/physics/PhysicsEngine.cpp)
add_executable(nls-engine ./src/physics/BoxCollider2D.cpp)
