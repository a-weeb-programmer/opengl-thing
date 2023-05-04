#include <GLFW/glfw3.h>
#include "OpenglThing.hpp"
#include <iostream>

OpenglThing::OpenglThing(bool *running, char *name, int width, int height) {
    this->is_running = running;
    this->window = glfwCreateWindow(width, height, name, nullptr, nullptr);
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
