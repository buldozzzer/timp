#include "task2-2.h"

using namespace std;

int main()
{
    int choice;
    Heap heap;
    do
    {
        cout << "1. adding a key element" << endl;
        cout << "2. extract the element with the maximum key value" << endl;
        cout << "3. sorting of items based on the heap" << endl;
        cout << "0. exit" << endl;
        cout << "select menu item: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int value;
                cout << endl << "entered value: ";
                cin >> value;
                heap.Add(value);
            }
                break;
            case 2:
            {
                int result = heap.ExtractMax();
                cout << result << endl;
            }
                break;
            case 3: {
                heap.HeapSort();
                heap.Print();
            }
                break;
            case 4:
            {
                heap.Print();
            }
            break;
            case 5:
            {
                heap.HeapSorter();
            }
                break;
            default:
                cout << "try again" << endl;
        }
    } while (choice != 0);
    system("pause");
    return 0;
}

