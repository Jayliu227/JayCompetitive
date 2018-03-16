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
const int maxn = (int) 1e6 + 10;

int sieve[maxn];

void genSieve(){
    sieve[1] = 0;
    REP(i, 2, maxn) if(sieve[i] == 1){
        for(int j = i * 2; j < maxn; j += i){
            sieve[j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    int n; cin >> n;
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    forn(i, maxn) sieve[i] = 1;
    genSieve();
    forn(i, n){
        ll p; cin >> p;
        cout << (((sqrt(p) - floor(sqrt(p)) == 0) && (sieve[(int)sqrt(p)] == 1)) ? "YES" : "NO") << endl;   
    }
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}