cmake_minimum_required(VERSION 3.10)
project(Template)

find_package(SDL3 REQUIRED)

if(SDL3_FOUND)
	include_directories(${SDL3_INCLUDE_DIRS})

	set(CMAKE_CXX_LINKER_FLAGS "-fuse-ld=mold")

	add_executable(Template Template.c)
	target_link_libraries(Template ${SDL3_LIBRARIES})
else()
	message(FATAL_ERROR "SDL3 not found. Please install SDL3 or set SDL3_DIR.")
endif()
