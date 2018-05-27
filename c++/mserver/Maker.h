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
    cJSON *userRoot, *Usuarios, *usuarioArray;
    BinarySearchTree<std::string> songTree, artistTree, albumTree, userTree;

    Maker();

    void addMusicJSON(cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);
    void searchSong(char* nombreCancion);
    void deleteSong(char* nombreCancion);
    void editSong(char* nombreCancion, cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);

    void addUserJSON(cJSON* Usuarios, char* cuenta, char* nombre,char* edad, char* favoritos, char* contrasegna, char* amigos);
    void deleteUser (char* nombreUsuario);
    bool searchUser (char* nombreUsuario);
    void searchUserdata (char* nombreUsuario);

    void addTreeSong (char* song);
    void addTreeArtist (char* artist);
    void addTreeAlbum (char* album);

    void deleteTreeSong (char* song);
    void deleteTreeArtist (char* artist);
    void deleteTreeAlbum (char* album);

    void addTreeUser (char* userName);
    void deleteTreeUser (char* userNAme);

    void recomendFriend(cJSON* Usuarios);
    void orderAlbum (BinarySearchTree <std::string> albumTree);
    void orderSong (BinarySearchTree <std::string> songTree);
    void orderArtist (BinarySearchTree <std::string> songTree);

    char* searchInformation(cJSON* json, char* string);

    char* hashPassword (std::string password);
    bool compareHash(char* inputUser,char *inputPassword);

    void loadJSON(char* option);
    void saveJSON(char* option);




//    void trackLyrics (cJSON* root);
};





#endif //TEST_JSONMAKER_H
