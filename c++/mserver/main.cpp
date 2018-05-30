#include <iostream>
#include "writedats.h"
#include "Maker.h"

using namespace std;
int main() {
    WriteDats wd;
    Maker m;

//    m.addUserJSON(m.Usuarios,"karilang1999","Karina Lang","18","123");
//    m.addUserJSON(m.Usuarios,"Beatvc", "Beatriz Vargas", "20", "contra");
//    m.addUserJSON(m.Usuarios,"Princess69", "Nicole Coberly", "17", "amoUber");
//    m.addUserJSON(m.Usuarios,"Yuberthec","Yuberth","20","uno2tres4cinco");
//
    m.compareHash("Princess69", "amoUber");

    m.addMusicJSON(m.metadata,"Nena Maldicion", "Trap", "Paulo Londra", "Nena Maldicion", "2018","Nena Maldicion");
    m.addMusicJSON(m.metadata,"Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017","Quiero Repetir..."  );
    m.addMusicJSON(m.metadata,"Candy", "Reggaeton", "Plan B", "Love and Sex", "2014", "Ella es fanatica de lo sensual");
    m.addMusicJSON(m.metadata,"Aprender A Quererte", "Latin Pop", "Morat", "Sobre El Amor Y Sus Efectos Secundarios", "2016","No se nada de tu historia ni de tu filosofia...");

    //m.getSpecificData("album","Odisea");
    m.songTree.print_inorder();

}