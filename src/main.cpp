#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "OpenglThing.hpp"
#include <unistd.h>

int initialize_glfw() {
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
    if (initialize_glfw() == -1) {
        std::cerr << "Failed to initialize glfw" << std::endl;
        glfwTerminate();
        return 1;
    }
    if ((new OpenglThing(&running, "a thing i guess", 800, 600)) == nullptr) {
        std::cerr << "Failed to create OpenglThing instance object";
    }
    while (running) {
        sleep(10);
        OpenglThing::instance_ptr->stop_program();
    }
    delete OpenglThing::instance_ptr;
    return 0;
}

