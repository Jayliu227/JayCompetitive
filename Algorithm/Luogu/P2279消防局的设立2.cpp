#include <bits/stdc++.h>
/*
*  cases when i can be covered:
*  dp[i][0]: set up a building at node i
*  dp[i][1]: has at least a building 1 unit away from i
*  dp[i][2]: has at least a building 2 units away from i 
*  cases when i MIGHT NOT be covered:
*  dp[i][3]: all children and grandchildren are covered
*  dp[i][4]: all grandchildren are covered
*  
*  transition function:
*  dp[i][0]:
*  	since we set up a building at i, all its children and grandchildren are covered;
*  	therefore, for each children, they can be either covered or not by their descendents,
*  	so we can just take the minimum of all their options and add 1 as the new building.
*  	thus:
*  	dp[i][0] = 1 + sum(min(dp[j][0...4]));
*  dp[i][1]:
*  	since there is at least one building 1 unit away from root i, we know that all of i's
*  	children are fine. But now we need to consider all grandchildren except those who are
*  	the children of the child who has the building. We call the child who has the building
*  	k. For all children other than k, we want to make all of their children covered somehow,
*  	so dp[j][0...3] would be fine. dp[j][4] wouldn't because it only guarantees the coverage of
*  	the grandchildren of j but not the children of j. 
*  	thus:
*  	dp[i][1] = min(dp[k][0] + sum(min(dp[j][0...3])));
*  dp[i][2]:
*  	since there is at least one building 2 units away from root i, we know that root can be
*  	covered. But all children except this child k can't be covered, so we need to make sure
*  	they are, as well as their children. dp[j][0..2] would do. dp[j][3] and dp[j][4] wouldn't
*  	because they didn't make sure j would be covered
*  	thus:
*  	dp[i][2] = min(dp[k][1] + sum(min(dp[j][0...2])));
*  dp[i][3]:
*  	in this case, we no longer care about whether i is covered or not. We only want to make sure all
*  	of its children and grandchildren are covered. In order to make all children and grandchildren 
*  	covered, dp[j][0...2] would work. dp[j][3] and dp[j][4] wouldn't because they don't assume for j
*  	thus:
*  	dp[i][3] = sum(min(dp[j][0...2]));
*  dp[i][4]:
*  	in this case, we dont care about i either. And we dont even care about its children. We just want
*  	to make sure all grandchildren are covered. dp[j][0...3] would work but not dp[j][4] might
*  	not since the latter doesn't guarantee the coverage of j's children.
*  	thus:
*  	dp[i][4] = sum(min(dp[j][0...3]));
*  
*  state compression:
*  f[i][j] = min(dp[i][0...j]); and j >= 2;
*  
*  thus, all above states can be converted into:
*  
*  f[i][0] = 1+¦²f[j][4]; 
*  
*  f[i][1] = min( f[k][0] + ¦²(j != k)f[j][3] ) 
*  = ¦²f[j][3] + min(f[k][0]-f[k][3]) 
*  = f[i][4] + min(f[k][0]-f[k][3]); 
*  
*  f[i][2] = min( f[k][1] + ¦²(j != k)f[j][2] ) 
*  = ¦²f[j][2] + min(f[k][1]-f[k][2]) 
*  = f[i][3] + min(f[k][1]-f[k][2]); 
*  
*  f[i][3] = ¦²f[j][2]; 
*  
*  f[i][4] = ¦²f[j][3]; 
*/
using namespace std;
const int N = 1010;
const int INF = 2100000000;
int f[N][5];
vector<int> adj[N];
void dfs(int u, int fa){
	f[u][0] = 1;
	f[u][1] = f[u][2] = INF;
	f[u][3] = f[u][4] = 0;
	bool son = 0;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(v != fa){
			son = 1;
			dfs(v, u);
			f[u][0] += f[v][4];
			f[u][3] += f[v][2];
			f[u][4] += f[v][3];
		}
	}
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(v != fa){
			f[u][1] = min(f[u][1], f[u][4] + f[v][0] - f[v][3]);
			f[u][2] = min(f[u][2], f[u][2] + f[v][1] - f[v][2]);
		}
	}
	for(int i = 1; i <= 4; i++)
		f[u][i] = min(f[u][i], f[u][i - 1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int v;
		cin >> v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}
	dfs(1, -1);
	cout << f[1][2] << endl;
	return 0;
}
