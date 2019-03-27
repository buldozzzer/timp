#include "task2-2.h"

using namespace std;



int Parent(int i)
{
    return i/2;
}

int Left(int i)
{
    return 2*i;
}

int Right(int i)
{
    return (2*i+1);
}

Heap::Heap()
{

}

int Heap::HeapSize()
{
    return v.size();
}

void Heap::Heapify(int i){
    int l = Left(i);
    int r = Right(i);
    int largest;
    if ((l <= HeapSize()) && (v[l] > v[i]))
        largest = l;
    else
        largest = i;
    if ((r <= HeapSize()) && (v[r] > v[largest]))
        largest = r;
    if (largest != i)
    {
        int tmp = v[i];
        v[i] = v[largest];
        v[largest] = tmp;
        Heapify(largest);
    }
}


void Heap::Add(int value){
    v.push_back(value);
    int i = HeapSize() - 1;
    /*int parent = Parent(i);
    while (i > 0 && v[parent] < v[i])
    {
        int temp = v[i];
        v[i] = v[parent];
        v[parent] = temp;
        i = parent;
        parent = (i - 1) / 2;
    }*/
}

int Heap::ExtractMax(){
    if (HeapSize() < 0)
        cout << "Error" << endl;
    int max = v[0];
    v[0] = v[HeapSize() - 1];
    v.pop_back();
    return max;
}

void Heap::HeapSort(){
    int i = HeapSize() - 1;
    int parent = Parent (i);
    while (i > 0 && v[parent] < v[i])
    {
        int temp = v[i];
        v[i] = v[parent];
        v[parent] = temp;
        i = parent;
        parent = Parent(i - 1);
    }
}

void Heap::Print(){
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void Heap::HeapSorter() {
    BuildHeap();
    for (int i = (HeapSize()-1) / 2; i > 1; i--){
        int tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;
        Heapify(0);
    }

}

void Heap::BuildHeap() {
    for (int i=(HeapSize()-1)/2; i>0; i--)
        Heapify(i);
}
