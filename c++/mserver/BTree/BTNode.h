#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template<class T>
class BTNode
{
  public:
    BTNode(BTNode<T> *parent = NULL );

    T _item;
    int _number_of_items;
    BTNode<T> *_parent;
    BTNode<T> *_left_child;
    BTNode<T> *_right_child;
};

template<class T>
BTNode<T>::BTNode(BTNode<T> *parent):
	_number_of_items(0), _parent(parent),	
	_left_child(NULL), _right_child(NULL){}	

#endif
