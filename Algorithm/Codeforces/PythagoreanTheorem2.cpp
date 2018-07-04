#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int res = 0;

	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int c = sqrt(i * i + j * j);
			if(c <= n && c >= j && c * c == (i * i + j * j))
				res++;
		}
	}

	cout << res << endl;

	return 0;
}