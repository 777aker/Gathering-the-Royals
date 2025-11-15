#include "game_manager.hpp"

GameManager::GameManager(Window *windowobj)
{
    this->windowobj = windowobj;
    main_shader = CreateShaderProg("shaders/main.vert", "shaders/main.frag");

    render_loop();
}

GameManager::~GameManager() {}

void GameManager::render_loop()
{
    while (!glfwWindowShouldClose(windowobj->glwindow))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(main_shader);
        int id = glGetUniformLocation(main_shader, "dim");
        glUniform1d(id, dim);
        id = glGetUniformLocation(main_shader, "asp");
        glUniform1d(id, asp);

        int err = glGetError();
        if (err)
        {
            fprintf(stderr, "[%s] %s\n", "display", gluErrorString(err));
        }
        glFlush();
        glfwSwapBuffers(windowobj->glwindow);
        glfwPollEvents();
    }
}

void GameManager::key(GLFWwindow *gl_window, int key, int scancode, int action, int mods)
{
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(gl_window, 1);
        break;
    }
}

void GameManager::mouse(GLFWwindow *gl_window, int button, int action, int mods)
{
}