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

/*
    key observation: f(n) is the possible sequences with the first n color
    f(n + 1): first put one ball of color n + 1 at the back, and then place
    the remaining balls of color n + 1 at any place before it;
    thus f(n + 1) = f(n) * bi[total ball before (n + 1) adds cnt of (n + 1) - 1][cnt of (n + 1) - 1]
*/

int bi[1010][1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int k;
    cin >> k;
    vi cnt(k);
    forn(i, k) cin >> cnt[i];    
    bi[0][0] = 1;
    for(int i = 1; i < 1010; i++){
        bi[i][0] = 1;
        for(int j = 1; j <= i; j++){
            bi[i][j] = (bi[i - 1][j - 1] + bi[i - 1][j]) % MODULO;
        }
    }
    ll total = 0;
    ll ans = 1;
    for(int i = 0; i < k; i++){
        ans = ans * (bi[total + cnt[i] - 1][cnt[i] - 1]) % MODULO;
        total += cnt[i];
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}