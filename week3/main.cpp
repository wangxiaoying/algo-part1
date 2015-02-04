//
//  main.cpp
//  random-contraction
//
//  Created by Xiaoying Wang on 2/4/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include "MyNode.h"

vector<Node*> g_Graph;
vector<Node*> g_ConstGraph;
int g_ans = COUNTS*COUNTS;
vector<int> g_Remain;

void debugShow(){
    cout<<"show show show status!!!!!"<<g_Remain.size()<<endl;
    for(int i = 1; i <= COUNTS; ++i){
        g_Graph[i]->showStatus();
    }
    
    cout<<"end end end show status-----"<<endl;
}

void input(){
    ifstream infile("/Users/momo/program/algo-part1/week3/kargerMinCut.txt");
//    ifstream infile("/Users/momo/program/algo-part1/week3/test.txt");
    if(!infile) exit(-1);
    
    int tmp;
    for(int i = 1; i <= COUNTS; ++i){
        while(infile >> tmp && 0 != tmp){
            if(i == tmp) continue;
            g_ConstGraph[i]->addLinkedNode(tmp);
        }
    }
}

void init(){
    g_ConstGraph.push_back(new Node(0));
    for(int i = 1; i <= COUNTS; ++i){
        g_ConstGraph.push_back(new Node(i));
    }
}

void reInit(){
    for(int i = 0; i < g_Graph.size(); ++i){
        delete(g_Graph[i]);
    }
    g_Graph.clear();
    
    for(int i = 0; i < g_ConstGraph.size(); ++i){
        Node *new_node = new Node(*g_ConstGraph[i]);
        g_Graph.push_back(new_node);
    }
    
    g_Remain.clear();
    for(int i = 1; i <= COUNTS; ++i){
        g_Remain.push_back(i);
    }
}

void randomContraction(){
    srand(5+rand() + (unsigned int)time(NULL));
    
    for(int i = 0; i < COUNTS - 2; ++i){
        int index1 = g_Remain[rand() % (COUNTS - i)];
        for(vector<int>::iterator iter = g_Remain.begin(); iter != g_Remain.end(); ++iter){
            if(index1 == *iter){
                g_Remain.erase(iter);
                break;
            }
        }
        int index2 = g_Remain[rand() % (COUNTS - i - 1)];
        
        g_Graph[index2]->mergeNodes(g_Graph[index1]);
//        debugShow();
    }
    
    int this_ans = g_Graph[g_Remain[0]]->getDegree();
    if(this_ans < g_ans){
        g_ans = this_ans;
        cout<<"new best: "<<g_ans<<endl;
    }
}



int main(int argc, const char * argv[]) {
    init();
    input();
    
    while(true){
        reInit();
        randomContraction();
    }
    
    
    return 0;
}
