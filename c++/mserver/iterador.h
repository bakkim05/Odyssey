#ifndef ITERADOR_H
#define ITERADOR_H
#include <string.h>
#include "writedats.h"
#include "maker.h"

class Iterador
{
public:
    Iterador();
    void fullJsonUser(string fileXML, Maker *maker);
};

#endif // ITERADOR_H
