cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

add_executable(main main.cpp apply_foo.cpp)

find_package(TBB REQUIRED COMPONENTS tbb)

target_link_libraries(main PRIVATE TBB::tbb)

include(format.cmake)
