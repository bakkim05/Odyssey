//
// Created by Oska on 5/23/2018.
//

#include <cstring>
#include <fstream>
#include <sstream>
#include "Maker.h"
#include "writedats.h"

using namespace std;

Maker::Maker()
{
    loadJSON("music");
    loadJSON("user");
}
void Maker::addMusicJSON(cJSON* metadata , char* nombre, char* genero,char* artista, char* album, char* agno, char* letra)
{
    addSongUser(nombre,artista,album);
    for (int i = 0; i < cJSON_GetArraySize(metadata); i++)
    {
        if (strcmp(cJSON_GetArrayItem(metadata,i)->child->valuestring,nombre)==0)
        {
            return;
        }
    }
    cJSON_AddItemToArray(metadata, songName = cJSON_CreateObject());
    cJSON_AddItemToObject(songName, "nombre", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(songName, "Genre", cJSON_CreateString(genero));
    cJSON_AddItemToObject(songName, "Artist", cJSON_CreateString(artista));
    cJSON_AddItemToObject(songName, "Album", cJSON_CreateString(album));
    cJSON_AddItemToObject(songName, "Year", cJSON_CreateString(agno));
    cJSON_AddItemToObject(songName, "Lyrics", cJSON_CreateString(letra));

    addTreeSong(nombre);
    addTreeArtist(artista);
    addTreeAlbum(album);

    saveJSON("music");
}
void Maker::searchSong(char* nombreCancion)
{
    WriteDats wd;
    char* input[7];

    for (int i = 0; i < cJSON_GetArraySize(metadata); i++)
    {
        if (strcmp(cJSON_GetArrayItem(metadata,i)->child->valuestring,nombreCancion)==0)
        {
            cJSON* current = cJSON_GetArrayItem(metadata,i)->child;
            for (int j = 0; j < cJSON_GetArraySize(root->child->child); j++)
            {
                input[j] = current->valuestring;
                current = current->next;
            }
        }
    }
}
void Maker::deleteSong(char *nombreCancion)
{
    char* input[7];

    for (int i = 0; i < cJSON_GetArraySize(metadata); i++)
    {
        if (strcmp(cJSON_GetArrayItem(metadata, i)->child->valuestring, nombreCancion) == 0)
        {

            cJSON* current = cJSON_GetArrayItem(metadata,i)->child;

            for (int j = 0; j < cJSON_GetArraySize(root->child->child); j++)
            {
                input[j] = current->valuestring;
                current = current->next;
            }

            cJSON_DeleteItemFromArray(metadata,i);

            if (!i == 0){
                deleteTreeSong(input[0]);
                deleteTreeArtist(input[2]);
                deleteTreeAlbum(input[3]);

            }else{
                deleteTreeSong(input[0]);
                deleteTreeArtist(input[2]);
            }
        }
    }

    saveJSON("music");
}
void Maker::editSong(char* nombreCancion, cJSON* metadata, char* nombre, char* genero,char* artista, char* album, char* agno, char* categoria, char* letra)
{
    WriteDats wd;

    for (int i = 0; i < cJSON_GetArraySize(metadata); i++) {
        if (strcmp(cJSON_GetArrayItem(metadata, i)->child->valuestring, nombreCancion) == 0) {
            cJSON *current = cJSON_GetArrayItem(metadata, i)->child;
            for (int j = 0; j < cJSON_GetArraySize(root->child->child); j++) {
                if (j == 0) {
                    deleteTreeSong(current->valuestring);
                    addTreeSong(nombre);
                    current->valuestring = nombre;
                }
                if (j == 1) {
                    current->valuestring = genero;
                }
                if (j == 2) {
                    deleteTreeArtist(current->valuestring);
                    addTreeArtist(artista);
                    current->valuestring = artista;
                }
                if (j == 3) {
                    if (i != 0)
                    {
                        deleteTreeAlbum(current->valuestring);
                        addTreeAlbum(album);
                    }
                    current->valuestring = album;
                }
                if (j == 4) {
                    current->valuestring = agno;
                }
                if (j == 5) {
                    current->valuestring = categoria;
                }
                if (j == 6) {
                    current->valuestring = letra;
                }
                current = current->next;
            }
        }
    }
    wd.escribirMetadata(nombre, genero, artista, album, agno, categoria, letra);
    saveJSON("music");
}
void Maker::addTreeSong (char* song)
{
    if (!songTree.search(song))
    {
        songTree.insert(song);
    }

}
void Maker::addTreeArtist (char* artist)
{
    if (!artistTree.search(artist))
    {
        artistTree.insert(artist);
    }
}
void Maker::addTreeAlbum (char* album)
{
    if (!albumTree.search(album))
    {
        albumTree.insert(album);
    }
}
void Maker::deleteTreeSong (char* song)
{
    if (songTree.search(song))
    {
        songTree.remove(song);
    }
}
void Maker::deleteTreeArtist (char* artist)
{
    if (artistTree.search(artist))
    {
        artistTree.remove(artist);
    }
}
void Maker::deleteTreeAlbum (char* album)
{
    if (albumTree.search(album))
    {
        albumTree.remove(album);
    }
}
void Maker::addUserJSON(cJSON* Usuarios, char* cuenta, char* nombre,char* edad, char* contrasegna)
{
//    cJSON* current = Usuarios->next;
    for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Usuarios,i)->child->valuestring,cuenta)==0)
        {
            return;
        }
    }
    cJSON_AddItemToArray(Usuarios, usuarioArray = cJSON_CreateObject());
    cJSON_AddItemToObject(usuarioArray, "Username", cJSON_CreateString(cuenta));
    cJSON_AddItemToObject(usuarioArray, "Name", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(usuarioArray, "Age", cJSON_CreateString(edad));
    cJSON_AddItemToObject(usuarioArray, "password", cJSON_CreateString(hashPassword(contrasegna)));
    addTreeUser(cuenta);
    saveJSON("user");
}
void Maker::deleteUser (char* nombreUsuario)
{
    for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Usuarios, i)->child->valuestring, nombreUsuario) == 0)
        {
            cJSON_DeleteItemFromArray(Usuarios,i);

            deleteTreeUser(cJSON_GetArrayItem(Usuarios, i)->child->valuestring);

        }
    }
    saveJSON("user");
}
bool Maker::searchUser (char* nombreUsuario)
{
    for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Usuarios,i)->child->valuestring,nombreUsuario)==0)
        {
            return true;
        }
    }

    return false;


}
void Maker::addTreeUser (char* userName)
{
    if (!userTree.search(userName))
    {
        userTree.insert(userName);
    }

}
void Maker::deleteTreeUser (char* userNAme)
{
    if (userTree.search(userNAme))
    {
        userTree.remove(userNAme);
    }
}
char* Maker::hashPassword(std::string password)
{
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(password);
    std::string hashedString = std::to_string(hash);


    std::string str = hashedString;
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());


    return cstr;
}
bool Maker::compareHash(char* inputUser,char *inputPassword)
{
    for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
    {
        if (i >= cJSON_GetArraySize(Usuarios))
        {
            return false;
        }

        if (strcmp(cJSON_GetArrayItem(Usuarios,i)->child->valuestring,inputUser)==0)
        {
            cJSON* current = cJSON_GetArrayItem(Usuarios,i)->child;

            while (current->string != "password")
            {
                if (strcmp(current->string, "password") == 0)
                {
                    if (strcmp(current->valuestring, hashPassword(inputPassword))==0)
                    {
                        cout << "true" << endl;

                        currentUser = cJSON_GetArrayItem(Usuarios,i)->child;
                        currentUserName = currentUser->valuestring;
                        filemaker();
                        loadJSON(currentUserChar);

                        loadTree("songTree");
                        loadTree("artistTree");
                        loadTree("albumTree");

                        return true;

                    }

                }
                if (current->next == nullptr)
                {
                    cout <<"false"<< endl;
                    return false;
                }

                current = current->next;
            }
        }
    }
    return false;
}
void Maker::loadJSON(char* option)
{
    if (strcmp(option,"music")==0)
    {
        std::ostringstream sstream;
        std::ifstream fs("musicJSON.json");

        if(fs.fail())
        {
            root = cJSON_CreateObject();
            metadata = cJSON_CreateArray();
            cJSON_AddItemToObject(root, "metadata", metadata);

            return;
        }

        sstream << fs.rdbuf();
        const std::string str(sstream.str());
        const char* ptr = str.c_str();

        root = cJSON_Parse(ptr);
        metadata = root->child;

        return;

    }else if (strcmp(option,"user")==0) {

        std::ostringstream sstream;
        std::ifstream fs("userJSON.json");

        if(fs.fail())
        {
            userRoot = cJSON_CreateObject();
            Usuarios = cJSON_CreateArray();
            cJSON_AddItemToObject(userRoot,"Usuarios", Usuarios);

            return;
        }

        sstream << fs.rdbuf();
        const std::string str(sstream.str());
        const char* ptr = str.c_str();

        userRoot = cJSON_Parse(ptr);
        Usuarios = userRoot->child;

        loadTree("userTree");

        return;

    }else {

        std::ostringstream sstream;
        std::ifstream fs(currentUserChar);

        if(fs.fail())
        {
            loadRoot = cJSON_CreateObject();
            Canciones = cJSON_CreateArray();
            Amigos = cJSON_CreateArray();
            cJSON_AddItemToObject(loadRoot,"Canciones", Canciones);
            cJSON_AddItemToObject(loadRoot,"Amigos", Amigos);

            return;
        }

        sstream << fs.rdbuf();
        const std::string str(sstream.str());
        const char* ptr = str.c_str();

        loadRoot = cJSON_Parse(ptr);
        Canciones = loadRoot->child;
        Amigos = loadRoot->child->next;

        //loadTree("userTree");

        return;

    }
}
void Maker::saveJSON(char* option)
{
    if (strcmp(option,"user")==0)
    {
        std::ofstream file_stored("userJSON.json");
        file_stored << cJSON_Print(userRoot);
        return;

    }else if (strcmp(option,"music")==0)
    {

        std::ofstream file_stored("musicJSON.json");
        file_stored << cJSON_Print(root);
        return;

    } else{

        std::ofstream file_stored(currentUserChar);
        file_stored << cJSON_Print(loadRoot);
        return;
    }
}
void Maker::loadTree(char* tree)
{
    if (strcmp(tree,"songTree")==0) {

        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            LoopSong:
            if (i >= cJSON_GetArraySize(Canciones))
            {
                return;
            }
            cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
            while (current->string != "Name")
            {
                if (strcmp(current->string, "Name") == 0)
                {
                    addTreeSong(current->valuestring);
                    i++;
                    goto LoopSong;
                }
                current = current->next;
            }
        }
    }

    if (strcmp(tree,"albumTree")==0) {
        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            LoopAlbum:
            if (i >= cJSON_GetArraySize(Canciones))
            {
                return;
            }
            cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
            while (current->string != "Album")
            {
                if (strcmp(current->string, "Album") == 0)
                {
                    addTreeAlbum(current->valuestring);
                    i++;
                    goto LoopAlbum;
                }
                current = current->next;
            }
        }
    }
    if (strcmp(tree,"artistTree")==0) {
        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            LoopArtist:
            if (i >= cJSON_GetArraySize(Canciones))
            {
                return;
            }
            cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
            while (current->string != "Artist")
            {
                if (strcmp(current->string, "Artist") == 0)
                {
                    addTreeArtist(current->valuestring);
                    i++;
                    goto LoopArtist;
                }
                current = current->next;
            }
        }
    }
    if (strcmp(tree,"userTree")==0) {
        for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
        {
            LoopUser:
            if (i >= cJSON_GetArraySize(Usuarios))
            {
                return;
            }
            cJSON *current = cJSON_GetArrayItem(Usuarios, i)->child;
            while (current->string != "Username")
            {
                if (strcmp(current->string, "Username") == 0)
                {
                    addTreeUser(current->valuestring);
                    i++;
                    goto LoopUser;
                }
                current = current->next;
            }
        }
    }
}
void Maker::addSongUser(char* nombreCancion, char* nombreArtista, char* nombreAlbum)
{
    for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Canciones,i)->child->valuestring,nombreCancion)==0)
        {
            return;
        }
    }
    cJSON_AddItemToArray(Canciones, CancionesArray = cJSON_CreateObject());
    cJSON_AddItemToObject(CancionesArray, "Name", cJSON_CreateString(nombreCancion));
    cJSON_AddItemToObject(CancionesArray, "Artist", cJSON_CreateString(nombreArtista));
    cJSON_AddItemToObject(CancionesArray, "Album", cJSON_CreateString(nombreAlbum));

    saveJSON(currentUserChar);
}
void Maker::addFriendUser(char* nUsuario)
{
    for (int i = 0; i < cJSON_GetArraySize(Amigos); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Amigos,i)->child->valuestring,nUsuario)==0)
        {
            return;
        }
    }
    cJSON_AddItemToArray(Amigos,AmigosArray = cJSON_CreateObject());
    cJSON_AddItemToObject(AmigosArray, "NombreUsuario", cJSON_CreateString(nUsuario));

}

