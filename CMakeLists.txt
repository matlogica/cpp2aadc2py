cmake_minimum_required(VERSION 3.12)

project(MyQLib)

if(NOT AADC_FOUND)

        include(${AADC_DIR}/options.cmake)

        option(AADC_QL  "Enable AAD for QL" ON)
        option(AADC_PASSIVE  "Enable passive AAD" OFF)

        if(AADC_QL)
                add_definitions(-DAADC_QL)
                add_definitions(-DAADC_ALLOW_TO_PASSIVE_BOOL)
        endif()

        if(AADC_PASSIVE)
                add_definitions(-DAADC_PASSIVE)
        endif()
endif()

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
