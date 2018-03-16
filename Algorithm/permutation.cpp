#include<bits/stdc++.h>

using namespace std;

int n;
int main(){
	printf("number of elements to permute and elements\n");
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", arr+i);
	}

	do{
		for(auto i : arr){
			cout << i << " ";
		}
		cout << endl;
	}while(next_permutation(arr, arr+n));
}