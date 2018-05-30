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
    string escribirMetadata(char* song1,char* gender1, char* artist1, char* album1, char* year1, char* lyrics1, char* category1);
    string escribirUser(char* username,char* name, char* favSongs, char* password, char* friends, char* year1);
    int read(string cd);
    string getXml();
    string getSong(string cd);
    string xml;
    void readsong(xml_node<> *root_node);
    string writeStreaming(string song, string encode);
    string getUser(string cd);
    string writeSucces(string tipoXML);
    string getPassword(string cd);
    string writeFail(string tipoXML);
};

#endif // WRITEDATS_H
