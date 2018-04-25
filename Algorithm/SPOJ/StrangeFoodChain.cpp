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

int TC, n, k;

vector<int> par;
vector<int> ranks;

void init(int n){
    par.resize(n); ranks.resize(n);
    forn(i, n){
        par[i] = i;
        ranks[i] = 0;
    }
}

int find(int n){
    if(n == par[n]) return n;
    return par[n] = find(par[n]);
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    int ai = find(a);
    int bi = find(b);
    if(ai == bi) return;
    if(ranks[a] < ranks[b]){
        par[a] = b;
    }else{
        par[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> TC;
    while(TC--){
        cin >> n >> k;
        init(n * 3);
        int type, x, y;
        int ans = 0;
        while(k--){
            cin >> type >> x >> y;
            x--, y--;
            if(x < 0 || y < 0 || x >= n || y >= n){ 
                ans++; 
                continue; 
            }
            if(type == 1){
                if(same(x, y + n) || same(x, y + 2*n)) 
                    ans++;
                else {
                    unite(x, y); 
                    unite(x + n, y + n); 
                    unite(x + 2*n, y + 2*n);
                }
            }else{                    
                if(same(x, y) || same(x, y + 2*n)) 
                    ans++;
                else{
                    unite(x, y + n); 
                    unite(x + n, y + 2*n);
                    unite(x + 2*n, y);
                }                    
            }
        }
        cout << ans << endl;
    }
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}