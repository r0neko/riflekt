cmake_minimum_required(VERSION 3.14)
project(riflekt VERSION 1.0.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
        riflekt
        src/private/rift/reflection/rf_object.cpp
        src/private/rift/reflection/rf_method.cpp
        src/private/rift/reflection/rf_type_ptr_property.cpp
        src/private/rift/reflection/rf_type_info.cpp
)

target_include_directories(
        riflekt
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/public"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/private"
)