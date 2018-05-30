#include "iterador.h"
#include "vector"
#include <fstream>
#include <sstream>

Iterador::Iterador()
{

}

void Iterador::fullJsonUser(string fileXML, Maker *maker)
{
    cout << "Parsing songs..." << endl;
    xml_document<> doc;
    xml_node<> * root_node;
    char* username;
    char* name;
    char* age;
    char* favsong;
    char* password;
    char* friends;

    // Read the xml file into a vector
    vector<char> buffer(fileXML.begin(),fileXML.end());
    buffer.push_back('\0');
    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);
    // Find our root node
    string nodoRoot = doc.first_node()->name();
    cout<<nodoRoot<<endl;
    if(nodoRoot == "InfoUser"){
        cout<<"parseo de user"<<endl;
        root_node = doc.first_node("InfoUser");
        xml_node<> * music_node = root_node->first_node("Username");
        username = music_node->first_attribute("username")->value();
        cout<<"Nombre usuario: "<<username<<endl;
        //print the atribute of the music
            xml_node<> * name1 = music_node->first_node("Name");
            name =name1->value();
            cout<<"Nombre Usuario: "<<name<<endl;

            xml_node<> * Age = music_node->first_node("Age");
            age = Age->value();
            cout<<"Edad del usuario: "<<age<<endl;

            xml_node<> * FavSong = music_node->first_node("FavSongs");
            favsong = FavSong->value();
            cout<<"valor del album: "<<favsong<<endl;

            xml_node<> * Password = music_node->first_node("password");
            password = Password->value();
            cout<<"valor del ano: "<<password<<endl;

            xml_node<> * Friends = music_node->first_node("Friends");
            friends = Friends->value();
            cout<<"valor de la categoria: "<<friends<<endl;

            //xml = buffer;
            maker->addUserJSON(maker->Usuarios,username,name,age,favsong,password,friends);
    }
    else{
        cout<<"no pos no"<<endl;
    }
    cout<<"mos se "<<endl;
}
