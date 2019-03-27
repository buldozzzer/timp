//
// Created by Ivan on 25.03.2019.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#endif //UNTITLED_TREE_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
struct Node{
    Node *_parent;
    Node *_left;
    Node *_right;

    int _key;
    T _value;
    Node();
    Node(int, int);
    Node(int, int, Node*);
};
template <typename T>
Node<T>::Node(int key, int value) {
    _parent=nullptr;
    _left=nullptr;
    _right=nullptr;
    _key=key;
    _value=value;
}
template <typename T>
Node<T>::Node(int key, int value, Node<T>* parent) {
    _parent=parent;
    _left=nullptr;
    _right=nullptr;
    _key=key;
    _value=value;
}

template<typename T>
Node<T>::Node() {
    _parent= nullptr;
    _left=nullptr;
    _right=nullptr;
    _key=0;
    _value=0;
}


template <typename T>
class Heap{
private:
    Node<T>* root;
    size_t size;
    vector<bool> to_bin(int);
public:
    Heap();
    void insert(int key, int value);
    void heapify(Node<T>* &node);
    pair<int, T> extract();
    void swap(Node<T>* &first, Node<T>* &second);
    vector<pair<int,T>> heapsort(vector<pair<int,T>>);
};

template <typename T>
Heap<T>::Heap() {
    root = new Node<T>();
    size = 0;
}
template <typename T>
vector<bool> Heap<T>::to_bin(int n) {
    vector<bool> vec;
    while (n>0) {
        vec.push_back(n % 2);
        n/=2;
    }
    return vec;
}
template <typename T>
void Heap<T>::insert(int key, int value) {
    size++;
    if(size == 1) {

        Node<T>* node = new Node<T>(key, value);
        root = node;
    }
    else {
        Node<T> *node = root;
        vector<bool> vecPath = to_bin(size);
        for (int i = vecPath.size() - 2; i > 0; --i) {
            if (vecPath[i] == 1)
                node = node->_right;
            else
                node = node->_left;
        }

        Node<T>* new_node = new Node<T>(key, value, node);
        if (vecPath[0] == 1)
            node->_right = new_node;
        else
            node->_left = new_node;

        while(new_node->_parent != nullptr){
            if(new_node->_key > new_node->_parent->_key){
                swap(new_node, new_node->_parent);
                new_node = new_node->_parent;
            }
            else
                break;
        }
    }
}
template <typename T>
void Heap<T>::heapify(Node<T>* &node)
{
    Node<T>* l = node->_left;
    Node<T>* r = node->_right;
    Node<T>* largest = new Node<T>();
    if (l!= nullptr || r!= nullptr) {
        if(l != nullptr) {
            if (l->_key > node->_key) {
                largest = l;
            } else {
                largest = node;
            }
        }
        if(r != nullptr) {
            if (r->_key > largest->_key) {
                largest = r;
            }
        }
        if (largest->_key != node->_key) {
            swap(largest, node);
            heapify(largest);
        }
    }
    else{
        return;
    }
}

template<typename T>
pair<int, T> Heap<T>::extract() {
    if(size <= 1){
        if(size == 0){
            throw "Heap is empty";
        }
        else {
            int key = root->_key;
            T val = root->_value;
            Node<T> *node = root;
            delete node;
            size--;
            //cout << key << ' ';
            return make_pair(key, val);
        }
    }
    else {
        int key = root->_key;
        T val = root->_value;

        root->_key = INT32_MIN;
        Node<T>* node = root;

        vector<bool> vecPath = to_bin(size);

        for (int i = vecPath.size() - 2; i > 0; --i) {
            if (vecPath[i] == 1)
                node = node->_right;
            else
                node = node->_left;
        }
        bool flag;
        if(node->_right != NULL) {
            node = node->_right;
            flag = true;
        }
        else {
            node = node->_left;
            flag = false;
        }
        swap(root, node);
        size--;
        Node<T>* parent = node->_parent;

        if(flag){
            parent->_right = nullptr;
        }
        else{
            parent->_left = nullptr;
        }
        delete node;
        heapify(root);
        //cout << val << ' ';
        return make_pair(key, val);
    }
}

template<typename T>
void Heap<T>::swap(Node<T>* &first, Node<T>* &second) {
    int tmp_key = first->_key;
    first->_key = second->_key;
    second->_key = tmp_key;

    T tmp_val = first->_value;
    first->_value = second->_value;
    second->_value = tmp_val;
}

template<typename T>
vector<pair<int, T>> Heap<T>::heapsort(vector<pair<int,T>> v) {
    Heap<T> A;

    for(auto i = v.begin(); i!=v.end(); i++){
        A.insert(i->first, i->second);
    }
    vector<pair<int,T>> new_v;
    while(A.size!=0){
        new_v.push_back(A.extract());
    }
    return new_v;
}

