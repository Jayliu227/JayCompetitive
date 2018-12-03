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

const int N = 120;
int n, a[N];
bool dp[N][1000];

/*
	dp[i][j] = true if first i numbers could be partitioned into groups of sum = j
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
   
   	bool alzeros = true;
    cin >> n;
    int S = 0;
    for(int i = 1; i <= n; i++){
    	char c; cin >> c;
    	a[i] = c - '0';
    	S += a[i];
    	alzeros &= a[i] == 0;
    }

    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < 1000; j++) {
    		dp[i][j] = false;
    	}
    }

    for(int i = 0; i < 1000; i++)
    	dp[0][i] = true;



    for(int i = 1; i <= n; i++) {
    	int s = 0;
    	for(int p = i; p >= 1; p--){
    		s += a[p];
    		dp[i][s] |= dp[p - 1][s];
    	}
    }

    bool ok = false;
    for(int i = 1; i < S; i++)
    	ok |= dp[n][i];

    cout << (ok || alzeros ? "YES" : "NO") << endl;

    return 0;
}