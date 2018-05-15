#include <iostream>
#include "bstree.hpp"


template <typename TKey, typename TVal> BSTree<TKey, TVal>::~BSTree() {
    _deleteTree(root);
}

template <typename TKey, typename TVal> void BSTree<TKey, TVal>::insert(TKey key, TVal data) {

    if(!root) {
        root = _newNode(key, data);

    } else {

        BSTree<TKey, TVal>::node** current = &root, *parent = NULL;

        while(*current) {

            parent = *current;

            if(key < (*current)->key) {
                current = &parent->left;
            } else {
                current = &parent->right;
            }
        }

        *current = _newNode(key,data);
        (*current)->parent = parent;
    }
}


template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::del(TKey key) {

    if(!root) {
        return false;
    }

    BSTree<TKey, TVal>::node** current = &root;

    while(*current && (*current)->key != key) {

        if(key < (*current)->key) {
            current = &(*current)->left;
        } 
        else {
            current = &(*current)->right;
        }
    }
    if(!*current) {
        return false;
    }

    if(!(*current)->left) {
        if((*current)->right) {
            (*current)->right->parent = (*current)->parent;
        }
        BSTree<TKey, TVal>::node* ptrToFree = *current;
        *current = (*current)->left;
        delete ptrToFree;
        
    }
    else if(!(*current)->right) {
        if((*current)->left) {
            (*current)->left->parent = (*current)->parent;
        }
        BSTree<TKey, TVal>::node* ptrToFree = *current;
        *current = (*current)->left;
        delete ptrToFree;
    }
    else {
        BSTree<TKey, TVal>::node** temp = &(*current)->right;

        while((*temp)->left) temp = &(*temp)->left;

        (*current)->data = (*temp)->data;
        (*current)->key = (*temp)->key;

        BSTree<TKey, TVal>::node* ptrToFree = *temp;
        *temp = (*temp)->right;
        delete ptrToFree;
    }

    return true;

}
template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::remove(TKey key) {

    return del(key);

}

template <typename TKey, typename TVal> void BSTree<TKey, TVal>::print(TRAVERSAL_METHOD t) {
    switch(t) {
        case INORDER : {
            _printInOrder(root);
            break;
        }
        case PREORDER : {
            _printPreOrder(root);
            break;
        }
        case POSTORDER : {
            _printPostOrder(root);
            break;
        }
    }
    std::cout << std::endl;
}

