#include <iostream>
#include "writedats.h"
#include "Maker.h"

using namespace std;
int main() {
    WriteDats wd;
    Maker m;

    m.addMusicJSON(m.metadata,"Quiero Repetir", "Reggaeton", "Ozuna", "Odisea", "2017","hi" ,"Quiero Repetir..."  );
    m.addMusicJSON(m.metadata,"Candy", "Reggaeton", "Plan B", "Love and Sex", "2014", "cate", "Ella es fanatica de lo sensual");
    m.addMusicJSON(m.metadata,"Aprender A Quererte", "Latin Pop", "Morat", "Sobre El Amor Y Sus Efectos Secundarios", "2016","hi" ,"No se nada de tu historia ni de tu filosofia..."  );

    m.addUserJSON(m.Usuarios,"karilang1999","Karina Lang","18","Waves","123","Mari Lu");
    m.addUserJSON(m.Usuarios,"Beatvc", "Beatriz Vargas", "20", "It's a Beautiful Day", "contra", "Ivannia Herrera");

    m.saveJSON("music");
    m.saveJSON("user");
}