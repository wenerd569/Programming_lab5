cmake_minimum_required(VERSION 3.20)
project(ProgLab5)


file(GLOB SOURCES "src/*.cpp")
add_library(prog5lib STATIC ${SOURCES})

target_include_directories(prog5lib PUBLIC "include")
target_compile_features(prog5lib PRIVATE cxx_std_23)


add_executable(ProgLab5 main.cpp)
target_link_libraries(ProgLab5 prog5lib)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std:c++23")
#set(CMAKE_CXX_COMPILER "usr/bin/clang++")
#set(CMAKE_CXX_STANDARD 23)


