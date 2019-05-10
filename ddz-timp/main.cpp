/*#include "dfs.h"

int main(){
    graph g(10);
    srand(time(0));
    string s="";
    unsigned int start_time =  clock();
    g.dfs(s);
    unsigned int end_time =  clock();
    unsigned int search_time =  end_time - start_time;
    cout << "runtime: " << search_time/1000. << endl;
    int a=0, b=0;
    for(auto i: s){
        if (i=='<')
            a++;
        if (i=='>')
            b++;
    }
    cout << a << ' ' << b << endl;
    return 0;
}*/