//
// Created by Ivan on 24.03.2019.
//

#ifndef UNTITLED_TREE_TREE_H
#define UNTITLED_TREE_TREE_H

#endif //UNTITLED_TREE_TREE_H

#include<iostream>
#include <vector>

using namespace std;

bool flag = true;
bool flag1 = true;

struct Node{
    int _key;
    Node* _left;
    Node* _right;
    Node* _parent;
    Node()
    {
        _left = nullptr;
        _right = nullptr;
        _parent = nullptr;
    }
};

class Tree {
private:
    Node *_root;
    vector<bool> to_bin(int);
public:
    Node* getRoot(){
        return _root;
    }
    Tree()
    {
        _root = nullptr;
    }
    void insert(int key);
    void heapify(Node* node);
    void inorder_tree_walk(Node* node);
    void heap(Node* node);
    void add(int key);
};

void Tree::add(int key){

}
void Tree::insert(int key)
{
    Node* new_node = new Node;
    new_node->_key = key;

    Node* tmp_node = nullptr;
    Node* node = _root;
    while(node != nullptr)
    {
        tmp_node = node;
        //if(key <= node->_key)
        if (flag1)
        {
            node = node->_left;
            flag1 = false;
        }
        else
        {
            node = node->_right;
            flag1 = true;
        }
    }

    if (tmp_node == nullptr)
    {
        _root = new_node;
        return;
    }
    new_node->_parent = tmp_node;


    //if (key <= tmp_node->_key)
    if (flag)
    {
        tmp_node->_left = new_node;
        flag = false;
    }
    else
    {
        tmp_node->_right = new_node;
        flag = true;
    }
}

void Tree::heapify(Node* node)
{
    Node* l = node->_left;
    Node* r = node->_right;
    Node* largest;
    if ((l != nullptr) && (l->_key > node->_key))
        largest = l;
    else largest = node;
    if ((r != nullptr) && (r->_key > largest->_key))
        largest = r;
    if (largest != node)
    {
        int tmp = node->_key;
        node->_key = largest->_key;
        largest->_key = tmp;
        heapify(largest);
    }
}


void Tree::inorder_tree_walk(Node* node) {
    if(node != nullptr){
        inorder_tree_walk(node->_left);
        cout << node->_key << endl;
        inorder_tree_walk(node->_right);
    }
}

void Tree::heap(Node *node) {
    while((node->_parent != nullptr) && (node->_parent->_key < node->_key)) {

        int tmp = node->_key;
        node->_key = node->_parent->_key;
        node->_parent->_key = tmp;
    }
}

vector<bool> Tree::to_bin(int n) {
    vector<bool> vec;
    while (n>0) {
        vec.push_back(n % 2);
        n/=2;
    }
    return vec;
}
