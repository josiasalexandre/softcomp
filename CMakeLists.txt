cmake_minimum_required(VERSION 3.9)

project(softcomp)

include_directories(include/)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(softcomp main.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

target_link_libraries(softcomp Eigen3::Eigen)

install(TARGETS softcomp RUNTIME DESTINATION bin)
