#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define RI(x) int (x); cin >> (x)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
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

int edge[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
    RI(n);
    forn(i, n){
        RI(e);
        edge[i] = e;
    }
    
    sort(edge, edge + n);
    
    for(int i = 0; i < n - 2; i++){
        int e1 = edge[i], e2 = edge[i + 1];
        ll sum = e1 + e2;
        if(sum > edge[i + 2]){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}