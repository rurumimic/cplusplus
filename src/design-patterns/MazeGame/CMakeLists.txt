cmake_minimum_required(VERSION 3.10)

project(Patterns VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config.h.in config.h)

include_directories(${PROJECT_BINARY_DIR})

file(GLOB SHARED_SRC "*.cpp")

add_executable(${PROJECT_NAME} ${SHARED_SRC})

add_library(game SHARED ${SHARED_SRC})

add_subdirectory(AbstractFactory)

