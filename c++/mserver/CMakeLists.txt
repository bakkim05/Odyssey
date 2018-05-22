cmake_minimum_required(VERSION 3.10)
project(mserver)

set(CMAKE_CXX_STANDARD 17)

add_executable(mserver main.cpp
        cJSON.h cJSON.c
        pugiconfig.hpp pugixml.cpp pugixml.hpp
        CreateXML.cpp CreateXML.h
        orderram.cpp orderram.h
        server.cpp tcpserver.cpp tcpserver.h)