cmake_minimum_required(VERSION 3.10)
project(PixelGame)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(PNG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
include_directories(${PNG_INLCUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${X11_INCLUDE_DIR})

add_executable(PixelGame src/main.cpp)
target_include_directories(PixelGame PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(PixelGame -static-libgcc -static-libstdc++ ${PNG_LIBRARY} ${OPENGL_LIBRARY} ${X11_LIBRARIES})
