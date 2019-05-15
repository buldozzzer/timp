#include <iostream>
#include <vector>
#include "task2-4.h"
#include <fstream>
using namespace std;

int main() {
    vector<int> vec_int;
    vector<string> vec_str;
    fstream in;
    in.open("C:/Users/Ivan/CLionProjects/task2-4/digits.txt");
    if(in.is_open()){
        string buf;
        while (!in.eof()){
            in >>buf;
            vec_int.push_back(stoi(buf.c_str()));
            vec_str.push_back(buf);
        }
        vector<string> true_vec_str = radix_sorter(vec_str);
        vector<int> true_vec_int = radix_sorter(vec_int);
        for (auto i: vec_str)
            cout << i << endl;
    }else{
        cout << "File isn't open" << endl;
    }
    return 0;
}