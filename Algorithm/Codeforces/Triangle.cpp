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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int start_s = clock();
    
    int edge[4];
    forn(i, 4){
        cin >> edge[i];
    }
    sort(edge, edge + 4);
    
    if(edge[0] + edge[1] > edge[2] || edge[1] + edge[2] > edge[3]){
        cout << "TRIANGLE" << endl;
    }else if(edge[0] + edge[1] == edge[2] || edge[0] + edge[1] == edge[3] || edge[1] + edge[2] == edge[3]){
        cout << "SEGMENT" << endl;
    }else{
        cout << "IMPOSSIBLE"<< endl;
    }
    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}