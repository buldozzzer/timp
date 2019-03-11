#include "BinaryHeap.h"

Heap::Heap() {
    key = 0;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
}
