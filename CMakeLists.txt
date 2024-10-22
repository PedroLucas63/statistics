cmake_minimum_required(VERSION 3.5.0)
project(stats VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp)

include_directories(src/include src/include/models)

add_executable(stats ${SOURCES})