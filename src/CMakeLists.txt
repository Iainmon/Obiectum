cmake_minimum_required(VERSION 2.8.9)
project (obiectum)

add_library (obiectum 
  Component.hpp
  Component.cpp
  GameObject.hpp
  GameObject.cpp
  Hierarchy.hpp
  Hierarchy.cpp
  physics/Vector.hpp
  physics/Vector.cpp
  physics/Color.hpp
  physics/Color.cpp
  components/Components.hpp
  components/RigidBody.cpp
  components/Transform.cpp
  components/Drawable.cpp
  Obiectum.hpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(obiectum ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

install (TARGETS obiectum DESTINATION bin)
install (FILES Obiectum.hpp DESTINATION include)