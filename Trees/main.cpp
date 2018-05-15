#include <iostream>
#include "BTree/btree.h"

using namespace std;

int main() {

    BTree<char *> bt;

    bt.Insert("Hello");
    bt.Insert("GoodBye");
    bt.Insert("Drive");
    cout << "In Order" << endl;
    bt.List_InOrder();
    cout << "Post Order" << endl;
    bt.List_PostOrder();
    cout << "Pre Order" << endl;
    bt.List_PreOrder();

    return 0;
}