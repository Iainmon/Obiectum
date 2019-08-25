cmake_minimum_required (VERSION 2.8)
project (test)

#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
elseif(UNIX AND APPLE)
    set(APPLE TRUE)
endif()

#include the subdirectory containing our libs
add_subdirectory (src)
include_directories (src)
add_executable (test src main.cpp)

# add_subdirectory (examples)
# include_directories (examples)
add_executable (drawables src examples/drawables.cpp)


if(LINUX)
    #link_directories(/usr/lib)
    #target_link_libraries(test obiectum "-lGL" "-lGLU" "-lglut" "-lGLEW")
    #target_link_libraries(test obiectum ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
    target_link_libraries(test obiectum)
    target_link_libraries(drawables obiectum)
elseif(APPLE)
    target_link_libraries(test obiectum "-framework OpenGL" "-framework GLUT" "-framework Cocoa" "-framework Foundation")
    target_link_libraries(drawables obiectum "-framework OpenGL" "-framework GLUT" "-framework Cocoa" "-framework Foundation")
endif()

# Indicate which libraries to include during the link process.

install (TARGETS obiectum DESTINATION bin)