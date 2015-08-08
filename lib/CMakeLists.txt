set(LOCAL_INCLUDES "")
set(LOCAL_LIBS "")

#     --    glfw
set(GLFW_CLIENT_LIBRARY "opengl")
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

add_subdirectory(glfw/)
set(LOCAL_INCLUDES ${LOCAL_INCLUDES} ${GLFW_SOURCE_DIR}/include)
set(LOCAL_LIBS ${LOCAL_LIBS} glfw ${GLFW_LIBRARIES})


#     --    glew
set(glew-cmake_BUILD_STATIC OFF)
set(glew-cmake_BUILD_SHARED ON)
add_subdirectory(glew-cmake/)
set(LOCAL_INCLUDES ${LOCAL_INCLUDES} ${glew_SOURCE_DIR}/include)
set(LOCAL_LIBS ${LOCAL_LIBS} libglew_shared)


#     --    glm
set(LOCAL_INCLUDES ${LOCAL_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}/glm)


# Push local includes and libs to parent scope
set(INCLUDES ${INCLUDES} ${LOCAL_INCLUDES} PARENT_SCOPE)
set(LIBS ${LIBS} ${LOCAL_LIBS} PARENT_SCOPE)

