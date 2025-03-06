cmake_minimum_required(VERSION 3.15)

project(main VERSION 1.0)

file(GLOB SHARED_SRC "src/*.cpp")

add_executable(main ${SHARED_SRC})

# include_directories(${PROJECT_SOURCE_DIR}/include)
# target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)

include(cmake/include.cmake)
include(cmake/format.cmake)

