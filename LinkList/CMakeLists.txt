cmake_minimum_required(VERSION 3.8)
project(LinkList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkList.h LinkList.cpp)
add_executable(LinkList ${SOURCE_FILES})