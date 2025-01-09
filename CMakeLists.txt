cmake_minimum_required(VERSION 3.12)

project(MyQLib)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(STRINGS "cu.txt" QL_SOURCES)

add_library(libQL SHARED ${QL_SOURCES})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(
    MyQLibTest
    src/test.cpp
)

target_link_libraries(
    MyQLibTest
    libQL
)
