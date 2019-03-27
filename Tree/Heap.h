//
// Created by Ivan on 16.03.2019.
//

/*#ifndef TREE_HEAP_H
#define TREE_HEAP_H

#endif //TREE_HEAP_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
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

Node* add(Node* root, int new_key){
    Node* root2 = root;
    Node* root3 = nullptr;
    Node* tmp = new Node(new_key);
    while(root2 != nullptr) {
        root3 = root2;
        if (tmp->key < root2->key)
            root2 = root2->left;
        else
            root2 = root2->right;
    }
    tmp->parent=root3;

    tmp->left = nullptr;
    tmp->right = nullptr;

    if(new_key < root3->key)
        root3->left = tmp;
    else root3->right = tmp;
    return root;
}*/
/*void Insert(int new_value, Node* ptr){
    Node* node = new Node();
    node->value = new_value;
    if(ptr != nullptr){
        if(ptr->left != nullptr && ptr->right == nullptr){
            ptr->right = node;
            node->parent = ptr;
            node->key=ptr->key*2+1;
        }
        else {
            if (ptr->right != nullptr && ptr->left == nullptr) {
                ptr->right = node;
                node->parent = ptr;
                node->key=ptr->key*2;
            }
        }
        if(Right(ptr)!= nullptr && Left(ptr)!= nullptr && Left(ptr)->value > Right(ptr)->value){
            Node* tmp = Left(ptr);
            ptr->left = Right(ptr);
            ptr->right = Left(ptr);
            ptr->right->key+=1;
            ptr->left->key-=1;
        }
    }
    else{
        node->parent= nullptr;
        node->right= nullptr;
        node->left= nullptr;
        node->key= 1;
    }
}*/
