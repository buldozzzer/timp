/* 4.
 * Граф неориентированный.
 * Поиск в глубину с помощью списка смежности.
 * Выделение связных компонент.
 */
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class graph {
private:
    vector<vector<int>> g;
    vector<int> color;
    vector<int> time_in, time_out;
public:
    graph(string s) {
        stringstream ss1, ss2;
        ss1 << s;
        ss2 << s;
        int n = 0;
        while (!ss1.eof()) {
            string buf;
            getline(ss1, buf, ',');
            if (buf.size() == 1)
                    n++;
                buf.clear();
        }
        g.resize(n);
        color.resize(n);
        time_in.resize(n);
        time_out.resize(n);
        while (!ss2.eof()) {
            string buf;
            getline(ss2, buf, ',');
                if (buf.size() == 2) {
                    int i = buf[0] - 97;
                    int j = buf[1] - 97;
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
                buf.clear();
        }
        int alpha = 97;
        for (auto &i: g) {
            cout << (char) alpha << ')' << ' ';
            ++alpha;
            for (auto &j: i)
                cout << (char)(j+97) << ' ';
            cout << endl;
        }
    }

    void dfs(string &s) {
        for (int i = 0; i < g.size(); ++i) {
            color[i] = 0;
        }
        static int timer = 0;
        for (auto i : g) {
            for (auto j: i) {
                if (color[j] == 0) {
                    dfs_visit(j, timer, s);
                    cout << endl;
                }
            }
        }
    }

    void dfs_visit(int v, int &timer, string &s) {
        time_in[v] = timer++;
        color[v] = 1;
        cout << (char) (v + 97) << ' ';
        s += '<';
        for (int i: g[v]) {
            if (color[i] == 0) {
                dfs_visit(i, timer, s);
            }
        }
        color[v] = 2;
        time_out[v] = timer++;
        s += '>';
    };
   /* void get_time(){
        for (auto i:g)
    }*/
};
