#include<bits/stdc++.h>

using namespace std;

int x[9], TC, lineCounter, a, b;

bool place(int queen, int row){
	for(int i = 1; i < queen; i++){
		// the formula holds true when the slope between these two points is -1 or 1 or 0
		if(x[i] == row || abs(x[i] - row) == abs(i - queen)){
			return false;
		}
	}
	return true;
}

void NQueens(int queen){
	for(int row = 1; row <= 8; row++){
		if(place(queen, row)){
			x[queen] = row;
			if(x[b] == a && queen == 8){
				printf("%2d:            %d", ++lineCounter, x[1]);
				for (int j = 2; j <= 8; j++) printf(" %d", x[j]);
				printf("\n");				
			}else{
				NQueens(queen + 1);
			}
		}		
	}
}


int main(){
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		memset(x, 0, sizeof(x)); lineCounter = 0;
		printf("SOLN COLUMN\n");
		printf(" # 1 2 3 4 5 6 7 8\n\n");
		NQueens(1); // generate all possible 8! candidate solutions
		if (TC) printf("\n");
	}
	return 0;
}