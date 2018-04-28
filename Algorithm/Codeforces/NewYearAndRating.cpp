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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;
/*
    when directly considering absolute value is hard.
    consider its change and find relation between them.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    ll pref = 0;
    ll minRed = INF, maxBlue = -INF;
    bool hasBlue = false;
    int change, divn;
    forn(i, n){
        cin >> change >> divn;        
        if(divn == 1){
            minRed = min(minRed, pref);
        }else{
            maxBlue = max(maxBlue, pref);
        }
        pref += change;   
        hasBlue |= divn == 2;    
    }        
    
    if(minRed <= maxBlue){
        cerr << minRed << " " << maxBlue << endl;
        cout << "Impossible" << endl;
        return 0;
    }
    
    if(!hasBlue){
        cout << "Infinity" << endl;
    }else{
        cout << (1899 + pref - maxBlue) << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}