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
    void escribir(char* username,char* name, char* favSongs, char* password, char* friends, char* year1);
    void read();
};

#endif // WRITEDATS_H
