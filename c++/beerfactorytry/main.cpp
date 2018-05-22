#include "writedats.h"

using namespace rapidxml;
using namespace std;

int main(void)
{
    WriteDats *ur = new WriteDats();
    ur->escribir("Faridd","Farid Marin","Camila Cabello, howlong","12345","jung, kim","19");
    //ur->read();


}
