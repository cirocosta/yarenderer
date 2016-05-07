# -- tests

include_directories(${yarenderer_INCLUDE_DIRS})


file(GLOB_RECURSE tests "test_*.cc")
foreach(file ${tests})
  get_filename_component(testname ${file} NAME_WE)
  add_executable(${testname} ${file})
  target_link_libraries(${testname} ${yarenderer_LIBRARY})
  add_test(NAME ${testname} COMMAND ${testname})
endforeach()
