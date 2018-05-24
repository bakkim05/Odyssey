#ifndef STREAMING_H
#define STREAMING_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>


class streaming
{
public:
    streaming();
    char cancion[64];
    long size;
    std::ifstream mp3In;
    std::string namesong;
    void setFile(std::string file);
    std::string streamin(int current);
    char* returnSong();

};

#endif // STREAMING_H
