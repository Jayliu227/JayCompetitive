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

vector<ll> all;
vector<ll> no;
int n, k, d;

ll solve(int c, bool contain){
    if(c == 0){
        return 1;
    }
    
    if(contain){
        if(all[c] != -1) return all[c];
    }else{
        if(no[c] != -1) return no[c];
    }
    
    if(contain){
        ll ways = 0;
        for(int i = 1; i <= k; i++){
            if(c - i >= 0){
                ways %= MODULO;
                ways += solve(c - i, true) % MODULO;
            }
        }
        return all[c] = ways % MODULO;
    }else{
        ll ways = 0;
        for(int i = 1; i < d; i++){
            if(c - i >= 0){
                ways %= MODULO;
                ways += solve(c - i, false) % MODULO;
            }
        }
        return no[c] = ways % MODULO;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    cin >> n >> k >> d;
    all.assign(n + 1, -1);
    no.resize(n + 1, -1);

    ll s1 = solve(n, true) % MODULO;
    ll s2 = solve(n, false) % MODULO;
    LOG(s1); LOG(s2);
    if(s1 >= s2)
        cout << s1 - s2 << endl;
    else
        cout << (s1 - s2 + MODULO) << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}









