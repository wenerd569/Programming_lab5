cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ProgLab5)

foreach(m IN ITEMS ${CMAKE_CXX_COMPILE_FEATURES})
    message(${m})
endforeach()

include_directories(include)

find_package(magic_enum REQUIRED)
find_package(nlohmann_json REQUIRED)


file(GLOB SOURCES1 "src/*/*/*.cpp")
file(GLOB SOURCES "src/*/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp; ${SOURCES}; ${SOURCES1})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE magic_enum::magic_enum)
target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json)