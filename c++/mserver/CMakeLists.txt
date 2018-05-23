cmake_minimum_required(VERSION 3.9)
project(Test)

set(CMAKE_CXX_STANDARD 11)

add_executable(Test main.cpp
        rapidxml_utils.hpp rapidxml_print.hpp rapidxml_iterators.hpp rapidxml.hpp
        writedats.cpp writedats.h Maker.cpp Maker.h
        cJSON.c cJSON.h
        "BTree/BTNode.h" "BTree/btree.h"
        server.cpp tcpserver.cpp tcpserver.h server
        mserver.pro mserver.pro.user.50d93ab mserver.pro.user mserver.pro.user.24ade14)