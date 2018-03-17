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

int bs[110], gs[110];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    int b, g;
    cin >> b;
    forn(i, b){
        int in;
        cin >> in;
        bs[i] = in;
    }
    cin >> g;
    forn(i, g){
        int in;
        cin >> in;
        gs[i] = in;
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    sort(bs, bs + b); sort(gs, gs + g);
    
    int res = 0;
    forn(i, b){
        forn(j, g){
            if(abs(bs[i] - gs[j]) <= 1){
                res++;
                gs[j] = 1000;
                break;
            }
        }
    }
    cout << res << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}