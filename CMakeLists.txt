cmake_minimum_required(VERSION 3.14)

project(calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(calc
    src/main.cpp
    src/calc.cpp
)

target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(calc PRIVATE -Wall -Wextra -Werror -pedantic)
endif()
