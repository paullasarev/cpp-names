find_package(BISON)
find_package(FLEX)
find_package( Boost 1.45.0 )

include_directories(${Boost_INCLUDE_DIRS})

BISON_TARGET(CppBisonParser cpp_scanner.y  ${CMAKE_CURRENT_SOURCE_DIR}/cpp_scanner_y.cpp)
FLEX_TARGET(CppFlexScanner cpp_scanner.l  ${CMAKE_CURRENT_SOURCE_DIR}/cpp_scanner_l.cpp)

ADD_FLEX_BISON_DEPENDENCY(CppFlexScanner CppBisonParser)

include_directories(SYSTEM .)

add_library (cpp_names database.cpp directory_tree.cpp cpp_scanner.cpp cpp_scanner_l.cpp cpp_scanner_y.cpp) 

add_executable (cppnames cppnames_main.cpp)

target_link_libraries (cppnames cpp_names)
