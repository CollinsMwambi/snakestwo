cmake_minimum_required(VERSION 3.21)
project(snakes)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES glad.c test GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor assimp)


add_executable(snakes main.cpp)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw GLEW::GLEW)