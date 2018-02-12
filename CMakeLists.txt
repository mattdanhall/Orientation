cmake_minimum_required(VERSION 3.9)
project(Orientation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Orientation orientation.cpp orientation.h main.cpp connection.cpp connection.h transition.cpp transition.h)

add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)
add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)
FIND_PACKAGE(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(Orientation ${ImageMagick_LIBRARIES} -lGraphicsMagick++ -lGraphicsMagick)