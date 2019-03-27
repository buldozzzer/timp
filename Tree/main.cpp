#include <iostream>
#include "task2-2.h"
#include "Heap.h"
using namespace std;

int main() {
    Node *node = new Node();
    Node* a;
    char choice;
    do{
        cout << "Insert" << endl;
        cout << "Print max" << endl;
        cout << "Extract max" << endl;
        cout << "Sort" << endl;
        cin >> choice;
        switch(choice){
            case '1':{
                int n;
                cout << "Key: ";
                cin >> n;
                node = Insert(n, node);
            }
            break;
            case '2':{
                cout << "Max: " << Heap_Print_Max(node) << endl;
            }
            break;
            case '3':{

            }
            break;
            case '4':{
            }
            break;
            default: cout << endl << "Try again" << endl;
            break;
        }
    }while(choice != 0);
    return 0;
}