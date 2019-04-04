#ifndef DDZ_TIMP_DDZ_H
#define DDZ_TIMP_DDZ_H

#endif //DDZ_TIMP_DDZ_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int dfs_timer = 0;                  // "таймер" для определения времён

class graph{
private:
    vector<vector<int>> g;          //граф
    int n;                          //число вершин
    vector<int> color;              //цвет вершины (0, 1, 2)
    vector<int> time_in, time_out;  //"времена" захода и выхода из вершины
public:
    void dfs(int v);
};