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
    void searchSong(char* nombreCancion);
    void deleteSong(char* nombreCancion);
    void editSong(char* nombreCancion, cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);

    void addTreeSong (char* song);
    void addTreeArtist (char* artist);
    void addTreeAlbum (char* album);

    void deleteTreeSong (char* song);
    void deleteTreeArtist (char* artist);
    void deleteTreeAlbum (char* album);

    void loadTree (cJSON* root);


//    void trackLyrics (cJSON* root);
};





#endif //TEST_JSONMAKER_H
