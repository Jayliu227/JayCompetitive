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
const int maxn = (int) 510;

int line[maxn][maxn], used[maxn], nxt[maxn];
int t, n, m, u, v;

bool find(int x){
    for(int i = 1; i <= m; i++){
        if(line[x][i] && !used[i]){
            used[i] = 1;
            if(nxt[i] == 0 || find(nxt[i])){
                nxt[i] = x;
                return true;
            }
        }
    }
    return false;
}

int match(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        FILL(used, 0);
        if(find(i)) sum++;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============    
    cin >> t;
    FILL(nxt, 0);
    FILL(line, 0);
    m = n = 4;
    
    while(t--){
        cin >> u >> v;
        line[u][v] = 1;
    }
    
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    cout << match() << endl;

//=======CODE ENDS HERE============    
    int stop_s = clock();
    cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}