#include<bits/stdc++.h>

using namespace std;

#define pb push_back
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
const int MODULO = (int) 1e9 + 7;

int a[100000 + 100];
ll dp[100000 + 100][20] = {0LL};
ll t[20][100000 + 100] = {0LL};
int n, k;

void update(int l, int x, int v){
    for(; x <= n; x += x&-x){
        t[l][x] += v;
    }
}

ll query(int l, int x){
    ll res = 0;
    for(; x; x -= x&-x) res += t[l][x];
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
        
    cin >> n >> k;
    k++;
    for(int i = 1; i <= n; i++) cin >> a[i];    
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
        update(1, a[i], 1);
        for(int j = 2; j <= k && j <= i; j++){
            dp[i][j] = query(j - 1, a[i] - 1);
            update(j, a[i], dp[i][j]);
        } 
        ans += dp[i][k];
    }
    
    cout << ans << endl;
    return 0;
}
