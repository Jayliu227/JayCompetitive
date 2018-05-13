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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    int pd, ph;
    bool good = true;
    forn(i, m){
        int d, h;
        cin >> d >> h;
        if(i == 0){
            pd = d, ph = h;
            chkmax(ans, h + d - 1);
            chkmax(ans, h);            
            continue;
        }
        
        if(i == m - 1){
            chkmax(ans, h + n - d);
            chkmax(ans, h);
        }        
        if(abs(h -ph) > abs(d - pd)){
            good = false;                
        }else{
            int newh = (abs(pd - d) - abs(ph - h)) / 2 + max(ph, h);
            chkmax(ans, newh);
            pd = d, ph = h;
        }            
    }
    if(m == 1){
        chkmax(ans, ph + n - pd);
    }
    if(good){
        cout << ans << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
#ifdef LOCAL_COMPILATION    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif    
    return 0;
}