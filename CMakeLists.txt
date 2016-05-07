cmake_minimum_required(VERSION 2.8.11)

# Turn it ON: -Dtest=ON
option(test "Include Tests." OFF)

set(PROJECT_NAME yarenderer)
project(${PROJECT_NAME} C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
    message(STATUS "Please use a different C++ compiler.")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)
set(LIBS "")
set(INCLUDES
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/include
)

#     --    dependencies

find_package(FreeImage REQUIRED)
set(LIBS ${LIBS} ${FREEIMAGE_LIBRARIES})
set(INCLUDES ${INCLUDES} ${FREEIMAGE_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
set(LIBS ${LIBS} ${OPENGL_gl_LIBRARY})
set(INCLUDES ${INCLUDES} ${OPENGL_INCLUDE_DIR})
add_subdirectory(lib/)


#     --    source
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
add_subdirectory(src/)


#     --    global variables
set(${PROJECT_NAME}_INCLUDE_DIRS ${INCLUDES}
    CACHE INTERNAL
    "${PROJECT_NAME}: Include Directories"
    FORCE
)

set(${PROJECT_NAME}_LIBRARIES ${LIBS}
    CACHE INTERNAL
    "${PROJECT_NAME}: Link Libraries"
    FORCE
)

set(${PROJECT_NAME}_LIBRARY yarenderer
    CACHE INTERNAL
    "${PROJECT_NAME}: Link Libraries"
    FORCE
)

if (test)
  add_subdirectory(tests/)
endif()
