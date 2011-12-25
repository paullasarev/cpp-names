cmake_minimum_required (VERSION 2.8)

project (CppNames)

enable_testing()

add_subdirectory (cpp_names ${CMAKE_CURRENT_BINARY_DIR}/cpp_names)
add_subdirectory (unit_tests ${CMAKE_CURRENT_BINARY_DIR}/unit_tests)
add_subdirectory (gui ${CMAKE_CURRENT_BINARY_DIR}/gui)
add_subdirectory (gui_tests ${CMAKE_CURRENT_BINARY_DIR}/gui_tests)

