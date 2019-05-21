#include "task2-5.h"
#include <fstream>
int main() {
    fstream in;
    in.open("../list.txt");
    string s;
    in >> s;
    graph g(s);
    string tmp="";
    g.dfs(tmp);
    int a=0, b=0;
    for (int i=0; i<tmp.size(); ++i){
        if(tmp[i]=='<')
            ++a;
        if(tmp[i]=='>')
            ++b;
    }
    cout << a << ' ' << b << endl;
    return 0;
}