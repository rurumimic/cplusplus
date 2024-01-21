include_directories(..)

file(GLOB SHARED_SRC "*.cpp")

add_executable(builder ${SHARED_SRC})

target_link_libraries(builder game)

