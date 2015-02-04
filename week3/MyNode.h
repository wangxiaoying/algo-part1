//
//  MyNode.h
//  random-contraction
//
//  Created by Xiaoying Wang on 2/5/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#ifndef __random_contraction__MyNode__
#define __random_contraction__MyNode__

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <set>
using namespace std;

class Node{
private:
    int id;
    vector<int> linked_nodes;
    int father_node;
    vector<int> son_nodes;
    
public:
    Node(int id);
    int getDegree();
    void addLinkedNode(int new_node_id);
    void mergeNodes(Node *node);
    void changeFatherNode(int);
    void removeSelfLoop();
    void showStatus();
};

const int COUNTS = 200;
//const int COUNTS = 5;
extern vector<Node*> g_Graph;
extern vector<Node*> g_ConstGraph;
extern int g_ans;
extern vector<int> g_Remain;


#endif /* defined(__random_contraction__MyNode__) */
