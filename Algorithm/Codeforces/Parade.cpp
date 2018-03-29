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
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e4;

// left more than right
int lft[100010];
int rht[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    RI(n);
    
    ll lf = 0, rt = 0;
    int l, r;
    forn(i, n){
        cin >> l >> r;
        lf += l, rt += r;
        lft[i] = l, rht[i] = r;   
    }
    
    int mx = abs(lf - rt);
    
    int index = -1;
    forn(i, n){
        int d = abs((lf - lft[i] + rht[i]) - (rt - rht[i] + lft[i]));
        if(d > mx){
            mx = d;
            index = i;
        }
    }   
    cout << index + 1 << endl;
    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}