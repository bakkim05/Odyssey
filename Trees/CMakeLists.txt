cmake_minimum_required(VERSION 3.10)
project(Trees)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trees main.cpp
        "BTree/btree.h" "BTree/BTNode.h"
        "BST/bstree.cpp" "BST/bstree.hpp")