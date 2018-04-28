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
    int n, m;
    cin >> n >> m;    
    int mx = 0;
    function<bool(int)> isPrime = [&](int n){
        if(n == 0 || n == 1) return false;
        if(n == 2) return true;
        for(int i = 2; i <= (int)sqrt(n); i++) if(n % i == 0) return false;
        return true;
    };
    
    vvi matrix(n, vi(m));
    forn(i, n) forn(j, m){
        int entry;
        cin >> entry;
        matrix[i][j] = entry;
        mx = max(mx, entry);
    }
    
    vector<bool> prime(10 * mx);
    forn(i, 10 * mx){
        prime[i] = isPrime(i);
    }

    function<int(int)> edit = [&](int n){
        int res = 0;
        while(!prime[n]) n++, res++;
        return res;
    };    
    
    forn(i, n) forn(j, m) matrix[i][j] = edit(matrix[i][j]);
    
    int ans = INF;
    forn(i, n){
        int sum = 0;
        forn(j, m) sum += matrix[i][j];
        ans = min(ans, sum);
    }
    forn(j, m){
        int sum = 0;
        forn(i, n) sum += matrix[i][j];
        ans = min(ans, sum);
    }
    cout << ans << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}