include_directories(${INCLUDES})

add_library(yarenderer Window.cc)
target_link_libraries(yarenderer ${LIBS})

add_executable(main main.cc)
target_link_libraries(main
  yarenderer
)


