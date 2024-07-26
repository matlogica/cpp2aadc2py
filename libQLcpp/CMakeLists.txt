cmake_minimum_required(VERSION 3.12)

project(MyQLib)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_library(
    libQL
    SHARED
    Curve.cpp
    CashFlowPricer.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(
    MyQLibTest
    test.cpp
)

target_link_libraries(
    MyQLibTest
    libQL
)