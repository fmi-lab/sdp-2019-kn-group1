#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Graph {
    vector<int> vertexes;
    vector<vector<int>> lists;
    
    int index_of(int v) {
        for(int i = 0; i < vertexes.size(); i++) {
            if(vertexes[i] == v) {
                return i;
            }
        }
        return -1;
    }
    
public:
    bool has_vertex(int v) {
        return index_of(v) >= 0;
    }

    void add_vertex(int v) {
        if(!has_vertex(v)) {
            vertexes.push_back(v);
            lists.push_back(vector<int>());
        }
    }
    
    void add_edge(int a, int b) {
        add_vertex(a);
        add_vertex(b);
        lists[index_of(a)].push_back(b);
    }
}