//
// Created by abdo on 1/3/2023.
//

#ifndef BALANCEDSORTEDTREE_BSTREE_H
#define BALANCEDSORTEDTREE_BSTREE_H
#include <iostream>

using namespace std;
template <typename Type>
class Node{
private:
    Type data;
public:
    Node();
    Node(Type );
    Type get_data();
    void set_data(Type data);
    Node<Type> * left;
    Node<Type> * right;
    int height;
};

template <typename Type>
class BSTree {
public:Node<Type> * root;
private:
    Node<Type>* insertionBalanced(Type ,Node<Type>* );
    void showInorder(Node<Type> *);
    void showPreorder(Node<Type> *);
    void showPostorder(Node<Type> *);
    void  showNode(Node<Type> *arb,int niveau_courant);
    bool find(Type ,Node<Type> *);
    Node<Type> * minNode(Node<Type> * leaf);
    Node<Type> * deleteElement(Type , Node<Type> *);
    int depth(Node<Type> *);
    int balanceValue(Node<Type> *);
    void balanceNode(Node<Type> *);
    Node<Type>* leftRotation(Node<Type>* );
    Node<Type>* rightRotation(Node<Type>* );
    int getHeight(Node<Type> *);
public:
    BSTree();
    void insert(Type);
    void deleteElement(Type );
    bool find(Type );
    void showInorder();
    void showPreorder();
    void showPostorder();
    void showGraphicBSTree();
};


#endif //BALANCEDSORTEDTREE_BSTREE_H
