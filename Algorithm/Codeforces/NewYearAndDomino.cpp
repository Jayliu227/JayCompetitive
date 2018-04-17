#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'

using namespace std;

inline int nxt(){ int x; cin >> x; return x; }

template<class T> inline void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;
int n, m, q;
int a[510][510];
int dp[510][510];
int x1, y1, x2, y2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> m;
    FILL(dp, 0);
    forn(i, n) forn(j, m){
        char c; cin >> c;
        a[i][j] = c == '.';
    }
    
    for1(i, n){
        if(a[i][0] == 0){
            dp[i][0] = dp[i - 1][0];
            continue;
        }
        if(a[i - 1][0] == 1){
            dp[i][0] = dp[i - 1][0] + 1;
        }else{
            dp[i][0] = dp[i - 1][0];
        }
    }
    
    for1(j, m) {
        if(a[0][j] == 0){
            dp[0][j] = dp[0][j - 1];
            continue;
        }
        if(a[0][j - 1] == 1){
            dp[0][j] = dp[0][j - 1] + 1;
        }else{
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    for1(i, n) for1(j, m){
        if(a[i][j] == 0){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] -= dp[i - 1][j - 1];
            continue;
        }
        if(a[i][j - 1] == 1){
            dp[i][j] += dp[i][j - 1] + 1;
        }else{
            dp[i][j] += dp[i][j - 1];
        }
        if(a[i - 1][j] == 1){
            dp[i][j] += dp[i - 1][j] + 1;
        }else{
            dp[i][j] += dp[i - 1][j];
        }
        dp[i][j] -= dp[i - 1][j - 1];
    }
    
    forn(i, n){ 
        forn(j, m){
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    
    cout << endl;
    cin >> q;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        
        if(x1 == 0 && y1 == 0){
            cout << dp[x2][y2] << endl;
        }else if(x1 == 0){
            cout << x2 << " " << y2 << " " << y1 - 1 << endl;
            cout << (dp[x2][y2] - dp[x2][y1 - 1]) << endl;
        }else if(y1 == 0){
            cout << (dp[x2][y2] - dp[x1 - 1][y2]) << endl;
        }else{
            cout << (dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]) << endl;
        }
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}













