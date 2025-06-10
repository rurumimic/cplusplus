cmake_minimum_required(VERSION 3.21)
project(add)

set(CMAKE_CXX_STANDARD 20)

add_executable(add src/main.cpp)

include(cmake/format.cmake)
