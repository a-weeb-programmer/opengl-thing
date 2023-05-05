#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenglThing.hpp"
#include <iostream>
#include <string>

OpenglThing *OpenglThing::instance_ptr = nullptr;

OpenglThing::OpenglThing(bool *running, std::string name, int width, int height) {
    if (instance_ptr != nullptr) {
        std::cerr << "Not creating new object with type: \"OpenglThing\", reason: instance already created" << std::endl;
        return;
    }
    GLFWwindow *window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "glfw window pointer is null after attempting to create, terminating program" << std::endl;
        *running = false;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    if (!this->setup_glad()) {
        std::cerr << "Failed to set up opengl context";
        window = nullptr;
        return;
    }
    this->is_running = running;
    this->window = window;
    instance_ptr = this;
}
OpenglThing::~OpenglThing() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
void OpenglThing::stop_program() {
    *is_running = false;
}

GLFWwindow *OpenglThing::get_window() {
    return window;
}

int OpenglThing::setup_glad() {
    if (!gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return 0;
    }
    return 1;
}
