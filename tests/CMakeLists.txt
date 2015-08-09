
# -- on-screen and Utils

include_directories(${yarenderer_INCLUDE_DIRS})
include_directories("/usr/include")

add_executable(test_window test_window.cc)
target_link_libraries(test_window ${yarenderer_LIBRARIES})


# -- off-screen tests

include_directories(${OSMESA_INCLUDE_DIR})
add_executable(test_shaders test_shaders.cc)
target_link_libraries(test_shaders
  ${yarenderer_LIBRARIES}
  ${OSMESA_LIBRARY}
  ${OPENGL_glu_LIBRARY}
)

