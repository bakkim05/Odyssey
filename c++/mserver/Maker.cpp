//
// Created by Oska on 5/23/2018.
//

#include <cstring>
#include <fstream>
#include "Maker.h"
#include "writedats.h"

using namespace std;

Maker::Maker()
{

    root = cJSON_CreateObject();
    metadata = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "metadata", metadata);

    addMusicJSON(metadata,"Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017","hi" ,"Quiero Repetir..."  );
    addMusicJSON(metadata,"Candy", "Reggaeton", "Plan B", "Love and Sex", "2014", "cate", "Ella es fanatica de lo sensual");

    //cout << cJSON_Print(metadata);

}

//cJSON* Maker::musicJSON() {
//    //std::cout<<cJSON_Print(root)<< std::endl;
//
////    if (strcmp(cJSON_GetArrayItem(root->child->child,0)->valuestring,"Quiero Repetir")==0)
////    {
////        for (int i = 0; i < cJSON_GetArraySize(root->child->child) ; i++)
////        {
////            cout << cJSON_GetArrayItem(root->child->child,i)->string << ": ";
////            cout << cJSON_GetArrayItem(root->child->child,i)->valuestring << endl;
////        }
////    }
//
//    //std::cout << cJSON_GetArrayItem(root->child->child,0)->string;
//
////    fstream fs;
////    fs.open("songJSON.json",fstream::in | fstream::out | fstream::app);
////    fs << cJSON_Print(root);
////    fs.close();
//
//    return root;
//}

cJSON* Maker::musicJSON()
{
    Maker* maker;


}



cJSON* Maker::addMusicJSON(cJSON* metadata , char* nombre, char* genero,char* artista, char* album, char* agno,char* categoria, char* letra)
{
    cJSON_AddItemToArray(metadata, songName = cJSON_CreateObject());
    cJSON_AddItemToObject(songName, "nombre", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(songName, "Genre", cJSON_CreateString(genero));
    cJSON_AddItemToObject(songName, "Artist", cJSON_CreateString(artista));
    cJSON_AddItemToObject(songName, "Album", cJSON_CreateString(album));
    cJSON_AddItemToObject(songName, "Year", cJSON_CreateString(agno));
    cJSON_AddItemToObject(songName, "Category", cJSON_CreateString(categoria));
    cJSON_AddItemToObject(songName, "Lyrics", cJSON_CreateString(letra));

    treeSong(nombre);
    treeArtist(artista);
    treeAlbum(album);



}

void Maker::searchsong(char* nombreCancion) {
    WriteDats wd;
    char* input[7];

    for (int i = 0; i < cJSON_GetArraySize(metadata); i++)
    {
        if (strcmp(cJSON_GetArrayItem(metadata,i)->child->valuestring,nombreCancion)==0)
        {
            cJSON* current = cJSON_GetArrayItem(metadata,i)->child;
            for (int j = 0; j < cJSON_GetArraySize(root->child->child); j++)
            {
                //cout << cJSON_GetArrayItem(metadata,1)->child->valuestring;
                //cout << current->string << ": ";
                //cout << current->valuestring << endl;
                input[j] = current->valuestring;
                current = current->next;
            }
        }
    }

    wd.escribirMetadata(input[0],input[1],input[2],input[3],input[4],input[6], input[5]);


    //cout << cJSON_GetArrayItem(metadata,1)->child->valuestring;
}


void Maker::treeSong (char* song)
{
    if (!songTree.search(song))
    {
        songTree.insert(song);
    }

}

void Maker::treeArtist (char* artist)
{
    if (!songTree.search(artist))
    {
        songTree.insert(artist);
    }
}

void Maker::treeAlbum (char* album)
{
    if (!songTree.search(album))
    {
        songTree.insert(album);
    }
}

void Maker::loadTree(cJSON *root)
{
    //
}



