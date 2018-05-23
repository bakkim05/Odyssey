//
// Created by Oska on 5/23/2018.
//

#ifndef TEST_JSONMAKER_H
#define TEST_JSONMAKER_H

#include "cJSON.h"
#include "BTree/btree.h"

class Maker{
public:
    cJSON *root, *metadata, *songName;

    Maker();
    cJSON* musicJSON ();
    cJSON* addMusicJSON(cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);
    void treeSong (cJSON* root);
    void treeArtist (cJSON* root);
    void treeAlbum (cJSON* root);
    void searchsong(char* nombreCancion);
//    void trackLyrics (cJSON* root);
};





#endif //TEST_JSONMAKER_H
