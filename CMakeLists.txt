cmake_minimum_required(VERSION 3.5)

# Project Name
project(MATLIB VERSION 0.5)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Setting Module Path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Executable
add_executable(MATLIB main.cpp matlib.cpp cfloat.cpp)