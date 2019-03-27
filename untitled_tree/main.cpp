#include <iostream>
#include"tree.h"


using namespace std;

int main() {
    Heap heap;
    int prog;
    do{
        cin >> prog;
        switch(prog){
            case 1:{
                int n;   //число вершин
                cout<<"Введите количество вершин -...\n"; cin>>n;
                cout<<"Вводите ключи...\n";
                heap.Tree(n, heap.getRoot());
            }break;
            case 2:
            {
                heap.print(heap.getRoot(), 0);
            }break;
            case 3:{

            }break;
            default:
            {
                cout << "Try again" << endl;

            } break;
        }
    }while(prog!=0);
    return 0;
}