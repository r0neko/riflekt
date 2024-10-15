cmake_minimum_required(VERSION 3.14)
project(ReflectionSample VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ReflectionSample main.cpp)

add_subdirectory("../" reflection_build)
target_link_libraries(ReflectionSample riflekt)