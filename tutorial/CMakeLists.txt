cmake_minimum_required(VERSION 3.12)
project(tutorial)

set(CMAKE_CXX_STANDARD 17)

add_executable(tutorial main.cpp Image.cpp Image.h PPMImage.cpp PPMImage.h)