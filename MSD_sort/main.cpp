#include <iostream>
#include "task2-4.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    vector<int> data={4,3,5,7,6,11,13,17,15,14};
    srand(time(NULL));
    /*for(int i=0; i<15; i++)
        data.push_back(rand()%10000000);*/
    msd_radix_sort(data.begin(), data.end());
    sort(data);
    for(auto i: data)
        cout << i << ' ';
    cout << endl;
    return 0;
}