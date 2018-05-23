
#include "writedats.h"
#include "rapidxml_print.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace rapidxml;
using namespace std;
WriteDats::WriteDats()
{

}

string WriteDats::escribirMetadata(char* song1, char* gender1, char* artist1, char* album1, char* year1, char* lyrics1, char* category1)
{
    cout<<"Writing xml Documents"<<endl;
    xml_document<> doc;
    xml_node<> *decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding","utf-8"));
    xml_node<>* root = doc.allocate_node(node_element, "Data");

    xml_node<>* root1 = doc.allocate_node(node_element, "Music");
    root1->append_attribute(doc.allocate_attribute("nombre",song1));
    root->append_node(root1);
    xml_node<> *gender = doc.allocate_node(node_element,"Gender");
    gender->value(gender1);
    root1->append_node(gender);
    xml_node<> *artist = doc.allocate_node(node_element,"Artist");
    artist->value(artist1);
    root1->append_node(artist);
    xml_node<> *album = doc.allocate_node(node_element,"Album");
    album->value(album1);
    root1->append_node(album);
    xml_node<> *year = doc.allocate_node(node_element,"Year");
    year->value(year1);
    root1->append_node(year);
    xml_node<> *category = doc.allocate_node(node_element,"Category");
    category->value(category1);
    root1->append_node(category);
    xml_node<> *lyrics = doc.allocate_node(node_element,"Lyrics");
    lyrics->value(lyrics1);
    root1->append_node(lyrics);

    xml_node<>* root2 = doc.allocate_node(node_element, "apCode");
    root2->value("0");
    root->append_node(root2);
    doc.append_node(root);


    // Convert doc to string if needed
    std::string xml_as_string;

    rapidxml::print(std::back_inserter(xml_as_string), doc);
    xml = xml_as_string;

    // Save to file
    std::ofstream file_stored("config2.xml");
    file_stored << doc;
    file_stored.close();
    doc.clear();
    return xml_as_string;
}

string WriteDats::escribirUser(char *username, char *name, char *favSongs, char *password, char *friends, char *year1)
{
    cout<<"Writing xml Documents"<<endl;
    xml_document<> doc;
    xml_node<> *decl = doc.allocate_node(node_declaration);
    //configuracion xml
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding","utf-8"));
    //primer Nodo
    xml_node<>* root = doc.allocate_node(node_element, "InfoUser");
    //Nombre del Usuario
    xml_node<>* root1 = doc.allocate_node(node_element, "Username");
    root1->append_attribute(doc.allocate_attribute("username",username));
    //Nombre
    root->append_node(root1);
    xml_node<> *Name = doc.allocate_node(node_element,"Name");
    Name->value(name);
    root1->append_node(Name);
    //Nodo Edad
    xml_node<> *Age = doc.allocate_node(node_element,"Age");
    Age->value(year1);
    root1->append_node(Age);
    //Nodo FavSongs
    xml_node<> *FavSongs = doc.allocate_node(node_element,"FavSongs");
    FavSongs->value(favSongs);
    root1->append_node(FavSongs);
    //Nodo password
    xml_node<> *Password = doc.allocate_node(node_element,"password");
    Password->value(password);
    root1->append_node(Password);
    //Nodo lista amigos
    xml_node<> *Friends = doc.allocate_node(node_element,"Friends");
    Friends->value(friends);
    root1->append_node(Friends);
    //Nodo apCode
    xml_node<>* root2 = doc.allocate_node(node_element, "apCode");
    root2->value("0");
    root->append_node(root2);
    doc.append_node(root);
    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    // Save to file
    std::ofstream file_stored("config1.xml");
    cout<<"do something1"<<endl;
    file_stored << doc;
    cout<<"do something1"<<endl;
    file_stored.close();
    cout<<"do something1"<<endl;
    doc.clear();
}



int WriteDats::read(string cd)
{
    cout << "Parsing songs..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;

    // Read the xml file into a vector
    vector<char> buffer(cd.begin(),cd.end());
     cout<<"holi"<<endl;
    buffer.push_back('\0');
    cout<<"holi"<<endl;
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    cout<<"holi"<<endl;
    // Find our root node
   string nodoRoot = doc.first_node()->name();
    cout<<nodoRoot<<endl;
    if(nodoRoot == "Data"){
        cout<<"parseo de musica"<<endl;
        root_node = doc.first_node("Data");
        xml_node<> * music_node = root_node->first_node("Music");
        cout<<"Valor nombre cancion: "<<music_node->first_attribute("nombre")->value()<<endl;

        //print the atribute of the music
        if(music_node->first_node()->name() =="Gender"){
            xml_node<> * gender = music_node->first_node("Gender");
            cout<<"valor del genero: "<<gender->value()<<endl;
        }
        if(music_node->first_node()->name() == "Artist"){
            xml_node<> * Artist = music_node->first_node("Artist");
            cout<<"valor del artista: "<<Artist->value()<<endl;
        }
        if(music_node->first_node()->name() == "Album"){
            xml_node<> * Album = music_node->first_node("Album");
            cout<<"valor del album: "<<Album->value()<<endl;
        }
        if(music_node->first_node()->name() == "Year"){
            xml_node<> * year = music_node->first_node("Year");
            cout<<"valor del ano: "<<year->value()<<endl;
        }
        if(music_node->first_node()->name() == "Category"){
        xml_node<> * category = music_node->first_node("Category");
        cout<<"valor de la categoria: "<<category->value()<<endl;
        }
        if(music_node->first_node()->name() == "Lyrics"){
            xml_node<> * lyrics = music_node->first_node("Lyrics");
            cout<<"valor de la letra: "<<lyrics->value()<<endl;
        }
        xml_node<> * Ope = root_node->first_node("apCode");
        cout<<"valor de la operacion: "<<Ope->value()<<endl;
        char* ap = Ope->value();
        int apcode = atoi(ap);
        cout<<"valor del apcode: "<<apcode<<endl;
        return apcode;

    }
    if(nodoRoot == "InfoUser"){
        cout<<"parseo de user"<<endl;
        root_node = doc.first_node("InfoUser");
        xml_node<> * music_node = root_node->first_node("Username");
        cout<<"Nombre usuario: "<<music_node->first_attribute("username")->value()<<endl;
        //print the atribute of the music
        if(music_node->first_node()->name() == "name"){
            xml_node<> * gender = music_node->first_node("Name");
            cout<<"valor del genero: "<<gender->value()<<endl;
        }
        if(music_node->first_node()->name() == "Age"){
            xml_node<> * Artist = music_node->first_node("Age");
            cout<<"valor del artista: "<<Artist->value()<<endl;
        }
        if(music_node->first_node()->name() == "FavSongs"){
            xml_node<> * Album = music_node->first_node("FavSongs");
            cout<<"valor del album: "<<Album->value()<<endl;
        }
        if(music_node->first_node()->name() == "password"){
            xml_node<> * year = music_node->first_node("password");
            cout<<"valor del ano: "<<year->value()<<endl;
        }
        if(music_node->first_node()->name() == "Friends"){
            xml_node<> * category = music_node->first_node("Friends");
            cout<<"valor de la categoria: "<<category->value()<<endl;
        }
        xml_node<> * Ope = root_node->first_node("apCode");
        cout<<"valor de la operacion: "<<Ope->value()<<endl;
        char* ap = Ope->value();
        int apcode = atoi(ap);
        cout<<"valor del apcode: "<<apcode<<endl;
        return apcode;

    }
    else{
        cout<<"no pos no"<<endl;
    }
    cout<<"mos se "<<endl;
    // Find the music

}

string WriteDats::getXml()
{
    return xml;
}
