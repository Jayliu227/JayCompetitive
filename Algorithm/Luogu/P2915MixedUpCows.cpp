#include<bits/stdc++.h>

/*
	Try to use binary to represent the set of numbers
	that we've chosen so far.
	dp[last][state] represents the number of ways to form
	such sequence when LAST is the last number we chose and
	every single bit set on represents the numbers we used,
	and their relative positions don't matter.
*/

using namespace std;

#define fi first
#define se second
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl
#define popcnt(x) __builtin_popcount(x)

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

ll n, k, a[16], dp[16][(1 << 16) + 10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    FILL(dp, 0);
    for(int i = 0; i < n; i++){
    	dp[i][(1 << i)] = 1;
    }

    for(int len = 1; len < n; len++){
    	for(int cur = 0; cur < n; cur++){
    		for(int state = 0; state < (1 << n); state++) if(popcnt(state) == len && ((state & (1 << cur)) != 0)){    			
    			for(int next = 0; next < n; next++) if(next != cur && ((state & (1 << next)) == 0)){
    				if(abs(a[next] - a[cur]) > k){
    					int nstate = state ^ (1 << next);
    					dp[next][nstate] += dp[cur][state];
    				}
    			}
    		}
    	}
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
    	ans += 1LL * dp[i][(1 << n) - 1];
    }

    cout << ans << endl;
    return 0;
} 