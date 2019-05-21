#define CATCH_CONFIG_MAIN
#include <iostream>
#include "dfs.h"
#include <fstream>
#include "catch.hpp"

TEST_CASE("1"){
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
    g.get_time();
    cout << a << ' ' << b << endl;
    REQUIRE(a==b);
}
TEST_CASE("2"){
    fstream in;
    in.open("../list.txt");
    string s;
    in >> s;
    graph g(s);
    string tmp="";
    g.dfs(tmp);
    vector<int> color = g.get_color();
    for(auto i:color){
        REQUIRE(i==2);
    }
}