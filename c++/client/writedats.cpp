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

string WriteDats::escribir(char* song1, char* gender1, char* artist1, char* album1, char* year1, char* lyrics1, char* category1)
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



void WriteDats::read()
{
    cout << "Parsing songs..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    // Read the xml file into a vector
    ifstream theFile ("config2.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    root_node = doc.first_node("Data");
    cout<<"mos se "<<endl;
    // Find the music
    xml_node<> * music_node = root_node->first_node("Music");
    cout<<"Vallor nombre cancion: "<<music_node->first_attribute("nombre")->value()<<endl;
    //print the atribute of the music
    xml_node<> * gender = music_node->first_node("Gender");
    cout<<"valor del genero: "<<gender->value()<<endl;
    xml_node<> * Artist = music_node->first_node("Artist");
    cout<<"valor del artista: "<<Artist->value()<<endl;
    xml_node<> * Album = music_node->first_node("Album");
    cout<<"valor del album: "<<Album->value()<<endl;
    xml_node<> * year = music_node->first_node("Year");
    cout<<"valor del ano: "<<year->value()<<endl;
    xml_node<> * category = music_node->first_node("Category");
    cout<<"valor de la categoria: "<<category->value()<<endl;
    xml_node<> * lyrics = music_node->first_node("Lyrics");
    cout<<"valor de la letra: "<<lyrics->value()<<endl;
    xml_node<> * Ope = root_node->first_node("apCode");
    cout<<"valor de la operacion: "<<Ope->value()<<endl;

}

string WriteDats::getXml()
{
    return xml;
}
