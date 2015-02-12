//
//  main.cpp
//  scc
//
//  Created by Xiaoying Wang on 2/12/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

const int SIZE = 875714;
//const int SIZE = 9;

struct Node{
    bool is_visited;
    vector<int> linked_vertices;
    vector<int> reverse_linked_vertices;
    
    Node():is_visited(false){}
};

struct Node Graph[SIZE+1];
int ReFinish[SIZE+1];
int t = 0;
int s = 0;
map<int, int> Ans;

void init(){
    for(int i = 1; i <= SIZE; ++i){
        Graph[i].is_visited = false;
    }
}

void input(){
    
    ifstream infile("/Users/momo/program/algo-part1/week4/SCC.txt");
//    ifstream infile("/Users/momo/program/algo-part1/week4/test.txt");
    if(!infile) exit(-1);
    int head, tail;
    
    while(infile>>head){
        infile>>tail;
        Graph[head].linked_vertices.push_back(tail);
        Graph[tail].reverse_linked_vertices.push_back(head);
    }
    
}

void reverseDfs(int node){
    Graph[node].is_visited = true;
    int tmp_id;
    for(int i = 0; i < Graph[node].reverse_linked_vertices.size(); ++i){
        tmp_id = Graph[node].reverse_linked_vertices[i];
        if(!Graph[tmp_id].is_visited){
            reverseDfs(tmp_id);
        }
    }
    t++;
    ReFinish[t] = node;
}

void dfs(int node){
    Graph[node].is_visited = true;
    Ans[s]++;
    int tmp_id;
    for(int i = 0; i < Graph[node].linked_vertices.size(); ++i){
        tmp_id = Graph[node].linked_vertices[i];
        if(!Graph[tmp_id].is_visited){
            dfs(tmp_id);
        }
    }
}


void dfsLoop(bool is_reverse){
    
    for(int i = SIZE; i > 0; --i){
        if(is_reverse && !Graph[i].is_visited) reverseDfs(i);
        else if(!is_reverse){
            s = ReFinish[i];
            if(!Graph[s].is_visited) dfs(ReFinish[i]);
        }
    }
    
}

int cmp(int a, int b){
    return a > b;
}

void output(){
    vector<int> ans_count;
    for(map<int, int>::iterator iter = Ans.begin(); iter != Ans.end(); ++iter){
        ans_count.push_back(iter->second);
    }
    sort(ans_count.begin(), ans_count.end(), cmp);
    for(int i = 0; i < ans_count.size(); ++i){
        if(i > 4) break;
        cout<<i+1<<": "<<ans_count[i]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    
    init();
    input();
    
    dfsLoop(true);
    init();
    dfsLoop(false);
    
    output();
    
    return 0;
}
