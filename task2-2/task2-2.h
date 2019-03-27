//
// Created by Иван on 03.03.2019.
//

#ifndef TASK2_2_TASK2_2_H
#define TASK2_2_TASK2_2_H

#endif //TASK2_2_tASK2_2_H
#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Heap
{
private:
    vector<int> v;
public:
    Heap();
    int ExtractMax();
    int HeapSize();
    void Heapify(int i);
    void Add(int value);
    void HeapSort();
    void Print();
    void HeapSorter();
    void BuildHeap();
};
int Parent(int i);

int Left(int i);

int Right(int i);