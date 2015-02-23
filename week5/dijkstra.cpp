//
//  main.cpp
//  dijkstra
//
//  Created by Xiaoying Wang on 2/23/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int SIZE = 201;
const int MAX_DIST = 1000000;
const int AIM[] = {7,37,59,82,99,115,133,165,188,197};

int p[SIZE][SIZE];
int dist[SIZE];
bool visited[SIZE];

void init(){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if(i == j) p[i][j] = 0;
            else p[i][j] = MAX_DIST;
        }
        dist[i] = MAX_DIST;
        visited[i] = false;
    }
    dist[1] = 0;
    visited[1] = true;
}

void input(){
    ifstream infile("/Users/momo/program/algo-part1/week5/dijkstraData.txt");
    if(!infile) exit(-1);
    
    string line;
    while(getline(infile, line)){
        int start, end, length;
        char c;
        istringstream iss(line);
        iss>>start;
        while(iss>>end>>c>>length){
//            cout<<start<<":"<<end<<"="<<length<<endl;
            p[start][end] = length;
        }
    }
}

void output(){
    for(int i = 0; i < 10; ++i){
        cout<<dist[AIM[i]]<<",";
    }
    cout<<endl;
}

void dijkstra(){
    int vertex = 1;
    while(vertex){
        int index = 0;
        for(int i = 1; i < SIZE; ++i){
            if(visited[i]) continue;
            int tmp = dist[vertex] + p[vertex][i];
            if(dist[i] > tmp) dist[i] = tmp;
            if(dist[index] > dist[i]) index = i;
        }
        vertex = index;
        visited[vertex] = true;
    }
}

int main(int argc, const char * argv[]) {
    
    init();
    input();
    
    dijkstra();
    
    output();
    
    return 0;
}
