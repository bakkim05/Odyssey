//
// Created by Oska on 5/23/2018.
//

#include "Maker.h"

int num_songs = 1;

cJSON* Maker::musicJSON(char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra)
{
    cJSON* root = cJSON_CreateObject();
    cJSON* Music = cJSON_CreateArray();
    cJSON_AddItemToObjectCS(root,"Music",Music);
    for (int i; i < num_songs ; i++)
    {
        cJSON* song = cJSON_CreateObject();
        cJSON_AddItemToArray(Music,song);
        cJSON_AddItemToObject(song,"nombre", cJSON_CreateString(nombre));
        cJSON_AddItemToObject(song,"Gender", cJSON_CreateString(genero));
        cJSON_AddItemToObject(song,"Artist", cJSON_CreateString(artista));
        cJSON_AddItemToObject(song,"Album", cJSON_CreateString(album));
        cJSON_AddItemToObject(song,"Year", cJSON_CreateString(agno));
        cJSON_AddItemToObject(song,"Category", cJSON_CreateString(categoria));
        cJSON_AddItemToObject(song,"Lyrics", cJSON_CreateString(letra));
    }



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



