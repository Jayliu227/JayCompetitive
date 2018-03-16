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
const int maxn = (int) 3010;

int a[maxn];
bitset<maxn> bs;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    int n;
    while(cin >> n){
        forn(i, n){
            int e; cin >> e;
            a[i] = e;
        }    
        
        bs.reset();
        bool ok = true;
        for1(i, n){
            int df = abs(a[i] - a[i - 1]);
            if(bs[df] == 1 || df < 0 || df > (n - 1)){
                ok = false; break;
            }
            bs[df] = 1;
        }
        
        if(ok && bs.count() == (n - 1)) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }

//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}