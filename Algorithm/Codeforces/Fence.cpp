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

int dp[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int in; cin >> in;
        
        if(i == 1){
            dp[1] = in;
        }else{
            dp[i] = dp[i - 1] + in;
        }
    }
//=======FINISHED INPUT============        
    int start_s = clock();
//=======CODE GOES HERE============
    dp[0] = 0;
    int mn = INF;
    int mnIndex = 0;

    for(int i = k; i <= n; i++){
        int sum = dp[i] - dp[i - k];
        if(sum < mn){
            mn = sum; mnIndex = i - k + 1;
        }
    }
    
    cout << mnIndex << endl;
//=======CODE ENDS HERE============    
    int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}