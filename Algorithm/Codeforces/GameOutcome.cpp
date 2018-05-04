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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vvi matrix(n, vi(n));
    forn(i, n) forn(j, n){
        cin >> matrix[i][j];
    }
    vi is(n), js(n);
    forn(i, n){
        int sum = 0;
        forn(j, n){
            sum += matrix[i][j];
        }
        is[i] = sum;
    }    
    forn(j, n){
        int sum = 0;
        forn(i, n){
            sum += matrix[i][j];
        }
        js[j] = sum;
    }
    int res = 0;
    forn(i, n) forn(j, n){
        res += js[j] > is[i];
    }
    cout << res << endl;    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}