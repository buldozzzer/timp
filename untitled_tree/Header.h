//
// Created by Ivan on 25.03.2019.
//

#ifndef UNTITLED_TREE_HEADER_H
#define UNTITLED_TREE_HEADER_H

#endif //UNTITLED_TREE_HEADER_H
#include<iostream>

using namespace std;

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

class Heap {
private:
    Node *_root;
public:
    Heap(){
        _root = nullptr;
    }
    Node** getRoot(){
        return &(_root);
    }
    Node *Tree(int, Node**);
    void print(Node** , int);
};

Node *Heap::Tree(int n, Node** p) {
    Node* now;
    int x, nl, nr;
    now = *p;
    if (n == 0)
        *p = nullptr;
    else{
        nl = n/2;
        nr = n - nl - 1;
        cin >> x;               //ключ узла
        now = new Node();
        now->_key = x;
        Tree(nl, &((*now)._left));
        Tree(nr, &((*now)._right));
        *p = now;
    }
}
void Heap::print(Node ** w, int l) {
    if  (*w!= nullptr)
    {
        print (&((**w)._right),l+1);
        for  (int i=1; i<=l; i++)
            cout<<"   ";
        cout<<(**w)._key<<endl;
        print (&((**w)._left),l+1);
    }
}