#include<bits/stdc++.h>
#define vi vector<int>
#define UNVISITED -1

using namespace std;

struct vertex{
	vi nei;
};

vi dfs_num, dfs_low, visited, S;    // visited here means this element is in the current SCC
vector<vertex> vertices;
int n, e, dfsCounter, SCCCounter;

void tarjan(int u){
	dfs_num[u] = dfs_low[u] = dfsCounter++;
	visited[u] = true;
	S.push_back(u);

	for(auto j : vertices[u].nei){
		if(dfs_num[j] == UNVISITED){
			tarjan(j);
		}	
		if(visited[j] == true){
		 	dfs_low[u] = min(dfs_low[j], dfs_low[u]);
		}
	}

	if(dfs_num[u] == dfs_low[u]){
		printf("SCC %d: ", ++SCCCounter);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			printf(" %d", v);
			if(v == u) break;		
		}
		printf("\n");	
	}
}

int main(){
	cin >> n >> e;
	for(int i = 0; i < n; i++) vertices.push_back(vertex());	
	for(int i = 0; i < e; i++){
		int a ,b;
		cin >> a >> b;
		vertices[a].nei.push_back(b);
	}

	dfsCounter = 0;
	SCCCounter = 0;
	dfs_num.assign(n, UNVISITED);
	dfs_low.assign(n,0);
	visited.assign(n,0);

	/*
	for(int i = 0; i < n; i++){
		printf("%d: ", i);
		for(auto v : vertices[i].nei){
			cout << v << " ";
		}
		printf("\n");
	}*/

	for(int i = 0; i < n; i++){
		if(dfs_num[i] == UNVISITED){
			tarjan(i);
		}
	}
	return 0;
} 