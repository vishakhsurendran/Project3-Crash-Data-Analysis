cmake_minimum_required(VERSION 3.29)
project(Project3_Crash_Data_Analysis)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Project3_Crash_Data_Analysis
    src/Crash.cpp
    src/Crash.h
    src/main.cpp)
