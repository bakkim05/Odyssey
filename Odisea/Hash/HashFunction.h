//
// Created by Oska on 4/26/2018.
//

#ifndef HASHING_HASHFUNCTION_H
#define HASHING_HASHFUNCTION_H

#include <string>
#include <iostream>
#include <cstdlib>

class HashFunction{

private:
    static const int tableSize = 57;

    struct item{

        std::string name;
        std::string password;
        item* next;

    };

    item* HashTable[tableSize];

public:

    HashFunction();
    int Hash(std::string key);
    void AddItem (std::string name , std::string password);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);

};



#endif //HASHING_HASHFUNCTION_H
