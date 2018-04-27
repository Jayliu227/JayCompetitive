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
    a trick: when we want to know the number of stuffs or something (called target) from 
    before and after ith element, we can use map to store the number of targets in two maps
    "before" and "after", and update this map as we traverse the array.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    map<ll, ll> rt, lt;
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    forn(i, n){
        cin >> a[i];
        rt[a[i]]++;
    }    
    ll ans = 0;
    forn(i, n){
        ll l = 0, r = 0;
        rt[a[i]]--;
        r = rt[a[i] * k];
        if(a[i] % k == 0){
            l = lt[a[i] / k];
        }
        lt[a[i]]++;
        ans += l * r;
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}