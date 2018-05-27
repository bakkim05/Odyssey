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
void Maker::addMusicJSON(cJSON* metadata , char* nombre, char* genero,char* artista, char* album, char* agno,char* categoria, char* letra)
{
    for (int i = 0; i < cJSON_GetArraySize(metadata); i++)
    {
        if (strcmp(cJSON_GetArrayItem(metadata,i)->child->valuestring,nombre)==0)
        {
            cout << "La cuenta ya existe" << endl;

            return;
        }
    }
    cJSON_AddItemToArray(metadata, songName = cJSON_CreateObject());
    cJSON_AddItemToObject(songName, "nombre", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(songName, "Genre", cJSON_CreateString(genero));
    cJSON_AddItemToObject(songName, "Artist", cJSON_CreateString(artista));
    cJSON_AddItemToObject(songName, "Album", cJSON_CreateString(album));
    cJSON_AddItemToObject(songName, "Year", cJSON_CreateString(agno));
    cJSON_AddItemToObject(songName, "Category", cJSON_CreateString(categoria));
    cJSON_AddItemToObject(songName, "Lyrics", cJSON_CreateString(letra));

    addTreeSong(nombre);
    addTreeArtist(artista);
    addTreeAlbum(album);

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
void Maker::addUserJSON(cJSON* Usuarios, char* cuenta, char* nombre,char* edad, char* favoritos, char* contrasegna, char* amigos)
{
//    cJSON* current = Usuarios->next;
    for (int i = 0; i < cJSON_GetArraySize(Usuarios); i++)
    {
        if (strcmp(cJSON_GetArrayItem(Usuarios,i)->child->valuestring,cuenta)==0)
        {
            cout << "La cuenta ya existe" << endl;

            return;
        }
    }
    cJSON_AddItemToArray(Usuarios, usuarioArray = cJSON_CreateObject());
    cJSON_AddItemToObject(usuarioArray, "Username", cJSON_CreateString(cuenta));
    cJSON_AddItemToObject(usuarioArray, "Name", cJSON_CreateString(nombre));
    cJSON_AddItemToObject(usuarioArray, "Age", cJSON_CreateString(edad));
    cJSON_AddItemToObject(usuarioArray, "FavSongs", cJSON_CreateString(favoritos));
    cJSON_AddItemToObject(usuarioArray, "password", cJSON_CreateString(hashPassword(contrasegna)));
    cJSON_AddItemToObject(usuarioArray, "friend", cJSON_CreateString(amigos));

    addTreeUser(cuenta);
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
void Maker::searchUserdata(char *nombreUsuario)
{

}
void Maker::addTreeUser (char* userName)
{
    if (userTree.search(userName))
    {
        userTree.remove(userName);
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
        //cout << "No entro" << endl;
        //cout << cJSON_GetArrayItem(Usuarios,i)->child->valuestring << " == " << inputUser << endl;
        if (strcmp(cJSON_GetArrayItem(Usuarios,i)->child->valuestring,inputUser)==0)
        {
            //cout <<"Si entro" << endl;
            cJSON* current = cJSON_GetArrayItem(Usuarios,i)->child;

            while (current->string != "password")
            {
                //cout << current->string << endl;
                if (strcmp(current->string, "password") == 0)
                {
                    if (strcmp(current->valuestring, hashPassword(inputPassword))==0)
                    {
                        //cout << current->valuestring << " == " << hashPassword(inputPassword) << endl;
                        cout << "true" << endl;


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
    }

    if (strcmp(option,"user")==0)
    {
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

        return;
    }
}
void Maker::saveJSON(char* option)
{
    if (strcmp(option,"user")==0)
    {
        std::ofstream file_stored("userJSON.json");
        file_stored << cJSON_Print(userRoot);
    }

    if (strcmp(option,"music")==0)
    {
        std::ofstream file_stored("musicJSON.json");
        file_stored << cJSON_Print(root);
    }
}
char* Maker::searchInformation(cJSON *jsonChild, char *string)
{
//    for (int i = 0; i < cJSON_GetArraySize(jsonChild); i++)
//    {
//        cJSON* current = cJSON_GetArrayItem(jsonChild,i)->child;
//        for ()
//        if (strcmp(current->valuestring,string)==0)
//        {
//            cout << "La cuenta ya existe" << endl;
//
//        }
//    }
//}
