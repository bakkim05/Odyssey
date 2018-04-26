cmake_minimum_required(VERSION 3.9)
project(Hashing)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hashing main.cpp Hash/HashFunction.cpp Hash/HashFunction.h)