cmake_minimum_required(VERSION 2.8.11)

# Turn it ON: -Dtest=ON
option(test "Include Tests." OFF)

set(PROJECT_NAME yarenderer)
project(${PROJECT_NAME} C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(BUILD_SHARED_LIBS ON)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
    message(STATUS "Please use a different C++ compiler.")
endif()


#     --    dependencies

add_subdirectory(lib/)
set(INCLUDES
    ${yahtml-parser_INCLUDES}
    ${yacss-parser_INCLUDES}
    ${yahttp-parser_INCLUDES}
    ${PROJECT_SOURCE_DIR}/includes
)

#     --    source

add_subdirectory(src/)


#     --    global variables

set(${PROJECT_NAME}_INCLUDES ${INCLUDES}
    CACHE INTERNAL
    "${PROJECT_NAME}: Include Directories"
    FORCE
)

set(${PROJECT_NAME}_LIBS ${LIBS}
    CACHE INTERNAL
    "${PROJECT_NAME}: Link Libraries"
    FORCE
)

