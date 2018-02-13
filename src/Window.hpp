#pragma once
#include <GLFW/glfw3.h>
#include <functional>

class Window
{
public:
    static Window* instance;
    Window(int width, int height, bool fullscreen, std::string title="");
    virtual ~Window();
    void Close();

    void Update();
    void set_update_function(std::function<void(float)> func);
    inline float get_aspect_ratio() const { return m_aspect_ratio; }
    static bool get_key_down(int keycode);

private:

    GLFWwindow* m_window;
    int m_width, m_height;
    float m_aspect_ratio;

    std::function<void(float)> m_update_function;
};
