#include <GL/glew.h>
#include <cstdlib>
#include <iostream>
#include "Window.hpp"
#include <algorithm>
#include <math.h>

Window* Window::instance = nullptr;
std::map<int,bool> Window::m_keycodes_watchlist;

static void resize_callback(GLFWwindow* window, int new_width, int new_height)
{
    // TODO
    // m_height = new_height;
    // glViewport(0, 0, m_width, m_height);
}  

Window::Window(int width,int height, bool fullscreen, std::string title, bool vsync)
    : m_width(width), m_height(height)
{
    // TODO: add error handling
    if (!glfwInit()){
	std::cout << "Error" << std::endl;
	Close();
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (fullscreen) {
	m_window = glfwCreateWindow(m_width, m_height, title.c_str(), glfwGetPrimaryMonitor(), NULL);
    }
    else {
	m_window = glfwCreateWindow(m_width, m_height, title.c_str(), NULL, NULL);
	glfwSetFramebufferSizeCallback(m_window, resize_callback);  
    }

    m_aspect_ratio = (float)m_width / m_height;
    
    if(m_window == nullptr){
	std::cout << "Failed to initialize window" << std::endl;
	Close();
    }

    glViewport(0, 0, m_width, m_height);
    glfwMakeContextCurrent(m_window);
    if (!vsync) 
	glfwSwapInterval(1);
    else
	glfwSwapInterval(0);
	


    // For some reason glewInit return gl error code 1280
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
	Close();
    }
    GLenum err;

    while((err = glGetError()) != GL_NO_ERROR);


    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f,0.2f,0.3f, 1.0f);
    Window::instance = this;
}

Window::~Window(){
    glfwTerminate();
}

void Window::Update(){
    if (!m_update_function) {
	std::cout << "ERROR! Window update function is not set!" << std::endl;
	Close();
    }

    double last_time = glfwGetTime();
    double now = last_time;
    double dt = 0;
    float fps;
    while (!glfwWindowShouldClose(m_window)) {
	now = glfwGetTime();
	dt = now - last_time;
	fps = 1/dt;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	m_update_function(dt);

	glfwSwapBuffers(m_window);


	check_for_keys();
	glfwPollEvents();
	last_time  = now;
    }
}

void Window::set_update_function(std::function<void(float)> func){
    m_update_function = func;
}

void Window::Close(){
    glfwTerminate();
    exit(0);
}

bool Window::get_key(int keycode){
    return glfwGetKey(Window::instance->m_window, keycode);
}

bool Window::get_key_up(int keycode){
    if (m_keycodes_watchlist.find(keycode) != m_keycodes_watchlist.end()) 
	return m_keycodes_watchlist[keycode] && !get_key(keycode);
    
    m_keycodes_watchlist.insert(std::make_pair(keycode,false));
    return false;
}

bool Window::get_key_down(int keycode){
    if (m_keycodes_watchlist.find(keycode) != m_keycodes_watchlist.end()) 
	return !m_keycodes_watchlist[keycode] && get_key(keycode);
    else
	m_keycodes_watchlist.insert(std::make_pair(keycode,false));
    return false;
}

void Window::check_for_keys() {
    for (auto it = m_keycodes_watchlist.begin(); it != m_keycodes_watchlist.end(); ++it){
	it->second = get_key(it->first);
    }

}
