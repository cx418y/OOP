cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC "*.cpp")
add_executable(lab3 ${SRC})