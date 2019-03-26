#ifndef BINARY_HEAP_BINARYHEAP_H
#define BINARY_HEAP_BINARYHEAP_H

#endif //BINARY_HEAP_BINARYHEAP_H

#include <iostream>
#include <cstdlib>
#include<vector>

using namespace std;

template <typename T>
class Element{
protected:
    Element* _right; // правый ребёнок
    Element* _left;  // левый ребёнок
    Element* _parent;// родитель
    int _key;
    T _value;
public:
    Element(){
        _right(nullptr);
        _left(nullptr);
        _parent(nullptr);
    }
    Element(T& tmp, int& key){
        _right(nullptr);
        _left(nullptr);
        _parent(nullptr);
        _value(tmp);
        _key(key);
    }
    Element(T& tmp, int& key, Element* parent){
        _right(nullptr);
        _left(nullptr);
        _parent(parent);
        _value(tmp);
        _key(key);
    }
    Element getKey(){
        return _key;
    }
    Element* Left(){
        return _left;
    }
    Element* Right(){
        return _right;
    }
    Element* Parent(){
        return _parent;
    }
};
template <typename T>
class Heap : Element<T>{
private:
    Element<T> *_root; //корень
    Element<T> *_last;
    size_t _size;
public:
    Heap(){
        _size = 0;
    }
    Heap(int& key, T& value){
        _size = 1;
        _root = new Element<T>(key, value);
    }
    vector<bool> To_Bin(int n);
    void Inseret(int& key, T& value);
    void Heap_Extract_Max();
    void Heap_Sort();
    int Heap_Size(){
        return _size;
    }

};

template<typename T>
void Heap<T>::Inseret(int& key, T& value){
    ++_size;
    if(_size == 1){
        Element<T> temp(key, value);
        _root = &temp;
    }
    else
    {
        Element<T>* temp = _root;
        vector<bool> vecPath = to_bin(_size);
        for (int i = vecPath.size() - 2; i > 0; --i) {
            if (vecPath[i])
                temp = temp->_right;
            else
                temp = temp->_left;
        }
        Element<T> new_element(key, value, temp);
        if(vecPath[0])
            temp->_right = &new_element;
        else
            temp->_left = &new_element;
    }
}

template<typename T>
vector<bool> Heap<T>::To_Bin(int n) {
    vector<bool> vec;
    while (n>0) {
        vec.push_back(n % 2);
        n/=2;
    }
    return vec;
}
