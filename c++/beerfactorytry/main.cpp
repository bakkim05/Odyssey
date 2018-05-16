#include "writedats.h"

using namespace rapidxml;
using namespace std;

int main(void)
{
    WriteDats *ur = new WriteDats();
    ur->read();
    ur->escribir("Havana","pop","Camila Cabello","Camila","2018","Latin pop","jugooyugf");
    ur->read();


}
