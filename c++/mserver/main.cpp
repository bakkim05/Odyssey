#include <iostream>
#include "writedats.h"
#include "Maker.h"

using namespace std;
int main() {
//    WriteDats wd;
    Maker m;

//    wd.escribirMetadata("Candy","Reggaeton", "Plan B", "Love and Sex", "2014", "Ella es fanatica de lo sensual...", "Categoria");
//
//    wd.read(wd.xml);

    //cout <<wd.xml << endl;

    cJSON* a = m.musicJSON("Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017", "Categoria", "Quiero Repetir...");
    cout << cJSON_Print(a);
    
//    m.treeSong(a);
//    m.treeAlbum(a);
//    m.treeArtist(a);











}