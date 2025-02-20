
cmake_minimum_required(VERSION 3.20)
project(ProgLab5)

set(HEADERS
    structures/color.h
    structures/coordinate.h
    structures/country.h
    structures/location.h)
add_library(common ${HEADERS})
target_include_directories(common PUBLIC include)