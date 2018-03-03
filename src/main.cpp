#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Log.hpp"
#include "Window.hpp"
#include "GameManager.hpp"
#include "./physics/PhysicsEngine.hpp"

#include "./graphics/SpriteRenderer.hpp"
#include "./graphics/low_level/stb_image.h"
#include "./graphics/low_level/Shader.hpp"



int main(int argc, char *argv[]) 
{
    stbi_set_flip_vertically_on_load(true);
    logging::init();
    log_message("test");

    log_error("test");

    LuaContext lc;
    std::ifstream settings("settings.dat");
    lc.executeCode(settings);
    bool fs = lc.readVariable<bool>("fullscreen");
    int width = lc.readVariable<int>("width");
    int height = lc.readVariable<int>("height");
    Window main_window(width, height, fs, "Nls-Engine");
    GameManager gm;
    physics::PhysicsEngine pe;
    pe.set_trigger([&gm](GameObject* p1, GameObject* p2,float x, float y) mutable {
	    gm.trigger_event(p1,p2,x,y);
	});
    pe.set_collision([&gm](GameObject* p1, GameObject* p2,float x, float y) mutable {
	    gm.collision_event(p1,p2,x,y);
	});

    main_window.set_update_function([&](float dt) mutable {
	    graphics::SpriteRenderer::Render();
	    pe.tick(dt);

	    gm.loop(dt);
	});
    
    main_window.Update();
    
    return 0;
}

