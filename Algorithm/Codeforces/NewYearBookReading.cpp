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
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

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
    int n, m;
    cin >> n >> m;
    vi cost(n);
    vi days(m);
    forn(i, n) cin >> cost[i];
    vector<bool> placed(n, false);
    deque<int> s;
    forn(i, m){
        int b = nxt();
        days[i] = b;
        if(placed[b - 1]) continue;
        s.pb(b);
        placed[b - 1] = true;
    }
    
    int res = 0;
    forn(i, m){
        deque<int> lift;
        int sum = 0;
        while(!s.empty() && s.front() != days[i]){
            lift.push_back(s.front());
            sum += cost[s.front() - 1];
            s.pop_front();
        }
        s.pop_front();
        while(!lift.empty()){
            s.push_front(lift.back());
            lift.pop_back();
        }
        s.push_front(days[i]);
        res += sum;
    }
    cout << res << endl;
#ifdef LOCAL_COMPILATION    
    int stop_s = clock();
    cerr << "time elapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
#endif    
    return 0;
}