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
const double PI = atan(1.0) * 4;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(13);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    double d, h, v, e;
    cin >> d >> h >> v >> e;
    double a = e * d * d * PI / 4.0;
    if(v <= a){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        cout << (d * d * PI / 4 * h / (v - a)) << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}