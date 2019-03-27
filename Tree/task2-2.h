#ifndef TREE_TASK2_2_H
#define TREE_TASK2_2_H

#endif //TREE_TASK2_2_H

#include <iostream>
#include <cstdlib>
#include <limits>
#define opportunity  Parent(ptr)->right->left == nullptr && Parent(ptr)->right->right == nullptr
using namespace std;



struct Node {
    Node(int _key) : key(_key), left(nullptr), right(nullptr), parent(nullptr){};
    Node() : key(NULL), left(nullptr), right(nullptr), parent(nullptr){};

    int key;                   // ключ узла
    Node* left;                // указатель на левого потомка
    Node* right;               // указатель на правого потомка
    Node* parent;
};

Node* Parent(Node* obj){
    return obj->parent;
}

Node* Left(Node* obj){
    return obj->left;
}

Node* Right(Node* obj){
    return obj->right;
}

//увеличение ключа элемента
void heap_increase_key(int  new_key, Node*& node){

    if (new_key < node->key)
        cout << "new key is smaller than current" << endl;


    while((Parent(node) != nullptr) && (Parent(node)->key < node->key)) {

        int tmp = node->key;
        node->key = Parent(node)->key;
        Parent(node)->key = tmp;
        node = Parent(node);

    }
}

//добавление элемента
/*Node* Insert(int new_key, Node* ptr){

    Node* node = new Node(new_key);
    if (ptr != nullptr) {
        if(ptr->left != nullptr && ptr->right != nullptr)
            ptr = ptr->left;
        if(ptr->left != nullptr && ptr->right != nullptr && opportunity)
            ptr = Parent(ptr)->right;
        if (node->key <= ptr->key) {
            if (ptr->right != nullptr) {
                ptr = ptr->left;
                node->parent = ptr;
                ptr->left = node;
            } else {
                node->parent = ptr;
                ptr->right = node;
            }
        }
        if (node->key > ptr->key) {
            if (ptr->left != nullptr) {

                node->parent = ptr;
                ptr->right = node;
            } else {
                node->parent = ptr;
                ptr->left = node;
            }
        }
    }
    while((Parent(node) != nullptr) && (Parent(node)->key < node->key)) {

        int tmp = node->key;
        node->key = Parent(node)->key;
        Parent(node)->key = tmp;
        node = Parent(node);

    }
    return node;
};*/

void max_heapifi(Node *node){

    Node* l = Left(node);
    Node* r = Right(node);
    Node* largest;
    if ((l != nullptr) && (l->key > node->key))
        largest = l;
    else largest = node;
    if ((r != nullptr) && (r->key > largest->key))
        largest = r;
    if (largest != node) {
        int tmp = node->key;
        node->key = largest->key;
        largest->key = tmp;
        max_heapifi(largest);
    }
}

Node* Insert(int new_key, Node* ptr){

    Node* node = new Node(new_key);
    if (ptr != nullptr) {
        if(ptr->left != nullptr && ptr->right != nullptr)
            ptr = ptr->left;
        if(ptr->left != nullptr && ptr->right != nullptr && opportunity)
            ptr = Parent(ptr)->right;
        if (node->key <= ptr->key) {
            if (ptr->right != nullptr) {
                ptr = ptr->left;
                node->parent = ptr;
                ptr->left = node;
            } else {
                node->parent = ptr;
                ptr->right = node;
            }
        }
        if (node->key > ptr->key) {
            if (ptr->left != nullptr) {

                node->parent = ptr;
                ptr->right = node;
            } else {
                node->parent = ptr;
                ptr->left = node;
            }
        }
    }
    while((Parent(node) != nullptr) && (Parent(node)->key < node->key)) {

        int tmp = node->key;
        node->key = Parent(node)->key;
        Parent(node)->key = tmp;
        node = Parent(node);

    }
    max_heapifi(node);
    return node;
};

//извлечение корня
Node* get_root(Node* node){

    while(Parent(node)!= nullptr) {
       node = Parent(Parent(node));
    }
    return node;

}

//построение дерева
void build_max_heap(Node* node){
    while(node->parent != nullptr){
        max_heapifi(node);
        node = Parent(node);
    }
}

//сортировка кучи
void Heapsort(Node* node){
    build_max_heap(node);
}

int Heap_Extract_Max(Node* node){
    if (node->key == NULL) {
        cout << "Heap is empty" << endl;
        return 0;
    }
    int max = (get_root(node))->key;

    return max;
}
//извлечение максимального элесента из кучи
int Heap_Print_Max(Node* node){
    if (node->key == NULL) {
        cout << "Heap is empty" << endl;
        return 0;
    }
    int max = (get_root(node))->key;

    return max;
}


