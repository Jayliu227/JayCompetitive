#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cout << "NxN matrix ";
	cin >> N;
	int m[N][N];
	// cumulative matrix
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%d", &m[i][j]);
			if(i > 0) m[i][j] += m[i - 1][j];
			if(j > 0) m[i][j] += m[i][j - 1];
			if(i > 0 && j > 0) m[i][j] -= m[i - 1][j - 1];			
		}

	int ans = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int p = i; p < N; p++){
				for(int q = j; q < N; q++){
					int subm = m[p][q];
					if(i > 0) subm -= m[i - 1][j];
					if(j > 0) subm -= m[i][j - 1];
					if(i > 0 && j > 0) subm += m[i - 1][j - 1];
					ans = max(ans, subm);
				}
			}
		}
	}

	printf("largest submatrix sum is: %d\n", ans);

	return 0;
}


