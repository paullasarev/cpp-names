include_directories (${CPPNAMES_SOURCE_DIR}/cpp_names)
link_directories (${CPPNAMES_BINARY_DIR}/cpp_names)

add_executable (unit_tests main.cpp test_database.cpp test_command_line.cpp test_directory_tree.cpp test_save.cpp test_cpp_scanner.cpp)

target_link_libraries (unit_tests cpp_names)
