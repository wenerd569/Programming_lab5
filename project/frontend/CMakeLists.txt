cmake_minimum_required(VERSION 3.20)
project(ProgLab5)


file(GLOB SOURCE src/*.cpp)
add_subdirectory(../comon)


add_library(magic_enum STATIC libs/magic_enum.h)

add_library(front STATIC ${SOURCE})
target_link_libraries(front common)
target_link_libraries(front magic_enum)
target_include_directories(front PUBLIC include)
