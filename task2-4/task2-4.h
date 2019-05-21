//9. Алгоритм сортировки «поразрядная» (MSD).

#ifndef TIMP_TASK2_4_H
#define TIMP_TASK2_4_H
#endif //TIMP_TASK2_4_H
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <sstream>
#include <list>

using namespace std;

template <typename T>
deque<int> to_bin(T number);

vector<int> radix_sort(vector<int> &vec_int, int d) {
    for(int i = d; i >=1; i--) {
        vector<deque<int>> vec_count(20);
        for (int t = 0; t < vec_int.size(); t++){
            int j = vec_int[t]/pow(10, i);
            j =j % (int) pow(10, i-1);
            vec_count[j+10].push_front(vec_int[t]);
        }
        vector<int> vec_new;
        for(auto& deq: vec_count)
            while(!deq.empty()){
                vec_new.emplace_back(deq.back());
                deq.pop_back();
            }
        vec_int = vec_new;
    }
    return vec_int;
}

int get_discharge(int digit) {
    stringstream tmp;
    string str;
    tmp << abs(digit);
    tmp >> str;
    return str.size();
}


vector<vector<int>> prelim_sort(vector<int> &vecInt){
    vector<vector<int>> prelimVec(10); //вектор очередей, содержащих числа одинакового разряда
    for(auto i: vecInt)
        prelimVec[get_discharge(i)].push_back(i);
    for(auto i: prelimVec)
    i.shrink_to_fit();
    prelimVec.shrink_to_fit();
    return prelimVec;
}

vector<int> radix_sorter(vector<int> &vec_int) {
    vector<vector<int>> mod_vec = prelim_sort(vec_int);
    vector<int> vec_new;
    vector<int> vec_temp;
    vector<list<int>> bin_vec(vec_int.size());
    for(int s=1; s!=mod_vec.size(); s++) {
            vec_temp = radix_sort(mod_vec[s], 10);
        for(auto &i: vec_temp)
            vec_new.emplace_back(i);
    }
    vec_int.clear();
    vec_int=vec_new;
    return vec_int;
}
int get_max_length(vector<string> &vec_str){
    int max_length=0;
    for(int i=0; i<vec_str.size(); i++){
        if(vec_str[i].size()>max_length)
            max_length=vec_str[i].size();
    }
    return max_length;
}

vector<string> radix_sort(vector<string> &vec_str) {
    int len = get_max_length(vec_str);
    for(auto i: vec_str){
        string reverse;
        copy(i.rbegin(), i.rend(), back_inserter(reverse));
        for(int j=0; j<len-i.size(); j++)
            reverse.push_back('\t');
        i.clear();
        copy(reverse.rbegin(), reverse.rend(), back_inserter(i));
        cout << i << '|';
    }
    cout << endl;
    for(int i = 0; i < get_max_length(vec_str); i++) {
        map<int, deque<string>> mapCount;
        for (int t = 0; t < vec_str.size(); t++) {
            int j = vec_str[t][i];
            mapCount[j].push_front(vec_str[t]);
        }
        vector<string> vecNew;
        for(auto& it : mapCount)
            while(!it.second.empty()) {
                vecNew.emplace_back(it.second.back());
                it.second.pop_back();
            }
        vec_str = vecNew;
    }
    return vec_str;
}

map<int, vector<string>> prelim_sort(vector<string> &vec_str){
    map<int, vector<string>> prelimVec;
    for(auto i: vec_str)
        prelimVec[i.size()].push_back(i);
    return prelimVec;
}

vector<string> radix_sorter(vector<string> &vec_str) {
map<int, vector<string>> mod_map = prelim_sort(vec_str);
    vector<string> vec_new;
    vector<string> vec_temp;
    for(auto &i : mod_map) {
        vec_temp = radix_sort(i.second);
        for(auto &i: vec_temp)
            vec_new.emplace_back(i);
    }
    vec_str.clear();
    vec_str=vec_new;
    return vec_str;
}