#ifndef DDZ_TIMP_DDZ_H
#define DDZ_TIMP_DDZ_H

#endif //DDZ_TIMP_DDZ_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class GraphNode{
public:
    bool New;
    vector<GraphNode> Links;
};

class Graph{
public:
    vector<GraphNode> Nodes;
};

class PathFinder{
private:
    vector<GraphNode> list;
    vector<list<GraphNode>> paths;
public:
    vector<list<GraphNode>> Find(Graph graph){
        for(auto i: graph.Nodes) {
            i = true;
        }

        list.push_back(graph.Nodes[0]);

        bool done = false;
        while(!done){
            while(list.size()>0){
                InteralFind(list[list.size()-1]);
            }
            done = true;

        }
    };
    void InternalFind(GraphNode node);
};