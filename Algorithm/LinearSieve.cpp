#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;
const int N = 123456789;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

	int n;
	cin >> n;

	vector<int> pr;
	int pl[N];	    

	for(int i = 2; i <= n; i++){
		if(pl[i] == 0){
			pl[i] = i;
			pr.push_back(i);
		}
		for(int j = 0; j < pr.size() && pr[j] <= pl[i] && i * pr[j] <= n; j++){
			pl[i * pr[j]] = pr[j];
		}
	}

    return 0;
}