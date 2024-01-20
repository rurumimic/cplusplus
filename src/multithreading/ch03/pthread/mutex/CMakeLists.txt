cmake_minimum_required(VERSION 3.10)

project(ch03_pthread_mutex VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_BINARY_DIR})

file(GLOB SHARED_SRC "*.cpp")

add_executable(main ${SHARED_SRC})

