cmake_minimum_required(VERSION 3.10)

project(init VERSION 1.0)

add_executable(init main.cpp)

find_package(TBB REQUIRED COMPONENTS tbb)

target_link_libraries(init PRIVATE TBB::tbb)

include(format.cmake)
