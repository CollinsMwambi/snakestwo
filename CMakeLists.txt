cmake_minimum_required(VERSION 3.21)
project(snakes)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES glad.c snakes GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor assimp)


add_executable(snakes main.cpp glad.c)
set(SOURCE_FILES glad.c main.cpp)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} glfw GLEW::GLEW)