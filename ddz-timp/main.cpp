#include "ddz.h"

int main(){
    graph g(100000);
    srand(time(0));
    unsigned int start_time =  clock();
    g.dfs();
    unsigned int end_time =  clock();
    unsigned int search_time =  end_time - start_time;
    cout << "runtime: " << search_time/1000. << endl;
    //g.print();
    return 0;
}