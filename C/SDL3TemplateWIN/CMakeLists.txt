cmake_minimum_required(VERSION 3.16)
project(Template.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "(${CMAKE_BINARY_DIR}/$<CONFIGURATION>)")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "(${CMAKE_BINARY_DIR}/$<CONFIGURATION>)")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(Template WIN32 Template.cpp)

target_link_libraries(Template PRIVATE SDL3::SDL3)
