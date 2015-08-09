include_directories(${INCLUDES})

file(GLOB_RECURSE SRCS *.cc)
add_library(yarenderer ${SRCS})

set(LIBS ${LIBS} yarenderer PARENT_SCOPE)

