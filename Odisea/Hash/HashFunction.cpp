//
// Created by Oska on 4/26/2018.
//

#include "HashFunction.h"
using namespace std;



HashFunction::HashFunction()
{
    for (int i = 0 ; i < tableSize ; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->password = "empty";
        HashTable[i]->next = NULL;
    }
}


int HashFunction::Hash(std::string key)
{
    int hash = 0;
    int index;

    for (int i = 0 ; i < key.length() ; i ++)
    {
        hash += ((int)key[i])*17;
        //cout << "Hash: " << hash << endl;
    }

    index = hash % tableSize;

    return index;
}

void HashFunction::AddItem(std::string name, std::string password)
{
    int index = Hash(name);

    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->password = password;

    } else{
        item* Ptr = HashTable[index];
        item* n = new item;

        n->name = name;
        n->password = password;
        n->next = NULL;

        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;

    }
}

int HashFunction::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if (HashTable[index]->name == "empty")
    {
        return count;

    }else{

        count++;
        item* Ptr = HashTable[index];
        while (Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
        return count;
    }
}

void HashFunction::PrintTable()
{
    int number;

    for (int i = 0 ; i < tableSize ; i++)
    {
        number = NumberOfItemsInIndex(i);

        cout << "------------------------" << endl;
        cout << "index: " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->password << endl;
        cout << "number of items: " << number << endl;
        cout << endl;

    }
}

void HashFunction::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];
    if (Ptr->name == "empty")
    {
        cout << "Index: " << index << " is empty" << endl;

    }else{

        cout << "Index: " << index << " contains the following items" << endl;
        while (Ptr != NULL)
        {
            cout << "------------------------" << endl;
            cout << Ptr->name << endl;
            cout << Ptr->password << endl;
            cout << "------------------------" << endl;

            Ptr = Ptr->next;
        }
    }
}
