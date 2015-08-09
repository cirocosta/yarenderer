include_directories(${INCLUDES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SRCS *.cc)
add_library(yarenderer ${SRCS})
target_link_libraries(yarenderer ${LIBS})

set(LIBS ${LIBS} yarenderer PARENT_SCOPE)

