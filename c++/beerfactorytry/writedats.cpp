#include "writedats.h"
#include "rapidxml_print.hpp"
#include <vector>
#include <fstream>
#include <sstream>

using namespace rapidxml;
using namespace std;
WriteDats::WriteDats()
{

}

void WriteDats::escribirUser(char* username,char* name, char* favSongs, char* password, char* friends, char* year1)
{
    cout<<"Writing xml Documents"<<endl;
    xml_document<> doc;
    xml_node<> *decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    cout<<"sed"<<endl;
    decl->append_attribute(doc.allocate_attribute("encoding","utf-8"));
    xml_node<>* root = doc.allocate_node(node_element, "InfoUser");
cout<<"do something1"<<endl;
    xml_node<>* root1 = doc.allocate_node(node_element, "Username");
    root1->append_attribute(doc.allocate_attribute("username",username));
    cout<<"do something1"<<endl;
    root->append_node(root1);
    xml_node<> *Name = doc.allocate_node(node_element,"Name");
    Name->value(name);
    root1->append_node(Name);
    cout<<"do something2"<<endl;
    xml_node<> *Age = doc.allocate_node(node_element,"Age");
    Age->value(year1);
    root1->append_node(Age);
    cout<<"do something3"<<endl;
    xml_node<> *FavSongs = doc.allocate_node(node_element,"FavSongs");
    FavSongs->value(favSongs);
    root1->append_node(FavSongs);
    cout<<"do something4"<<endl;
    xml_node<> *Password = doc.allocate_node(node_element,"password");
    Password->value(password);
    root1->append_node(Password);
    cout<<"do something5"<<endl;
    xml_node<> *Friends = doc.allocate_node(node_element,"Friends");
    Friends->value(friends);
    root1->append_node(Friends);
    cout<<"do something6"<<endl;
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
    /**
    for (xml_node<> * brewery_node = root_node->first_node("Brewery"); brewery_node; brewery_node = brewery_node->next_sibling())
    {
        printf("I have visited %s in %s. ",
            brewery_node->first_attribute("name")->value(),
            brewery_node->first_attribute("location")->value());
            // Interate over the beers
        for(xml_node<> * beer_node = brewery_node->first_node("Beer"); beer_node; beer_node = beer_node->next_sibling())
        {
            printf("On %s, I tried their %s which is a %s. ",
                beer_node->first_attribute("dateSampled")->value(),
                beer_node->first_attribute("name")->value(),
                beer_node->first_attribute("description")->value());
            printf("I gave it the following review: %s", beer_node->value());
        }
        cout << endl;
    }
    **/
}
