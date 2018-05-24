//
// Created by Oska on 5/23/2018.
//

#ifndef TEST_JSONMAKER_H
#define TEST_JSONMAKER_H

#include "cJSON.h"

#include "BTree/BT.h"

class Maker{
public:
    cJSON *root, *metadata, *songName;
    BinarySearchTree<std::string> songTree, artistTree, albumTree;

    Maker();
    cJSON* musicJSON ();
    cJSON* addMusicJSON(cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);
    void treeSong (char* song);
    void treeArtist (char* artist);
    void treeAlbum (char* album);
    void loadTree (cJSON* root);
    void searchsong(char* nombreCancion);
//    void trackLyrics (cJSON* root);
};





#endif //TEST_JSONMAKER_H
