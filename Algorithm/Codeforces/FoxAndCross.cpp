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

inline int nxt(){ int x; cin >> x; return x; }

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
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif    
    int n = nxt();
    vvi grid(n, vi(n));
    forn(i, n) forn(j, n){
        char c;
        cin >> c;
        grid[i][j] = c == '#';
    }
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < n - 1; j++){
            int sum = 0;
            sum = grid[i][j] + grid[i + 1][j] + grid[i - 1][j] + grid[i][j - 1] + grid[i][j + 1];
            if(sum == 5){
                grid[i][j] = grid[i + 1][j] = grid[i - 1][j] = grid[i][j - 1] = grid[i][j + 1] = 0;
            }
        }
    }
    int sum = 0;
    forn(i, n) forn(j, n) sum += grid[i][j];
    if(sum == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}