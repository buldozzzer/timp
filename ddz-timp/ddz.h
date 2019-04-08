#ifndef DDZ_TIMP_DDZ_H
#define DDZ_TIMP_DDZ_H

#endif //DDZ_TIMP_DDZ_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

int timer;                              // "таймер" для определения времён

class graph{
private:
    vector<vector<bool>> g;             //граф
    vector<int> color;                  //цвет вершины (0-белый, 1-серый, 2-чёрный)
    vector<int> time_in, time_out;      //"времена" захода и выхода из вершины
public:
    graph(int n){
        vector <vector <bool>> _g(n, vector<bool> (n));
        srand(time(NULL));
        for (int i = 0; i < n; i++){
            _g[i][i] = 0;
            for (int j = i+1; j < n; j++){
                _g[i][j] = rand() % 2;
                _g[j][i] = _g[i][j];
            }
        }
        g = _g;
        _g.clear();
        vector<int> _color (n);
        color = _color;
        _color.clear();
        vector<int> _time (n);
        time_out = _time;
        time_in = _time;
        _time.clear();
    }

    void dfs(){
        for (auto i : g)
            for (auto j : i)
                color[j] = 0;

        timer = 0;

        for (auto i : g)
            for (auto j = 0; j!=i.size(); ++j)
                if (color[j] == 0)
                    dfs_visit(j, timer);
    }

    void dfs_visit(int v, int timer){
        time_in[v] = timer++;

        color[v]=1;

        for(auto i=g[v].begin(); i!=g[v].end(); ++i)
            if (*i == 1)
                if (color[*i] == 0)
                    dfs_visit(*i, timer);

        color[v]=2;

        time_out[v]=timer++;
    };

    void print(){
        for (auto i : color)
            cout << i << ' ';
    }
};