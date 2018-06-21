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
const ll MOD = (int) 1e9 + 7;

int k, n;
string a, b;
ll dp[123456][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    cin >> a >> b >> k;
    n = a.size();
#define G 0
#define B 1
    int nog = 0;
    for(int i = 0; i < n; i++){
    	bool ok = true;
    	for(int j = 0; j < n; j++){
    		if(a[(i + j) % n] != b[j]){
    			ok = false;
    			break;
    		}
    	}
    	if(ok) nog++;
    }

    FILL(dp, 0);
    dp[0][G] = a == b;
    dp[0][B] = a != b;

    for(int i = 1; i <= k; i++){
    	dp[i][G] = ((dp[i - 1][B] * nog * 1LL) % MOD + (dp[i - 1][G] * (nog - 1) * 1LL) % MOD) % MOD;
    	dp[i][B] = ((dp[i - 1][G] * (n - nog) * 1LL) % MOD + (dp[i - 1][B] * (n - nog - 1) * 1LL) % MOD) % MOD;
    }

    cout << dp[k][G] << endl;
    return 0;
}