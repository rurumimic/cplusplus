cmake_minimum_required(VERSION 3.10)

project(Patterns VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(config.h.in config.h)

file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

