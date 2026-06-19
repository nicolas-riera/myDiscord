cmake_minimum_required(VERSION 3.10)
project(myDiscord C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(myDiscord main.c)
target_link_libraries(myDiscord PRIVATE PkgConfig::GTK4)