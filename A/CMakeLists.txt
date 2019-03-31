cmake_minimum_required(VERSION 3.0)

project(mylib)

list(APPEND SOURCES_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp)

message(${SOURCES_LIST})

list(APPEND HEADERS_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/lib.h)

add_library(mylib SHARED
    ${SOURCES_LIST}
)

target_include_directories(mylib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(mylib PUBLIC
        ${SOURCES_LIST}
        )

install(FILES ${HEADERS} DESTINATION A/${PROJECT_NAME})