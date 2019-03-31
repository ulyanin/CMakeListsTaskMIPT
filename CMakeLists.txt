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

message("${HEADERS_LIST}")
message("${SOURCES_LIST}")

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

## first we can indicate the documentation build as an option and set it to ON by default
#option(BUILD_DOC "Build documentation" ON)
#
## check if Doxygen is installed
#find_package(Doxygen)
#if (DOXYGEN_FOUND)
#    # set input and output files
#    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
#    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)
#
#    # request to configure the file
#    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#    message("Doxygen build started")
#
#    # note the option ALL which allows to build the docs together with the application
#    add_custom_target( doc_doxygen ALL
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc
#            COMMENT "Generating API documentation with Doxygen"
#            VERBATIM )
#else (DOXYGEN_FOUND)
#    message("Doxygen need to be installed to generate the doxygen documentation")
#endif (DOXYGEN_FOUND)