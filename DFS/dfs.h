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
#include <map>

using namespace std;

struct vertex{
    int name;
    int color;
    int time_in;
    int time_out;
    vector<int> adj;
    vertex(){
        name=0;
        color=0;
        time_in=0;
        time_out=0;
    };
};
class graph {
private:
    map<int, vertex> g;
public:
    graph(string s) {
        stringstream ss1, ss2;
        ss1 << s;
        ss2 << s;
        while (!ss1.eof()) {
            string buf;
            getline(ss1, buf, ',');
            if (buf.size() == 1)
                g[buf[0]-97].name=buf[0];
            buf.clear();
        }
        while (!ss2.eof()) {
            string buf;
            getline(ss2, buf, ',');
            if (buf.size() == 2) {
                int i = buf[0] - 97;
                int j = buf[1] - 97;
                g[i].adj.push_back(j);
                g[i].name=i;
                g[j].adj.push_back(i);
                g[j].name=j;
            }
            buf.clear();
        }
        for (auto &i: g) {
            cout << (char)(i.first+97)<< ')' << ' ';
            for (auto &j: i.second.adj)
                cout << (char)(j+97) << ' ';
            cout << endl;
        }
    }

    void dfs(string &s) {
        static int timer = 0;
        for (auto i : g) {
            if (g[i.first].color == 0) {

                dfs_visit(i.first, timer, s);
                cout << endl;
            }
            /*for (auto &j: i.second.adj) {
                if (g[j].color == 0) {
                    dfs_visit(j, timer, s);
                    cout << endl;
                }
            }*/
        }
    }

    void dfs_visit(int v, int &timer, string &s) {
        g[v].time_in = timer++;
        g[v].color = 1;
        s += '<';
        cout << (char)(v + 97) << ' ';
        for (auto i: g[v].adj) {
            if (g[i].color == 0) {
                dfs_visit(i, timer, s);
            }
        }
        g[v].color = 2;
        g[v].time_out = timer++;
        s += '>';
    }
    void get_time(){
        for(auto i:g){
            cout << (char)(i.second.name+97) << '\t' << i.second.time_in << '\t' << i.second.time_out << endl;
        }
    }
    vector<int> get_color(){
        vector<int> color;
       for(auto i: g)
           color.push_back(i.second.color);
       return color;
    }
};