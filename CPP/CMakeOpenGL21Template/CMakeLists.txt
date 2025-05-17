cmake_minimum_required(VERSION 3.10)
project(OpenGLTemplate)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp" "${CMAKE_SOURCE_DIR}/Libraries/src/gl.c" "${CMAKE_SOURCE_DIR}/Libraries/src/glx.c")
set(OpenGL_GL_PREFERENCE "LEGACY")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(X11 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${X11_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories("Libraries/include/")
include_directories(${GLFW_INCLUDE_DIR})

add_executable(OpenGLTemplate ${SOURCE_FILES})
target_link_libraries(OpenGLTemplate ${X11_LIBRARIES} ${OPENGL_LIBRARIES} glfw)