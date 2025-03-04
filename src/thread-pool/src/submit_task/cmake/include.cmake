# Option: Stop upward search when reaching a directory with this name.
set(STOP_DIR_NAME "thread-pool" CACHE STRING "Stop upward search when reaching this directory name")

if(STOP_DIR_NAME)
    message(STATUS "Search will stop when reaching a directory named '${STOP_DIR_NAME}'.")
endif()

# Check if the include directory has already been cached.
if(NOT DEFINED CACHED_INCLUDE_DIR)
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

    # Cache the found include directory.
    set(CACHED_INCLUDE_DIR "${INCLUDE_DIR_FOUND}" CACHE PATH "Cached include directory path")
else()
    message(STATUS "Using cached 'include' directory: ${CACHED_INCLUDE_DIR}")
endif()

# Add the cached include directory to the project.
include_directories(${CACHED_INCLUDE_DIR})

