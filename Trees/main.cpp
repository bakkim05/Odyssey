#include <iostream>
#include "BTree/btree.h"
#include "BST/bstree.hpp"
#include "AVLTree/AVL.hpp"

using namespace std;

int main() {

//    BTree<char *> bt;
//    bt.Insert("Hello");
//    bt.Insert("GoodBye");
//    bt.Insert("Drive");
//    cout << "In Order" << endl;
//    bt.List_InOrder();
//    cout << "Post Order" << endl;
//    bt.List_PostOrder();
//    cout << "Pre Order" << endl;
//    bt.List_PreOrder();

//    BSTree<int, const char*> bst;
//    bst.insert(3,"tres");
//    bst.insert(4,"cuatro");
//    bst.print(PREORDER);


    AVLTree<int> avl;
    avl.insert(4);
    avl.insert(5);
    avl.printInOrder();



    return 0;
}