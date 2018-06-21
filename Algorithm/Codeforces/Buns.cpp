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

int n, m, dp[1050][20];
int a[110], b[110], c[110], d[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> n >> m >> c[0] >> d[0];
    a[0] = b[0] = 0;

    forn(i, m) cin >> a[i + 1] >> b[i + 1] >> c[i + 1] >> d[i + 1];

    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    int ans = 0;
   	for(int i = 0; i <= n; i++){
   		for(int j = 0; j <= m; j++){
   			for(int k = 0; k * b[j] <= a[j] && i >= k * c[j]; k++){
   				dp[i][j + 1] = max(dp[i][j + 1], dp[i - k * c[j]][j] + d[j] * k);
   				ans = max(ans, dp[i][j + 1]);
   			}
   		}
   	}

   	cout << ans << endl;
    return 0;
}