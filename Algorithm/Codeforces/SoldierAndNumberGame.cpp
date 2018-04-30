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
const int maxn = 5000005;

int d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
#ifdef LOCAL_COMPILATION    
    int start_s = clock();
#endif        
    FILL(d, 0);
    for(int i = 2; i < maxn; i++){
        // this number is prime because there is no previous number that is a divisor of i
        if(d[i] == 0){
            // we go through all multiple of i and calculate its number of prime factors
            for(int j = i; j < maxn; j += i){
                d[j] = d[j / i] + 1;
            }
        }
    }
    
    for(int i = 1; i < maxn; i++) d[i] += d[i - 1];

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << d[a] - d[b] << endl;
    }    
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}