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
const int maxn = (int) 1e4;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    ll n, m;
    cin >> n >> m;
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    ll kmn = 0, kmx = 0;
    ll t = n / m;
    ll r = n % m;
    kmn += ((t + 1) * t / 2) * r;
    kmn += (t * (t - 1) / 2) * (m - r);
    
    kmx = (n - (m - 1)) * (n - (m - 1) - 1) / 2;
    cout << kmn << " " << kmx << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}