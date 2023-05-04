cmake_minimum_required(VERSION 3.12)
project(Glad)
set(CMAKE_CXX_STANDARD 23)

add_library(glad include/glad/glad.h include/KHR/khrplatform.h src/glad.c)
target_include_directories(glad PUBLIC include/)
