#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

#define SIZE 10000
// #define SIZE 10

using namespace std;

long long ans;
vector<int> array;

void input(){
	freopen("QuickSort.txt", "r", stdin);
	// freopen("test.txt", "r", stdin);
	int tmp;

	for(int i = 0; i < SIZE; ++i){
		cin>>tmp;
		array.push_back(tmp);
	}

	fclose(stdin);
}

void output(){
	cout<<"ans: "<<ans<<endl;

	for(int i = 0; i < SIZE; i+=100){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

void quickSort(vector<int> &array, int pos_l, int pos_r){
	int size = pos_r - pos_l;
	if(size <= 1) return;

	ans += size - 1;
	int pivot = array[pos_l];
	int i = pos_l+1;

	for(int j = i; j < pos_r; ++j){
		if(array[j] < pivot){
			swap(array[i++], array[j]);
		}
	}

	swap(array[pos_l], array[i-1]);

	quickSort(array, pos_l, i-1);
	quickSort(array, i, pos_r);
}


int main(){

	ans = 0;
	input();

	quickSort(array, 0, SIZE);

	output();
	return 0;
}