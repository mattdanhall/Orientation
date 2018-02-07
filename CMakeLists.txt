cmake_minimum_required(VERSION 3.9)
project(Orientation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Orientation orientation.cpp orientation.h main.cpp connection.cpp connection.h transition.cpp transition.h)