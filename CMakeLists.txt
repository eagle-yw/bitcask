cmake_minimum_required(VERSION 3.28.0)
project(bitcask VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_SCAN_FOR_MODULES ON)

add_subdirectory(demo)
add_subdirectory(src)


