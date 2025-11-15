#pragma once

#include "dbbe/engine.hpp"

class GameManager
{
public:
    GameManager(Window *Windowobj);
    ~GameManager();
    void key(GLFWwindow *gl_window, int key, int scancode, int action, int mods);
    void mouse(GLFWwindow *gl_window, int button, int action, int mods);

private:
    Window *windowobj;
    int main_shader;

    void render_loop();
};