void Maker::filemaker()
{
    string currentUserJSON = (currentUserName+(string)(".json"));
    char *cstr = new char[currentUserJSON.length() + 1];
    strcpy(cstr, currentUserJSON.c_str());
    currentUserChar = cstr;
}

void Maker::getSpecificData(char* option, char* name)
{
    if (strcmp(option,"song")==0)
    {
        string artist, album;
        cout << cJSON_GetArraySize(Canciones) << endl;
        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            if (strcmp(cJSON_GetArrayItem(Canciones, i)->child->valuestring, name) == 0)
            {
                cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
                while (current!=nullptr)
                {
                    if (strcmp(current->string, "Artist")==0)
                    {
                        artist = current->valuestring;
                        cout << artist << endl;

                    }
                    if (strcmp(current->string, "Album")==0)
                    {
                        album = current->valuestring;
                        cout << album << endl;
                    }
                    current = current->next;
                }
                return;
            }
        }
    }

    if (strcmp(option,"artist")==0)
    {
        string song, album;
        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            if (strcmp(cJSON_GetArrayItem(Canciones, i)->child->next->valuestring, name) == 0)
            {
                cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
                while (current!=nullptr)
                {
                    if (strcmp(current->string, "Name")==0)
                    {
                        song = current->valuestring;
                        cout << song << endl;
                    }
                    if (strcmp(current->string, "Album")==0)
                    {
                        album = current->valuestring;
                        cout << album << endl;
                    }
                    current = current->next;
                }
                return;
            }
        }
    }

    if (strcmp(option,"album")==0)
    {
        string song, album;
        cout << cJSON_GetArraySize(Canciones) << endl;
        for (int i = 0; i < cJSON_GetArraySize(Canciones); i++)
        {
            if (strcmp(cJSON_GetArrayItem(Canciones, i)->child->next->next->valuestring, name) == 0)
            {
                cJSON *current = cJSON_GetArrayItem(Canciones, i)->child;
                while (current!=nullptr)
                {
                    if (strcmp(current->string, "Name")==0)
                    {
                        song = current->valuestring;
                        cout << song << endl;
                    }
                    if (strcmp(current->string, "Artist")==0)
                    {
                        album = current->valuestring;
                        cout << album << endl;
                    }
                    current = current->next;
                }
                return;
            }
        }
    }
}


