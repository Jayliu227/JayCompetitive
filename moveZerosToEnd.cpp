#include<bits/stdc++.h>

using namespace std;

void move(int* arr, int size){
	int* n = (int*) malloc(size * 4);
	int index = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] != 0){
			n[index++] = arr[i];
		}
	}

	for(int i = index; i < size; i++){
		n[i] = 0;
	}            

	for(int i = 0; i < size; i++){
	 	arr[i] = n[i];
	}
	
	delete(n);
}


void move2(int* arr, int size){
	int index = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] != 0){
			int tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
			index++;
		}
	}

	for(int i = index; i < size; i++){
		arr[index] = 0;
	}
}

int main(){

	int a[] = {1,0,0,2,1,2,2,3,0,2,23,4,30};

	move2(a, 13);
	
	for(auto i : a) cout << i << " ";

	return 0;
}