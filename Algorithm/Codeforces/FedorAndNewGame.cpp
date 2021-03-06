#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define endl '\n'

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;


const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1100;

int friends[maxn];
int n, m, k;
int fedor;

bool solve(int i){
    int d = i ^ fedor;
    int nod = 0;
    forn(i, n){
        if(d & (1 << i))
            nod++;
    }
    return nod <= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> n >> m >> k;
    forn(i, m){
        int f; cin >> f;
        friends[i] = f;
    }
    cin >> fedor;    
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    int res = 0;
    
    forn(i, m){
        if(solve(friends[i]))
            res++;
    }
    cout << res << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}