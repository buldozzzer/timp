#ifndef DDZ_TIMP_DDZ_H
#define DDZ_TIMP_DDZ_H

#endif //DDZ_TIMP_DDZ_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class graph{
private:
    vector <vector <bool>> g;
    vector<int> color;                  //цвет вершины (0-белый, 1-серый, 2-чёрный)
    vector<int> time_in, time_out;      //"времена" захода и выхода из вершины
public:
    graph(int n){
        g.reserve(n);

        for (int i=0; i<n; i++) {
            g.push_back(vector<bool>(n));
        }

        srand(time(NULL));

        for (int i = 0; i < n; i++){
            g[i][i] = 0;
            for (int j = i+1; j < n; j++){
                g[i][j] = rand()%2;
                g[j][i] = g[i][j];
            }
        }
        vector<int> _color(n);
        color=_color;
        time_in.reserve(n);
        time_out.reserve(n);
    }

    void dfs(string& s){
        for (auto i : g) {
            for (auto j : i) {
                color[j] = 0;
            }
        }

        static int timer = 0;

        for (auto i : g) {
            for (int j = 0; j != i.size(); ++j) {
                if (color[j] == 0)
                    dfs_visit(j, timer, s);
            }
        }
    }

    void dfs_visit(int v, int& timer, string& s){
        time_in[v] = timer++;

        color[v]=1;

        s+="<";

        for(int i= 0; i!=g[v].size(); ++i) {
            if (g[v][i] == 1) {
                if (color[i] == 0) {
                    dfs_visit(i, timer, s);
                }
            }
        }

        color[v]=2;

        time_out[v]=timer++;

        s+=">";
    };
    void getColor(){
        for (auto i: color)
            cout << i << ' ';
    }
};