include_directories(${yarenderer_INCLUDE_DIRS})

add_executable(test_window test_window.cc)
target_link_libraries(test_window ${yarenderer_LIBRARIES})

