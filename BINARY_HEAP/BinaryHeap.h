
#ifndef BINARY_HEAP_BINARYHEAP_H
#define BINARY_HEAP_BINARYHEAP_H

#endif //BINARY_HEAP_BINARYHEAP_H

#include <iostream>
#include <cstdlib>
#include<vector>

using namespace std;

/*template <typename T>
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
    void Max_Hepifi(Element<T>* A, int key);
};*/

template<typename T>
struct Node{
    Node* _right; // правый ребёнок
    Node* _left;  // левый ребёнок
    Node* _parent;// родитель
};

template <typename T>
class Heap{
private:
    Node<T> *_root; //корень
    Node<T> *_last;
    size_t _size;
public:
    Heap(){
        _size = 0;
    }
    Heap(int& key, T& value){
        _size = 1;
        _root = new Node<T>(key, value);
    }

    void Inseret(int& key, T& value, Node<T>* node);
    void Heap_Extract_Max();
    void Heap_Sort();
    int Heap_Size(){
        return _size;
    }

};

template<typename T>
void Heap<T>::Inseret(int& key, T& value, Node<T>* node){
    if (this->_root == NULL){
        this->_root = node;
        this->_last = node;
        node->_parent = NULL;
        node->_left = NULL;
        node->_right = NULL;
        return;
    }
    // Начните с текущего последнего узла и
    // двигайтесь вверх до тех пор, пока
    // _parent существует,
    // и текущий узел является его правым дочерним узлом.
    Node<T>* tmp = _last;
    while(tmp->_parent!= NULL && tmp == tmp->_parent->_right){
        tmp = tmp->_parent;
    }
    if (tmp->_parent != NULL){
        if (tmp->_parent->_right != NULL){
            // Родитель имеет правого ребенка.
            // Присоединить новый узел к
            // самому левому узлу родительского правого поддерева.
            tmp->_parent->_right;
            while (tmp->_left != NULL){
                tmp = tmp->_left;
            }
        } else {
            // Родитель не имеет права на ребенка.
            // Это может произойти только тогда, когда
            // последний узел является правым дочерним узлом.
            // Новый узел может стать правым ребенок.
            tmp = tmp->_parent;
        }
    } else {
        // Мы достигли корня. Новый узел будет на новом уровне,
        // левый дочерний элемент текущего самого левого узла.
        while(tmp->_left != NULL){
            tmp = tmp->_left;
        }
    }
    // Это узел, ниже которого мы будем вставлять. У него либо нет
    // детей, либо только левый ребенок.
    assert(tmp->_right == NULL);
    // Вставьте новый узел, который станет новым последним узлом.
    this->_root = node;
    if(tmp->_left != NULL)
        tmp->_right = node;
    else
        tmp->_left = node;
    node->_parent = tmp;
    node->_left = NULL;
    node->_right = NULL;

    // Восстановить свойство кучи
    while (node->parent !=  NULL && )
}