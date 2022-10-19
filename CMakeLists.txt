cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(game VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp CONFIGURE_DEPENDS)
add_executable(game src/main.cpp ${SRC_FILES})
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
