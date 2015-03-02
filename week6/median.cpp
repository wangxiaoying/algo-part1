//
//  main.cpp
//  median
//
//  Created by Xiaoying Wang on 3/3/15.
//  Copyright (c) 2015 Xiaoying Wang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int SIZE = 10000;

int Min_Heap[SIZE] = {0};
int Max_Heap[SIZE] = {0};
int Min_Size = 0;
int Max_Size = 0;

int Final_Ans = 0;

void maxHeapInsert(int x){
    Max_Heap[Max_Size] = x;
    
    int index = Max_Size;
    int father;
    while(index){
        father = (index - 1) / 2;
        if(Max_Heap[index] <= Max_Heap[father]) break;
        swap(Max_Heap[index], Max_Heap[father]);
        index = father;
    }
    
    Max_Size++;
}

int maxHeapExtract(){
    if(!Max_Size) return 0;
    
    int ans = Max_Heap[0];
    Max_Size--;
    if(Max_Size){
        Max_Heap[0] = Max_Heap[Max_Size];
        int index = 0, child1, child2, temp;
        
        while(true){
            child1 = 2 * index + 1;
            child2 = 2 * index + 2;
            if(child1 >= Max_Size) break;
            if(child2 >= Max_Size) temp = child1;
            else if(Max_Heap[child1] > Max_Heap[child2]) temp = child1;
            else temp = child2;
            
            if(Max_Heap[index] >= Max_Heap[temp]) break;
            swap(Max_Heap[index], Max_Heap[temp]);
            index = temp;
        }
    }
    
    return ans;
}

void minHeapInsert(int x){
    Min_Heap[Min_Size] = x;
    
    int index = Min_Size;
    int father;
    while(index){
        father = (index - 1) / 2;
        if(Min_Heap[index] >= Min_Heap[father]) break;
        swap(Min_Heap[index], Min_Heap[father]);
        index = father;
    }
    
    Min_Size++;
}

int minHeapExtract(){
    if(!Min_Size) return 0;
    
    int ans = Min_Heap[0];
    Min_Size--;
    if(Min_Size){
        Min_Heap[0] = Min_Heap[Min_Size];
        int index = 0, child1, child2, temp;
        
        while(true){
            child1 = index * 2 + 1;
            child2 = index * 2 + 2;
            if(child1 >= Min_Size) break;
            if(child2 >= Min_Size) temp = child1;
            else if(Min_Heap[child1] <= Min_Heap[child2]) temp = child1;
            else temp = child2;
            
            if(Min_Heap[index] <= Min_Heap[temp]) break;
            swap(Min_Heap[index], Min_Heap[temp]);
            index = temp;
        }
    }
    
    return ans;
}

void twoHeapMaintain(){
    if(Min_Size - Max_Size > 1){
        maxHeapInsert(minHeapExtract());
    }else if(Max_Size - Min_Size > 1){
        minHeapInsert(maxHeapExtract());
    }
}

int getMedianNumber(){
    int ans = 0;
    
    twoHeapMaintain();
    if(Min_Size == Max_Size || Max_Size > Min_Size) ans = Max_Heap[0];
    else ans = Min_Heap[0];
    
    return ans;
}

void printHeap(){
    cout<<"Max Heap: ";
    for(int i = 0; i < Max_Size; ++i){
        cout<<Max_Heap[i]<<" ";
    }
    
    cout<<endl<<"Min Heap: ";
    for(int j = 0; j < Min_Size; ++j){
        cout<<Min_Heap[j]<<" ";
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    ifstream infile("/Users/momo/program/algo-part1/week6/Median.txt");
    if(!infile) exit(-1);
    
    int tmp = 0;
    for(int i = 0; i < SIZE; ++i){
        infile>>tmp;
        if((!Max_Size && !Min_Size) || tmp < Max_Heap[0]){
            maxHeapInsert(tmp);
        }else{
            minHeapInsert(tmp);
        }
//        printHeap();
        
        Final_Ans += getMedianNumber();
        Final_Ans %= SIZE;
//        cout<<tmp<<" : "<<Final_Ans<<endl;
//        printHeap();
    }
    
    cout<<Final_Ans<<endl;
    
    return 0;
}
