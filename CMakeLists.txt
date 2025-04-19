cmake_minimum_required(VERSION 3.28)

project(code_master_main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_subdirectory(code_master)
# add_subdirectory(campus_recruit)

add_executable(main_test main.cpp)
