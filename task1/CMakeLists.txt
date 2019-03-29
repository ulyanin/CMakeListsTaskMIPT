cmake_minimum_required(VERSION 3.0)

project(task1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory("A")

set(SOURCES_LIST B/main.cpp)

add_executable(task1 ${SOURCES_LIST})

target_link_libraries(task1 mylib)
target_include_directories(task1 PRIVATE .)
