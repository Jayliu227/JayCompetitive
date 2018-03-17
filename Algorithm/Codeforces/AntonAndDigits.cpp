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
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    int maxFirst = 0, maxSecond = 0;
    int a2, a3, a5, a6;
    a2 = k2, a3 = k3, a5 = k5, a6 = k6;
    int n256 = min(a2, a5);
    n256 = min(n256, a6);
    maxFirst += n256 * 256;
    a2 -= n256, a5 -= n256, a6 -= n256;
    maxFirst += min(a3, a2) * 32;
    
    int n32 = min(k3, k2);
    maxSecond += n32 * 32;
    k3 -= n32, k2 -= n32;
    n256 = min(k2, k5);
    n256 = min(n256, k6);
    maxSecond += n256 * 256;
    
    cout << max(maxFirst, maxSecond) << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}