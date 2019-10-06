cmake_minimum_required(VERSION 3.0)

project(softcomp)

include_directories(include/)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(softcomp main.cpp)

install(TARGETS softcomp RUNTIME DESTINATION bin)
