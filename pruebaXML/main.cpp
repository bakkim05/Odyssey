#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <fstream>
#include <sstream>


using namespace std;
using namespace rapidxml;
void escribir();
void leer();
int main()
{
cout<<"vamos a probar"<<endl;
escribir();

xml_document<> doc1;
std::ifstream file("file_stored.xml");

stringstream buffer2;
buffer2 << file.rdbuf();
std::string content(buffer2.str());
doc1.parse<0>(&content[0]);
xml_node<> *pRoot = doc1.first_node("data");
cout<<pRoot->first_attribute()->name()<<endl;
cout<<pRoot->first_attribute("version")->value()<<endl;
cout<<pRoot->first_attribute("type")->value()<<endl;
for (xml_node<> *chilRoot = pRoot->first_node("Havana"); chilRoot; chilRoot = chilRoot->next_sibling())
{
        cout<<"aqui ni me arrimo"<<endl;
        cout<<"Nombre artista: "<<chilRoot->first_attribute("Artist")->value()<<endl;
        cout<<"Nombre del album: "<<chilRoot->first_attribute("Album")->value()<<endl;
}
}
void escribir(){
    xml_document<> doc;
    xml_node<> *decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding","utf-8"));
    xml_node<>* root = doc.allocate_node(node_element, "data");
    root->append_attribute(doc.allocate_attribute("version", "1.0"));
    root->append_attribute(doc.allocate_attribute("type", "metadata"));
    doc.append_node(root);

    xml_node<>* child = doc.allocate_node(node_element, "Havana");
    child->append_attribute(doc.allocate_attribute("Artist","Camila Cabello"));
    child->append_attribute(doc.allocate_attribute("Album","Camila"));
    child->append_attribute(doc.allocate_attribute("Gender","Latin pop"));
    child->append_attribute(doc.allocate_attribute("year","2018"));
    child->append_attribute(doc.allocate_attribute("Letra","paso a pasito"));
    child->append_attribute(doc.allocate_attribute("Categorias","Latin pop"));
    root->append_node(child);

    xml_node<>* child1 = doc.allocate_node(node_element, "HowLong");
    child->append_attribute(doc.allocate_attribute("Artist","Charlie Puth"));
    child->append_attribute(doc.allocate_attribute("Album","Voicenotes"));
    child->append_attribute(doc.allocate_attribute("Gender","Pop"));
    child->append_attribute(doc.allocate_attribute("year","2018"));
    child->append_attribute(doc.allocate_attribute("Letra","paso a pasito"));
    child->append_attribute(doc.allocate_attribute("Categorias","Pop"));
    root->append_node(child1);

    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    // Save to file
    std::ofstream file_stored("file_stored.xml");
    file_stored << doc;
    file_stored.close();
    doc.clear();
}
