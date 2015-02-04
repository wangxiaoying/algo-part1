//
//  MyNode.cpp
//  random-contraction
//
//  Created by Xiaoying Wang on 2/5/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include "MyNode.h"

Node::Node(int id):
id(id),
linked_nodes(NULL),
father_node(id),
son_nodes(NULL){
    
}

int Node::getDegree(){
    return (int)linked_nodes.size();
}

void Node::addLinkedNode(int new_node_id){
    this->linked_nodes.push_back(new_node_id);
}

void Node::mergeNodes(Node *node){
    node->changeFatherNode(this->father_node);
    this->son_nodes.push_back(node->id);
    this->son_nodes.insert(this->son_nodes.end(), node->son_nodes.begin(), node->son_nodes.end());
    
    this->linked_nodes.insert(this->linked_nodes.end(), node->linked_nodes.begin(), node->linked_nodes.end());
    this->removeSelfLoop();
}

void Node::changeFatherNode(int father_id){
    this->father_node = father_id;
    for(vector<int>::iterator iter = son_nodes.begin(); iter != son_nodes.end(); ++iter){
        g_Graph[*iter]->father_node = father_id;
    }
}

void Node::removeSelfLoop(){
    for(vector<int>::iterator iter = linked_nodes.begin(); iter != linked_nodes.end(); ){
        if(g_Graph[*iter]->father_node == this->father_node){
            iter = linked_nodes.erase(iter);
        }else{
            ++iter;
        }
    }
}

void Node::showStatus(){

    cout<<"id: "<<id<<endl;
    cout<<"father id: "<<father_node<<endl;
    cout<<"linked node: ";
    for(int i = 0; i < linked_nodes.size(); ++i) cout<<linked_nodes[i]<<" ";
    cout<<endl;
    cout<<"son node: ";
    for(int i = 0; i < son_nodes.size(); ++i) cout<<son_nodes[i]<<" ";
    cout<<endl;
    
}