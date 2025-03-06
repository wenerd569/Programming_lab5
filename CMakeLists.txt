cmake_minimum_required(VERSION 3.20)
project(ProgLab5)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ProgLab5 ${SOURCES})
target_compile_features(ProgLab5 PUBLIC cxx_std_23)

add_subdirectory(external_libs/magic_enum)
add_subdirectory(external_libs/nlohmann)

target_link_libraries(ProgLab5 PRIVATE magic_enum)
target_link_libraries(ProgLab5 PRIVATE nlohmann_json)

target_include_directories(ProgLab5 PRIVATE external_libs/magic_enum/include/magic_enum)
target_include_directories(ProgLab5 PRIVATE external_libs/nlohmann/include/nlohmann)