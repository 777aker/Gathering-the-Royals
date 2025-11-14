#include "dbbe/engine.hpp"
#include "dbbe/colors.hpp"

int main_shader;

void key(GLFWwindow *windowobj, int key, int scancode, int action, int mods) {
    switch(key) {
        case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(windowobj, 1);
    }
}

void mouse(GLFWwindow *window, int button, int action, int mods) {

}

void display_loop(Window *windowobj) {
    while(!glfwWindowShouldClose(windowobj->glwindow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(main_shader);
        int id = glGetUniformLocation(main_shader, "dim");
        glUniform1d(id, dim);
        id = glGetUniformLocation(main_shader, "asp");
        glUniform1d(id, asp);

        int err = glGetError();
        if(err) {
            fprintf(stderr, "[%s] %s\n", "display", gluErrorString(err));
        }
        glFlush();
        glfwSwapBuffers(windowobj->glwindow);
        glfwPollEvents();
    }
}

int main(int argc, char *argv[]) {
    Window mainwindow("Deck Builder Builder", 0, 800, 500, key, mouse);
    // clear color accepts them in a 1.0-0.0 scale so this is the only time we need to do this
    glClearColor((float)midnight_blue.r / 255.0, (float)midnight_blue.g / 255.0, (float)midnight_blue.b / 255.0, 1.0);

    main_shader = CreateShaderProg("shaders/main.vert", "shaders/main.frag");

    display_loop(&mainwindow);
}