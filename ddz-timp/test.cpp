#define CATCH_CONFIG_MAIN
#include "C:\Users\Ivan\Desktop\catch.hpp"
#include "dfs.h"

TEST_CASE("1"){
    string s;
    graph g(10);
    g.dfs(s);
    int a=0, b=0;
    for(auto i: s){
        if (i=='<')
            a++;
        if (i=='>')
            b++;
    }
    REQUIRE(a==b);
}
TEST_CASE("2"){
    graph g(10);
    string s;
    g.dfs(s);
    g.getColor();
}
