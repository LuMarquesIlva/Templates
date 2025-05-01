cmake_minimum_required(VERSION 3.31)
project(NcursesTemplate)

set(LINKER mold)

add_executable(NcursesTemplate main.c)
target_link_libraries(NcursesTemplate ncurses)
