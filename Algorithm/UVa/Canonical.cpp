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
const int maxn = (int) 110;

int n;
int coins[maxn];
int ce;
int dp[maxn][200010];

int greedy(int i){
    int sum = 0;
    while(i){
        for(int j = n - 1; j >= 0; j--) if(coins[j] <= i){
            sum++;
            i -= coins[j];
            break;
        }
    }
    return sum;
}

int normal(int index, int rem){
    if(index > n - 1) return INF;    
    if(rem < 0) return INF;
    if(rem == 0) return 0;
    if(dp[index][rem] != -1) return dp[index][rem];
    int num = min(normal(index, rem - coins[index]) + 1, normal(index + 1, rem));
    return dp[index][rem] = num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//=======GET INPUT HERE============
    cin >> n;
    forn(i, n) {int c; cin >> c; coins[i] = c;}
//=======FINISHED INPUT============        
    //int start_s = clock();
//=======CODE GOES HERE============
    ce = coins[n - 1] + coins[n - 2];    
    forn(i, ce){
        FILL(dp, -1);
        if(greedy(i) != normal(0,i)){
            cout << "non-canonical" << endl;
            return 0;
        }
    }
    cout << "canonical" << endl;
//=======CODE ENDS HERE============    
    //int stop_s = clock();
    //cerr << "time lapsed: " <<((stop_s - start_s) / double(CLOCKS_PER_SEC)) << "s."<<endl;    
    return 0;
}