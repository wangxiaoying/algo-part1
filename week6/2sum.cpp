//
//  main.cpp
//  2sum
//
//  Created by Xiaoying Wang on 3/2/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

const int MIN = -10000;
const int MAX = 10000;

vector<long> Array;
bool Flag[2*MAX+1] = {0};
int Count = 0;

void input(){
    ifstream infile("/Users/momo/program/algo-part1/week6/2sum.txt");
    if(!infile) exit(-1);
    
    long temp = 0;
    while(infile>>temp){
        Array.push_back(temp);
    }
    
}

void twoSum(int sum){
    int i = 0, j = Array.size();
    
    while(i < j && Array[i] != Array[j]){
        int tmp = Array[i] + Array[j];
        if(sum == tmp){
            Count++;
            cout<<sum<<endl;
            break;
        }else if(sum < tmp){
            j--;
            while(Array[j] == Array[j+1]) j--;
        }else{
            i++;
            while(Array[i] == Array[i-1]) i++;
        }
    }
}


int main(){
    
    input();
    sort(Array.begin(), Array.end());
    
    for(int i = MIN; i <= MAX; ++i){
        twoSum(i);
    }
    cout<<endl<<"ans: "<<Count<<endl;
    
    return 0;
}