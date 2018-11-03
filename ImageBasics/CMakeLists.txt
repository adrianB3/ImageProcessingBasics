cmake_minimum_required(VERSION 3.12)
project(ImageBasics)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageBasics main.cpp Image.cpp Image.h ImageIO.cpp ImageIO.h)