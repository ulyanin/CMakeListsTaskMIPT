cmake_minimum_required(VERSION 3.0)

project(task2)

set(CMAKE_CXX_STANDARD 14)

## A

add_subdirectory("A")

## C

set(codegen_impl
        C/preparing.py
)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
        ${codegen_impl}
        )

execute_process(
        COMMAND python3 preparing.py
        -o ${CMAKE_BINARY_DIR}/generated C
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/C
)

file(GLOB_RECURSE ${generated_files}
        ${CMAKE_BINARY_DIR}/generated C/index.h
)

## B

set(SOURCES_LIST B/main.cpp)

add_executable(task2 ${generated_files} ${SOURCES_LIST})

target_link_libraries(task2 mylib)
target_include_directories(task2 PRIVATE .)
