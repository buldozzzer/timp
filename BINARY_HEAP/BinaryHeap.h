#ifndef BINARY_HEAP_BINARYHEAP_H
#define BINARY_HEAP_BINARYHEAP_H

#endif //BINARY_HEAP_BINARYHEAP_H

#include <iostream>
#include <cstdlib>

class Heap{
private:
    struct Node{
        Node *parent;
        Node *left;
        Node *right;
    };
    Node *root;
    int key;
    int value;
public:
    Heap();

};