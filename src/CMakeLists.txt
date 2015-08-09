#  -- Config

set(SHADER_SOURCES_DIR 
  ${CMAKE_CURRENT_SOURCE_DIR}/shaders/sources
)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/yarenderer__config.hh.in 
  ${CMAKE_CURRENT_BINARY_DIR}/yarenderer__config.hh
)

# --  Source

include_directories(${INCLUDES})

file(GLOB_RECURSE SRCS *.cc)
add_library(yarenderer ${SRCS})
target_link_libraries(yarenderer ${LIBS})



set(LIBS ${LIBS} yarenderer PARENT_SCOPE)

