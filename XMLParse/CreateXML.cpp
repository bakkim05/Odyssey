//
// Created by Juno on 5/21/2018.
//

#include "CreateXML.h"
#include <iostream>

void create(char* song, char* gender, char* artist, char* album, char* year, char* lyrics, char* category)
{
    pugi::xml_document doc;

    pugi::xml_node root = doc.append_child("Data");

    pugi::xml_node cancion = root.append_child("Music");
    cancion.append_attribute("nombre") = song;

    pugi::xml_node genero = cancion.append_child("Gender");
    genero.append_child(pugi::node_pcdata).set_value(gender);

    pugi::xml_node artista = cancion.append_child("Artist");
    artista.append_child(pugi::node_pcdata).set_value(artist);

    pugi::xml_node discografia = cancion.append_child("Album");
    discografia.append_child(pugi::node_pcdata).set_value(album);

    pugi::xml_node agno = cancion.append_child("Year");
    agno.append_child(pugi::node_pcdata).set_value(year);

    pugi::xml_node categoria = cancion.append_child("Category");
    categoria.append_child(pugi::node_pcdata).set_value(category);

    pugi::xml_node letra = cancion.append_child("Lyrics");
    letra.append_child(pugi::node_pcdata).set_value(lyrics);

    doc.print(std::cout);

}
