/*
 * Стек на основе статического массива.
 * Операции: добавление элемента; извлечение элемента; определение количества элементов в стеке; очистка стека.
 * Элементом данных должен быть указатель на некоторые данные.
 */

#include <iostream>
#define SIZE_STACK 20
using namespace std;


template <typename T>

class Stack
{
private:
    int _size=SIZE_STACK;
    T* _array_stack;
    int _top = 0;
public:
    Stack(){
        _array_stack=new T[_size];
    };
    Stack(T key){
        _top++;
        _array_stack=new T[_size];
        _array_stack[0]=key;
    }
    bool Push(const T);
    int Pop();
    int Size();
    void Clear();

};
template <typename T> //delete head of the stack
int Stack<T>::Pop()
{
    if(!_top)
        return false;
    _top--;
    return *(_array_stack+_top+1); // Pointer on memory
}
template <typename T>
bool Stack<T>::Push(const T element)
{
    if (_top==_size) return false ;
    _array_stack[_top]= element;
    _top++;

}
template <typename T>

int Stack<T>::Size(){
    return _top+1;
}
template <typename T>

void Stack<T>::Clear(){
    delete[] _array_stack;
    _top=-1;
}