#include <cstring>
#include <fstream>
#include "writedats.h"
#include "maker.h"

using namespace std;
Maker::Maker()
{
    root = cJSON_CreateObject();
    metadata = cJSON_CreateArray();
    cJSON_AddItemToObject(root, "metadata", metadata);

    addMusicJSON(metadata,"Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017","hi" ,"Quiero Repetir..."  );
    addMusicJSON(metadata,"Candy", "Reggaeton", "Plan B", "Love and Sex", "2014", "cate", "Ella es fanatica de lo sensual");
    addMusicJSON(metadata,"Aprender A Quererte", "Latin Pop", "Morat", "Sobre El Amor Y Sus Efectos Secundarios", "2016","hi" ,"No se nada de tu historia ni de tu filosofia..."  );

    cout << cJSON_Print(metadata) << endl;

    editSong("Candy", metadata, "Amorfoda",  "Trap", "Bad Bunny", "Amorfoda", "2018", "5 Estrellas", "Un Buen Trap");

    cout << cJSON_Print(metadata) << endl;
}

cJSON *Maker::addMusicJSON(cJSON *metadata, char *nombre, char *genero, char *artista, char *album, char *agno, char *categoria, char *letra)
{
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

void Maker::editSong(char *nombreCancion, cJSON *metadata, char *nombre, char *genero, char *artista, char *album, char *agno, char *categoria, char *letra)
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

void Maker::loadTree(cJSON *root)
{
    //
}
