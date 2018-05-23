//
// Created by Juno on 5/21/2018.
//

#ifndef MSERVER_CREATEXML_H
#define MSERVER_CREATEXML_H

#include "pugixml.hpp"

class ParserXML
{
public:

    std::string xmlCancion(char* song, char* gender, char* artist, char* album, char* year, char* lyrics, char* category);
    std::string xmlUsuario(char* username, char* name, char* favSongs, char* password, char* friends, char* age);
    void readXML(std::string);
};


#endif //MSERVER_CREATEXML_H
