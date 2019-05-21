#ifndef MSD_SORT_TASK2_4_H
#define MSD_SORT_TASK2_4_H

#endif //MSD_SORT_TASK2_4_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <iterator>
using namespace std;
void msd_radix_sort(vector<int>::iterator first, vector<int>::iterator last, int msb=31) {
    if (first != last && msb >= 0) {
        auto mid = std::stable_partition(first, last, [msb](int value) {
            if (msb == 31)
                return (value < 0);
            else
                return !(value & (1 << msb));
        });
        msb--;
        msd_radix_sort(first, mid, msb);
        msd_radix_sort(mid, last, msb);
    }
}
/*void msd_radix_sort(vector<string>::iterator first, vector<string>::iterator last, int msb=7) {
    if(first != last && msb>=0){
        auto mid = std::stable_partition(first, last, [msb](string value) {
            if (msb == 7)
                return (value < 97);
            else
                return !(value & (1 << msb));
        });
        msb--;
        msd_radix_sort(first, mid, msb);
        msd_radix_sort(mid, last, msb);
    }
}*/

vector<int> sort(vector<int> old) {
    for (int shift = 4; shift >= 0; shift--) {
        vector<int> tmp(old.size());
        int j = 0;
        for (int i = 0; i < old.size(); i++) {
            bool move = old[i] << shift >= 0;
            if (shift == 0 ? !move : move) {
                tmp[j] = old[i];
                j++;
            } else {
                old[i - j] = old[i];
            }
        }
        for (int i = j; i < tmp.size(); i++) {
            tmp[i] = old[i - j];
        }
        old = tmp;
    }
    return old;
}