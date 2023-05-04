#include <iostream>
#include <GLFW/glfw3.h>
#include "OpenglThing.hpp"
#include <unistd.h>

int initialize_glfw_window() {
    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return 1;
}

int main() {
    bool running = true;
    if (initialize_glfw_window() == -1) {
        glfwTerminate();
        return 1;
    }
    auto *thing = new OpenglThing(&running, "a thing i guess", 800, 600);
    while (running) {
        sleep(10);
        thing->stop_program();
    }
    delete thing;
    return 0;
}

