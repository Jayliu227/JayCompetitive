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

vi q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    int n, t;
    cin >> n >> t;
    forn(i, n){
        char g;
        cin >> g;
        q.push_back(g == 'B' ? 1 : 0);
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    forn(i, t){
        vi q1 = q;
        forn(j, n - 1) if(q[j] == 1){
            if(q[j + 1] == 0){
                q1[j] = 0; q1[j + 1] = 1;
            }        
        }    
        q = q1;
    }
    forn(i, n){
        cout << (q[i] == 1 ? 'B' : 'G');
    }
    cout << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}