cmake_minimum_required(VERSION 3.8)

project(SimpleMath C)

add_executable(example_generics examples/example_generics.c)
target_include_directories(example_generics PUBLIC include/)

add_executable(example_no_generics examples/example_no_generics.c)
target_include_directories(example_no_generics PUBLIC include/)