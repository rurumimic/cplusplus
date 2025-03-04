# Option: Stop upward search when reaching a directory with this name.
# You can set this variable from the command line or in your top-level CMakeLists.txt.
set(STOP_DIR_NAME "thread-pool" CACHE STRING "Stop upward search when reaching this directory name")

# Inform the user that the search will stop at the specified directory name if set.
if(STOP_DIR_NAME)
    message(STATUS "Search will stop when reaching a directory named '${STOP_DIR_NAME}'.")
endif()

# Set the starting directory to PROJECT_SOURCE_DIR.
set(START_DIR ${PROJECT_SOURCE_DIR})
# Set the maximum search depth.
set(MAX_LEVELS 10)
set(CURRENT_LEVEL 0)
set(INCLUDE_DIR_FOUND "")

# Search upward for the "include" folder up to MAX_LEVELS levels.
while(CURRENT_LEVEL LESS MAX_LEVELS)
    message(STATUS "Searching for 'include' directory in: ${START_DIR}")

    if(EXISTS "${START_DIR}/include")
        set(INCLUDE_DIR_FOUND "${START_DIR}/include")
        message(STATUS "Found 'include' directory: ${INCLUDE_DIR_FOUND}")
        break()
    endif()

    # If STOP_DIR_NAME is set, check if the current directory name matches it.
    if(STOP_DIR_NAME)
        get_filename_component(CURRENT_DIR_NAME ${START_DIR} NAME)
        if(CURRENT_DIR_NAME STREQUAL STOP_DIR_NAME)
            message(STATUS "Reached stop directory '${STOP_DIR_NAME}'. Stopping search.")
            break()
        endif()
    endif()

    # Move to the parent directory.
    get_filename_component(START_DIR "${START_DIR}" DIRECTORY)
    math(EXPR CURRENT_LEVEL "${CURRENT_LEVEL} + 1")
endwhile()

# If the "include" folder is not found, display an error message.
if(NOT INCLUDE_DIR_FOUND)
    message(FATAL_ERROR "Could not find the 'include' directory in any parent directories.")
endif()

# Add the found include directory to the project.
include_directories(${INCLUDE_DIR_FOUND})

