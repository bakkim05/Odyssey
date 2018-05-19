#ifndef WRITEDATS_H
#define WRITEDATS_H
#include "rapidxml.hpp"
#include <string.h>
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace rapidxml;
class WriteDats
{
public:
    WriteDats();
    string escribir(char* song1,char* gender1, char* artist1, char* album1, char* year1, char* lyrics1, char* category1);
    void read();
    string getXml();
    string xml;
};

#endif // WRITEDATS_H
