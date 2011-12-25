find_package (Qt4 REQUIRED QtCore QtGui QtXml QtTest)

set (LIBNAME cpp_names_view_lib)
set (LIBDIR gui)
set (EXENAME gui_tests)

set (LIBCPPNAMES cpp_names)
include_directories (${CPPNAMES_SOURCE_DIR}/cpp_names)
link_directories (${CPPNAMES_BINARY_DIR}/cpp_names)

set (HEADERS 
	test_mainwindow.h
    )

set (SOURCES 
	test_mainwindow.cpp
	)

include_directories (. ${RELVIEW_SOURCE_DIR}/${LIBDIR} ${CMAKE_BINARY_DIR}/gui)

link_directories (${RELVIEW_BINARY_DIR}/${LIBDIR} ${CPP_NAMES_VIEW_LIB_BINARY_DIR}/${LIBDIR})

qt4_wrap_cpp (MOC_SOURCES ${HEADERS})

include (${QT_USE_FILE})

add_definitions (${QT_DEFINITIONS})

add_executable (${EXENAME} main.cpp ${SOURCES} ${MOC_SOURCES})

target_link_libraries (${EXENAME} ${LIBNAME} ${QT_LIBRARIES} ${LIBCPPNAMES})

add_test(cpp ${EXENAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
