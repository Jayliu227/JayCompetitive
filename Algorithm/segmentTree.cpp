#include<bits/stdc++.h>

#define RANGE_SUM 0
#define RANGE_MAX 1
#define RANGE_MIN 2

using namespace std;

vector<int> segmentTree;

void init(int N){
	int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
	segmentTree.resize(length, 0);
}

void buildTree(int code, int A[], int node, int b, int e){
	if(b == e){
		if(code == RANGE_SUM){
			segmentTree[node] = A[b];
		}else{
			segmentTree[node] = b;
		}                            

	}else{
	 	int leftIndex = node * 2, rightIndex = node * 2 + 1;
		buildTree(code, A, leftIndex, b, (b + e) /2);
		buildTree(code, A, rightIndex, (b + e)/2 + 1, e);

		int lContent = segmentTree[leftIndex], rContent = segmentTree[rightIndex];

		if(code == RANGE_SUM){
			segmentTree[node] = lContent + rContent;
		}else{
			int leftV = A[lContent], rightV = A[rContent];
			if (code == RANGE_MIN) segmentTree[node] = (leftV <= rightV) ? lContent : rContent;
			else segmentTree[node] = (leftV >= rightV) ? lContent : rContent;		
		}
	}
}

int query(int code, int A[], int node, int b, int e, int i, int j){
	if(i > e || j < b) return -1;
	if(b >= i && e <= j) return segmentTree[node];

	int p1 = query(code, A, node*2, b, (b + e) / 2, i, j);
	int p2 = query(code, A, node*2 + 1, (b + e) / 2 + 1, e, i, j);

	if(p1 == -1) return p2;
	if(p2 == -1) return p1;

	if(code == RANGE_SUM) return p1 + p2;
	if(code == RANGE_MIN) return A[p1] <= A[p2] ? p1 : p2;
	if(code == RANGE_MAX) return A[p1] <= A[p2] ? p2 : p1;	
}

int main(){

	int A[] = {8,7,3,9,5,1,10};
	init(7);

	buildTree(RANGE_MIN, A, 1, 0, 6);
	printf("%d\n", query(RANGE_MIN, A, 1, 0, 6, 0, 3));
	return 0;
}














