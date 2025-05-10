cmake_minimum_required(VERSION 3.10)
project(Template)

find_package(SDL2 REQUIRED)

if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIRS})

	set(CMAKE_CXX_LINKER_FLAGS "-fuse-ld=mold")

	add_executable(Template main.cpp)
	target_link_libraries(Template ${SDL2_LIBRARIES})
else()
	message(FATAL_ERROR "SDL2 not found. Please install SDL2 or set SDL2_DIR.")
endif()
