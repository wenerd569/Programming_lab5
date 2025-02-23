cmake_minimum_required(VERSION 3.20)
project(ProgLab5)

set(CMAKE_CXX_COMPILER "usr/bin/clang++")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ProgLab5 ${SOURCES})
target_compile_features(ProgLab5 PUBLIC cxx_std_23)