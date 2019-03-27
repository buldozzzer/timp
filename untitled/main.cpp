/*#include "tree.h"

using namespace std;

int main() {
    Heap<int> heap;
    int prog;
    do{
        cout << "Insert" << endl;
        cin >> prog;
        switch(prog){
            case 1:{
                cout << "Key...";
                int key;
                cin >> key;
                cout << "Value...";
                char value;
                cin >> value;
                heap.insert(key, value);
            }break;
            case 2:
            {
                heap.extract();
            }break;
            case 3:{
                int keys[] = {35, 7, 69, 100, 96, 25, 69, 15};
                int values[] = {1, 1, 1, 1, 1, 1, 1, 1};
                Heap<int> A;
                A.heapsort(keys, 8);
            }
            case 4:{
            }
            default:break;
        }
    }while(prog!=0);
    return 0;
}*/