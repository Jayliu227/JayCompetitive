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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;
const int N = 3500;

int a[N], cost[N];
ll dp[N][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n;
    cin >> n;
    for1(i, n + 1){
    	cin >> a[i];
    }
    for1(i, n + 1){
    	cin >> cost[i];
    }

    ll res = INF;

    for(int i = 1; i <= n; i++){
    	dp[i][1] = cost[i];
    	dp[i][2] = dp[i][3] = INF;
    	for(int j = 1; j < i; j++) if(a[j] < a[i]) {
    		dp[i][2] = min(dp[i][2], dp[j][1] + 1LL * cost[i]);
    	}    	
    	for(int j = 1; j < i; j++) if(a[j] < a[i]) {
    		dp[i][3] = min(dp[i][3], dp[j][2] + 1LL * cost[i]);
    	}

    	chkmin(res, dp[i][3]);
    }

    if(res == INF){
    	cout << -1 << endl;
    }else{
    	cout << res << endl;
    }
    return 0;
}

