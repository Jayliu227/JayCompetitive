#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define RI(x) int (x); cin >> (x)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define endl '\n'

using namespace std;

template<class T> void LOG(T s){
#ifdef LOCAL_COMPILATION
    cout << "DEBUG: " << s << endl;
#endif
}

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int INF = (int) 1e9;
const int MODULO = (int) 1e9 + 7;

vector<pair<pair<int,int>, int>> troopers;
int x, y, x1, y1;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> x >> y;
    forn(i, n){
        cin >> x1 >> y1;
        troopers.pb(mp(mp(x1, y1), 1));
    }    
    
    int res = 0;
    for(int i = 0; i < n; i++) if(troopers[i].se == 1){
        troopers[i].se = 0;
        if(x == troopers[i].fi.fi){
            for(int j = i + 1; j < n; j++) if(troopers[j].se == 1){
                if(troopers[j].fi.fi == x){
                    troopers[j].se = 0;
                }
            }
        }else{
            double xl = (troopers[i].fi.se - y) / (double)(troopers[i].fi.fi - x);
            for(int j = i + 1; j < n; j++) if(troopers[j].se == 1){
                if(((double)(troopers[j].fi.se - y) / (double)(troopers[j].fi.fi - x)) == xl){
                    troopers[j].se = 0;
                }
            }
        }        
        res++;
    }
    
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}







