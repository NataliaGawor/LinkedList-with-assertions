cmake_minimum_required(VERSION 3.10)
project(LinkedList)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinkedList Sources/main.cpp Headres/el.h Sources/List.cpp Headres/List.h Sources/el.cpp)