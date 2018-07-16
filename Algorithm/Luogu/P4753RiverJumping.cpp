#include <bits/stdc++.h>
#define re register
/* use two pointers to simulate the process
 * greedily take update the positions
 * and if there is no way to move both of them
 * print no, otherwise print out the remembered path
 */
using namespace std;
int a[100005], b[100050];
int ax, bx, tota, totb;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	for(re int i = 1; i <= m; i++){
		int x; cin >> x;
		if(ax < bx){
			if(x - ax < s){
				cout << "NO" << endl;
				return 0;
			}else if(x - bx < s){
				a[tota++] = i;
				ax = x;
			}else{
				b[totb++] = i;
				bx = x;
			}
		}else{
			if(x - bx < s){
				cout << "NO" << endl;
				return 0;
			}else if(x - ax < s){
				b[totb++] = i;
				bx = x;
			}else{
				a[tota++] = i;
				ax = x;
			}
		}
	}
	if(n - ax < s && n - bx < s){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(re int i = 0; i < tota; i++)
		cout << a[i] << " ";
	cout << m + 1 << endl;
	for(re int i = totb - 1; i >= 0; i--)
		cout << b[i] << " ";
	cout << 0;
	return 0;
}
