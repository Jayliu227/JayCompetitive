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
    int a, b;
    cin >> a >> b;
    int x, y;
    
    function<int(int, int, int&, int&)> exgcd = [&](int a, int b, int& x, int& y){
        if(b == 0){
            x = 1, y = 0;
            return a;
        }
        int x1, y1;
        int d = exgcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return d;
    };

    int d = exgcd(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}