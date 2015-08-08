include_directories(${INCLUDES})

add_executable(main main.cc)
target_link_libraries(main
  ${LIBS}
)


