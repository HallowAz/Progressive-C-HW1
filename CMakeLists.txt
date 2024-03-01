cmake_minimum_required(VERSION 3.0.0)
project(hw1)

add_subdirectory(lib/hw1)

add_executable(hw1.exe src/main.cpp)
target_link_libraries(hw1.exe hw1)