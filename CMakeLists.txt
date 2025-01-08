cmake_minimum_required(VERSION 3.18)

project(CPP)

add_executable(main main.cpp)
add_executable(main2 main2.cpp)
target_compile_features(main PRIVATE cxx_std_20)
target_compile_features(main2 PRIVATE cxx_std_20)