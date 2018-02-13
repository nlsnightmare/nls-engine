#pragma once
#include "./graphics/Camera.hpp"
#include "./graphics/Sprite.hpp"
#include "./game/GameObject.hpp"

class GameManager
{
public:
    GameManager();
    virtual ~GameManager();

    void loop(float dt);

private:
    GameObject* go;
    graphics::Camera* main_camera;
    graphics::Sprite* player;
};
