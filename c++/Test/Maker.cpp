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

    addMusicJSON(metadata,"Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017", "Cate", "Quiero Repetir...");
    addMusicJSON(metadata,"Candy", "Reggaeton", "Plan B", "Love and Sex", "2014", "Cate", "Ella es fanatica de lo sensual");

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



cJSON* Maker::addMusicJSON(cJSON* metadata , char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra)
{
    cJSON_AddItemToArray(metadata, songName = cJSON_CreateObject());
    cJSON_AddItemToObject(songName, "nombre", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(songName, "Genre", cJSON_CreateString(genero));
    cJSON_AddItemToObject(songName, "Artist", cJSON_CreateString(artista));
    cJSON_AddItemToObject(songName, "Album", cJSON_CreateString(album));
    cJSON_AddItemToObject(songName, "Year", cJSON_CreateString(agno));
    cJSON_AddItemToObject(songName, "Category", cJSON_CreateString(categoria));
    cJSON_AddItemToObject(songName, "Lyrics", cJSON_CreateString(letra));



}

void Maker::searchsong(char* nombreCancion) {
    WriteDats wd;
    char* input[6];

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
    cout << input[5];

    //wd.escribirMetadata(input[0],input[1],input[2],input[3],input[4],input[5],input[6]);


    //cout << cJSON_GetArrayItem(metadata,1)->child->valuestring;
}

//void Maker::searchSong (char* songName)
//{
//
//    if (strcmp(cJSON_GetArrayItem(root->child->child,0)->valuestring,"Quiero Repetir")==0)
//    {
//        for (int i = 0; i < cJSON_GetArraySize(root->child->child) ; i++)
//        {
//            cout << cJSON_GetArrayItem(root->child->child,i)->string << ": ";
//            cout << cJSON_GetArrayItem(root->child->child,i)->valuestring << endl;
//        }
//    }
//}


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



