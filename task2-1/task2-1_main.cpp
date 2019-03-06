#include <iostream>
#include "task2-1.h"

using namespace std;

int main(){

    char choice='1';
    Stack<int> stack;
    do{
        try {
            cout << "1. PUSH" << endl;
            cout << "2. POP" << endl;
            cout << "3. SIZE" << endl;
            cout << "4. CLEAR" << endl;
            cout << "5. PRINT" << endl;
            cout << "0. EXIT" << endl;
            cout << "Select menu item: ";
            cin >> choice;
            switch (choice) {
                case '1': {
                    int tmp;
                    cout << "Enter item: ";
                    cin >> tmp;
                    stack.push(tmp);
                }
                    break;
                case '2': {
                    stack.pop();
                }
                    break;
                case '3': {
                    cout << stack.size() << endl;
                }
                    break;
                case '4': {
                    stack.clear();
                    cout << "Stack is empty" << endl;
                }
                    break;
                case '5': {
                    stack.print();
                }
                    break;
                default:
                    cout << "Try again." << endl;
            }
        }
        catch(const char* ex ){
            cout << ex << endl;
        }

    }while(choice!='0');
    return 0;
}