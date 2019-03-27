
#ifndef TASK2_1_TASK2_1_H
#define TASK2_1_TASK2_1_H

#endif //TASK2_1_TASK2_1_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack
{
private:
    struct DataElement {
        T value;
        DataElement *next;
    };
    DataElement *first;
    int top;      //number of the current stack element

public:
    Stack();
    T pop();      //push out element
    void push(T); //pop element
    void print(); //print stack
    void clear(); //delete stack
    int size();   //size of stack
};



using namespace std;
template <typename T>
Stack<T>::Stack() {
    first = NULL;
    top = 0;
}
template <typename T>
void Stack<T>::push(T value) {
    auto *d = new DataElement();
    d->value = value;
    d->next = first;
    first = d;
    top++;
}
template <typename T>
T Stack<T>::pop() {
    if (first == NULL) throw "stack is empty";
    DataElement *d = first;
    first = first->next;
    T tmp = d->value;
    top--;
    delete d;
    return tmp;
}



template <typename T>
void Stack<T>::print() {
    if (first == NULL) throw "stack is empty";
    DataElement* f = first;
    int i = 1;
    while (f != NULL) {
        cout << i << ". " << f->value << endl;
        f = f->next;
        i++;
    }
}

template <typename T>
int Stack<T>::size() {
    return top;
}

template<typename T>
void Stack<T>::clear(){
    while (first != NULL) {
        pop();
        --top;
    }
}