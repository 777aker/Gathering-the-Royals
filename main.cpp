#include "dbbe/engine.hpp"
#include "dbbe/colors.hpp"

#include "ui/button.hpp"

#include "game_manager.hpp"

#include <vector>

void key(GLFWwindow *gl_window, int key, int scancode, int action, int mods)
{
    GameManager *gm = (GameManager *)glfwGetWindowUserPointer(gl_window);
    gm->key(gl_window, key, scancode, action, mods);
}

void mouse(GLFWwindow *gl_window, int button, int action, int mods)
{
    GameManager *gm = (GameManager *)glfwGetWindowUserPointer(gl_window);
    gm->mouse(gl_window, button, action, mods);
}

int main(int argc, char *argv[])
{
    Window mainwindow("Deck Builder Builder", 0, 1200, 900, key, mouse);
    // clear color accepts them in a 1.0-0.0 scale so this is the only time we need to do this
    glClearColor((float)midnight_blue.r / 255.0, (float)midnight_blue.g / 255.0, (float)midnight_blue.b / 255.0, 1.0);

    GameManager gm(&mainwindow);
    glfwSetWindowUserPointer(mainwindow.glwindow, &gm);
}