find_package (Qt4 REQUIRED QtCore QtGui QtXml)

set (EXENAME cpp_names_view)
set (LIBNAME cpp_names_view_lib)

set (LIBCPPNAMES cpp_names)
include_directories (${CPPNAMES_SOURCE_DIR}/cpp_names)
link_directories (${CPPNAMES_BINARY_DIR}/cpp_names)

set (HEADERS 
	mainwindow.h
    )

set (SOURCES 
	mainwindow.cpp
	)

set (FORMS
	mainwindow.ui
	)
    
qt4_wrap_cpp (MOC_SOURCES ${HEADERS})
qt4_wrap_ui (FORMS_HEADERS ${FORMS})

include (${QT_USE_FILE})

add_definitions (${QT_DEFINITIONS})

add_library (${LIBNAME} ${SOURCES} ${MOC_SOURCES} ${FORMS_HEADERS}) 

add_executable (${EXENAME} WIN32 main.cpp)

target_link_libraries (${EXENAME} ${LIBNAME} ${QT_LIBRARIES} ${QT_QTMAIN_LIBRARY} ${LIBCPPNAMES})

include_directories (. ${CMAKE_CURRENT_BINARY_DIR})
