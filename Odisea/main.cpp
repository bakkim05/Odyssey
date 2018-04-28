#include "Hash/HashFunction.h"

using namespace std;

int main()
{
    HashFunction h;
    //h.PrintTable();

    h.AddItem("IvanCifuentes", "Cifuentes123");
    h.AddItem("IanCoberly", "Coberly123");
    h.AddItem("RachidSlon", "Slon123");
    h.AddItem("ChrsitianFonseca", "Fonseca123");
    h.AddItem("AlessandroRamirez", "Ramirez123");
    h.AddItem("FelipeMarin", "Marin123");
    h.PrintTable();
    //h.PrintItemsInIndex(0);

    //Part 12

    return 0;
}