#define BTREE_H
#include "BTNode.h"
#include <iostream>

template<class T>
class BTree{

  	public:

		BTree() : _node_count(0), _root(NULL){};   		
		~BTree() { Delete_Tree(_root); };

    	void Insert(T item);

    	void List_PreOrder();

    	void List_InOrder();

    	void List_PostOrder();

  	private:

    	bool _r, _l;

    	BTNode<T> *_root;

    	int _node_count;

   		void Insert(T _item, BTNode<T> *tree, BTNode<T> *parent);

    	void Delete_Tree(BTNode<T> *tree);

    	void Visit(BTNode<T> *the_node);

    	void List_PreOrder(BTNode<T> *tree);

    	void List_InOrder(BTNode<T> *tree);

    	void List_PostOrder(BTNode<T> *tree);
};


template<class T>
void BTree<T>::Delete_Tree(BTNode<T> *tree)
{
  	if(tree)
	{
    	Delete_Tree(tree->_left_child);
		Delete_Tree(tree->_right_child);
    	delete tree;
	}
}

template<class T>
void BTree<T>::Insert(T item)
{
	Insert(item, _root, _root);
}

template<class T>
void BTree<T>::Insert(T item, BTNode<T> *tree, BTNode<T> *parent){

  	if(_node_count == 0)
	{
    	_root = new BTNode<T>(parent);
    	_root->_item = item;
    	_root->_number_of_items++;
    	_node_count++;    
    }
	else if(!tree)
	{
		tree = new BTNode<T>(parent);
		tree->_item = item;
    	tree->_number_of_items++;

    	if(_r) parent->_right_child = tree;
      	else if(_l) parent->_left_child = tree;
		_node_count++;
    }
	else if(item == tree->_item)
	{
		tree->_number_of_items++;
	}
    else if(item < tree->_item)
	{
		_r = false;
		_l = true;
		Insert(item, tree->_left_child, tree);
	}
	else if(item > tree->_item)
	{
		_r = true;
		_l = false;
		Insert(item, tree->_right_child, tree);
	}
}


template<class T>
void BTree<T>::Visit(BTNode<T> *n)
{
	std::cout<<n->_item;
}

template<class T>
void BTree<T>::List_PreOrder()
{
     List_PreOrder(_root);
}

template<class T>
void BTree<T>::List_InOrder()
{
	List_InOrder(_root);
}

template<class T>
void BTree<T>::List_PostOrder()
{
	List_PostOrder(_root);
}

template<class T>
void BTree<T>::List_PreOrder(BTNode<T> *tree){

	if(tree)
	{
		Visit(tree);
		List_PreOrder(tree->_left_child);
		List_PreOrder(tree->_right_child);
	}
}

template<class T>
void BTree<T>::List_InOrder(BTNode<T> *tree){

    if(tree)
	{
      	List_InOrder(tree->_left_child);
		Visit(tree);
		List_InOrder(tree->_right_child);
	}
}

template<class T>
void BTree<T>::List_PostOrder(BTNode<T> *tree){

    if(tree)
	{
     	List_PostOrder(tree->_left_child);
		List_PostOrder(tree->_right_child);
		Visit(tree);
	}
}