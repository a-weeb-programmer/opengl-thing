cmake_minimum_required(VERSION 3.12)
project(opengl)
file(GLOB_RECURSE sources src/*.cpp src/*.h)
add_executable(opengl-thing ${sources})

target_link_libraries(opengl-thing PRIVATE GL glfw glad)
add_subdirectory(./third-party/glad)
