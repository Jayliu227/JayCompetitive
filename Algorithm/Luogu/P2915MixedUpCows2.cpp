#include<bits/stdc++.h>

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

ll n, K, a[17], dp[17][(1 << 16) + 10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    FILL(dp, 0);
    for(int i = 1; i <= n; i++){
    	dp[i][(1 << (i - 1))] = 1;
    }

    for(int i = 1; i < (1 << n); i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(abs(a[j] - a[k]) > K){
                    if((i & (1 << (j - 1))) != 0){
                        if((i & (1 << (k - 1))) == 0){
                            dp[k][(1 << (k - 1)) ^ i] += dp[j][i];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
    	ans += dp[i][(1 << n) - 1];
    }

    cout << ans << endl;
    return 0;
} 