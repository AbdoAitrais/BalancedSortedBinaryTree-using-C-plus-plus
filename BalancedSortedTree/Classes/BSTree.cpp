//
// Created by abdo on 12/20/2022.
//

#include "BSTree.h"

///

//template <typename T1, typename T2>
//bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//{
//    return (lhs.first==rhs.first);
//}

template <typename T1, typename T2>
ostream & operator<< (ostream & os, const pair<T1,T2>& hs)
{
    os << hs.first << ", " << hs.second;
    return os;
}
//
//
//template <typename T1, typename T2>
//bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//{
//    return !(lhs==rhs);
//}
//
//
//template <typename T1, typename T2>
//bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//{
//    return (lhs.first<rhs.first);
//}
//
//template <typename T1, typename T2>
//bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
//{
//    return (rhs<lhs);
//}

/// ************************** Node Implementation **************************

template <typename Type>
Node<Type>::Node(){
    data = (Type) nullptr;
    left = nullptr;
    right = nullptr;
}

template <typename Type>
Node<Type>::Node(Type data){
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template <typename Type>
Type Node<Type>::get_data(){
    return data;
}

template<typename Type>
void Node<Type>::set_data(Type data) {
    this->data = data;
}

/// ************************** BSTree Implementation **************************

template <typename Type>
BSTree<Type>::BSTree(){
    root = NULL;
}

/// ************************** Affichage **************************

template <typename Type>
void BSTree<Type>::showInorder(Node<Type> * leaf){
    if(leaf){
        showInorder(leaf->left);
        cout << leaf->get_data() << " ";
        showInorder(leaf->right);
    }
}

template <typename Type>
void BSTree<Type>::showInorder(){
    if(!root){
        cout << "L'arbre est vide" << endl;
        return;
    }
    cout << endl;
    showInorder(root);
    cout << endl;
}

template<typename Type>
void BSTree<Type>::showPreorder(Node<Type> * leaf) {
    if(leaf){
        cout << leaf->get_data() << " ";
        showInorder(leaf->left);
        showInorder(leaf->right);
    }
}

template<typename Type>
void BSTree<Type>::showPreorder() {
    if(!root){
        cout << "L'arbre est vide" << endl;
        return;
    }
    cout << endl;
    showInorder(root);
    cout << endl;
}

template<typename Type>
void BSTree<Type>::showPostorder(Node<Type> * leaf) {
    if(leaf){
        cout << leaf->get_data() << " ";
        showInorder(leaf->left);
        showInorder(leaf->right);
    }
}

template<typename Type>
void BSTree<Type>::showPostorder() {
    if(!root){
        cout << "L'arbre est vide" << endl;
        return;
    }
    cout << endl;
    showInorder(root);
    cout << endl;
}

/// ************************** Manipulation **************************

template <typename Type>
Node<Type>* BSTree<Type>::insertionBalanced(Type data,Node<Type>* leaf)
{
    if (!leaf)
    {
        return (Node<Type>*) new Node<Type>(data);
    }
    if (leaf->get_data() > data)
    {
        leaf->left = insertionBalanced(data,leaf->left);

    }
    else if (leaf->get_data() < data)
    {
        leaf->right = insertionBalanced(data,leaf->right);
    }


    int bf = balanceValue(leaf);

    if(bf > 1 && data < leaf->left->get_data())     return  rightRotation(leaf);
    if(bf < -1 && data > leaf->right->get_data())   return   leftRotation(leaf);
    if(bf > 1 && data > leaf->left->get_data())
    {
        leaf->left =  leftRotation(leaf->left);
        return rightRotation(leaf);
    }
    if(bf < -1 && data < leaf->right->get_data())
    {
        leaf->right =  rightRotation(leaf->right);
        return leftRotation(leaf);
    }
    return leaf;
}

template <typename Type>
void BSTree<Type>::insert(Type data){
    if(!root){
        root = new Node<Type>(data);
        return;
    }
    root = insertionBalanced(data,root);
}

template<typename Type>
int BSTree<Type>::depth(Node<Type> * leaf){
    if (!leaf)
        return 0;
    return max(depth(leaf->left) , depth(leaf->right)) + 1;
}

template<typename Type>
int BSTree<Type>::balanceValue(Node<Type> * leaf){
    if (!leaf)
        return -1;
    return (depth(leaf->left) - depth(leaf->right));
}

template <typename Type>
Node<Type>* BSTree<Type>::leftRotation(Node<Type>* nd)
{
    Node<Type> *x = nd->right,*y = x->left;
    x->left = nd;
    nd->right = y;
    return x;
}

template <typename Type>
Node<Type>* BSTree<Type>::rightRotation(Node<Type>* nd)
{
    Node<Type> *x = nd->left,*y = x->right;
    x->right = nd;
    nd->left =  y;
    return x;
}


/// *******************************

template<typename Type>
bool BSTree<Type>::find(Type data, Node<Type> * leaf) {
    if (leaf == NULL)
        return false;

    if(leaf->get_data() == data)
        return true;

    if(find(data, leaf->left))
        return true;

    return find(data, leaf->right);
}

template<typename Type>
bool BSTree<Type>::find(Type data) {
    if(!root){
        cout << "L'arbre est vide" << endl;
        return false;
    }
    return find(data, root);
}

///TODO:: Complete suppression function
template<typename Type>
Node<Type> * BSTree<Type>::deleteElement(Type data, Node<Type> * leaf) {
    Node<Type> * temp;
    if (!leaf) return (Node<Type> *) nullptr;
    if (data > leaf->get_data()) leaf->right = deleteElement(data, leaf->right);
    else if (data < leaf->get_data()) leaf->left = deleteElement(data, leaf->left);
    else {
        if ((!leaf->left) && (!leaf->right))
        {
            delete leaf;
            return ((Node<Type> *) nullptr);
        }
        if ((leaf->left) && (!leaf->right))
        {
            temp = leaf;
            leaf = temp->left;
            delete temp;
            return ((Node<Type>*) leaf);
        }
        if((!leaf->left) && (leaf->right))
        {
            //
            temp = leaf;
            leaf = temp->right;
            delete temp;
            return((Node<Type>*) leaf);
        }
        if((leaf->left) && (leaf->right))
        {
            temp = minNode(leaf->right);
            leaf->set_data(temp->get_data());
            leaf->right = deleteElement(leaf->get_data(),leaf->right);
            return((Node<Type>*)leaf);
        }
    }
    return leaf;
}

template<typename Type>
void BSTree<Type>::deleteElement(Type data) {
    if(!root){
        cout << "L'arbre est vide" << endl;
        return ;
    }
    root = deleteElement(data, root);
}

template<typename Type>
Node<Type> *BSTree<Type>::minNode(Node<Type> *leaf) {
    while(leaf->left) leaf = leaf->left;
    return leaf;
}

/// ************** Affichage graphique **************

template <typename Type>
void BSTree<Type>::showNode(Node<Type> *leaf,int niveau_courant)
{
    //indice pour faire les espaces entre les niveaux
    int ind;
    //s'il y a des éléments dans l'arbre
    if(leaf)
    {
        //on affiche d'abord l'arbre droit
        showNode(leaf->right,niveau_courant+1);
        // affichage des espaces entre les niveaux de l'arbre
        for (ind = 0; ind < niveau_courant; ind++)
            printf("      ");
        //affichage du noeud courant
        cout << leaf->get_data() << endl;
        //on affiche l'arbre gauche
        showNode(leaf->left,niveau_courant+1);
    } else {
        for (ind = 0; ind < niveau_courant; ind++)
            printf("      ");
        cout << "~" << endl;
    }
}

template <typename Type>
void BSTree<Type>::showGraphicBSTree()
{
    if(root)
    {
        printf("\nL'AFFICHAGE DE L'arbre\n");
        //appel de la fonction afficher_noeud avec un niveau
        //courant=0
        showNode(root,0);
        printf("\n\n");
    }
}
