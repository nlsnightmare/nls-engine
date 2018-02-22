#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.hpp"
#include "GameManager.hpp"

#include "./graphics/SpriteRenderer.hpp"
#include "./graphics/low_level/stb_image.h"
#include "./graphics/low_level/Shader.hpp"



int main(int argc, char *argv[]) 
{
    stbi_set_flip_vertically_on_load(true);

    LuaContext lc;
    std::ifstream settings("settings.dat");
    lc.executeCode(settings);
    bool fs = lc.readVariable<bool>("fullscreen");
    int width = lc.readVariable<int>("width");
    int height = lc.readVariable<int>("height");
    Window main_window(width, height, fs, "Nls-Engine");
    GameManager gm;
    // Window main_window(1600, 900, true, "test");
    main_window.set_update_function([&](float dt) mutable {
	    graphics::SpriteRenderer::Render();
	    gm.loop(dt);
	});
    
    main_window.Update();
    
    return 0;
}

