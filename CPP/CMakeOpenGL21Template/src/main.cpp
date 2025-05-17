#include <iostream>
#include "glad/gl.h"
#include "glad/glx.h"
#include <GLFW/glfw3.h>

int main() {
    int code;
    GLFWerrorfun callback;

    GLFWwindow* window;

    if (glfwInit() == false) {
        const char* description;
        code = glfwGetError(&description);
        std::cout << "GLFW Not Initialized: Error Code '" << code << "'" << description << std::endl;
        glfwTerminate();
        return -1;
    };
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL) {
        const char* description;
        code = glfwGetError(&description);
        std::cout << "GLFW Window Not Initialized! Error Code '" << code << "' " << description << std::endl;
        glfwTerminate();
        return -2;
    }
    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to Initialize OpenGL context: version is '" << version << "'" << std::endl;
        glfwTerminate();
        return -3;
    }

    glViewport(0, 0, 800, 600);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}