template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::has(TKey key) {

    BSTree<TKey, TVal>::node* current = root;
    while(current) {
        if(key == current->key) {
            return true;
        }
        if(key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
    
}

template <typename TKey, typename TVal> const typename BSTree<TKey, TVal>::node* BSTree<TKey, TVal>::findNode(TKey key) {

    BSTree<TKey, TVal>::node* current = root;
    
    while(current) {
        if(key == current->key) {
            return current;
        }
        if(key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

template <typename TKey, typename TVal> const TVal* BSTree<TKey, TVal>::getVal(TKey key) {
    BSTree<TKey, TVal>::node* current = root;

    while(current) {
        if(key == current->key) {
            return &(current->data);
        }
        if(key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::change(TKey key, TVal data) {

    BSTree<TKey, TVal>::node** current = &root;

    while(*current) {
        if(key == (*current)->key) {
            (*current)->data = data;
            return true;
        }

        if(key < (*current)->key) {
            current = &(*current)->left;
        } else {
            current = &(*current)->right;
        }
    }
    return false;
}


template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::begin() {

    BSTree<TKey, TVal>::node* current = root;

    if(current != NULL) {
        while(current->left != NULL) current = current->left;
    }

    return iterator(current,this);

}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::begin(int start) {
    BSTree<TKey, TVal>::iterator temp = this->begin();
    int i=0;
    while(i<start && temp != this->end()) {
        temp++;
        i++;
    }
    return temp;
}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::rbegin() {

    BSTree<TKey, TVal>::node* current = root;
    
    if(current != NULL) {
        while(current->right != NULL) current = current->right;
    }

    return iterator(current,this);

}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::end() {

    return iterator(NULL,this);

}


template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::node* BSTree<TKey, TVal>::_newNode(TKey key, TVal data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

template <typename TKey, typename TVal> void BSTree<TKey, TVal>::_deleteTree(node* root) {
    if(root != NULL) {
        _deleteTree(root->left);
        _deleteTree(root->right);
        delete root;
    }
}

template <typename TKey, typename TVal> void BSTree<TKey, TVal>::_printInOrder(node* root) {
    if(root != NULL) {
        _printInOrder(root->left);
        std::cout << root->data << " ";
        _printInOrder(root->right);
    }
}
template <typename TKey, typename TVal> void BSTree<TKey, TVal>::_printPreOrder(node* root) {
    if(root != NULL) {
        std::cout << root->data << " ";
        _printPreOrder(root->left);
        _printPreOrder(root->right);
    }
}
template <typename TKey, typename TVal> void BSTree<TKey, TVal>::_printPostOrder(node* root) {
    if(root != NULL) {
        _printPostOrder(root->right);
        _printPostOrder(root->left);
        std::cout << root->data << " ";
    }
}

template <typename TKey, typename TVal> const TVal BSTree<TKey, TVal>::iterator::get() {
    return currentNode->data;
}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator& BSTree<TKey, TVal>::iterator::operator= (const iterator& rhs) {

    this->currentNode = rhs.currentNode;
    this->tree = rhs.tree;
    return *this;

}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator& BSTree<TKey, TVal>::iterator::operator++ () {

    if(currentNode == NULL) {
            currentNode = tree->root;

            while( currentNode->left != NULL)  currentNode =  currentNode->left;

    } else {

        if(currentNode->right != NULL) {
            currentNode = currentNode->right;
            while(currentNode->left != NULL) {
                currentNode = currentNode->left;
            }

        } else {
            BSTree<TKey, TVal>::node* parent = currentNode->parent;
            while(parent != NULL && currentNode != parent->left) {
                currentNode = parent;
                parent = parent->parent;
            }
            currentNode = parent;
        }
    }


    return *this;
}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::iterator::operator++ (int) {

    BSTree<TKey, TVal>::iterator temp = *this;
    
    if(currentNode == NULL) {
            currentNode = tree->root;

            while( currentNode->left != NULL)  currentNode =  currentNode->left;

    } else {

        if(currentNode->right != NULL) {
            currentNode = currentNode->right;
            while(currentNode->left != NULL) {
                currentNode = currentNode->left;
            }

        } else {

            BSTree<TKey, TVal>::node* parent = currentNode->parent;
            while(parent != NULL && currentNode != parent->left) {
                currentNode = parent;
                parent = parent->parent;
            }
            currentNode = parent;
        }
    }


    return temp;
}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator& BSTree<TKey, TVal>::iterator::operator-- () {

    if(currentNode == NULL) {
            currentNode = tree->root;

            while( currentNode->right != NULL)  currentNode =  currentNode->right;

    } else {

        if(currentNode->left != NULL) {
            currentNode = currentNode->left;
            while(currentNode->right != NULL) {
                currentNode = currentNode->right;
            }

        } else {
            BSTree<TKey, TVal>::node* parent = currentNode->parent;
            while(parent != NULL && currentNode != parent->right) {
                currentNode = parent;
                parent = parent->parent;
            }
            currentNode = parent;
        }
    }


    return *this;
}

template <typename TKey, typename TVal> typename BSTree<TKey, TVal>::iterator BSTree<TKey, TVal>::iterator::operator-- (int) {

    BSTree<TKey, TVal>::iterator temp = *this;

    if(currentNode == NULL) {
            currentNode = tree->root;

            while( currentNode->right != NULL)  currentNode =  currentNode->right;

    } else {

        if(currentNode->left != NULL) {
            currentNode = currentNode->left;
            while(currentNode->right != NULL) {
                currentNode = currentNode->right;
            }

        } else {
            BSTree<TKey, TVal>::node* parent = currentNode->parent;
            while(parent != NULL && currentNode != parent->right) {
                currentNode = parent;
                parent = parent->parent;
            }
            currentNode = parent;
        }
    }


    return temp;
}


template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::iterator::operator== (const BSTree<TKey, TVal>::iterator& rhs) const {
    return this->currentNode == rhs.currentNode;
}
template <typename TKey, typename TVal> bool BSTree<TKey, TVal>::iterator::operator!= (const BSTree<TKey, TVal>::iterator& rhs) const {
    return this->currentNode != rhs.currentNode;
}
template <typename TKey, typename TVal> const typename BSTree<TKey, TVal>::node& BSTree<TKey, TVal>::iterator::operator* () const {
    return *(this->currentNode);
}


template class BSTree<int, int>;
template class BSTree<int, const char*>;

template class BSTree<char, int>;
template class BSTree<char, const char*>;

template class BSTree<const char*, int>;
template class BSTree<const char*, const char*>;

template class BSTree<float, const char*>;

