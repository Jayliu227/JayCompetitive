#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define REP(i,s,t) for(int i = (s); i < (int)t; i++)
#define forn(i,n) for(int i = 0; i < (int)n; i++)
#define for1(i,n) for(int i = 1; i < (int)n; i++)
#define FILL(x,v) memset(x,v,sizeof(x))

using namespace std;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e3;

int m, n;
int dp[2][maxn][maxn];

bool state(int id, int m, int n){
    if(n == 0) return id == 0;
    if(dp[id][m][n] != -1) return dp[id][m][n];
    
    int multiple = 1;
    bool canWin = 0;
    while(n*multiple <= m){
        canWin |= !state(1 - id, n, m - n*multiple);
        multiple++;
    }
    
    return dp[id][m][n] = canWin;
}

int main(){
    int start_s = clock();
//=======CODE GOES HERE============
    
    cin >> m >> n;
    
    FILL(dp, -1);

    cout << state(0,m,n) << endl;
    
//=======CODE ENDS HERE============    
    int stop_s = clock();
    printf("time lapsed: %.3fs\n", (stop_s - start_s) / double(CLOCKS_PER_SEC));    
    return 0;
}