#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define COUNT 100000
// #define COUNT 10

using namespace std;

long long ans;

vector<int> init(){
	ans = 0;
	vector<int> v_array;

	freopen("IntegerArray.txt", "r", stdin);
	// freopen("test.txt", "r", stdin);
	int temp;
	for(int i = 0; i < COUNT; ++i){
		cin>>temp;
		v_array.push_back(temp);
	}
	fclose(stdin);
	
	return v_array;
}

void merge(vector<int> &copy, vector<int> &left, vector<int> &right){
	int i = 0, j = 0, k = 0;
	int size = left.size();
	while(i < left.size() && j < right.size()){
		if(left[i] < right[j]){
			copy[k++] = left[i++];
		}else{
			copy[k++] = right[j++];
			ans += size - i;
			// cout<<"haha: "<<k<<endl;
		}
	}

	if(i < left.size()){
		for(; k < copy.size(); ){
			copy[k++] = left[i++];
		}
	}
	if(j < right.size()){
		for(; k < copy.size(); ){
			copy[k++] = right[j++];
		}
	}
}

void mergeSort(vector<int> &copy){
	if(copy.size() <= 1) return;
	int mid_pos = (int)copy.size()/2;
	vector<int> left(copy.begin(), copy.begin()+mid_pos);
	vector<int> right(copy.begin()+mid_pos, copy.end());
	mergeSort(left);
	mergeSort(right);
	merge(copy, left, right);
}

int main(){

	vector<int> copy = init();

	mergeSort(copy);

	cout<<ans<<endl;
	
	return 0;
}