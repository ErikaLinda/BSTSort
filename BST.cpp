
#include<iostream>
using namespace std;

template <typename S>
class Node{
public:
    S key;
    Node<S> *left, *right, *parent;
};

template <typename T>
class BST{
    private:
        Node<T> *root;
        Node<T> *current = nullptr;
        Node<T>* NewNode(T key, Node<T> *parent);
        int height(Node<T> *n);
        void printPreorder(Node<T> *n);
        void deleteNode(Node<T>* n);
        void printInorder(Node<T> *n);
    public:
        BST();
        ~BST();
        void insert(T key);
        void remove(T key);
        Node<T>* find(T key);
        void printPreorder();
        int depth();
        void printInorder();
};

//constructor
template <typename T>
BST<T>::BST(){
    root = nullptr;
}

//destructor
template <typename T>
BST<T>::~BST(){
    deleteNode(root);
}

//private function that recursively deletes the a node all it's sub-trees
template <typename T>
void BST<T>::deleteNode(Node<T>* n){
    if(n != nullptr){
        deleteNode(n->left);
        deleteNode(n->right);
        delete n;}
}

//private function that creates a new BST node
template <typename T>
Node<T>* BST<T>::NewNode(T key, Node<T> *anc){
    Node<T> *newN = new Node<T>;
    newN->key = key;
    newN->left = nullptr;
    newN->right = nullptr;
    newN->parent = anc;
    return newN;
}

//public function that inserts new nodes
template <typename T>
void BST<T>::insert(T key) {
    //if the tree is empty, then initialize it
    if (root == nullptr)
        root = NewNode(key, nullptr);

    //if the key is already in the tree
    else if (current->key == key)
        cout<<key<<" is already in the tree."<<endl;

    //continue search in the right sub-tree
    else if(current->key < key){
        if(current->right == nullptr)
            current->right = NewNode(key, current);
        else{
            current = current->right;
            return insert(key);}
    }

    //continue search in the left sub-tree
    else {
        if (current->left == nullptr)
            current->left = NewNode(key, current);
        else{
            current = current->left;
            return insert(key);}
    }
    current = root; //reset the pointer that traverses the tree
}

//public function that removes node with the given key from the tree
template <typename T>
void BST<T>::remove(T key){
    Node<T> * item = find(key);

    //if item is not in the tree
    if (item == nullptr) return;

    //if item is a leaf
    if (item->left == nullptr && item->right == nullptr){
        if (key == root->key)
            root = current = nullptr;
        else if (item->parent->left == item)
            item->parent->left = nullptr;
        else
            item->parent->right = nullptr;
    }
    //if item has only left child
    else if(item->right == nullptr){
        //if item is the root
        if (item->parent == nullptr) {
            root = item->left;
            root->parent = nullptr;
            current = root;} //reset the traversing variable in for next find() call
        //if item is not a root
        else{
            if (item->parent->left == item)
                item->parent->left = item->left;
            else
                item->parent->right = item->left;
            item->left->parent  = item->parent;}
    }
    //if item has only right child or both children
    else{
        Node<T> *item2 = item->right;
        //find the successor in the right sub-tree of the item
        while(item2->left != nullptr)
            item2 = item2->left;
        swap(item->key,item2->key); //swap values

        //delete node that held the successor value
        if(item2->right != nullptr){
            if (item2->parent->left == item2)
                item2->parent->left = item2->right;
            else
                item2->parent->right = item2->right;
            item2->right->parent  = item2->parent;}
        else{
            if (item2->parent->left == item2)
                item2->parent->left = nullptr;
            else
                item2->parent->right = nullptr;}

        item = item2;
    }
    cout<<item->key<<" was removed."<<endl;
    delete item;
}

//finds node with the given key
template <typename T>
Node<T>* BST<T>::find(T key){
    Node<T> *tmp = nullptr;
    //if pointer is null where the key should be
    if(current == nullptr)
        cout<<key<<" not found."<<endl;

    //when matching element has been found
    else if (current->key == key){
        tmp = current;
        cout<<key<<" was found."<<endl;}

    //continue search in right sub-tree
    else if (current->key < key){
        current = current->right;
        return find(key);}

    //continue search in left sub-tree
    else {
        current = current->left;
        return find(key);}

    current = root; //reset the traversing variable
    return tmp;
}

//private function that starts from the root and prints the tree in pre-order
template <typename T>
void BST<T>::printPreorder(Node<T> *n){
    if (n != nullptr){
        cout<<n->key<<" ";
        printPreorder(n->left);
        printPreorder(n->right);
    }
}

//public function that print tree in pre-order
template <typename T>
void BST<T>::printPreorder(){
    if(root == nullptr)
        cout<<"Tree is empty.";
    else
        printPreorder(root);
    cout<<endl;
}

//private function that determines height of any node
template <typename T>
int BST<T>::height(Node<T> *n){
    if (n == nullptr) return -1;
    int lchild = height(n->left);
    int rchild = height(n->right);
    if (lchild > rchild) return lchild+1;
    return rchild+1;
}

//public function that returns height of the root (or depth of the tree)
template <typename T>
int BST<T>::depth(){
    cout<<"Depth of the tree is "<<height(root)<<endl;
    return height(root);
}

//private function that starts from the root and prints the tree in-order
template <typename T>
void BST<T>::printInorder(Node<T> *n){
    if (n == nullptr) return;
    printInorder(n->left);
    cout<<n->key<<" ";
    printInorder(n->right);
}

//public function that prints tree in in-order
template <typename T>
void BST<T>::printInorder(){
     if(root == nullptr)
        cout<<"Tree is empty.";
    else
        printInorder(root);
    cout<<endl;
}

