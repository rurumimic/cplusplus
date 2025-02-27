cmake_minimum_required(VERSION 3.15)

project(main VERSION 1.0)

file(GLOB SHARED_SRC "src/*.cpp")

add_executable(main ${SHARED_SRC})

find_package(TBB REQUIRED COMPONENTS tbb)

target_link_libraries(main PRIVATE TBB::tbb)

include(format.cmake)
