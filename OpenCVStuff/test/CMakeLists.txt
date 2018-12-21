cmake_minimum_required(VERSION 3.12)
project(test)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( test ${OpenCV_LIBS} )

add_executable(test main.cpp)