include_directories(${INCLUDES})

message("Libs == ${LIBS}")

add_executable(main main.cc)
target_link_libraries(main
  ${LIBS}
)


