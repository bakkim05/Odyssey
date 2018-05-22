cmake_minimum_required(VERSION 3.10)
project(XMLParse)

set(CMAKE_CXX_STANDARD 17)

add_executable(XMLParse main.cpp cJSON.h cJSON.c
        pugiconfig.hpp pugixml.cpp pugixml.hpp
        CreateXML.cpp CreateXML.h)