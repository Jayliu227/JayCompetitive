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
const int MODULO = (int) 1e8;

int dp[205][105][12][12];
int fn, hn, fk, hk;

int solve(int index, int fmused, int cf, int ch){
    int hmused = index - fmused;
    if(index == fn + hn){
        if(hmused == hn && fmused == fn && cf <= fk && ch <= hk){
            return 1;
        }else{
            return 0;
        }         
    }
    if(dp[index][fmused][cf][ch] != -1) return dp[index][fmused][cf][ch];
    
    int sum = 0;
    if(hmused < hn && ch < hk){
        sum += solve(index + 1, fmused, 0, ch + 1) % MODULO;
        sum %= MODULO;
    }
    
    if(fmused < fn && cf < fk){
        sum += solve(index + 1, fmused + 1, cf + 1, 0) % MODULO;
        sum %= MODULO;
    }
    return dp[index][fmused][cf][ch] = sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    FILL(dp, -1);
    cin >> fn >> hn >> fk >> hk;
    cout << solve(0, 0, 0, 0) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}