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
    int n;
    cin >> n;
    int gn[5] = {0};
    forn(i, n){
        int s;
        cin >> s;
        gn[s]++;
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============    
    int res = 0;
    res += gn[4];
    int de = min(gn[3], gn[1]);
    res += de;
    gn[3] -= de;
    gn[1] -= de;
    res += gn[2] / 2;
    gn[2] %= 2;
    res += gn[3];
    if(gn[2] == 1){
        res++, gn[1] -=2, gn[1] = max(0, gn[1]);
    }
    res += gn[1] / 4;
    gn[1] %= 4;
    res += gn[1] == 0 ? 0 : 1;
    cout << res << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}