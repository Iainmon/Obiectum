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
include_directories(src)
#indicate the entry point for the executable
add_executable (test src main.cpp)

#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

if(LINUX)
    #link_directories(/usr/lib)
    #target_link_libraries(test obiectum "-lGL" "-lGLU" "-lglut" "-lGLEW")
    #target_link_libraries(test obiectum ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
    target_link_libraries(test obiectum)
elseif(APPLE)
    target_link_libraries(test obiectum "-framework OpenGL" "-framework GLUT" "-framework Cocoa" "-framework Foundation")
endif()

# Indicate which libraries to include during the link process.

install (TARGETS obiectum DESTINATION bin)