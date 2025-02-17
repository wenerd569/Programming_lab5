cmake_minimum_required(VERSION 3.10)
project(ProgLab5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std:c++latest")
set(CMAKE_CXX_COMPILER "usr/bin/clang++")
set(CMAKE_CXX_STANDARD 23)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ProgLab5 ${SOURCES})