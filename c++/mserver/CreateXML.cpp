//
// Created by Juno on 5/21/2018.
//

#include "CreateXML.h"
#include <iostream>
#include <sstream>
#include <fstream>

std::string ParserXML::xmlCancion(char* song, char* gender, char* artist, char* album, char* year, char* lyrics, char* category)
{
    std::cout << "Writing XML Cancion" << std::endl;

    pugi::xml_document doc;

    pugi::xml_node declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

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

    pugi::xml_node code = cancion.append_child("apCode");
    code.append_child(pugi::node_pcdata).set_value("0");
    //Convert to String
    std::stringstream ss;
    doc.save(ss, "");

    std::string xml_as_string;
    xml_as_string = ss.str();

    //Save to File
     doc.save_file("../xmlCancion.xml");

     return xml_as_string;
}

std::string ParserXML::xmlUsuario(char* username, char* name, char* favSongs, char* password, char* friends, char* age)
{
    std::cout << "Writing XML Usuario" << std::endl;

    pugi::xml_document doc;

    pugi::xml_node declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

    pugi::xml_node root = doc.append_child("InfoUser");

    pugi::xml_node usuario = root.append_child("Usuario");
    usuario.append_attribute("nombre") = username;

    pugi::xml_node nombre = usuario.append_child("Name");
    nombre.append_child(pugi::node_pcdata).set_value(name);

    pugi::xml_node edad = usuario.append_child("Age");
    usuario.append_child(pugi::node_pcdata).set_value(age);

    pugi::xml_node favoritas = usuario.append_child("FavSongs");
    usuario.append_child(pugi::node_pcdata).set_value(favSongs);

    pugi::xml_node contrasegna = usuario.append_child("Password");
    usuario.append_child(pugi::node_pcdata).set_value(password);

    pugi::xml_node amigos = usuario.append_child("Friends");
    usuario.append_child(pugi::node_pcdata).set_value(friends);

    pugi::xml_node code = usuario.append_child("apCode");
    code.append_child(pugi::node_pcdata).set_value("0");

    //Convert to String
    std::stringstream ss;
    doc.save(ss, "");

    std::string xml_as_string;
    xml_as_string = ss.str();


    //Save to File
    doc.save_file("../xmlUsuario.xml");

    return xml_as_string;
}