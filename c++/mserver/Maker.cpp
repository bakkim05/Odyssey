//
// Created by Oska on 5/23/2018.
//

#include "Maker.h"

cJSON* Maker::musicJSON(char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra)
{
    cJSON* root = cJSON_CreateObject();

    cJSON_AddItemToObject(root,"nombre", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(root,"Gender", cJSON_CreateString(genero));
    cJSON_AddItemToObject(root,"Artist", cJSON_CreateString(artista));
    cJSON_AddItemToObject(root,"Album", cJSON_CreateString(album));
    cJSON_AddItemToObject(root,"Year", cJSON_CreateString(agno));
    cJSON_AddItemToObject(root,"Category", cJSON_CreateString(categoria));
    cJSON_AddItemToObject(root,"Lyrics", cJSON_CreateString(letra));

    return root;
}

void Maker::treeSong (cJSON* root)
{
    BTree <std::string> songTree;
    songTree.Insert(cJSON_GetObjectItem(root,"nombre")->valuestring);
    songTree.List_InOrder();
}

void Maker::treeArtist (cJSON* root)
{
    BTree <std::string> artistTree;
    artistTree.Insert(cJSON_GetObjectItem(root,"Artist")->valuestring);
    artistTree.List_InOrder();
}

void Maker::treeAlbum (cJSON* root)
{
    BTree <std::string> albumTree;
    albumTree.Insert(cJSON_GetObjectItem(root,"Album")->valuestring);
    albumTree.List_InOrder();
}



