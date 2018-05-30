#ifndef MAKER_H
#define MAKER_H

#include "cJSON.h"
#include "BTree/bt.h"

class Maker
{
public:
    cJSON *root, *metadata, *songName;
    cJSON *userRoot,*Usuarios, *usuarioArray;
    cJSON *loadRoot, *Canciones, *CancionesArray, *Amigos, *AmigosArray;
    BinarySearchTree<std::string> songTree, artistTree, albumTree, userTree;
    cJSON *currentUser;
    string currentUserName;
    char* currentUserChar;

    Maker();

    void searchSong(char* nombreCancion); //case0
    void addMusicJSON(cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra); //case1
    void deleteSong(char* nombreCancion); //case2
    void editSong(char* nombreCancion, cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra);//case3

    void addUserJSON(cJSON* Usuarios, char* cuenta, char* nombre,char* edad, char* contrasegna); //case10
    bool compareHash(char* inputUser,char *inputPassword); //case11;
    void deleteUser (char* nombreUsuario); //case12


//back back end

    bool searchUser (char* nombreUsuario);

    void addTreeSong (char* song);
    void addTreeAlbum (char* album);
    void addTreeArtist (char* artist);
    void addTreeUser (char* userName);

    void deleteTreeSong (char* song);
    void deleteTreeAlbum (char* album);
    void deleteTreeArtist (char* artist);
    void deleteTreeUser (char* userNAme);

    void loadJSON(char* option);
    void saveJSON(char* option);
    void loadTree(char* tree);

    char* hashPassword (std::string password);

    void addSongUser(char* nombreCancion, char* nombreArtista, char* nombreAlbum);
    void addFriendUser(char* nUsuario);

    void getSongInfo(char* songName);

    void recomendFriend(cJSON* Usuarios);
    void orderAlbum (BinarySearchTree <std::string> albumTree);
    void orderSong (BinarySearchTree <std::string> songTree);

    void orderArtist (BinarySearchTree <std::string> songTree);
    void filemaker ();
};

#endif // MAKER_H
