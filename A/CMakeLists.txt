cmake_minimum_required(VERSION 3.0)

project(mylib)

add_library(mylib SHARED
    lib.cpp
)

install(FILES ${HEADERS} DESTINATION A/${PROJECT_NAME})