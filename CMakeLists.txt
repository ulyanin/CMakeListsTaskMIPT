cmake_minimum_required(VERSION 3.0)

project(task2)

include(Doxygen/doxygen.cmake)

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
list(APPEND SOURCES_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/B/main.cpp
        )
list(APPEND HEADERS_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/B/main.h
        ${CMAKE_CURRENT_SOURCE_DIR}/C/index.h
        )

add_executable(task2 ${SOURCES_LIST} ${HEADERS_LIST})

target_link_libraries(task2 mylib)

target_include_directories(task2 PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}  ## for "A/lib.h"
        ${CMAKE_CURRENT_SOURCE_DIR}/B
        ${CMAKE_CURRENT_SOURCE_DIR}/C)
target_sources(task2 PUBLIC
        ${SOURCES_LIST}
        )

add_doxygen(task2)
add_doxygen(mylib)
