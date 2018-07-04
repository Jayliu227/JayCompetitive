#include <bits/stdc++.h>

using namespace std;

/*
	find all cycles, if the length is odd, then we take its lcm
	otherwise, we take lcm of half of its length as that would 
	suffice the condition.
	if at any moment we find ourselves revisiting some node
	that is not the start of our cycle (dfs start), we have
	found a deadlock, thus impossible. because this deadlock
	point would make the start node inaccessible from all nodes 
	on the smaller cycle.
 */

int n;
vector<int> nxt;
vector<bool> vis;

bool ok = true;

int dfs(int cur, int par){
	vis[cur] = true;
	if(nxt[cur] == cur && par != cur){
		ok = false;
		return 12345;
	}else if(nxt[cur] == par){
		vis[nxt[cur]] = true;
		return 1;
	}else if(vis[nxt[cur]]){
		ok = false;
		return 12345;
	}else{
		return 1 + dfs(nxt[cur], par);
	}
}

int lcm(int a, int b){
	return a * b / __gcd(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	nxt.assign(n + 1, 0);
	vis.assign(n + 1, false);
	for(int i = 1; i <= n; i++){
		cin >> nxt[i];
	}

	int res = -1;
	for(int i = 1; i <= n; i++){
		if(!vis[i] && ok){
			int p = dfs(i, i);
			if(res == -1){
				if(p % 2 == 0){
					res = p / 2;
				}else{
					res = p;
				}
			}
			else{
				if(p % 2 == 0){
					res = lcm(res, p / 2);
				}else{
					res = lcm(res, p);
				}
			}
		}
	}

	if(ok){
		cout << res << endl;
	}else{
		cout << -1 << endl;
	}

	return 0;
}