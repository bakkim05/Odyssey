//
// Created by Oska on 4/26/2018.
//

#include "HashFunction.h"
using namespace std;


int HashFunction::Hash(std::string key)
{
    int hash = 0;
    int index;

    index = key.length();

    for (int i = 0 ; i < key.length() ; i ++)
    {
        hash += (int)key[i];
         cout << "key["<<i<<"]: " << key[i] << " == " << (int)key[i] << endl;
        cout << "Hash: " << hash << endl;
    }






    return index;
}

