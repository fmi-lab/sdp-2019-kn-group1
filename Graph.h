#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Graph {
    vector<int> vertexes;
    vector<vector<int>> lists;
    
public:
    int index_of(int v) {
        for(int i = 0; i < vertexes.size(); i++) {
            if(vertexes[i] == v) {
                return i;
            }
        }
        return -1;
    }
    
    
}