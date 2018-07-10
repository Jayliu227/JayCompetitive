#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define FILL(x,v) memset(x,v,sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define debug(x) cerr << #x << " = " << (x) << ";" << endl
#define debug2(x, y) cerr << #x << " = " << (x) << "; " << #y << " = " << (y) << ";" << endl

template<typename T> inline bool chkmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int INF = (int) 1e9;
const int MOD = (int) 1e9 + 7;

int n, m;
vector<vector<int>> adj;
vector<int> weight;
vector<bool> vis;
int dp[301][301] = {0};

void solve(int cur){
    vis[cur] = true;
    if(adj[cur].size() == 0){
        dp[cur][1] = weight[cur];    
		return;
    }
    for(int j = 0; j < adj[cur].size(); j++){
        if(vis[adj[cur][j]] == false){
            solve(adj[cur][j]);
        }
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j < adj[cur].size(); j++){
            int child = adj[cur][j];
            dp[cur][m - i] = max(dp[cur][m - i], dp[child][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> n >> m; 
    adj.resize(n + 1);
    weight.assign(n + 1, 0);
    vis.resize(n + 1, false);
    for(int i = 1; i <= n; i++){
        int from, w;
        cin >> from >> w;
        adj[from].emplace_back(i);
        weight[i] = w;
    }   

    solve(0);
    cout << dp[0][m] << endl;
    return 0;
}
